//
//  main.c
//  yttp
//
//  Created by Егор on 2/18/17.
//  Copyright © 2017 Yegor's Mac. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/syslimits.h>
#include<ctype.h>

typedef struct{
    int code;
    char *about;
}Code;

void searchForKey(Code codes[],char const *word, int size){
    for (int i = 0; i < size; i++)
        if (strcasestr(codes[i].about, word) != NULL){
            printf(" %d - %s \n",codes[i].code,codes[i].about);
        }
}

int main(int argc, const char * argv[]) {
    
    if (argc < 2 || argc > 3){
        printf("Please type -h for help \n");
        exit(-1);
    }
    
    if (strcmp("-h", argv[1]) == 0){
        printf("Usage: \"yttp code\" or \"yttp codeword\" \n" );
        exit(0);
    }
    
    Code codes[] = { {100, "  Continue "},
        {101, "Switching Protocols "},
        {200, "OK, Everything is normal "},
        {201, "Created "},
        {202, "Accepted "},
        {203, "Non-Authoritative Information "},
        {204, "No Content "},
        {205, "Reset Content "},
        {206, "Partial Content "},
        {300, "Multiple Choices "},
        {301, "Moved Permanently. Update your URL, this has moved for good. "},
        {302, "Found "},
        {303, "See Other "},
        {304, "Not Modified "},
        {305, "Use Proxy "},
        {306, "Unused "},
        {307, "Temporary Redirect, This is temporarly moved, don't update your bookmarks. "},
        {400, "Bad Request, Server didn't understand the URL you gave it. "},
        {401, "Unauthorized, Must be authenticated "},
        {402, "Payment Required, Not used really "},
        {403, "Forbidden, Server refuses to give you a file, authentication won't help "},
        {404, "Not Found, A file doesn't exist at that address "},
        {405, "Method Not Allowed "},
        {406, "Not Acceptable "},
        {407, "Proxy Authentication Required "},
        {408, "Request Timeout, Browser took too long to request something "},
        {409, "Conflict "},
        {410, "Gone "},
        {411, "Length Required "},
        {412, "Precondition Failed "},
        {413, "ReqeustEntityTooLarge "},
        {415, "Unsupported Media Type "},
        {416, "Request Range Not Satisfiable "},
        {417, "Expectation Failed "},
        {500, "Internal Server Error, Something on the server didn't work right. "},
        {501, "Not Implemented "},
        {502, "Bad Gateway "},
        {503, "Service Unavailable, Too busy to respond to a client "},
        {504, "Gateway Timeout "},
        {505, "HTTP Version Not Supported "}};

    
    int code = atoi(argv[1]);
    int size = sizeof(codes) / sizeof(Code);
    if (code == 0){
        searchForKey(codes, argv[1] , size);
    }else{
        for (int i = 0; i < size; i++){
            if (codes[i].code == code){
                printf("%s \n", codes[i].about);
                exit(0);
            }
        }
        printf("Code is not assighned \n");
    }
    
    return 0;
}
