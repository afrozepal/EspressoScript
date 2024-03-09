#include <omp.h>
#include <stdio.h>
#include <time.h>
// int func = 1 / (1 + x + x * x + x * x * x * x);
// using trapezoidal rule
// that is delta x = (b-a)/n and then :
// (delta x/2) (f(x0) + f(xn) + 2(f(x1) + f(x2) + ... + f(xn)
// I make it as: by taking 2 common from bracket.
// delta x (f(x0)/2 + f(xn)/2 + f(x1) + f(x2) + ... + f(xn))
double serial_calculation(double a, double b, int n) {
  double integral = 0.0;
  double delta_x = (b - a) / n;
  double x0 = 1 / (1 + a + a * a + a * a * a * a);
  double xn = 1 / (1 + b + b * b + b * b * b * b);
  integral += x0 / 2;
  integral += xn / 2;
  double next_x = a + delta_x;

  for (int i = 1; i < n; i++) {

    integral += 1.0 / (1 + next_x + next_x * next_x +
                       next_x * next_x * next_x * next_x);
    next_x += delta_x;
  }

  integral *= (delta_x);
  return integral;
}

double parallel_calculation(double a, double b, int n) {
  double integral = 0.0;
  double delta_x = (b - a) / n;
  double x0 = 1 / (1 + a + a * a + a * a * a * a);
  double xn = 1 / (1 + b + b * b + b * b * b * b);
  integral += x0 / 2;
  integral += xn / 2;

// Parallel region
#pragma omp parallel
  {
    double private_integral = 0.0;

// Each thread computes its own private_integral and then add it to the integral
// one by one
#pragma omp for
    for (int i = 1; i < n; i++) {
      double next_x = a + i * delta_x;
      private_integral += 1.0 / (1 + next_x + next_x * next_x +
                                 next_x * next_x * next_x * next_x);
    }

// in order to make sure that just one thread is executing at once , else it
// will overwrite the value of private_integral
#pragma omp critical
    integral += private_integral;
  }

  integral *= delta_x;
  return integral;
}

int main() {
  double a = 5;
  double b = 10;
  double n = 200;
  // to calculate time for serial
  clock_t start, end;
  double cpu_time_used;
  start = clock();
  double xint = serial_calculation(a, b, n);
  end = clock();
  printf("The integral with n: %f  is: %f : \n", n, xint);
  cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
  printf("Time taken by the serial function: %f seconds\n", cpu_time_used);
  // for parallel
  clock_t start2, end2;
  double cpu_time_used2;
  start2 = clock();
  double xint2 = parallel_calculation(a, b, n);
  end2 = clock();
  printf("The integral with n: %f  is: %f : \n", n, xint2);
  cpu_time_used2 = ((double)(end2 - start2)) / CLOCKS_PER_SEC;
  printf("Time taken by the parallel function: %f seconds\n", cpu_time_used2);
}