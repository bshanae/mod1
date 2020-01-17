void kernel			minus(global const int *A, global const int *B, global int *C)
{
    C[get_global_id(0)] = A[get_global_id(0)] - B[get_global_id(0)];
}

void kernel			plus(global const int *A, global const int *B, global int *C)
{
    C[get_global_id(0)] = A[get_global_id(0)] + B[get_global_id(0)];
}