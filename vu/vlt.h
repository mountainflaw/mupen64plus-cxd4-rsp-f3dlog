#include "vu.h"

void VLT(int vd, int vs, int vt, int element)
{
    register int i;
    VCF[01] = 0x0000;
    for (i = 0; i < 8; i++)
    {
        int sel = element_index[element][i];
        if (VR[vs].s[i] < VR[vt].s[sel])
        {
            VACC[i].w[01] = VR[vs].s[i];
            VCF[01] |= 0x0001 << i;
            continue;
        }
        if (VR[vs].s[i] > VR[vt].s[sel])
        {
            VACC[i].w[01] = VR[vt].s[sel];
            continue;
        }
        VACC[i].w[01] = VR[vs].s[i];
        if ((VCF[00] & (0x0101 << i)) != 0x0101 << i) continue;
            VCF[01] |= 0x0001 << i;
    }
    VR[vd].s[00] = VACC[00].w[01];
    VR[vd].s[01] = VACC[01].w[01];
    VR[vd].s[02] = VACC[02].w[01];
    VR[vd].s[03] = VACC[03].w[01];
    VR[vd].s[04] = VACC[04].w[01];
    VR[vd].s[05] = VACC[05].w[01];
    VR[vd].s[06] = VACC[06].w[01];
    VR[vd].s[07] = VACC[07].w[01];
    VCF[00] = 0x0000;
    return;
}
