float pump(int o,float t){
  if (o == 0){
    digitalWrite(OP,HIGH);
    //if yes run the pumps for 2 mins*
    delay(t);    
    digitalWrite(OP,LOW);
  }
  else if (o == 1){
    digitalWrite(WP,HIGH);
    //if yes run the pumps for 2 mins*
    delay(t);    
    digitalWrite(WP,LOW);
  }
  else if (o == 2){
    digitalWrite(WP,HIGH);
    //actite servo
    //if yes run the pumps for 2 mins*
    delay(t);    
    digitalWrite(WP,LOW);
    //close servo 
  }
}
