// STEAPIUK ROMAN (S ROZSIRENIM)

#include<stdio.h>
#include<string.h>
char inicializace_seznamu(char seznam[100][100], int *delka){

        int bool = 0; //promena, ktera hleda konec retezzce a pak vychazi z cyklu
  for(int i = 0; i < 100; i++)
  {  
      if(bool != 0)  //vychod z cyklu 
      {
        break;
      }
   
      for(int j = 0; j < 100; j++)
    {
      scanf("%c", &seznam[i][j]);
      if (j == 0)
        {
         *delka = *delka + 1;
        }

      if(seznam[i][j] == '\n') //kdyz symbol == konci radku vychazi z vnitrniho cyklu
      {
        break;
      }
      
      if(seznam[i][j] == '\0'){
        bool++;
        break;
      }
    }
  }
      return seznam[*delka][100];
}

void print_seznamu(char seznam[100][100], int delka, int argc){
    for (int i = 0; i < delka; i++){
            for (int j = 0; seznam[i][j] != '\n'; j++)     //prevod velkych pismen na male
              {
                      if(seznam[i][j] >= 'A' && seznam[i][j] < 'a')
                      {
                        seznam[i][j]+='a'-'A';
                      }
                      if (argc == 1){
                        printf("%c", seznam[i][j]);  //vypis celeho seznamu, kdyz argv[1] == 1
                      }
              }
            if (argc == 1)   
            {
              if (i%2 == 0)  // pidminky na spravny zapis v formatu [jmeno, telefonni cislo]
              { 
                printf(", ");
              }
              if(i%2 == 1){
                 printf("\n");
              }
            }
    }
}

char cislovi_seznam(char seznam[100][100], char seznam_cisel[100][100], int delka){
  for(int i = 0; i < delka; i++)
  {
    for(int j = 0; seznam[i][j] != '\n'; j++)
    {
      switch(seznam[i][j])            //zaplnujeme jeste jedno pole cislami misto pismen
        {
                case '0': case '+':
            seznam_cisel[i][j] = '0'; 
            break;
                case '1':
            seznam_cisel[i][j] = '1';
            break;
                case '2': case 'a': case 'b': case 'c':
            seznam_cisel[i][j] = '2'; 
            break;
                case '3': case 'd': case 'e': case 'f':
            seznam_cisel[i][j] = '3';
            break;
                case '4': case 'g': case 'h': case 'i':
            seznam_cisel[i][j] = '4'; 
            break;
                case '5': case 'j': case 'k': case 'l':
            seznam_cisel[i][j] = '5';
            break;
                case '6': case 'm': case 'n': case 'o':
            seznam_cisel[i][j] = '6'; 
            break;
                case '7': case 'p': case 'r': case 's':
            seznam_cisel[i][j] = '7';
            break;
                case '8': case 't': case 'u': case 'v':
            seznam_cisel[i][j] = '8'; 
            break;
                case '9': case 'w': case 'x': case 'y': case 'z':
            seznam_cisel[i][j] = '9';
            break;
        }
    }
  }

 return seznam_cisel[100][100];

}

char transform_pole_bonus(char seznam[100][100], char seznam_cisel[100][100], char *argv[], int delka)
{
  char bonus[strlen(argv[1])];
  
    for(int i = 0; i < strlen(argv[1]); i++)
    {
      bonus[i] = 0;
    }
  
  for (int i = 0; i < delka; i++)   
    {
      for(int j = 0; seznam[i][j] != '\n'; j++) // hledame stejne cisla v argv[1] a polem z cisel a menime stejne cisla poli na '*'
       {
         int pocet = 0;  //promena ktera spocita stejne znaky ­ pocet stejnych znaku
         int bonus_pocet = 1;
           if (argv[1][0] == seznam_cisel[i][j]){
                   bonus[0] = 0;
              for(int x = 1; x < strlen(argv[1]); x++)
                {
                  for(int y = bonus_pocet; seznam[i][y] != '\n'; y++)
                    {
                      bonus_pocet++;
                      if(argv[1][0+x] == seznam_cisel[i][j+y])
                       {
                        bonus[x] = y;
                        pocet++;
                        break;
                       }
                    }
                }
             if (pocet+1 == strlen(argv[1])){
              for(int z = 0; z < pocet+1; z++){  // velke pismena na male pismena
                if(seznam[i][j+bonus[z]] <= 'z' && seznam[i][j+bonus[z]] >= 'a')
                 {
                   seznam[i][j+bonus[z]]= seznam[i][j+bonus[z]] - ('a' - 'A'); 
                 }
                seznam_cisel[i][j+bonus[z]] = '*';
               } 
             }
          } 
      }
    }
  return seznam_cisel[100][100];
}

void print_seznam_result(char seznam[100][100], char seznam_cisel[100][100], int delka) // vypis seznamu hlavnĂ­ho zadani
{
  int score = 0; // promena, ktera zjistuje jestli v k-radku je alespon '*' a pak vypsat ten a pristi radek kdyz to byl radek s jmenem, anebo ten a predchozi radek kdyz to byl radek s telefonnim cislom
  for (int i = 0; i < delka; i++)
   {
     for (int j = 0; seznam[i][j] != '\n'; j++)
      {
        for(int k = 0; seznam[i][k] != '\n'; k++)
         {
           if(seznam_cisel[i][k] == '*')
            {
              score = 1;
            }
         }
       if (i%2 == 0){
         for(int k = 0; seznam[i+1][k] != '\n'; k++)
          {
            if(seznam_cisel[i+1][k] == '*')
             {
               score = 1;
             }
          }
        } else if (i%2 == 1)
           {
             for(int k = 0; seznam[i-1][k] != '\n'; k++)
               {
                 if(seznam_cisel[i-1][k] == '*')
                  {
                    score = 1;
                  }
              }
          }
        if (score == 0)
         {
           break;
         }
          printf("%c", seznam[i][j]);
         }
       if(i%2 == 0 && score == 1)
        {
          printf(", ");
        }
       if(i%2 == 1 && score == 1)
         {
          printf("\n");
         }
         score = 0;
   } 
  int not_found = 0;
  for(int i = 0; i < delka; i++)
  {
    for (int j = 0; seznam[i][j] != '\n'; j++)
    {
      if(seznam_cisel[i][j] == '*'){
        not_found++;
      }
    }
  }
  if(not_found == 0)
  {
    printf("NOT FOUND\n");
  }
}

int main(int argc, char *argv[]) {
    char seznam[100][100];
    char seznam_cisel[100][100];
    int delka = -1; //pocet radku
    inicializace_seznamu(seznam, &delka);
    print_seznamu(seznam, delka, argc); //print seznamu bez arguemntu

    cislovi_seznam(seznam, seznam_cisel, delka); //predelame pole seznam[][] v pole_cisel [][] 
    if (argc == 2)
    {
      transform_pole_bonus(seznam, seznam_cisel, argv, delka); //prepisujeme stejne znaky ktery maji 1.argument a seznam_cisel[][] na '*'
      print_seznam_result(seznam, seznam_cisel, delka);// vypisujeme seznam[][] po hodnotech seznam_cisel[][]
    }
    else if(argc > 2)
      {
        printf("CHYBA! muzete pouzit jen 1 nebo 2 argumenty\n");
      }
    return 0;
  }