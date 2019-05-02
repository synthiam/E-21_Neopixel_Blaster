#include <main.h>

volatile char _buffer[240];     // This buffer is used to transmit to the neo pixels. support for 80 neopixels per channel
volatile char _outputPort;
volatile char _bufferSize;

volatile char _bufferRecv[240]; // This buffer is used in the receive from the COMM. support for 80 neopixels per channel
volatile char _outputPortRecv;
volatile char _bufferSizeRecv;

volatile char _inputState; // 0 = get port, 1 = number of leds, 2 = data
volatile char _inputPosition;
volatile int1 _startSending;

#INT_RDA
void  RDA_isr(void) {
  
  switch (_inputState) {
  
    case 0:
    
      // get the port
      _outputPortRecv = getc(COMM);
           
      // next read byte is the number of leds
      _inputState = 1;
      
      break;

    case 1:
    
      // get the number of leds
      _bufferSizeRecv = getc(COMM);
            
      // multiply the number of leds by 3 to get the buffer size (for each color of red green blue)
      _bufferSizeRecv += _bufferSizeRecv + _bufferSizeRecv;
              
      // all next bytes are the data
      _inputState = 2;
      
      break;
      
    case 2:

      _bufferRecv[_inputPosition] = getc(COMM);
      
      _inputPosition++;
      
      if (_inputPosition == _bufferSizeRecv)        
        _startSending = true; // tell the main loop to start sending
      
      break;
  }  
}

#inline
void ChangeLED0() {

  for (unsigned int16 p=0; p < _bufferSize; p++) {
  
    char dataByte = _buffer[p];
    
    if (bit_test(dataByte, 7)) {
    
      output_high(pin_a5);
      delay_cycles(DELAY_HIGH_1);
      output_low(pin_a5);
//        delay_cycles(DELAY_LOW_1);
    } else {
    
      output_high(pin_a5);
      delay_cycles(DELAY_HIGH_0);
      output_low(pin_a5);
      delay_cycles(DELAY_LOW_0);
    }             
    
    if (bit_test(dataByte, 6)) {
    
      output_high(pin_a5);
      delay_cycles(DELAY_HIGH_1);
      output_low(pin_a5);
//        delay_cycles(DELAY_LOW_1);
    } else {
    
      output_high(pin_a5);
      delay_cycles(DELAY_HIGH_0);
      output_low(pin_a5);
      delay_cycles(DELAY_LOW_0);
    }             
    
    if (bit_test(dataByte, 5)) {
    
      output_high(pin_a5);
      delay_cycles(DELAY_HIGH_1);
      output_low(pin_a5);
//        delay_cycles(DELAY_LOW_1);
    } else {
    
      output_high(pin_a5);
      delay_cycles(DELAY_HIGH_0);
      output_low(pin_a5);
      delay_cycles(DELAY_LOW_0);
    }             
    
    if (bit_test(dataByte, 4)) {
    
      output_high(pin_a5);
      delay_cycles(DELAY_HIGH_1);
      output_low(pin_a5);
//        delay_cycles(DELAY_LOW_1);
    } else {
    
      output_high(pin_a5);
      delay_cycles(DELAY_HIGH_0);
      output_low(pin_a5);
      delay_cycles(DELAY_LOW_0);
    }             
    
    if (bit_test(dataByte, 3)) {
    
      output_high(pin_a5);
      delay_cycles(DELAY_HIGH_1);
      output_low(pin_a5);
//        delay_cycles(DELAY_LOW_1);
    } else {
    
      output_high(pin_a5);
      delay_cycles(DELAY_HIGH_0);
      output_low(pin_a5);
      delay_cycles(DELAY_LOW_0);
    }             
    
    if (bit_test(dataByte, 2)) {
    
      output_high(pin_a5);
      delay_cycles(DELAY_HIGH_1);
      output_low(pin_a5);
//        delay_cycles(DELAY_LOW_1);
    } else {
    
      output_high(pin_a5);
      delay_cycles(DELAY_HIGH_0);
      output_low(pin_a5);
      delay_cycles(DELAY_LOW_0);
    }             
    
    if (bit_test(dataByte, 1)) {
    
      output_high(pin_a5);
      delay_cycles(DELAY_HIGH_1);
      output_low(pin_a5);
//        delay_cycles(DELAY_LOW_1);
    } else {
    
      output_high(pin_a5);
      delay_cycles(DELAY_HIGH_0);
      output_low(pin_a5);
      delay_cycles(DELAY_LOW_0);
    }             

    if (bit_test(dataByte, 0)) {
    
      output_high(pin_a5);
      delay_cycles(DELAY_HIGH_1);
      output_low(pin_a5);
//        delay_cycles(DELAY_LOW_1);
    } else {
    
      output_high(pin_a5);
      delay_cycles(DELAY_HIGH_0);
      output_low(pin_a5);
      delay_cycles(DELAY_LOW_0);
    }             
  }
}

