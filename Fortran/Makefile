FC = gfortran
FFLAGS = -Wall -Wextra -O3 -std=f2003

all: matrix-multiplier matrix-multiplier-v2

matrix-multiplier: matrix-multiplier.o
	$(FC) $(FFLAGS) -o matrix-multiplier matrix-multiplier.o

matrix-multiplier-v2: matrix-multiplier-v2.o
	$(FC) $(FFLAGS) -o matrix-multiplier-v2 matrix-multiplier-v2.o


matrix-multiplier.o: matrix-multiplier.f90
	$(FC) $(FFLAGS) -c matrix-multiplier.f90

matrix-multiplier-v2.o: matrix-multiplier-v2.f90
	$(FC) $(FFLAGS) -c matrix-multiplier-v2.f90

clean:
	rm -f *.o matrix-multiplier matrix-multiplier-v2
