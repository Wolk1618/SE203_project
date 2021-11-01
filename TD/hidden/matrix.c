#include"matrix.h"

int pulses=3000000;

void matrix_init(){
    //On active les horloges des ports A B et C
    RCC->AHB2ENR |= RCC_AHB2ENR_GPIOAEN;
    RCC->AHB2ENR |= RCC_AHB2ENR_GPIOBEN;
    RCC->AHB2ENR |= RCC_AHB2ENR_GPIOCEN;

    //On active toutes les broches reliées a la
    //matrice de LED comme des sorties
    GPIOA->MODER = (GPIOA->MODER & ~GPIO_MODER_MODE2_Msk) | GPIO_MODER_MODE2_0; //PA2 = C2
    GPIOA->MODER = (GPIOA->MODER & ~GPIO_MODER_MODE3_Msk) |GPIO_MODER_MODE3_0; //PA3 = C7
    GPIOA->MODER = (GPIOA->MODER & ~GPIO_MODER_MODE4_Msk) | GPIO_MODER_MODE4_0; //PA4 = SDA
    GPIOA->MODER = (GPIOA->MODER & ~GPIO_MODER_MODE5_Msk) | GPIO_MODER_MODE5_0; //PA5 = C5
    GPIOA->MODER = (GPIOA->MODER & ~GPIO_MODER_MODE6_Msk) | GPIO_MODER_MODE6_0; //PA6 = C4
    GPIOA->MODER = (GPIOA->MODER & ~GPIO_MODER_MODE7_Msk) | GPIO_MODER_MODE7_0; //PA7 = C3
    GPIOA->MODER = (GPIOA->MODER & ~GPIO_MODER_MODE15_Msk) | GPIO_MODER_MODE15_0;//PA15 = C1
    GPIOB->MODER = (GPIOB->MODER & ~GPIO_MODER_MODE0_Msk) | GPIO_MODER_MODE0_0; //PB0 = C6
    GPIOB->MODER = (GPIOB->MODER & ~GPIO_MODER_MODE1_Msk) | GPIO_MODER_MODE1_0; //PB1 = SCK
    GPIOB->MODER = (GPIOB->MODER & ~GPIO_MODER_MODE2_Msk) | GPIO_MODER_MODE2_0; //PB2 = C0
    GPIOC->MODER = (GPIOC->MODER & ~GPIO_MODER_MODE3_Msk) | GPIO_MODER_MODE3_0; //PC3 = RST
    GPIOC->MODER = (GPIOC->MODER & ~GPIO_MODER_MODE4_Msk) | GPIO_MODER_MODE4_0; //PC4 = LAT
    GPIOC->MODER = (GPIOC->MODER & ~GPIO_MODER_MODE5_Msk) | GPIO_MODER_MODE5_0; //PC5 = SB

    //On regle la vitesse au maximum
    GPIOA->OSPEEDR |= GPIO_OSPEEDR_OSPEED2;
    GPIOA->OSPEEDR |= GPIO_OSPEEDR_OSPEED3;
    GPIOA->OSPEEDR |= GPIO_OSPEEDR_OSPEED4;
    GPIOA->OSPEEDR |= GPIO_OSPEEDR_OSPEED5;
    GPIOA->OSPEEDR |= GPIO_OSPEEDR_OSPEED6;
    GPIOA->OSPEEDR |= GPIO_OSPEEDR_OSPEED7;
    GPIOA->OSPEEDR |= GPIO_OSPEEDR_OSPEED15;
    GPIOB->OSPEEDR |= GPIO_OSPEEDR_OSPEED0;
    GPIOB->OSPEEDR |= GPIO_OSPEEDR_OSPEED1;
    GPIOB->OSPEEDR |= GPIO_OSPEEDR_OSPEED2;
    GPIOC->OSPEEDR |= GPIO_OSPEEDR_OSPEED3;
    GPIOC->OSPEEDR |= GPIO_OSPEEDR_OSPEED4;
    GPIOA->OSPEEDR |= GPIO_OSPEEDR_OSPEED5;

    //On initialise les sorties
    GPIOC->BSRR = GPIO_BSRR_BR3; //RST=0
    GPIOC->BSRR = GPIO_BSRR_BS4; //LAT=1
    GPIOC->BSRR = GPIO_BSRR_BS5; //SB=1
    GPIOB->BSRR = GPIO_BSRR_BR1; //SCK=0
    GPIOA->BSRR = GPIO_BSRR_BR4; //SDA=0
    //C0 a C7 =0
    GPIOB->BSRR |= GPIO_BSRR_BR2;
    GPIOA->BSRR |= GPIO_BSRR_BR15;
    GPIOA->BSRR |= GPIO_BSRR_BR2;
    GPIOA->BSRR |= GPIO_BSRR_BR7;
    GPIOA->BSRR |= GPIO_BSRR_BR6;
    GPIOA->BSRR |= GPIO_BSRR_BR5;
    GPIOB->BSRR |= GPIO_BSRR_BR0;
    GPIOA->BSRR |= GPIO_BSRR_BR3;

    //On attend 100ms
    for (int i=0; i<pulses; i++){
      asm volatile("nop");
    }

    //On passe RST (PC3) a l'état haut
    GPIOC->BSRR |= GPIO_BSRR_BS3; //RST=1

    //On initialise BANK0
    init_bank0();
}

