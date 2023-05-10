program matrix_multiplier
    use iso_fortran_env
    implicit none

    integer :: n, i, j, ierr
    real(kind=8), dimension(:,:), allocatable :: A
    real(kind=8), dimension(:), allocatable :: x, b
    character(len=20) :: arg0, arg1
    real :: start, finish, time_elapsed

    call get_command_argument(0, arg0)
    if (command_argument_count() /= 1) then
        print*, "Uso: ", arg0, " <tamanho_sistema>"
        stop
    endif

    ! Tamanho do sistema
    call get_command_argument(1, arg1)
    read(arg1, *) n

    ! Alocar memória para as matrizes A e b e o vetor x
    allocate(A(n,n), stat=ierr)
    allocate(x(n), stat=ierr)
    allocate(b(n), stat=ierr)

    if (ierr /= 0) then
        print*, "Erro ao alocar memória"
        stop
    endif

    ! Inicialização da matriz A e do vetor x com valores aleatórios
    call random_seed()
    call random_number(A)
    call random_number(x)

    b = 0.0

    call cpu_time(start)

    ! Cálculo do produto matriz-vetor A · x = b
    do j = 1, n
        do i = 1, n
            b(i) = b(i) + A(i,j) * x(j)
        enddo
    enddo

    call cpu_time(finish)
    time_elapsed = finish - start

    print '("Tempo de CPU utilizado:  ",f0.7," segundos")', time_elapsed

    ! Liberar memória alocada
    deallocate(A)
    deallocate(x)
    deallocate(b)

end program matrix_multiplier


