/*
** EPITECH PROJECT, 2021
** my_strncmp
** File description:
** task07
*/

int my_strlen(char const *str)
{
    int i = 0;
    while (str[i] != '\0'){
        i++;
    }
    return(i);
}

int my_strncmp(char const *s1, char const *s2, int n)
{

    int i = 0;
    int result = 0;
    int len = my_strlen(s1);
    

    while(i != n)
    {
        if(s1[i] != s2[i]){
            return (s2[i] - s1[i]);
        }
        i++;
    }
    return(0);
}

int main()
{
    my_strncmp("Hello","Bonjour",5);
}
