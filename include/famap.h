/**    
    @file     famap.h
    @date     2010/12/1
    @author   ?????? freefrug@falinux.com  FALinux.Co.,Ltd.
    @brief    mmap À¯Æ¿??Æ¼?Ì´?.
              Ver 0.1.0
              
    @modify   
    @todo     
    @bug     
    @remark   
    @warning   tmmap.c  tmmap.h ?Í´? ???? ???????? ?Ê´Â´?.
*/
//----------------------------------------------------------------------------

#ifndef _FA_MMAP_H_
#define _FA_MMAP_H_


#ifndef  PAGE_SIZE
#define  PAGE_SIZE  (1024*4)
#endif

/// mmap ?? À§?? ???? ???? ??Á¶Ã¼
typedef struct {
	
	int            dev;         // /dev/mem ?????Úµ?
	unsigned long  phys;        // ?????Ö¼?
	unsigned long  size;        // Å©??
	int            base_ofs;    // ???Ì½? ?Ö¼Ò°? 4K Á¤???? ???? ?Ê¾?À»?? ????

	void          *virt;        // ?Ò´???Àº ?Þ¸?????????
	
} mmap_alloc_t;

#ifdef __cplusplus 
extern "C" { 
#endif 	

extern void  *fa_mmap_alloc( mmap_alloc_t *ma, unsigned long phys_base, unsigned long size );
extern void   fa_mmap_free ( mmap_alloc_t *ma );

#ifdef __cplusplus 
}
#endif 

#endif // _FA_MMAP_H_
