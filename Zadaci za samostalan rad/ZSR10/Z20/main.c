/*DATOTEKE*/
//1)citanje formata 500000,Sarajevo,13.7
while(fscanf(ulaz, "%d,", &br_stanovnika) == 1) {
i=-1;
do {
if (i<19) i++;
ime[i] = fgetc(ulaz);
} while(ime[i] != ',' && ime[i] != EOF);
ime[i] = '\0';
if (fscanf(ulaz, "%f\n", &temperatura) == 0) break;
printf("Prosjecna temperatura u %s (%d) je %g\n", ime, br_stanovnika,temperatura);
}