#inline
void ChangeLED1() {

  for (unsigned int16 p=0; p < _bufferSize; p++) {
  
    char dataByte = _buffer[p];
    
    if (bit_test(dataByte, 7)) {
    
      output_high(pin_a4);
      delay_cycles(DELAY_HIGH_1);
      output_low(pin_a4);
//        delay_cycles(DELAY_LOW_1);
    } else {
    
      output_high(pin_a4);
      delay_cycles(DELAY_HIGH_0);
      output_low(pin_a4);
      delay_cycles(DELAY_LOW_0);
    }             
    
    if (bit_test(dataByte, 6)) {
    
      output_high(pin_a4);
      delay_cycles(DELAY_HIGH_1);
      output_low(pin_a4);
//        delay_cycles(DELAY_LOW_1);
    } else {
    
      output_high(pin_a4);
      delay_cycles(DELAY_HIGH_0);
      output_low(pin_a4);
      delay_cycles(DELAY_LOW_0);
    }             
    
    if (bit_test(dataByte, 5)) {
    
      output_high(pin_a4);
      delay_cycles(DELAY_HIGH_1);
      output_low(pin_a4);
//        delay_cycles(DELAY_LOW_1);
    } else {
    
      output_high(pin_a4);
      delay_cycles(DELAY_HIGH_0);
      output_low(pin_a4);
      delay_cycles(DELAY_LOW_0);
    }             
    
    if (bit_test(dataByte, 4)) {
    
      output_high(pin_a4);
      delay_cycles(DELAY_HIGH_1);
      output_low(pin_a4);
//        delay_cycles(DELAY_LOW_1);
    } else {
    
      output_high(pin_a4);
      delay_cycles(DELAY_HIGH_0);
      output_low(pin_a4);
      delay_cycles(DELAY_LOW_0);
    }             
    
    if (bit_test(dataByte, 3)) {
    
      output_high(pin_a4);
      delay_cycles(DELAY_HIGH_1);
      output_low(pin_a4);
//        delay_cycles(DELAY_LOW_1);
    } else {
    
      output_high(pin_a4);
      delay_cycles(DELAY_HIGH_0);
      output_low(pin_a4);
      delay_cycles(DELAY_LOW_0);
    }             
    
    if (bit_test(dataByte, 2)) {
    
      output_high(pin_a4);
      delay_cycles(DELAY_HIGH_1);
      output_low(pin_a4);
//        delay_cycles(DELAY_LOW_1);
    } else {
    
      output_high(pin_a4);
      delay_cycles(DELAY_HIGH_0);
      output_low(pin_a4);
      delay_cycles(DELAY_LOW_0);
    }             
    
    if (bit_test(dataByte, 1)) {
    
      output_high(pin_a4);
      delay_cycles(DELAY_HIGH_1);
      output_low(pin_a4);
//        delay_cycles(DELAY_LOW_1);
    } else {
    
      output_high(pin_a4);
      delay_cycles(DELAY_HIGH_0);
      output_low(pin_a4);
      delay_cycles(DELAY_LOW_0);
    }             

    if (bit_test(dataByte, 0)) {
    
      output_high(pin_a4);
      delay_cycles(DELAY_HIGH_1);
      output_low(pin_a4);
//        delay_cycles(DELAY_LOW_1);
    } else {
    
      output_high(pin_a4);
      delay_cycles(DELAY_HIGH_0);
      output_low(pin_a4);
      delay_cycles(DELAY_LOW_0);
    }             
  }
}

