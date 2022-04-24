#ifndef __NIXIETUBE_H__
#define __NIXIETUBE_H__
void nixie_scan(unsigned char pos,unsigned char num);
void nixie_setBuffer(unsigned char location, unsigned char num);
void nixie_loop();
#endif