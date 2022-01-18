#include <gtest/gtest.h>
#include <iostream>
#include <thread>  // sleep_for

#include "timer.h"
#include "utils.h"

// El tiempo transcurrido debiera ser positivo
TEST(TimerTest, positive) {
	Timer my_timer;
	my_timer.Reset();
	double elapsed = my_timer.Elapsed();

  std::cout << "Elapsed: " << elapsed << std::endl;
  EXPECT_GT(elapsed, 0);
	EXPECT_TRUE((elapsed >= 0) && (elapsed <= 0.5)); // elapsed is between 0 and 0.5 
}

// El tiempo transcurrido debiera ser cero o mínimo
TEST(TimerTest, cero) {
	Timer my_timer;
	my_timer.Reset();

	double elapsed =my_timer.Elapsed();
  EXPECT_LT(elapsed, 0.001);
}

// Comprueba el funcionamiento de la temporización usando la función DelaySeconds
TEST(TimerTest, precision) {
  Timer my_timer;
	my_timer.Reset();
  DelaySeconds(1);  // Esperar 1 segundo
	double elapsed =my_timer.Elapsed();
	EXPECT_TRUE((elapsed >= 1.0) && (elapsed <= 1.001)); 

	my_timer.Reset();
  DelaySeconds(2);  // Esperar 2 segundos
	elapsed =my_timer.Elapsed();
	EXPECT_TRUE((elapsed >= 2.0) && (elapsed <= 2.001)); 

	my_timer.Reset();
  DelaySeconds(5);  // Esperar 5 segundos
	elapsed =my_timer.Elapsed();
	EXPECT_TRUE((elapsed >= 5.0) && (elapsed <= 5.001)); 
}


/**
 * Test para probar el método Reset()
 */
TEST(TimerTest, Reset) {
  Timer timer;  // A Timer object
  
  timer.Reset();
  EXPECT_EQ(true, timer.Elapsed() == 0);
}

/**
 * Test para probar el método Elapsed()
 */
TEST(TimerTest, Elapsed) {
  Timer timer;  // A Timer object

  timer.Reset();
  WaitMilliSeconds(1000); // Waits 1 second
  EXPECT_EQ(true, timer.Elapsed() == 1000);

  timer.Reset();
  WaitMilliSeconds(5000); // Waits 5 seconds  
  EXPECT_EQ(true, timer.Elapsed() == 5000);
}
