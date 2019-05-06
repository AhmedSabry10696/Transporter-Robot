signed char up=0;
char x;
unsigned short count(unsigned short num)
{
 switch(num)
  {
  case 0: return 0x3F;break;
  case 1: return 0x06;break;
  case 2: return 0x5B;break;
  case 3: return 0x4F;break;
  case 4: return 0x66;break;
  case 5: return 0x6D;break;
  case 6: return 0x7D;break;
  case 7: return 0x07;break;
  case 8: return 0x7F;break;
  case 9: return 0x6F;break;
  }
}
void main()
{
 trisb=0;
 trisd=0;
 trisc=0;
 
 portb=0;
 portd=0x3F;
 portc=0;
 uart1_init(9600);
 
 while(1)
 {
  if(uart1_data_ready()==1)
   {
    x=uart1_read();
     switch(x)
     {
      case 'F':
      {
       portb.f0=1;
       portb.f2=1;
      }break;

      case 'B':
      {
       portb.f1=1;
       portb.f3=1;
      }break;
    
      case 'R':
      {
       portb.f2=1;
      }break;
    
      case 'L':
      {
       portb.f0=1;
      }break;
    
      case 'G':
      {
        portb.f4=1;
      }break;
    
      case 'H':
      {
       portb.f5=1;
      }break;
      
      case 'I':
      {
       portb.f6=1;
      }break;
      
      case 'J':
      {
       portb.f7=1;
      }break;
    
      case 'S':
      {
       portb=0;
       portc=0;
      }break;

      case 'U':
      {
       up++;
       if(up>=10) up=0;
       portd=count(up);
      }break;
    
      case 'V':
      {
       portc.f0=1;
      }break;
      
      case 'C':
      {
       portc.f1=1;
      }break;
      
      case 'D':
      {
       portc.f2=1;
      }break;
      
      default:
      {
       portb=0;
       portc=0;
      } break;
    
     }
   }

  }

}