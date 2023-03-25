#include <avr/io.h>
#include <util/delay.h>
#include <stdint.h>

#define LED_PIN PB0
#define BAUD_RATE 9600
#define UBRR_VALUE ((F_CPU / (BAUD_RATE * 16UL)) - 1)

void uart_init(void) {
    // Set baud rate
    UBRR0H = (uint8_t)(UBRR_VALUE >> 8);
    UBRR0L = (uint8_t)(UBRR_VALUE);

    // Enable transmitter
    UCSR0B |= (1 << TXEN0);

    // Set frame format: 8 data bits, 1 stop bit, no parity
    UCSR0C |= (1 << UCSZ01) | (1 << UCSZ00);
}

void uart_transmit(uint8_t data) {
    // Wait for empty transmit buffer
    while (!(UCSR0A & (1 << UDRE0)));

    // Put data into the buffer, which sends the data
    UDR0 = data;
}

int main(void) {
    // Set the LED pin as output
    DDRB |= (1 << LED_PIN);

    // Initialize UART
    uart_init();
        while (1) {
        // Toggle the LED pin state
        PORTB ^= (1 << LED_PIN);

        // Send the LED state over UART ('1' for ON, '0' for OFF)
        uart_transmit((PORTB & (1 << LED_PIN)) ? '1' : '0');

        // Wait for 500 ms
        _delay_ms(500);
    }

    return 0;
}