#inline
void ChangeLED2() {

  for (unsigned int16 p=0; p < _bufferSize; p++) {
  
    char dataByte = _buffer[p];
    
    if (bit_test(dataByte, 7)) {
    
      output_high(pin_c4);
      delay_cycles(DELAY_HIGH_1);
      output_low(pin_c4);
//        delay_cycles(DELAY_LOW_1);
    } else {
    
      output_high(pin_c4);
      delay_cycles(DELAY_HIGH_0);
      output_low(pin_c4);
      delay_cycles(DELAY_LOW_0);
    }             
    
    if (bit_test(dataByte, 6)) {
    
      output_high(pin_c4);
      delay_cycles(DELAY_HIGH_1);
      output_low(pin_c4);
//        delay_cycles(DELAY_LOW_1);
    } else {
    
      output_high(pin_c4);
      delay_cycles(DELAY_HIGH_0);
      output_low(pin_c4);
      delay_cycles(DELAY_LOW_0);
    }             
    
    if (bit_test(dataByte, 5)) {
    
      output_high(pin_c4);
      delay_cycles(DELAY_HIGH_1);
      output_low(pin_c4);
//        delay_cycles(DELAY_LOW_1);
    } else {
    
      output_high(pin_c4);
      delay_cycles(DELAY_HIGH_0);
      output_low(pin_c4);
      delay_cycles(DELAY_LOW_0);
    }             
    
    if (bit_test(dataByte, 4)) {
    
      output_high(pin_c4);
      delay_cycles(DELAY_HIGH_1);
      output_low(pin_c4);
//        delay_cycles(DELAY_LOW_1);
    } else {
    
      output_high(pin_c4);
      delay_cycles(DELAY_HIGH_0);
      output_low(pin_c4);
      delay_cycles(DELAY_LOW_0);
    }             
    
    if (bit_test(dataByte, 3)) {
    
      output_high(pin_c4);
      delay_cycles(DELAY_HIGH_1);
      output_low(pin_c4);
//        delay_cycles(DELAY_LOW_1);
    } else {
    
      output_high(pin_c4);
      delay_cycles(DELAY_HIGH_0);
      output_low(pin_c4);
      delay_cycles(DELAY_LOW_0);
    }             
    
    if (bit_test(dataByte, 2)) {
    
      output_high(pin_c4);
      delay_cycles(DELAY_HIGH_1);
      output_low(pin_c4);
//        delay_cycles(DELAY_LOW_1);
    } else {
    
      output_high(pin_c4);
      delay_cycles(DELAY_HIGH_0);
      output_low(pin_c4);
      delay_cycles(DELAY_LOW_0);
    }             
    
    if (bit_test(dataByte, 1)) {
    
      output_high(pin_c4);
      delay_cycles(DELAY_HIGH_1);
      output_low(pin_c4);
//        delay_cycles(DELAY_LOW_1);
    } else {
    
      output_high(pin_c4);
      delay_cycles(DELAY_HIGH_0);
      output_low(pin_c4);
      delay_cycles(DELAY_LOW_0);
    }             

    if (bit_test(dataByte, 0)) {
    
      output_high(pin_c4);
      delay_cycles(DELAY_HIGH_1);
      output_low(pin_c4);
//        delay_cycles(DELAY_LOW_1);
    } else {
    
      output_high(pin_c4);
      delay_cycles(DELAY_HIGH_0);
      output_low(pin_c4);
      delay_cycles(DELAY_LOW_0);
    }             
  }
}

