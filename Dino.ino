//DINOSAURIO GOOGLE

#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

byte DINO_PARADO_PARTE_1[8] = {B00000, B00000, B00010, B00010, B00011, B00011, B00001, B00001}; 
byte DINO_PARADO_PARTE_2[8] = {B00111, B00111, B00111, B00100, B11100, B11100, B11000, B01000};
byte DINO_PIE_DERE_PART_1[8] = {B00000, B00000, B00010, B00010, B00011, B00011, B00001, B00001};
byte DINO_PIE_DERE_PART_2[8] = {B00111, B00111, B00111, B00100, B11100, B11100, B11000, B00000};
byte DINO_PIE_IZQU_PART_1[8] = {B00000, B00000, B00010, B00010, B00011, B00011, B00001, B00000};
byte DINO_PIE_IZQU_PART_2[8] = {B00111, B00111, B00111, B00100, B11100, B11100, B11000, B01000};
byte DOS_RAMAS_PART_1[8] = {B00000, B00100, B00100, B10100, B10100, B11100, B00100, B00100};
byte DOS_RAMAS_PART_2[8] = {B00100, B00101, B00101, B10101, B11111, B00100, B00100, B00100};
byte AVE_ALAS_PART1[8] = {B00001, B00001, B00001, B00001, B01001, B11111, B00000, B00000};
byte AVE_ALAS_PART2[8] = {B00000, B10000, B11000, B11100, B11110, B11111, B00000, B00000};

//Variables 
int columna_dino1 = 1;
int columna_dino2 = 2;
int fila_dino = 1;
unsigned long reloj=0;
int periodo=100;
int flag=1;
int fila_rama=0;
int columna_rama=13;
int periodo2=100;
unsigned long reloj2=0;
int a=0;
int b=1;
int c=2;
int d=0;
unsigned long reloj3=0;
int periodo3=100; 
int puntos =0;
int punto2 =0;
int numerorandom=0;
int columnaave= 13;
int e=0;
int fila_ave=1;
int senalactual=0;
int senalantigua=0;
int f=13;
int aceleracion=1;

void setup() {
  lcd.init();
  lcd.backlight();
  lcd.begin(16, 2);             
  lcd.createChar(0,DINO_PARADO_PARTE_1);      
  lcd.createChar(1,DINO_PARADO_PARTE_2);               
  lcd.createChar(2,DINO_PIE_DERE_PART_1);      
  lcd.createChar(3,DINO_PIE_DERE_PART_2);          
  lcd.createChar(4,DINO_PIE_IZQU_PART_1);      
  lcd.createChar(5,DINO_PIE_IZQU_PART_2);          
  lcd.createChar(6,DOS_RAMAS_PART_1);      
  lcd.createChar(7,DOS_RAMAS_PART_2);
  //lcd.createChar(2,AVE_ALAS_PART1);
  //lcd.createChar(3,AVE_ALAS_PART2);
} 
void loop() {
  /*lcd.setCursor(0,1);
  lcd.write(byte(0));
  lcd.write(byte(1));
  lcd.setCursor(2,1);
  lcd.write(byte(7));
  lcd.setCursor(5, 0);
  lcd.write(byte(2));
  lcd.write(byte(3));
  lcd.setCursor(7,0);
  lcd.print("GAME OVER");*/

  if(millis()>reloj+periodo){		//retardo para el pies del dinosaurio
    reloj=millis();
     if(flag==1){
      flag=2;
    }
    else if(flag==2){
      flag=1;

    }  
    
    
  }  
  
    if(millis()>reloj2+periodo2){			//retardo para la velocidad de las ramas
    reloj2=millis();
           
    columna_rama=columna_rama-1;
    if(columna_rama<0){
    columna_rama=13;  
    periodo2=periodo2-aceleracion;//aceleracion 
    numerorandom=random(0,3);//aca debe estar el random ya que es cada vez que regresa a la columna 13 
      
      
      }
      
       f=columna_rama+1;
   	lcd.setCursor(f,1);
 	lcd.print(" ");    
      
      f=columna_rama+1;
    lcd.setCursor(f,0);
 	lcd.print(" ");   

  if(a==1){

    if(numerorandom == 1){
      fila_rama = 1;
      lcd.createChar(6,DOS_RAMAS_PART_1);
      lcd.setCursor(columna_rama,fila_rama); 
      lcd.write(byte(6));

    }
    else if(numerorandom == 2){
      fila_rama = 1;
      lcd.createChar(7,DOS_RAMAS_PART_2);
  	  lcd.setCursor(columna_rama,fila_rama);
      lcd.write(byte(7));
 
    }
        else{				//esta es la parte del ave
    
      columnaave=columna_rama;
      columnaave=columnaave-1;
      fila_rama = 0;
      lcd.createChar(6,AVE_ALAS_PART1);
      lcd.setCursor(columnaave,fila_rama); 
      lcd.write(byte(6));
          
      lcd.createChar(7,AVE_ALAS_PART2);  
      lcd.setCursor(columna_rama,fila_rama); //columna rama porque debe estar a la izquierda de columan ave
      lcd.write(byte(7));   
	 
    		}
    
    
    
  a=0;
  }

  //condiciones ante colision
  
  
  if(digitalRead(13)==HIGH && (columna_rama==1||columna_rama==2||columnaave==1||columnaave==2) && fila_rama==0 ){
    lcd.clear();
    lcd.setCursor(5, 0);					
 	lcd.print("GAME OVER");
    delay(2000);
    lcd.clear();
    columna_rama=15;
    periodo2=100;
    puntos=0;
  	punto2=0;
    periodo2=100;
   
     }
  
  if((columna_rama==b||columna_rama==c) && fila_rama==1){    //condicion de la rama
    lcd.clear();
    lcd.setCursor(5, 0);					
 	lcd.print("GAME OVER");
    delay(2000);
    lcd.clear();
    columna_rama=15;
    periodo2=100;
    puntos=0;
    puntos=2;
    periodo2=100;
  }
  
  if(digitalRead(13)==HIGH){
    
    b=50;  //a b c lo pongo un valor mayor a 15 para que no coincida con el movimiento de la columna
    c=50;

    if(d==0){
    lcd.setCursor(0, 1);	 // LIMPIA ABAJO			
 	lcd.print("    ");   
    }
  d=1; 

  lcd.setCursor(columna_dino1,0); 
  lcd.write(byte(2));
  lcd.setCursor(columna_dino2,0);
  lcd.write(byte(3));   
 
    
  }
  else{    
    b=1;		//que regrese a su valor de inicio
    c=2;
   // lcd.setCursor(0, 0);					
 	//lcd.print("    "); 
	d=0;
  }
  
  
  
 //creamos otro retardo para los puntos 
  if(millis()>reloj3+periodo3){		//reatrdo para los puntos acumulados
    reloj3=millis();
    lcd.setCursor(14, 1);					
 	lcd.print(puntos);
    
    //if(b==50){					// el que solo cuente cuando esta en el piso es opcional
     // }
    //else{
      puntos=puntos+1;
    //}
    
     if(puntos==100){
      puntos=0;
       punto2=punto2+1;
       if(punto2==100){
       punto2=0;}
       
    }
     
  }  
  
  
    lcd.setCursor(14, 1);					
 	lcd.print(puntos);
    lcd.setCursor(14, 0);					
 	lcd.print(punto2);
  

//detector de cambio de estado
  senalactual=digitalRead(13);
if (senalactual != senalantigua)
{
  lcd.setCursor(1, 0);					
 lcd.print("  "); 
}
senalantigua = senalactual;
    }   
