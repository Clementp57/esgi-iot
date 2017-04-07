#include <SoftwareSerial.h>

#define BUFFER_SIZE 64

int irPin=2; 
int ledPin=3;

char inData[BUFFER_SIZE];
char inChar=-1;
int i=0;

int count=0;
int isPresent=0;
unsigned long elapsed_time=0;

char recv_str[100];

SoftwareSerial serial_connection(11, 10);

void setup() {
  Serial.begin(9600);
  serial_connection.begin(9600);

  // Setup bluetooth one time and ping python server
  //if(setupBlueToothConnection() != 0) while(1); 
  // ping();
  
  pinMode(ledPin, OUTPUT);
  pinMode(irPin, INPUT);  
}

void loop() {
  // Uncomment to read IR value
  int irValue = digitalRead(irPin);

  if(irValue == 0 && isPresent == 0) {
    count++;
    isPresent = 1;
  } 

  if(irValue == 1 && isPresent == 1) {
    isPresent = 0;
  }

  if(millis()-elapsed_time>5000) {
    // Send count to server and reset count
    Serial.print("Count: ");
    Serial.println(count);
    Serial.println("Sending, and resetting");
    
    serial_connection.println(String(count) + "\0");
    
    count=0;
    elapsed_time=millis();
  }
  
  delay(100); //Pause for a moment   
}

int ping() 
{
   byte byte_count=serial_connection.available();//This gets the number of bytes that were sent by the python script
  if(byte_count)//If there are any bytes then deal with them
  {
    Serial.println("Incoming Data");//Signal to the monitor that something is happening
    int first_bytes=byte_count;//initialize the number of bytes that we might handle. 
    int remaining_bytes=0;//Initialize the bytes that we may have to burn off to prevent a buffer overrun
    if(first_bytes>=BUFFER_SIZE-1)//If the incoming byte count is more than our buffer...
    {
      remaining_bytes =byte_count-(BUFFER_SIZE-1);//Reduce the bytes that we plan on handleing to below the buffer size
    }
    
    for(i=0;i<first_bytes;i++)//Handle the number of incoming bytes
    {
      inChar=serial_connection.read();//Read one byte
      inData[i]=inChar;//Put it into a character string(array)
    }
    inData[i]='\0';//This ends the character array with a null character. This signals the end of a string
    
    for(i=0;i<remaining_bytes;i++)//This burns off any remaining bytes that the buffer can't handle.
    {
      inChar=serial_connection.read();
    }
    Serial.println(inData);//Print to the monitor what was detected
    serial_connection.println("Hello from Blue "+String(count));//Then send an incrmented string back to the python script
    count++;//Increment the line counter
  }
}

// send command to Bluetooth and return if there is a response
int sendBlueToothCommand(char command[])
{
    Serial.print("send: ");
    Serial.print(command);
    Serial.println("");

    Serial3.print(command);

    if(recvMsg(5000) != 0) return -1;

    Serial.print("recv: ");
    Serial.print(recv_str);
    Serial.println("");
    return 0;
}

int tryATCommand(long baud)
{
  delay(500);
  Serial3.begin(baud);
  delay(500);
  Serial.print("try ");
  Serial.println(baud);
  return sendBlueToothCommand("AT\r\n");
}

//receive message from Bluetooth with time out
int recvMsg(unsigned int timeout)
{
    //wait for feedback
    unsigned int time = 0;
    unsigned char num;
    unsigned char i;
    
    //waiting for the first character with time out
    i = 0;
    while(1)
    {
        delay(50);
        if(Serial3.available())
        {
            char c = Serial3.read();
            recv_str[i] = c;
            i++;
            break;
        }
        time++;
        if(time > (timeout / 50)) {
          Serial.println("Timeout...");
          return -1;
        }
    }

    //read other characters from uart buffer to string
    while(Serial3.available() && (i < 100))
    {                                              
        recv_str[i] = Serial3.read();
        i++;
    }
    recv_str[i] = '\0';

    return 0;
}

//configure the Bluetooth through AT commands
int setupBlueToothConnection()
{
    Serial.print("Setting up Bluetooth link\r\n");
    delay(2000);//wait for module restart

    //send command to module in different baud rate
    while(1)
    {   
        if (tryATCommand(38400) == 0) break;
        delay(500);
    }

    // Sets device name
    Serial.println(sendBlueToothCommand("AT+NAME=ArduinoBLE_CD\r\n")); 

    // Sets device password
    Serial.println(sendBlueToothCommand("AT+PSWD=testpassword\r\n")); 

    // Get mac address
    Serial.println(sendBlueToothCommand("AT+ADDR?\r\n"));

    Serial.print("AT+RESET : ");
    Serial.println(sendBlueToothCommand("AT+RESET\r\n"));

    /*
    //we have to set the baud rate to 9600, since the soft serial is not stable at 115200
    sendBlueToothCommand("AT+RENEW");//restore factory configurations
    sendBlueToothCommand("AT+BAUD2");//reset the module's baud rate
    sendBlueToothCommand("AT+AUTH1");//enable authentication
    sendBlueToothCommand("AT+RESET");//restart module to take effect
    blueToothSerial.begin(115200);//reset the Arduino's baud rate
    */

    Serial.print("Setup complete\r\n\r\n");
    return 0;
}