#inline
void ChangeLED3() {

  for (unsigned int16 p=0; p < _bufferSize; p++) {
  
    char dataByte = _buffer[p];
    
    if (bit_test(dataByte, 7)) {
    
      output_high(pin_c3);
      delay_cycles(DELAY_HIGH_1);
      output_low(pin_c3);
//        delay_cycles(DELAY_LOW_1);
    } else {
    
      output_high(pin_c3);
      delay_cycles(DELAY_HIGH_0);
      output_low(pin_c3);
      delay_cycles(DELAY_LOW_0);
    }             
    
    if (bit_test(dataByte, 6)) {
    
      output_high(pin_c3);
      delay_cycles(DELAY_HIGH_1);
      output_low(pin_c3);
//        delay_cycles(DELAY_LOW_1);
    } else {
    
      output_high(pin_c3);
      delay_cycles(DELAY_HIGH_0);
      output_low(pin_c3);
      delay_cycles(DELAY_LOW_0);
    }             
    
    if (bit_test(dataByte, 5)) {
    
      output_high(pin_c3);
      delay_cycles(DELAY_HIGH_1);
      output_low(pin_c3);
//        delay_cycles(DELAY_LOW_1);
    } else {
    
      output_high(pin_c3);
      delay_cycles(DELAY_HIGH_0);
      output_low(pin_c3);
      delay_cycles(DELAY_LOW_0);
    }             
    
    if (bit_test(dataByte, 4)) {
    
      output_high(pin_c3);
      delay_cycles(DELAY_HIGH_1);
      output_low(pin_c3);
//        delay_cycles(DELAY_LOW_1);
    } else {
    
      output_high(pin_c3);
      delay_cycles(DELAY_HIGH_0);
      output_low(pin_c3);
      delay_cycles(DELAY_LOW_0);
    }             
    
    if (bit_test(dataByte, 3)) {
    
      output_high(pin_c3);
      delay_cycles(DELAY_HIGH_1);
      output_low(pin_c3);
//        delay_cycles(DELAY_LOW_1);
    } else {
    
      output_high(pin_c3);
      delay_cycles(DELAY_HIGH_0);
      output_low(pin_c3);
      delay_cycles(DELAY_LOW_0);
    }             
    
    if (bit_test(dataByte, 2)) {
    
      output_high(pin_c3);
      delay_cycles(DELAY_HIGH_1);
      output_low(pin_c3);
//        delay_cycles(DELAY_LOW_1);
    } else {
    
      output_high(pin_c3);
      delay_cycles(DELAY_HIGH_0);
      output_low(pin_c3);
      delay_cycles(DELAY_LOW_0);
    }             
    
    if (bit_test(dataByte, 1)) {
    
      output_high(pin_c3);
      delay_cycles(DELAY_HIGH_1);
      output_low(pin_c3);
//        delay_cycles(DELAY_LOW_1);
    } else {
    
      output_high(pin_c3);
      delay_cycles(DELAY_HIGH_0);
      output_low(pin_c3);
      delay_cycles(DELAY_LOW_0);
    }             

    if (bit_test(dataByte, 0)) {
    
      output_high(pin_c3);
      delay_cycles(DELAY_HIGH_1);
      output_low(pin_c3);
//        delay_cycles(DELAY_LOW_1);
    } else {
    
      output_high(pin_c3);
      delay_cycles(DELAY_HIGH_0);
      output_low(pin_c3);
      delay_cycles(DELAY_LOW_0);
    }             
  }
}

#inline
void ChangeLED4() {

  for (unsigned int16 p=0; p < _bufferSize; p++) {
  
    char dataByte = _buffer[p];
    
    if (bit_test(dataByte, 7)) {
    
      output_high(pin_a2);
      delay_cycles(DELAY_HIGH_1);
      output_low(pin_a2);
//        delay_cycles(DELAY_LOW_1);
    } else {
    
      output_high(pin_a2);
      delay_cycles(DELAY_HIGH_0);
      output_low(pin_a2);
      delay_cycles(DELAY_LOW_0);
    }             
    
    if (bit_test(dataByte, 6)) {
    
      output_high(pin_a2);
      delay_cycles(DELAY_HIGH_1);
      output_low(pin_a2);
//        delay_cycles(DELAY_LOW_1);
    } else {
    
      output_high(pin_a2);
      delay_cycles(DELAY_HIGH_0);
      output_low(pin_a2);
      delay_cycles(DELAY_LOW_0);
    }             
    
    if (bit_test(dataByte, 5)) {
    
      output_high(pin_a2);
      delay_cycles(DELAY_HIGH_1);
      output_low(pin_a2);
//        delay_cycles(DELAY_LOW_1);
    } else {
    
      output_high(pin_a2);
      delay_cycles(DELAY_HIGH_0);
      output_low(pin_a2);
      delay_cycles(DELAY_LOW_0);
    }             
    
    if (bit_test(dataByte, 4)) {
    
      output_high(pin_a2);
      delay_cycles(DELAY_HIGH_1);
      output_low(pin_a2);
//        delay_cycles(DELAY_LOW_1);
    } else {
    
      output_high(pin_a2);
      delay_cycles(DELAY_HIGH_0);
      output_low(pin_a2);
      delay_cycles(DELAY_LOW_0);
    }             
    
    if (bit_test(dataByte, 3)) {
    
      output_high(pin_a2);
      delay_cycles(DELAY_HIGH_1);
      output_low(pin_a2);
//        delay_cycles(DELAY_LOW_1);
    } else {
    
      output_high(pin_a2);
      delay_cycles(DELAY_HIGH_0);
      output_low(pin_a2);
      delay_cycles(DELAY_LOW_0);
    }             
    
    if (bit_test(dataByte, 2)) {
    
      output_high(pin_a2);
      delay_cycles(DELAY_HIGH_1);
      output_low(pin_a2);
//        delay_cycles(DELAY_LOW_1);
    } else {
    
      output_high(pin_a2);
      delay_cycles(DELAY_HIGH_0);
      output_low(pin_a2);
      delay_cycles(DELAY_LOW_0);
    }             
    
    if (bit_test(dataByte, 1)) {
    
      output_high(pin_a2);
      delay_cycles(DELAY_HIGH_1);
      output_low(pin_a2);
//        delay_cycles(DELAY_LOW_1);
    } else {
    
      output_high(pin_a2);
      delay_cycles(DELAY_HIGH_0);
      output_low(pin_a2);
      delay_cycles(DELAY_LOW_0);
    }             

    if (bit_test(dataByte, 0)) {
    
      output_high(pin_a2);
      delay_cycles(DELAY_HIGH_1);
      output_low(pin_a2);
//        delay_cycles(DELAY_LOW_1);
    } else {
    
      output_high(pin_a2);
      delay_cycles(DELAY_HIGH_0);
      output_low(pin_a2);
      delay_cycles(DELAY_LOW_0);
    }             
  }
}

