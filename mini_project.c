void main(){
unsigned cnt;                 // Define variable cnt
void interrupt() {
    cnt++;                    // Interrupt causes cnt to be incremented by 1
    TRISB_bit = 0x01;         // PORTB is returned its initial value
}
void main() {
    ANSEL = 0;                // All I/O pins are configured as digital
    ANSELH = 0;
    TRISB_bit = 0;            // All port B pins are configured as outputs
    cnt = 0;                  // Variable cnt is assigned a 0
    do {                      // Endless loop
        if (cnt == 400) {     // Increment port B after 400 interrupts
            PORTB = PORTB++;  // Increment number on port B by 1
            cnt = 0;          // Reset variable cnt
        }
    } while(1);
}


