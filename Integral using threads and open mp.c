#include <omp.h>
#include <stdio.h>

#define NUM_THREADS 4 // number of threads going to use to use
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

  integral *= (delta_x); // according to formula
  return integral;
}

double parallel_calculation(double a, double b, int n) {
  double integral = 0.0;
  double delta_x = (b - a) / n;
  double thread_integral[NUM_THREADS] = {0.0};

#pragma omp parallel num_threads(NUM_THREADS)
  {
    int thread_id = omp_get_thread_num();
    double local_integral = 0.0;

    // integral calculation , i*delta_x , to get next thread interval.
    //  as x+x+x=3*x;
    for (int i = thread_id; i < n; i += NUM_THREADS) {
      double x = a + i * delta_x; // i starts from 0 ,
      local_integral += 1.0 / (1 + x + x * x + x * x * x * x);
    }

    // Storing the integral of each thread respectively
    thread_integral[thread_id] = local_integral;
  }

  // summ all integrals solved by threads
  for (int i = 0; i < NUM_THREADS; i++) {
    integral += thread_integral[i];
  }

  integral *= delta_x;
  return integral;
}

void print_table(double s_time, double p_time) {
  printf("-----------------------------------------------------\n");
  printf("|     Method    |    Elapsed Time                    |\n");
  printf("|---------------|------------------------------------|\n");
  printf("|    Serial     |    %f                        |\n", s_time);
  printf("|    Parallel   |    %f                        |\n", p_time);
  printf("-----------------------------------------------------\n");
}

int main() {
  double a = 5;
  double b = 10;
  double n = 200;
  // to calculate time for serial

  double start_time = omp_get_wtime();
  double xint = serial_calculation(a, b, n);
  double end_time = omp_get_wtime();
  printf("The integral with n: %f  is: %f : \n", n, xint);
  double serial_t1 = end_time - start_time;
  printf("Time taken by the serial function: %f seconds\n", serial_t1);
  // for parallel
  start_time = omp_get_wtime();
  double xint2 = parallel_calculation(a, b, n);
  end_time = omp_get_wtime();
  printf("The integral with n: %f  is: %f : \n", n, xint2);
  double parallel_t1 = end_time - start_time;
  printf("Time taken by the parallel function: %f seconds\n", parallel_t1);

  // to print in table form
  print_table(serial_t1, parallel_t1);
}