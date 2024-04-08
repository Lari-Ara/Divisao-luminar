#define ledVermelho 5
#define ledAmarelo 4
#define ledVerde 3

int num = 0;
int resultado;

void setup() {
  pinMode(ledVermelho, OUTPUT);
  pinMode(ledAmarelo, OUTPUT);
  pinMode(ledVerde, OUTPUT);
  
  Serial.begin(9600);
  Serial.println("Inicio do criterio");
}

void loop() {
  Serial.println("Digite um numero inteiro");
  while (!Serial.available());
  num = Serial.parseInt(); 
  Serial.println(num);

  resultado = num % 3;
  if(resultado == 0){ 
    Serial.println("Numero divisivel por 3");
    digitalWrite(ledVermelho, HIGH);
    digitalWrite(ledAmarelo, LOW);
    digitalWrite(ledVerde, LOW);
  } else{ 
      digitalWrite(ledVermelho, LOW);
  }
  
  resultado = num % 2;
  if(resultado == 0){ 
    Serial.println("Numero divisivel por 2");
    digitalWrite(ledAmarelo, HIGH);
    digitalWrite(ledVermelho, LOW);
    digitalWrite(ledVerde, LOW);
  } else{
      digitalWrite(ledAmarelo, LOW);
  }
  
 
  if(num % 3 == 0 && num % 2 == 0) {
    Serial.println("Numero divisivel por 2 e por 3");
    digitalWrite(ledVerde, HIGH);
    digitalWrite(ledAmarelo, LOW);
    digitalWrite(ledVermelho, LOW);
  } else {
      digitalWrite(ledVerde, LOW); 
  }
}
