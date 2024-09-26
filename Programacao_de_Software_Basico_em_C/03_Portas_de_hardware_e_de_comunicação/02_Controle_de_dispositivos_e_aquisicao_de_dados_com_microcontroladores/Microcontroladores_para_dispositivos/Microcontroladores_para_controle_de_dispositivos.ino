int velocidade = 0;

void setup(){
	pinMode(10, OUTPUT);
	pinMode(6, INPUT_PULLUP);
}

void loop(){
  delay(200);
  if(digitalRead(6) == LOW){
    velocidade++;
    
    switch(velocidade){
      case 1:
      	analogWrite(10, 64);
      break;
      case 2:
      	analogWrite(10, 128);
      break;
      case 3:
      	analogWrite(10,192);
      break;
      case 4:
      	analogWrite(10, 255);
      break;
      default:
      	velocidade = 0;
      	analogWrite(10,0);
  }
  	}
	 }
      