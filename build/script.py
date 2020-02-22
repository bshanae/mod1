import os
import re
import argparse
import shlex


'''
					+++ READ +++				
'''

compiler = None
project = None
executable = None
flag = None
source = None
target = None
include = None
link_directory = None
link_library = None


def extract_command(string, command):
	pattern = re.compile(command + '\(([^)]+)\)')
	result = pattern.findall(string)
	result = [shlex.split(element) for element in result]
	result = [y for x in result for y in x]
	return result


def work_configuration(path):
	file = open(path)
	content = file.read()
	file.close()

	global compiler
	global project
	global executable
	global flag
	global source
	global include
	global link_directory
	global link_library

	compiler = extract_command(content, 'compiler')
	project = extract_command(content, 'project')
	executable = extract_command(content, 'executable')
	flag = extract_command(content, 'add_flag')
	source = extract_command(content, 'add_source')
	include = extract_command(content, 'include_directory')
	link_directory = extract_command(content, 'link_directory')
	link_library = extract_command(content, 'link_library')

	if not compiler:
		compiler = 'gcc'
	else:
		compiler = compiler[0]

	if not project:
		raise Exception('project name is not defined')
	else:
		project = project[0]

	if not executable:
		raise Exception('executable is not defined')
	else:
		executable = executable[0]

	if not source:
		raise Exception('source is not defined')


def work_target():
	global target

	target = [os.path.basename(element) for element in source]
	for i in range(len(target)):
		occurrence = 1
		for j in range(len(target)):
			if i != j and target[i] == target[j]:
				split = os.path.splitext(target[i])
				target[j] = split[0] + '_' + str(occurrence) + split[1]
				occurrence += 1


def work_include():
	global include

	include = ['-I ' + element for element in include]


def work_link_x():
	global link_directory
	global link_library

	link_directory = ['-L ' + element for element in link_directory]
	link_library = ['-l ' + element if element[0] != '-' else element for element in link_library]



'''
					+++ WRITE +++				
'''


def concat(object, separator = ' '):
	if not object:
		return ''
	else:
		return separator.join([str(element) for element in object])


def generate_object(file):
	return '${OBJECT_FOLDER}/' + file + '.o'


def generate_depend(file):
	return '${DEPEND_FOLDER}/' + file + '.d'


def generate_object_rule(source_name, target_name, percent):
	object_name = generate_object(target_name)
	depend_name = generate_depend(target_name)
	depend = '{depend} | ${{OBJECT_FOLDER}} ${{DEPEND_FOLDER}}'.format(depend = depend_name)
	compile = '@${{COMPILER}} ${{INCLUDE}} ${{FLAG}} -MMD -MP -MT {object} -MF {depend} -c {source} -o {object}'.format(
		source = source_name,
		object = object_name,
		depend = depend_name)
	info = '${{call INFO,{percent}%${{COMMA}} compiling object {object}}}'.format(percent = percent, object = source_name)
	return '{object} : {depend}\n\t{info}\n\t{compile}\n'.format(
		object = object_name,
		depend = depend,
		info = info,
		compile = compile)


def work_makefile(path = './Makefile'):
	template = '''#						FUNCTIONS

define INFO
${{info ${{PREFIX}} : $1}}
endef

#						VARIABLES

COMMA = ,

OBJECT_FOLDER = .object
DEPEND_FOLDER = .depend

COMPILER = {template_compiler}
PREFIX = {template_project}
EXECUTABLE = {template_executable}

INCLUDE = {template_include}
OBJECT = {template_object}
DEPEND = {template_depend}
LINK_DIRECTORY = {template_link_directory}
LINK_LIBRARY = {template_link_library}

FLAG = {template_flag}

#						BASIC RULES	

all : ${{EXECUTABLE}}

${{EXECUTABLE}} : ${{OBJECT}}
	${{call INFO,Linking in executable ${{EXECUTABLE}}}}
	@${{COMPILER}} ${{FLAG}} ${{LINK_DIRECTORY}} ${{LINK_LIBRARY}} ${{OBJECT}} -o ${{EXECUTABLE}}

clean :
	${{call INFO,Deleting objects' folder}}
	@rm -rf ${{OBJECT_FOLDER}}
	${{call INFO,Deleting dependencies' folder}}
	@rm -rf ${{DEPEND_FOLDER}}

fclean : clean
	${{call INFO,Deleting executable}}
	@rm -rf ${{EXECUTABLE}}

re : fclean ${{EXECUTABLE}}

info :
	@echo "Objects :"
	@echo ${{OBJECT}}
	@echo "Depends :"
	@echo ${{DEPEND}}

.PHONY : clean fclean re info

#						OBJECTS
	
${{OBJECT_FOLDER}} :
	${{call INFO,Creating objects' folder}}
	@mkdir ${{OBJECT_FOLDER}}

{template_object_rule}	

#						DEPENDENCIES

${{DEPEND_FOLDER}} :
	${{call INFO,Creating dependencies' folder}}
	@mkdir ${{DEPEND_FOLDER}}
	
${{DEPEND}} :

include ${{wildcard ${{DEPEND}}}}	
'''

	object = [generate_object(element) for element in target]
	depend = [generate_depend(element) for element in target]
	object_rule = list()
	for i in range(len(target)):
		object_rule.append(generate_object_rule(source[i], target[i], 100 * (i + 1) // len(target)))

	content = template.format(
		template_compiler = compiler,
		template_project = project,
		template_executable = executable,
		template_flag = concat(flag),
		template_include = concat(include),
		template_link_directory = concat(link_directory),
		template_link_library = concat(link_library),
		template_object = concat(object),
		template_depend = concat(depend),
		template_object_rule = concat(object_rule, '\n'),)
	file = open(path, 'w')
	file.write(content)
	file.close()


'''
					+++ MAIN +++				
'''


def main():
	parser = argparse.ArgumentParser()
	parser.add_argument('-input', '-in', default = 'configuration.txt', type = str)
	parser.add_argument("-output", '-out', default = 'Makefile', type = str)
	parser.add_argument('-info', action = 'store_true')
	args = parser.parse_args()

	work_configuration(args.input)
	work_target()
	work_include()
	work_link_x()

	if args.info:
		print(os.path.basename(__file__) + ' : compiler = ' + str(compiler))
		print(os.path.basename(__file__) + ' : project = ' + str(project))
		print(os.path.basename(__file__) + ' : executable = ' + str(executable))
		print(os.path.basename(__file__) + ' : flag = ' + str(flag))
		print(os.path.basename(__file__) + ' : source = ' + str(source))
		print(os.path.basename(__file__) + ' : target = ' + str(target))
		print(os.path.basename(__file__) + ' : include = ' + str(include))
		print(os.path.basename(__file__) + ' : link directory = ' + str(link_directory))
		print(os.path.basename(__file__) + ' : link library = ' + str(link_library))

	work_makefile(args.output)


try:
	main()
except Exception as exception:
	print('Terminating with exception : ' + str(exception))