#inline
void ChangeLED5() {

  for (unsigned int16 p=0; p < _bufferSize; p++) {
  
    char dataByte = _buffer[p];
    
    if (bit_test(dataByte, 7)) {
    
      output_high(pin_c0);
      delay_cycles(DELAY_HIGH_1);
      output_low(pin_c0);
//        delay_cycles(DELAY_LOW_1);
    } else {
    
      output_high(pin_c0);
      delay_cycles(DELAY_HIGH_0);
      output_low(pin_c0);
      delay_cycles(DELAY_LOW_0);
    }             
    
    if (bit_test(dataByte, 6)) {
    
      output_high(pin_c0);
      delay_cycles(DELAY_HIGH_1);
      output_low(pin_c0);
//        delay_cycles(DELAY_LOW_1);
    } else {
    
      output_high(pin_c0);
      delay_cycles(DELAY_HIGH_0);
      output_low(pin_c0);
      delay_cycles(DELAY_LOW_0);
    }             
    
    if (bit_test(dataByte, 5)) {
    
      output_high(pin_c0);
      delay_cycles(DELAY_HIGH_1);
      output_low(pin_c0);
//        delay_cycles(DELAY_LOW_1);
    } else {
    
      output_high(pin_c0);
      delay_cycles(DELAY_HIGH_0);
      output_low(pin_c0);
      delay_cycles(DELAY_LOW_0);
    }             
    
    if (bit_test(dataByte, 4)) {
    
      output_high(pin_c0);
      delay_cycles(DELAY_HIGH_1);
      output_low(pin_c0);
//        delay_cycles(DELAY_LOW_1);
    } else {
    
      output_high(pin_c0);
      delay_cycles(DELAY_HIGH_0);
      output_low(pin_c0);
      delay_cycles(DELAY_LOW_0);
    }             
    
    if (bit_test(dataByte, 3)) {
    
      output_high(pin_c0);
      delay_cycles(DELAY_HIGH_1);
      output_low(pin_c0);
//        delay_cycles(DELAY_LOW_1);
    } else {
    
      output_high(pin_c0);
      delay_cycles(DELAY_HIGH_0);
      output_low(pin_c0);
      delay_cycles(DELAY_LOW_0);
    }             
    
    if (bit_test(dataByte, 2)) {
    
      output_high(pin_c0);
      delay_cycles(DELAY_HIGH_1);
      output_low(pin_c0);
//        delay_cycles(DELAY_LOW_1);
    } else {
    
      output_high(pin_c0);
      delay_cycles(DELAY_HIGH_0);
      output_low(pin_c0);
      delay_cycles(DELAY_LOW_0);
    }             
    
    if (bit_test(dataByte, 1)) {
    
      output_high(pin_c0);
      delay_cycles(DELAY_HIGH_1);
      output_low(pin_c0);
//        delay_cycles(DELAY_LOW_1);
    } else {
    
      output_high(pin_c0);
      delay_cycles(DELAY_HIGH_0);
      output_low(pin_c0);
      delay_cycles(DELAY_LOW_0);
    }             

    if (bit_test(dataByte, 0)) {
    
      output_high(pin_c0);
      delay_cycles(DELAY_HIGH_1);
      output_low(pin_c0);
//        delay_cycles(DELAY_LOW_1);
    } else {
    
      output_high(pin_c0);
      delay_cycles(DELAY_HIGH_0);
      output_low(pin_c0);
      delay_cycles(DELAY_LOW_0);
    }             
  }
}

