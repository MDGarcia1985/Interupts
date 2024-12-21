#include <avr/io.h>
#include <avr/interrupt.h>

#define LED_1_PIN PD3 // Define LED 1 pin for the button
#define LED_2_PIN PD2 // Define LED 2 pin for blinking

volatile uint8_t button_state = 0; // Variable to track button state

void initializeTimer();
void initializeInterrupts();

int main(void) 
{
    // Set LED pins as outputs
    DDRD |= (1 << LED_1_PIN) | (1 << LED_2_PIN); // Set PD3 and PD2 as outputs

    // Set up timer and external interrupts
    initializeTimer();
    initializeInterrupts();

    sei(); // Enable global interrupts

    while (1) 
    {
        // Handle LED 1 based on button state
        if (button_state) 
        {
            PORTD |= (1 << LED_1_PIN); // Turn LED 1 ON
        } else 
        {
            PORTD &= ~(1 << LED_1_PIN); // Turn LED 1 OFF
        }
    }

    return 0;
}

void initializeTimer() 
{
    // Configure Timer1 for CTC mode
    TCCR1B |= (1 << WGM12); // CTC mode
    TCCR1B |= (1 << CS12) | (1 << CS10); // Prescaler 1024
    OCR1A = 15624; // Set compare value for 1-second delay (16MHz clock)

    // Enable Timer1 Compare Match A interrupt
    TIMSK1 |= (1 << OCIE1A);
}

void initializeInterrupts() 
{
    // Configure external interrupt INT0 (on PD2) for the button
    EICRA |= (1 << ISC01); // Falling edge triggers interrupt
    EIMSK |= (1 << INT0);  // Enable INT0
}

ISR(TIMER1_COMPA_vect) 
{
    // Timer interrupt toggles LED 2
    PORTD ^= (1 << LED_2_PIN); // Toggle LED 2
}

ISR(INT0_vect) 
{
    // External interrupt toggles button state
    button_state = !button_state; // Toggle button state
}
