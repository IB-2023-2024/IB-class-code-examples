#include <gtest/gtest.h>
#include <iostream>

#include "timer.h"
#include "utils.h"

TEST(TimerTest, positive) {
	      Timer my_timer;
				my_timer.reset();
				double elapsed = my_timer.elapsed();

        std::cout << "Elapsed: " << elapsed << std::endl;
        EXPECT_GT(elapsed, 0);
				EXPECT_TRUE((elapsed >= 0) && (elapsed <= 0.5)); // elapsed is between 0 and 0.5 
}

// El tiempo transcurrido debiera ser cero o mínimo
TEST(TimerTest, cero) {
	      Timer my_timer;
				my_timer.reset();

				double elapsed =my_timer.elapsed();
        EXPECT_LT(elapsed, 0.001);
}

// Comprueba el funcionamiento de la temporización usando la función DelaySeconds
TEST(TimerTest, precision) {
	      Timer my_timer;
				my_timer.reset();
        DelaySeconds(1);  // Esperar 1 segundo
				double elapsed =my_timer.elapsed();
				EXPECT_TRUE((elapsed >= 1.0) && (elapsed <= 1.001)); 

				my_timer.reset();
        DelaySeconds(2);  // Esperar 2 segundos
				elapsed =my_timer.elapsed();
				EXPECT_TRUE((elapsed >= 2.0) && (elapsed <= 2.001)); 

				my_timer.reset();
        DelaySeconds(5);  // Esperar 5 segundos
				elapsed =my_timer.elapsed();
				EXPECT_TRUE((elapsed >= 5.0) && (elapsed <= 5.001)); 
}