#inline
void ChangeLED6() {

  for (unsigned int16 p=0; p < _bufferSize; p++) {
  
    char dataByte = _buffer[p];
    
    if (bit_test(dataByte, 7)) {
    
      output_high(pin_c1);
      delay_cycles(DELAY_HIGH_1);
      output_low(pin_c1);
//        delay_cycles(DELAY_LOW_1);
    } else {
    
      output_high(pin_c1);
      delay_cycles(DELAY_HIGH_0);
      output_low(pin_c1);
      delay_cycles(DELAY_LOW_0);
    }             
    
    if (bit_test(dataByte, 6)) {
    
      output_high(pin_c1);
      delay_cycles(DELAY_HIGH_1);
      output_low(pin_c1);
//        delay_cycles(DELAY_LOW_1);
    } else {
    
      output_high(pin_c1);
      delay_cycles(DELAY_HIGH_0);
      output_low(pin_c1);
      delay_cycles(DELAY_LOW_0);
    }             
    
    if (bit_test(dataByte, 5)) {
    
      output_high(pin_c1);
      delay_cycles(DELAY_HIGH_1);
      output_low(pin_c1);
//        delay_cycles(DELAY_LOW_1);
    } else {
    
      output_high(pin_c1);
      delay_cycles(DELAY_HIGH_0);
      output_low(pin_c1);
      delay_cycles(DELAY_LOW_0);
    }             
    
    if (bit_test(dataByte, 4)) {
    
      output_high(pin_c1);
      delay_cycles(DELAY_HIGH_1);
      output_low(pin_c1);
//        delay_cycles(DELAY_LOW_1);
    } else {
    
      output_high(pin_c1);
      delay_cycles(DELAY_HIGH_0);
      output_low(pin_c1);
      delay_cycles(DELAY_LOW_0);
    }             
    
    if (bit_test(dataByte, 3)) {
    
      output_high(pin_c1);
      delay_cycles(DELAY_HIGH_1);
      output_low(pin_c1);
//        delay_cycles(DELAY_LOW_1);
    } else {
    
      output_high(pin_c1);
      delay_cycles(DELAY_HIGH_0);
      output_low(pin_c1);
      delay_cycles(DELAY_LOW_0);
    }             
    
    if (bit_test(dataByte, 2)) {
    
      output_high(pin_c1);
      delay_cycles(DELAY_HIGH_1);
      output_low(pin_c1);
//        delay_cycles(DELAY_LOW_1);
    } else {
    
      output_high(pin_c1);
      delay_cycles(DELAY_HIGH_0);
      output_low(pin_c1);
      delay_cycles(DELAY_LOW_0);
    }             
    
    if (bit_test(dataByte, 1)) {
    
      output_high(pin_c1);
      delay_cycles(DELAY_HIGH_1);
      output_low(pin_c1);
//        delay_cycles(DELAY_LOW_1);
    } else {
    
      output_high(pin_c1);
      delay_cycles(DELAY_HIGH_0);
      output_low(pin_c1);
      delay_cycles(DELAY_LOW_0);
    }             

    if (bit_test(dataByte, 0)) {
    
      output_high(pin_c1);
      delay_cycles(DELAY_HIGH_1);
      output_low(pin_c1);
//        delay_cycles(DELAY_LOW_1);
    } else {
    
      output_high(pin_c1);
      delay_cycles(DELAY_HIGH_0);
      output_low(pin_c1);
      delay_cycles(DELAY_LOW_0);
    }             
  }
}

