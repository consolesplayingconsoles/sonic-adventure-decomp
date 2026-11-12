/* @unit 8C653384-8C653420 +pool32 +tail0900 */
/* Kamui: PVR register access and copies to and from texture memory. One source file of the SDK (its functions share one literal pool). */
int kmiWriteRegister(int off, int v);
void kmiPurgeCache(void *p);
void kmiMemCopy4(int *d, int *s, unsigned int n);
int kmiPurgeMemory(char *p, int n);
int kmiCopyToPVRMemory(int off, int *src, unsigned int n);
int kmiReadRegister(int);

/* kmiWriteRegister */
int kmiWriteRegister(int off, int v)
{
    *(int *)(off + 0xA05F8000) = v;
    return 1;
}

/* kmiPurgeMemory */
int kmiPurgeMemory(char *p, int n)
{
    char *end;

    end = p;
    end += n;
    while (p <= end) {
        kmiPurgeCache(p);
        p += 32;
    }
}

/* kmiReadRegister */
int kmiReadRegister(int off)
{
    return *(int *)(off + 0xA05F8000);
}

/* kmiCopyToPVRMemory */
int kmiCopyToPVRMemory(int off, int *src, unsigned int n)
{
    kmiMemCopy4((int *)(off + 0xA5000000), src, n);
    return 1;
}

/* kmiCopyFromPVRMemory */
int kmiCopyFromPVRMemory(int *dst, int off, unsigned int n)
{
    kmiMemCopy4(dst, (int *)(off + 0xA5000000), n);
    return 1;
}
