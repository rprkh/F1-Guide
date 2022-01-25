#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char str_track[20];
char str1[] = "australia";
char str2[] = "bahrain";
char str3[] = "china";
char str4[] = "azerbaijan";
char str5[] = "spain";
char str6[] = "monaco";
char str7[] = "canada";
char str8[] = "france";
char str9[] = "austria";
char str10[] = "britain";
char str11[] = "hungary";
char str12[] = "belgium";
char str13[] = "italy";
char str14[] = "singapore";
char str15[] = "russia";
char str16[] = "japan";
char str17[] = "mexico";
char str18[] = "usa";
char str19[] = "brazil";
char str20[] = "abu dhabi";
char str21[] = "vietnam";
char str22[] = "netherlands";

float s1, s2, s3, total, sub_total, ps1, ps2, ps3, ptotal, sub_ptotal;
FILE *fp;
int c;
char tyre_comp;

int main(), lap_time(), file_open();
int australia(), bahrain(), china(), azerbaijan(), spain(), monaco(), canada(), france(), austria();
int britain(), hungary(), belgium(), italy(), singapore(), russia(), japan(), mexico(), usa(), brazil(), abu_dhabi(), vietnam(), netherlands();

int main()
{
  printf("Enter the name of the country: ");
  gets(str_track);
  printf("\n");
  if(strcmp(str_track, str1) == 0){australia();}
  else if(strcmp(str_track, str2) == 0){bahrain();}
  else if(strcmp(str_track, str3) == 0){china();}
  else if(strcmp(str_track, str4) == 0){azerbaijan();}
  else if(strcmp(str_track, str5) == 0){spain();}
  else if(strcmp(str_track, str6) == 0){monaco();}
  else if(strcmp(str_track, str7) == 0){canada();}
  else if(strcmp(str_track, str8) == 0){france();}
  else if(strcmp(str_track, str9) == 0){austria();}
  else if(strcmp(str_track, str10) == 0){britain();}
  else if(strcmp(str_track, str11) == 0){hungary();}
  else if(strcmp(str_track, str12) == 0){belgium();}
  else if(strcmp(str_track, str13) == 0){italy();}
  else if(strcmp(str_track, str14) == 0){singapore();}
  else if(strcmp(str_track, str15) == 0){russia();}
  else if(strcmp(str_track, str16) == 0){japan();}
  else if(strcmp(str_track, str17) == 0){mexico();}
  else if(strcmp(str_track, str18) == 0){usa();}
  else if(strcmp(str_track, str19) == 0){brazil();}
  else if(strcmp(str_track, str20) == 0){abu_dhabi();}
  else if(strcmp(str_track, str21) == 0){vietnam();}
  else if(strcmp(str_track, str22) == 0){netherlands();}
  else{printf("You have entered an invalid location name.");}
  return 0;
}

// opens the required file based on the user's choice
int file_open()
{
  char folder[] = "locations/";
  char extension[] = ".txt";
  fp = fopen(strcat(strcat(folder, str_track), extension), "r");
  if(fp == NULL)
  {
    perror("Error in opening file");
    return (-1);
  }
  while((c = fgetc(fp)) != EOF)
  {
    printf("%c", c);
  }
  fclose(fp);
  fp = NULL;
}

// calculates the lap time and tells you which sectors you can improve in
int lap_time()
{
  printf("\n");
  printf("\nEnter your tyre compound: ");
  scanf("%c", &tyre_comp);
  printf("Enter time in S1: ");
  scanf("%f", &s1);
  printf("Enter time in S2: ");
  scanf("%f", &s2);
  printf("Enter time in S3: ");
  scanf("%f", &s3);
  printf("\n\t\t\t\t\t\tQUALI TIME\n");
  printf("\n\t\t\tTyre Compound\t\tS1\t\tS2\t\tS3\t\tTotal\n");
  total = s1 + s2 + s3;
  if(total > 60 || total == 60)
  {
    sub_total = total - 60;
    if(sub_total > 10)
    {
      printf("Best time:\t\t\t%c\t\t%.3f\t\t%.3f\t\t%.3f\t\t1.%.3f\n", tyre_comp, s1, s2, s3, sub_total);
    }
  }
  if(total < 60)
  {
    printf("Best time:\t\t\t%c\t\t%.3f\t\t%.3f\t\t%.3f\t\t%.3\nf", tyre_comp, s1, s2, s3, total);
  }
  ptotal = ps1 + ps2 + ps3;
  if(ptotal > 60 || ptotal == 60)
  {
    sub_ptotal = ptotal - 60;
    printf("Pole time:\t\t\t%c\t\t%.3f\t\t%.3f\t\t%.3f\t\t1.%.3f\n", tyre_comp, ps1, ps2, ps3, sub_ptotal);
  }
  printf("Difference:\t\t\t\t\t%.3f\t\t%.3f\t\t%.3f\t\t%.3f\n", s1 - ps1, s2 - ps2, s3 - ps3, (s1 + s2 + s3) - ptotal);
  if(s1 - ps1 > 0)
  {
    printf("\nYou can improve in sector 1 by %.3f seconds", s1 - ps1);
  }
  if(s2 - ps2 > 0)
  {
    printf("\nYou can improve in sector 2 by %.3f seconds", s2 - ps2);
  }
  if(s3 - ps3 > 0)
  {
    printf("\nYou can improve in sector 3 by %.3f seconds", s3 - ps3);
  }
  if((s1 + s2 + s3) - ptotal > 0)
  {
    printf("\nYou can improve your overall lap time by %.3f seconds", (s1 + s2 + s3) - ptotal);
  }
  return 0;
}

