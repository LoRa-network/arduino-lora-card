#ifndef _SERIAL_ADAPTER
#define _SERIAL_ADAPTER

#define SERIAL_RATE 9600

#include "Arduino.h"
#include "config.h"
class Serial_adapter{
  String input;
  void (*callbackOnLocalMessage)(String str);
  static Serial_adapter* sa;  
  static String message;  
  static bool new_message;
public:
  static Serial_adapter* getSerialAdapter(){
    if(nullptr == Serial_adapter::sa){
      Serial_adapter::sa = new Serial_adapter();
    }
    return Serial_adapter::sa;
  }
  
  void setCallBackOnLocalMessage(void (*callbackOnLocalMessage)(String str)){
    this->callbackOnLocalMessage = callbackOnLocalMessage;
  }
  void info(String str);
  void info_nnl(String str);

  void serialEvent();
  bool checkNewMessage();

private:
  Serial_adapter();
};


#endif