void RST(int i){
    switch(i){
        case 0 :
            GPIOC->BSRR |= GPIO_BSRR_BR3; //RST=0
            break;
        case 1 :
            GPIOC->BSRR |= GPIO_BSRR_BS3; //RST=1
            break;
        default :
            GPIOC->BSRR |= GPIO_BSRR_BR3; //RST=0
            break;
    }
}

void SB(int i){
    switch(i){
        case 0 :
            GPIOC->BSRR |= GPIO_BSRR_BR5; //SB=0
            break;
        case 1 :
            GPIOC->BSRR |= GPIO_BSRR_BS5; //SB=1
            break;
        default :
            GPIOC->BSRR |= GPIO_BSRR_BR5; //SB=0
            break;
    }
}

void LAT(int i){
    switch(i){
        case 0 :
            GPIOC->BSRR |= GPIO_BSRR_BR4; //LAT=0
            break;
        case 1 :
            GPIOC->BSRR |= GPIO_BSRR_BS4; //LAT=1
            break;
        default :
            GPIOC->BSRR |= GPIO_BSRR_BR4; //LAT=0
            break;
    }
}

void SCK(int i){
    switch(i){
        case 0 :
            GPIOB->BSRR |= GPIO_BSRR_BR1; //SCK=0
            break;
        case 1 :
            GPIOB->BSRR |= GPIO_BSRR_BS1; //SCK=1
            break;
        default :
            GPIOB->BSRR |= GPIO_BSRR_BR1; //SCK=0
            break;
    }
}

void SDA(int i){
    switch(i){
        case 0 :
            GPIOA->BSRR |= GPIO_BSRR_BR4; //SDA=0
            break;
        case 1 :
            GPIOA->BSRR |= GPIO_BSRR_BS4; //SDA=1
            break;
        default :
            GPIOA->BSRR |= GPIO_BSRR_BR4; //SDA=0
            break;
    }
}

void ROW0(int i){
    switch(i){
        case 0 :
            GPIOB->BSRR |= GPIO_BSRR_BR2; //C0=0
            break;
        case 1 :
            GPIOB->BSRR |= GPIO_BSRR_BS2; //C0=1
            break;
        default :
            GPIOB->BSRR |= GPIO_BSRR_BR2; //C0=0
            break;
    }
}

void ROW1(int i){
    switch(i){
        case 0 :
            GPIOA->BSRR |= GPIO_BSRR_BR15; //C1=0
            break;
        case 1 :
            GPIOA->BSRR |= GPIO_BSRR_BS15; //C1=1
            break;
        default :
            GPIOA->BSRR |= GPIO_BSRR_BR15; //C1=0
            break;
    }
}

void ROW2(int i){
    switch(i){
        case 0 :
            GPIOA->BSRR |= GPIO_BSRR_BR2; //C2=0
            break;
        case 1 :
            GPIOA->BSRR |= GPIO_BSRR_BS2; //C2=1
            break;
        default :
            GPIOA->BSRR |= GPIO_BSRR_BR2; //C2=0
            break;
    }
}

void ROW3(int i){
    switch(i){
        case 0 :
            GPIOA->BSRR |= GPIO_BSRR_BR7; //C3=0
            break;
        case 1 :
            GPIOA->BSRR |= GPIO_BSRR_BS7; //C3=0
            break;
        default :
            GPIOA->BSRR |= GPIO_BSRR_BR7; //C3=0
            break;
    }
}

void ROW4(int i){
    switch(i){
        case 0 :
            GPIOA->BSRR |= GPIO_BSRR_BR6; //C4=0
            break;
        case 1 :
            GPIOA->BSRR |= GPIO_BSRR_BS6; //C4=1
            break;
        default :
            GPIOA->BSRR |= GPIO_BSRR_BR6; //C4=0
            break;
    }
}