int abu_dhabi()
{
  ps1 = 16.903;
  ps2 = 40.641;
  ps3 = 37.235;
  file_open();
  lap_time();
  return 0;
}

int australia()
{
  ps1 = 26.613;
  ps2 = 21.962;
  ps3 = 31.911;
  file_open();
  lap_time();
  return 0;
}

int austria()
{
  ps1 = 15.956;
  ps2 = 27.961;
  ps3 = 19.050;
  file_open();
  lap_time();
  return 0;
}

int azerbaijan()
{
  ps1 = 27.762;
  ps2 = 38.066;
  ps3 = 22.036;
  file_open();
  lap_time();
  return 0;
}

int bahrain()
{
  ps1 = 27.762;
  ps2 = 38.068;
  ps3 = 22.036;
  file_open();
  lap_time();
  return 0;
}

int belgium()
{
  ps1 = 30.337;
  ps2 = 42.550;
  ps3 = 28.365;
  file_open();
  lap_time();
  return 0;
}

int brazil()
{
  ps1 = 17.486;
  ps2 = 34.195;
  ps3 = 15.827;
  file_open();
  lap_time();
  return 0;
}

int britain()
{
  ps1 = 27.514;
  ps2 = 34.408;
  ps3 = 23.171;
  file_open();
  lap_time();
  return 0;
}

int canada()
{
  ps1 = 19.364;
  ps2 = 22.427;
  ps3 = 28.449;
  file_open();
  lap_time();
  return 0;
}

int china()
{
  ps1 = 23.988;
  ps2 = 27.176;
  ps3 = 40.383;
  file_open();
  lap_time();
  return 0;
}

int france()
{
  ps1 = 21.951;
  ps2 = 27.363;
  ps3 = 39.005;
  file_open();
  lap_time();
  return 0;
}

int hungary()
{
  ps1 = 26.934;
  ps2 = 25.783;
  ps3 = 20.730;
  file_open();
  lap_time();
  return 0;
}

int italy()
{
  ps1 = 26.566;
  ps2 = 26.307;
  ps3 = 26.014;
  file_open();
  lap_time();
  return 0;
}

int japan()
{
  ps1 = 30.374;
  ps2 = 39.372;
  ps3 = 17.318;
  file_open();
  lap_time();
  return 0;
}

int mexico()
{
  ps1 = 26.714;
  ps2 = 28.787;
  ps3 = 19.523;
  file_open();
  lap_time();
  return 0;
}

int monaco()
{
  ps1 = 18.403;
  ps2 = 33.096;
  ps3 = 18.667;
  file_open();
  lap_time();
  return 0;
}

int netherlands()
{
  ps1 = 29.894;
  ps2 = 17.809;
  ps3 = 20.778;
  file_open();
  lap_time();
  return 0;
}

int russia()
{
  ps1 = 33.370;
  ps2 = 31.319;
  ps3 = 26.939;
  file_open();
  lap_time();
  return 0;
}

int singapore()
{
  ps1 = 26.211;
  ps2 = 37.127;
  ps3 = 32.879;
  file_open();
  lap_time();
  return 0;
}

int spain()
{
  ps1 = 21.488;
  ps2 = 28.040;
  ps3 = 25.878;
  file_open();
  lap_time();
  return 0;
}

int usa()
{
  ps1 = 24.758;
  ps2 = 36.718;
  ps3 = 30.553;
  file_open();
  lap_time();
  return 0;
}

int vietnam()
{
  ps1 = 25.153;
  ps2 = 40.164;
  ps3 = 27.637;
  file_open();
  lap_time();
  return 0;
}