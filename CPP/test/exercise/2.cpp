//异常
//可以抛出数字，字符串，对象
#include <stdio.h>

class BadSrcFile{};
class BadDestFile{};
class BadCopy{};

void my_cp(const char *src_file, const char *dest_file){
    FILE *in_file,*out_file;
    in_file = fopen(src_file,"rb");

    if(in_file == NULL){
//        throw 1;    //抛出异常
//        throw "打开源文件出错";
        throw BadSrcFile();
    }

    out_file = fopen(dest_file,"wb");
    if(out_file == NULL){
//        throw 2;
//        throw "打开目标文件出错";
        throw BadDestFile();
    }

    char rec[256];

    size_t bytes_in,bytes_out;
    while((bytes_in = fread(rec,1,256,in_file)) > 0){
        bytes_out = fwrite(rec,1,bytes_out,out_file);
        if(bytes_in != bytes_out){
//            throw 3;
//            throw "写入文件出错";
            throw BadCopy();
        }
    }

    fclose(in_file);
    fclose(out_file);
}

int main(){
    try {
        my_cp("./1.txt","./2.txt");
    }catch(int e){
        printf("发生异常：%d\n",e);
    }catch (const char *err){
        printf("%s\n",err);
    }catch (BadSrcFile e){
        printf("发生打开源文件异常\n");
    }catch (BadDestFile e){
        printf("发生打开目标文件异常\n");
    }catch (BadCopy e){
        printf("发生写入文件异常\n");
    }catch (...){
        printf("发生未知异常\n");
    }

    printf("OK\n");

}