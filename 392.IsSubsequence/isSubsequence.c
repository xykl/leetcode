int char_exist(char c, char *str)
{
    int i, len;
    
    len = strlen(str);
    
    for (i = 0; i < len; ++i) {
        if (str[i] == c) { return i; }
    }
    
    return -1;
}

bool isSubsequence(char * s, char * t)
{
    int tmp, i, s_len, t_len, t_i;

    s_len = strlen(s);
    t_len = strlen(t);
    
    if (!t_len && !s_len)   { return true; }
    if (!s_len)             { return true; }
    if (!t_len)             { return false; }
    
    tmp = char_exist(s[0], t);
    if (tmp < 0) { return false; }
    t_i = tmp;
    
    for (i = 1; i < s_len; ++i) {
        tmp = char_exist(s[i], &(t[t_i+1]));

        if (tmp < 0) { return false; }
        t_i += tmp + 1;
    }
    
    return true;
}
