/*
char* printch(char ch,char* s);
char* printdec(int dec,char* s);
char* vprintdec(int dec,char* s);
char* printstr(char* str,char* s);

//int vprintk(

int printk(const char *fmt, ...){
	//return vprintk(0,fmt,...);
	int vargint=0;
	char* vargpch=0;
	char vargch=0;
	
	const char* pfmt=0;
	va_list vp;

	va_start(vp,fmt);
	pfmt=fmt;

	while(*pfmt){
		if(*pfmt == '%'){
			switch(*(++pfmt)){
				case 'c':vargch=va_arg(vp,int);printch(vargch,0);break;
				case 'd':
				case 'i':vargint=va_arg(vp,int);vprintdec(vargint,0);break;
				case 's':vargpch=va_arg(vp,char*);printstr(vargpch,0);break;
				case 'u':
				case 'x':
				case 'X':
				case 'p':
				default:;
			}
			pfmt++;
		}
		else{
			printch(*pfmt++,0);
		}
	}
	va_end(vp);
	return 0;
}
int sprintf(char* out,char* fmt,...){
	int vargint=0;
	char* vargpch=0;
	char vargch=0;
	
	char* pfmt=0;
	va_list vp;

	va_start(vp,fmt);
	pfmt=fmt;

	while(*pfmt){
		if(*pfmt == '%'){
			switch(*(++pfmt)){
				case 'c':vargch=va_arg(vp,int);out=printch(vargch,out);break;
				case 'd':
				case 'i':vargint=va_arg(vp,int);out=vprintdec(vargint,out);break;
				case 's':vargpch=va_arg(vp,char*);out=printstr(vargpch,out);break;
				default:;
			}
			pfmt++;
		}
		else{
			out=printch(*pfmt++,out);
		}
	}
	va_end(vp);
	*out='\0';
	return 0;

}
*/