#inline
void ChangeLED7() {

  for (unsigned int16 p=0; p < _bufferSize; p++) {
  
    char dataByte = _buffer[p];
    
    if (bit_test(dataByte, 7)) {
    
      output_high(pin_c2);
      delay_cycles(DELAY_HIGH_1);
      output_low(pin_c2);
//        delay_cycles(DELAY_LOW_1);
    } else {
    
      output_high(pin_c2);
      delay_cycles(DELAY_HIGH_0);
      output_low(pin_c2);
      delay_cycles(DELAY_LOW_0);
    }             
    
    if (bit_test(dataByte, 6)) {
    
      output_high(pin_c2);
      delay_cycles(DELAY_HIGH_1);
      output_low(pin_c2);
//        delay_cycles(DELAY_LOW_1);
    } else {
    
      output_high(pin_c2);
      delay_cycles(DELAY_HIGH_0);
      output_low(pin_c2);
      delay_cycles(DELAY_LOW_0);
    }             
    
    if (bit_test(dataByte, 5)) {
    
      output_high(pin_c2);
      delay_cycles(DELAY_HIGH_1);
      output_low(pin_c2);
//        delay_cycles(DELAY_LOW_1);
    } else {
    
      output_high(pin_c2);
      delay_cycles(DELAY_HIGH_0);
      output_low(pin_c2);
      delay_cycles(DELAY_LOW_0);
    }             
    
    if (bit_test(dataByte, 4)) {
    
      output_high(pin_c2);
      delay_cycles(DELAY_HIGH_1);
      output_low(pin_c2);
//        delay_cycles(DELAY_LOW_1);
    } else {
    
      output_high(pin_c2);
      delay_cycles(DELAY_HIGH_0);
      output_low(pin_c2);
      delay_cycles(DELAY_LOW_0);
    }             
    
    if (bit_test(dataByte, 3)) {
    
      output_high(pin_c2);
      delay_cycles(DELAY_HIGH_1);
      output_low(pin_c2);
//        delay_cycles(DELAY_LOW_1);
    } else {
    
      output_high(pin_c2);
      delay_cycles(DELAY_HIGH_0);
      output_low(pin_c2);
      delay_cycles(DELAY_LOW_0);
    }             
    
    if (bit_test(dataByte, 2)) {
    
      output_high(pin_c2);
      delay_cycles(DELAY_HIGH_1);
      output_low(pin_c2);
//        delay_cycles(DELAY_LOW_1);
    } else {
    
      output_high(pin_c2);
      delay_cycles(DELAY_HIGH_0);
      output_low(pin_c2);
      delay_cycles(DELAY_LOW_0);
    }             
    
    if (bit_test(dataByte, 1)) {
    
      output_high(pin_c2);
      delay_cycles(DELAY_HIGH_1);
      output_low(pin_c2);
//        delay_cycles(DELAY_LOW_1);
    } else {
    
      output_high(pin_c2);
      delay_cycles(DELAY_HIGH_0);
      output_low(pin_c2);
      delay_cycles(DELAY_LOW_0);
    }             

    if (bit_test(dataByte, 0)) {
    
      output_high(pin_c2);
      delay_cycles(DELAY_HIGH_1);
      output_low(pin_c2);
//        delay_cycles(DELAY_LOW_1);
    } else {
    
      output_high(pin_c2);
      delay_cycles(DELAY_HIGH_0);
      output_low(pin_c2);
      delay_cycles(DELAY_LOW_0);
    }             
  }
}

void main() {

  enable_interrupts(INT_RDA);
  enable_interrupts(GLOBAL);

  // initialize the i/o for the led communications
  output_drive(pin_a5);
  output_drive(pin_a4);
  output_drive(pin_c4);
  output_drive(pin_c3);
  output_drive(pin_a2);
  output_drive(pin_c0);
  output_drive(pin_c1);
  output_drive(pin_c2);
  
  // 0 means waiting for the port on next receive byte
  _inputState = 0;
  
  // reset to the beginning of the buffer for populating
  _inputPosition = 0;

  // do not send when we begin
  _startSending = false;

  while (true) {

    while (!_startSending);

    // 0 means waiting for the port
    _inputState = 0;
    
    // 0 is the first position of the buffer
    _inputPosition = 0;

    // reset the send status to not send
    _startSending = false;

    // copy the data from the receive buffer to the transmit buffer
    for (char tr = 0; tr < _bufferSizeRecv; tr++)
      _buffer[tr] = _bufferRecv[tr];

    _bufferSize = _bufferSizeRecv;
    _outputPort = _outputPortRecv;
 
    switch (_outputPort) {
    
      case 0:
        ChangeLED0();
        break;
      case 1:
        ChangeLED1();
        break;
      case 2:
        ChangeLED2();
        break;
      case 3:
        ChangeLED3();
        break;
      case 4:
        ChangeLED4();
        break;
      case 5:
        ChangeLED5();
        break;
      case 6:
        ChangeLED6();
        break;
      case 7:
        ChangeLED7();
        break;
    }        
  }
}