void ROW5(int i){
    switch(i){
        case 0 :
            GPIOA->BSRR |= GPIO_BSRR_BR5; //C5=0
            break;
        case 1 :
            GPIOA->BSRR |= GPIO_BSRR_BS5; //C5=1
            break;
        default :
            GPIOA->BSRR |= GPIO_BSRR_BR5; //C5=0
            break;
    }
}

void ROW6(int i){
    switch(i){
        case 0 :
            GPIOB->BSRR |= GPIO_BSRR_BR0; //C6=0
            break;
        case 1 :
            GPIOB->BSRR |= GPIO_BSRR_BS0; //C6=1
            break;
        default :
            GPIOB->BSRR |= GPIO_BSRR_BR0; //C6=0
            break;
    }
}

void ROW7(int i){
    switch(i){
        case 0 :
            GPIOA->BSRR |= GPIO_BSRR_BR3; //C7=0
            break;
        case 1 :
            GPIOA->BSRR |= GPIO_BSRR_BS3; //C7=1
            break;
        default :
            GPIOA->BSRR |= GPIO_BSRR_BR3; //C7=0
            break;
    }
}

void pulse_SCK(){
    SCK(0);
    asm volatile("nop");
    asm volatile("nop");    
    SCK(1);
    asm volatile("nop");
    asm volatile("nop"); 
    SCK(0);
    asm volatile("nop");
    asm volatile("nop"); 
}

void pulse_LAT(){
    LAT(1);
    asm volatile("nop");
    asm volatile("nop"); 
    LAT(0);
    asm volatile("nop");
    LAT(1);
    asm volatile("nop");
    asm volatile("nop"); 
}

void desactivate_rows(){
    ROW0(0);
    ROW1(0);
    ROW2(0);
    ROW3(0);
    ROW4(0);
    ROW5(0);
    ROW6(0);
    ROW7(0);
}

void activate_rows(){
    ROW0(1);
    ROW1(1);
    ROW2(1);
    ROW3(1);
    ROW4(1);
    ROW5(1);
    ROW6(1);
    ROW7(1);
}

void activate_row(int row){
    switch(row){
        case 0 :
            GPIOB->BSRR |= GPIO_BSRR_BS2; //C0=1
            break;
        case 1 :
            GPIOA->BSRR |= GPIO_BSRR_BS15; //C1=1
            break;
        case 2 :
            GPIOA->BSRR |= GPIO_BSRR_BS2; //C2=1
            break;
        case 3 :
            GPIOA->BSRR |= GPIO_BSRR_BS7; //C3=1
            break;
        case 4 :
            GPIOA->BSRR |= GPIO_BSRR_BS6; //C4=1
            break;
        case 5 :
            GPIOA->BSRR |= GPIO_BSRR_BS5; //C5=1
            break;
        case 6 :
            GPIOB->BSRR |= GPIO_BSRR_BS0; //C6=1
            break;
        case 7 :
            GPIOA->BSRR |= GPIO_BSRR_BS3; //C7=1
            break;    
        default :
            activate_rows(); //C0 a C7 = 1
            break;
    }
}

void send_byte(uint8_t val, int bank){
    if(bank==0){
        SB(0);
        for(int i=5; i>=0;i--){
            SDA((val & (1<<i))!=0);
            pulse_SCK();
        }      
    }else if(bank==1){
        SB(1);
        for(int i=7; i>=0;i--){
            SDA((val & (1<<i))!=0);
            pulse_SCK();
        }
    }
}

void mat_set_row(int row,const rgb_color *val){
    for(int i=7;i>=0;i--){
        send_byte((*(val+i)).b,1);
        send_byte((*(val+i)).g,1);
        send_byte((*(val+i)).r,1);
    }
    activate_row(row);
    pulse_LAT();
}

void init_bank0(){
    for(int i=0; i<24;i++){
        send_byte(0xFF,0);
    }
    pulse_LAT();    
}

void test_pixels(){
    rgb_color color[8];
    for(int j=0; j<8;j++){
        color[j].r=0xFF;
        color[j].g=0x00;
        color[j].b=0x00;
    };
    for(int i=0;i<8;i++){
        mat_set_row(i,color);
    };
    for (int i=0; i<10*pulses; i++){
      asm volatile("nop");
    };
    for(int j=0; j<8;j++){
        color[j].r=0x00;
        color[j].g=0xFF;
        color[j].b=0x00;
    };
    for(int i=0;i<8;i++){
        mat_set_row(i,color);
    };
    for (int i=0; i<10*pulses; i++){
      asm volatile("nop");
    };
    for(int j=0; j<8;j++){
        color[j].r=0x00;
        color[j].g=0x00;
        color[j].b=0xFF;
    };
    for(int i=0;i<8;i++){
        mat_set_row(i,color);
    };
}

void show(){
    
}
