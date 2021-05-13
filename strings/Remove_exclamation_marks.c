void remove_exclamation_marks(const char * str_in, char * str_out) {
        int a = strlen(str_in);
        int j = 0;
        for (int i = 0; i < a; i++) {
                if (str_in[i] != '!') {
                        str_out[j] = str_in[i];
                        j++;
                }
               
        }
         str_out[j] = '\0';
}





//best solution 

void remove_exclamation_marks(const char *str_in, char *str_out) 
{
        do
        {
                if(*str_in != '!') *str_out++ = *str_in;
        } while ( *str_in++);
        
}