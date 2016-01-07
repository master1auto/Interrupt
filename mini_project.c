unsigned cnt;                 // Define variable cnt
void interrupt() {
    cnt++;                    // Interrupt causes cnt to be incremented by 1
    TRISB_bit = 0x01;             // PORTB is returned its initial value
    INTCON = 0x20;            // Bit T0IE is set, bit T0IF is cleared
}
void main() {
    ANSEL = 0;                // All I/O pins are configured as digital
    ANSELH = 0;
    TRISB_bit = 0;            // All port B pins are configured as outputs
    INTCON = 0xA0;            // Enable interrupt TMR0
    cnt = 0;                  // Variable cnt is assigned a 0
    do {                      // Endless loop
        if (cnt == 400) {     // Increment port B after 400 interrupts
            PORTB = PORTB++;  // Increment number on port B by 1
            cnt = 0;          // Reset variable cnt
        }
    } while(1);
}void main() {
unsigned cnt;                 // Define variable cnt
void interrupt() {
    cnt++;                    // Interrupt causes cnt to be incremented by 1
    TMR0 = 96;                // Timer TMR0 is returned its initial value
    INTCON = 0x20;            // Bit T0IE is set, bit T0IF is cleared
}
void main() {
    OPTION_REG = 0x84;        // Prescaler is assigned to timer TMR0
    ANSEL = 0;                // All I/O pins are configured as digital
    ANSELH = 0;
    TRISB = 0;                // All port A pins are configured as outputs
    PORTA = 0x0;              // Reset port A
    TMR0 = 96;                // Timer T0 counts from 96 to 255
    INTCON = 0xA0;            // Enable interrupt TMR0
    cnt = 0;                  // Variable cnt is assigned a 0
    do {                      // Endless loop
        if (cnt == 400) {     // Increment port B after 400 interrupts
            PORTB = PORTB++;  // Increment number on port B by 1
            cnt = 0;          // Reset variable cnt
        }
    } while(1);
}

}
