#ifndef STRING_TOOLS_PARAM
#define STRING_TOOLS_PARAM 1

bool RestrictUpperCase(char *text){
    for(int i = 0; text[i] != '\0'; i++){
        if(text[i] >= 'A' && text[i] <= 'Z'){
            return false;
        }
    }
    return true;
}

bool RestrictSpace(char *text){
    for(int i = 0; text[i] != '\0'; i++){
        if(text[i] == ' '){
            return false;
        }
    }
    return true;
}

unsigned long DJB2(char *str, const int max){
    unsigned long hash = 5381;
    int c;
    while((c = *str++)){
        hash = ((hash << 5) + hash) + c;
    }
    return hash % max;
}

void OrderingGetValue(char *input, char **dish_name, int *many){
    char split_name[200];
    int index = 0;
    for(index = 0; input[index + 1] != 'x'; index++){
        split_name[index] = input[index];
    }
    split_name[index] = '\0';

    index+= 2;
    for(index = index; input[index] != '\0'; index++){
        (*many) = ((*many) * 10) + (input[index] - '0');
    }

    (*dish_name) = strdup(split_name);
}

void PrintButkemp(){
    system("cls||clear");

//Multiple Line Input, Maybe only for C++ (?)
char *logoButkemp = 
R"(
                                                                                                    
                                                      ..`                                           
                  .//.                               /+++-   `    :/:                               
                  /MM:                               -/+/` .hm/   dMd                               
         :osso/`  /MM:   `+ss+:ss-  `/osso:   /so:sy: ss/ +yMMhs: dMd/sso:   +s+/sso-.+sso:         
        hMdo+dMm. /MM:  .NMNyyNMM/ .NMmsyNMh  yMMmss- MMy :oMMy/- dMMdshMMo  mMMdsdMMMdshMMs        
        .-:--+MM/ /MM:  +MM-  /MM/ sMM`  +MM- yMM`    MMy  -MM+   dMm   dMm  mMm   mMm   hMN        
       `hMmhyhMM/ /MM:  +MM-  /MM/ sMM   /MM: yMM     MMy  -MM+   dMd   dMm  mMd   dMm   yMM        
       :MM+  +MM/ :MMo. .NMmsyNMM/ +MM+..yMM. yMM     MMy  -MMs`  dMd   dMm  mMd   dMm   yMM        
        sNMMNdMM/  smMM- `+syo+MM/  omMMMNh:  yMM     MMs   omMM: dMd   hMm  dMd   dMm   yMN        
         ``.` ``     `` .dds::hMm`  `..-..`````..`````...````....`...```...``...............        
                         -shhhyo`  `..............------------------------------------------        
                                   .+-/`   /::/    :::/`  .-o-`  `/::    -/    -o  :+   -/::        
                                   .s:s`  -+  /:  .o  :/    s    s`     `y+/   :++./s   //-+        
                                   .o-+.  `+--+`   +--/.    o    -/--   +.`+`  :-/+ o   :-`         
                                    ```     ``      ``      `     ```   `         ` `               
                                                                                                    
 
)";

printf("%s", logoButkemp);
}

#endif