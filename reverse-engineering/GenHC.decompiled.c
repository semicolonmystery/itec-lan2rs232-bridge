/* ===== FUNC FUN_00011008 @ 00011008 ===== */

ulonglong FUN_00011008(longlong *param_1,longlong param_2)

{
  uint uVar1;
  longlong lVar2;
  longlong lVar3;
  bool bVar4;
  int iVar5;
  uint uVar6;
  ulonglong uVar7;
  uint uVar8;
  int *piVar9;
  undefined7 uStackX_9;
  
  lVar2 = param_1[8];
  lVar3 = *(longlong *)(param_2 + 0xb8);
  uVar8 = 0;
  uVar1 = *(uint *)(lVar3 + 0x18);
  bVar4 = true;
  if (*(char *)(lVar2 + 8) == '\0') {
    FUN_000121dc();
    *(undefined4 *)(param_2 + 0x30) = 0xc0000010;
    IofCompleteRequest(param_2,0);
    return 0xc0000010;
  }
  FUN_00012134(param_1,lVar2);
  if (*(int *)(lVar2 + 0xc) == 1) {
    piVar9 = *(int **)(param_2 + 0x18);
    uVar8 = *(uint *)(lVar3 + 8);
    if (uVar1 < 0x220429) {
      if (uVar1 != 0x220428) {
        if (uVar1 < 0x220411) {
          if (uVar1 == 0x220410) goto LAB_000110d6;
          iVar5 = uVar1 - 0x2203fc;
        }
        else {
          iVar5 = uVar1 - 0x220414;
        }
        if ((iVar5 != 0) && (iVar5 != 4)) {
          iVar5 = iVar5 + -8;
          goto LAB_000110ca;
        }
      }
LAB_000110d6:
      bVar4 = false;
      uVar7 = FUN_0001e9ec((longlong)param_1,param_2);
      uVar7 = uVar7 & 0xffffffff;
      goto LAB_00011264;
    }
    if (uVar1 < 0x220449) {
      if (((uVar1 == 0x220448) || (uVar1 == 0x220430)) || (uVar1 == 0x220434)) goto LAB_000110d6;
      iVar5 = uVar1 - 0x22043c;
LAB_000110ca:
      if (((iVar5 != 0) && (iVar5 != 4)) && (iVar5 != 8)) {
LAB_0001112f:
        FUN_000121dc();
        uVar7 = 0xc0000010;
        goto LAB_0001125b;
      }
      goto LAB_000110d6;
    }
    if (uVar1 == 0x2a4084) {
      KeWaitForSingleObject(lVar2 + 0xfb8,0,0,0,0);
      FUN_000121dc();
      uVar6 = FUN_00013678(param_1,(longlong)piVar9);
LAB_0001124b:
      uVar7 = (ulonglong)uVar6;
      KeSetEvent(lVar2 + 0xfb8,0,0);
LAB_0001125b:
      *(undefined8 *)(param_2 + 0x38) = 0;
      goto LAB_00011264;
    }
    if (uVar1 == 0x2a4088) {
      KeWaitForSingleObject(lVar2 + 0xfb8,0,0,0,0);
      FUN_000121dc();
      uVar6 = FUN_0003b26c(param_1,(longlong)piVar9);
      goto LAB_0001124b;
    }
    if (uVar1 == 0x2ae00c) {
      FUN_000121dc();
      lVar3 = param_1[8];
      *(undefined8 *)(param_2 + 0x88) = 0;
      IoCsqInsertIrp(lVar3 + 0x218,param_2,lVar3 + 0x3a0);
      uVar7 = 0x103;
      FUN_0001216c(param_1,lVar2);
      goto LAB_0001125b;
    }
    if (uVar1 == 0x2ae010) {
      FUN_000121dc();
      uVar7 = 0;
      goto LAB_0001125b;
    }
    if (uVar1 != 0x2ae084) goto LAB_0001112f;
    uVar7 = FUN_000121e8((longlong)param_1,param_2);
    uVar7 = uVar7 & 0xffffffff;
  }
  else {
    piVar9 = (int *)CONCAT71(uStackX_9,1);
    uVar7 = 0xc00000c0;
LAB_00011264:
    if (((uVar1 != 0x2ae00c) && (uVar1 != 0x2ae010)) && ((bVar4 && (3 < uVar8)))) {
      *piVar9 = (int)uVar7;
      *(ulonglong *)(param_2 + 0x38) = (ulonglong)uVar8;
      FUN_00021370((int)uVar7);
      FUN_000121dc();
      uVar7 = 0;
    }
  }
  if ((int)uVar7 == 0x102) {
    if (uVar8 != 0) goto LAB_000112c7;
    uVar7 = 0xc0000001;
  }
  if ((int)uVar7 == 0x103) {
    return uVar7;
  }
LAB_000112c7:
  *(int *)(param_2 + 0x30) = (int)uVar7;
  IofCompleteRequest(param_2,0);
  FUN_0001216c(param_1,lVar2);
  return uVar7;
}



/* ===== FUNC FUN_00011308 @ 00011308 ===== */

int FUN_00011308(longlong param_1,longlong param_2)

{
  longlong ****pppplVar1;
  longlong lVar2;
  longlong ***ppplVar3;
  longlong ***ppplVar4;
  undefined1 uVar5;
  longlong lVar6;
  longlong lVar7;
  longlong ****pppplVar8;
  longlong ****pppplVar9;
  int iVar10;
  longlong ****pppplVar11;
  undefined8 uVar12;
  longlong ****local_28;
  longlong ****local_20;
  
  lVar2 = *(longlong *)(param_1 + 0x40);
  lVar6 = *(longlong *)(param_2 + 0xb8);
  uVar12 = *(undefined8 *)(lVar6 + 0x30);
  lVar7 = param_2;
  FUN_000121dc();
  iVar10 = 0;
  if (*(longlong *)(lVar6 + 0x30) == *(longlong *)(lVar2 + 0x40)) {
    if (*(char *)(lVar2 + 8) != '\0') {
      FUN_00012134(param_1,lVar2);
      local_20 = (longlong ****)&local_28;
      local_28 = (longlong ****)&local_28;
      uVar5 = KeAcquireSpinLockRaiseToDpc(lVar2 + 0xf0);
      pppplVar1 = (longlong ****)(lVar2 + 0x90);
      pppplVar9 = (longlong ****)*pppplVar1;
      pppplVar11 = (longlong ****)**pppplVar1;
      while (pppplVar9 != pppplVar1) {
        if (*(longlong ***)(lVar6 + 0x30) == pppplVar9[2][6]) {
          ppplVar3 = pppplVar9[1];
          ppplVar4 = *pppplVar9;
          *ppplVar3 = (longlong **)ppplVar4;
          ppplVar4[1] = (longlong **)ppplVar3;
          LOCK();
          ppplVar3 = pppplVar9[-8];
          pppplVar9[-8] = (longlong ***)0x0;
          UNLOCK();
          if (ppplVar3 == (longlong ***)0x0) {
            pppplVar9[1] = (longlong ***)pppplVar9;
            *pppplVar9 = (longlong ***)pppplVar9;
          }
          else {
            pppplVar9[1] = (longlong ***)local_20;
            *pppplVar9 = (longlong ***)&local_28;
            *local_20 = (longlong ***)pppplVar9;
            local_20 = pppplVar9;
          }
        }
        pppplVar9 = pppplVar11;
        pppplVar11 = (longlong ****)*pppplVar11;
      }
      KeReleaseSpinLock(lVar2 + 0xf0,CONCAT71((int7)((ulonglong)pppplVar9 >> 8),uVar5),pppplVar11,
                        pppplVar1,lVar7,uVar12);
      while (pppplVar1 = local_28, (longlong *****)local_28 != &local_28) {
        pppplVar11 = (longlong ****)*local_28;
        pppplVar8 = local_28 + -0x15;
        pppplVar11[1] = (longlong ***)&local_28;
        pppplVar9 = local_28 + -0xe;
        local_28 = pppplVar11;
        *pppplVar9 = (longlong ***)0x0;
        *(undefined4 *)(pppplVar1 + -0xf) = 0xc0000120;
        IofCompleteRequest(pppplVar8,0);
      }
      *(undefined8 *)(param_2 + 0x38) = 0;
      *(undefined4 *)(param_2 + 0x30) = 0;
      IofCompleteRequest(param_2,0);
      FUN_0001216c(param_1,lVar2);
      FUN_000121dc();
      lVar6 = IoCsqRemoveIrp(lVar2 + 0x218,lVar2 + 0x3a0);
      lVar7 = FUN_000121dc();
      if (lVar7 != 0) {
        lVar7 = *(longlong *)(lVar7 + 0x18);
        *(undefined4 *)(lVar7 + 4) = 0x24544e55;
        *(undefined2 *)(lVar7 + 2) = 0x300;
        *(undefined8 *)(lVar6 + 0x38) = 0x40d;
        *(undefined4 *)(lVar6 + 0x30) = 0;
        IofCompleteRequest(lVar6,0);
      }
      KeCancelTimer(lVar2 + 0x3b8);
      KeCancelTimer(lVar2 + 0x438);
      KeCancelTimer(lVar2 + 0xf08);
      KeCancelTimer(lVar2 + 0x538);
      KeCancelTimer(lVar2 + 0x4b8);
      goto LAB_0001154c;
    }
    FUN_000121dc();
    iVar10 = -0x3ffffff0;
    *(undefined4 *)(param_2 + 0x30) = 0xc0000010;
  }
  else {
    *(undefined8 *)(param_2 + 0x38) = 0;
    *(undefined4 *)(param_2 + 0x30) = 0;
  }
  IofCompleteRequest(param_2,0);
LAB_0001154c:
  FUN_00021370(iVar10);
  FUN_000121dc();
  return iVar10;
}



/* ===== FUNC FUN_0001158c @ 0001158c ===== */

void FUN_0001158c(void)

{
  if (DAT_00037878 != 0) {
    ExFreePoolWithTag(DAT_00037878,0);
  }
  return;
}



/* ===== FUNC FUN_000115b0 @ 000115b0 ===== */

ulonglong FUN_000115b0(longlong param_1,longlong param_2)

{
  uint uVar1;
  longlong lVar2;
  ulonglong uVar3;
  longlong lVar4;
  int iVar5;
  ulonglong uVar6;
  longlong lVar7;
  undefined4 *puVar8;
  longlong lVar9;
  
  lVar2 = *(longlong *)(param_1 + 0x40);
  lVar9 = *(longlong *)(param_2 + 0xb8);
  uVar6 = 0;
  uVar1 = *(uint *)(lVar9 + 0x18);
  if (*(char *)(lVar2 + 8) != '\0') {
    lVar7 = param_2;
    lVar2 = FUN_000121dc();
    lVar4 = *(longlong *)(lVar7 + 0x78);
    if (*(longlong *)(lVar7 + 0x78) != 0) goto LAB_00011617;
    goto LAB_0001160a;
  }
  lVar4 = lVar2;
LAB_00011617:
  if ((*(char *)(lVar2 + 8) == '\0') &&
     (((*(int *)(lVar2 + 0xc) == 6 || (*(char *)(lVar4 + 0x69) == '\0')) ||
      (*(char *)(lVar4 + 0x6d) == '\0')))) {
    FUN_000121dc();
    if (uVar1 != 0x220013) {
      uVar3 = FUN_0001b3e0(param_1,param_2);
      uVar6 = uVar3 & 0xffffffff;
      FUN_00017594(param_2,(int)uVar3);
      goto LAB_000117f1;
    }
    puVar8 = *(undefined4 **)(lVar9 + 8);
    FUN_000121dc();
    *puVar8 = 0;
    FUN_000121dc();
    *puVar8 = 0;
    FUN_000121dc();
    uVar6 = 0xc000000e;
  }
  else {
    if (uVar1 < 0x220020) {
      if (uVar1 != 0x22001f) {
        if (uVar1 != 0x220003) {
          if (uVar1 == 0x220007) {
            FUN_000121dc();
          }
          else {
            if ((uVar1 == 0x22000f) || (uVar1 != 0x220013)) goto LAB_0001160a;
            puVar8 = *(undefined4 **)(lVar9 + 8);
            lVar2 = *(longlong *)(param_1 + 0x40);
            FUN_000120dc(500);
            FUN_000121dc();
            if ((*(char *)(lVar2 + 0x69) == '\x01') && (*(char *)(lVar2 + 0x6d) == '\x01')) {
              *puVar8 = 3;
            }
            else {
              *puVar8 = 0;
            }
            FUN_000121dc();
          }
          iVar5 = 0;
          goto LAB_0001182c;
        }
        if (*(char *)(lVar2 + 8) == '\0') {
          uVar6 = FUN_00016a70(param_1,param_2);
          uVar1 = (uint)uVar6;
        }
        else {
          uVar1 = FUN_0001680c(param_1,param_2);
        }
        uVar6 = (ulonglong)uVar1;
        goto LAB_000117f1;
      }
LAB_0001160a:
      uVar6 = 0xc00000bb;
    }
    else {
      if (uVar1 != 0x220020) {
        if (((uVar1 != 0x220027) && (uVar1 == 0x220420)) &&
           (lVar2 = *(longlong *)(lVar9 + 8), lVar2 != 0)) {
          *(undefined4 *)(lVar2 + 4) = 4000;
          *(undefined4 *)(lVar2 + 8) = 3000;
          *(undefined4 *)(lVar2 + 0xc) = 0x14;
          return 0;
        }
        goto LAB_0001160a;
      }
      uVar6 = 0xc00000bb;
LAB_000117f1:
      if (((int)uVar6 != -0x3fffff45) && ((int)uVar6 != -0x3ffffff0)) {
        return uVar6;
      }
    }
    FUN_00021370((int)uVar6);
    FUN_000121dc();
  }
  iVar5 = (int)uVar6;
LAB_0001182c:
  FUN_00017594(param_2,iVar5);
  return uVar6;
}



/* ===== FUNC FUN_00011858 @ 00011858 ===== */

undefined8 FUN_00011858(undefined8 param_1,longlong param_2,longlong param_3)

{
  byte *pbVar1;
  longlong *plVar2;
  longlong lVar3;
  longlong *plVar4;
  undefined1 uVar5;
  undefined7 uVar6;
  
  FUN_000121dc();
  pbVar1 = (byte *)(*(longlong *)(param_3 + 0xb8) + 3);
  *pbVar1 = *pbVar1 | 1;
  uVar5 = KeAcquireSpinLockRaiseToDpc(param_2 + 0xf0);
  LOCK();
  *(code **)(param_3 + 0x68) = FUN_00011adc;
  UNLOCK();
  plVar2 = (longlong *)(param_3 + 0xa8);
  uVar6 = (undefined7)((ulonglong)plVar2 >> 8);
  if (*(char *)(param_3 + 0x44) == '\x01') {
    LOCK();
    lVar3 = *(longlong *)(param_3 + 0x68);
    *(longlong *)(param_3 + 0x68) = 0;
    UNLOCK();
    *(longlong **)(param_3 + 0xb0) = plVar2;
    *plVar2 = (longlong)plVar2;
    KeReleaseSpinLock(param_2 + 0xf0,CONCAT71(uVar6,uVar5));
    if (lVar3 != 0) {
      *(undefined8 *)(param_3 + 0x38) = 0;
      *(undefined4 *)(param_3 + 0x30) = 0xc0000120;
      IofCompleteRequest(param_3,0);
    }
  }
  else {
    plVar4 = *(longlong **)(param_2 + 0x98);
    *plVar2 = param_2 + 0x90;
    *(longlong **)(param_3 + 0xb0) = plVar4;
    *plVar4 = (longlong)plVar2;
    *(longlong **)(param_2 + 0x98) = plVar2;
    KeReleaseSpinLock(param_2 + 0xf0,CONCAT71(uVar6,uVar5));
  }
  FUN_0001216c(param_1,param_2);
  return 0x103;
}



/* ===== FUNC FUN_00011958 @ 00011958 ===== */

void FUN_00011958(longlong *param_1,longlong *param_2)

{
  longlong **pplVar1;
  longlong ***ppplVar2;
  longlong ****pppplVar3;
  undefined1 uVar4;
  undefined8 uVar5;
  longlong ****pppplVar6;
  undefined7 uVar7;
  longlong ****local_18;
  longlong ****local_10;
  
  FUN_000121dc();
  local_10 = (longlong ****)&local_18;
  local_18 = (longlong ****)&local_18;
  uVar4 = KeAcquireSpinLockRaiseToDpc(param_2 + 0x1e);
  pplVar1 = (longlong **)(param_2 + 0x12);
  while( true ) {
    if ((longlong **)*pplVar1 == pplVar1) break;
    pppplVar6 = (longlong ****)*pplVar1;
    ppplVar2 = *pppplVar6;
    *pplVar1 = (longlong *)ppplVar2;
    ppplVar2[1] = pplVar1;
    LOCK();
    ppplVar2 = pppplVar6[-8];
    pppplVar6[-8] = (longlong ***)0x0;
    UNLOCK();
    uVar7 = (undefined7)((ulonglong)pppplVar6 >> 8);
    if (*(char *)((longlong)pppplVar6 + -100) == '\x01') {
      if (ppplVar2 == (longlong ***)0x0) {
        pppplVar6[1] = (longlong ***)pppplVar6;
        *pppplVar6 = (longlong ***)pppplVar6;
      }
      else {
        pppplVar6[1] = (longlong ***)local_10;
        *pppplVar6 = (longlong ***)&local_18;
        *local_10 = (longlong ***)pppplVar6;
        local_10 = pppplVar6;
      }
      KeReleaseSpinLock(param_2 + 0x1e,CONCAT71(uVar7,uVar4));
    }
    else {
      KeReleaseSpinLock(param_2 + 0x1e,CONCAT71(uVar7,uVar4));
      if (*(int *)((longlong)param_2 + 0x8c) == 2) {
        pppplVar6[-0xe] = (longlong ***)0x0;
        *(undefined4 *)(pppplVar6 + -0xf) = 0xc000000e;
        IofCompleteRequest(pppplVar6 + -0x15,0);
      }
      else {
        uVar5 = FUN_00039198(*param_2,(longlong)(pppplVar6 + -0x15));
        if ((int)uVar5 == 0x103) goto LAB_00011a76;
      }
    }
    uVar4 = KeAcquireSpinLockRaiseToDpc(param_2 + 0x1e);
  }
  KeReleaseSpinLock(param_2 + 0x1e,uVar4);
LAB_00011a76:
  pppplVar6 = local_18;
  if ((longlong *****)local_18 != &local_18) {
    do {
      pppplVar3 = (longlong ****)*pppplVar6;
      pppplVar3[1] = (longlong ***)&local_18;
      pppplVar6[-0xe] = (longlong ***)0x0;
      *(undefined4 *)(pppplVar6 + -0xf) = 0xc0000120;
      local_18 = pppplVar3;
      IofCompleteRequest(pppplVar6 + -0x15,0);
      pppplVar6 = local_18;
    } while ((longlong *****)local_18 != &local_18);
  }
  return;
}



/* ===== FUNC FUN_00011adc @ 00011adc ===== */

void FUN_00011adc(longlong param_1,longlong param_2)

{
  longlong lVar1;
  longlong *plVar2;
  longlong lVar3;
  
  lVar1 = *(longlong *)(param_1 + 0x40);
  FUN_000121dc();
  IoReleaseCancelSpinLock();
  KeAcquireSpinLockAtDpcLevel(lVar1 + 0xf0);
  plVar2 = *(longlong **)(param_2 + 0xb0);
  lVar3 = *(longlong *)(param_2 + 0xa8);
  *plVar2 = lVar3;
  *(longlong **)(lVar3 + 8) = plVar2;
  KeReleaseSpinLockFromDpcLevel(lVar1 + 0xf0);
  *(undefined8 *)(param_2 + 0x38) = 0;
  *(undefined4 *)(param_2 + 0x30) = 0xc0000120;
                    /* WARNING: Could not recover jumptable at 0x00011b5a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  IofCompleteRequest(param_2,0);
  return;
}



/* ===== FUNC FUN_00011b68 @ 00011b68 ===== */

undefined8 FUN_00011b68(void)

{
  FUN_000121dc();
  return 0;
}



/* ===== FUNC FUN_00011b90 @ 00011b90 ===== */

undefined8 FUN_00011b90(void)

{
  FUN_000121dc();
  return 0;
}



/* ===== FUNC FUN_00011bb8 @ 00011bb8 ===== */

undefined8 FUN_00011bb8(longlong param_1)

{
  longlong lVar1;
  
  lVar1 = param_1;
  FUN_000121dc();
  FUN_00020478(*(longlong *)(lVar1 + 0x40));
  FUN_0001f978(*(longlong *)(param_1 + 0x40));
  return 0;
}



/* ===== FUNC FUN_00011bf8 @ 00011bf8 ===== */

void FUN_00011bf8(undefined8 param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  longlong lVar4;
  uint uVar5;
  uint uVar6;
  undefined1 auStack_b8 [32];
  uint *local_98;
  uint *local_90;
  uint local_88;
  int local_84;
  int local_80 [2];
  undefined8 local_78;
  undefined1 local_70 [16];
  undefined1 local_60 [16];
  undefined1 local_50;
  undefined1 local_4f;
  undefined1 local_4e;
  undefined1 local_4d;
  undefined1 local_4c;
  undefined1 local_4b;
  undefined1 local_48;
  undefined1 local_47;
  undefined1 local_46;
  undefined1 local_45;
  undefined1 local_44;
  undefined1 local_43;
  undefined1 local_42;
  undefined1 local_41;
  ulonglong local_40;
  
  local_40 = DAT_00037100 ^ (ulonglong)auStack_b8;
  local_98 = (uint *)(local_80 + 1);
  local_80[1] = 0;
  iVar1 = IoGetDeviceProperty(param_1,0x11,4,param_2);
  iVar2 = 0;
  if (iVar1 != 0) {
    iVar2 = IoOpenDeviceRegistryKey(param_1,1,0x20019,&local_78);
    if (-1 < iVar2) {
      local_88 = 0;
      RtlInitUnicodeString(local_60,L"Identity");
      local_90 = &local_88;
      local_98 = (uint *)((ulonglong)local_98 & 0xffffffff00000000);
      iVar2 = ZwQueryValueKey(local_78,local_60,2,0);
      if (iVar2 != -0x3fffffcc) {
        if ((local_88 != 0) && (local_88 < 0x1000)) {
          lVar4 = ExAllocatePoolWithTag(1,local_88,0x31747345);
          local_90 = &local_88;
          local_98 = (uint *)CONCAT44(local_98._4_4_,local_88);
          iVar2 = ZwQueryValueKey(local_78,local_60,2,lVar4);
          if (-1 < iVar2) {
            uVar5 = 0;
            uVar6 = 0;
            local_48 = 0x75;
            local_47 = 0;
            local_46 = 0x75;
            local_45 = 0;
            local_44 = 0x69;
            local_43 = 0;
            local_42 = 100;
            local_41 = 0;
            local_50 = 0x75;
            local_4f = 0;
            local_4e = 0x72;
            local_4d = 0;
            local_4c = 0x6e;
            local_4b = 0;
            iVar1 = RtlCompareMemory(&local_48,lVar4 + 0xc,8);
            iVar3 = RtlCompareMemory(&local_50,lVar4 + 0xc,6);
            if (iVar1 == 8) {
              uVar5 = 0x26;
              uVar6 = 0x30;
            }
            else if (iVar3 == 6) {
              uVar5 = 0x2e;
              uVar6 = 0x38;
            }
            else {
              iVar2 = -0x3ffffddb;
            }
            if (iVar2 != -0x3ffffddb) {
              RtlInitUnicodeString(local_70,(ulonglong)uVar5 + 0xc + lVar4);
              RtlUnicodeStringToInteger(local_70,0x10,local_80);
              RtlInitUnicodeString(local_70,(ulonglong)uVar6 + 0xc + lVar4);
              RtlUnicodeStringToInteger(local_70,0x10,&local_84);
              local_84 = local_84 + local_80[0] * 0x10000;
              *param_2 = local_84;
            }
          }
          ExFreePoolWithTag(lVar4,0);
        }
      }
      ZwClose(local_78);
    }
  }
  if (iVar2 == -0x3ffffddb) {
    local_98 = &local_88;
    local_88 = 0;
    iVar2 = IoGetDeviceProperty(param_1,10,0);
    if (iVar2 == -0x3fffffcc) goto LAB_00011f38;
    if ((local_88 == 0) || (0xfcc < local_88 - 0x33)) goto LAB_00011f38;
    lVar4 = ExAllocatePoolWithTag(1,local_88,0x31747345);
    local_98 = (uint *)(local_80 + 1);
    iVar2 = IoGetDeviceProperty(param_1,10,local_88,lVar4);
    if (-1 < iVar2) {
      RtlInitUnicodeString(local_70,lVar4 + -0x2e + (ulonglong)(local_88 >> 1) * 2);
      RtlUnicodeStringToInteger(local_70,0x10,local_80);
      RtlInitUnicodeString(local_70,lVar4 + -0x24 + (ulonglong)(local_88 >> 1) * 2);
      RtlUnicodeStringToInteger(local_70,0x10,&local_84);
      local_84 = local_84 + local_80[0] * 0x10000;
      *param_2 = local_84;
      ExFreePoolWithTag(lVar4,0);
      goto LAB_00011f38;
    }
  }
  else {
LAB_00011f38:
    if (-1 < iVar2) goto LAB_00011f3f;
  }
  *param_2 = 0;
LAB_00011f3f:
  FUN_00025050(local_40 ^ (ulonglong)auStack_b8);
  return;
}



/* ===== FUNC FUN_00011f70 @ 00011f70 ===== */

void FUN_00011f70(void)

{
  int iVar1;
  undefined1 auStack_118 [32];
  undefined4 local_f8;
  undefined1 *local_f0;
  undefined8 local_e8;
  ushort local_e0 [4];
  void *local_d8;
  undefined1 local_d0 [8];
  undefined4 local_c8 [2];
  undefined8 local_c0;
  undefined1 *local_b8;
  undefined4 local_b0;
  undefined8 local_a8;
  undefined8 local_a0;
  undefined1 local_98 [16];
  undefined1 local_88 [16];
  undefined1 local_78 [16];
  undefined1 local_68 [12];
  undefined1 local_5c [68];
  ulonglong local_18;
  
  local_18 = DAT_00037100 ^ (ulonglong)auStack_118;
  RtlInitUnicodeString
            (local_98,L"\\Registry\\Machine\\System\\CurrentControlSet\\Services\\Tcpip\\Parameters"
            );
  RtlInitUnicodeString(local_88);
  DAT_0003782c = 0;
  FUN_000251f0((ulonglong *)&DAT_00037830,0,0x40);
  local_c0 = 0;
  local_a8 = 0;
  local_a0 = 0;
  local_b8 = local_98;
  local_c8[0] = 0x30;
  local_b0 = 0x240;
  iVar1 = ZwOpenKey(&local_e8,0x20019,local_c8);
  if (-1 < iVar1) {
    local_f0 = local_d0;
    local_f8 = 0x50;
    iVar1 = ZwQueryValueKey(local_e8,local_88,2,local_68);
    if (-1 < iVar1) {
      RtlInitUnicodeString(local_78,local_5c);
      RtlUnicodeStringToAnsiString(local_e0,local_78,1);
      DAT_0003782c = (uint)local_e0[0];
      memcpy(&DAT_00037830,local_d8,(ulonglong)local_e0[0]);
      RtlFreeAnsiString(local_e0);
    }
  }
  ZwClose(local_e8);
  FUN_00025050(local_18 ^ (ulonglong)auStack_118);
  return;
}



/* ===== FUNC FUN_000120dc @ 000120dc ===== */

void FUN_000120dc(uint param_1)

{
  longlong local_res10 [3];
  
  if (param_1 != 0) {
    local_res10[0] = (ulonglong)param_1 * -10000;
    KeDelayExecutionThread(0,0,local_res10);
  }
  return;
}



/* ===== FUNC FUN_0001210c @ 0001210c ===== */

void FUN_0001210c(void)

{
  undefined8 local_res10 [3];
  
  local_res10[0] = 0xffffffffff676980;
  KeDelayExecutionThread(0,0,local_res10);
  return;
}



/* ===== FUNC FUN_00012134 @ 00012134 ===== */

int FUN_00012134(undefined8 param_1,longlong param_2)

{
  int *piVar1;
  int iVar2;
  
  LOCK();
  piVar1 = (int *)(param_2 + 0x128);
  iVar2 = *piVar1;
  *piVar1 = *piVar1 + 1;
  UNLOCK();
  if (iVar2 + 1 == 2) {
    KeClearEvent(param_2 + 0x110);
  }
  return iVar2 + 1;
}



/* ===== FUNC FUN_0001216c @ 0001216c ===== */

int FUN_0001216c(undefined8 param_1,longlong param_2)

{
  int *piVar1;
  int iVar2;
  
  LOCK();
  piVar1 = (int *)(param_2 + 0x128);
  iVar2 = *piVar1;
  *piVar1 = *piVar1 + -1;
  UNLOCK();
  iVar2 = iVar2 + -1;
  if (iVar2 == 1) {
    KeSetEvent(param_2 + 0x110,0,0);
  }
  if (iVar2 == 0) {
    KeSetEvent(param_2 + 0xf8,0,0);
  }
  return iVar2;
}



/* ===== FUNC FUN_000121c8 @ 000121c8 ===== */

void FUN_000121c8(void)

{
  return;
}



/* ===== FUNC FUN_000121dc @ 000121dc ===== */

void FUN_000121dc(void)

{
  return;
}



/* ===== FUNC FUN_000121e8 @ 000121e8 ===== */

undefined8 FUN_000121e8(longlong param_1,longlong param_2)

{
  longlong lVar1;
  undefined8 *puVar2;
  undefined8 uVar3;
  longlong lVar4;
  ulonglong uVar5;
  
  lVar1 = *(longlong *)(param_1 + 0x40);
  puVar2 = *(undefined8 **)(param_2 + 0x18);
  if (*(uint *)(*(longlong *)(param_2 + 0xb8) + 0x10) < 0x17) {
    uVar3 = 0xc000009a;
  }
  else {
    uVar5 = (ulonglong)*(byte *)((longlong)puVar2 + 6);
    FUN_000121dc();
    *(undefined8 *)(param_2 + 0x38) = 0x17;
    lVar4 = uVar5 * 0x268;
    *puVar2 = *(undefined8 *)(lVar4 + 0x1028 + lVar1);
    puVar2[1] = *(undefined8 *)(lVar4 + 0x1030 + lVar1);
    *(undefined4 *)(puVar2 + 2) = *(undefined4 *)(lVar4 + 0x1038 + lVar1);
    *(undefined2 *)((longlong)puVar2 + 0x14) = *(undefined2 *)(lVar4 + 0x103c + lVar1);
    *(undefined1 *)((longlong)puVar2 + 0x16) = *(undefined1 *)(lVar4 + 0x103e + lVar1);
    uVar3 = 0;
    *(char *)(lVar4 + 0x102e + lVar1) = (char)uVar5;
    *(undefined4 *)(lVar4 + 0x102f + lVar1) = 0;
    *(undefined4 *)(lVar4 + 0x1033 + lVar1) = 0;
    *(undefined4 *)(lVar4 + 0x1037 + lVar1) = 0;
    *(undefined4 *)(lVar4 + 0x103b + lVar1) = 0;
  }
  return uVar3;
}



/* ===== FUNC FUN_000122b0 @ 000122b0 ===== */

void FUN_000122b0(STRSAFE_PCNZWCH param_1,size_t param_2,STRSAFE_LPCWSTR param_3,undefined8 param_4)

{
  HRESULT HVar1;
  undefined8 local_res20;
  
  local_res20 = param_4;
  HVar1 = StringValidateDestW(param_1,param_2,0);
  if (-1 < HVar1) {
    StringVPrintfWorkerW(param_1,param_2,(size_t *)0x0,param_3,(va_list)&local_res20);
  }
  return;
}



/* ===== FUNC FUN_00012304 @ 00012304 ===== */

void FUN_00012304(undefined8 param_1,longlong param_2)

{
  int *piVar1;
  char *pcVar2;
  byte bVar3;
  longlong lVar4;
  longlong lVar5;
  
  bVar3 = *(byte *)(param_2 + 0x24);
  lVar4 = *(longlong *)(*(longlong *)(param_2 + 0x28) + 0x40);
  FUN_000121dc();
  if (*(char *)(lVar4 + 0xfd0) == '\0') {
    ExAcquireFastMutex(lVar4 + 0xb8);
    lVar5 = (ulonglong)bVar3 * 0x268;
    LOCK();
    piVar1 = (int *)(lVar5 + 0xfd8 + lVar4);
    *piVar1 = *piVar1 + 1;
    UNLOCK();
    pcVar2 = (char *)(lVar5 + 0xfdc + lVar4);
    *pcVar2 = *pcVar2 + -1;
    if (*pcVar2 == '\0') {
      FUN_000121dc();
      KeSetEvent(lVar4 + 0xf88,0,0);
    }
    ExReleaseFastMutex(lVar4 + 0xb8);
  }
  return;
}



/* ===== FUNC FUN_000123c0 @ 000123c0 ===== */

int FUN_000123c0(longlong param_1,longlong param_2)

{
  longlong lVar1;
  int iVar2;
  
  lVar1 = *(longlong *)(param_1 + 0x40);
  *(longlong *)(param_2 + 0x78) = lVar1;
  iVar2 = IoAcquireRemoveLockEx(lVar1 + 0x130,param_2,&LAB_00026aa0,1,0x20);
  if (iVar2 == 0) {
    *(char *)(param_2 + 0x43) = *(char *)(param_2 + 0x43) + '\x01';
    *(longlong *)(param_2 + 0xb8) = *(longlong *)(param_2 + 0xb8) + 0x48;
    iVar2 = IofCallDriver(*(undefined8 *)(lVar1 + 0x28),param_2);
    IoReleaseRemoveLockEx(lVar1 + 0x130,param_2,0x20);
  }
  else {
    FUN_000121dc();
  }
  return iVar2;
}



/* ===== FUNC FUN_00012478 @ 00012478 ===== */

int FUN_00012478(undefined8 param_1,longlong param_2)

{
  int iVar1;
  
  iVar1 = 0;
  if (*(char *)(param_2 + 0x210) == '\0') {
    iVar1 = IoRegisterDeviceInterface(param_1,&DAT_00035f90,0,param_2 + 0x200);
    if (iVar1 == 0) {
      FUN_000121dc();
      IoSetDeviceInterfaceState(param_2 + 0x200,1);
      *(undefined1 *)(param_2 + 0x210) = 1;
    }
    else {
      FUN_00021370(iVar1);
      FUN_000121dc();
    }
  }
  return iVar1;
}



/* ===== FUNC FUN_00012520 @ 00012520 ===== */

undefined8 FUN_00012520(longlong param_1)

{
  if (*(char *)(param_1 + 0x210) == '\x01') {
    IoSetDeviceInterfaceState(param_1 + 0x200,0);
    IoDeleteSymbolicLink(param_1 + 0x200);
    RtlFreeUnicodeString(param_1 + 0x200);
    *(undefined1 *)(param_1 + 0x210) = 0;
  }
  return 0;
}



/* ===== FUNC FUN_0001257c @ 0001257c ===== */

int FUN_0001257c(undefined8 param_1,longlong param_2)

{
  longlong *plVar1;
  longlong *plVar2;
  int iVar3;
  int iVar4;
  STRSAFE_PCNZWCH pwVar5;
  ulonglong uVar6;
  longlong lVar7;
  longlong *plVar8;
  longlong *plVar9;
  uint uVar10;
  undefined1 uVar11;
  uint uVar12;
  uint local_res18 [2];
  longlong local_res20;
  undefined8 in_stack_ffffffffffffff98;
  ulonglong in_stack_ffffffffffffffa0;
  undefined4 uVar13;
  code *pcVar14;
  undefined1 local_48 [16];
  
  uVar10 = (uint)((ulonglong)in_stack_ffffffffffffff98 >> 0x20);
  local_res20 = 0;
  DbgPrint(&LAB_000262b0);
  FUN_00011bf8(param_2,(int *)local_res18);
  FUN_000121c8();
  pwVar5 = (STRSAFE_PCNZWCH)ExAllocatePoolWithTag(0,0x34,0x34747345);
  if (pwVar5 == (STRSAFE_PCNZWCH)0x0) {
    return -0x3fffff66;
  }
  FUN_000251f0((ulonglong *)pwVar5,0,0x34);
  FUN_000122b0(pwVar5,0x34,L"\\Device\\Generic_%08X",(ulonglong)local_res18[0]);
  RtlInitUnicodeString(local_48,pwVar5);
  iVar3 = IoCreateDevice(param_1,0x2080,local_48,4,(ulonglong)uVar10 << 0x20,
                         in_stack_ffffffffffffffa0 & 0xffffffffffffff00,&local_res20);
  FUN_00021370(iVar3);
  FUN_000121c8();
  ExFreePoolWithTag(pwVar5,0x34747345);
  if (iVar3 < 0) {
    return iVar3;
  }
  iVar3 = 3;
  plVar2 = *(longlong **)(local_res20 + 0x40);
  FUN_000121c8();
  *(undefined4 *)(plVar2 + 5) = 0x6f644653;
  *(undefined4 *)((longlong)plVar2 + 0xc) = 0;
  *(undefined4 *)(plVar2 + 2) = 0;
  *(undefined2 *)(plVar2 + 0x400) = 0x5b4;
  *(undefined1 *)((longlong)plVar2 + 300) = 0;
  plVar2[6] = param_2;
  *(undefined4 *)((longlong)plVar2 + 0x8c) = 0;
  uVar12 = iVar3 - 2;
  uVar11 = (undefined1)uVar12;
  *(undefined1 *)(plVar2 + 1) = uVar11;
  *(undefined1 *)((longlong)plVar2 + 0x214) = uVar11;
  *plVar2 = local_res20;
  plVar2[7] = 0;
  plVar2[8] = 0;
  plVar9 = plVar2 + 0x12;
  plVar2[0x13] = (longlong)plVar9;
  *plVar9 = (longlong)plVar9;
  plVar9 = plVar2 + 0x14;
  plVar2[0x15] = (longlong)plVar9;
  *plVar9 = (longlong)plVar9;
  *(uint *)(plVar2 + 0x17) = uVar12;
  plVar2[0x18] = 0;
  *(undefined4 *)(plVar2 + 0x19) = 0;
  KeInitializeEvent(plVar2 + 0x1a,uVar12,0);
  plVar2[0x1e] = 0;
  KeInitializeEvent(plVar2 + 0x1f,uVar12,0);
  KeInitializeEvent(plVar2 + 0x22,uVar12,uVar11);
  plVar9 = plVar2 + 0x4c;
  *(undefined4 *)(plVar2 + 0x42) = 0;
  *(undefined1 *)(plVar2 + 0x11) = 0;
  plVar2[0x4b] = 0;
  plVar2[0x4d] = (longlong)plVar9;
  *plVar9 = (longlong)plVar9;
  IoCsqInitialize(plVar2 + 0x43,&LAB_00015f98,&LAB_00015fbc,FUN_00015fd8,FUN_000160c4,&LAB_000166cc,
                  FUN_000160e8);
  plVar9 = plVar2 + 0x57;
  plVar2[0x56] = 0;
  plVar2[0x58] = (longlong)plVar9;
  *plVar9 = (longlong)plVar9;
  pcVar14 = FUN_000166e0;
  uVar13 = 0;
  IoCsqInitialize(plVar2 + 0x4e,FUN_000165dc,&LAB_00015fbc,FUN_00016650,FUN_000160c4,&LAB_000166cc,
                  FUN_000166e0);
  uVar10 = 0;
  do {
    lVar7 = *(longlong *)(local_res20 + 0x40);
    uVar6 = (ulonglong)(uVar10 & 0xff);
    uVar10 = uVar10 + uVar12;
    *(undefined1 *)(lVar7 + 0x2c8 + uVar6 * 0x48) = 0xff;
    *(undefined1 *)(lVar7 + 0x2ca + uVar6 * 0x48) = 0xff;
    *(undefined1 *)(lVar7 + 0x2c9 + uVar6 * 0x48) = 0xff;
    *(undefined8 *)(lVar7 + 0x300 + uVar6 * 0x48) = 0;
    *(undefined1 *)(lVar7 + 0x2e8 + uVar6 * 0x48) = 0;
    *(undefined4 *)(lVar7 + 0x2ec + uVar6 * 0x48) = 0;
    *(undefined4 *)(lVar7 + 0x2f0 + uVar6 * 0x48) = 0xf0;
    *(undefined1 *)(lVar7 + 0x2fc + uVar6 * 0x48) = 0;
    *(undefined4 *)(lVar7 + 0x2f4 + uVar6 * 0x48) = 0;
    *(undefined4 *)(lVar7 + 0x308 + uVar6 * 0x48) = 2000000;
  } while (uVar10 < 3);
  KeInitializeTimerEx(plVar2 + 0x77,uVar12);
  KeInitializeDpc(plVar2 + 0x7f,FUN_000177b0,local_res20);
  KeInitializeTimerEx(plVar2 + 0x97,uVar12);
  KeInitializeDpc(plVar2 + 0x9f,FUN_00017888,local_res20);
  KeInitializeTimerEx(plVar2 + 0x87,uVar12);
  KeInitializeDpc(plVar2 + 0x8f,FUN_00017984,local_res20);
  KeQueryPerformanceCounter(plVar2 + 0x401);
  KeInitializeTimerEx(plVar2 + 0xa7,uVar12);
  KeInitializeDpc(plVar2 + 0xaf,FUN_00017a70,local_res20);
  ExInitializeNPagedLookasideList
            (plVar2 + 0x3f0,0,0,0,0x5b4,CONCAT44(uVar13,0x37747345),
             (ulonglong)pcVar14 & 0xffffffffffff0000);
  plVar9 = plVar2 + 0x262;
  uVar10 = uVar12;
  do {
    *(undefined4 *)(plVar9 + -1) = 0;
    KeInitializeEvent(plVar9,0,uVar11);
    KeInitializeEvent(plVar9 + 3,uVar12,uVar11);
    *(undefined4 *)(plVar9 + -0x1a) = 0;
    *(undefined4 *)(plVar9 + -0xd) = 0;
    KeInitializeMutex(plVar9 + -0xc,0);
    KeInitializeEvent(plVar9 + -0x19,uVar12,0);
    KeInitializeEvent(plVar9 + -0x16,uVar12,0);
    *(undefined1 *)((longlong)plVar9 + -0x94) = 0;
    *(undefined4 *)(plVar9 + -0x12) = 0;
    *(undefined1 *)((longlong)plVar9 + -0x8c) = 0;
    *(undefined4 *)(plVar9 + -0x11) = 0;
    plVar9[-5] = 0;
    *(undefined4 *)(plVar9 + -4) = 0;
    *(undefined4 *)((longlong)plVar9 + -0x1c) = 0;
    *(char *)(plVar9 + 0x32) = (char)uVar10;
    uVar10 = uVar10 + uVar12;
    *(undefined2 *)(plVar9 + -0x10) = 0x100;
    plVar9[0x31] = local_res20;
    *(undefined4 *)((longlong)plVar9 + -0x7e) = 0x17;
    *(undefined4 *)((longlong)plVar9 + -0x79) = 0;
    *(undefined4 *)((longlong)plVar9 + -0x75) = 0;
    *(undefined4 *)((longlong)plVar9 + -0x71) = 0;
    *(undefined4 *)((longlong)plVar9 + -0x6d) = 0;
    plVar9 = plVar9 + 0x4d;
  } while (uVar10 < 6);
  plVar9 = plVar2 + 0x3d0;
  plVar8 = plVar2 + 0xe7;
  uVar10 = uVar12;
  do {
    *(char *)plVar8 = (char)uVar10;
    *(longlong **)((longlong)plVar8 + 1) = plVar2;
    plVar8[-0x13] = 0;
    KeInitializeEvent(plVar8 + -0x16,uVar12,0);
    plVar8[-0xc] = 0;
    KeInitializeEvent(plVar8 + -0x12,uVar12);
    KeInitializeEvent(plVar8 + -0xf,uVar12);
    KeInitializeEvent(plVar8 + -0xb,uVar12);
    plVar1 = plVar8 + 2;
    plVar8[3] = (longlong)plVar1;
    *plVar1 = (longlong)plVar1;
    *(char *)plVar9 = (char)uVar10;
    uVar10 = uVar10 + uVar12;
    plVar9[-1] = local_res20;
    plVar9 = plVar9 + 6;
    plVar8 = plVar8 + 0x1a;
  } while (uVar10 < 6);
  KeInitializeEvent(plVar2 + 0x1cf,uVar12,0);
  KeInitializeEvent(plVar2 + 0x1d3,uVar12,0);
  plVar2[0x1d8] = 0;
  plVar9 = plVar2 + 0x1d6;
  plVar2[0x1d7] = (longlong)plVar9;
  *plVar9 = (longlong)plVar9;
  plVar9 = plVar2 + 0x1df;
  plVar2[0x1e0] = (longlong)plVar9;
  *plVar9 = (longlong)plVar9;
  KeInitializeTimerEx(plVar2 + 0x1e1,uVar12);
  KeInitializeDpc(plVar2 + 0x1e9,FUN_00017d0c,local_res20);
  plVar2[0x1d9] = 0;
  IoCsqInitialize(plVar2 + 0xc5,&LAB_000161d4,&LAB_00015fbc,&LAB_00016214,FUN_00016260,&LAB_00016338
                  ,FUN_000163b0);
  plVar2[0x1da] = 0;
  IoCsqInitialize(plVar2 + 0xdf,&LAB_000161d4,&LAB_00015fbc,&LAB_00016214,FUN_00016284,&LAB_0001634c
                  ,FUN_000163b0);
  plVar2[0x1db] = 0;
  IoCsqInitialize(plVar2 + 0xf9,&LAB_000161d4,&LAB_00015fbc,&LAB_00016214,FUN_000162a8,&LAB_00016360
                  ,FUN_000163b0);
  plVar2[0x1dc] = 0;
  IoCsqInitialize(plVar2 + 0x113,&LAB_000161d4,&LAB_00015fbc,&LAB_00016214,FUN_000162cc,
                  &LAB_00016374,FUN_000163b0);
  plVar2[0x1dd] = 0;
  IoCsqInitialize(plVar2 + 0x12d,&LAB_000161d4,&LAB_00015fbc,&LAB_00016214,FUN_000162f0,
                  &LAB_00016388,FUN_000163b0);
  plVar2[0x1de] = 0;
  IoCsqInitialize(plVar2 + 0x147,&LAB_000161d4,&LAB_00015fbc,&LAB_00016214,FUN_00016314,
                  &LAB_0001639c,FUN_000163b0);
  uVar10 = 0;
  plVar9 = plVar2 + 0x153;
  do {
    *plVar9 = 0;
    plVar9[7] = 0;
    *(char *)(plVar9 + 3) = (char)uVar10;
    *(undefined1 *)(plVar9 + 1) = 0xff;
    *(undefined1 *)((longlong)plVar9 + 9) = 0xff;
    *(undefined1 *)((longlong)plVar9 + 10) = 0xff;
    plVar9[2] = 0;
    KeInitializeEvent(plVar9 + 4,1,0);
    KeInitializeEvent(plVar9 + 8,1,0);
    KeInitializeSemaphore(plVar9 + 0x13,0x40,0x40);
    plVar8 = plVar9 + 0x17;
    plVar9[0x18] = (longlong)plVar8;
    *plVar8 = (longlong)plVar8;
    plVar9[0x19] = 0;
    IoCsqInitialize(plVar9 + 0xb,FUN_0001647c,&LAB_00015fbc,&LAB_0001651c,FUN_00016584,&LAB_000165a8
                    ,&LAB_000165bc);
    uVar10 = uVar10 + 1;
    plVar9[0x1b] = 0;
    plVar9 = plVar9 + 0x1f;
  } while (uVar10 < 4);
  KeInitializeEvent(plVar2 + 0x1f1,1,0);
  KeInitializeEvent(plVar2 + 500,0,1);
  KeInitializeEvent(plVar2 + 0x1f7,1,1);
  *(undefined1 *)(plVar2 + 0x1fa) = 1;
  *(undefined1 *)((longlong)plVar2 + 0x215) = 1;
  KeInitializeEvent(plVar2 + 0x402,1,0);
  KeInitializeEvent(plVar2 + 0x405,1,0);
  KeInitializeEvent(plVar2 + 0x408,1,0);
  KeInitializeEvent(plVar2 + 0x40b,1,1);
  *(undefined4 *)(plVar2 + 0x25) = 1;
  *(uint *)(local_res20 + 0x30) = *(uint *)(local_res20 + 0x30) | 0x2000;
  *(uint *)(local_res20 + 0x30) = *(uint *)(local_res20 + 0x30) | 4;
  *(undefined4 *)((longlong)plVar2 + 0x1c) = 4;
  *(undefined4 *)(plVar2 + 3) = 1;
  PoSetPowerState(local_res20,1,4);
  *(undefined4 *)((longlong)plVar2 + 0x1d4) = 1;
  *(undefined1 *)((longlong)plVar2 + 0x1d1) = 0;
  plVar2[0x3b] = 0;
  KeInitializeEvent(plVar2 + 0x3f,1,1);
  KeInitializeEvent(plVar2 + 0x3c,0,1);
  lVar7 = IoAttachDeviceToDeviceStack(local_res20,param_2);
  plVar2[7] = lVar7;
  if (lVar7 == 0) {
    iVar3 = -0x3ffffff2;
  }
  else {
    IoRegisterDeviceInterface(param_2,&DAT_00035a50,0,plVar2 + 9);
    IoRegisterDeviceInterface(param_2,&DAT_00035fa0,0,plVar2 + 0xb);
    FUN_000121c8();
    iVar3 = IoRegisterDeviceInterface(param_2,&DAT_00035f80,0,plVar2 + 0xd);
    iVar4 = FUN_000121c8();
    if (-1 < iVar4) {
      *(undefined1 *)((longlong)plVar2 + 0x24) = 0;
      *(undefined4 *)(plVar2 + 0x40e) = 0;
      *(uint *)(plVar2 + 4) = local_res18[0];
      *(uint *)(local_res20 + 0x30) = *(uint *)(local_res20 + 0x30) & 0xffffff7f;
      FUN_000121c8();
      return iVar3;
    }
    FUN_000121c8();
    IoDetachDevice(plVar2[7]);
  }
  IoDeleteDevice(local_res20);
  return iVar3;
}



/* ===== FUNC FUN_00012ff0 @ 00012ff0 ===== */

undefined8 FUN_00012ff0(undefined8 param_1,longlong param_2,undefined8 param_3)

{
  FUN_00021370(*(int *)(param_2 + 0x30));
  FUN_000121dc();
  if (*(char *)(param_2 + 0x41) == '\x01') {
    KeSetEvent(param_3,0,0);
  }
  return 0xc0000016;
}



/* ===== FUNC FUN_00013050 @ 00013050 ===== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong FUN_00013050(longlong param_1,longlong param_2,undefined1 param_3,longlong param_4,
                      undefined8 param_5,undefined1 *param_6)

{
  undefined1 uVar1;
  longlong *plVar2;
  longlong *plVar3;
  longlong lVar4;
  ulonglong *puVar5;
  ulonglong uVar6;
  longlong *plVar7;
  longlong lVar8;
  longlong *plVar9;
  ushort uVar10;
  longlong lVar11;
  ulonglong uVar12;
  char *pcVar13;
  byte bVar14;
  uint uVar15;
  
  plVar2 = *(longlong **)(param_1 + 0x40);
  lVar8 = 0;
  uVar6 = 0;
  lVar4 = FUN_000121dc();
  plVar3 = *(longlong **)(param_4 + 0x40);
  uVar15 = (int)lVar8 + 1;
  uVar12 = (ulonglong)((int)lVar8 + 0x10);
  plVar7 = plVar2 + lVar4 * 0x4d + 0x21f;
  plVar9 = plVar3 + 0x11;
  bVar14 = (byte)uVar15;
  *(byte *)(plVar3 + 0x21) = bVar14;
  do {
    *plVar9 = *plVar7;
    *plVar7 = lVar8;
    *(short *)(plVar7 + -1) = (short)lVar8;
    plVar7 = plVar7 + 2;
    plVar9 = plVar9 + 1;
    uVar12 = uVar12 - uVar15;
  } while (uVar12 != 0);
  lVar11 = plVar3[(ulonglong)*(byte *)(plVar3 + 0x21) + 0x11];
  if ((*(byte *)((longlong)plVar2 + 0x215) == bVar14) && (bVar14 < *(byte *)(lVar11 + 4))) {
    *(byte *)((longlong)plVar3 + 0x25) = bVar14;
  }
  else {
    *(char *)((longlong)plVar3 + 0x25) = (char)lVar8;
  }
  uVar15 = 0x2e;
  if ((DAT_00037820 == 0x5000000) && (uVar15 = 0x2e, *(byte *)((longlong)plVar3 + 0x25) == bVar14))
  {
    uVar15 = 0x3a;
  }
  uVar12 = (ulonglong)uVar15;
  puVar5 = (ulonglong *)ExAllocatePoolWithTag(0,uVar15,0x53747345);
  plVar3[6] = (longlong)puVar5;
  if (puVar5 != (ulonglong *)0x0) {
    FUN_000251f0(puVar5,0,uVar12);
    if ((DAT_00037820 == 0x5000000) && (*(char *)((longlong)plVar3 + 0x25) == '\x01')) {
      FUN_000122b0((STRSAFE_PCNZWCH)plVar3[6],uVar12 * 2,L"USB\\Vid_%04X&Pid_%04X&MI_%02d",
                   (ulonglong)*(ushort *)(plVar2 + lVar4 * 0x4d + 0x21c));
    }
    else {
      FUN_000122b0((STRSAFE_PCNZWCH)plVar3[6],uVar12 * 2,L"USB\\Vid_%04X&Pid_%04X",
                   (ulonglong)*(ushort *)(plVar2 + lVar4 * 0x4d + 0x21c));
    }
    pcVar13 = "====== HardwareId: %ws\n====== Length:     %d\n";
    FUN_000121dc();
    *(int *)(plVar3 + 4) = (int)plVar2[4];
    lVar4 = lVar4 + 7;
    *(undefined1 *)((longlong)plVar3 + 0x24) = *(undefined1 *)(param_2 + 10);
    *(undefined4 *)(plVar3 + 7) = *(undefined4 *)(param_2 + 2);
    *(undefined4 *)((longlong)plVar3 + 0x3c) = *(undefined4 *)(param_2 + 6);
    *(undefined1 *)(plVar3 + 8) = *(undefined1 *)(param_2 + 0xb);
    uVar1 = *(undefined1 *)(param_2 + 0xc);
    *(undefined1 *)((longlong)plVar3 + 0x26) = param_3;
    *(undefined1 *)((longlong)plVar3 + 0x41) = uVar1;
    *(undefined1 *)(plVar3 + 0xd) = 0;
    *(undefined1 *)(plVar3 + 0x42) = 0;
    *(undefined1 *)((longlong)plVar3 + 0x211) = 0;
    *(longlong *)((longlong)plVar3 + 0x74) = plVar2[lVar4 * 0x4d];
    *(longlong *)((longlong)plVar3 + 0x7c) = plVar2[lVar4 * 0x4d + 1];
    *(short *)((longlong)plVar3 + 0x84) = (short)plVar2[lVar4 * 0x4d + 2];
    if ((DAT_00037820 == 0x5000000) && (*(char *)((longlong)plVar3 + 0x25) == '\x01')) {
      uVar6 = FUN_00013ff0(param_1,(undefined8 *)plVar3[(ulonglong)*(byte *)(plVar3 + 0x21) + 0x11],
                           CONCAT71((int7)((ulonglong)pcVar13 >> 8),param_3),(longlong)plVar3);
      uVar6 = uVar6 & 0xffffffff;
    }
    else {
      lVar4 = USBD_ParseConfigurationDescriptorEx
                        (lVar11,lVar11,0xffffffff,0xffffffff,1,0xffffffff,0xffffffff);
      if (lVar4 == 0) {
        lVar4 = USBD_ParseConfigurationDescriptorEx
                          (lVar11,lVar11,0xffffffff,0xffffffff,0xff,0xffffffff,0xffffffff);
        if (lVar4 != 0) {
          *(undefined1 *)((longlong)plVar3 + 0x1f1) = 0xff;
        }
      }
      else {
        *(undefined1 *)((longlong)plVar3 + 0x1f1) = 1;
      }
      if ((*(byte *)(lVar11 + 4) < 2) &&
         (lVar4 = USBD_ParseConfigurationDescriptorEx(lVar11,lVar11,0,0,8,0xffffffff,0xffffffff),
         lVar4 != 0)) {
        *(undefined1 *)((longlong)plVar3 + 0x1f1) = 8;
      }
      lVar11 = plVar3[(ulonglong)*(byte *)(plVar3 + 0x21) + 0x11];
    }
    if ((int)uVar6 == 0) {
      lVar4 = *(longlong *)(param_1 + 0x40);
      *param_6 = *(undefined1 *)(plVar3[(ulonglong)*(byte *)(plVar3 + 0x21) + 0x11] + 4);
      lVar8 = (ulonglong)*(byte *)(param_2 + 10) * 0x268;
      plVar3[0x23] = *(longlong *)(lVar8 + 0x1200 + lVar4);
      plVar3[0x24] = *(longlong *)(lVar8 + 0x1210 + lVar4);
      plVar3[0x25] = *(longlong *)(lVar8 + 0x1220 + lVar4);
      if ((int)plVar2[0x16] == 0) {
        KeSetTimer(plVar2 + 0x77,0xffffffffff676980,plVar2 + 0x7f);
        KeSetTimer(plVar2 + 0x87,0xffffffffffb3b4c0,plVar2 + 0x8f);
        KeSetTimer(plVar2 + 0x1e1,0xfffffffffff0bdc0,plVar2 + 0x1e9);
        KeSetTimer(plVar2 + 0xa7,0xffffffffffffd8f0,plVar2 + 0xaf);
        KeSetTimerEx(plVar2 + 0x97,0xffffffffffffd8f0,1000,plVar2 + 0x9f);
      }
      *(undefined1 *)(plVar3 + 0x3e) = 0;
      lVar4 = USBD_ParseConfigurationDescriptorEx
                        (plVar3[(ulonglong)*(byte *)(plVar3 + 0x21) + 0x11],
                         plVar3[(ulonglong)*(byte *)(plVar3 + 0x21) + 0x11],0xffffffff,1,0xffffffff,
                         0xffffffff,0xffffffff);
      *(bool *)((longlong)plVar3 + 500) = lVar4 != 0;
      puVar5 = (ulonglong *)ExAllocatePoolWithTag(0,(ulonglong)*(byte *)(lVar11 + 4) * 2,0x53747345)
      ;
      plVar3[0x22] = (longlong)puVar5;
      if (puVar5 != (ulonglong *)0x0) {
        lVar4 = plVar3[(ulonglong)*(byte *)(plVar3 + 0x21) + 0x11];
        FUN_000251f0(puVar5,0,(ulonglong)*(byte *)(lVar11 + 4) * 2);
        uVar10 = 0;
        lVar8 = lVar4;
        if (*(char *)(lVar4 + 4) != '\0') {
          do {
            lVar8 = USBD_ParseConfigurationDescriptorEx
                              (lVar4,lVar8,0xffffffff,0,0xffffffff,0xffffffff,0xffffffff);
            uVar10 = uVar10 + 1;
            *(undefined1 *)puVar5 = *(undefined1 *)(lVar8 + 2);
            puVar5 = (ulonglong *)((longlong)puVar5 + 2);
            lVar8 = lVar8 + 9;
          } while (uVar10 < *(byte *)(lVar4 + 4));
        }
        *(undefined1 *)(plVar3 + 1) = 0;
        *plVar3 = param_4;
        lVar4 = *plVar2;
        *(undefined1 *)((longlong)plVar3 + 0x6a) = 0;
        plVar3[5] = lVar4;
        *(undefined1 *)((longlong)plVar3 + 0x69) = 1;
        *(undefined1 *)((longlong)plVar3 + 0x6d) = 1;
        plVar3[0x3d] = _DAT_fffff78000000014;
        *(undefined4 *)((longlong)plVar3 + 0xc) = 0;
        *(undefined4 *)(plVar3 + 2) = 0;
        plVar9 = plVar3 + 9;
        plVar3[10] = (longlong)plVar9;
        *plVar9 = (longlong)plVar9;
        IoInitializeRemoveLockEx(plVar3 + 0x26,0x53747345,10,0,0x20);
        *(undefined4 *)((longlong)plVar3 + 0x1c) = 4;
        *(undefined4 *)(plVar3 + 3) = 1;
        *(uint *)(param_4 + 0x30) = *(uint *)(param_4 + 0x30) | 0x2000;
        ExAcquireFastMutex(plVar2 + 0x17);
        plVar9 = plVar3 + 0xb;
        plVar7 = (longlong *)plVar2[0x15];
        *plVar9 = (longlong)(plVar2 + 0x14);
        plVar3[0xc] = (longlong)plVar7;
        *plVar7 = (longlong)plVar9;
        plVar2[0x15] = (longlong)plVar9;
        *(int *)(plVar2 + 0x16) = (int)plVar2[0x16] + 1;
        ExReleaseFastMutex(plVar2 + 0x17);
        *(uint *)(param_4 + 0x30) = *(uint *)(param_4 + 0x30) & 0xffffff7f;
        return uVar6;
      }
    }
  }
  *param_6 = 1;
  if (plVar3[6] != 0) {
    ExFreePoolWithTag(plVar3[6],0x53747345);
  }
  if (plVar3[0x23] != 0) {
    ExFreePoolWithTag(plVar3[0x23],0x53747345);
  }
  if (plVar3[0x24] != 0) {
    ExFreePoolWithTag(plVar3[0x24],0x53747345);
  }
  if (plVar3[0x25] != 0) {
    ExFreePoolWithTag(plVar3[0x25],0x53747345);
  }
  return 0xc000009a;
}



/* ===== FUNC FUN_00013678 @ 00013678 ===== */

void FUN_00013678(longlong *param_1,longlong param_2)

{
  char *pcVar1;
  uint uVar2;
  longlong *plVar3;
  bool bVar4;
  short sVar5;
  int iVar6;
  longlong *plVar7;
  ulonglong uVar8;
  undefined1 uVar9;
  char cVar10;
  undefined8 uVar11;
  longlong *plVar12;
  undefined1 auStackY_f8 [32];
  longlong lVar13;
  undefined1 local_88 [8];
  longlong local_80;
  undefined2 local_78;
  undefined4 local_76;
  undefined4 local_72;
  undefined1 local_6e;
  undefined1 local_6d;
  char local_6c;
  undefined1 local_6b;
  undefined8 local_68;
  undefined1 local_60;
  undefined1 local_5f;
  undefined1 local_5e;
  undefined1 local_5d;
  undefined1 local_5c;
  undefined1 local_5b;
  undefined1 local_5a;
  undefined1 local_59;
  undefined1 local_58;
  undefined1 local_57;
  undefined1 local_56;
  undefined1 local_55;
  undefined1 local_54;
  undefined1 local_53;
  undefined1 local_52;
  undefined1 local_51;
  undefined1 local_50;
  undefined1 local_4f;
  undefined1 local_4e;
  undefined1 local_4d;
  undefined1 local_4c;
  undefined1 local_4b;
  undefined1 local_4a;
  undefined1 local_49;
  undefined1 local_48;
  undefined1 local_47;
  ulonglong local_40;
  
  local_40 = DAT_00037100 ^ (ulonglong)auStackY_f8;
  plVar3 = (longlong *)param_1[8];
  FUN_000121dc();
  FUN_000121dc();
  FUN_000121dc();
  FUN_000121dc();
  FUN_000121dc();
  iVar6 = FUN_0001f788((longlong)plVar3);
  if (iVar6 == 0) {
    iVar6 = FUN_0002028c((longlong)plVar3);
    if (iVar6 == 0) {
      plVar12 = plVar3 + (ulonglong)*(byte *)(param_2 + 10) * 6 + 0x3c9;
      iVar6 = FUN_00014adc(param_1,*(uint *)(param_2 + 6),*(ushort *)(param_2 + 0x13),
                           (ulonglong)plVar12);
      if (iVar6 != 0) goto LAB_00013fab;
      FUN_00014fa0((longlong)param_1,*(byte *)(param_2 + 10));
      uVar11 = 0;
      KeSetEvent(plVar3 + (ulonglong)*(byte *)(param_2 + 10) * 0x1a + 0xbb,0,0);
      uVar11 = CONCAT71((int7)((ulonglong)uVar11 >> 8),10);
      iVar6 = FUN_00014db0((longlong)param_1,*(byte *)(param_2 + 10),'\n');
      if (iVar6 != 0) goto LAB_00013fab;
      iVar6 = FUN_0001b4f8((longlong)param_1,param_2,uVar11,plVar12);
      if (iVar6 != 0) {
        FUN_00021370(iVar6);
        FUN_000121dc();
        goto LAB_00013fab;
      }
      uVar2 = *(uint *)(param_2 + 0xd);
      if ((uVar2 < 0x3c) && (uVar2 != 0)) {
        *(undefined4 *)((ulonglong)*(byte *)(param_2 + 10) * 0x268 + 0x1024 + (longlong)plVar3) =
             0x3c;
      }
      else {
        *(uint *)((ulonglong)*(byte *)(param_2 + 10) * 0x268 + 0x1024 + (longlong)plVar3) = uVar2;
      }
      if ((int)plVar3[0x16] == 0) {
        *(undefined2 *)(plVar3 + 0x3ed) = *(undefined2 *)(param_2 + 0x11);
      }
      *(undefined1 *)(plVar3 + 0x1fa) = 1;
      if (((*(int *)(param_2 + 2) != (int)plVar3[4]) || (*(byte *)(param_2 + 10) == 0)) ||
         (5 < *(byte *)(param_2 + 10))) goto LAB_00013fab;
      ExAcquireFastMutex(plVar3 + 0x17);
      plVar12 = plVar3 + 0x14;
      plVar7 = (longlong *)*plVar12;
      bVar4 = true;
      if (plVar7 != plVar12) {
        do {
          if ((*(char *)(param_2 + 10) == *(char *)((longlong)plVar7 + -0x34)) &&
             (bVar4 = false, *(int *)((longlong)plVar7 + -0x4c) != 5)) break;
          plVar7 = (longlong *)*plVar7;
          bVar4 = true;
        } while (plVar7 != plVar12);
      }
      ExReleaseFastMutex(plVar3 + 0x17);
      if (!bVar4) {
        FUN_000121dc();
        goto LAB_00013fab;
      }
      FUN_000121dc();
      local_88[0] = 0;
      *(undefined1 *)((ulonglong)*(byte *)(param_2 + 10) * 0x268 + 0xfdc + (longlong)plVar3) = 0;
      WdmlibIoCreateDeviceSecure
                (*(undefined8 *)(*plVar3 + 8),0x218,0,0x22,0x80,0,&DAT_00035780,&DAT_00035f90,
                 &local_80);
      lVar13 = local_80;
      iVar6 = FUN_000121dc();
      if (iVar6 < 0) {
        FUN_000121dc();
      }
      uVar8 = FUN_00013050((longlong)param_1,param_2,iVar6 < 0,local_80,
                           CONCAT71((int7)((ulonglong)lVar13 >> 8),1),local_88);
      if (((int)uVar8 != 0) && (FUN_000121dc(), local_80 != 0)) {
        IoDeleteDevice();
      }
      pcVar1 = (char *)((ulonglong)*(byte *)(param_2 + 10) * 0x268 + 0xfdc + (longlong)plVar3);
      *pcVar1 = *pcVar1 + '\x01';
      *(undefined1 *)(plVar3 + 0x1fa) = 0;
      *(undefined1 *)((ulonglong)*(byte *)(param_2 + 10) * 0x268 + 0x1014 + (longlong)plVar3) = 1;
      if (*(int *)((ulonglong)*(byte *)(param_2 + 10) * 0x268 + 0x1024 + (longlong)plVar3) == 0) {
        *(undefined1 *)((ulonglong)*(byte *)(param_2 + 10) * 0x268 + 0x101c + (longlong)plVar3) = 0;
      }
      else {
        *(undefined1 *)((ulonglong)*(byte *)(param_2 + 10) * 0x268 + 0x101c + (longlong)plVar3) = 1;
      }
      KeSetEvent(plVar3 + (ulonglong)*(byte *)(param_2 + 10) * 0x4d + 0x218,0,0);
      local_58 = 0x53;
      local_57 = 0;
      local_56 = 0x6e;
      local_55 = 0;
      local_54 = 0x6f;
      local_53 = 0;
      local_52 = 0x77;
      local_51 = 0;
      local_50 = 0x66;
      local_4f = 0;
      local_4e = 0x6c;
      local_4d = 0;
      local_4c = 0x61;
      local_4b = 0;
      local_4a = 0x6b;
      local_49 = 0;
      local_48 = 0x65;
      local_47 = 0;
      local_78 = 0x42;
      local_76 = 0x610065;
      local_72 = 0x62006e;
      local_6e = 0x61;
      local_6d = 0;
      local_6c = 'g';
      local_6b = 0;
      local_68 = 0x77006f006e0053;
      local_60 = 0x62;
      local_5f = 0;
      local_5e = 0x61;
      local_5d = 0;
      local_5c = 0x6c;
      local_5b = 0;
      local_5a = 0x6c;
      local_59 = 0;
      lVar13 = *(longlong *)(local_80 + 0x40);
      if ((0x11 < *(ushort *)(plVar3 + (ulonglong)*(byte *)(param_2 + 10) * 0x4d + 0x241)) &&
         (sVar5 = RtlCompareMemory(plVar3[(ulonglong)*(byte *)(param_2 + 10) * 0x4d + 0x242] + 2,
                                   &local_78,0xe), sVar5 == 0xe)) {
        uVar9 = 4;
        if ((short)plVar3[(ulonglong)*(byte *)(param_2 + 10) * 0x4d + 0x241] == 0x12) {
          uVar9 = 2;
        }
        *(undefined1 *)(lVar13 + 0x211) = uVar9;
      }
      if ((0x13 < *(ushort *)(plVar3 + (ulonglong)*(byte *)(param_2 + 10) * 0x4d + 0x241)) &&
         (sVar5 = RtlCompareMemory(plVar3[(ulonglong)*(byte *)(param_2 + 10) * 0x4d + 0x242] + 2,
                                   &local_68,0x10), sVar5 == 0x10)) {
        *(char *)(lVar13 + 0x211) =
             ((short)plVar3[(ulonglong)*(byte *)(param_2 + 10) * 0x4d + 0x241] != 0x14) + '\x03';
      }
      if ((0x15 < *(ushort *)(plVar3 + (ulonglong)*(byte *)(param_2 + 10) * 0x4d + 0x241)) &&
         (sVar5 = RtlCompareMemory(plVar3[(ulonglong)*(byte *)(param_2 + 10) * 0x4d + 0x242] + 2,
                                   &local_58,0x12), sVar5 == 0x12)) {
        uVar9 = 4;
        if ((short)plVar3[(ulonglong)*(byte *)(param_2 + 10) * 0x4d + 0x241] == 0x16) {
          uVar9 = 1;
        }
        *(undefined1 *)(lVar13 + 0x211) = uVar9;
      }
      if (*(char *)(lVar13 + 0x211) != '\0') {
        FUN_000121dc();
      }
      IoInvalidateDeviceRelations(plVar3[6],0);
      if ((char)plVar3[0x1fa] == '\0') {
        local_68 = 0xffffffffdc3cba00;
        FUN_000121dc();
        iVar6 = KeWaitForSingleObject(plVar3 + 0x1f1,0,0,0);
        if (iVar6 == 0) {
          FUN_00014794((longlong)param_1);
          FUN_000121dc();
          plVar3[(ulonglong)*(byte *)(param_2 + 10) * 0x4d + 0x210] = 0;
          *(undefined1 *)(plVar3 + (ulonglong)*(byte *)(param_2 + 10) * 0x4d + 0x212) = 2;
          *(undefined1 *)((ulonglong)*(byte *)(param_2 + 10) * 0x268 + 0x1091 + (longlong)plVar3) =
               2;
          goto LAB_00013f98;
        }
        cVar10 = '\0';
        if (iVar6 != 0x102) {
          FUN_000121dc();
          goto LAB_00013f98;
        }
        FUN_000121dc();
        local_76 = *(undefined4 *)(param_2 + 2);
        cVar10 = cVar10 + '\x01';
        local_72 = *(undefined4 *)(param_2 + 6);
        local_6e = *(undefined1 *)(param_2 + 10);
        local_78 = 0x20;
        local_6d = 0;
        local_6c = cVar10;
        FUN_0003b26c(param_1,(longlong)&local_78);
      }
      else {
LAB_00013f98:
        cVar10 = '\x01';
      }
      *(char *)(plVar3 + 0x1fa) = cVar10;
      goto LAB_00013fab;
    }
    FUN_00021370(iVar6);
  }
  else {
    FUN_00021370(iVar6);
  }
  FUN_000121dc();
LAB_00013fab:
  FUN_000121dc();
  FUN_00025050(local_40 ^ (ulonglong)auStackY_f8);
  return;
}



/* ===== FUNC FUN_00013ff0 @ 00013ff0 ===== */

undefined8 FUN_00013ff0(longlong param_1,undefined8 *param_2,undefined8 param_3,longlong param_4)

{
  char cVar1;
  undefined8 *puVar2;
  longlong lVar3;
  void *_Src;
  undefined8 uVar4;
  undefined8 uVar5;
  ushort uVar6;
  char cVar7;
  ulonglong uVar8;
  char local_res8 [8];
  ushort local_res10 [4];
  
  uVar5 = 0;
  local_res10[0] = 0;
  local_res8[0] = '\0';
  if (*(char *)(*(longlong *)(param_1 + 0x40) + 0x215) == '\0') {
    _Src = (void *)FUN_00014170(param_1,(longlong)param_2,local_res10);
    cVar7 = '\x01';
  }
  else {
    _Src = (void *)FUN_0001430c(param_1,(longlong)param_2,param_3,local_res8,local_res10);
    cVar7 = local_res8[0];
  }
  if (_Src == (void *)0x0) {
    uVar5 = 0xc000000e;
  }
  else {
    cVar1 = *(char *)((longlong)_Src + 5);
    if ((((cVar1 == '\0') || (cVar1 == '\x01')) || (cVar1 == '\a')) ||
       (((cVar1 == '\b' || (cVar1 == -1)) || ((cVar1 == '\x06' || (cVar1 == '\x03')))))) {
      *(char *)(param_4 + 0x1f1) = cVar1;
      *(undefined1 *)(param_4 + 0x1f2) = *(undefined1 *)((longlong)_Src + 6);
      uVar6 = local_res10[0] + 9;
      uVar8 = (ulonglong)uVar6;
      *(undefined1 *)(param_4 + 499) = *(undefined1 *)((longlong)_Src + 7);
      uVar4 = ExAllocatePoolWithTag(0,uVar8,0x53747345);
      *(undefined8 *)(param_4 + 0x88 + (ulonglong)*(byte *)(param_4 + 0x108) * 8) = uVar4;
      if (*(longlong *)(param_4 + 0x88 + (ulonglong)*(byte *)(param_4 + 0x108) * 8) == 0) {
        uVar5 = 0xc000009a;
      }
      else {
        FUN_000251f0(*(ulonglong **)(param_4 + 0x88 + (ulonglong)*(byte *)(param_4 + 0x108) * 8),0,
                     uVar8);
        puVar2 = *(undefined8 **)(param_4 + 0x88 + (ulonglong)*(byte *)(param_4 + 0x108) * 8);
        *puVar2 = *param_2;
        *(undefined1 *)(puVar2 + 1) = *(undefined1 *)(param_2 + 1);
        memcpy((void *)(*(longlong *)(param_4 + 0x88 + (ulonglong)*(byte *)(param_4 + 0x108) * 8) +
                       9),_Src,uVar8 - 9);
        lVar3 = *(longlong *)(param_4 + 0x88 + (ulonglong)*(byte *)(param_4 + 0x108) * 8);
        *(char *)(lVar3 + 4) = cVar7;
        *(ushort *)(lVar3 + 2) = uVar6;
      }
    }
    else {
      uVar5 = 0xc00000bb;
    }
  }
  return uVar5;
}



/* ===== FUNC FUN_00014170 @ 00014170 ===== */

longlong FUN_00014170(undefined8 param_1,longlong param_2,ushort *param_3)

{
  ushort uVar1;
  longlong lVar2;
  longlong lVar3;
  int iVar4;
  
  FUN_000121dc();
  lVar2 = USBD_ParseConfigurationDescriptorEx
                    (param_2,param_2,0xffffffff,0xffffffff,7,0xffffffff,0xffffffff);
  if (lVar2 == 0) {
    uVar1 = FUN_000121dc();
    *param_3 = *param_3 & uVar1;
  }
  else {
    iVar4 = 1;
    *param_3 = (ushort)*(byte *)(lVar2 + 4) * 7 + 9;
    while( true ) {
      lVar3 = USBD_ParseConfigurationDescriptorEx
                        (param_2,(ulonglong)*param_3 + param_2,*(undefined1 *)(lVar2 + 2),iVar4,
                         *(undefined1 *)(lVar2 + 5),0xffffffff,0xffffffff);
      if (lVar3 == 0) break;
      *param_3 = *param_3 + (ushort)*(byte *)(lVar3 + 4) * 7 + 9;
      iVar4 = iVar4 + 1;
    }
  }
  return lVar2;
}



/* ===== FUNC FUN_00014268 @ 00014268 ===== */

short FUN_00014268(undefined8 param_1,longlong param_2,longlong param_3)

{
  short sVar1;
  short sVar2;
  longlong lVar3;
  longlong lVar4;
  int iVar5;
  
  lVar4 = (ulonglong)*(ushort *)(param_2 + 2) + param_2;
  iVar5 = 1;
  sVar1 = USBD_GetInterfaceLength(param_3,lVar4);
  if (*(char *)(param_3 + 5) == '\x03') {
    sVar1 = sVar1 + 9;
  }
  while( true ) {
    lVar3 = USBD_ParseConfigurationDescriptorEx
                      (param_2,param_2,*(undefined1 *)(param_3 + 2),iVar5,0xffffffff,0xffffffff,
                       0xffffffff);
    if (lVar3 == 0) break;
    sVar2 = USBD_GetInterfaceLength(lVar3,lVar4);
    sVar1 = sVar1 + sVar2;
    iVar5 = iVar5 + 1;
  }
  return sVar1;
}



/* ===== FUNC FUN_0001430c @ 0001430c ===== */

longlong FUN_0001430c(undefined8 param_1,longlong param_2,undefined8 param_3,char *param_4,
                     ushort *param_5)

{
  ushort uVar1;
  short sVar2;
  undefined4 uVar3;
  longlong lVar4;
  longlong lVar5;
  char cVar6;
  char *pcVar7;
  
  pcVar7 = param_4;
  uVar3 = FUN_000121dc();
  *pcVar7 = '\0';
  lVar4 = USBD_ParseConfigurationDescriptorEx
                    (param_2,param_2,uVar3,0xffffffff,0xffffffff,0xffffffff,0xffffffff);
  if (lVar4 == 0) {
    uVar1 = FUN_000121dc();
    *param_5 = *param_5 & uVar1;
  }
  else if (*(char *)(lVar4 + 5) == '\x01') {
    cVar6 = *(char *)(lVar4 + 2);
    uVar1 = FUN_00014268(param_1,param_2,lVar4);
    *param_4 = '\x01';
    while( true ) {
      cVar6 = cVar6 + '\x01';
      lVar5 = USBD_ParseConfigurationDescriptorEx
                        (param_2,param_2,cVar6,0xffffffff,1,0xffffffff,0xffffffff);
      if (lVar5 == 0) break;
      sVar2 = FUN_00014268(param_1,param_2,lVar5);
      *param_4 = *param_4 + '\x01';
      uVar1 = uVar1 + sVar2;
    }
    *param_5 = uVar1;
  }
  else {
    *param_4 = '\x01';
    uVar1 = FUN_00014268(param_1,param_2,lVar4);
    *param_5 = uVar1;
  }
  return lVar4;
}



/* ===== FUNC FUN_00014458 @ 00014458 ===== */

undefined4 FUN_00014458(longlong param_1,longlong param_2)

{
  longlong *plVar1;
  int iVar2;
  undefined4 uVar3;
  longlong *plVar4;
  
  plVar1 = *(longlong **)(param_1 + 0x40);
  iVar2 = *(int *)((longlong)plVar1 + 0xc);
  *(undefined4 *)((longlong)plVar1 + 0xc) = 6;
  *(int *)(plVar1 + 2) = iVar2;
  if (iVar2 != 5) {
    *(undefined4 *)((longlong)plVar1 + 0x8c) = 2;
    FUN_00011958(param_1,plVar1);
    iVar2 = IoSetDeviceInterfaceState(plVar1 + 9,0);
    if (iVar2 < 0) {
      FUN_000121dc();
    }
    iVar2 = IoSetDeviceInterfaceState(plVar1 + 0xb,0);
    if (iVar2 < 0) {
      FUN_000121dc();
    }
    iVar2 = IoSetDeviceInterfaceState(plVar1 + 0xd,0);
    if (iVar2 < 0) {
      FUN_000121dc();
    }
    FUN_00011bb8(param_1);
    uVar3 = 2;
    FUN_000121dc();
    IoWMIRegistrationControl(*plVar1,uVar3);
  }
  for (plVar4 = (longlong *)plVar1[0x14]; plVar4 != plVar1 + 0x14; plVar4 = (longlong *)*plVar4) {
    *(undefined1 *)(plVar4 + 2) = 1;
  }
  FUN_0001216c(param_1,(longlong)plVar1);
  FUN_0001216c(param_1,(longlong)plVar1);
  KeWaitForSingleObject(plVar1 + 0x1f,0,0,0,0);
  *(undefined4 *)(param_2 + 0x30) = 0;
  *(char *)(param_2 + 0x43) = *(char *)(param_2 + 0x43) + '\x01';
  *(longlong *)(param_2 + 0xb8) = *(longlong *)(param_2 + 0xb8) + 0x48;
  uVar3 = IofCallDriver(plVar1[7],param_2);
  ExDeleteNPagedLookasideList(plVar1 + 0x3f0);
  IoDetachDevice(plVar1[7]);
  RtlFreeUnicodeString(plVar1 + 9);
  RtlFreeUnicodeString(plVar1 + 0xb);
  RtlFreeUnicodeString(plVar1 + 0xd);
  IoDeleteDevice(*plVar1);
  return uVar3;
}



/* ===== FUNC FUN_000145ec @ 000145ec ===== */

void FUN_000145ec(longlong param_1,char param_2,undefined1 param_3,undefined1 param_4)

{
  longlong lVar1;
  longlong lVar2;
  longlong lVar3;
  undefined8 uVar4;
  longlong lVar5;
  undefined1 local_58 [16];
  undefined2 local_48;
  undefined1 local_46;
  undefined1 local_45;
  undefined1 local_44;
  
  lVar1 = *(longlong *)(param_1 + 0x40);
  local_45 = param_4;
  FUN_000121dc();
  local_48 = 0;
  local_44 = 0;
  local_46 = param_3;
  while( true ) {
    lVar2 = IoCsqRemoveNextIrp(lVar1 + 0x218,local_58);
    if (lVar2 == 0) break;
    lVar3 = FUN_000121dc();
    if (*(longlong *)(lVar3 + 0x88) != 0) {
      uVar4 = FUN_000121c8();
      ExFreePoolWithTag(uVar4,0x53747345);
    }
    lVar3 = *(longlong *)(*(longlong *)(lVar2 + 0xb8) + 8);
    *(undefined4 *)(lVar3 + 0x24) = 0;
    if (*(short *)(lVar3 + 2) == 9) {
      lVar5 = FUN_000121dc();
      *(char *)(lVar5 + 0x1c) = *(char *)(lVar5 + 0x1c) + -1;
    }
    if (param_2 == '\0') {
      *(undefined4 *)(lVar3 + 4) = 0xc0007000;
      *(undefined4 *)(lVar2 + 0x30) = 0xc000009d;
    }
    else {
      *(undefined4 *)(lVar3 + 4) = 0xc0010000;
      *(undefined4 *)(lVar2 + 0x30) = 0xc0000120;
    }
    FUN_000121dc();
    FUN_00017594(lVar2,*(int *)(lVar2 + 0x30));
  }
  FUN_000121dc();
  return;
}



/* ===== FUNC FUN_00014778 @ 00014778 ===== */

void FUN_00014778(longlong param_1)

{
  if (param_1 != 0) {
    ExFreePoolWithTag(param_1,0);
  }
  return;
}



/* ===== FUNC FUN_00014794 @ 00014794 ===== */

void FUN_00014794(longlong param_1)

{
  longlong lVar1;
  int iVar2;
  STRSAFE_PCNZWCH pwVar3;
  byte bVar4;
  undefined8 local_res8;
  undefined1 local_res18 [8];
  undefined1 local_48 [8];
  undefined8 local_40;
  undefined1 local_38 [8];
  undefined8 local_30;
  
  lVar1 = *(longlong *)(param_1 + 0x40);
  FUN_000121dc();
  if (*(char *)(lVar1 + 0x88) == '\0') {
    pwVar3 = (STRSAFE_PCNZWCH)ExAllocatePoolWithTag(0,0x1e,0x33747345);
    if (pwVar3 != (STRSAFE_PCNZWCH)0x0) {
      bVar4 = 0;
      do {
        FUN_000122b0(pwVar3,0x1e,L"\\GLOBAL??\\HCD%d",(ulonglong)bVar4);
        RtlInitUnicodeString(local_48,pwVar3);
        iVar2 = IoGetDeviceObjectPointer(local_48,1,&local_res8,local_res18);
        FUN_00021370(iVar2);
        FUN_000121dc();
        if (iVar2 == 0) {
          FUN_000121dc();
          ObfDereferenceObject(local_res8);
          if (bVar4 == 9) {
            ExFreePoolWithTag(local_40,0x33747345);
          }
        }
        else {
          if (iVar2 == -0x3ffffff2) {
            iVar2 = IoDeleteSymbolicLink(local_48);
            FUN_00021370(iVar2);
            FUN_000121dc();
          }
          RtlInitUnicodeString(lVar1 + 0x78,pwVar3);
          pwVar3 = (STRSAFE_PCNZWCH)ExAllocatePoolWithTag(0,0x34,0x33747345);
          if (pwVar3 == (STRSAFE_PCNZWCH)0x0) {
            ExFreePoolWithTag(*(undefined8 *)(lVar1 + 0x80),0x33747345);
            return;
          }
          FUN_000122b0(pwVar3,0x34,L"\\Device\\Generic_%08X",(ulonglong)*(uint *)(lVar1 + 0x20));
          RtlInitUnicodeString(local_38,pwVar3);
          iVar2 = IoCreateSymbolicLink(lVar1 + 0x78,local_38);
          FUN_00021370(iVar2);
          FUN_000121dc();
          ExFreePoolWithTag(local_30,0x33747345);
          if (-1 < iVar2) {
            *(char *)(lVar1 + 0x88) = *(char *)(lVar1 + 0x88) + '\x01';
            FUN_000121dc();
            return;
          }
        }
        bVar4 = bVar4 + 1;
      } while (bVar4 < 10);
    }
  }
  else {
    FUN_000121dc();
    *(char *)(lVar1 + 0x88) = *(char *)(lVar1 + 0x88) + '\x01';
  }
  return;
}



/* ===== FUNC FUN_00014a38 @ 00014a38 ===== */

void FUN_00014a38(longlong param_1)

{
  longlong lVar1;
  char cVar2;
  int iVar3;
  
  lVar1 = *(longlong *)(param_1 + 0x40);
  FUN_000121dc();
  if ((*(char *)(lVar1 + 0x88) != '\0') &&
     (cVar2 = *(char *)(lVar1 + 0x88) + -1, *(char *)(lVar1 + 0x88) = cVar2, cVar2 == '\0')) {
    iVar3 = IoDeleteSymbolicLink(lVar1 + 0x78);
    FUN_00021370(iVar3);
    FUN_000121dc();
    ExFreePoolWithTag(*(undefined8 *)(lVar1 + 0x80),0x33747345);
  }
  return;
}



/* ===== FUNC FUN_00014adc @ 00014adc ===== */

int FUN_00014adc(undefined8 param_1,uint param_2,ushort param_3,ulonglong param_4)

{
  int iVar1;
  int iVar2;
  ulonglong uVar3;
  
  uVar3 = param_4;
  FUN_000121dc();
  iVar1 = FUN_0003cbb8(uVar3);
  FUN_00021370(iVar1);
  iVar2 = 2;
  FUN_000121dc();
  if (iVar1 == 0) {
    iVar1 = FUN_0003d4f0(param_1,*(longlong *)(param_4 + 0x20),(ulonglong)(iVar2 - 1),FUN_00024c10,
                         param_4);
    FUN_00021370(iVar1);
    FUN_000121dc();
    if (iVar1 == 0) {
      iVar1 = FUN_0003d080(*(undefined8 *)(param_4 + 0x28),
                           param_2 >> 0x18 | (param_2 & 0xff0000) >> 8 | (param_2 & 0xff00) << 8 |
                           param_2 << 0x18,param_3 >> 8 | param_3 << 8);
      FUN_00021370(iVar1);
      FUN_000121dc();
      if (iVar1 == 0) {
        return 0;
      }
    }
    FUN_0003ce20(param_4);
  }
  return iVar1;
}



/* ===== FUNC FUN_00014bec @ 00014bec ===== */

int FUN_00014bec(undefined8 param_1,longlong param_2)

{
  longlong lVar1;
  longlong lVar2;
  int iVar3;
  undefined8 uVar4;
  longlong lVar5;
  undefined8 local_res10;
  int local_78 [4];
  undefined1 local_68 [24];
  undefined4 local_50 [2];
  ulonglong local_48 [6];
  
  iVar3 = 2;
  FUN_000121dc();
  lVar1 = *(longlong *)(param_2 + 0x28);
  local_78[0] = 0;
  local_50[0] = 0;
  local_78[1] = 0;
  local_78[2] = 0;
  local_78[3] = 0;
  FUN_000251f0(local_48,0,(ulonglong)(iVar3 + 0x26));
  local_res10 = 0;
  KeInitializeEvent(local_68,0,0);
  if (lVar1 == 0) {
    iVar3 = 0;
  }
  else {
    uVar4 = IoGetRelatedDeviceObject(lVar1);
    lVar5 = IoBuildDeviceIoControlRequest(3,uVar4,0,0,0,0,1,local_68,local_78);
    iVar3 = -0x3fffff66;
    if (lVar5 != 0) {
      local_res10 = 0xffffffff94b62e00;
      lVar2 = *(longlong *)(lVar5 + 0xb8);
      *(undefined8 *)(lVar2 + -0x10) = 0;
      *(undefined8 *)(lVar2 + -8) = 0;
      *(undefined1 *)(lVar2 + -0x45) = 0;
      lVar5 = *(longlong *)(lVar5 + 0xb8);
      *(undefined1 *)(lVar5 + -0x48) = 0xf;
      *(undefined1 *)(lVar5 + -0x47) = 6;
      *(undefined8 *)(lVar5 + -0x20) = uVar4;
      *(longlong *)(lVar5 + -0x18) = lVar1;
      *(undefined8 *)(lVar5 + -0x38) = 0;
      *(undefined4 **)(lVar5 + -0x30) = local_50;
      *(undefined8 *)(lVar5 + -0x40) = 2;
      *(undefined8 **)(lVar5 + -0x28) = &local_res10;
      iVar3 = IofCallDriver(uVar4);
      if (iVar3 == 0x103) {
        KeWaitForSingleObject(local_68,0,0,0,0);
        iVar3 = local_78[0];
      }
    }
  }
  FUN_00021370(iVar3);
  FUN_000121dc();
  if ((iVar3 == 0) || (iVar3 == -0x3ffffdc6)) {
    FUN_000121dc();
    FUN_0003ce20(param_2);
  }
  return iVar3;
}



/* ===== FUNC FUN_00014db0 @ 00014db0 ===== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00014db0(longlong param_1,byte param_2,char param_3)

{
  int *piVar1;
  longlong lVar2;
  int iVar3;
  longlong lVar4;
  ulonglong uVar5;
  undefined1 auStackY_f8 [32];
  uint local_c8 [2];
  undefined8 local_c0;
  undefined1 local_b8 [8];
  undefined8 uStack_b0;
  undefined4 local_a8;
  undefined2 local_a4;
  byte local_a2;
  char local_a1;
  short local_a0;
  byte local_9e;
  byte local_98;
  undefined1 local_88 [64];
  undefined4 local_48;
  ulonglong local_38;
  
  local_38 = DAT_00037100 ^ (ulonglong)auStackY_f8;
  lVar2 = *(longlong *)(param_1 + 0x40);
  uVar5 = (ulonglong)param_2;
  local_b8 = (undefined1  [8])((ulonglong)local_b8 & 0xffffffffffffff00);
  FUN_000251f0((ulonglong *)(local_b8 + 1),0,0x73);
  local_c8[0] = 0;
  FUN_000121dc();
  if (*(longlong *)(lVar2 + 0x1e70 + uVar5 * 0x30) != 0) {
    local_a8 = 0x24544e55;
    local_b8 = (undefined1  [8])_DAT_00035ec0;
    uStack_b0 = _UNK_00035ec8;
    do {
      LOCK();
      piVar1 = (int *)(lVar2 + 0x210);
      iVar3 = *piVar1;
      *piVar1 = *piVar1 + 1;
      UNLOCK();
      local_a0 = (short)iVar3 + 1;
    } while (local_a0 == 0);
    local_9e = local_9e | 0x80;
    local_a4 = 0x4400;
    local_a2 = param_2;
    local_a1 = param_3;
    memcpy(local_88,&DAT_00037830,(ulonglong)DAT_0003782c);
    lVar4 = uVar5 * 0x268;
    local_48 = *(undefined4 *)(lVar2 + 0x1094 + lVar4);
    *(undefined1 *)(lVar2 + 0x1010 + lVar4) = 0xff;
    local_98 = param_2;
    iVar3 = FUN_0003d284(param_1,param_2,*(longlong *)(lVar2 + 0x1e70 + uVar5 * 0x30),local_b8,0x74,
                         local_c8);
    if ((iVar3 == 0) && (local_c8[0] == 0x74)) {
      local_c0 = 0xfffffffffd050f80;
      KeWaitForSingleObject(lVar2 + 0xff8 + lVar4,0,0,0);
      iVar3 = FUN_000121dc();
      if ((iVar3 == 0) && (*(char *)(lVar2 + 0x1010 + lVar4) == '\0')) goto LAB_00014f6a;
    }
    if ((param_3 == '\n') || (param_3 == '\x1c')) {
      FUN_00014bec(param_1,lVar2 + 0x1e48 + uVar5 * 0x30);
    }
  }
LAB_00014f6a:
  FUN_00025050(local_38 ^ (ulonglong)auStackY_f8);
  return;
}



/* ===== FUNC FUN_00014fa0 @ 00014fa0 ===== */

int FUN_00014fa0(longlong param_1,byte param_2)

{
  longlong lVar1;
  int iVar2;
  longlong lVar3;
  longlong lVar4;
  
  lVar1 = *(longlong *)(param_1 + 0x40);
  FUN_000121dc();
  lVar3 = ExAllocatePoolWithTag(1,0x800,0x38747345);
  if (lVar3 == 0) {
    iVar2 = -0x3fffff66;
  }
  else {
    iVar2 = FUN_00024d00(param_1,*(undefined8 *)(lVar1 + 0x1e70 + (ulonglong)param_2 * 0x30));
    if (iVar2 == 0) {
      lVar4 = (ulonglong)param_2 * 0x268;
      *(undefined8 *)(lVar4 + 0x1092 + lVar1) = *(undefined8 *)(lVar3 + 0xc);
      *(undefined4 *)(lVar4 + 0x109a + lVar1) = *(undefined4 *)(lVar3 + 0x14);
      *(undefined2 *)(lVar4 + 0x109e + lVar1) = *(undefined2 *)(lVar3 + 0x18);
    }
    ExFreePoolWithTag(lVar3,0x38747345);
  }
  return iVar2;
}



/* ===== FUNC FUN_00015094 @ 00015094 ===== */

undefined4 FUN_00015094(longlong param_1,longlong param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined8 *puVar3;
  int iVar4;
  longlong lVar5;
  
  lVar5 = *(longlong *)(param_2 + 0xb8);
  puVar3 = *(undefined8 **)(param_1 + 0x40);
  iVar1 = *(int *)(lVar5 + 0x18);
  iVar4 = *(int *)(lVar5 + 0x10);
  FUN_000157f4(*(int *)((longlong)puVar3 + 0x1c));
  FUN_00015780(*(int *)(puVar3 + 3));
  FUN_000121dc();
  if (*(char *)(lVar5 + 1) == '\x02') {
    if (iVar4 == 0) {
      FUN_00015780(iVar1);
    }
    else {
      FUN_000157f4(iVar1);
    }
    FUN_000121dc();
    if (iVar4 == 0) {
      *(int *)(puVar3 + 3) = iVar1;
    }
    else {
      if (iVar4 != 1) goto LAB_000151b6;
      PoSetPowerState(*puVar3,1,iVar1);
      *(int *)((longlong)puVar3 + 0x1c) = iVar1;
    }
  }
  else if (*(char *)(lVar5 + 1) != '\x03') goto LAB_000151b6;
  *(undefined4 *)(param_2 + 0x30) = 0;
LAB_000151b6:
  PoStartNextPowerIrp(param_2);
  uVar2 = *(undefined4 *)(param_2 + 0x30);
  IofCompleteRequest(param_2,0);
  return uVar2;
}



/* ===== FUNC FUN_000151ec @ 000151ec ===== */

undefined8 FUN_000151ec(longlong param_1)

{
  longlong lVar1;
  longlong lVar2;
  undefined8 uVar3;
  longlong lVar4;
  
  lVar1 = *(longlong *)(param_1 + 0x40);
  lVar4 = param_1;
  lVar2 = FUN_000121dc();
  if (*(int *)(lVar2 + 0x30) < 0) {
    PoStartNextPowerIrp();
    FUN_0001216c(param_1,lVar1);
    uVar3 = 0;
  }
  else {
    FUN_00015250(lVar2,lVar4);
    uVar3 = 0xc0000016;
  }
  return uVar3;
}



/* ===== FUNC FUN_00015250 @ 00015250 ===== */

void FUN_00015250(longlong param_1,longlong param_2)

{
  longlong lVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  longlong lVar8;
  longlong lVar9;
  
  lVar9 = *(longlong *)(param_1 + 0xb8);
  lVar1 = *(longlong *)(param_2 + 0x40);
  iVar2 = 2;
  FUN_000121dc();
  lVar8 = (longlong)*(int *)(lVar9 + 0x18);
  FUN_000121dc();
  uVar6 = iVar2 - 1;
  uVar7 = (uint)lVar8;
  uVar4 = uVar6;
  if (uVar7 != uVar6) {
    uVar5 = iVar2 + 2;
    if (*(uint *)(lVar1 + 0x1d4) == uVar5) {
      if (((int)uVar5 < (int)uVar7) || ((int)uVar7 <= *(int *)(lVar1 + 0x1b0))) {
        uVar4 = uVar5;
        if (*(int *)(lVar1 + 0x194 + lVar8 * 4) <= (int)uVar5) {
          do {
            if (uVar4 - uVar6 == 0) {
              uVar3 = *(uint *)(lVar1 + 0x188) >> 10;
LAB_00015312:
              if ((uVar3 & uVar6) != 0) goto LAB_0001532e;
            }
            else {
              uVar3 = (uVar4 - uVar6) - uVar6;
              if (uVar3 == 0) {
                uVar3 = *(uint *)(lVar1 + 0x188) >> 0xb;
                goto LAB_00015312;
              }
              if (uVar3 == uVar6) {
                uVar3 = *(uint *)(lVar1 + 0x188) >> 0xc;
                goto LAB_00015312;
              }
              if (uVar3 - uVar6 == uVar6) {
                uVar3 = *(uint *)(lVar1 + 0x188) >> 0xd;
                goto LAB_00015312;
              }
            }
            uVar4 = uVar4 - uVar6;
          } while (*(int *)(lVar1 + 0x194 + lVar8 * 4) <= (int)uVar4);
        }
        if ((int)uVar5 < (int)uVar7) goto LAB_0001532b;
      }
      iVar2 = -0x3fffffff;
      goto LAB_0001535b;
    }
LAB_0001532b:
    uVar4 = uVar5;
  }
LAB_0001532e:
  *(longlong *)(lVar1 + 0x1c8) = param_1;
  iVar2 = PoRequestPowerIrp(*(undefined8 *)(lVar1 + 0x30),*(undefined1 *)(lVar9 + 1),uVar4,
                            FUN_000153a0,lVar1,0);
  if (-1 < iVar2) {
    return;
  }
LAB_0001535b:
  PoStartNextPowerIrp(param_1);
  *(int *)(param_1 + 0x30) = iVar2;
  IofCompleteRequest(param_1,0);
  FUN_0001216c(param_2,lVar1);
  return;
}



/* ===== FUNC FUN_000153a0 @ 000153a0 ===== */

void FUN_000153a0(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4,
                 undefined4 *param_5)

{
  longlong lVar1;
  
  lVar1 = *(longlong *)(param_4 + 0x1c8);
  FUN_000121dc();
  if (lVar1 != 0) {
    *(undefined4 *)(lVar1 + 0x30) = *param_5;
    PoStartNextPowerIrp(lVar1);
    IofCompleteRequest(lVar1,0);
    *(undefined8 *)(param_4 + 0x1c8) = 0;
    FUN_0001216c(param_1,param_4);
  }
  return;
}



/* ===== FUNC FUN_0001541c @ 0001541c ===== */

undefined8 FUN_0001541c(longlong param_1,longlong param_2)

{
  longlong lVar1;
  undefined8 uVar2;
  undefined4 uVar3;
  
  lVar1 = *(longlong *)(param_1 + 0x40);
  uVar3 = 2;
  FUN_000121dc();
  if (*(int *)(param_2 + 0x30) < 0) {
    PoStartNextPowerIrp(param_2);
    FUN_0001216c(param_1,lVar1);
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_00015548(param_1,param_2,uVar3,FUN_0003bfd8);
    if ((int)uVar2 != 0x103) {
      FUN_000154b4(param_1,param_2,2,(int)uVar2);
    }
    uVar2 = 0xc0000016;
  }
  return uVar2;
}



/* ===== FUNC FUN_000154b4 @ 000154b4 ===== */

int FUN_000154b4(longlong param_1,longlong param_2,undefined8 param_3,int param_4)

{
  longlong lVar1;
  int iVar2;
  int iVar3;
  
  lVar1 = *(longlong *)(param_1 + 0x40);
  iVar3 = 2;
  iVar2 = FUN_000121dc();
  if ((iVar2 == iVar3) || (param_4 < 0)) {
    PoStartNextPowerIrp(param_2);
    *(int *)(param_2 + 0x30) = param_4;
    IofCompleteRequest(param_2,0);
  }
  else {
    *(int *)(param_2 + 0x30) = param_4;
    param_4 = FUN_0003bc0c(param_1,param_2);
  }
  FUN_0001216c(param_1,lVar1);
  return param_4;
}



/* ===== FUNC FUN_00015548 @ 00015548 ===== */

undefined8 FUN_00015548(undefined8 param_1,longlong param_2,undefined4 param_3,undefined8 param_4)

{
  byte *pbVar1;
  undefined8 *puVar2;
  longlong lVar3;
  int iVar4;
  
  iVar4 = 2;
  FUN_000121dc();
  puVar2 = (undefined8 *)ExAllocatePoolWithTag(0,iVar4 + 0x26,0x53747345);
  if (puVar2 != (undefined8 *)0x0) {
    lVar3 = IoAllocateWorkItem(param_1);
    if (lVar3 != 0) {
      puVar2[1] = param_2;
      *puVar2 = param_1;
      *(undefined4 *)(puVar2 + 2) = param_3;
      puVar2[3] = param_4;
      puVar2[4] = lVar3;
      pbVar1 = (byte *)(*(longlong *)(param_2 + 0xb8) + 3);
      *pbVar1 = *pbVar1 | 1;
      IoQueueWorkItem(lVar3,FUN_0003bed4,1,puVar2);
      return 0x103;
    }
    ExFreePoolWithTag(puVar2,0);
  }
  return 0xc000009a;
}



/* ===== FUNC FUN_0001561c @ 0001561c ===== */

void FUN_0001561c(longlong param_1)

{
  longlong lVar1;
  int iVar2;
  uint uVar3;
  undefined8 *puVar4;
  
  lVar1 = *(longlong *)(param_1 + 0x40);
  FUN_000121dc();
  for (puVar4 = *(undefined8 **)(lVar1 + 0xa0); puVar4 != (undefined8 *)(lVar1 + 0xa0);
      puVar4 = (undefined8 *)*puVar4) {
    uVar3 = 1;
    FUN_000121dc();
    if (*(char *)((longlong)puVar4 + 0x11) == (char)uVar3) {
      FUN_000121dc();
      *(undefined1 *)((ulonglong)*(byte *)((longlong)puVar4 + -0x34) * 0x268 + 0x1014 + lVar1) = 0;
      *(undefined1 *)((ulonglong)*(byte *)((longlong)puVar4 + -0x34) * 0x268 + 0x101c + lVar1) = 0;
      iVar2 = FUN_0003d4f0(param_1,*(longlong *)
                                    (lVar1 + 0x1e68 +
                                    (ulonglong)*(byte *)((longlong)puVar4 + -0x34) * 0x30),
                           (ulonglong)uVar3,0,0);
      FUN_00021370(iVar2);
      FUN_000121dc();
      FUN_00014db0(param_1,*(byte *)((longlong)puVar4 + -0x34),'\x1e');
      *(undefined1 *)((longlong)puVar4 + 0x15) = 0;
      FUN_000120dc(0xfa);
    }
  }
  return;
}



/* ===== FUNC FUN_0001573c @ 0001573c ===== */

char * FUN_0001573c(char param_1)

{
  if (param_1 == '\0') {
    return "IRP_MN_WAIT_WAKE";
  }
  if (param_1 == '\x01') {
    return "IRP_MN_POWER_SEQUENCE";
  }
  if (param_1 == '\x02') {
    return "IRP_MN_SET_POWER";
  }
  if (param_1 == '\x03') {
    return "IRP_MN_QUERY_POWER";
  }
  return "unknown_power_irp";
}



/* ===== FUNC FUN_00015780 @ 00015780 ===== */

char * FUN_00015780(int param_1)

{
  if (param_1 == 0) {
    return "PowerSystemUnspecified";
  }
  if (param_1 == 1) {
    return "PowerSystemWorking";
  }
  if (param_1 == 2) {
    return "PowerSystemSleeping1";
  }
  if (param_1 == 3) {
    return "PowerSystemSleeping2";
  }
  if (param_1 == 4) {
    return "PowerSystemSleeping3";
  }
  if (param_1 == 5) {
    return "PowerSystemHibernate";
  }
  if (param_1 == 6) {
    return "PowerSystemShutdown";
  }
  if (param_1 == 7) {
    return "PowerSystemMaximum";
  }
  return "UnKnown System Power State";
}



/* ===== FUNC FUN_000157f4 @ 000157f4 ===== */

char * FUN_000157f4(int param_1)

{
  if (param_1 == 0) {
    return "PowerDeviceUnspecified";
  }
  if (param_1 == 1) {
    return "PowerDeviceD0";
  }
  if (param_1 == 2) {
    return "PowerDeviceD1";
  }
  if (param_1 == 3) {
    return "PowerDeviceD2";
  }
  if (param_1 == 4) {
    return "PowerDeviceD3";
  }
  if (param_1 == 5) {
    return "PowerDeviceMaximum";
  }
  return "UnKnown Device Power State";
}



/* ===== FUNC FUN_00015850 @ 00015850 ===== */

char * FUN_00015850(int param_1)

{
  if (param_1 == 0) {
    return "PowerActionNone";
  }
  if (param_1 == 2) {
    return "PowerActionSleep";
  }
  if (param_1 == 3) {
    return "PowerActionHibernate";
  }
  if (param_1 == 4) {
    return "PowerActionShutdown";
  }
  if (param_1 == 5) {
    return "PowerActionShutdownReset";
  }
  if (param_1 == 6) {
    return "PowerActionShutdownOff";
  }
  return "UnKnown System Power Action";
}



/* ===== FUNC FUN_000158ac @ 000158ac ===== */

void FUN_000158ac(undefined8 param_1)

{
  undefined8 uVar1;
  
  uVar1 = FUN_000121dc();
  WmiCompleteRequest(param_1,uVar1,0,0,0);
  return;
}



/* ===== FUNC FUN_000158ec @ 000158ec ===== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_000158ec(longlong param_1)

{
  uint uVar1;
  undefined8 uVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  int iVar5;
  undefined4 uVar6;
  ulonglong *puVar7;
  ushort *puVar8;
  undefined8 uVar9;
  uint uVar10;
  uint uVar11;
  longlong lVar12;
  undefined4 local_res8 [2];
  ushort local_48 [4];
  void *local_40;
  ushort local_38 [4];
  void *local_30;
  
  lVar12 = *(longlong *)(param_1 + 0x40);
  FUN_000121dc();
  RtlInitUnicodeString(local_38,L"Sonali");
  uVar2 = *(undefined8 *)(lVar12 + 0x30);
  local_res8[0] = 0;
  FUN_000121c8();
  uVar9 = 9;
  lVar12 = 2;
  do {
    iVar5 = IoGetDeviceProperty(uVar2,uVar9,0,0,local_res8);
    if (iVar5 != -0x3fffffdd) {
      uVar9 = 0;
    }
    lVar12 = lVar12 + -1;
  } while (lVar12 != 0);
  lVar12 = ExAllocatePoolWithTag(0,local_res8[0],0x39747345);
  if (lVar12 == 0) {
    iVar5 = -0x3fffff66;
  }
  else {
    iVar5 = IoGetDeviceProperty(uVar2,uVar9,local_res8[0],lVar12,local_res8);
    if (iVar5 < 0) {
      FUN_000121dc();
      ExFreePoolWithTag(lVar12,0);
    }
    else {
      RtlInitUnicodeString(local_48,lVar12);
      iVar5 = 0;
    }
  }
  if (-1 < iVar5) {
    uVar11 = (uint)local_48[0];
    uVar10 = (uint)local_38[0];
    uVar1 = uVar10 + uVar11 + 0x44;
    puVar7 = (ulonglong *)ExAllocatePoolWithTag(0,uVar1,0x39747345);
    iVar5 = -0x3fffff66;
    if (puVar7 != (ulonglong *)0x0) {
      FUN_000251f0(puVar7,0,(ulonglong)uVar1);
      *(uint *)puVar7 = uVar1;
      uVar6 = IoWMIDeviceObjectToProviderId(param_1);
      *(undefined4 *)(puVar7 + 1) = 1;
      *(undefined4 *)((longlong)puVar7 + 4) = uVar6;
      puVar7[2] = _DAT_fffff78000000014;
      uVar4 = _UNK_00035a78;
      uVar3 = _DAT_00035a70;
      *(undefined4 *)((longlong)puVar7 + 0x2c) = 10;
      *(undefined4 *)(puVar7 + 6) = 0x40;
      puVar7[3] = uVar3;
      puVar7[4] = uVar4;
      *(uint *)(puVar7 + 7) = uVar11 + 0x42;
      *(uint *)((longlong)puVar7 + 0x3c) = uVar10 + 2;
      *(ushort *)(puVar7 + 8) = local_48[0];
      memcpy((void *)((longlong)puVar7 + 0x42),local_40,(ulonglong)local_48[0]);
      puVar8 = (ushort *)((ulonglong)(uint)puVar7[7] + (longlong)puVar7);
      *puVar8 = local_38[0];
      memcpy(puVar8 + 1,local_30,(ulonglong)local_38[0]);
      iVar5 = IoWMIWriteEvent(puVar7);
      if (iVar5 < 0) {
        FUN_000121dc();
        ExFreePoolWithTag(puVar7,0);
      }
    }
    ExFreePoolWithTag(local_40,0);
  }
  return iVar5;
}



/* ===== FUNC FUN_00015b44 @ 00015b44 ===== */

char * FUN_00015b44(byte param_1)

{
  if (param_1 < 6) {
    if (param_1 == 5) {
      return "IRP_MN_DISABLE_EVENTS";
    }
    if (param_1 == 0) {
      return "IRP_MN_QUERY_ALL_DATA";
    }
    if (param_1 == 1) {
      return "IRP_MN_QUERY_SINGLE_INSTANCE";
    }
    if (param_1 == 2) {
      return "IRP_MN_CHANGE_SINGLE_INSTANCE";
    }
    if (param_1 == 3) {
      return "IRP_MN_CHANGE_SINGLE_ITEM";
    }
    if (param_1 == 4) {
      return "IRP_MN_ENABLE_EVENTS";
    }
  }
  else {
    if (param_1 == 6) {
      return "IRP_MN_ENABLE_COLLECTION";
    }
    if (param_1 == 7) {
      return "IRP_MN_DISABLE_COLLECTION";
    }
    if (param_1 == 8) {
      return "IRP_MN_REGINFO";
    }
    if (param_1 == 9) {
      return "IRP_MN_EXECUTE_METHOD";
    }
    if (param_1 == 0xb) {
      return "IRP_MN_REGINFO_EX";
    }
  }
  return "Unknown_SysControl_IRP";
}



/* ===== FUNC FUN_00015be8 @ 00015be8 ===== */

uint FUN_00015be8(longlong param_1)

{
  int *piVar1;
  int iVar2;
  
  FUN_000121dc();
  LOCK();
  piVar1 = (int *)(*(longlong *)(param_1 + 0x40) + 0x1d4);
  iVar2 = *piVar1;
  *piVar1 = 7;
  UNLOCK();
  return -(uint)(iVar2 != 4) & 0xc0000016;
}



/* ===== FUNC FUN_00015c2c @ 00015c2c ===== */

void FUN_00015c2c(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 *param_4,
                 int *param_5)

{
  int iVar1;
  code *pcVar2;
  undefined8 *puVar3;
  
  puVar3 = param_4;
  FUN_000121dc();
  puVar3[0x3b] = 0;
  *(undefined4 *)((longlong)puVar3 + 0x1d4) = 1;
  KeSetEvent(puVar3 + 0x3c,0,0);
  iVar1 = *param_5;
  if (iVar1 < 0) {
    if (((iVar1 != -0x3fffffff) && (iVar1 != -0x3ffffffe)) && (iVar1 != -0x3fffff45)) {
      return;
    }
    pcVar2 = FUN_0003c9dc;
  }
  else {
    pcVar2 = FUN_0003c990;
  }
  FUN_00015cc4(param_1,param_4,pcVar2);
  return;
}



/* ===== FUNC FUN_00015cc4 @ 00015cc4 ===== */

void FUN_00015cc4(undefined8 param_1,undefined8 *param_2,undefined *param_3)

{
  longlong lVar1;
  char cVar2;
  char in_CR8;
  
  cVar2 = '\x02';
  FUN_000121dc();
  if (in_CR8 == cVar2) {
    lVar1 = IoAllocateWorkItem(*param_2);
    if (lVar1 != 0) {
      IoQueueWorkItem(lVar1,param_3,1,lVar1);
    }
  }
  else {
    (*(code *)param_3)(*param_2,0);
  }
  return;
}



/* ===== FUNC FUN_00015d24 @ 00015d24 ===== */

void FUN_00015d24(byte param_1,byte *param_2,ushort param_3)

{
  byte bVar1;
  ushort uVar2;
  byte *pbVar3;
  longlong lVar4;
  byte *pbVar5;
  ushort uVar6;
  longlong lVar7;
  int iVar8;
  ushort uVar9;
  
  iVar8 = 0;
  lVar7 = 0;
  uVar9 = (ushort)(byte)(((((param_1 * '\x04' + (param_1 & 2)) * '\x04' + (param_1 & 4)) * '\x04' +
                          (param_1 & 8)) * '\x02' + (param_1 >> 1 & 8) + (param_1 >> 5 & 2) +
                         (param_1 >> 3 & 4)) - ((char)param_1 >> 7)) * 0x101;
  if (param_3 != 0) {
    pbVar3 = param_2;
    do {
      lVar4 = 2;
      uVar6 = ~uVar9;
      uVar2 = *(ushort *)(param_2 + lVar7);
      pbVar5 = pbVar3;
      do {
        bVar1 = *pbVar5;
        pbVar5 = pbVar5 + 1;
        uVar9 = *(ushort *)(&DAT_000375c0 + (ulonglong)(byte)(bVar1 ^ (byte)uVar9) * 2) ^ uVar9 >> 8
        ;
        lVar4 = lVar4 + -1;
      } while (lVar4 != 0);
      param_2[lVar7] = (byte)(uVar6 ^ uVar2);
      if (iVar8 + 1 < (int)(uint)param_3) {
        param_2[lVar7 + 1] = (byte)((uVar6 ^ uVar2) >> 8);
      }
      iVar8 = iVar8 + 2;
      pbVar3 = pbVar3 + 2;
      lVar7 = lVar7 + 2;
    } while (iVar8 < (int)(uint)param_3);
  }
  return;
}



/* ===== FUNC FUN_00015e28 @ 00015e28 ===== */

void FUN_00015e28(byte param_1,longlong param_2,ushort param_3,ushort param_4)

{
  ushort uVar1;
  ulonglong uVar2;
  ushort uVar3;
  
  uVar2 = 0;
  uVar3 = param_4;
  do {
    uVar1 = param_3;
    if (uVar3 <= param_3) {
      uVar1 = uVar3;
    }
    FUN_00015d24(param_1,(byte *)(uVar2 + param_2),uVar1);
    uVar1 = (short)uVar2 + param_3;
    uVar2 = (ulonglong)uVar1;
    uVar3 = uVar3 - param_3;
  } while (uVar1 < param_4);
  return;
}



/* ===== FUNC FUN_00015e9c @ 00015e9c ===== */

void FUN_00015e9c(byte param_1,byte *param_2,ushort param_3)

{
  byte bVar1;
  ushort uVar2;
  longlong lVar3;
  byte *pbVar4;
  longlong lVar5;
  byte *pbVar6;
  ushort uVar7;
  int iVar8;
  
  iVar8 = 0;
  lVar5 = 0;
  uVar7 = (ushort)(byte)(((((param_1 * '\x04' + (param_1 & 2)) * '\x04' + (param_1 & 4)) * '\x04' +
                          (param_1 & 8)) * '\x02' + (param_1 >> 1 & 8) + (param_1 >> 5 & 2) +
                         (param_1 >> 3 & 4)) - ((char)param_1 >> 7)) * 0x101;
  if (param_3 != 0) {
    pbVar6 = param_2;
    do {
      uVar2 = *(ushort *)(param_2 + lVar5);
      param_2[lVar5] = (byte)(~uVar7 ^ uVar2);
      if (iVar8 + 1 < (int)(uint)param_3) {
        param_2[lVar5 + 1] = (byte)((ushort)(~uVar7 ^ uVar2) >> 8);
      }
      lVar3 = 2;
      pbVar4 = pbVar6;
      do {
        bVar1 = *pbVar4;
        pbVar4 = pbVar4 + 1;
        uVar7 = *(ushort *)(&DAT_000375c0 + (ulonglong)(byte)(bVar1 ^ (byte)uVar7) * 2) ^ uVar7 >> 8
        ;
        lVar3 = lVar3 + -1;
      } while (lVar3 != 0);
      iVar8 = iVar8 + 2;
      pbVar6 = pbVar6 + 2;
      lVar5 = lVar5 + 2;
    } while (iVar8 < (int)(uint)param_3);
  }
  return;
}



/* ===== FUNC FUN_00015fd8 @ 00015fd8 ===== */

longlong * FUN_00015fd8(longlong param_1,longlong param_2,longlong param_3)

{
  longlong *plVar1;
  longlong *plVar2;
  longlong lVar3;
  longlong *plVar4;
  bool bVar5;
  
  plVar1 = (longlong *)(param_1 + 0x48);
  plVar4 = (longlong *)*plVar1;
  if (plVar4 == plVar1) {
    FUN_000121c8();
    return (longlong *)0x0;
  }
  if (param_2 != 0) {
    plVar4 = *(longlong **)(param_2 + 0xa8);
  }
  do {
    if (plVar4 == plVar1) {
      return (longlong *)0x0;
    }
    plVar2 = plVar4 + -0x15;
    if (param_3 == 0) {
      return plVar2;
    }
    lVar3 = plVar4[-4];
    if (lVar3 != 0) {
      if (*(short *)(param_3 + 0x10) == 0) {
        if (*(char *)(param_3 + 0x12) == *(char *)(lVar3 + 0x12)) {
          if (((*(byte *)(lVar3 + 0x13) ^ *(byte *)(param_3 + 0x13)) & 0x7f) == 0) {
            return plVar2;
          }
          if (*(char *)(param_3 + 0x12) == *(char *)(lVar3 + 0x12)) {
            bVar5 = *(char *)(param_3 + 0x13) == -1;
            goto LAB_000160a5;
          }
        }
      }
      else if (*(char *)(param_3 + 0x14) == '\b') {
        if ((*(char *)(param_3 + 0x12) == *(char *)(lVar3 + 0x12)) &&
           (((*(byte *)(lVar3 + 0x13) ^ *(byte *)(param_3 + 0x13)) & 0xf) == 0)) {
          bVar5 = *(char *)(lVar3 + 0x14) == '\b';
LAB_000160a5:
          if (bVar5) {
            return plVar2;
          }
        }
      }
      else if (((*(short *)(param_3 + 0x10) == *(short *)(lVar3 + 0x10)) &&
               (*(char *)(param_3 + 0x12) == *(char *)(lVar3 + 0x12))) &&
              (((*(byte *)(lVar3 + 0x13) ^ *(byte *)(param_3 + 0x13)) & 0xf) == 0)) {
        bVar5 = *(char *)(param_3 + 0x14) == *(char *)(lVar3 + 0x14);
        goto LAB_000160a5;
      }
    }
    plVar4 = (longlong *)*plVar4;
  } while( true );
}



/* ===== FUNC FUN_000160c4 @ 000160c4 ===== */

void FUN_000160c4(longlong param_1,undefined1 *param_2)

{
  undefined1 uVar1;
  
  uVar1 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x40);
  *param_2 = uVar1;
  return;
}



/* ===== FUNC FUN_000160e8 @ 000160e8 ===== */

void FUN_000160e8(longlong param_1,longlong param_2)

{
  longlong lVar1;
  longlong lVar2;
  char *pcVar3;
  int iVar4;
  
  iVar4 = *(int *)(*(longlong *)(param_2 + 0xb8) + 0x18);
  pcVar3 = "+ CSQ_CompleteCanceledIrp(): IRP_0x%p \n";
  FUN_000121dc();
  lVar1 = *(longlong *)(param_2 + 0x88);
  if (iVar4 == 0x220003) {
    lVar2 = *(longlong *)(*(longlong *)(param_2 + 0xb8) + 8);
    *(undefined4 *)(lVar2 + 4) = 0xc0010000;
    if (*(short *)(lVar2 + 2) == 9) {
      *(undefined4 *)(lVar2 + 0x24) = 0;
      FUN_0001e010(*(undefined8 *)(param_1 + -0x218),(undefined8 *)(param_1 + -0x218),
                   CONCAT71((int7)((ulonglong)pcVar3 >> 8),*(undefined1 *)(lVar1 + 0x12)),
                   *(longlong *)(lVar2 + 0x18));
    }
  }
  *(undefined8 *)(param_2 + 0x38) = 0;
  *(undefined4 *)(param_2 + 0x30) = 0xc0000120;
  if (lVar1 != 0) {
    FUN_00021370(-0x3ffffee0);
    FUN_000121dc();
    ExFreePoolWithTag(lVar1,0x53747345);
  }
                    /* WARNING: Could not recover jumptable at 0x000161c5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  IofCompleteRequest(param_2,0);
  return;
}



/* ===== FUNC FUN_00016260 @ 00016260 ===== */

void FUN_00016260(longlong param_1,undefined1 *param_2)

{
  undefined1 uVar1;
  
  uVar1 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x8a0);
  *param_2 = uVar1;
  return;
}



/* ===== FUNC FUN_00016284 @ 00016284 ===== */

void FUN_00016284(longlong param_1,undefined1 *param_2)

{
  undefined1 uVar1;
  
  uVar1 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x7d8);
  *param_2 = uVar1;
  return;
}



/* ===== FUNC FUN_000162a8 @ 000162a8 ===== */

void FUN_000162a8(longlong param_1,undefined1 *param_2)

{
  undefined1 uVar1;
  
  uVar1 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x710);
  *param_2 = uVar1;
  return;
}



/* ===== FUNC FUN_000162cc @ 000162cc ===== */

void FUN_000162cc(longlong param_1,undefined1 *param_2)

{
  undefined1 uVar1;
  
  uVar1 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x648);
  *param_2 = uVar1;
  return;
}



/* ===== FUNC FUN_000162f0 @ 000162f0 ===== */

void FUN_000162f0(longlong param_1,undefined1 *param_2)

{
  undefined1 uVar1;
  
  uVar1 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x580);
  *param_2 = uVar1;
  return;
}



/* ===== FUNC FUN_00016314 @ 00016314 ===== */

void FUN_00016314(longlong param_1,undefined1 *param_2)

{
  undefined1 uVar1;
  
  uVar1 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x4b8);
  *param_2 = uVar1;
  return;
}



/* ===== FUNC FUN_000163b0 @ 000163b0 ===== */

void FUN_000163b0(undefined8 param_1,longlong param_2)

{
  short sVar1;
  longlong lVar2;
  undefined8 *puVar3;
  longlong lVar4;
  char *pcVar5;
  undefined1 local_res10;
  undefined7 uStackX_11;
  
  lVar4 = *(longlong *)(param_2 + 0x78);
  lVar2 = *(longlong *)(*(longlong *)(param_2 + 0xb8) + 8);
  puVar3 = *(undefined8 **)(*(longlong *)(lVar4 + 0x28) + 0x40);
  sVar1 = *(short *)(lVar2 + 2);
  FUN_000121dc();
  if (sVar1 == 9) {
    local_res10 = *(undefined1 *)(lVar4 + 0x24);
    lVar4 = *(longlong *)(lVar2 + 0x18);
  }
  else {
    lVar4 = CONCAT71(uStackX_11,local_res10);
  }
  *(undefined8 *)(param_2 + 0x38) = 0;
  *(undefined4 *)(param_2 + 0x30) = 0xc0000120;
  IofCompleteRequest(param_2,0);
  if (sVar1 == 9) {
    pcVar5 = "    CSQ_CompleteCanceledUsbIrp()  IRP_0x%p. pPipeInfo_0x%p. Send next IRP. \n";
    FUN_000121dc();
    FUN_0001e010(*puVar3,puVar3,CONCAT71((int7)((ulonglong)pcVar5 >> 8),local_res10),lVar4);
  }
  return;
}



/* ===== FUNC FUN_0001647c @ 0001647c ===== */

void FUN_0001647c(longlong param_1,longlong param_2)

{
  longlong *plVar1;
  char *pcVar2;
  longlong *plVar3;
  longlong lVar4;
  
  pcVar2 = *(char **)(param_2 + 0x80);
  lVar4 = param_1 + -0x58;
  if (pcVar2 == (char *)0x0) {
    return;
  }
  if (*pcVar2 == '\0') {
    if (pcVar2[8] == '\0') {
      FUN_000121c8();
    }
    else if (pcVar2[8] != '\x01') goto LAB_000164df;
    plVar3 = (longlong *)(param_2 + 0xa8);
    plVar1 = (longlong *)(lVar4 + 0xb8);
    lVar4 = *plVar1;
    *plVar3 = lVar4;
    *(longlong **)(param_2 + 0xb0) = plVar1;
    *(longlong **)(lVar4 + 8) = plVar3;
    *plVar1 = (longlong)plVar3;
  }
  else {
LAB_000164df:
    FUN_000121c8();
    plVar1 = (longlong *)(param_2 + 0xa8);
    plVar3 = *(longlong **)(lVar4 + 0xc0);
    *plVar1 = lVar4 + 0xb8;
    *(longlong **)(param_2 + 0xb0) = plVar3;
    *plVar3 = (longlong)plVar1;
    *(longlong **)(lVar4 + 0xc0) = plVar1;
  }
  return;
}



/* ===== FUNC FUN_00016584 @ 00016584 ===== */

void FUN_00016584(longlong param_1,undefined1 *param_2)

{
  undefined1 uVar1;
  
  uVar1 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x70);
  *param_2 = uVar1;
  return;
}



/* ===== FUNC FUN_000165dc @ 000165dc ===== */

void FUN_000165dc(undefined8 param_1,longlong param_2)

{
  longlong *plVar1;
  undefined8 *puVar2;
  longlong lVar3;
  longlong *plVar4;
  longlong lVar5;
  
  lVar5 = *(longlong *)(param_2 + 0x88);
  lVar3 = FUN_000121c8();
  if (lVar3 != 0x270) {
    plVar4 = (longlong *)(lVar3 + 0x48);
    plVar1 = (longlong *)(param_2 + 0xa8);
    if (*(char *)(lVar5 + 0x12) == '\0') {
      lVar5 = *plVar4;
      *(longlong **)(param_2 + 0xb0) = plVar4;
      *plVar1 = lVar5;
      *(longlong **)(lVar5 + 8) = plVar1;
      *plVar4 = (longlong)plVar1;
    }
    else {
      puVar2 = *(undefined8 **)(lVar3 + 0x50);
      *plVar1 = (longlong)plVar4;
      *(undefined8 **)(param_2 + 0xb0) = puVar2;
      *puVar2 = plVar1;
      *(longlong **)(lVar3 + 0x50) = plVar1;
    }
  }
  return;
}



/* ===== FUNC FUN_00016650 @ 00016650 ===== */

longlong * FUN_00016650(longlong param_1,longlong param_2,longlong param_3)

{
  longlong *plVar1;
  longlong lVar2;
  longlong *plVar3;
  longlong *plVar4;
  
  plVar1 = (longlong *)(param_1 + 0x48);
  plVar3 = (longlong *)*plVar1;
  if (plVar3 != plVar1) {
    if (param_2 != 0) {
      plVar3 = *(longlong **)(param_2 + 0xa8);
    }
    for (; plVar3 != plVar1; plVar3 = (longlong *)*plVar3) {
      plVar4 = plVar3 + -0x15;
      if (param_3 == 0) {
        FUN_000121c8();
        return plVar4;
      }
      lVar2 = plVar3[-4];
      if (((lVar2 != 0) && (*(char *)(param_3 + 0x10) == *(char *)(lVar2 + 0x10))) &&
         (*(char *)(param_3 + 0x11) == *(char *)(lVar2 + 0x11))) {
        return plVar4;
      }
    }
  }
  return (longlong *)0x0;
}



/* ===== FUNC FUN_000166e0 @ 000166e0 ===== */

void FUN_000166e0(undefined8 param_1,longlong param_2)

{
  if (*(longlong *)(param_2 + 0x88) != 0) {
    ExFreePoolWithTag(*(longlong *)(param_2 + 0x88),0x53747345);
  }
  *(undefined8 *)(param_2 + 0x38) = 0;
  *(undefined4 *)(param_2 + 0x30) = 0xc0000120;
                    /* WARNING: Could not recover jumptable at 0x00016716. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  IofCompleteRequest(param_2,0);
  return;
}



/* ===== FUNC FUN_00016784 @ 00016784 ===== */

void FUN_00016784(longlong param_1,undefined1 *param_2)

{
  undefined1 uVar1;
  
  uVar1 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x50);
  *param_2 = uVar1;
  return;
}



/* ===== FUNC FUN_000167bc @ 000167bc ===== */

void FUN_000167bc(undefined8 param_1,longlong param_2)

{
  char *pcVar1;
  longlong lVar2;
  
  if (param_2 != 0) {
    lVar2 = *(longlong *)(*(longlong *)(param_2 + 0xb8) + 8);
    if ((lVar2 != 0) && (*(int *)(*(longlong *)(param_2 + 0xb8) + 0x18) == 0x220003)) {
      pcVar1 = (char *)(*(longlong *)(lVar2 + 0x18) + 0x1c);
      *pcVar1 = *pcVar1 + -1;
    }
    *(undefined8 *)(param_2 + 0x38) = 0;
    *(undefined4 *)(param_2 + 0x30) = 0xc0000120;
    IofCompleteRequest(param_2,0);
  }
  return;
}



/* ===== FUNC FUN_0001680c @ 0001680c ===== */

int FUN_0001680c(longlong param_1,longlong param_2)

{
  ushort uVar1;
  longlong lVar2;
  longlong lVar3;
  longlong lVar4;
  int iVar5;
  undefined8 uVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  undefined4 *puVar10;
  uint uVar11;
  longlong lVar12;
  bool bVar13;
  
  lVar2 = *(longlong *)(param_2 + 0x78);
  lVar3 = *(longlong *)(param_1 + 0x40);
  lVar4 = *(longlong *)(*(longlong *)(param_2 + 0xb8) + 8);
  uVar11 = 0;
  lVar12 = 3;
  iVar5 = -0x3fffff45;
  FUN_000121dc();
  uVar1 = *(ushort *)(lVar4 + 2);
  if (0x28 < uVar1) {
    if (uVar1 != 0x32) goto LAB_00016921;
    iVar5 = 0x103;
    goto LAB_000169e8;
  }
  if (uVar1 != 0x28) {
    uVar7 = (uint)uVar1;
    if (uVar7 < 0x12) {
      if ((uVar7 != 0x11) && (uVar7 != 0)) {
        if (uVar1 == 1) {
          uVar6 = FUN_00018778(param_1,param_2);
          iVar5 = (int)uVar6;
        }
        else if (uVar1 == 2) {
          uVar6 = FUN_00016eb4(param_1,param_2);
          *(undefined4 *)(lVar4 + 4) = 0;
          *(longlong *)(lVar4 + 8) = lVar2;
          iVar5 = (int)uVar6;
        }
        else {
          if (uVar1 == 7) {
            lVar2 = *(longlong *)(param_1 + 0x40);
            lVar3 = *(longlong *)(*(longlong *)(param_2 + 0xb8) + 8);
            *(uint *)(lVar3 + 4) = *(uint *)(lVar3 + 4) & uVar11;
            *(uint *)(lVar3 + 0x18) = *(uint *)(lVar3 + 0x18) & uVar11;
            puVar10 = (undefined4 *)(lVar2 + 0x2f0);
            do {
              if (*(char *)(lVar3 + 0x22) == *(char *)((longlong)puVar10 + -0x26)) {
                *(undefined4 *)(lVar3 + 0x18) = *puVar10;
              }
              puVar10 = puVar10 + 0x12;
              lVar12 = lVar12 + -1;
            } while (lVar12 != 0);
            FUN_000121dc();
            goto LAB_0001691f;
          }
          if (uVar1 == 8) goto LAB_000168a9;
          if (uVar1 == 9) {
            uVar6 = FUN_00016f84(param_1,param_2);
            iVar5 = (int)uVar6;
          }
          else {
            if (uVar1 != 10) {
              if (uVar1 != 0xb) {
                bVar13 = uVar1 == 0x10;
                goto LAB_000168a7;
              }
              goto LAB_000168a9;
            }
            iVar5 = FUN_00018b94(param_1,param_2);
          }
        }
LAB_000169e8:
        if (iVar5 != 0x103) {
          if (iVar5 == -0x3fffffea) {
            return 0x103;
          }
LAB_00016921:
          FUN_00017594(param_2,iVar5);
          return iVar5;
        }
        goto LAB_000169f0;
      }
    }
    else if (((((uVar7 != 0x12) && (uVar7 != 0x13)) && (uVar7 != 0x17)) &&
             ((iVar8 = uVar7 - 0x18, iVar8 != 0 &&
              (iVar9 = iVar8 - (int)lVar12, iVar8 != (int)lVar12)))) && (iVar9 != 1)) {
      if (iVar9 == 3) {
        if ((*(byte *)(*(longlong *)(*(longlong *)(lVar4 + 0x18) + 0x10) + 3) & (byte)lVar12) == 1)
        {
          *(uint *)(lVar4 + 4) = *(uint *)(lVar4 + 4) & uVar11;
LAB_0001691f:
          iVar5 = 0;
          goto LAB_00016921;
        }
      }
      else if (iVar9 != 4) {
        bVar13 = iVar9 == 5;
LAB_000168a7:
        if (!bVar13) goto LAB_00016921;
      }
    }
  }
LAB_000168a9:
  iVar5 = 0x103;
LAB_000169f0:
  if (*(short *)(lVar4 + 2) != 10) {
    FUN_0001f9e0(param_1,param_2);
    KeSetEvent((ulonglong)*(byte *)(lVar2 + 0x24) * 0xd0 + 0x610 + lVar3,0,0);
  }
  if ((*(short *)(lVar4 + 2) == 0x1e) &&
     (*(char *)(*(longlong *)(*(longlong *)(lVar4 + 0x18) + 8) + 5) != '\b')) {
    FUN_000120dc(1000);
  }
  return iVar5;
}



/* ===== FUNC FUN_00016a70 @ 00016a70 ===== */

ulonglong FUN_00016a70(longlong param_1,longlong param_2)

{
  char cVar1;
  ushort uVar2;
  longlong lVar3;
  longlong lVar4;
  longlong lVar5;
  int iVar6;
  uint uVar7;
  ulonglong uVar8;
  int iVar9;
  ulonglong uVar10;
  bool bVar11;
  
  lVar3 = *(longlong *)(param_1 + 0x40);
  uVar8 = 0;
  lVar4 = *(longlong *)(*(longlong *)(param_2 + 0xb8) + 8);
  uVar10 = 0xc00000bb;
  FUN_000121dc();
  uVar2 = *(ushort *)(lVar4 + 2);
  if (uVar2 < 0x29) {
    if (uVar2 == 0x28) goto LAB_00016c0c;
    if (0x11 < uVar2) {
      if ((((uVar2 != 0x12) && (uVar2 != 0x13)) && (uVar2 != 0x17)) &&
         (((uVar2 != 0x18 && (uVar2 != 0x1b)) &&
          ((uVar2 != 0x1c && ((uVar2 != 0x1e && (uVar2 != 0x1f)))))))) {
        bVar11 = uVar2 == 0x20;
        goto LAB_00016c0a;
      }
      goto LAB_00016c0c;
    }
    if (uVar2 == 0x11) goto LAB_00016c0c;
    if (uVar2 == 0) {
      *(undefined8 *)(param_2 + 0x78) = *(undefined8 *)(param_1 + 0x40);
      uVar7 = FUN_00018db0(param_1,param_2);
    }
    else {
      iVar6 = (int)uVar8 + 1;
      if ((uint)uVar2 - iVar6 != 0) {
        iVar9 = ((uint)uVar2 - iVar6) - iVar6;
        if (((iVar9 != 0) && (iVar9 = iVar9 + -5, iVar9 != 0)) &&
           (iVar9 = iVar9 - iVar6, iVar9 != 0)) {
          iVar9 = iVar9 - iVar6;
          if (iVar9 == 0) {
            *(ulonglong *)(param_2 + 0x80) = *(ulonglong *)(param_2 + 0x80) & uVar8;
            *(longlong *)(param_2 + 0x78) = lVar3;
            uVar8 = FUN_00016f84(param_1,param_2);
            uVar10 = uVar8 & 0xffffffff;
            uVar7 = 0x103;
            if ((int)uVar8 == 0x103) {
              lVar5 = *(longlong *)(*(longlong *)(lVar3 + 0x28) + 0x40);
              FUN_0001f9e0(param_1,param_2);
              KeSetEvent((ulonglong)*(byte *)(lVar3 + 0x24) * 0xd0 + 0x610 + lVar5,0,0);
              goto LAB_00016c19;
            }
            if ((int)uVar8 != -0x3fffffea) goto LAB_00016c19;
            goto LAB_00016c17;
          }
          iVar9 = iVar9 - iVar6;
          if (iVar9 != 0) {
            if (iVar9 == iVar6) {
              cVar1 = *(char *)(lVar4 + 0x83);
              if ((cVar1 == '\x02') || (cVar1 == (char)iVar6)) {
                *(undefined8 *)(param_2 + 0x78) = *(undefined8 *)(param_1 + 0x40);
                uVar7 = FUN_0001c774(param_1,param_2);
                goto LAB_00016c17;
              }
              bVar11 = cVar1 == '\x03';
            }
            else {
              bVar11 = iVar9 - iVar6 == 5;
            }
            goto LAB_00016c0a;
          }
        }
        goto LAB_00016c0c;
      }
      uVar7 = FUN_00016d08(param_1,param_2);
    }
  }
  else {
    bVar11 = uVar2 == 0x32;
LAB_00016c0a:
    if (!bVar11) goto LAB_00016c19;
LAB_00016c0c:
    uVar7 = FUN_000123c0(param_1,param_2);
  }
LAB_00016c17:
  uVar10 = (ulonglong)uVar7;
LAB_00016c19:
  if (*(short *)(lVar4 + 2) == 0x2a) {
    uVar10 = 0xc0000010;
  }
  return uVar10;
}



/* ===== FUNC FUN_00016c48 @ 00016c48 ===== */

int FUN_00016c48(longlong param_1,longlong param_2,longlong param_3)

{
  longlong lVar1;
  int iVar2;
  undefined8 uVar3;
  undefined8 local_res10;
  
  FUN_000121dc();
  lVar1 = *(longlong *)(*(longlong *)(param_2 + 0xb8) + 8);
  iVar2 = -0x3fffffff;
  uVar3 = FUN_000175e4(*(short *)(lVar1 + 2),&local_res10);
  if ((char)uVar3 != '\0') {
    lVar1 = *(longlong *)(lVar1 + 0x18);
    if (lVar1 == 0) {
      local_res10._2_1_ = 0;
    }
    else {
      local_res10._2_1_ = *(undefined1 *)(lVar1 + 5);
    }
    FUN_000121dc();
    iVar2 = FUN_00018f58(param_1,param_2,&local_res10,param_3);
  }
  if (iVar2 == 0) {
    iVar2 = 0x103;
  }
  return iVar2;
}



/* ===== FUNC FUN_00016d08 @ 00016d08 ===== */

int FUN_00016d08(longlong param_1,longlong param_2)

{
  undefined1 uVar1;
  longlong lVar2;
  longlong lVar3;
  longlong lVar4;
  longlong lVar5;
  longlong *plVar6;
  int iVar7;
  undefined1 *puVar8;
  
  lVar2 = *(longlong *)(param_1 + 0x40);
  lVar3 = *(longlong *)(*(longlong *)(param_2 + 0xb8) + 8);
  lVar5 = *(longlong *)(lVar2 + 0x88 + (ulonglong)*(byte *)(lVar2 + 0x108) * 8);
  lVar4 = USBD_ParseConfigurationDescriptorEx
                    (lVar5,lVar5,*(undefined1 *)(lVar3 + 0x22),1,0xffffffff,0xffffffff,0xffffffff);
  if (lVar4 == 0) {
    lVar4 = USBD_ParseConfigurationDescriptorEx
                      (lVar5,lVar5,*(undefined1 *)(lVar3 + 0x22),*(undefined1 *)(lVar3 + 0x23),
                       0xffffffff,0xffffffff,0xffffffff);
    if (lVar4 != 0) {
      *(undefined1 *)(lVar3 + 0x24) = *(undefined1 *)(lVar4 + 5);
      *(undefined1 *)(lVar3 + 0x25) = *(undefined1 *)(lVar4 + 6);
      uVar1 = *(undefined1 *)(lVar4 + 7);
      *(longlong *)(lVar3 + 0x28) = lVar4;
      *(undefined1 *)(lVar3 + 0x26) = uVar1;
      if ((*(int *)(lVar3 + 0x30) == 0) && (*(char *)(lVar4 + 4) != '\0')) {
        *(uint *)(lVar3 + 0x30) = (uint)*(byte *)(lVar4 + 4);
      }
      lVar5 = USBD_ParseDescriptors(lVar5,*(undefined2 *)(lVar5 + 2),lVar4,5);
      if (lVar5 != 0) {
        if (*(char *)(lVar4 + 4) != '\0') {
          puVar8 = (undefined1 *)(lVar3 + 0x3b);
          iVar7 = 0;
          do {
            puVar8[-1] = *(undefined1 *)(lVar5 + 2);
            *(ushort *)(puVar8 + -3) = *(ushort *)(lVar5 + 4) & 0x7ff;
            plVar6 = FUN_0001c104(param_1,lVar2,lVar4,lVar5);
            *(longlong **)(puVar8 + 5) = plVar6;
            *puVar8 = *(undefined1 *)(lVar5 + 6);
            *(uint *)(puVar8 + 1) = *(byte *)(lVar5 + 3) & 3;
            FUN_000121dc();
            iVar7 = iVar7 + 1;
            lVar5 = lVar5 + 7;
            puVar8 = puVar8 + 0x18;
          } while (iVar7 < (int)(uint)*(byte *)(lVar4 + 4));
        }
        *(undefined4 *)(lVar3 + 4) = 0;
        FUN_00017594(param_2,0);
        return 0;
      }
    }
    *(undefined4 *)(lVar3 + 4) = 0xc0000f00;
    iVar7 = -0x3fffffff;
  }
  else {
    iVar7 = FUN_000123c0(param_1,param_2);
  }
  return iVar7;
}



/* ===== FUNC FUN_00016eb4 @ 00016eb4 ===== */

undefined8 FUN_00016eb4(longlong param_1,longlong param_2)

{
  longlong lVar1;
  longlong lVar2;
  longlong lVar3;
  int iVar4;
  byte *pbVar5;
  ulonglong uVar6;
  longlong lVar7;
  
  lVar7 = *(longlong *)(param_2 + 0x78);
  lVar1 = *(longlong *)(param_1 + 0x40);
  lVar2 = *(longlong *)(*(longlong *)(param_2 + 0xb8) + 8);
  lVar3 = *(longlong *)(*(longlong *)(lVar2 + 0x18) + 0x10);
  iVar4 = 2;
  FUN_000121dc();
  uVar6 = (ulonglong)(iVar4 + 1U);
  if ((*(byte *)(lVar3 + 3) & (byte)(iVar4 + 1U)) == 1) {
    if ((*(byte *)(lVar3 + 2) & 0x80) != 0) {
      pbVar5 = (byte *)(lVar1 + 0x2c9);
      do {
        if ((*(byte *)(lVar2 + 0x22) == pbVar5[1]) && (*(byte *)(lVar3 + 2) == *pbVar5)) {
          FUN_00021298(param_1,pbVar5[-1],*pbVar5);
        }
        pbVar5 = pbVar5 + 0x48;
        uVar6 = uVar6 - 1;
      } while (uVar6 != 0);
    }
  }
  else {
    FUN_000145ec(param_1,'\x01',*(undefined1 *)(lVar7 + 0x24),*(undefined1 *)(lVar3 + 2));
  }
  return 0;
}



/* ===== FUNC FUN_00016f84 @ 00016f84 ===== */

undefined8 FUN_00016f84(undefined8 param_1,longlong param_2)

{
  longlong lVar1;
  int iVar2;
  longlong lVar3;
  byte bVar4;
  undefined8 uVar5;
  undefined8 local_res10;
  
  lVar1 = *(longlong *)(*(longlong *)(*(longlong *)(param_2 + 0xb8) + 8) + 0x18);
  bVar4 = 0;
  FUN_000121dc();
  local_res10 = 0;
  uVar5 = 0x102;
  do {
    iVar2 = KeWaitForSingleObject(lVar1 + 0x30,0,0,0,&local_res10);
    FUN_00021370(iVar2);
    FUN_000121dc();
    if (iVar2 != 0x102) {
      if (*(char *)(lVar1 + 0x1c) == '\0') {
        uVar5 = 0x103;
      }
      else {
        FUN_000121dc();
        IoCsqInsertIrp(lVar1 + 0x50,param_2,0);
        uVar5 = 0xc0000016;
      }
      *(char *)(lVar1 + 0x1c) = *(char *)(lVar1 + 0x1c) + '\x01';
      goto LAB_0001709a;
    }
    lVar3 = 10000;
    do {
      KeStallExecutionProcessor(0x19);
      lVar3 = lVar3 + -1;
    } while (lVar3 != 0);
    bVar4 = bVar4 + 1;
  } while (bVar4 < 0x14);
  FUN_000121dc();
LAB_0001709a:
  KeSetEvent(lVar1 + 0x30,0,0);
  return uVar5;
}



/* ===== FUNC FUN_000170c8 @ 000170c8 ===== */

ulonglong FUN_000170c8(longlong param_1,undefined8 *param_2,longlong param_3,undefined8 *param_4,
                      undefined8 param_5,byte *param_6,undefined1 *param_7)

{
  uint uVar1;
  ulonglong uVar2;
  longlong lVar3;
  
  lVar3 = *(longlong *)(param_2[0x17] + 8);
  uVar2 = 0xc0000001;
  FUN_000121dc();
  if (param_4 != (undefined8 *)0x0) {
    if ((*(byte *)(*(longlong *)(*(longlong *)(lVar3 + 0x18) + 0x10) + 2) & 0x80) == 0) {
      uVar1 = FUN_00019630(param_1,param_2,param_3,(longlong)param_4,param_5,param_6,param_7);
    }
    else {
      uVar2 = FUN_000192c0(param_1,(longlong)param_2,param_3,param_4,param_6,param_7);
      uVar1 = (uint)uVar2;
    }
    uVar2 = (ulonglong)uVar1;
    if (uVar1 == 0xc000009a) {
      *(undefined4 *)(*(longlong *)(param_2[0x17] + 8) + 4) = 0xc0001000;
    }
  }
  return uVar2 & 0xffffffff;
}



/* ===== FUNC FUN_000171b0 @ 000171b0 ===== */

int FUN_000171b0(longlong param_1,longlong param_2,longlong param_3)

{
  longlong lVar1;
  longlong lVar2;
  int iVar3;
  undefined8 uVar4;
  byte local_res10 [2];
  undefined2 local_res12;
  ushort local_res14;
  
  lVar1 = *(longlong *)(*(longlong *)(param_2 + 0xb8) + 8);
  lVar2 = *(longlong *)(*(longlong *)(lVar1 + 0x18) + 0x10);
  iVar3 = -0x3fffffff;
  FUN_000121dc();
  uVar4 = FUN_000175e4(0x1e,(undefined8 *)local_res10);
  if ((char)uVar4 != '\0') {
    local_res12 = 0;
    local_res10[0] = local_res10[0] & 0xfe | 2;
    local_res14 = (ushort)*(byte *)(lVar2 + 2);
    iVar3 = FUN_00018f58(param_1,param_2,(ulonglong *)local_res10,param_3);
    if (iVar3 == 0) {
      *(undefined4 *)(lVar1 + 4) = 0;
      *(undefined4 *)(lVar1 + 0x10) = 0x10;
      *(undefined8 *)(lVar1 + 8) = *(undefined8 *)(param_2 + 0x78);
      *(undefined8 *)(param_2 + 0x38) = 0;
    }
  }
  return iVar3;
}



/* ===== FUNC FUN_0001728c @ 0001728c ===== */

int FUN_0001728c(longlong param_1,longlong param_2,longlong param_3)

{
  char cVar1;
  longlong lVar2;
  int iVar3;
  undefined8 uVar4;
  undefined8 local_res10;
  
  lVar2 = *(longlong *)(*(longlong *)(param_2 + 0xb8) + 8);
  cVar1 = *(char *)(lVar2 + 0x83);
  FUN_000121dc();
  uVar4 = FUN_000175e4(*(short *)(lVar2 + 2),&local_res10);
  if ((char)uVar4 == '\0') {
    return 0x103;
  }
  local_res10._2_1_ = *(undefined1 *)(lVar2 + 0x82);
  local_res10._3_1_ = cVar1;
  if (cVar1 == '\x03') {
    FUN_000121dc();
  }
  else if ((cVar1 != '\x01') && (cVar1 != '\"')) {
    local_res10._4_2_ = 0;
    goto LAB_00017337;
  }
  local_res10._4_2_ = *(undefined2 *)(lVar2 + 0x84);
LAB_00017337:
  local_res10._6_2_ = *(undefined2 *)(lVar2 + 0x24);
  iVar3 = FUN_00018f58(param_1,param_2,&local_res10,param_3);
  if (iVar3 == 0) {
    return 0x103;
  }
  return iVar3;
}



/* ===== FUNC FUN_00017378 @ 00017378 ===== */

int FUN_00017378(longlong param_1,longlong param_2,longlong param_3,longlong param_4)

{
  int iVar1;
  longlong lVar2;
  ulonglong *puVar3;
  undefined8 uVar4;
  
  iVar1 = 0;
  lVar2 = FUN_000121dc();
  puVar3 = (ulonglong *)ExAllocatePoolWithTag(0,lVar2 + 8,0x53747345);
  if (puVar3 == (ulonglong *)0x0) {
    iVar1 = -0x3fffff66;
  }
  else {
    uVar4 = FUN_000175e4(*(short *)(param_3 + 2),puVar3);
    if ((char)uVar4 != '\0') {
      *(undefined2 *)((longlong)puVar3 + 4) = *(undefined2 *)(param_3 + 0x84);
      *(undefined2 *)((longlong)puVar3 + 2) = *(undefined2 *)(param_3 + 0x82);
      iVar1 = FUN_00018f58(param_1,param_2,puVar3,param_4);
      if ((iVar1 != -0x3fffff66) && (iVar1 != -0x3fffff63)) {
        iVar1 = 0x103;
      }
    }
    ExFreePoolWithTag(puVar3,0);
  }
  return iVar1;
}



/* ===== FUNC FUN_00017454 @ 00017454 ===== */

int FUN_00017454(longlong param_1,longlong param_2,longlong param_3,longlong param_4)

{
  undefined2 uVar1;
  uint uVar2;
  int iVar3;
  ulonglong *puVar4;
  undefined8 uVar5;
  
  uVar2 = *(uint *)(param_3 + 0x24);
  iVar3 = 0;
  FUN_000121dc();
  puVar4 = (ulonglong *)ExAllocatePoolWithTag(0,(ulonglong)uVar2 + 8,0x53747345);
  if (puVar4 == (ulonglong *)0x0) {
    iVar3 = -0x3fffff66;
  }
  else {
    uVar5 = FUN_000175e4(*(short *)(param_3 + 2),puVar4);
    if ((char)uVar5 != '\0') {
      uVar1 = *(undefined2 *)(param_3 + 0x84);
      *(short *)((longlong)puVar4 + 6) = (short)uVar2;
      *(undefined2 *)((longlong)puVar4 + 4) = uVar1;
      iVar3 = FUN_00018f58(param_1,param_2,puVar4,param_4);
      if ((iVar3 != -0x3fffff66) && (iVar3 != -0x3fffff63)) {
        iVar3 = 0x103;
      }
    }
    ExFreePoolWithTag(puVar4,0);
  }
  return iVar3;
}



/* ===== FUNC FUN_00017534 @ 00017534 ===== */

ulonglong FUN_00017534(longlong param_1,int param_2)

{
  ulonglong in_CR8;
  
  FUN_00021370(param_2);
  FUN_000121c8();
  if (param_1 != 0) {
    *(int *)(param_1 + 0x30) = param_2;
    IofCompleteRequest(param_1,0);
  }
  return in_CR8 & 0xff;
}



/* ===== FUNC FUN_00017594 @ 00017594 ===== */

void FUN_00017594(longlong param_1,int param_2)

{
  FUN_00021370(param_2);
  FUN_000121c8();
  if (param_1 != 0) {
    *(undefined8 *)(param_1 + 0x68) = 0;
    *(int *)(param_1 + 0x30) = param_2;
    IofCompleteRequest(param_1,0);
  }
  return;
}



/* ===== FUNC FUN_000175e4 @ 000175e4 ===== */

undefined8 FUN_000175e4(short param_1,undefined8 *param_2)

{
  short *psVar1;
  undefined1 uVar2;
  int iVar3;
  
  uVar2 = 0;
  psVar1 = &DAT_00037310;
  iVar3 = 0;
  do {
    if (param_1 == *psVar1) {
      uVar2 = 1;
      psVar1 = *(short **)(&DAT_00037312 + (longlong)iVar3 * 10);
      *param_2 = psVar1;
      break;
    }
    psVar1 = psVar1 + 5;
    iVar3 = iVar3 + 1;
  } while ((longlong)psVar1 < 0x373ba);
  return CONCAT71((int7)((ulonglong)psVar1 >> 8),uVar2);
}



/* ===== FUNC FUN_0001762c @ 0001762c ===== */

int FUN_0001762c(longlong param_1,longlong param_2,longlong param_3,longlong param_4)

{
  undefined2 uVar1;
  uint uVar2;
  longlong lVar3;
  byte bVar4;
  int iVar5;
  ulonglong *puVar6;
  undefined8 uVar7;
  void *_Src;
  
  uVar2 = *(uint *)(param_3 + 0x24);
  iVar5 = 0;
  FUN_000121dc();
  puVar6 = (ulonglong *)ExAllocatePoolWithTag(0,(ulonglong)uVar2 + 8,0x53747345);
  if (puVar6 == (ulonglong *)0x0) {
    return -0x3fffff66;
  }
  uVar7 = FUN_000175e4(*(short *)(param_3 + 2),puVar6);
  if ((char)uVar7 != '\0') {
    *(byte *)puVar6 = (byte)*puVar6 ^ (*(byte *)(param_3 + 0x80) ^ (byte)*puVar6) & 0x1c;
    if ((*(byte *)(param_3 + 0x20) & 1) == 0) {
      bVar4 = (byte)*puVar6 & 0x7f;
    }
    else {
      bVar4 = (byte)*puVar6 | 0x80;
    }
    *(byte *)puVar6 = bVar4;
    *(undefined1 *)((longlong)puVar6 + 1) = *(undefined1 *)(param_3 + 0x81);
    *(undefined2 *)((longlong)puVar6 + 2) = *(undefined2 *)(param_3 + 0x82);
    uVar1 = *(undefined2 *)(param_3 + 0x84);
    *(short *)((longlong)puVar6 + 6) = (short)uVar2;
    *(undefined2 *)((longlong)puVar6 + 4) = uVar1;
    if (((*puVar6 & 0x80) == 0) && (uVar2 != 0)) {
      _Src = *(void **)(param_3 + 0x28);
      if (_Src == (void *)0x0) {
        lVar3 = *(longlong *)(param_3 + 0x30);
        if (lVar3 == 0) {
          FUN_000121dc();
          iVar5 = -0x3ffffff3;
          goto LAB_00017765;
        }
        if ((*(byte *)(lVar3 + 10) & 5) == 0) {
          _Src = (void *)MmMapLockedPagesSpecifyCache(lVar3,0,1,0,0,0x10);
        }
        else {
          _Src = *(void **)(lVar3 + 0x18);
        }
      }
      memcpy(puVar6 + 1,_Src,(ulonglong)uVar2);
    }
    iVar5 = FUN_00018f58(param_1,param_2,puVar6,param_4);
    if ((iVar5 != -0x3fffff66) && (iVar5 != -0x3fffff63)) {
      iVar5 = 0x103;
    }
  }
LAB_00017765:
  ExFreePoolWithTag(puVar6,0);
  return iVar5;
}



/* ===== FUNC FUN_000177b0 @ 000177b0 ===== */

void FUN_000177b0(undefined8 param_1,longlong param_2)

{
  int *piVar1;
  int iVar2;
  longlong lVar3;
  longlong *plVar4;
  short sVar5;
  int *piVar6;
  byte bVar7;
  
  lVar3 = *(longlong *)(param_2 + 0x40);
  if (*(int *)(lVar3 + 0xb0) != 0) {
    bVar7 = 1;
    piVar6 = (int *)(lVar3 + 0x1280);
    do {
      if ((char)piVar6[-1] == '\x01') {
        LOCK();
        *piVar6 = *piVar6 + 1;
        UNLOCK();
        if (*piVar6 == 9) {
          LOCK();
          *piVar6 = 0;
          UNLOCK();
          plVar4 = (longlong *)FUN_00017df4(param_2);
          if (plVar4 != (longlong *)0x0) {
            plVar4[1] = 0;
            *plVar4 = param_2;
            do {
              LOCK();
              piVar1 = (int *)(lVar3 + 0x210);
              iVar2 = *piVar1;
              *piVar1 = *piVar1 + 1;
              UNLOCK();
              sVar5 = (short)iVar2 + 1;
            } while (sVar5 == 0);
            *(short *)(plVar4 + 2) = sVar5;
            *(byte *)((longlong)plVar4 + 0x12) = bVar7;
            IoQueueWorkItem(plVar4[3],FUN_00017e54,1,plVar4);
          }
        }
      }
      bVar7 = bVar7 + 1;
      piVar6 = piVar6 + 0x9a;
    } while (bVar7 < 6);
    KeSetTimer(lVar3 + 0x3b8,0xffffffffff676980,lVar3 + 0x3f8);
  }
  return;
}



/* ===== FUNC FUN_00017888 @ 00017888 ===== */

void FUN_00017888(undefined8 param_1,longlong param_2)

{
  longlong lVar1;
  longlong lVar2;
  longlong lVar3;
  int *piVar4;
  byte bVar5;
  byte bVar6;
  
  lVar1 = *(longlong *)(param_2 + 0x40);
  bVar6 = 1;
  piVar4 = (int *)(lVar1 + 0x1288);
  do {
    if ((char)piVar4[-1] == '\x01') {
      LOCK();
      *piVar4 = *piVar4 + 1;
      UNLOCK();
      if (*piVar4 == piVar4[1]) {
        bVar5 = 0;
        LOCK();
        *piVar4 = 0;
        UNLOCK();
        do {
          lVar3 = IoCsqRemoveIrp(lVar1 + 0x218,lVar1 + 0x3a0);
          if (lVar3 != 0) {
            lVar2 = *(longlong *)(lVar3 + 0x18);
            *(undefined4 *)(lVar2 + 4) = 0x24544e55;
            *(undefined2 *)(lVar2 + 2) = 0x100;
            *(byte *)(lVar2 + 8) = bVar6;
            *(undefined4 *)(lVar2 + 9) = 0xc00000b5;
            *(undefined4 *)(lVar3 + 0x30) = 0;
            *(undefined8 *)(lVar3 + 0x38) = 0xd;
            FUN_000121dc();
            IofCompleteRequest(lVar3,0);
            break;
          }
          FUN_000120dc(100);
          bVar5 = bVar5 + 1;
        } while (bVar5 < 0x17);
      }
    }
    bVar6 = bVar6 + 1;
    piVar4 = piVar4 + 0x9a;
    if (5 < bVar6) {
      return;
    }
  } while( true );
}



/* ===== FUNC FUN_00017984 @ 00017984 ===== */

void FUN_00017984(undefined8 param_1,longlong param_2)

{
  longlong lVar1;
  uint uVar2;
  undefined8 uVar3;
  undefined1 *puVar4;
  longlong lVar5;
  
  lVar1 = *(longlong *)(param_2 + 0x40);
  if (*(int *)(lVar1 + 0xb0) != 0) {
    puVar4 = (undefined1 *)(lVar1 + 0x12f9);
    lVar5 = 5;
    do {
      uVar3 = KeQueryPerformanceCounter();
      if ((*(int *)(puVar4 + -5) + *(int *)(puVar4 + -9) < 1) || (*(longlong *)(puVar4 + -0x11) < 1)
         ) {
LAB_00017a16:
        puVar4[-1] = 8;
        *puVar4 = 8;
      }
      else {
        uVar2 = (uint)((*(longlong *)(lVar1 + 0x2008) *
                       (longlong)(*(int *)(puVar4 + -5) + *(int *)(puVar4 + -9))) /
                      (longlong)(ulonglong)(uint)((int)uVar3 - *(int *)(puVar4 + -0x11)));
        if (uVar2 < 0x400001) {
          if (uVar2 < 0x300001) {
            if (uVar2 < 0x200001) goto LAB_00017a16;
            puVar4[-1] = 0x10;
            *puVar4 = 0x10;
          }
          else {
            puVar4[-1] = 0x20;
            *puVar4 = 0x20;
          }
        }
        else {
          puVar4[-1] = 0x20;
          *puVar4 = 0x40;
        }
      }
      *(undefined8 *)(puVar4 + -0x11) = uVar3;
      LOCK();
      *(undefined4 *)(puVar4 + -9) = 0;
      UNLOCK();
      LOCK();
      *(undefined4 *)(puVar4 + -5) = 0;
      UNLOCK();
      puVar4 = puVar4 + 0x268;
      lVar5 = lVar5 + -1;
    } while (lVar5 != 0);
    KeSetTimer(lVar1 + 0x438,0xffffffffffb3b4c0,lVar1 + 0x478);
  }
  return;
}



/* ===== FUNC FUN_00017a70 @ 00017a70 ===== */

void FUN_00017a70(undefined8 param_1,longlong param_2)

{
  longlong lVar1;
  longlong *plVar2;
  char *pcVar3;
  longlong lVar4;
  
  lVar1 = *(longlong *)(param_2 + 0x40);
  if (*(int *)(lVar1 + 0xb0) != 0) {
    pcVar3 = (char *)(lVar1 + 0x2c8);
    lVar4 = 3;
    do {
      if ((*pcVar3 != -1) && (*(uint *)(pcVar3 + 0x30) != 0xffffffff)) {
        if (pcVar3[0x34] == '\0') {
          *(int *)(pcVar3 + 0x2c) = *(int *)(pcVar3 + 0x2c) + 2;
          if (*(uint *)(pcVar3 + 0x30) <= *(uint *)(pcVar3 + 0x2c)) {
            plVar2 = (longlong *)FUN_00017df4(param_2);
            if (plVar2 != (longlong *)0x0) {
              plVar2[1] = 0;
              *plVar2 = param_2;
              *(char *)((longlong)plVar2 + 0x12) = *pcVar3;
              IoQueueWorkItem(plVar2[3],FUN_00017b40,1,plVar2);
            }
          }
        }
        else {
          pcVar3[0x2c] = '\0';
          pcVar3[0x2d] = '\0';
          pcVar3[0x2e] = '\0';
          pcVar3[0x2f] = '\0';
          pcVar3[0x34] = '\0';
        }
      }
      pcVar3 = pcVar3 + 0x48;
      lVar4 = lVar4 + -1;
    } while (lVar4 != 0);
    KeSetTimer(lVar1 + 0x538,0xffffffffffffb1e0,lVar1 + 0x578);
  }
  return;
}



/* ===== FUNC FUN_00017b40 @ 00017b40 ===== */

void FUN_00017b40(longlong param_1,longlong param_2)

{
  longlong lVar1;
  longlong lVar2;
  longlong lVar3;
  int iVar4;
  uint uVar5;
  longlong lVar6;
  uint *puVar7;
  longlong lVar8;
  undefined1 local_48 [16];
  undefined1 local_38;
  byte local_37;
  
  lVar1 = *(longlong *)(param_1 + 0x40);
  if (*(int *)(lVar1 + 0xb0) != 0) {
    iVar4 = KeWaitForSingleObject(lVar1 + 0x2058,0,0,0,0);
    if (iVar4 == 0) {
      puVar7 = (uint *)(lVar1 + 0x2f4);
      lVar8 = 3;
      do {
        if (((char)puVar7[-0xb] != -1) && (puVar7[1] <= *puVar7)) {
          *puVar7 = 0;
          local_37 = *(byte *)((longlong)puVar7 + -0x2b) & 0x7f;
          local_38 = (undefined1)puVar7[-0xb];
          lVar6 = IoCsqRemoveNextIrp(lVar1 + 0x270,local_48);
          if (lVar6 == 0) {
            FUN_000121dc();
          }
          else {
            lVar2 = *(longlong *)(lVar6 + 0x88);
            lVar3 = *(longlong *)(*(longlong *)(lVar6 + 0xb8) + 8);
            *(undefined4 *)(lVar3 + 0x24) = *(undefined4 *)(lVar2 + 0x18);
            uVar5 = *(uint *)(lVar3 + 0x84);
            if (*(char *)(*(longlong *)(lVar6 + 0x78) + 0x41) == '\x02') {
              uVar5 = uVar5 >> 3;
            }
            puVar7[-1] = puVar7[-1] + uVar5;
            *(uint *)(lVar3 + 0x80) = puVar7[-1];
            ExFreePoolWithTag(lVar2,0x53747345);
            FUN_000121dc();
            FUN_00017594(lVar6,0);
          }
        }
        puVar7 = puVar7 + 0x12;
        lVar8 = lVar8 + -1;
      } while (lVar8 != 0);
    }
    else {
      FUN_000121dc();
    }
  }
  if (param_2 != 0) {
    if (*(longlong *)(param_2 + 0x18) != 0) {
      IoFreeWorkItem();
      *(undefined8 *)(param_2 + 0x18) = 0;
    }
    ExFreePoolWithTag(param_2,0x53747345);
  }
  KeSetEvent(lVar1 + 0x2058,0,0);
  return;
}



/* ===== FUNC FUN_00017d0c @ 00017d0c ===== */

void FUN_00017d0c(undefined8 param_1,longlong param_2)

{
  longlong lVar1;
  longlong *plVar2;
  longlong *plVar3;
  
  lVar1 = *(longlong *)(param_2 + 0x40);
  plVar3 = (longlong *)(lVar1 + 0xef8);
  if ((longlong *)*plVar3 != plVar3) {
    for (plVar2 = (longlong *)*plVar3; plVar2 != plVar3; plVar2 = (longlong *)*plVar2) {
      if ((plVar2 != (longlong *)0x8) && ((char)plVar2[2] == '\x01')) {
        *(short *)((longlong)plVar2 + -6) = *(short *)((longlong)plVar2 + -6) + 1;
        FUN_000121dc();
      }
    }
  }
                    /* WARNING: Could not recover jumptable at 0x00017d91. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  KeSetTimer(lVar1 + 0xf08,0xfffffffffff0bdc0,lVar1 + 0xf48);
  return;
}



/* ===== FUNC FUN_00017da0 @ 00017da0 ===== */

void FUN_00017da0(longlong param_1,longlong param_2,longlong param_3)

{
  undefined2 *puVar1;
  longlong lVar2;
  
  lVar2 = *(longlong *)(param_1 + 0x40);
  puVar1 = (undefined2 *)FUN_000121dc();
  *(undefined2 *)(param_3 + 0x10) = *puVar1;
  *(longlong *)(param_2 + 0x88) = param_3;
                    /* WARNING: Could not recover jumptable at 0x00017de6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  IoCsqInsertIrp(lVar2 + 0x218,param_2,param_3 + 0x20);
  return;
}



/* ===== FUNC FUN_00017df4 @ 00017df4 ===== */

longlong FUN_00017df4(undefined8 param_1)

{
  longlong lVar1;
  longlong lVar2;
  
  lVar1 = ExAllocatePoolWithTag(0,0x30,0x53747345);
  if (lVar1 != 0) {
    lVar2 = IoAllocateWorkItem(param_1);
    *(longlong *)(lVar1 + 0x18) = lVar2;
    if (lVar2 != 0) {
      return lVar1;
    }
    ExFreePoolWithTag(lVar1,0x53747345);
  }
  return 0;
}



/* ===== FUNC FUN_00017e54 @ 00017e54 ===== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00017e54(longlong param_1,longlong param_2)

{
  longlong lVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  ushort uVar4;
  int iVar5;
  longlong lVar6;
  ulonglong *puVar7;
  undefined8 *puVar8;
  byte bVar9;
  uint local_res8 [2];
  
  lVar1 = *(longlong *)(param_1 + 0x40);
  FUN_000121dc();
  if (*(int *)(lVar1 + 0xb0) == 0) {
    FUN_000121dc();
  }
  else {
    for (puVar8 = *(undefined8 **)(lVar1 + 0xa0); puVar8 != (undefined8 *)(lVar1 + 0xa0);
        puVar8 = (undefined8 *)*puVar8) {
      FUN_000121dc();
      if (((*(char *)((longlong)puVar8 + -0x34) == *(char *)(param_2 + 0x12)) &&
          (*(char *)((longlong)puVar8 + 0x11) == '\x01')) &&
         (*(char *)((longlong)puVar8 + 0x199) == '\b')) {
        local_res8[0] = 0;
        local_res8[1] = 0;
        iVar5 = KeWaitForSingleObject
                          ((ulonglong)*(byte *)((longlong)puVar8 + -0x34) * 0x268 + 0x10c0 + lVar1,0
                           ,0,0,local_res8);
        if (iVar5 == 0x102) {
          iVar5 = FUN_00014bec(param_1,lVar1 + 0x1e48 + (ulonglong)*(byte *)(param_2 + 0x12) * 0x30)
          ;
          FUN_00021370(iVar5);
          FUN_000121dc();
          FUN_000120dc(500);
          FUN_000145ec(param_1,'\0',*(undefined1 *)(param_2 + 0x12),0xff);
          FUN_000120dc(500);
          *(undefined1 *)((longlong)puVar8 + 0x15) = 0;
          bVar9 = 0;
          do {
            lVar6 = IoCsqRemoveIrp(lVar1 + 0x218,lVar1 + 0x3a0);
            if (lVar6 != 0) {
              lVar1 = *(longlong *)(lVar6 + 0x18);
              *(undefined4 *)(lVar1 + 4) = 0x24544e55;
              *(undefined2 *)(lVar1 + 2) = 0x200;
              *(undefined1 *)(lVar1 + 8) = *(undefined1 *)((longlong)puVar8 + -0x34);
              *(undefined4 *)(lVar1 + 9) = 0xc000020c;
              *(undefined4 *)(lVar6 + 0x30) = 0;
              *(undefined8 *)(lVar6 + 0x38) = 0x40d;
              FUN_000121dc();
              FUN_000120dc(2000);
              IofCompleteRequest(lVar6,0);
              goto LAB_000181a7;
            }
            bVar9 = bVar9 + 1;
          } while (bVar9 < 0x17);
          FUN_000120dc(100);
        }
        else {
          FUN_00021370(iVar5);
          FUN_000121dc();
        }
      }
    }
    puVar7 = (ulonglong *)FUN_0001bd38(param_1,lVar1,0);
    if (puVar7 != (ulonglong *)0x0) {
      FUN_000251f0(puVar7,0,0x20);
      uVar3 = _UNK_00035cc8;
      uVar2 = _DAT_00035cc0;
      *(undefined4 *)(puVar7 + 2) = 0x24544e55;
      *(undefined1 *)((longlong)puVar7 + 0x17) = 0x12;
      *puVar7 = uVar2;
      puVar7[1] = uVar3;
      *(undefined1 *)((longlong)puVar7 + 0x16) = *(undefined1 *)(param_2 + 0x12);
      *(undefined2 *)(puVar7 + 3) = *(undefined2 *)(param_2 + 0x10);
      FUN_000121dc();
      KeClearEvent((ulonglong)*(byte *)(param_2 + 0x12) * 0x268 + 0x10c0 + lVar1);
      FUN_0003d284(param_1,*(byte *)(param_2 + 0x12),
                   *(longlong *)(lVar1 + 0x1e70 + (ulonglong)*(byte *)(param_2 + 0x12) * 0x30),
                   puVar7,(uint)*(ushort *)(lVar1 + 0x2000),local_res8);
      KeSetEvent((ulonglong)*(byte *)(param_2 + 0x12) * 0x268 + 0x10c0 + lVar1,0,0);
      *(int *)(lVar1 + 0x1f9c) = *(int *)(lVar1 + 0x1f9c) + 1;
      uVar4 = ExQueryDepthSList(lVar1 + 0x1f80);
      if (uVar4 < *(ushort *)(lVar1 + 0x1f90)) {
        ExpInterlockedPushEntrySList(lVar1 + 0x1f80,puVar7);
      }
      else {
        *(int *)(lVar1 + 0x1fa0) = *(int *)(lVar1 + 0x1fa0) + 1;
        (**(code **)(lVar1 + 0x1fb8))(puVar7);
      }
    }
  }
LAB_000181a7:
  if (*(longlong *)(param_2 + 0x18) != 0) {
    IoFreeWorkItem();
  }
                    /* WARNING: Could not recover jumptable at 0x000181da. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ExFreePoolWithTag(param_2,0x53747345);
  return;
}



/* ===== FUNC FUN_000181e8 @ 000181e8 ===== */

void FUN_000181e8(undefined8 param_1,longlong param_2,longlong param_3)

{
  byte bVar1;
  undefined1 uVar2;
  undefined8 *puVar3;
  short sVar4;
  int iVar5;
  longlong lVar6;
  undefined1 local_18 [16];
  
  puVar3 = *(undefined8 **)(param_2 + 0x78);
  lVar6 = USBD_ParseConfigurationDescriptorEx
                    (puVar3[(ulonglong)*(byte *)(puVar3 + 0x21) + 0x11],
                     puVar3[(ulonglong)*(byte *)(puVar3 + 0x21) + 0x11],*(undefined1 *)(param_3 + 2)
                     ,*(undefined1 *)(param_3 + 3),0xffffffff,0xffffffff,0xffffffff);
  bVar1 = *(byte *)(lVar6 + 4);
  *(undefined1 *)((longlong)puVar3 + 0x173) = 0;
  *(undefined2 *)((longlong)puVar3 + 0x152) = 1;
  sVar4 = ((ushort)bVar1 * 3 + -3) * 8;
  *(short *)(puVar3 + 0x2a) = sVar4 + 0x50;
  *(undefined1 *)((longlong)puVar3 + 0x172) = *(undefined1 *)(lVar6 + 2);
  *(short *)(puVar3 + 0x2e) = sVar4 + 0x30;
  puVar3[0x2d] = puVar3[(ulonglong)*(byte *)(puVar3 + 0x21) + 0x11];
  *(ushort *)(puVar3 + 0x2e) = (bVar1 + 1) * 0x18;
  *(undefined1 *)((longlong)puVar3 + 0x172) = *(undefined1 *)(param_3 + 2);
  uVar2 = *(undefined1 *)(param_3 + 3);
  *(undefined4 *)(puVar3 + 0x33) = 0x1000;
  *(undefined1 *)((longlong)puVar3 + 0x173) = uVar2;
  puVar3[0x2f] = 0xf0f0f0f0f0f0f0f0;
  lVar6 = IoBuildDeviceIoControlRequest(0x220003,*puVar3,0,0,0,0,1,0,local_18);
  if (lVar6 != 0) {
    *(undefined8 **)(*(longlong *)(lVar6 + 0xb8) + -0x40) = puVar3 + 0x2a;
    *(undefined1 *)(puVar3 + 0x3e) = 1;
    iVar5 = IofCallDriver(*puVar3,lVar6);
    if (iVar5 != 0x103) {
      *(undefined1 *)(puVar3 + 0x3e) = 0;
    }
  }
  return;
}



/* ===== FUNC FUN_0001834c @ 0001834c ===== */

int FUN_0001834c(undefined8 param_1,ulonglong param_2,longlong param_3)

{
  int *piVar1;
  int iVar2;
  longlong lVar3;
  
  LOCK();
  piVar1 = (int *)((param_2 & 0xffffffff) * 0x268 + 0x10a0 + param_3);
  iVar2 = *piVar1;
  *piVar1 = *piVar1 + 1;
  UNLOCK();
  lVar3 = FUN_000121dc();
  if (iVar2 + 1 == 1) {
    KeClearEvent(lVar3 + 0x10a8 + param_3);
  }
  return iVar2 + 1;
}



/* ===== FUNC FUN_000183ac @ 000183ac ===== */

int FUN_000183ac(undefined8 param_1,ulonglong param_2,longlong param_3)

{
  int *piVar1;
  int iVar2;
  longlong lVar3;
  
  LOCK();
  piVar1 = (int *)((param_2 & 0xffffffff) * 0x268 + 0x10a0 + param_3);
  iVar2 = *piVar1;
  *piVar1 = *piVar1 + -1;
  UNLOCK();
  lVar3 = FUN_000121dc();
  if (iVar2 + -1 == 0) {
    KeSetEvent(lVar3 + 0x10a8 + param_3,0,0);
  }
  return iVar2 + -1;
}



/* ===== FUNC FUN_00018410 @ 00018410 ===== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00018410(longlong param_1,longlong param_2)

{
  undefined2 uVar1;
  longlong lVar2;
  longlong lVar3;
  longlong lVar4;
  ulonglong *puVar5;
  undefined1 *puVar6;
  ushort uVar7;
  ushort uVar8;
  byte bVar9;
  ulonglong uVar10;
  int iVar11;
  longlong lVar12;
  uint uVar13;
  longlong lVar14;
  undefined2 uVar15;
  undefined1 uVar16;
  longlong local_res8;
  undefined1 local_res10;
  byte local_res18 [8];
  uint local_res20;
  
  lVar2 = *(longlong *)(param_1 + 0x40);
  iVar11 = 0;
  lVar14 = (*(longlong **)(param_2 + 0x20))[2];
  lVar3 = **(longlong **)(param_2 + 0x20);
  uVar13 = 1;
  uVar7 = *(ushort *)(lVar14 + 4) & 0x7ff;
  local_res10 = 0;
  local_res18[0] = 0;
  lVar12 = lVar14;
  local_res8 = param_1;
  lVar4 = FUN_000121dc();
  if (*(int *)(lVar2 + 0xb0) == iVar11) {
    return;
  }
  if ((*(char *)(lVar4 + 0x40) == '\x02') && (*(byte *)(lVar4 + 0x41) < 2)) {
    local_res20 = CONCAT31(local_res20._1_3_,(char)uVar13);
    local_res10 = 0xfc;
    uVar7 = 0xbc;
  }
  else {
    local_res20 = uVar13 & 0xff;
    if (*(char *)(lVar4 + 0x41) == '\x02') {
      local_res20 = 0xff;
    }
    if (((uVar7 < 0x201) && (uVar7 < 0x101)) && (uVar7 < 0x81)) {
      uVar8 = 0x20;
      if (uVar7 < 0x41) {
        if (uVar7 < 0x21) {
          uVar8 = 0x50;
          uVar15 = 0x544;
          uVar16 = 0xa6;
          bVar9 = 0x28;
        }
        else {
          uVar8 = 0x30;
          uVar15 = 0x564;
          uVar16 = 0x86;
          bVar9 = 0x18;
        }
      }
      else {
        uVar15 = 0x574;
        uVar16 = 0x76;
        bVar9 = 0x10;
      }
      goto LAB_0001852d;
    }
  }
  uVar15 = 0x584;
  uVar16 = 0x66;
  uVar8 = 0x10;
  bVar9 = 8;
LAB_0001852d:
  FUN_00021144(param_1,*(char *)(param_2 + 0x12),*(char *)(lVar12 + 2),local_res18);
  puVar5 = (ulonglong *)FUN_0001bd38(param_1,lVar2,lVar3);
  if (puVar5 != (ulonglong *)0x0) {
    FUN_000251f0(puVar5,0,(ulonglong)uVar8 + 0x30);
    uVar10 = _UNK_00035cc8;
    *puVar5 = _DAT_00035cc0;
    puVar5[1] = uVar10;
    *(undefined4 *)(puVar5 + 2) = 0x24544e55;
    *(undefined1 *)((longlong)puVar5 + 0x16) = *(undefined1 *)(param_2 + 0x12);
    uVar1 = *(undefined2 *)(param_2 + 0x10);
    *(byte *)((longlong)puVar5 + 0x1e) = bVar9;
    *(undefined2 *)(puVar5 + 3) = uVar1;
    *(undefined1 *)((longlong)puVar5 + 0x1f) = 0;
    if (*(char *)(param_2 + 0x13) == '\0') {
      *(undefined1 *)((longlong)puVar5 + 0x15) = 0;
      *(undefined1 *)((longlong)puVar5 + 0x17) = 0x18;
    }
    else {
      *(char *)((longlong)puVar5 + 0x15) = (char)uVar8;
      *(undefined1 *)((longlong)puVar5 + 0x17) = 0x1a;
    }
    *(undefined1 *)((longlong)puVar5 + 0x14) = 0;
    lVar12 = local_res8;
    FUN_000121dc();
    *(byte *)((longlong)puVar5 + 0x2d) = *(byte *)((longlong)puVar5 + 0x2d) & 0xf0;
    *(byte *)((longlong)puVar5 + 0x25) = *(byte *)((longlong)puVar5 + 0x25) & 0xf0;
    *(char *)((longlong)puVar5 + 0x24) = (char)uVar15;
    *(char *)((longlong)puVar5 + 0x2c) = (char)uVar7;
    *(undefined1 *)(puVar5 + 4) = 1;
    *(undefined1 *)((longlong)puVar5 + 0x22) = 0x30;
    *(undefined1 *)((longlong)puVar5 + 0x23) = 0xf0;
    *(undefined1 *)((longlong)puVar5 + 0x26) = uVar16;
    *(undefined1 *)((longlong)puVar5 + 0x2b) = 0;
    *(undefined1 *)((longlong)puVar5 + 0x27) = 0;
    *(byte *)((longlong)puVar5 + 0x25) =
         *(byte *)((longlong)puVar5 + 0x25) | (byte)((ushort)uVar15 >> 8);
    *(char *)(puVar5 + 5) = (char)local_res20;
    *(undefined1 *)((longlong)puVar5 + 0x29) = local_res10;
    *(byte *)((longlong)puVar5 + 0x2d) = *(byte *)((longlong)puVar5 + 0x2d) | (byte)(uVar7 >> 8);
    *(byte *)((longlong)puVar5 + 0x2d) =
         (*(char *)(param_2 + 0x12) + -1) * '\x10' | *(byte *)((longlong)puVar5 + 0x2d) & 0xf;
    *(byte *)((longlong)puVar5 + 0x2e) =
         *(byte *)((longlong)puVar5 + 0x2e) ^
         (*(byte *)(param_2 + 0x12) ^ *(byte *)((longlong)puVar5 + 0x2e)) & 0xf;
    *(byte *)((longlong)puVar5 + 0x2e) =
         *(byte *)((longlong)puVar5 + 0x2e) & 0xf | *(char *)(lVar14 + 2) << 4;
    *(byte *)((longlong)puVar5 + 0x2f) = (-(*(byte *)(lVar3 + 0x41) < 2) & 0x7eU) + 0x96;
    if (bVar9 != 0) {
      puVar6 = (undefined1 *)((longlong)puVar5 + 0x31);
      uVar10 = (ulonglong)bVar9;
      do {
        puVar6[-1] = *(undefined1 *)(lVar2 + 0x2ec + (ulonglong)local_res18[0] * 0x48);
        *puVar6 = (char)((uint)*(undefined4 *)(lVar2 + 0x2ec + (ulonglong)local_res18[0] * 0x48) >>
                        8);
        puVar6 = puVar6 + 2;
        uVar10 = uVar10 - 1;
      } while (uVar10 != 0);
    }
    FUN_0003d284(lVar12,*(byte *)(param_2 + 0x12),
                 *(longlong *)(lVar2 + 0x1e70 + (ulonglong)*(byte *)(param_2 + 0x12) * 0x30),puVar5,
                 (uint)*(ushort *)(lVar2 + 0x2000),(uint *)&local_res8);
    *(int *)(lVar2 + 0x1f9c) = *(int *)(lVar2 + 0x1f9c) + 1;
    uVar7 = ExQueryDepthSList(lVar2 + 0x1f80);
    if (uVar7 < *(ushort *)(lVar2 + 0x1f90)) {
      ExpInterlockedPushEntrySList(lVar2 + 0x1f80,puVar5);
    }
    else {
      *(int *)(lVar2 + 0x1fa0) = *(int *)(lVar2 + 0x1fa0) + 1;
      (**(code **)(lVar2 + 0x1fb8))(puVar5);
    }
  }
  if (*(longlong *)(param_2 + 0x18) != 0) {
    IoFreeWorkItem();
  }
  ExFreePoolWithTag(param_2,0x53747345);
  return;
}



/* ===== FUNC FUN_00018778 @ 00018778 ===== */

undefined8 FUN_00018778(longlong param_1,longlong param_2)

{
  byte *pbVar1;
  char cVar2;
  uint uVar3;
  longlong lVar4;
  longlong lVar5;
  longlong lVar6;
  byte *pbVar7;
  byte *pbVar8;
  undefined8 uVar9;
  ulonglong uVar10;
  ushort uVar11;
  int iVar12;
  longlong *plVar13;
  longlong lVar14;
  byte bVar15;
  ulonglong local_res8;
  longlong local_res10;
  undefined8 in_stack_ffffffffffffffb8;
  undefined4 uVar16;
  
  uVar16 = (undefined4)((ulonglong)in_stack_ffffffffffffffb8 >> 0x20);
  lVar14 = *(longlong *)(param_2 + 0x78);
  lVar4 = *(longlong *)(param_1 + 0x40);
  lVar5 = *(longlong *)(*(longlong *)(param_2 + 0xb8) + 8);
  local_res10 = lVar14;
  FUN_000121dc();
  cVar2 = *(char *)(lVar5 + 0x23);
  if (cVar2 == '\0') {
    plVar13 = (longlong *)(lVar4 + 0x300);
    local_res8 = 3;
    do {
      if ((*(char *)(lVar5 + 0x22) == *(char *)((longlong)plVar13 + -0x36)) &&
         (*(char *)(lVar14 + 0x24) == (char)plVar13[-7])) {
        if (*plVar13 != 0) {
          FUN_0001e5bc(param_1,*(char *)(lVar14 + 0x24),*plVar13,0);
          FUN_00021298(param_1,(char)plVar13[-7],*(byte *)((longlong)plVar13 + -0x37));
          lVar14 = local_res10;
        }
        if (*(uint *)(plVar13 + 1) < *(uint *)(lVar4 + 0x2070)) {
          *(uint *)(lVar4 + 0x2070) = *(uint *)(lVar4 + 0x2070) - (int)plVar13[1];
        }
        else {
          *(undefined4 *)(lVar4 + 0x2070) = 0;
        }
        FUN_000121dc();
        *(undefined1 *)(plVar13 + -3) = 0;
        *(undefined4 *)((longlong)plVar13 + -0x14) = 0;
        *(undefined1 *)((longlong)plVar13 + -4) = 0;
        *(undefined4 *)((longlong)plVar13 + -0xc) = 0;
        *(undefined4 *)(plVar13 + 1) = 2000000;
      }
      plVar13 = plVar13 + 9;
      local_res8 = local_res8 - 1;
    } while (local_res8 != 0);
  }
  else if (cVar2 != '\0') {
    lVar14 = *(longlong *)(lVar14 + 0x88 + (ulonglong)*(byte *)(lVar14 + 0x108) * 8);
    if (lVar14 != 0) {
      pbVar7 = (byte *)USBD_ParseConfigurationDescriptorEx
                                 (lVar14,lVar14,*(undefined1 *)(lVar5 + 0x22),cVar2,0xffffffff,
                                  0xffffffff,CONCAT44(uVar16,0xffffffff));
      if (pbVar7 == (byte *)0x0) {
        FUN_000121dc();
        return 0x103;
      }
      pbVar1 = pbVar7 + 4;
      bVar15 = 0;
      if (*pbVar1 != 0) {
        do {
          pbVar8 = (byte *)USBD_ParseDescriptors(lVar14,*(undefined2 *)(lVar14 + 2),pbVar7,5);
          lVar6 = local_res10;
          if (((pbVar8[3] & 3) == 1) && (*(short *)(pbVar8 + 4) != 0)) break;
          bVar15 = bVar15 + 1;
          pbVar7 = pbVar8 + *pbVar8;
        } while (bVar15 < *pbVar1);
        if (-1 < (char)pbVar8[2]) {
          return 0x103;
        }
        uVar9 = FUN_00021144(param_1,*(char *)(local_res10 + 0x24),pbVar8[2],(byte *)&local_res8);
        if ((int)uVar9 == 0) {
          uVar10 = local_res8 & 0xff;
          lVar14 = *(longlong *)(lVar4 + 0x300 + uVar10 * 0x48);
          if (lVar14 != 0) {
            FUN_0001e5bc(param_1,*(undefined1 *)(lVar6 + 0x24),lVar14,0);
            FUN_00021298(param_1,*(undefined1 *)(lVar4 + 0x2c8 + uVar10 * 0x48),
                         *(byte *)(lVar4 + 0x2c9 + uVar10 * 0x48));
          }
          uVar3 = *(uint *)(lVar4 + 0x308 + uVar10 * 0x48);
          if (uVar3 < *(uint *)(lVar4 + 0x2070)) {
            *(uint *)(lVar4 + 0x2070) = *(uint *)(lVar4 + 0x2070) - uVar3;
          }
          else {
            *(undefined4 *)(lVar4 + 0x2070) = 0;
          }
          *(undefined1 *)(lVar4 + 0x2e8 + uVar10 * 0x48) = 0;
          *(undefined4 *)(lVar4 + 0x2ec + uVar10 * 0x48) = 0;
          *(undefined1 *)(lVar4 + 0x2fc + uVar10 * 0x48) = 0;
          *(undefined4 *)(lVar4 + 0x2f4 + uVar10 * 0x48) = 0;
          *(undefined4 *)(lVar4 + 0x308 + uVar10 * 0x48) = 2000000;
          FUN_000121dc();
        }
        uVar11 = *(ushort *)(pbVar8 + 4) & 0x1800;
        if ((uVar11 != 0) && (1 < *(byte *)(lVar5 + 0x23))) {
          FUN_000121dc();
          *(undefined4 *)(lVar5 + 4) = 0x80000700;
          return 0xc000009c;
        }
        if ((*(char *)(lVar6 + 0x41) == '\x02') &&
           ((*(char *)(lVar6 + 0x40) != '\x01' && (*(char *)(lVar6 + 0x40) != '\0')))) {
          iVar12 = ((*(ushort *)(pbVar8 + 4) >> 0xb & 3) + 1) * (*(ushort *)(pbVar8 + 4) & 0x7ff) *
                   64000;
        }
        else {
          iVar12 = (*(ushort *)(pbVar8 + 4) & 0x7ff) * 8000;
        }
        uVar3 = iVar12 + *(int *)(lVar4 + 0x2070);
        if ((uVar3 < 0xa7d8c1) && (uVar11 == 0)) {
          *(uint *)(lVar4 + 0x2070) = uVar3;
          FUN_000121dc();
          FUN_00021198(param_1,*(char *)(lVar6 + 0x24),*(char *)(lVar5 + 0x22),0,0xff,pbVar8[2],
                       (byte *)&local_res8);
          FUN_000121dc();
          *(int *)(lVar4 + 0x308 + (local_res8 & 0xff) * 0x48) = iVar12;
          return 0x103;
        }
        *(undefined4 *)(lVar5 + 4) = 0x80000700;
        FUN_000121dc();
        return 0xc000009c;
      }
    }
    FUN_000121dc();
  }
  return 0x103;
}



/* ===== FUNC FUN_00018b94 @ 00018b94 ===== */

int FUN_00018b94(longlong param_1,longlong param_2)

{
  char cVar1;
  longlong lVar2;
  longlong lVar3;
  longlong lVar4;
  longlong lVar5;
  byte bVar6;
  uint uVar7;
  int iVar8;
  undefined8 uVar9;
  ulonglong uVar10;
  byte bVar11;
  byte local_res8 [8];
  
  lVar2 = *(longlong *)(param_2 + 0x78);
  lVar3 = *(longlong *)(param_1 + 0x40);
  lVar4 = *(longlong *)(*(longlong *)(param_2 + 0xb8) + 8);
  if (*(longlong *)(lVar4 + 0x18) != 0) {
    cVar1 = *(char *)(*(longlong *)(*(longlong *)(lVar4 + 0x18) + 0x10) + 2);
    if (-1 < cVar1) {
      iVar8 = -0x3ffffff2;
      bVar6 = 0;
      while ((*(char *)(lVar2 + 0x24) != *(char *)((ulonglong)bVar6 * 0xf8 + 0xaa0 + lVar3) ||
             (cVar1 != *(char *)((ulonglong)bVar6 * 0xf8 + 0xaa2 + lVar3)))) {
        bVar6 = bVar6 + 1;
        bVar11 = 0xff;
        if (3 < bVar6) {
LAB_00018c1d:
          if (iVar8 != 0) {
            return iVar8;
          }
          uVar9 = FUN_00020bec(param_1,param_2,'\x01',*(byte *)(lVar4 + 0x84),bVar11,(char *)0x0);
          if ((int)uVar9 == 0) {
            KeSetEvent((ulonglong)bVar11 * 0xf8 + 0xad8 + lVar3,0,0);
            return 0x103;
          }
          return (int)uVar9;
        }
      }
      iVar8 = 0;
      bVar11 = bVar6;
      goto LAB_00018c1d;
    }
    uVar9 = FUN_00021144(param_1,*(char *)(lVar2 + 0x24),cVar1,local_res8);
    if ((int)uVar9 == 0) {
      uVar10 = (ulonglong)local_res8[0];
      if (*(char *)(lVar3 + 0x2e8 + uVar10 * 0x48) == '\0') {
        *(undefined1 *)(lVar3 + 0x2e8 + uVar10 * 0x48) = 1;
        *(uint *)(lVar3 + 0x2ec + uVar10 * 0x48) = *(uint *)(lVar4 + 0x24) / *(uint *)(lVar4 + 0x84)
        ;
        FUN_0001e5bc(param_1,*(undefined1 *)(lVar2 + 0x24),
                     *(longlong *)(lVar3 + 0x300 + uVar10 * 0x48),1);
        lVar5 = **(longlong **)(lVar3 + 0x300 + uVar10 * 0x48);
        if (((*(byte *)(lVar2 + 0x24) < 2) || (*(char *)(lVar5 + 0x40) == '\x02')) &&
           (*(char *)(lVar5 + 0x41) == '\x02')) {
          uVar7 = *(uint *)(lVar4 + 0x84) >> 3;
        }
        else {
          uVar7 = *(uint *)(lVar4 + 0x84);
        }
        *(uint *)(lVar3 + 0x2f8 + uVar10 * 0x48) = uVar7;
        FUN_000121dc();
      }
      FUN_000121dc();
      uVar9 = FUN_00020fc4(param_1,param_2,0,'\x01');
      iVar8 = (int)uVar9;
      if (iVar8 == 0) {
        iVar8 = 0x103;
      }
      return iVar8;
    }
    FUN_000121dc();
  }
  return -0x3fffff63;
}



/* ===== FUNC FUN_00018db0 @ 00018db0 ===== */

int FUN_00018db0(longlong param_1,longlong param_2)

{
  char cVar1;
  longlong lVar2;
  int iVar3;
  byte bVar4;
  longlong lVar5;
  undefined8 uVar6;
  longlong lVar7;
  
  lVar7 = *(longlong *)(param_1 + 0x40);
  lVar2 = *(longlong *)(*(longlong *)(*(longlong *)(param_2 + 0xb8) + 8) + 0x18);
  lVar5 = param_1;
  FUN_000121dc();
  iVar3 = 0;
  *(undefined8 *)(param_2 + 0x78) = *(undefined8 *)(lVar5 + 0x40);
  if (*(longlong *)(lVar7 + 0x88 + (ulonglong)*(byte *)(lVar7 + 0x108) * 8) == 0) {
    *(undefined1 *)(lVar7 + 0x108) = 0;
    iVar3 = FUN_000123c0(param_1,param_2);
  }
  else {
    cVar1 = *(char *)(lVar2 + 5);
    if (cVar1 == *(char *)(*(longlong *)(lVar7 + 0x88 + (ulonglong)*(byte *)(lVar7 + 0x108) * 8) + 5
                          )) {
      uVar6 = **(undefined8 **)(*(longlong *)(lVar7 + 0x28) + 0x40);
      lVar7 = *(longlong *)(*(longlong *)(param_2 + 0xb8) + 8);
      FUN_000121dc();
      if (*(longlong *)(lVar7 + 0x18) != 0) {
        *(undefined4 *)(lVar7 + 4) = 0;
        FUN_0001c4e8(uVar6,param_2);
      }
      FUN_00017594(param_2,0);
    }
    else {
      bVar4 = 0;
      if (cVar1 != '\0') {
        do {
          lVar2 = *(longlong *)(lVar7 + 0x88 + (ulonglong)bVar4 * 8);
          if ((lVar2 != 0) && (*(char *)(lVar2 + 5) == cVar1)) goto LAB_00018e79;
          bVar4 = bVar4 + 1;
        } while (bVar4 < 0x10);
        bVar4 = 0;
      }
LAB_00018e79:
      *(byte *)(lVar7 + 0x108) = bVar4;
      iVar3 = FUN_000123c0(param_1,param_2);
    }
  }
  return iVar3;
}



/* ===== FUNC FUN_00018ef0 @ 00018ef0 ===== */

undefined8 FUN_00018ef0(undefined8 param_1,longlong param_2)

{
  longlong lVar1;
  undefined8 uVar2;
  
  if (*(longlong *)(param_2 + 0x28) == 0) {
    lVar1 = *(longlong *)(param_2 + 0x30);
    if (lVar1 == 0) {
      uVar2 = FUN_000121dc();
    }
    else if ((*(byte *)(lVar1 + 10) & 5) == 0) {
      uVar2 = MmMapLockedPagesSpecifyCache(lVar1,0,1,0,0,0x10);
    }
    else {
      uVar2 = *(undefined8 *)(lVar1 + 0x18);
    }
  }
  else {
    uVar2 = *(undefined8 *)(param_2 + 0x28);
  }
  return uVar2;
}



/* ===== FUNC FUN_00018f58 @ 00018f58 ===== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_00018f58(longlong param_1,longlong param_2,ulonglong *param_3,longlong param_4)

{
  undefined1 uVar1;
  short sVar2;
  longlong lVar3;
  ulonglong uVar4;
  longlong lVar5;
  ulonglong uVar6;
  byte bVar7;
  short sVar8;
  ushort uVar9;
  int iVar10;
  ulonglong *puVar11;
  ulonglong *_Dst;
  size_t _Size;
  longlong local_res10;
  
  lVar3 = *(longlong *)(param_1 + 0x40);
  uVar4 = *(ulonglong *)(param_2 + 0x78);
  lVar5 = *(longlong *)(*(longlong *)(param_2 + 0xb8) + 8);
  uVar9 = *(ushort *)(lVar3 + 0x2000);
  sVar2 = *(short *)(lVar5 + 2);
  local_res10 = param_2;
  puVar11 = (ulonglong *)FUN_0001bd38(param_1,lVar3,uVar4);
  if (puVar11 == (ulonglong *)0x0) {
    if ((*(char *)(uVar4 + 0x69) == '\0') || (iVar10 = -0x3fffff66, *(char *)(uVar4 + 0x6d) == '\0')
       ) {
      iVar10 = -0x3fffff63;
    }
    FUN_00021370(iVar10);
    FUN_000121dc();
    goto LAB_00019271;
  }
  FUN_000251f0(puVar11,0,(ulonglong)uVar9);
  uVar6 = _UNK_00035c88;
  *puVar11 = _DAT_00035c80;
  puVar11[1] = uVar6;
  *(undefined4 *)(puVar11 + 2) = 0x24544e55;
  *(undefined1 *)((longlong)puVar11 + 0x17) = 0;
  if (uVar4 < 0xffffffffffffff01) {
    *(undefined1 *)((longlong)puVar11 + 0x16) = *(undefined1 *)(uVar4 + 0x24);
  }
  else {
    *(char *)((longlong)puVar11 + 0x16) = (char)uVar4;
  }
  if (param_4 == 0) {
    *(undefined2 *)(puVar11 + 3) = 0;
  }
  else {
    *(undefined2 *)(puVar11 + 3) = *(undefined2 *)(param_4 + 0x10);
  }
  if ((char)*param_3 < '\0') {
    *(undefined1 *)((longlong)puVar11 + 0x1c) = 0x33;
  }
  else if (-1 < (char)*param_3) {
    if (*(short *)((longlong)param_3 + 6) == 0) {
      *(undefined1 *)((longlong)puVar11 + 0x1c) = 0x25;
    }
    else {
      *(undefined1 *)((longlong)puVar11 + 0x1c) = 0x2d;
    }
  }
  *(undefined1 *)(puVar11 + 4) = 1;
  *(undefined1 *)((longlong)puVar11 + 0x21) = *(undefined1 *)((longlong)param_3 + 2);
  *(undefined1 *)((longlong)puVar11 + 0x22) = *(undefined1 *)((longlong)param_3 + 3);
  *(undefined1 *)((longlong)puVar11 + 0x23) = *(undefined1 *)((longlong)param_3 + 4);
  uVar1 = *(undefined1 *)((longlong)param_3 + 5);
  *(undefined1 *)((longlong)puVar11 + 0x24) = 8;
  *(undefined1 *)((longlong)puVar11 + 0x2a) = uVar1;
  if ((*param_3 & 0x80) == 0) {
    sVar8 = *(short *)((longlong)param_3 + 6);
    *(byte *)((longlong)puVar11 + 0x25) = *(byte *)((longlong)puVar11 + 0x25) & 0xf0;
    sVar8 = sVar8 + 8;
    *(char *)((longlong)puVar11 + 0x24) = (char)sVar8;
    *(byte *)((longlong)puVar11 + 0x25) =
         *(byte *)((longlong)puVar11 + 0x25) | (byte)((ushort)sVar8 >> 8) & 0xf;
  }
  *(undefined1 *)((longlong)puVar11 + 0x15) = *(undefined1 *)((longlong)puVar11 + 0x24);
  *(byte *)((longlong)puVar11 + 0x14) = *(byte *)((longlong)puVar11 + 0x25) & 0xf;
  if (((*param_3 & 0x80) != 0) && (*(ushort *)(lVar3 + 0x2000) < *(ushort *)((longlong)param_3 + 6))
     ) {
    *(ushort *)((longlong)param_3 + 6) = *(ushort *)(lVar3 + 0x2000);
  }
  *(undefined1 *)((longlong)puVar11 + 0x26) = *(undefined1 *)((longlong)param_3 + 6);
  *(undefined1 *)((longlong)puVar11 + 0x27) = *(undefined1 *)((longlong)param_3 + 7);
  *(char *)(puVar11 + 5) = (char)*param_3;
  uVar1 = *(undefined1 *)((longlong)param_3 + 1);
  *(byte *)((longlong)puVar11 + 0x2a) = *(byte *)((longlong)puVar11 + 0x2a) & 0x7f;
  *(undefined1 *)((longlong)puVar11 + 0x29) = uVar1;
  *(byte *)((longlong)puVar11 + 0x2d) = *(byte *)((longlong)puVar11 + 0x2d) & 0xf;
  bVar7 = *(byte *)((longlong)puVar11 + 0x16) & 0xf;
  *(byte *)((longlong)puVar11 + 0x2e) = bVar7;
  *(byte *)((longlong)puVar11 + 0x2d) = *(byte *)((longlong)puVar11 + 0x2d) | (bVar7 - 1) * '\x10';
  *(byte *)((longlong)puVar11 + 0x2f) = *(byte *)((longlong)puVar11 + 0x2f) & 0xcb | 8;
  if ((*(short *)(lVar5 + 2) == 8) || (*(short *)(lVar5 + 2) == 0x32)) {
    puVar11[6] = *param_3;
    if ((*(short *)((longlong)param_3 + 6) != 0) && ((*param_3 & 0x80) == 0)) {
      _Size = (size_t)*(ushort *)((longlong)param_3 + 6);
      param_3 = *(ulonglong **)(lVar5 + 0x28);
      _Dst = puVar11 + 7;
      goto LAB_0001915d;
    }
  }
  else {
    _Size = (size_t)((uint)*(byte *)((longlong)puVar11 + 0x24) +
                    (*(byte *)((longlong)puVar11 + 0x25) & 0xf) * 0x100);
    _Dst = puVar11 + 6;
LAB_0001915d:
    memcpy(_Dst,param_3,_Size);
  }
  if ((param_4 != 0) && (*(short *)(lVar5 + 2) != 0x1e)) {
    *(byte *)(param_4 + 0x12) = *(byte *)((longlong)puVar11 + 0x2e) & 0xf;
    *(byte *)(param_4 + 0x13) = *(byte *)((longlong)puVar11 + 0x2e) >> 4;
    *(undefined1 *)(param_4 + 0x14) = *(undefined1 *)((longlong)puVar11 + 0x17);
    FUN_00017da0(param_1,local_res10,param_4);
  }
  iVar10 = FUN_0003d284(param_1,*(byte *)(uVar4 + 0x24),
                        *(longlong *)(lVar3 + 0x1e70 + (ulonglong)*(byte *)(uVar4 + 0x24) * 0x30),
                        puVar11,(uint)*(ushort *)(lVar3 + 0x2000),(uint *)&local_res10);
  *(int *)(lVar3 + 0x1f9c) = *(int *)(lVar3 + 0x1f9c) + 1;
  uVar9 = ExQueryDepthSList(lVar3 + 0x1f80);
  if (uVar9 < *(ushort *)(lVar3 + 0x1f90)) {
    ExpInterlockedPushEntrySList(lVar3 + 0x1f80,puVar11);
  }
  else {
    *(int *)(lVar3 + 0x1fa0) = *(int *)(lVar3 + 0x1fa0) + 1;
    (**(code **)(lVar3 + 0x1fb8))(puVar11);
  }
  if (iVar10 == 0) {
    if ((uint)local_res10 == *(ushort *)(lVar3 + 0x2000)) {
      if (sVar2 != 0x1e) {
        iVar10 = 0x103;
      }
      goto LAB_00019271;
    }
  }
  else if ((iVar10 == -0x3fffff4b) || (iVar10 == -0x3ffffdf4)) goto LAB_00019271;
  iVar10 = -0x3fffffff;
LAB_00019271:
  FUN_00021370(iVar10);
  FUN_000121dc();
  return iVar10;
}



/* ===== FUNC FUN_000192c0 @ 000192c0 ===== */

ulonglong FUN_000192c0(longlong param_1,longlong param_2,longlong param_3,undefined8 *param_4,
                      byte *param_5,undefined1 *param_6)

{
  int *piVar1;
  char cVar2;
  byte bVar3;
  undefined1 uVar4;
  ushort uVar5;
  undefined2 uVar6;
  int iVar7;
  longlong lVar8;
  longlong lVar9;
  longlong lVar10;
  byte bVar11;
  ulonglong uVar12;
  uint uVar13;
  longlong lVar14;
  uint uVar15;
  ulonglong uVar16;
  longlong lVar17;
  longlong local_res10;
  longlong local_res18;
  undefined2 local_res20;
  
  lVar17 = *(longlong *)(*(longlong *)(param_2 + 0xb8) + 8);
  local_res20 = *(undefined2 *)(param_3 + 0x10);
  lVar14 = param_1;
  local_res10 = param_2;
  local_res18 = param_3;
  FUN_000121dc();
  lVar8 = *(longlong *)(lVar17 + 0x18);
  iVar7 = *(int *)(lVar17 + 0x24);
  lVar9 = *(longlong *)(param_2 + 0x78);
  cVar2 = *(char *)(lVar9 + 0x1f1);
  lVar10 = *(longlong *)(lVar8 + 0x10);
  lVar14 = *(longlong *)(lVar14 + 0x40);
  FUN_000121dc();
  uVar15 = iVar7 - *(int *)(param_2 + 0x80);
  uVar12 = FUN_0001b110(param_1,lVar17,lVar9,param_4);
  uVar16 = uVar12 & 0xffffffff;
  if ((int)uVar12 == 0) {
    bVar11 = (byte)(uVar15 >> 8);
    if (*(ushort *)(lVar8 + 0x1a) < uVar15) {
      uVar5 = *(ushort *)(lVar8 + 0x1a);
      bVar3 = *(byte *)((ulonglong)*(byte *)((longlong)param_4 + 0x16) * 0x268 + 0x1090 + lVar14);
      *(byte *)((longlong)param_4 + 0x25) = *(byte *)((longlong)param_4 + 0x25) & 0xf0;
      *(byte *)((longlong)param_4 + 0x25) =
           *(byte *)((longlong)param_4 + 0x25) | (byte)(uVar5 >> 8) & 0xf;
      uVar13 = (uint)uVar5 * (uint)bVar3;
      *(undefined1 *)((longlong)param_4 + 0x24) = *(undefined1 *)(lVar8 + 0x1a);
      if (uVar13 < uVar15) {
        *(char *)((longlong)param_4 + 0x15) = (char)uVar13;
        *(byte *)((longlong)param_4 + 0x1e) = bVar3;
        *(char *)((longlong)param_4 + 0x14) = (char)(uVar13 >> 8);
      }
      else {
        *(char *)((longlong)param_4 + 0x15) = (char)uVar15;
        *(byte *)((longlong)param_4 + 0x14) = bVar11;
        *(char *)((longlong)param_4 + 0x1e) = (char)(uVar15 / *(ushort *)(lVar8 + 0x1a));
        if (uVar15 % (uint)*(ushort *)(lVar8 + 0x1a) != 0) {
          *(char *)((longlong)param_4 + 0x1e) = (char)(uVar15 / *(ushort *)(lVar8 + 0x1a)) + '\x01';
        }
      }
    }
    else {
      *(char *)((longlong)param_4 + 0x15) = (char)uVar15;
      *(byte *)((longlong)param_4 + 0x14) = bVar11;
      *(byte *)((longlong)param_4 + 0x25) = *(byte *)((longlong)param_4 + 0x25) & 0xf0;
      *(byte *)((longlong)param_4 + 0x25) = *(byte *)((longlong)param_4 + 0x25) | bVar11 & 0xf;
      *(undefined1 *)((longlong)param_4 + 0x24) = *(undefined1 *)((longlong)param_4 + 0x15);
      *(undefined1 *)((longlong)param_4 + 0x1e) = 1;
    }
    bVar11 = *(byte *)(lVar10 + 3) & 3;
    if (bVar11 == 2) {
      *(undefined1 *)((longlong)param_4 + 0x17) = 4;
    }
    else {
      if (bVar11 != 3) {
        uVar16 = 0xc000000d;
        goto LAB_000195e0;
      }
      *(undefined1 *)((longlong)param_4 + 0x17) = 8;
      *(undefined1 *)(param_4 + 5) = 4;
      *(undefined1 *)((longlong)param_4 + 0x29) = 0xf8;
      uVar4 = *(undefined1 *)(lVar10 + 6);
      *(undefined1 *)((longlong)param_4 + 0x23) = 0;
      *(undefined1 *)((longlong)param_4 + 0x22) = uVar4;
    }
    uVar6 = *(undefined2 *)(local_res18 + 0x10);
    *(undefined2 *)(param_4 + 3) = uVar6;
    if (*(char *)(lVar14 + 0x214) == '\x01') {
      *(byte *)((longlong)param_4 + 0x2a) = *(byte *)((longlong)param_4 + 0x2a) | 0x80;
      *(char *)((longlong)param_4 + 0x2b) = (char)uVar6;
    }
    bVar11 = *(byte *)((longlong)param_4 + 0x2e);
    *param_5 = bVar11 >> 4;
    *param_6 = *(undefined1 *)((longlong)param_4 + 0x17);
    *(byte *)(local_res18 + 0x12) = bVar11 & 0xf;
    *(byte *)(local_res18 + 0x13) = *(byte *)((longlong)param_4 + 0x2e) >> 4;
    *(undefined1 *)(local_res18 + 0x14) = *(undefined1 *)((longlong)param_4 + 0x17);
    FUN_00017da0(param_1,local_res10,local_res18);
    FUN_000121dc();
    if (cVar2 == '\b') {
      KeClearEvent((ulonglong)*(byte *)(lVar9 + 0x24) * 0x268 + 0x10c0 + lVar14);
    }
    piVar1 = (int *)((ulonglong)*(byte *)(lVar9 + 0x24) * 0x268 + 0x102f + lVar14);
    *piVar1 = *piVar1 + 1;
    uVar15 = FUN_0003d284(param_1,*(byte *)(lVar9 + 0x24),
                          *(longlong *)(lVar14 + 0x1e70 + (ulonglong)*(byte *)(lVar9 + 0x24) * 0x30)
                          ,param_4,(uint)*(ushort *)(lVar14 + 0x2000),(uint *)&local_res10);
    uVar16 = (ulonglong)uVar15;
    if (cVar2 == '\b') {
      KeSetEvent((ulonglong)*(byte *)(lVar9 + 0x24) * 0x268 + 0x10c0 + lVar14,0,0);
    }
    if (uVar15 == 0) {
      if ((uint)local_res10 == *(ushort *)(lVar14 + 0x2000)) {
        uVar16 = 0x103;
        goto LAB_000195e0;
      }
    }
    else if ((uVar15 == 0xc00000b5) || (uVar15 == 0xc000020c)) goto LAB_000195e0;
    uVar16 = 0xc0000001;
  }
LAB_000195e0:
  FUN_00021370((int)uVar16);
  FUN_000121dc();
  return uVar16;
}



/* ===== FUNC FUN_00019630 @ 00019630 ===== */

int FUN_00019630(longlong param_1,undefined8 *param_2,longlong param_3,longlong param_4,
                undefined8 param_5,byte *param_6,undefined1 *param_7)

{
  int *piVar1;
  char cVar2;
  byte bVar3;
  char cVar4;
  undefined2 uVar5;
  longlong lVar6;
  longlong lVar7;
  longlong lVar8;
  longlong lVar9;
  longlong lVar10;
  int iVar11;
  undefined8 *puVar12;
  undefined8 *puVar13;
  byte bVar14;
  ushort uVar15;
  uint uVar16;
  uint uVar17;
  byte bVar18;
  byte local_res8;
  uint local_74;
  uint local_70;
  uint local_6c;
  longlong local_68;
  undefined2 *local_60;
  longlong local_58;
  longlong local_50;
  
  lVar6 = param_2[0xf];
  local_74 = *(uint *)(param_2 + 0x10);
  local_68 = *(longlong *)(param_2[0x17] + 8);
  local_60 = (undefined2 *)(param_3 + 0x10);
  lVar7 = *(longlong *)(local_68 + 0x18);
  lVar8 = *(longlong *)(param_1 + 0x40);
  lVar9 = *(longlong *)(lVar7 + 0x10);
  cVar2 = *(char *)(lVar6 + 0x1f1);
  uVar17 = local_74;
  local_50 = lVar9;
  lVar10 = FUN_000121dc();
  uVar17 = *(int *)(lVar10 + 0x24) - uVar17;
  local_58 = FUN_00018ef0(param_1,lVar10);
  if (*(char *)(*(longlong *)(lVar7 + 8) + 5) == '\a') {
    uVar16 = 1;
  }
  else {
    uVar16 = (uint)*(byte *)((ulonglong)*(byte *)(lVar6 + 0x24) * 0x268 + 0x1091 + lVar8);
  }
  bVar14 = (byte)uVar16;
  if (uVar17 / *(ushort *)(lVar7 + 0x1a) < uVar16) {
    if (uVar17 == 0) {
      bVar14 = 1;
    }
    else {
      bVar14 = (byte)(uVar17 / *(ushort *)(lVar7 + 0x1a));
      if (uVar17 % (uint)*(ushort *)(lVar7 + 0x1a) != 0) {
        bVar14 = bVar14 + 1;
      }
    }
  }
  uVar16 = 0;
  bVar18 = *(byte *)(lVar9 + 3) & 3;
  local_res8 = 0;
  if (bVar14 == 0) {
    puVar13 = param_2;
  }
  else {
    local_6c = bVar14 - 1;
    do {
      puVar13 = (undefined8 *)((int)(*(ushort *)(lVar8 + 0x2000) * uVar16) + param_4);
      FUN_0001b110(param_1,local_68,lVar6,puVar13);
      if (((int)(uint)local_res8 < (int)local_6c) || (*(ushort *)(lVar7 + 0x1a) < uVar17)) {
        *(undefined1 *)((longlong)puVar13 + 0x14) = *(undefined1 *)(lVar7 + 0x1b);
        *(undefined1 *)((longlong)puVar13 + 0x15) = *(undefined1 *)(lVar7 + 0x1a);
      }
      else {
        *(char *)((longlong)puVar13 + 0x15) = (char)uVar17;
        *(char *)((longlong)puVar13 + 0x14) = (char)(uVar17 >> 8);
      }
      if ((bVar18 != 2) && (bVar18 != 3)) {
        iVar11 = -0x3ffffff3;
        goto LAB_00019af0;
      }
      *(undefined1 *)((longlong)puVar13 + 0x17) = 2;
      uVar5 = *local_60;
      *(byte *)((longlong)puVar13 + 0x1e) = bVar14;
      *(byte *)((longlong)puVar13 + 0x1f) = local_res8;
      *(undefined2 *)(puVar13 + 3) = uVar5;
      *(byte *)((longlong)puVar13 + 0x25) =
           *(byte *)((longlong)puVar13 + 0x25) ^
           (*(byte *)((longlong)puVar13 + 0x25) ^ *(byte *)((longlong)puVar13 + 0x14)) & 0xf;
      *(byte *)((longlong)puVar13 + 0x24) = *(byte *)((longlong)puVar13 + 0x15);
      if (uVar17 != 0) {
        memcpy(puVar13 + 6,(void *)((ulonglong)local_74 + local_58),
               (longlong)
               (int)((*(byte *)((longlong)puVar13 + 0x25) & 0xf) * 0x100 +
                    (uint)*(byte *)((longlong)puVar13 + 0x15)));
      }
      if (((*(int *)(local_68 + 0x24) == 0x1f) && (*(char *)(*(longlong *)(lVar7 + 8) + 5) == '\b'))
         && (*(char *)((longlong)puVar13 + 0x3f) != '\0')) {
        LOCK();
        *(undefined4 *)
         ((ulonglong)*(byte *)((longlong)puVar13 + 0x16) * 0x268 + 0x1020 +
         *(longlong *)(param_1 + 0x40)) = 0;
        UNLOCK();
      }
      if (*(char *)(lVar8 + 0x214) == '\x01') {
        *(byte *)((longlong)puVar13 + 0x2a) = *(byte *)((longlong)puVar13 + 0x2a) | 0x80;
        *(byte *)((longlong)puVar13 + 0x2b) = *(byte *)(puVar13 + 3);
        uVar15 = CONCAT11(*(undefined1 *)((longlong)puVar13 + 0x25),
                          *(undefined1 *)((longlong)puVar13 + 0x24)) & 0xfff;
        if (uVar15 != 0) {
          FUN_00015e28(*(byte *)(puVar13 + 3),(longlong)(puVar13 + 6),
                       *(ushort *)((longlong)puVar13 + 0x2c) & 0xfff,uVar15);
        }
      }
      iVar11 = (*(byte *)((longlong)puVar13 + 0x25) & 0xf) * 0x100;
      local_74 = local_74 + iVar11 + (uint)*(byte *)((longlong)puVar13 + 0x24);
      bVar3 = *(byte *)((longlong)puVar13 + 0x2e);
      uVar17 = uVar17 - (iVar11 + (uint)*(byte *)((longlong)puVar13 + 0x24));
      *param_6 = bVar3 >> 4;
      *param_7 = *(undefined1 *)((longlong)puVar13 + 0x17);
      if (local_res8 == local_6c) {
        *(byte *)(param_3 + 0x12) = bVar3 & 0xf;
        *(byte *)(param_3 + 0x13) = *(byte *)((longlong)puVar13 + 0x2e) >> 4;
        *(undefined1 *)(param_3 + 0x14) = *(undefined1 *)((longlong)puVar13 + 0x17);
        FUN_00017da0(param_1,(longlong)param_2,param_3);
      }
      if ((*(char *)(*(longlong *)(lVar7 + 8) + 5) == '\a') && (bVar18 == 2)) {
        for (puVar12 = *(undefined8 **)(lVar8 + 0xef8); puVar12 != (undefined8 *)(lVar8 + 0xef8);
            puVar12 = (undefined8 *)*puVar12) {
          if ((((char *)(puVar12 + -1) != (char *)0x0) &&
              (*(char *)(puVar12 + -1) == *(char *)(lVar6 + 0x24))) &&
             ((*(char *)((longlong)puVar12 + -7) == *(char *)(local_50 + 2) &&
              (*(char *)(puVar12 + 2) == '\0')))) {
            *(undefined2 *)((longlong)puVar12 + -6) = 0;
            *(undefined1 *)(puVar12 + 2) = 1;
            FUN_000121dc();
            break;
          }
        }
      }
      local_res8 = local_res8 + 1;
      uVar16 = (uint)local_res8;
    } while (local_res8 < bVar14);
  }
  if (cVar2 == '\b') {
    KeClearEvent((ulonglong)*(byte *)(lVar6 + 0x24) * 0x268 + 0x10c0 + lVar8);
  }
  cVar4 = *(char *)(*(longlong *)(lVar7 + 8) + 5);
  if (cVar4 == '\a') {
    piVar1 = (int *)((ulonglong)*(byte *)(lVar6 + 0x24) * 0x268 + 0x103b + lVar8);
    *piVar1 = *piVar1 + 1;
  }
  else if (((*(int *)(local_68 + 0x24) == 0x1f) && (cVar4 == '\b')) &&
          (*(char *)((longlong)puVar13 + 0x3f) != '\0')) {
    piVar1 = (int *)((ulonglong)*(byte *)(lVar6 + 0x24) * 0x268 + 0x1037 + lVar8);
    *piVar1 = *piVar1 + 1;
  }
  piVar1 = (int *)((ulonglong)*(byte *)(lVar6 + 0x24) * 0x268 + 0x1033 + lVar8);
  *piVar1 = *piVar1 + 1;
  iVar11 = FUN_0003d284(param_1,*(byte *)(lVar6 + 0x24),
                        *(longlong *)(lVar8 + 0x1e70 + (ulonglong)*(byte *)(lVar6 + 0x24) * 0x30),
                        param_4,(uint)*(ushort *)(lVar8 + 0x2000) * (uint)bVar14,&local_70);
  if (cVar2 == '\b') {
    KeSetEvent((ulonglong)*(byte *)(lVar6 + 0x24) * 0x268 + 0x10c0 + lVar8,0,0);
  }
  if (iVar11 == 0) {
    if (local_70 == (uint)*(ushort *)(lVar8 + 0x2000) * (uint)bVar14) {
      iVar11 = 0x103;
      goto LAB_00019af0;
    }
  }
  else if ((iVar11 == -0x3fffff4b) || (iVar11 == -0x3ffffdf4)) goto LAB_00019af0;
  iVar11 = -0x3fffffff;
LAB_00019af0:
  FUN_00021370(iVar11);
  FUN_000121dc();
  return iVar11;
}



/* ===== FUNC FUN_00019b40 @ 00019b40 ===== */

undefined4
FUN_00019b40(longlong param_1,longlong param_2,longlong param_3,byte param_4,undefined2 param_5,
            ulonglong *param_6)

{
  ulonglong *puVar1;
  int *piVar2;
  ushort *puVar3;
  int iVar4;
  longlong lVar5;
  ushort uVar6;
  short sVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  longlong lVar11;
  ulonglong uVar12;
  longlong lVar13;
  void *_Src;
  byte bVar14;
  longlong lVar15;
  uint *puVar16;
  ushort uVar17;
  ushort uVar18;
  ulonglong *puVar19;
  byte bVar20;
  byte bVar21;
  ulonglong uVar22;
  short *psVar23;
  uint uVar24;
  char *pcVar25;
  ushort uVar26;
  undefined4 uVar27;
  
  lVar5 = *(longlong *)(param_1 + 0x40);
  uVar26 = 0;
  FUN_000121dc();
  pcVar25 = *(char **)(param_3 + 0x80);
  lVar13 = *(longlong *)(*(longlong *)(param_3 + 0xb8) + 8);
  if ((*(int *)(lVar13 + 0x24) == 0) || (*(int *)(lVar13 + 0x84) == 0)) {
    if (pcVar25 != (char *)0x0) {
      ExFreePoolWithTag(pcVar25,0x53747345);
    }
    uVar27 = *(undefined4 *)(lVar13 + 0x84);
    *(undefined4 *)(lVar13 + 4) = 0;
    FUN_000121dc();
    FUN_00017594(param_3,-0x3fffffff);
    KeReleaseSemaphore(param_2 + 0x98,0,1,0,uVar27);
    goto LAB_0001a2d0;
  }
  uVar17 = *(ushort *)(lVar5 + 0x2000);
  lVar15 = *(longlong *)(param_3 + 0x78);
  lVar11 = FUN_00018ef0(param_1,lVar13);
  FUN_000251f0(param_6,0,(ulonglong)uVar17);
  FUN_0001b110(param_1,lVar13,lVar15,param_6);
  *(undefined1 *)((longlong)param_6 + 0x17) = 0x16;
  *(byte *)((longlong)param_6 + 0x2d) = *(byte *)((longlong)param_6 + 0x2d) & 0xf0;
  *(undefined1 *)(param_6 + 5) = 0;
  *(undefined1 *)((longlong)param_6 + 0x29) = 0;
  *(char *)((longlong)param_6 + 0x2c) = (char)param_5;
  uVar17 = 0;
  *(byte *)((longlong)param_6 + 0x2d) =
       *(byte *)((longlong)param_6 + 0x2d) | (byte)((ushort)param_5 >> 8) & 0xf;
  bVar14 = *(byte *)(lVar15 + 0x24);
  if (bVar14 < 2) {
LAB_00019cf4:
    if ((bVar14 == 1) && (*(char *)(lVar15 + 0x41) == '\x02')) {
LAB_00019cfe:
      *(undefined1 *)(param_6 + 5) = 2;
    }
  }
  else {
    if (*(char *)(lVar15 + 0x40) != '\x02') {
      bVar14 = *(byte *)(lVar15 + 0x24);
      goto LAB_00019cf4;
    }
    if (*(char *)(lVar15 + 0x41) != '\0') goto LAB_00019cfe;
    *(undefined1 *)((longlong)param_6 + 0x2c) = 0xbc;
    uVar18 = 0;
    *(byte *)((longlong)param_6 + 0x2d) = *(byte *)((longlong)param_6 + 0x2d) & 0xf0;
    uVar24 = 0;
    if (*(int *)(lVar13 + 0x84) == 0) {
LAB_00019ce9:
      *(undefined1 *)(param_6 + 5) = 0x10;
    }
    else {
      uVar8 = *(int *)(lVar13 + 0x84) - 1;
      psVar23 = (short *)(lVar13 + 0x8c);
      do {
        if (uVar24 < uVar8) {
          uVar6 = psVar23[6] - *psVar23;
        }
        else {
          uVar6 = *(short *)(lVar13 + 0x24) - *(short *)(lVar13 + 0x8c + (ulonglong)uVar8 * 0xc);
        }
        if (uVar18 < uVar6) {
          uVar18 = uVar6;
        }
        uVar24 = uVar24 + 1;
        psVar23 = psVar23 + 6;
      } while (uVar24 < *(uint *)(lVar13 + 0x84));
      if (uVar18 < 0x26d) {
        if (uVar18 < 499) {
          if (uVar18 < 0x179) {
            if (uVar18 < 0xbd) goto LAB_00019ce9;
            *(undefined1 *)(param_6 + 5) = 0x30;
          }
          else {
            *(undefined1 *)(param_6 + 5) = 0x70;
          }
        }
        else {
          *(undefined1 *)(param_6 + 5) = 0xf0;
        }
      }
      else {
        *(undefined1 *)(param_6 + 5) = 0xf8;
      }
      uVar17 = 0x4000;
    }
  }
  puVar1 = param_6 + 6;
  uVar22 = 0;
  puVar19 = puVar1;
  for (lVar15 = 0x20; lVar15 != 0; lVar15 = lVar15 + -1) {
    *(ushort *)puVar19 = uVar17;
    puVar19 = (ulonglong *)((longlong)puVar19 + 2);
  }
  bVar14 = *(char *)(lVar13 + 0x84) - pcVar25[4];
  puVar16 = (uint *)(lVar13 + 0x8c + (ulonglong)bVar14 * 0xc);
  uVar24 = *puVar16;
  if (*(uint *)(pcVar25 + 4) < (uint)param_4) {
    bVar20 = pcVar25[4];
    *(byte *)((longlong)param_6 + 0x1e) = bVar20;
    if (*(int *)(pcVar25 + 4) != 0) {
      uVar8 = 0;
      do {
        if (uVar8 + bVar14 < (uint)(byte)(*(char *)(lVar13 + 0x84) - 1)) {
          uVar12 = uVar22 + bVar14;
          puVar3 = (ushort *)((longlong)param_6 + uVar22 * 2 + 0x30);
          *puVar3 = *puVar3 | *(short *)(lVar13 + 0x98 + uVar12 * 0xc) -
                              *(short *)(lVar13 + 0x8c + uVar12 * 0xc);
          sVar7 = *(short *)(lVar13 + 0x98 + uVar12 * 0xc);
        }
        else {
          puVar3 = (ushort *)((longlong)param_6 + uVar22 * 2 + 0x30);
          *puVar3 = *puVar3 | *(short *)(lVar13 + 0x24) -
                              *(short *)(lVar13 + 0x8c +
                                        (ulonglong)(*(int *)(lVar13 + 0x84) - 1) * 0xc);
          uVar12 = (ulonglong)(*(int *)(lVar13 + 0x84) - 1);
          sVar7 = *(short *)(lVar13 + 0x24);
        }
        bVar21 = (char)uVar22 + 1;
        uVar22 = (ulonglong)bVar21;
        uVar26 = uVar26 + (sVar7 - *(short *)(lVar13 + 0x8c + uVar12 * 0xc));
        uVar8 = (uint)bVar21;
      } while (uVar8 < *(uint *)(pcVar25 + 4));
    }
    *(short *)((longlong)param_6 + 0x24) = (short)param_6[6];
    memcpy(param_6 + 0xe,(void *)((ulonglong)uVar24 + lVar11),(ulonglong)uVar26);
    ExFreePoolWithTag(pcVar25,0x53747345);
    *(undefined4 *)(lVar13 + 4) = 0;
    lVar13 = FUN_000121dc();
    FUN_00017594(lVar13,0);
    param_3 = IoCsqRemoveNextIrp(param_2 + 0x58,0);
    if (param_3 != 0) {
      bVar14 = param_4 - *(char *)((longlong)param_6 + 0x1e);
      pcVar25 = *(char **)(param_3 + 0x80);
      lVar13 = *(longlong *)(*(longlong *)(param_3 + 0xb8) + 8);
      _Src = (void *)FUN_00018ef0(param_1,lVar13);
      uVar8 = (uint)bVar14;
      uVar24 = (uint)bVar14;
      FUN_000121dc();
      if (*(uint *)(pcVar25 + 4) <= uVar8) {
        FUN_000121dc();
        bVar14 = pcVar25[4];
        *(char *)((longlong)param_6 + 0x1e) = *(char *)((longlong)param_6 + 0x1e) + bVar14;
        uVar8 = (uint)bVar20 + (uint)bVar14;
        uVar24 = 0;
        uVar17 = 0;
        if (bVar20 < uVar8) {
          psVar23 = (short *)(lVar13 + 0x8c);
          do {
            uVar9 = *(int *)(lVar13 + 0x84) - 1;
            if (uVar24 < uVar9) {
              puVar3 = (ushort *)((longlong)param_6 + (ulonglong)bVar20 * 2 + 0x30);
              *puVar3 = *puVar3 | psVar23[6] - *psVar23;
              sVar7 = psVar23[6] - *psVar23;
            }
            else {
              puVar3 = (ushort *)((longlong)param_6 + (ulonglong)bVar20 * 2 + 0x30);
              *puVar3 = *puVar3 | *(short *)(lVar13 + 0x24) -
                                  *(short *)(lVar13 + 0x8c + (ulonglong)uVar9 * 0xc);
              sVar7 = *(short *)(lVar13 + 0x24) -
                      *(short *)(lVar13 + 0x8c + (ulonglong)(*(int *)(lVar13 + 0x84) - 1) * 0xc);
            }
            bVar20 = bVar20 + 1;
            uVar17 = uVar17 + sVar7;
            uVar24 = uVar24 + 1;
            psVar23 = psVar23 + 6;
          } while (bVar20 < uVar8);
        }
        *(short *)((longlong)param_6 + 0x24) = (short)param_6[6];
        memcpy((void *)((ulonglong)uVar26 + 0x70 + (longlong)param_6),_Src,(ulonglong)uVar17);
        uVar26 = uVar26 + uVar17;
        ExFreePoolWithTag(pcVar25,0x53747345);
        *(undefined4 *)(lVar13 + 4) = 0;
        lVar13 = FUN_000121dc();
        goto LAB_00019e7c;
      }
      *(char *)((longlong)param_6 + 0x1e) = *(char *)((longlong)param_6 + 0x1e) + (char)uVar8;
      uVar9 = 0;
      uVar8 = (uint)bVar20;
      uVar17 = 0;
      if ((int)(uint)bVar20 < (int)(uVar8 + uVar24)) {
        psVar23 = (short *)(lVar13 + 0x8c);
        do {
          uVar10 = *(int *)(lVar13 + 0x84) - 1;
          if (uVar9 < uVar10) {
            puVar3 = (ushort *)((longlong)param_6 + (ulonglong)bVar20 * 2 + 0x30);
            *puVar3 = *puVar3 | psVar23[6] - *psVar23;
            sVar7 = psVar23[6] - *psVar23;
          }
          else {
            puVar3 = (ushort *)((longlong)param_6 + (ulonglong)bVar20 * 2 + 0x30);
            *puVar3 = *puVar3 | *(short *)(lVar13 + 0x24) -
                                *(short *)(lVar13 + 0x8c + (ulonglong)uVar10 * 0xc);
            sVar7 = *(short *)(lVar13 + 0x24) -
                    *(short *)(lVar13 + 0x8c + (ulonglong)(*(int *)(lVar13 + 0x84) - 1) * 0xc);
          }
          bVar20 = bVar20 + 1;
          uVar17 = uVar17 + sVar7;
          uVar9 = uVar9 + 1;
          psVar23 = psVar23 + 6;
        } while ((int)(uint)bVar20 < (int)(uVar8 + uVar24));
      }
      *(short *)((longlong)param_6 + 0x24) = (short)param_6[6];
      memcpy((void *)((ulonglong)uVar26 + 0x70 + (longlong)param_6),_Src,(ulonglong)uVar17);
      uVar26 = uVar26 + uVar17;
      if (*(int *)(pcVar25 + 4) != 0) {
        bVar14 = pcVar25[4] - bVar14;
        goto LAB_00019e09;
      }
    }
  }
  else {
    *(byte *)((longlong)param_6 + 0x1e) = param_4;
    if (param_4 != 0) {
      puVar19 = puVar1;
      do {
        if ((int)uVar22 + (uint)bVar14 < (uint)(byte)(*(char *)(lVar13 + 0x84) - 1)) {
          *(ushort *)puVar19 = (ushort)*puVar19 | (short)puVar16[3] - (short)*puVar16;
          sVar7 = (short)puVar16[3] - (short)*puVar16;
        }
        else {
          *(ushort *)puVar19 =
               (ushort)*puVar19 |
               *(short *)(lVar13 + 0x24) -
               *(short *)(lVar13 + 0x8c + (ulonglong)(*(int *)(lVar13 + 0x84) - 1) * 0xc);
          sVar7 = *(short *)(lVar13 + 0x24) -
                  *(short *)(lVar13 + 0x8c + (ulonglong)(*(int *)(lVar13 + 0x84) - 1) * 0xc);
        }
        bVar20 = (char)uVar22 + 1;
        uVar22 = (ulonglong)bVar20;
        uVar26 = uVar26 + sVar7;
        puVar16 = puVar16 + 3;
        puVar19 = (ulonglong *)((longlong)puVar19 + 2);
      } while (bVar20 < param_4);
    }
    *(ushort *)((longlong)param_6 + 0x24) = (ushort)*puVar1;
    memcpy(param_6 + 0xe,(void *)((ulonglong)uVar24 + lVar11),(ulonglong)uVar26);
    if (*(int *)(pcVar25 + 4) == 0) {
      ExFreePoolWithTag(pcVar25,0x53747345);
      *(undefined4 *)(lVar13 + 4) = 0;
      FUN_000121dc();
      lVar13 = 0;
LAB_00019e7c:
      FUN_00017594(lVar13,0);
    }
    else {
      bVar14 = pcVar25[4] - *(char *)((longlong)param_6 + 0x1e);
LAB_00019e09:
      FUN_00020bec(param_1,param_3,'\0',bVar14,*(byte *)(param_2 + 0x18),pcVar25);
      KeSetEvent((ulonglong)*(byte *)(param_2 + 0x18) * 0xf8 + 0xad8 + lVar5,0,0);
    }
  }
  if (uVar26 != 0) {
    do {
      LOCK();
      piVar2 = (int *)(lVar5 + 0x210);
      iVar4 = *piVar2;
      *piVar2 = *piVar2 + 1;
      UNLOCK();
      sVar7 = (short)iVar4 + 1;
    } while (sVar7 == 0);
    *(short *)(param_6 + 3) = sVar7;
    FUN_000121dc();
    return 0;
  }
  FUN_000121dc();
  KeReleaseSemaphore(param_2 + 0x98,0,1,0);
LAB_0001a2d0:
  FUN_000121dc();
  return 0xc0000001;
}



/* ===== FUNC FUN_0001a308 @ 0001a308 ===== */

undefined4
FUN_0001a308(longlong param_1,longlong *param_2,longlong param_3,byte param_4,undefined2 param_5,
            ulonglong *param_6)

{
  longlong *plVar1;
  ushort *puVar2;
  int iVar3;
  longlong lVar4;
  longlong lVar5;
  byte bVar6;
  ushort uVar7;
  short sVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  longlong lVar12;
  longlong lVar13;
  void *_Src;
  ushort uVar14;
  longlong lVar15;
  int iVar16;
  ulonglong *puVar17;
  short *psVar18;
  uint *puVar19;
  int *piVar20;
  byte bVar21;
  uint uVar22;
  ulonglong *puVar23;
  byte bVar24;
  void *_Src_00;
  ushort uVar25;
  char *pcVar26;
  undefined8 in_stack_ffffffffffffff78;
  undefined4 uVar28;
  undefined8 uVar27;
  ushort local_78;
  uint local_74;
  
  uVar28 = (undefined4)((ulonglong)in_stack_ffffffffffffff78 >> 0x20);
  lVar4 = *param_2;
  plVar1 = param_2 + 0x13;
  KeReadStateSemaphore(plVar1);
  bVar6 = FUN_000121dc();
  local_74 = 10;
  if (9 < bVar6) {
    local_74 = (bVar6 < 0x14) + 8;
  }
  pcVar26 = *(char **)(param_3 + 0x80);
  lVar13 = *(longlong *)(*(longlong *)(param_3 + 0xb8) + 8);
  if ((*(int *)(lVar13 + 0x24) == 0) || (*(int *)(lVar13 + 0x84) == 0)) {
    if (pcVar26 != (char *)0x0) {
      ExFreePoolWithTag(pcVar26,0x53747345);
    }
    *(undefined4 *)(lVar13 + 4) = 0;
    uVar27 = CONCAT44(uVar28,*(undefined4 *)(lVar13 + 0x84));
    FUN_000121dc();
    FUN_00017534(param_3,-0x3fffffff);
    KeReleaseSemaphore(plVar1,0,1,0,uVar27);
    goto LAB_0001abf7;
  }
  uVar25 = *(ushort *)(lVar4 + 0x2000);
  lVar15 = *(longlong *)(*(longlong *)(lVar13 + 0x18) + 0x10);
  lVar5 = *(longlong *)(param_3 + 0x78);
  lVar12 = FUN_00018ef0(param_1,lVar13);
  FUN_000251f0(param_6,0,(ulonglong)uVar25);
  FUN_0001b270(param_1,lVar13,lVar5,param_6,lVar15);
  *(undefined1 *)((longlong)param_6 + 0x17) = 0x16;
  *(byte *)((longlong)param_6 + 0x2d) = *(byte *)((longlong)param_6 + 0x2d) & 0xf0;
  *(undefined1 *)(param_6 + 5) = 0;
  *(undefined1 *)((longlong)param_6 + 0x29) = 0;
  *(char *)((longlong)param_6 + 0x2c) = (char)param_5;
  *(byte *)((longlong)param_6 + 0x2d) =
       *(byte *)((longlong)param_6 + 0x2d) | (byte)((ushort)param_5 >> 8) & 0xf;
  bVar6 = *(byte *)(lVar5 + 0x24);
  uVar25 = 0;
  if (bVar6 < 2) {
LAB_0001a511:
    if ((bVar6 == 1) && (*(char *)(lVar5 + 0x41) == '\x02')) {
LAB_0001a519:
      *(undefined1 *)(param_6 + 5) = 2;
    }
  }
  else {
    if (*(char *)(lVar5 + 0x40) != '\x02') {
      bVar6 = *(byte *)(lVar5 + 0x24);
      goto LAB_0001a511;
    }
    if (*(char *)(lVar5 + 0x41) != '\0') goto LAB_0001a519;
    *(undefined1 *)((longlong)param_6 + 0x2c) = 0xbc;
    uVar14 = 0;
    *(byte *)((longlong)param_6 + 0x2d) = *(byte *)((longlong)param_6 + 0x2d) & 0xf0;
    uVar22 = 0;
    if (*(int *)(lVar13 + 0x84) == 0) {
LAB_0001a508:
      *(undefined1 *)(param_6 + 5) = 0x10;
    }
    else {
      uVar9 = *(int *)(lVar13 + 0x84) - 1;
      psVar18 = (short *)(lVar13 + 0x8c);
      do {
        if (uVar22 < uVar9) {
          uVar7 = psVar18[6] - *psVar18;
        }
        else {
          uVar7 = *(short *)(lVar13 + 0x24) - *(short *)(lVar13 + 0x8c + (ulonglong)uVar9 * 0xc);
        }
        if (uVar14 < uVar7) {
          uVar14 = uVar7;
        }
        uVar22 = uVar22 + 1;
        psVar18 = psVar18 + 6;
      } while (uVar22 < *(uint *)(lVar13 + 0x84));
      if (uVar14 < 0x26d) {
        if (uVar14 < 499) {
          if (uVar14 < 0x179) {
            if (uVar14 < 0xbd) goto LAB_0001a508;
            *(undefined1 *)(param_6 + 5) = 0x30;
          }
          else {
            *(undefined1 *)(param_6 + 5) = 0x70;
          }
        }
        else {
          *(undefined1 *)(param_6 + 5) = 0xf0;
        }
      }
      else {
        *(undefined1 *)(param_6 + 5) = 0xf8;
      }
      uVar25 = 0x4000;
    }
  }
  puVar23 = param_6 + 6;
  puVar17 = puVar23;
  for (lVar15 = 0x20; lVar15 != 0; lVar15 = lVar15 + -1) {
    *(ushort *)puVar17 = uVar25;
    puVar17 = (ulonglong *)((longlong)puVar17 + 2);
  }
  local_78 = 0;
  bVar6 = *(char *)(lVar13 + 0x84) - pcVar26[4];
  puVar19 = (uint *)(lVar13 + 0x8c + (ulonglong)bVar6 * 0xc);
  uVar22 = *puVar19;
  if (*(uint *)(pcVar26 + 4) < (uint)param_4) {
    bVar24 = pcVar26[4];
    local_78 = 0;
    bVar21 = 0;
    *(byte *)((longlong)param_6 + 0x1e) = bVar24;
    if (*(int *)(pcVar26 + 4) != 0) {
      uVar9 = 0;
      do {
        if (uVar9 + bVar6 < (uint)(byte)(*(char *)(lVar13 + 0x84) - 1)) {
          lVar15 = (ulonglong)bVar21 + (ulonglong)bVar6;
          iVar16 = *(int *)(lVar13 + 0x98 + lVar15 * 0xc) - *(int *)(lVar13 + 0x8c + lVar15 * 0xc);
          puVar2 = (ushort *)((longlong)param_6 + (ulonglong)bVar21 * 2 + 0x30);
          uVar25 = (ushort)iVar16;
          *puVar2 = *puVar2 | uVar25;
          *(undefined4 *)(lVar13 + 0x94 + lVar15 * 0xc) = 0;
          *(int *)(lVar13 + (lVar15 * 3 + 0x24) * 4) = iVar16;
        }
        else {
          iVar16 = *(int *)(lVar13 + 0x24) -
                   *(int *)(lVar13 + 0x8c + (ulonglong)(*(int *)(lVar13 + 0x84) - 1) * 0xc);
          puVar2 = (ushort *)((longlong)param_6 + (ulonglong)bVar21 * 2 + 0x30);
          uVar25 = (ushort)iVar16;
          *puVar2 = *puVar2 | uVar25;
          *(int *)(lVar13 + ((ulonglong)(*(int *)(lVar13 + 0x84) - 1) * 3 + 0x24) * 4) = iVar16;
          *(undefined4 *)(lVar13 + 0x94 + (ulonglong)(*(int *)(lVar13 + 0x84) - 1) * 0xc) = 0;
        }
        local_78 = local_78 + uVar25;
        bVar21 = bVar21 + 1;
        uVar9 = (uint)bVar21;
      } while (uVar9 < *(uint *)(pcVar26 + 4));
    }
    *(short *)((longlong)param_6 + 0x24) = (short)param_6[6];
    memcpy(param_6 + 0xe,(void *)((ulonglong)uVar22 + lVar12),(ulonglong)local_78);
    uVar22 = *(uint *)(lVar13 + 0x84);
    if (*(char *)(lVar5 + 0x41) == '\x02') {
      uVar22 = uVar22 >> 3;
    }
    *(int *)((longlong)param_2 + 0xd4) = *(int *)((longlong)param_2 + 0xd4) + uVar22;
    *(undefined4 *)(lVar13 + 0x80) = *(undefined4 *)((longlong)param_2 + 0xd4);
    pcVar26[8] = '\x01';
    pcVar26[4] = '\0';
    pcVar26[5] = '\0';
    pcVar26[6] = '\0';
    pcVar26[7] = '\0';
    FUN_000120dc(local_74);
    ExFreePoolWithTag(pcVar26);
    FUN_00017534(param_3,0);
    lVar13 = IoCsqRemoveNextIrp(param_2 + 0xb,0);
    if (lVar13 != 0) {
      pcVar26 = *(char **)(lVar13 + 0x80);
      bVar6 = param_4 - *(char *)((longlong)param_6 + 0x1e);
      lVar15 = *(longlong *)(*(longlong *)(lVar13 + 0xb8) + 8);
      _Src = (void *)FUN_00018ef0(param_1,lVar15);
      uVar22 = (uint)bVar6;
      lVar5 = *(longlong *)(lVar13 + 0x78);
      _Src_00 = _Src;
      FUN_000121dc();
      if (uVar22 < *(uint *)(pcVar26 + 4)) {
        uVar10 = 0;
        uVar25 = 0;
        *(char *)((longlong)param_6 + 0x1e) = *(char *)((longlong)param_6 + 0x1e) + bVar6;
        uVar9 = (uint)bVar24;
        if ((int)(uint)bVar24 < (int)(uVar9 + uVar22)) {
          piVar20 = (int *)(lVar15 + 0x8c);
          do {
            uVar11 = *(int *)(lVar15 + 0x84) - 1;
            if (uVar10 < uVar11) {
              iVar16 = piVar20[3];
              iVar3 = *piVar20;
              puVar2 = (ushort *)((longlong)param_6 + (ulonglong)bVar24 * 2 + 0x30);
              uVar14 = (ushort)(iVar16 - iVar3);
              *puVar2 = *puVar2 | uVar14;
              piVar20[1] = iVar16 - iVar3;
              piVar20[2] = 0;
            }
            else {
              iVar16 = *(int *)(lVar15 + 0x24) - *(int *)(lVar15 + 0x8c + (ulonglong)uVar11 * 0xc);
              puVar2 = (ushort *)((longlong)param_6 + (ulonglong)bVar24 * 2 + 0x30);
              uVar14 = (ushort)iVar16;
              *puVar2 = *puVar2 | uVar14;
              *(int *)(lVar15 + ((ulonglong)(*(int *)(lVar15 + 0x84) - 1) * 3 + 0x24) * 4) = iVar16;
              *(undefined4 *)(lVar15 + 0x94 + (ulonglong)(*(int *)(lVar15 + 0x84) - 1) * 0xc) = 0;
            }
            uVar25 = uVar25 + uVar14;
            bVar24 = bVar24 + 1;
            uVar10 = uVar10 + 1;
            piVar20 = piVar20 + 3;
          } while ((int)(uint)bVar24 < (int)(uVar9 + uVar22));
        }
        *(short *)((longlong)param_6 + 0x24) = (short)param_6[6];
        memcpy((void *)((ulonglong)(uint)local_78 + 0x70 + (longlong)param_6),_Src,(ulonglong)uVar25
              );
        local_78 = local_78 + uVar25;
        if (*(int *)(pcVar26 + 4) != 0) {
          bVar6 = pcVar26[4] - bVar6;
          goto LAB_0001a64c;
        }
      }
      else {
        FUN_000121dc();
        bVar6 = pcVar26[4];
        *(char *)((longlong)param_6 + 0x1e) = *(char *)((longlong)param_6 + 0x1e) + bVar6;
        uVar9 = (uint)bVar24 + (uint)bVar6;
        uVar22 = 0;
        uVar25 = 0;
        if (bVar24 < uVar9) {
          piVar20 = (int *)(lVar15 + 0x8c);
          do {
            uVar10 = *(int *)(lVar15 + 0x84) - 1;
            if (uVar22 < uVar10) {
              iVar16 = piVar20[3];
              iVar3 = *piVar20;
              puVar2 = (ushort *)((longlong)param_6 + (ulonglong)bVar24 * 2 + 0x30);
              uVar14 = (ushort)(iVar16 - iVar3);
              *puVar2 = *puVar2 | uVar14;
              piVar20[1] = iVar16 - iVar3;
              piVar20[2] = 0;
            }
            else {
              iVar16 = *(int *)(lVar15 + 0x24) - *(int *)(lVar15 + 0x8c + (ulonglong)uVar10 * 0xc);
              puVar2 = (ushort *)((longlong)param_6 + (ulonglong)bVar24 * 2 + 0x30);
              uVar14 = (ushort)iVar16;
              *puVar2 = *puVar2 | uVar14;
              *(int *)(lVar15 + ((ulonglong)(*(int *)(lVar15 + 0x84) - 1) * 3 + 0x24) * 4) = iVar16;
              *(undefined4 *)(lVar15 + 0x94 + (ulonglong)(*(int *)(lVar15 + 0x84) - 1) * 0xc) = 0;
            }
            uVar25 = uVar25 + uVar14;
            bVar24 = bVar24 + 1;
            uVar22 = uVar22 + 1;
            piVar20 = piVar20 + 3;
          } while (bVar24 < uVar9);
        }
        *(short *)((longlong)param_6 + 0x24) = (short)param_6[6];
        memcpy((void *)((ulonglong)(uint)local_78 + 0x70 + (longlong)param_6),_Src_00,
               (ulonglong)uVar25);
        local_78 = local_78 + uVar25;
        uVar22 = *(uint *)(lVar15 + 0x84);
        if (*(char *)(lVar5 + 0x41) == '\x02') {
          uVar22 = uVar22 >> 3;
        }
        *(int *)((longlong)param_2 + 0xd4) = *(int *)((longlong)param_2 + 0xd4) + uVar22;
        *(undefined4 *)(lVar15 + 0x80) = *(undefined4 *)((longlong)param_2 + 0xd4);
        pcVar26[8] = '\x01';
        FUN_000120dc(local_74);
        ExFreePoolWithTag(pcVar26);
        FUN_00017534(param_3,0);
      }
    }
  }
  else {
    *(byte *)((longlong)param_6 + 0x1e) = param_4;
    uVar9 = 0;
    if (param_4 != 0) {
      do {
        if (uVar9 + bVar6 < (uint)(byte)(*(char *)(lVar13 + 0x84) - 1)) {
          uVar10 = puVar19[3];
          uVar11 = *puVar19;
          uVar25 = (ushort)(uVar10 - uVar11);
          *(ushort *)puVar23 = (ushort)*puVar23 | uVar25;
          puVar19[1] = uVar10 - uVar11;
          puVar19[2] = 0;
        }
        else {
          iVar16 = *(int *)(lVar13 + 0x24) -
                   *(int *)(lVar13 + 0x8c + (ulonglong)(*(int *)(lVar13 + 0x84) - 1) * 0xc);
          uVar25 = (ushort)iVar16;
          *(ushort *)puVar23 = (ushort)*puVar23 | uVar25;
          *(int *)(lVar13 + ((ulonglong)(*(int *)(lVar13 + 0x84) - 1) * 3 + 0x24) * 4) = iVar16;
          *(undefined4 *)(lVar13 + 0x94 + (ulonglong)(*(int *)(lVar13 + 0x84) - 1) * 0xc) = 0;
        }
        local_78 = local_78 + uVar25;
        bVar24 = (char)uVar9 + 1;
        uVar9 = (uint)bVar24;
        puVar19 = puVar19 + 3;
        puVar23 = (ulonglong *)((longlong)puVar23 + 2);
      } while (bVar24 < param_4);
    }
    *(short *)((longlong)param_6 + 0x24) = (short)param_6[6];
    memcpy(param_6 + 0xe,(void *)((ulonglong)uVar22 + lVar12),(ulonglong)local_78);
    if (*(uint *)(pcVar26 + 4) == (uint)*(byte *)((longlong)param_6 + 0x1e)) {
      uVar22 = *(uint *)(lVar13 + 0x84);
      if (*(char *)(lVar5 + 0x41) == '\x02') {
        uVar22 = uVar22 >> 3;
      }
      *(int *)((longlong)param_2 + 0xd4) = *(int *)((longlong)param_2 + 0xd4) + uVar22;
      *(undefined4 *)(lVar13 + 0x80) = *(undefined4 *)((longlong)param_2 + 0xd4);
      pcVar26[8] = '\x01';
      pcVar26[4] = '\0';
      pcVar26[5] = '\0';
      pcVar26[6] = '\0';
      pcVar26[7] = '\0';
      FUN_000120dc(local_74);
      ExFreePoolWithTag(pcVar26);
      FUN_00017534(param_3,0);
    }
    else {
      bVar6 = (char)*(uint *)(pcVar26 + 4) - *(byte *)((longlong)param_6 + 0x1e);
      lVar13 = param_3;
LAB_0001a64c:
      FUN_00020bec(param_1,lVar13,'\0',bVar6,*(byte *)(param_2 + 3),pcVar26);
      KeSetEvent((ulonglong)*(byte *)(param_2 + 3) * 0xf8 + 0xad8 + lVar4,0,0);
    }
  }
  if (local_78 != 0) {
    do {
      LOCK();
      piVar20 = (int *)(lVar4 + 0x210);
      iVar16 = *piVar20;
      *piVar20 = *piVar20 + 1;
      UNLOCK();
      sVar8 = (short)iVar16 + 1;
    } while (sVar8 == 0);
    *(short *)(param_6 + 3) = sVar8;
    FUN_000121dc();
    return 0;
  }
  FUN_000121dc();
  KeReleaseSemaphore(plVar1,0,1,0);
LAB_0001abf7:
  FUN_000121dc();
  return 0xc0000001;
}



/* ===== FUNC FUN_0001ac2c @ 0001ac2c ===== */

ulonglong FUN_0001ac2c(longlong param_1,longlong param_2,byte param_3,undefined2 param_4)

{
  longlong lVar1;
  ulonglong *puVar2;
  uint uVar3;
  int iVar4;
  longlong lVar5;
  byte bVar6;
  ulonglong *puVar7;
  ulonglong uVar8;
  uint local_res8 [2];
  
  lVar1 = *(longlong *)(param_1 + 0x40);
  puVar7 = (ulonglong *)0x0;
  uVar8 = 0xc0000001;
  bVar6 = 0;
  local_res8[0] = 0;
  FUN_000121dc();
  puVar2 = *(ulonglong **)(param_2 + 0xf0);
  if (puVar2 == puVar7) {
    FUN_000121dc();
  }
  else {
    puVar7 = puVar2;
    while( true ) {
      uVar3 = KeWaitForMultipleObjects();
      uVar8 = (ulonglong)uVar3;
      if ((int)uVar3 < 0) break;
      if (uVar3 == 0) {
        FUN_000121dc();
        uVar8 = 0xc000004b;
        goto LAB_0001aea7;
      }
      if (uVar3 == 1) {
        FUN_000121dc();
        lVar5 = IoCsqRemoveNextIrp(param_2 + 0x58,0);
        if (lVar5 == 0) {
          FUN_000121dc();
          KeReleaseSemaphore(param_2 + 0x98,0,1,0);
          uVar3 = FUN_0003d284(param_1,*(byte *)(param_2 + 8),
                               *(longlong *)
                                (lVar1 + 0x1e70 + (ulonglong)*(byte *)(param_2 + 8) * 0x30),puVar2,
                               (uint)*(ushort *)(lVar1 + 0x2000) * (uint)bVar6,local_res8);
          uVar8 = (ulonglong)uVar3;
          goto LAB_0001aea7;
        }
        iVar4 = FUN_00019b40(param_1,param_2,lVar5,param_3,param_4,puVar7);
        if (iVar4 == 0) {
          bVar6 = bVar6 + 1;
          puVar7 = (ulonglong *)((longlong)puVar7 + (ulonglong)*(ushort *)(lVar1 + 0x2000));
        }
        else {
          FUN_0003d284(param_1,*(byte *)(param_2 + 8),
                       *(longlong *)(lVar1 + 0x1e70 + (ulonglong)*(byte *)(param_2 + 8) * 0x30),
                       puVar2,(uint)*(ushort *)(lVar1 + 0x2000) * (uint)bVar6,local_res8);
          bVar6 = 0;
          puVar7 = puVar2;
        }
      }
      if (3 < bVar6) {
        FUN_0003d284(param_1,*(byte *)(param_2 + 8),
                     *(longlong *)(lVar1 + 0x1e70 + (ulonglong)*(byte *)(param_2 + 8) * 0x30),puVar2
                     ,(uint)*(ushort *)(lVar1 + 0x2000) * (uint)bVar6,local_res8);
        bVar6 = 0;
        puVar7 = puVar2;
      }
    }
    FUN_000121dc();
  }
LAB_0001aea7:
  FUN_000121dc();
  return uVar8 & 0xffffffff;
}



/* ===== FUNC FUN_0001aedc @ 0001aedc ===== */

int FUN_0001aedc(longlong param_1,longlong *param_2,byte param_3,undefined2 param_4)

{
  longlong lVar1;
  ulonglong *puVar2;
  int iVar3;
  longlong lVar4;
  longlong lVar5;
  undefined4 local_res8 [2];
  longlong *in_stack_ffffffffffffff98;
  ulonglong *in_stack_ffffffffffffffa0;
  longlong *local_48;
  longlong *local_40;
  
  lVar1 = *(longlong *)(param_1 + 0x40);
  local_48 = param_2 + 4;
  iVar3 = -0x3fffffff;
  local_res8[0] = 0;
  local_40 = param_2 + 0x13;
  FUN_000121dc();
  if (param_2 != (longlong *)0x0) {
LAB_0001af3e:
    in_stack_ffffffffffffffa0 =
         (ulonglong *)((ulonglong)in_stack_ffffffffffffffa0 & 0xffffffffffffff00);
    in_stack_ffffffffffffff98 =
         (longlong *)((ulonglong)in_stack_ffffffffffffff98 & 0xffffffffffffff00);
    iVar3 = KeWaitForMultipleObjects
                      (2,&local_48,1,0,in_stack_ffffffffffffff98,in_stack_ffffffffffffffa0,0,0);
    if (-1 < iVar3) {
      if (iVar3 == 0) {
        FUN_000121dc();
        return -0x3fffffb5;
      }
      if (iVar3 == 1) {
        FUN_000121dc();
        lVar4 = IoCsqRemoveNextIrp(param_2 + 0xb,0);
        if (lVar4 == 0) {
          iVar3 = 2;
          FUN_000121dc();
          KeReleaseSemaphore(param_2 + 0x13,0,iVar3 + -1,0);
          return 1;
        }
        lVar5 = ExInterlockedPopEntryList(param_2 + 0x1c,param_2 + 0x1b);
        if (lVar5 != 0) {
          *(undefined1 *)(lVar5 + 0x10) = 1;
          ExInterlockedPushEntryList(param_2 + 0x1d,lVar5,param_2 + 0x1b);
          puVar2 = *(ulonglong **)(lVar5 + 8);
          if (puVar2 != (ulonglong *)0x0) {
            in_stack_ffffffffffffff98 =
                 (longlong *)CONCAT62((int6)((ulonglong)in_stack_ffffffffffffff98 >> 0x10),param_4);
            in_stack_ffffffffffffffa0 = puVar2;
            iVar3 = FUN_0001a308(param_1,param_2,lVar4,param_3,param_4,puVar2);
            if (iVar3 == 0) {
              in_stack_ffffffffffffffa0 = (ulonglong *)local_res8;
              in_stack_ffffffffffffff98 = param_2;
              FUN_00024788(param_1,*(longlong *)
                                    (lVar1 + 0x1e70 + (ulonglong)*(byte *)(param_2 + 1) * 0x30),
                           puVar2,(uint)*(ushort *)(lVar1 + 0x2000),param_2,
                           (undefined4 *)in_stack_ffffffffffffffa0,lVar5);
            }
            goto LAB_0001af3e;
          }
        }
        FUN_000121dc();
        IoCsqInsertIrp(param_2 + 0xb,lVar4,0);
        return 1;
      }
      goto LAB_0001af3e;
    }
    FUN_000121dc();
  }
  return iVar3;
}



/* ===== FUNC FUN_0001b110 @ 0001b110 ===== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_0001b110(undefined8 param_1,longlong param_2,longlong param_3,undefined8 *param_4)

{
  longlong lVar1;
  undefined8 uVar2;
  ushort uVar3;
  int iVar4;
  byte bVar5;
  undefined1 uVar6;
  undefined7 uVar7;
  
  uVar6 = SUB81(param_4,0);
  uVar7 = (undefined7)((ulonglong)param_4 >> 8);
  iVar4 = 3;
  FUN_000121dc();
  lVar1 = *(longlong *)(*(longlong *)(param_2 + 0x18) + 0x10);
  FUN_000251f0((ulonglong *)CONCAT71(uVar7,uVar6),0,(ulonglong)(iVar4 + 0x2d));
  uVar2 = _UNK_00035c88;
  *param_4 = _DAT_00035c80;
  param_4[1] = uVar2;
  *(undefined4 *)(param_4 + 2) = 0x24544e55;
  bVar5 = *(byte *)(lVar1 + 3);
  *(undefined1 *)((longlong)param_4 + 0x16) = *(undefined1 *)(param_3 + 0x24);
  bVar5 = bVar5 & 3;
  uVar6 = *(undefined1 *)(*(longlong *)(param_2 + 0x18) + 0x48);
  *(byte *)((longlong)param_4 + 0x25) = *(byte *)((longlong)param_4 + 0x25) & 0x3f;
  *(undefined1 *)(param_4 + 4) = uVar6;
  if (bVar5 == 1) {
    *(byte *)((longlong)param_4 + 0x25) = *(byte *)((longlong)param_4 + 0x25) | 0x40;
  }
  *(undefined1 *)((longlong)param_4 + 0x22) = 0x30;
  if ((bVar5 == 1) && ((*(byte *)(lVar1 + 2) & 0x80) == 0)) {
    *(char *)((longlong)param_4 + 0x24) = *(char *)(param_2 + 0x98) - *(char *)(param_2 + 0x8c);
    *(byte *)((longlong)param_4 + 0x25) =
         *(byte *)((longlong)param_4 + 0x25) ^
         ((byte)((uint)(*(int *)(param_2 + 0x98) - *(int *)(param_2 + 0x8c)) >> 8) ^
         *(byte *)((longlong)param_4 + 0x25)) & 0xf;
  }
  *(undefined1 *)((longlong)param_4 + 0x23) = 0xf0;
  uVar3 = *(ushort *)(lVar1 + 4);
  *(byte *)((longlong)param_4 + 0x2d) = *(byte *)((longlong)param_4 + 0x2d) & 0xf0;
  uVar3 = uVar3 & 0x7ff;
  *(char *)((longlong)param_4 + 0x2c) = (char)uVar3;
  *(byte *)((longlong)param_4 + 0x2d) = *(byte *)((longlong)param_4 + 0x2d) | (byte)(uVar3 >> 8);
  *(byte *)((longlong)param_4 + 0x2d) =
       (*(char *)(param_3 + 0x24) + -1) * '\x10' | *(byte *)((longlong)param_4 + 0x2d) & 0xf;
  *(byte *)((longlong)param_4 + 0x2e) =
       *(byte *)((longlong)param_4 + 0x2e) ^
       (*(byte *)((longlong)param_4 + 0x2e) ^ *(byte *)(param_3 + 0x24)) & 0xf;
  *(byte *)((longlong)param_4 + 0x2e) =
       *(char *)(lVar1 + 2) << 4 | *(byte *)((longlong)param_4 + 0x2e) & 0xf;
  if ((*(byte *)(lVar1 + 2) & 0x80) == 0) {
    *(byte *)((longlong)param_4 + 0x2f) = *(byte *)((longlong)param_4 + 0x2f) & 0xf3;
  }
  else {
    *(byte *)((longlong)param_4 + 0x2f) = *(byte *)((longlong)param_4 + 0x2f) & 0xf7;
    *(byte *)((longlong)param_4 + 0x2f) = *(byte *)((longlong)param_4 + 0x2f) | 4;
  }
  if ((bVar5 == 3) && ((*(byte *)(lVar1 + 2) & 0x80) == 0)) {
    *(byte *)((longlong)param_4 + 0x2f) = *(byte *)((longlong)param_4 + 0x2f) & 0xef;
    *(byte *)((longlong)param_4 + 0x2f) = *(byte *)((longlong)param_4 + 0x2f) | 0x20;
  }
  else {
    *(byte *)((longlong)param_4 + 0x2f) = *(byte *)((longlong)param_4 + 0x2f) & 0xcf;
    *(byte *)((longlong)param_4 + 0x2f) = *(byte *)((longlong)param_4 + 0x2f) | bVar5 << 4;
  }
  return 0;
}



/* ===== FUNC FUN_0001b270 @ 0001b270 ===== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
FUN_0001b270(undefined8 param_1,undefined8 param_2,longlong param_3,ulonglong *param_4,
            longlong param_5)

{
  byte bVar1;
  ulonglong uVar2;
  ushort uVar3;
  
  FUN_000251f0(param_4,0,0x30);
  uVar2 = _UNK_00035c88;
  *param_4 = _DAT_00035c80;
  param_4[1] = uVar2;
  *(undefined4 *)(param_4 + 2) = 0x24544e55;
  bVar1 = *(byte *)(param_5 + 3);
  *(undefined1 *)((longlong)param_4 + 0x16) = *(undefined1 *)(param_3 + 0x24);
  *(byte *)((longlong)param_4 + 0x25) = *(byte *)((longlong)param_4 + 0x25) & 0x3f;
  *(byte *)((longlong)param_4 + 0x25) = *(byte *)((longlong)param_4 + 0x25) | 0x40;
  *(undefined1 *)(param_4 + 4) = 1;
  *(undefined1 *)((longlong)param_4 + 0x22) = 0x30;
  *(undefined1 *)((longlong)param_4 + 0x23) = 0xf0;
  uVar3 = *(ushort *)(param_5 + 4);
  *(byte *)((longlong)param_4 + 0x2d) = *(byte *)((longlong)param_4 + 0x2d) & 0xf0;
  uVar3 = uVar3 & 0x7ff;
  *(char *)((longlong)param_4 + 0x2c) = (char)uVar3;
  *(byte *)((longlong)param_4 + 0x2d) = *(byte *)((longlong)param_4 + 0x2d) | (byte)(uVar3 >> 8);
  *(byte *)((longlong)param_4 + 0x2d) =
       (*(char *)(param_3 + 0x24) + -1) * '\x10' | *(byte *)((longlong)param_4 + 0x2d) & 0xf;
  *(byte *)((longlong)param_4 + 0x2e) =
       *(byte *)((longlong)param_4 + 0x2e) ^
       (*(byte *)((longlong)param_4 + 0x2e) ^ *(byte *)(param_3 + 0x24)) & 0xf;
  *(byte *)((longlong)param_4 + 0x2e) =
       *(char *)(param_5 + 2) << 4 | *(byte *)((longlong)param_4 + 0x2e) & 0xf;
  if ((*(byte *)(param_5 + 2) & 0x80) == 0) {
    *(byte *)((longlong)param_4 + 0x2f) = *(byte *)((longlong)param_4 + 0x2f) & 0xf3;
  }
  else {
    *(byte *)((longlong)param_4 + 0x2f) = *(byte *)((longlong)param_4 + 0x2f) & 0xf7;
    *(byte *)((longlong)param_4 + 0x2f) = *(byte *)((longlong)param_4 + 0x2f) | 4;
  }
  *(byte *)((longlong)param_4 + 0x2f) = *(byte *)((longlong)param_4 + 0x2f) & 0xcf;
  *(byte *)((longlong)param_4 + 0x2f) = *(byte *)((longlong)param_4 + 0x2f) | (bVar1 & 3) << 4;
  return 0;
}



/* ===== FUNC FUN_0001b34c @ 0001b34c ===== */

ulonglong FUN_0001b34c(longlong param_1,longlong param_2,longlong param_3)

{
  longlong lVar1;
  uint uVar2;
  ulonglong uVar3;
  
  lVar1 = *(longlong *)(*(longlong *)(param_2 + 0xb8) + 8);
  uVar3 = 0xc0000001;
  FUN_000121dc();
  if (*(short *)(lVar1 + 2) == 8) {
    uVar2 = FUN_00018f58(param_1,param_2,(ulonglong *)(lVar1 + 0x80),param_3);
    uVar3 = (ulonglong)uVar2;
    if (uVar2 == 0) {
      uVar3 = 0x103;
    }
  }
  return uVar3 & 0xffffffff;
}



/* ===== FUNC FUN_0001b3e0 @ 0001b3e0 ===== */

ulonglong FUN_0001b3e0(longlong param_1,longlong param_2)

{
  ushort uVar1;
  longlong lVar2;
  uint uVar3;
  uint uVar4;
  ulonglong uVar5;
  longlong lVar6;
  
  lVar2 = *(longlong *)(param_1 + 0x40);
  uVar5 = 0xc000009d;
  lVar6 = *(longlong *)(*(longlong *)(param_2 + 0xb8) + 8);
  if (lVar6 == 0) goto LAB_0001b4e6;
  uVar4 = 0;
  uVar3 = 2;
  FUN_000121dc();
  uVar1 = *(ushort *)(lVar6 + 2);
  if (uVar1 == uVar3) {
    if (*(char *)(lVar2 + 0x6a) != '\x01') {
      *(undefined8 *)(lVar6 + 8) = 0xffffffff;
LAB_0001b4df:
      *(uint *)(lVar6 + 4) = *(uint *)(lVar6 + 4) & uVar4;
      uVar5 = 0;
      goto LAB_0001b4e6;
    }
  }
  else if (7 < uVar1) {
    if (uVar1 < 10) {
LAB_0001b494:
      *(uint *)(lVar6 + 0x24) = *(uint *)(lVar6 + 0x24) & uVar4;
      if (*(char *)(lVar2 + 0x6a) != '\x01') {
        *(undefined4 *)(lVar6 + 4) = 0xc0000005;
        uVar5 = 0xc0000001;
        if (*(char *)(lVar2 + 0x6d) != (char)uVar4) goto LAB_0001b4e6;
        goto LAB_0001b4bc;
      }
      *(undefined4 *)(lVar6 + 4) = 0xc0007000;
    }
    else {
      if (uVar1 == 10) {
        *(uint *)(lVar6 + 0x24) = *(uint *)(lVar6 + 0x24) & uVar4;
        *(longlong *)(lVar6 + 8) = lVar2;
        *(undefined4 *)(lVar6 + 4) = 0xc0000b00;
        uVar5 = 0xc0000001;
        goto LAB_0001b4e6;
      }
      if (uVar1 == 0x17) goto LAB_0001b494;
      if (uVar1 != 0x1e) {
        if (uVar1 == 0x1f) goto LAB_0001b4df;
        goto LAB_0001b449;
      }
      if (*(char *)(lVar2 + 0x6a) != '\x01') {
        *(uint *)(lVar6 + 4) = *(uint *)(lVar6 + 4) & uVar4;
        uVar5 = 0;
        if (*(char *)(lVar2 + 0x6d) == (char)uVar4) {
          *(uint *)(lVar6 + 4) = *(uint *)(lVar6 + 4) & uVar4;
          uVar5 = 0xc000009d;
        }
        goto LAB_0001b4e6;
      }
      *(undefined8 *)(lVar6 + 8) = 0xffffffff;
LAB_0001b4bc:
      *(undefined4 *)(lVar6 + 4) = 0x80000300;
    }
    uVar5 = 0xc000000e;
    goto LAB_0001b4e6;
  }
LAB_0001b449:
  *(uint *)(lVar6 + 4) = *(uint *)(lVar6 + 4) & uVar4;
LAB_0001b4e6:
  return uVar5 & 0xffffffff;
}



/* ===== FUNC FUN_0001b4f8 @ 0001b4f8 ===== */

void FUN_0001b4f8(longlong param_1,longlong param_2,undefined8 param_3,undefined8 param_4)

{
  int *piVar1;
  byte bVar2;
  longlong lVar3;
  longlong lVar4;
  short sVar5;
  int iVar6;
  ulonglong uVar7;
  undefined8 *puVar8;
  undefined4 *puVar9;
  undefined2 *puVar10;
  byte bVar11;
  longlong lVar12;
  longlong lVar13;
  undefined8 uVar14;
  char *pcVar15;
  ulonglong uVar16;
  undefined1 auStackY_648 [32];
  uint local_618 [2];
  undefined8 local_610;
  ulonglong local_608 [6];
  undefined8 local_5d8;
  ulonglong local_48;
  
  local_48 = DAT_00037100 ^ (ulonglong)auStackY_648;
  bVar2 = *(byte *)(param_2 + 10);
  uVar16 = (ulonglong)bVar2;
  lVar3 = *(longlong *)(param_1 + 0x40);
  uVar14 = 0x5b4;
  FUN_000251f0(local_608,0xff,0x5b4);
  local_610 = 0xfffffffffd050f80;
  FUN_000175e4(0xb,&local_5d8);
  local_5d8._3_1_ = 1;
  local_5d8._6_2_ = 0x12;
  do {
    LOCK();
    piVar1 = (int *)(lVar3 + 0x210);
    iVar6 = *piVar1;
    *piVar1 = *piVar1 + 1;
    UNLOCK();
    sVar5 = (short)iVar6 + 1;
  } while (sVar5 == 0);
  FUN_0001bc20(lVar3,*(byte *)(param_2 + 10),
               CONCAT71((int7)((ulonglong)uVar14 >> 8),*(undefined1 *)(param_2 + 0xc)),
               CONCAT71((int7)((ulonglong)param_4 >> 8),0x33),sVar5,local_608);
  FUN_0003d284(param_1,bVar2,*(longlong *)(lVar3 + 0x1e70 + uVar16 * 0x30),local_608,0x5b4,local_618
              );
  lVar13 = uVar16 * 0x268;
  iVar6 = KeWaitForSingleObject(lVar13 + 0xff8 + lVar3,0,0);
  uVar14 = 0;
  if ((iVar6 != 0) || (local_618[0] != 0x5b4)) goto LAB_0001bbe9;
  pcVar15 = "    GetDescriptors() - Get Device_Descriptor completed. \n";
  FUN_000121dc();
  puVar10 = (undefined2 *)(lVar13 + 0x10f0 + lVar3);
  uVar7 = (ulonglong)((int)uVar14 + 0x10);
  do {
    *(undefined8 *)(puVar10 + 4) = uVar14;
    *puVar10 = (short)uVar14;
    puVar10 = puVar10 + 8;
    uVar7 = uVar7 - 1;
  } while (uVar7 != 0);
  bVar11 = 1;
  *(char *)(lVar13 + 0x11f0 + lVar3) = (char)uVar14;
  if (*(char *)(lVar13 + 0x10e9 + lVar3) != '\0') {
    do {
      *(byte *)(lVar13 + 0x11f0 + lVar3) = bVar11;
      local_5d8._2_1_ = bVar11 - 1;
      local_5d8._3_1_ = 2;
      local_5d8._6_2_ = 9;
      do {
        LOCK();
        piVar1 = (int *)(lVar3 + 0x210);
        iVar6 = *piVar1;
        *piVar1 = *piVar1 + 1;
        UNLOCK();
        sVar5 = (short)iVar6 + 1;
      } while (sVar5 == (short)uVar14);
      FUN_0001bc20(lVar3,*(byte *)(param_2 + 10),
                   CONCAT71((int7)((ulonglong)pcVar15 >> 8),*(undefined1 *)(param_2 + 0xc)),
                   CONCAT71((int7)((ulonglong)uVar14 >> 8),0x33),sVar5,local_608);
      FUN_0003d284(param_1,bVar2,*(longlong *)(lVar3 + 0x1e70 + uVar16 * 0x30),local_608,0x5b4,
                   local_618);
      lVar12 = lVar13 + 0xff8 + lVar3;
      uVar14 = 0;
      iVar6 = KeWaitForSingleObject(lVar12,0,0,0);
      if ((iVar6 != 0) || (local_618[0] != 0x5b4)) goto LAB_0001bbe9;
      pcVar15 = "    GetDescriptors() - Get Config_Descriptor (9 bytes) completed. \n";
      FUN_000121dc();
      lVar4 = *(longlong *)((ulonglong)bVar11 * 0x10 + lVar13 + 0x10f8 + lVar3);
      if (lVar4 == 0) goto LAB_0001bbe9;
      local_5d8._6_2_ = *(undefined2 *)(lVar4 + 2);
      ExFreePoolWithTag(lVar4,0x34747345);
      do {
        LOCK();
        piVar1 = (int *)(lVar3 + 0x210);
        iVar6 = *piVar1;
        *piVar1 = *piVar1 + 1;
        UNLOCK();
        sVar5 = (short)iVar6 + 1;
      } while (sVar5 == 0);
      FUN_0001bc20(lVar3,*(byte *)(param_2 + 10),
                   CONCAT71((int7)((ulonglong)pcVar15 >> 8),*(undefined1 *)(param_2 + 0xc)),
                   CONCAT71((int7)((ulonglong)uVar14 >> 8),0x33),sVar5,local_608);
      FUN_0003d284(param_1,bVar2,*(longlong *)(lVar3 + 0x1e70 + uVar16 * 0x30),local_608,0x5b4,
                   local_618);
      iVar6 = KeWaitForSingleObject(lVar12,0,0);
      uVar14 = 0;
      if ((iVar6 != 0) || (local_618[0] != 0x5b4)) goto LAB_0001bbe9;
      pcVar15 = "    GetDescriptors() - Get Config_Descriptor ( Full Descriptor ) completed. \n";
      FUN_000121dc();
      bVar11 = bVar11 + 1;
    } while (bVar11 <= *(byte *)(lVar13 + 0x10e9 + lVar3));
  }
  *(char *)(lVar13 + 0x11f0 + lVar3) = (char)uVar14;
  if (*(char *)(lVar13 + 0x10e6 + lVar3) == (char)uVar14) {
    iVar6 = 2;
    FUN_000121dc();
    pcVar15 = (char *)0x34747345;
    puVar8 = (undefined8 *)ExAllocatePoolWithTag(0,iVar6 + 0xe,0x34747345);
    lVar12 = lVar13 + 0xff8 + lVar3;
LAB_0001b945:
    *puVar8 = 0;
    puVar8[1] = 0;
    *(undefined1 *)puVar8 = 0x10;
    *(undefined1 *)((longlong)puVar8 + 1) = 3;
    *(undefined8 *)((longlong)puVar8 + 2) = u_Generic_0002a0a0._0_8_;
    *(undefined4 *)((longlong)puVar8 + 10) = u_Generic_0002a0a0._8_4_;
    *(wchar_t *)((longlong)puVar8 + 0xe) = u_Generic_0002a0a0[6];
    *(undefined2 *)(lVar13 + 0x11f8 + lVar3) = 0x10;
    *(undefined8 **)(lVar13 + 0x1200 + lVar3) = puVar8;
  }
  else {
    local_5d8._3_1_ = 3;
    local_5d8._2_1_ = *(char *)(lVar13 + 0x10e6 + lVar3);
    local_5d8._4_2_ = 0x409;
    local_5d8._6_2_ = 0xff;
    do {
      LOCK();
      piVar1 = (int *)(lVar3 + 0x210);
      iVar6 = *piVar1;
      *piVar1 = *piVar1 + 1;
      UNLOCK();
      sVar5 = (short)iVar6 + 1;
    } while (sVar5 == (short)uVar14);
    FUN_0001bc20(lVar3,*(byte *)(param_2 + 10),
                 CONCAT71((int7)((ulonglong)pcVar15 >> 8),*(undefined1 *)(param_2 + 0xc)),
                 CONCAT71((int7)((ulonglong)uVar14 >> 8),0x33),sVar5,local_608);
    FUN_0003d284(param_1,bVar2,*(longlong *)(lVar3 + 0x1e70 + uVar16 * 0x30),local_608,0x5b4,
                 local_618);
    lVar12 = lVar13 + 0xff8 + lVar3;
    uVar14 = 0;
    iVar6 = KeWaitForSingleObject(lVar12,0,0,0);
    if ((iVar6 != 0) || (local_618[0] != 0x5b4)) {
      iVar6 = 2;
      FUN_000121dc();
      pcVar15 = (char *)0x34747345;
      puVar8 = (undefined8 *)ExAllocatePoolWithTag(0,iVar6 + 0xe,0x34747345);
      goto LAB_0001b945;
    }
    pcVar15 = "    GetDescriptors() - Get iManufacturer String_Descriptor completed. \n";
    FUN_000121dc();
  }
  if (*(char *)(lVar13 + 0x10e7 + lVar3) == '\0') {
LAB_0001ba62:
    iVar6 = 2;
    FUN_000121dc();
    pcVar15 = (char *)0x34747345;
    puVar8 = (undefined8 *)ExAllocatePoolWithTag(0,iVar6 + 0x14,0x34747345);
    *puVar8 = 0;
    puVar8[1] = 0;
    *(undefined4 *)(puVar8 + 2) = 0;
    *(undefined2 *)((longlong)puVar8 + 0x14) = 0;
    *(undefined1 *)puVar8 = 0x16;
    *(undefined1 *)((longlong)puVar8 + 1) = 3;
    *(undefined8 *)((longlong)puVar8 + 2) = u_USB_Device_0002a190._0_8_;
    *(undefined8 *)((longlong)puVar8 + 10) = u_USB_Device_0002a190._8_8_;
    *(undefined4 *)((longlong)puVar8 + 0x12) = u_USB_Device_0002a190._16_4_;
    *(undefined2 *)(lVar13 + 0x1208 + lVar3) = 0x16;
    *(undefined8 **)(lVar13 + 0x1210 + lVar3) = puVar8;
  }
  else {
    local_5d8._3_1_ = 3;
    local_5d8._2_1_ = *(char *)(lVar13 + 0x10e7 + lVar3);
    local_5d8._4_2_ = 0x409;
    local_5d8._6_2_ = 0xff;
    do {
      LOCK();
      piVar1 = (int *)(lVar3 + 0x210);
      iVar6 = *piVar1;
      *piVar1 = *piVar1 + 1;
      UNLOCK();
      sVar5 = (short)iVar6 + 1;
    } while (sVar5 == 0);
    FUN_0001bc20(lVar3,*(byte *)(param_2 + 10),
                 CONCAT71((int7)((ulonglong)pcVar15 >> 8),*(undefined1 *)(param_2 + 0xc)),
                 CONCAT71((int7)((ulonglong)uVar14 >> 8),0x33),sVar5,local_608);
    FUN_0003d284(param_1,bVar2,*(longlong *)(lVar3 + 0x1e70 + uVar16 * 0x30),local_608,0x5b4,
                 local_618);
    uVar14 = 0;
    iVar6 = KeWaitForSingleObject(lVar12,0,0,0);
    if ((iVar6 != 0) || (local_618[0] != 0x5b4)) goto LAB_0001ba62;
    pcVar15 = "    GetDescriptors() - Get iProduct String_Descriptor completed. \n";
    FUN_000121dc();
  }
  if (*(char *)(lVar13 + 0x10e8 + lVar3) == '\0') {
    iVar6 = 2;
    FUN_000121dc();
    puVar9 = (undefined4 *)ExAllocatePoolWithTag(0,iVar6 + 2,0x34747345);
    *puVar9 = 0;
    *(undefined1 *)puVar9 = 4;
    *(undefined1 *)((longlong)puVar9 + 1) = 3;
    *(undefined2 *)((longlong)puVar9 + 2) = DAT_0002a280;
    *(undefined4 **)(lVar13 + 0x1220 + lVar3) = puVar9;
    *(undefined2 *)(lVar13 + 0x1218 + lVar3) = 4;
  }
  else {
    local_5d8._3_1_ = 3;
    local_5d8._2_1_ = *(char *)(lVar13 + 0x10e8 + lVar3);
    local_5d8._4_2_ = 0x409;
    local_5d8._6_2_ = 0xff;
    do {
      LOCK();
      piVar1 = (int *)(lVar3 + 0x210);
      iVar6 = *piVar1;
      *piVar1 = *piVar1 + 1;
      UNLOCK();
      sVar5 = (short)iVar6 + 1;
    } while (sVar5 == 0);
    FUN_0001bc20(lVar3,*(byte *)(param_2 + 10),
                 CONCAT71((int7)((ulonglong)pcVar15 >> 8),*(undefined1 *)(param_2 + 0xc)),
                 CONCAT71((int7)((ulonglong)uVar14 >> 8),0x33),sVar5,local_608);
    FUN_0003d284(param_1,bVar2,*(longlong *)(lVar3 + 0x1e70 + uVar16 * 0x30),local_608,0x5b4,
                 local_618);
    iVar6 = KeWaitForSingleObject(lVar12,0,0,0);
    if ((iVar6 == 0) && (local_618[0] == 0x5b4)) {
      FUN_000121dc();
    }
  }
LAB_0001bbe9:
  FUN_00025050(local_48 ^ (ulonglong)auStackY_648);
  return;
}



/* ===== FUNC FUN_0001bc20 @ 0001bc20 ===== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0001bc20(longlong param_1,byte param_2,undefined8 param_3,undefined8 param_4,
                 undefined2 param_5,ulonglong *param_6)

{
  ulonglong uVar1;
  ulonglong uVar2;
  
  FUN_000251f0(param_6,0,0x30);
  uVar2 = _UNK_00035c88;
  uVar1 = _DAT_00035c80;
  *(byte *)((longlong)param_6 + 0x1a) = *(byte *)((longlong)param_6 + 0x1a) | 0x80;
  *(undefined4 *)(param_6 + 2) = 0x24544e55;
  *(undefined1 *)((longlong)param_6 + 0x17) = 0;
  *param_6 = uVar1;
  param_6[1] = uVar2;
  *(byte *)((longlong)param_6 + 0x16) = param_2;
  *(undefined2 *)(param_6 + 3) = param_5;
  if (*(short *)((longlong)param_6 + 0x36) == 0) {
    *(undefined1 *)((longlong)param_6 + 0x1c) = 0x25;
  }
  else if ((char)param_6[6] < '\0') {
    if ((char)param_6[6] < '\0') {
      *(undefined1 *)((longlong)param_6 + 0x1c) = 0x33;
    }
  }
  else {
    *(undefined1 *)((longlong)param_6 + 0x1c) = 0x2d;
  }
  *(undefined1 *)(param_6 + 4) = 1;
  *(undefined1 *)((longlong)param_6 + 0x21) = *(undefined1 *)((longlong)param_6 + 0x32);
  *(undefined1 *)((longlong)param_6 + 0x22) = *(undefined1 *)((longlong)param_6 + 0x33);
  *(undefined1 *)((longlong)param_6 + 0x23) = *(undefined1 *)((longlong)param_6 + 0x34);
  *(undefined2 *)((longlong)param_6 + 0x24) = 8;
  *(undefined1 *)((longlong)param_6 + 0x2a) = *(undefined1 *)((longlong)param_6 + 0x35);
  if ((param_6[6] & 0x80) == 0) {
    *(short *)((longlong)param_6 + 0x24) = *(short *)((longlong)param_6 + 0x36) + 8;
  }
  *(ushort *)((longlong)param_6 + 0x14) =
       *(ushort *)((longlong)param_6 + 0x24) >> 8 | *(ushort *)((longlong)param_6 + 0x24) << 8;
  if (((param_6[6] & 0x80) != 0) &&
     (*(ushort *)(param_1 + 0x2000) < *(ushort *)((longlong)param_6 + 0x36))) {
    *(ushort *)((longlong)param_6 + 0x36) = *(ushort *)(param_1 + 0x2000);
  }
  *(undefined2 *)((longlong)param_6 + 0x26) = *(undefined2 *)((longlong)param_6 + 0x36);
  *(char *)(param_6 + 5) = (char)param_6[6];
  *(byte *)((longlong)param_6 + 0x2d) = *(byte *)((longlong)param_6 + 0x2d) & 0xf;
  *(undefined1 *)((longlong)param_6 + 0x29) = *(undefined1 *)((longlong)param_6 + 0x31);
  *(byte *)((longlong)param_6 + 0x2e) = param_2 & 0xf;
  *(byte *)((longlong)param_6 + 0x2d) =
       *(byte *)((longlong)param_6 + 0x2d) | ((param_2 & 0xf) - 1) * '\x10';
  *(byte *)((longlong)param_6 + 0x2f) = *(byte *)((longlong)param_6 + 0x2f) & 0xcb | 8;
  return;
}



/* ===== FUNC FUN_0001bd38 @ 0001bd38 ===== */

longlong FUN_0001bd38(undefined8 param_1,longlong param_2,longlong param_3)

{
  longlong lVar1;
  uint uVar2;
  undefined8 local_res10;
  
  uVar2 = 0;
  do {
    *(int *)(param_2 + 0x1f94) = *(int *)(param_2 + 0x1f94) + 1;
    lVar1 = ExpInterlockedPopEntrySList(param_2 + 0x1f80);
    if (lVar1 == 0) {
      *(int *)(param_2 + 0x1f98) = *(int *)(param_2 + 0x1f98) + 1;
      lVar1 = (**(code **)(param_2 + 0x1fb0))
                        (*(undefined4 *)(param_2 + 0x1fa4),*(undefined4 *)(param_2 + 0x1fac),
                         *(undefined4 *)(param_2 + 0x1fa8));
    }
    if (lVar1 != 0) {
      return lVar1;
    }
    if ((param_3 != 0) &&
       ((*(char *)(param_3 + 0x69) == '\0' || (*(char *)(param_3 + 0x6d) == '\0')))) {
      FUN_000121dc();
      return 0;
    }
    uVar2 = uVar2 + 1;
    local_res10 = 0xfffffffffffffc18;
    KeDelayExecutionThread(0,0,&local_res10);
    if (19999 < uVar2) {
      return 0;
    }
  } while (*(int *)(param_2 + 0xb0) != 0);
  return 0;
}



/* ===== FUNC FUN_0001be2c @ 0001be2c ===== */

ulonglong FUN_0001be2c(longlong param_1,longlong param_2)

{
  longlong lVar1;
  undefined2 *puVar2;
  ulonglong uVar3;
  
  lVar1 = *(longlong *)(param_2 + 0xb8);
  uVar3 = 0;
  FUN_000121dc();
  puVar2 = *(undefined2 **)(lVar1 + 0x18);
  if (((*(char *)(param_1 + 0x1f1) == '\x01') || (*(char *)(param_1 + 0x1f1) == -1)) ||
     (*(char *)(param_1 + 0x78) == -0x11)) {
    *(longlong *)(puVar2 + 4) = param_1;
    FUN_000121dc();
    if (*(ushort *)(lVar1 + 0x10) < 0x40) {
      return 0xc000000d;
    }
    if ((uint)*(ushort *)(lVar1 + 0x12) == (uint)uVar3) {
      puVar2[1] = (short)uVar3;
      *puVar2 = 0x40;
    }
    else {
      if (*(ushort *)(lVar1 + 0x12) != 1) goto LAB_0001be86;
      puVar2[1] = 1;
      *puVar2 = 0x48;
      *(undefined1 **)(puVar2 + 0x20) = &LAB_0001c0e4;
    }
    *(undefined1 **)(puVar2 + 8) = &LAB_0001bf88;
    *(undefined1 **)(puVar2 + 0xc) = &LAB_0001bf94;
    *(undefined1 **)(puVar2 + 0x10) = &LAB_0001bfa0;
    *(undefined1 **)(puVar2 + 0x14) = &LAB_0001bfc4;
    *(undefined1 **)(puVar2 + 0x18) = &LAB_0001c008;
    *(code **)(puVar2 + 0x1c) = FUN_0001c014;
    *(longlong *)(lVar1 + 0x20) = param_1;
    LOCK();
    *(int *)(param_1 + 0x70) = *(int *)(param_1 + 0x70) + 1;
    UNLOCK();
  }
  else {
LAB_0001be86:
    uVar3 = (ulonglong)*(uint *)(param_2 + 0x30);
  }
  FUN_000121dc();
  return uVar3 & 0xffffffff;
}



/* ===== FUNC FUN_0001c014 @ 0001c014 ===== */

void FUN_0001c014(longlong param_1,int param_2,undefined8 *param_3,uint *param_4,uint *param_5)

{
  longlong lVar1;
  uint uVar2;
  undefined1 auStack_48 [32];
  undefined4 local_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined2 uStack_1c;
  undefined2 uStack_1a;
  ulonglong local_18;
  
  local_18 = DAT_00037100 ^ (ulonglong)auStack_48;
  lVar1 = *(longlong *)(*(longlong *)(param_1 + 0x28) + 0x40);
  if (param_2 == 0) {
    uVar2 = 8;
    if (*param_4 < 8) goto LAB_0001c0ca;
    uStack_24 = *(undefined4 *)(lVar1 + 0x2070);
    *param_3 = CONCAT44(uStack_24,11000000);
  }
  else {
    if (param_2 != 1) {
      FUN_000121dc();
      goto LAB_0001c0ca;
    }
    uVar2 = 0x10;
    if (*param_4 < 0x10) goto LAB_0001c0ca;
    uStack_24 = *(undefined4 *)(lVar1 + 0x2070);
    uStack_20 = 0;
    uStack_1c = 0;
    uStack_1a = 0;
    *param_3 = CONCAT44(uStack_24,11000000);
    param_3[1] = 0;
  }
  local_28 = 11000000;
  *param_5 = uVar2;
  *param_4 = uVar2;
LAB_0001c0ca:
  FUN_00025050(local_18 ^ (ulonglong)auStack_48);
  return;
}



/* ===== FUNC FUN_0001c104 @ 0001c104 ===== */

longlong * FUN_0001c104(undefined8 param_1,longlong param_2,longlong param_3,longlong param_4)

{
  longlong *plVar1;
  longlong lVar2;
  longlong *plVar3;
  undefined1 uVar4;
  longlong *plVar5;
  byte bVar6;
  longlong *plVar7;
  byte bVar8;
  
  lVar2 = *(longlong *)(param_2 + 0x88 + (ulonglong)*(byte *)(param_2 + 0x108) * 8);
  FUN_000121dc();
  plVar1 = (longlong *)(param_2 + 0x48);
  plVar7 = (longlong *)*plVar1;
  if (plVar7 != plVar1) {
    do {
      plVar5 = plVar7 + -4;
      if (*(char *)(plVar7[-2] + 2) == *(char *)(param_4 + 2)) goto LAB_0001c21f;
      plVar7 = (longlong *)*plVar7;
    } while (plVar7 != plVar1);
  }
  plVar5 = (longlong *)ExAllocatePoolWithTag(0,0xa8,0x32747345);
  if (plVar5 == (longlong *)0x0) {
    return (longlong *)0x0;
  }
  plVar7 = plVar5 + 0x12;
  plVar5[0x13] = (longlong)plVar7;
  *plVar7 = (longlong)plVar7;
  KeInitializeEvent(plVar5 + 6,1,1);
  plVar5[0x14] = 0;
  IoCsqInitialize(plVar5 + 10,&LAB_00016724,&LAB_00015fbc,&LAB_00016750,FUN_00016784,&LAB_000167a8,
                  FUN_000167bc);
  plVar3 = *(longlong **)(param_2 + 0x50);
  plVar7 = plVar5 + 4;
  *plVar7 = (longlong)plVar1;
  plVar5[5] = (longlong)plVar3;
  *plVar3 = (longlong)plVar7;
  *(longlong **)(param_2 + 0x50) = plVar7;
LAB_0001c21f:
  *plVar5 = param_2;
  plVar5[1] = param_3;
  plVar5[2] = param_4;
  *(undefined1 *)((longlong)plVar5 + 0x1c) = 0;
  bVar6 = *(byte *)(param_4 + 3) & 3;
  uVar4 = 1;
  if (((bVar6 != 1) && (bVar6 != 3)) && (bVar6 != 0)) {
    bVar8 = *(byte *)(param_4 + 2) & 0x80;
    if (((bVar8 == 0) && (bVar6 == 2)) && (*(char *)(param_3 + 5) == '\a')) {
      uVar4 = 0x81;
    }
    else if (((bVar8 != 0) && (bVar6 == 2)) &&
            (((*(char *)(param_3 + 5) == '\b' && (*(byte *)(lVar2 + 4) < 2)) ||
             ((*(short *)(param_2 + 0x7c) == 0x4b8 ||
              (uVar4 = 0x81, *(short *)(param_2 + 0x7c) == 0x4e8)))))) {
      uVar4 = 1;
    }
  }
  *(undefined1 *)(plVar5 + 9) = uVar4;
  if ((*(char *)(param_3 + 5) == '\a') && ((~(*(byte *)(param_4 + 2) >> 7) & 1) != 0)) {
    *(undefined1 *)(plVar5 + 3) = 1;
  }
  else {
    uVar4 = 0x20;
    if ((~(*(byte *)(param_4 + 2) >> 7) & 1) == 1) {
      uVar4 = 0x40;
    }
    *(undefined1 *)(plVar5 + 3) = uVar4;
  }
  if ((*(byte *)(param_4 + 3) & 3) == 2) {
    *(ushort *)((longlong)plVar5 + 0x1a) =
         (short)(((ulonglong)
                  *(ushort *)(*(longlong *)(*(longlong *)(param_2 + 0x28) + 0x40) + 0x2000) - 0x30)
                / ((ulonglong)*(ushort *)(param_4 + 4) & 0x7ff)) *
         (*(ushort *)(param_4 + 4) & 0x7ff);
  }
  else {
    *(undefined2 *)((longlong)plVar5 + 0x1a) = 0xffff;
  }
  return plVar5;
}



/* ===== FUNC FUN_0001c32c @ 0001c32c ===== */

undefined4
FUN_0001c32c(undefined8 param_1,longlong param_2,longlong param_3,longlong param_4,longlong param_5)

{
  byte bVar1;
  longlong lVar2;
  undefined8 *puVar3;
  longlong lVar4;
  longlong *plVar5;
  undefined1 *puVar6;
  int iVar7;
  undefined4 uVar8;
  byte *pbVar9;
  int iVar10;
  
  uVar8 = 0;
  iVar10 = 0;
  if (*(char *)(param_4 + 4) != '\0') {
    if (*(int *)(param_5 + 0x10) == 0) {
      *(uint *)(param_5 + 0x10) = (uint)*(byte *)(param_4 + 4);
    }
    lVar4 = USBD_ParseDescriptors(param_3,*(undefined2 *)(param_3 + 2),param_4,5);
    if (lVar4 == 0) {
      uVar8 = 0xc0000001;
    }
    else if (*(char *)(param_4 + 4) != '\0') {
      pbVar9 = (byte *)(param_5 + 0x1a);
      do {
        *pbVar9 = *(byte *)(lVar4 + 2);
        *(undefined2 *)(pbVar9 + -2) = *(undefined2 *)(lVar4 + 4);
        pbVar9[1] = *(byte *)(lVar4 + 6);
        plVar5 = FUN_0001c104(param_1,param_2,param_4,lVar4);
        *(longlong **)(pbVar9 + 6) = plVar5;
        if (plVar5 == (longlong *)0x0) {
LAB_0001c4a5:
          FUN_000121dc();
          return 0xc000009a;
        }
        *(uint *)(pbVar9 + 2) = *(byte *)(lVar4 + 3) & 3;
        iVar7 = 2;
        FUN_000121dc();
        if (((*(char *)(param_4 + 5) == '\a') && (*(int *)(pbVar9 + 2) == iVar7)) &&
           ((*pbVar9 & 0x80) == 0)) {
          lVar2 = *(longlong *)(*(longlong *)(param_2 + 0x28) + 0x40);
          FUN_000121dc();
          puVar6 = (undefined1 *)ExAllocatePoolWithTag(0,iVar7 + 0x1e,0x32747345);
          if (puVar6 == (undefined1 *)0x0) goto LAB_0001c4a5;
          *puVar6 = *(undefined1 *)(param_2 + 0x24);
          bVar1 = *pbVar9;
          *(undefined2 *)(puVar6 + 2) = 0;
          puVar6[0x18] = 0;
          puVar6[1] = bVar1;
          puVar3 = *(undefined8 **)(lVar2 + 0xf00);
          plVar5 = (longlong *)(puVar6 + 8);
          *(undefined8 **)(puVar6 + 0x10) = puVar3;
          *plVar5 = lVar2 + 0xef8;
          *puVar3 = plVar5;
          *(longlong **)(lVar2 + 0xf00) = plVar5;
        }
        iVar10 = iVar10 + 1;
        lVar4 = lVar4 + 7;
        pbVar9 = pbVar9 + 0x18;
      } while (iVar10 < (int)(uint)*(byte *)(param_4 + 4));
    }
  }
  return uVar8;
}



/* ===== FUNC FUN_0001c4e8 @ 0001c4e8 ===== */

int FUN_0001c4e8(undefined8 param_1,longlong param_2)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  longlong lVar4;
  longlong lVar5;
  longlong lVar6;
  uint uVar7;
  int iVar8;
  longlong lVar9;
  uint uVar10;
  ushort *puVar11;
  uint uVar12;
  byte bVar13;
  
  lVar4 = *(longlong *)(param_2 + 0x78);
  iVar8 = 0;
  lVar5 = *(longlong *)(*(longlong *)(param_2 + 0xb8) + 8);
  FUN_000121dc();
  *(longlong *)(lVar5 + 8) = lVar4;
  *(undefined8 *)(lVar5 + 0x20) =
       *(undefined8 *)(lVar4 + 0x88 + (ulonglong)*(byte *)(lVar4 + 0x108) * 8);
  if (*(longlong *)(lVar5 + 0x18) == 0) {
    FUN_000121dc();
  }
  else {
    lVar6 = *(longlong *)(lVar4 + 0x88 + (ulonglong)*(byte *)(lVar4 + 0x108) * 8);
    FUN_000121dc();
    puVar11 = (ushort *)(lVar5 + 0x28);
    if (puVar11 == (ushort *)0x0) {
      iVar8 = -0x3fffffff;
LAB_0001c6ef:
      *(undefined4 *)(lVar5 + 4) = 0xc0002000;
      return iVar8;
    }
    bVar13 = 0;
    if (*(char *)(lVar6 + 4) != '\0') {
      do {
        lVar9 = USBD_ParseConfigurationDescriptorEx
                          (lVar6,lVar6,(char)puVar11[1],*(undefined1 *)((longlong)puVar11 + 3),
                           0xffffffff,0xffffffff,0xffffffff);
        if (lVar9 != 0) {
          bVar1 = *(byte *)(lVar9 + 5);
          *(byte *)(puVar11 + 2) = bVar1;
          bVar2 = *(byte *)(lVar9 + 6);
          *(byte *)((longlong)puVar11 + 5) = bVar2;
          bVar3 = *(byte *)(lVar9 + 7);
          *(longlong *)(puVar11 + 4) = lVar9;
          uVar7 = (uint)bVar3;
          *(byte *)(puVar11 + 3) = bVar3;
          uVar10 = (uint)bVar2;
          uVar12 = (uint)bVar1;
          FUN_000121dc();
          iVar8 = FUN_0001c32c(param_1,lVar4,lVar6,lVar9,(longlong)puVar11);
          lVar9 = USBD_ParseConfigurationDescriptorEx
                            (lVar6,lVar6,(char)puVar11[1],1,0xffffffff,0xffffffff,0xffffffff,uVar12,
                             uVar10,uVar7);
          if (lVar9 != 0) {
            FUN_000121dc();
            FUN_000181e8(param_1,param_2,(longlong)puVar11);
            FUN_000120dc(500);
          }
        }
        bVar13 = bVar13 + 1;
        puVar11 = (ushort *)((longlong)puVar11 + (ulonglong)*puVar11);
      } while (bVar13 < *(byte *)(lVar6 + 4));
      if (iVar8 != 0) goto LAB_0001c6ef;
    }
  }
  *(undefined4 *)(lVar5 + 4) = 0;
  return 0;
}



/* ===== FUNC FUN_0001c704 @ 0001c704 ===== */

undefined8 FUN_0001c704(longlong param_1,undefined8 param_2,byte param_3)

{
  longlong lVar1;
  longlong lVar2;
  
  lVar1 = *(longlong *)(param_1 + 0x40);
  lVar2 = FUN_000121dc();
  FUN_0001f9e0(param_1,lVar2);
  KeSetEvent((ulonglong)param_3 * 0xd0 + 0x610 + lVar1,0,0);
  return 0x103;
}



/* ===== FUNC FUN_0001c774 @ 0001c774 ===== */

int FUN_0001c774(undefined8 param_1,longlong param_2)

{
  char cVar1;
  uint uVar2;
  longlong lVar3;
  longlong lVar4;
  longlong lVar5;
  void *_Dst;
  byte *_Src;
  size_t _Size;
  int iVar6;
  
  lVar3 = *(longlong *)(param_2 + 0x78);
  iVar6 = 0;
  lVar4 = *(longlong *)(*(longlong *)(param_2 + 0xb8) + 8);
  uVar2 = *(uint *)(lVar4 + 0x24);
  cVar1 = *(char *)(lVar4 + 0x83);
  FUN_000121dc();
  _Dst = *(void **)(lVar4 + 0x28);
  if (_Dst == (void *)0x0) {
    lVar5 = *(longlong *)(lVar4 + 0x30);
    if (lVar5 == 0) {
      FUN_000121dc();
      iVar6 = -0x3fffffff;
      goto LAB_0001c8b0;
    }
    if ((*(byte *)(lVar5 + 10) & 5) == 0) {
      _Dst = (void *)MmMapLockedPagesSpecifyCache(lVar5,0,1,0,0,0x10);
    }
    else {
      _Dst = *(void **)(lVar5 + 0x18);
    }
  }
  if (cVar1 == '\x02') {
    FUN_000121dc();
    _Src = *(byte **)(lVar3 + 0x88 + (ulonglong)*(byte *)(lVar3 + 0x108) * 8);
    _Size = (size_t)*(ushort *)(_Src + 2);
LAB_0001c85a:
    if (uVar2 < (uint)_Size) {
      memcpy(_Dst,_Src,(ulonglong)uVar2);
    }
    else {
      memcpy(_Dst,_Src,_Size);
      *(uint *)(lVar4 + 0x24) = (uint)_Size;
    }
    *(undefined4 *)(lVar4 + 0x44) = 0xdeadf00d;
    *(undefined4 *)(lVar4 + 0x40) = 0xffffffff;
  }
  else if (cVar1 == '\x01') {
    FUN_000121dc();
    _Src = (byte *)(lVar3 + 0x74);
    _Size = (size_t)*_Src;
    goto LAB_0001c85a;
  }
  *(undefined4 *)(lVar4 + 4) = 0;
  if (*(longlong *)(lVar4 + 8) == 0) {
    *(longlong *)(lVar4 + 8) = lVar3;
  }
  if (*(int *)(lVar4 + 0x10) == 0) {
    *(undefined4 *)(lVar4 + 0x10) = 0x22;
  }
LAB_0001c8b0:
  FUN_00017594(param_2,iVar6);
  return iVar6;
}



/* ===== FUNC FUN_0001c8e4 @ 0001c8e4 ===== */

int FUN_0001c8e4(undefined8 param_1,longlong param_2)

{
  int iVar1;
  int iVar2;
  longlong lVar3;
  
  lVar3 = *(longlong *)(*(longlong *)(param_2 + 0xb8) + 8);
  iVar1 = FUN_000121dc();
  iVar2 = 0;
  if (iVar1 != 0) {
    iVar2 = -0x3fffffff;
  }
  *(int *)(lVar3 + 4) = iVar1;
  FUN_00017594(param_2,iVar2);
  return iVar2;
}



/* ===== FUNC FUN_0001c94c @ 0001c94c ===== */

undefined8 FUN_0001c94c(undefined8 param_1,longlong param_2,longlong param_3)

{
  longlong lVar1;
  longlong lVar2;
  void *_Dst;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  
  lVar1 = *(longlong *)(*(longlong *)(param_2 + 0xb8) + 8);
  uVar5 = *(uint *)(lVar1 + 0x24);
  uVar4 = (*(byte *)(param_3 + 0x15) & 0xf) * 0x100 + -8 + (uint)*(byte *)(param_3 + 0x14);
  _Dst = (void *)FUN_000121dc();
  if (((*(byte *)(param_3 + 0x10) & 2) == 0) && ((*(byte *)(param_3 + 0x10) & 4) == 0)) {
    uVar3 = uVar5;
    if (uVar4 <= uVar5) {
      uVar3 = uVar4;
    }
    if ((uVar5 != 0) && (_Dst = *(void **)(lVar1 + 0x28), _Dst == (void *)0x0)) {
      lVar2 = *(longlong *)(lVar1 + 0x30);
      if (lVar2 == 0) {
        FUN_000121dc();
        goto LAB_0001ca51;
      }
      if ((*(byte *)(lVar2 + 10) & 5) == 0) {
        _Dst = (void *)MmMapLockedPagesSpecifyCache(lVar2,0,1,0,0,0x10);
      }
      else {
        _Dst = *(void **)(lVar2 + 0x18);
      }
    }
    *(uint *)(lVar1 + 0x24) = uVar3;
    if (_Dst != (void *)0x0) {
      memcpy(_Dst,(void *)(param_3 + 0x28),(ulonglong)uVar3);
    }
    *(undefined4 *)(lVar1 + 0x40) = 0xffffffff;
    *(undefined4 *)(lVar1 + 0x44) = 0xdeadf00d;
    *(undefined4 *)(lVar1 + 0x48) = 0xe2ffa4a8;
    *(undefined4 *)(lVar1 + 4) = 0;
    *(undefined4 *)(lVar1 + 0x10) = 0x22;
  }
  else {
    *(uint *)(lVar1 + 0x24) = *(uint *)(lVar1 + 0x24) & (uint)_Dst;
    *(undefined4 *)(lVar1 + 4) = 0xc0008000;
  }
LAB_0001ca51:
  *(undefined8 *)(lVar1 + 8) = *(undefined8 *)(param_2 + 0x78);
  FUN_00017594(param_2,0);
  return 0;
}



/* ===== FUNC FUN_0001ca80 @ 0001ca80 ===== */

ulonglong FUN_0001ca80(longlong param_1,int *param_2)

{
  byte *pbVar1;
  char cVar2;
  ushort uVar3;
  longlong lVar4;
  ulonglong uVar5;
  uint uVar6;
  undefined4 uVar7;
  longlong lVar8;
  longlong lVar9;
  undefined8 uVar10;
  ulonglong uVar11;
  longlong lVar12;
  int *piVar13;
  int iVar14;
  byte bVar15;
  int *local_res8;
  
  lVar4 = *(longlong *)(param_1 + 0x40);
  uVar11 = 0;
  pbVar1 = (byte *)(param_2 + 4);
  if ((*(char *)(lVar4 + 8) == '\0') || (*param_2 != 0x24544e55)) {
    FUN_000121dc();
    return 0;
  }
  if ((*(char *)((longlong)param_2 + 7) == '\x17') || (*(char *)((longlong)param_2 + 7) == '\x0f'))
  {
    lVar8 = 0;
  }
  else {
    lVar8 = FUN_0001d004(param_1,(longlong)param_2);
    if ((((*pbVar1 & 2) != 0) && (lVar8 != 0)) && (*(char *)((longlong)param_2 + 7) == '\x01')) {
      lVar9 = *(longlong *)(*(longlong *)(lVar8 + 0xb8) + 8);
      if (((*(short *)(lVar9 + 2) == 0x18) || (*(short *)(lVar9 + 2) == 0x1b)) ||
         (*(short *)(lVar9 + 2) == 0x17)) {
        FUN_000121dc();
        *(undefined4 *)(lVar9 + 0x24) = 0;
      }
      else if (*(short *)(*(longlong *)(lVar8 + 0x78) + 0x7c) == 0x43d) {
        lVar9 = ExAllocatePoolWithTag(0,0x38,0x53747345);
        if (lVar9 != 0) {
          *(short *)(lVar9 + 0x10) = (short)param_2[2];
          *(byte *)(lVar9 + 0x12) = *(byte *)((longlong)param_2 + 0x1e) & 0xf;
          *(byte *)(lVar9 + 0x13) = *(byte *)((longlong)param_2 + 0x1e) >> 4;
          *(char *)(lVar9 + 0x14) = *(char *)((longlong)param_2 + 7) + -1;
          FUN_00017da0(param_1,lVar8,lVar9);
          FUN_000121dc();
          return 0;
        }
        FUN_000121dc();
      }
    }
  }
  FUN_0001834c(param_1,(ulonglong)(*(byte *)((longlong)param_2 + 0x1e) & 0xf),lVar4);
  cVar2 = *(char *)((longlong)param_2 + 7);
  if (cVar2 == '\x17') {
    uVar10 = FUN_0001d448(param_1,(longlong)param_2);
    uVar6 = (uint)uVar10;
LAB_0001cbf9:
    uVar11 = (ulonglong)uVar6;
    goto LAB_0001cfbd;
  }
  if (cVar2 == '\x0f') {
    local_res8 = (int *)0xfffffffffffcf2c0;
    KeWaitForSingleObject(lVar4 + 0x2058,0,0,0,&local_res8);
    uVar11 = FUN_0001e1dc(param_1,(longlong)param_2);
    uVar11 = uVar11 & 0xffffffff;
    KeSetEvent(lVar4 + 0x2058,0,0);
    goto LAB_0001cfbd;
  }
  if ((cVar2 == '\x1b') || (cVar2 == '\x19')) {
    FUN_00017594(lVar8,0);
  }
  if (lVar8 == 0) {
    FUN_000121dc();
    goto LAB_0001cfbd;
  }
  lVar9 = *(longlong *)(*(longlong *)(lVar8 + 0xb8) + 8);
  uVar5 = *(ulonglong *)(lVar8 + 0x78);
  if (uVar5 < 0xffffffffffffff00) {
    if (*(int *)(lVar4 + 0xb0) == 0) {
LAB_0001cca9:
      uVar11 = 0;
      goto LAB_0001cfbd;
    }
    if ((*(char *)(uVar5 + 0x69) != '\0') && (*(char *)(uVar5 + 0x6d) != '\0')) goto LAB_0001ccee;
    lVar12 = FUN_000121dc();
    if (*(int *)(lVar12 + 0xc) == 6) goto LAB_0001cfbd;
    uVar11 = 0;
    *(undefined4 *)(lVar9 + 4) = 0xc0007000;
    iVar14 = 0;
  }
  else {
LAB_0001ccee:
    bVar15 = 2;
    if ((*pbVar1 & 2) != 0) {
      FUN_0001e930(param_1,lVar8,lVar9,(longlong)param_2,(longlong)pbVar1);
      goto LAB_0001cfbd;
    }
    uVar3 = *(ushort *)(lVar9 + 2);
    if (uVar3 < 0x18) {
      if (uVar3 != 0x17) {
        if (uVar3 < 0xc) {
          if (uVar3 == 0xb) {
            uVar6 = FUN_0001d504(param_1,lVar8,(longlong)param_2);
          }
          else {
            if (uVar3 == 0) {
              FUN_000121dc();
              if (((*pbVar1 & bVar15) == 0) && ((*pbVar1 & 4) == 0)) {
                *(undefined4 *)(lVar9 + 4) = 0;
                FUN_0001c4e8(param_1,lVar8);
              }
              else {
                FUN_000121dc();
                *(undefined4 *)(lVar9 + 4) = 0xc0002000;
              }
              goto LAB_0001cdd7;
            }
            if (uVar3 == 1) {
              uVar6 = FUN_0001d0bc(param_1,lVar8,(longlong)param_2);
            }
            else {
              if (uVar3 == 8) goto LAB_0001cf87;
              if (uVar3 != 9) goto LAB_0001cfbd;
              uVar6 = FUN_0001d7b0(param_1,lVar4,*(undefined1 *)((longlong)param_2 + 6),lVar8,
                                   (longlong)param_2);
            }
          }
        }
        else if (((uVar3 == 0x10) || (uVar3 == 0x11)) || (uVar3 == 0x12)) {
          uVar6 = FUN_0001c8e4(param_1,lVar8);
        }
        else {
          if ((uVar3 < 0x13) || (0x15 < uVar3)) goto LAB_0001cfbd;
LAB_0001ce17:
          uVar10 = FUN_0001c94c(param_1,lVar8,(longlong)param_2);
          uVar6 = (uint)uVar10;
        }
        goto LAB_0001cbf9;
      }
LAB_0001ce49:
      FUN_000121dc();
      uVar11 = 0;
      if (*param_2 == 0x24544e55) {
        uVar11 = FUN_0001d690(param_1,lVar9,(longlong)param_2);
        uVar11 = uVar11 & 0xffffffff;
      }
    }
    else if ((uVar3 == 0x18) || (uVar3 == 0x1b)) {
LAB_0001cf87:
      FUN_000121dc();
      uVar11 = 0;
      if (*param_2 == 0x24544e55) {
        uVar11 = FUN_0001d690(param_1,lVar9,(longlong)param_2);
        uVar11 = uVar11 & 0xffffffff;
      }
      *(undefined8 *)(lVar9 + 8) = *(undefined8 *)(lVar8 + 0x78);
    }
    else {
      if (uVar3 == 0x1c) goto LAB_0001ce49;
      if (uVar3 == 0x1e) {
        FUN_000121dc();
        uVar7 = 0;
        if (((*pbVar1 & bVar15) != 0) || ((*pbVar1 & 4) != 0)) {
          uVar7 = 0xc0008000;
        }
        *(undefined4 *)(lVar9 + 4) = uVar7;
        *(undefined8 *)(lVar8 + 0x38) = 0;
        *(undefined4 *)(lVar9 + 0x10) = 0x10;
LAB_0001cdd7:
        FUN_00017594(lVar8,0);
        goto LAB_0001cca9;
      }
      if (uVar3 != 0x1f) {
        if (uVar3 != 0x20) {
          if (uVar3 == 0x21) goto LAB_0001ce17;
          if (uVar3 != 0x28) goto LAB_0001cfbd;
          uVar6 = FUN_0001df20(param_1,lVar8,(longlong)param_2);
          goto LAB_0001cbf9;
        }
        goto LAB_0001cf87;
      }
      FUN_000121dc();
      uVar11 = 0;
      if (*param_2 == 0x24544e55) {
        uVar11 = FUN_0001d690(param_1,lVar9,(longlong)param_2);
        uVar11 = uVar11 & 0xffffffff;
        if (*param_2 != 0x24544e55) goto LAB_0001cf10;
        piVar13 = param_2 + 8;
      }
      else {
LAB_0001cf10:
        piVar13 = local_res8;
      }
      *(char *)(lVar9 + 0x80) = (char)*piVar13;
    }
    iVar14 = (int)uVar11;
  }
  FUN_00017594(lVar8,iVar14);
LAB_0001cfbd:
  FUN_000183ac(param_1,(ulonglong)(*(byte *)((longlong)param_2 + 0x1e) & 0xf),lVar4);
  return uVar11;
}



/* ===== FUNC FUN_0001d004 @ 0001d004 ===== */

longlong FUN_0001d004(longlong param_1,longlong param_2)

{
  longlong lVar1;
  longlong lVar2;
  uint uVar3;
  undefined1 local_48 [16];
  undefined2 local_38;
  byte local_36;
  byte local_35;
  char local_34;
  
  local_38 = *(undefined2 *)(param_2 + 8);
  lVar2 = *(longlong *)(param_1 + 0x40);
  local_35 = *(byte *)(param_2 + 0x1e) >> 4;
  local_36 = *(byte *)(param_2 + 0x1e) & 0xf;
  local_34 = *(char *)(param_2 + 7) + -1;
  uVar3 = 0;
  do {
    lVar1 = IoCsqRemoveNextIrp(lVar2 + 0x218,local_48);
    if (lVar1 != 0) {
      lVar2 = FUN_000121dc();
      if (*(longlong *)(lVar2 + 0x88) == 0) {
        return lVar1;
      }
      ExFreePoolWithTag(*(longlong *)(lVar2 + 0x88),0x53747345);
      return lVar1;
    }
    uVar3 = uVar3 + 1;
  } while (uVar3 < 10);
  return 0;
}



/* ===== FUNC FUN_0001d0bc @ 0001d0bc ===== */

int FUN_0001d0bc(longlong param_1,longlong param_2,longlong param_3)

{
  undefined1 uVar1;
  ulonglong uVar2;
  longlong lVar3;
  longlong lVar4;
  longlong lVar5;
  uint uVar6;
  undefined4 uVar7;
  longlong lVar8;
  longlong *plVar9;
  ulonglong uVar10;
  longlong lVar11;
  int iVar12;
  undefined7 uVar13;
  int iVar14;
  ulonglong uVar15;
  char *pcVar16;
  byte *pbVar17;
  byte bVar18;
  ulonglong local_res8;
  longlong local_res10;
  longlong local_res18;
  longlong local_res20;
  undefined8 in_stack_ffffffffffffff88;
  undefined8 uVar19;
  undefined8 in_stack_ffffffffffffff98;
  undefined4 uVar20;
  int local_58;
  byte *local_50;
  
  uVar7 = (undefined4)((ulonglong)in_stack_ffffffffffffff88 >> 0x20);
  uVar20 = (undefined4)((ulonglong)in_stack_ffffffffffffff98 >> 0x20);
  uVar2 = *(ulonglong *)(param_1 + 0x40);
  lVar3 = *(longlong *)(param_2 + 0x78);
  uVar15 = 0;
  iVar14 = 0;
  local_res8 = uVar2;
  local_res10 = param_2;
  local_res18 = param_3;
  FUN_000121dc();
  if (*(char *)(lVar3 + 0x1f0) == '\x01') {
    *(undefined1 *)(lVar3 + 0x1f0) = 0;
    return 0;
  }
  lVar4 = *(longlong *)(*(longlong *)(param_2 + 0xb8) + 8);
  *(longlong *)(lVar4 + 8) = lVar3;
  if (*(longlong *)(lVar3 + 0x88 + (ulonglong)*(byte *)(lVar3 + 0x108) * 8) == 0) {
    iVar14 = -0x3fffff66;
  }
  else {
    local_res20 = *(longlong *)(lVar3 + 0x88 + (ulonglong)*(byte *)(lVar3 + 0x108) * 8);
    lVar8 = USBD_ParseConfigurationDescriptorEx
                      (local_res20,local_res20,*(undefined2 *)(param_3 + 0x24),
                       *(undefined2 *)(param_3 + 0x22),CONCAT44(uVar7,0xffffffff),0xffffffff,
                       CONCAT44(uVar20,0xffffffff));
    if (lVar8 != 0) {
      *(uint *)(lVar4 + 0x30) = (uint)*(byte *)(lVar8 + 4);
      *(undefined1 *)(lVar4 + 0x24) = *(undefined1 *)(lVar8 + 5);
      *(undefined1 *)(lVar4 + 0x25) = *(undefined1 *)(lVar8 + 6);
      uVar1 = *(undefined1 *)(lVar8 + 7);
      *(longlong *)(lVar4 + 0x28) = lVar8;
      *(undefined1 *)(lVar4 + 0x26) = uVar1;
      *(undefined1 *)(lVar4 + 0x23) = *(undefined1 *)(lVar8 + 3);
      FUN_000121dc();
      local_58 = 0;
      local_50 = (byte *)USBD_ParseDescriptors(local_res20,*(undefined2 *)(local_res20 + 2),lVar8,5)
      ;
      uVar10 = local_res8;
      if (local_50 != (byte *)0x0) {
        if (((*(byte *)(param_3 + 0x10) & 2) == 0) && ((*(byte *)(param_3 + 0x10) & 4) == 0)) {
          bVar18 = 0;
          pcVar16 = (char *)(uVar2 + 0xaa1);
          do {
            if ((*(char *)(lVar3 + 0x24) == pcVar16[-1]) && (*(char *)(lVar8 + 2) == *pcVar16)) {
              FUN_00020b10(uVar10,bVar18);
            }
            bVar18 = bVar18 + 1;
            pcVar16 = pcVar16 + 0xf8;
          } while (bVar18 < 4);
          param_3 = local_res18;
          param_2 = local_res10;
        }
        lVar5 = local_res20;
        uVar2 = local_res8;
        if (*(char *)(lVar8 + 4) != '\0') {
          pbVar17 = (byte *)(lVar4 + 0x3a);
          do {
            *pbVar17 = local_50[2];
            *(undefined2 *)(pbVar17 + -2) = *(undefined2 *)(local_50 + 4);
            lVar11 = lVar3;
            plVar9 = FUN_0001c104(param_1,lVar3,lVar8,(longlong)local_50);
            *(longlong **)(pbVar17 + 6) = plVar9;
            pbVar17[1] = local_50[6];
            bVar18 = local_50[3];
            *(uint *)(pbVar17 + 2) = bVar18 & 3;
            if (((bVar18 & 3) == 1) && (*(short *)(pbVar17 + -2) != 0)) {
              if ((*pbVar17 & 0x80) == 0) {
                uVar13 = (undefined7)((ulonglong)lVar11 >> 8);
                uVar10 = FUN_00020cc4(param_1,*(undefined1 *)(lVar3 + 0x24),
                                      *(undefined1 *)(lVar8 + 2),(longlong)plVar9,
                                      (byte *)&local_res8);
                uVar15 = uVar10 & 0xffffffff;
                if ((int)uVar10 == 0) {
                  lVar11 = (local_res8 & 0xff) * 0xf8;
                  uVar6 = FUN_000209dc(uVar2,CONCAT71(uVar13,*(undefined1 *)(lVar11 + 0xaa0 + uVar2)
                                                     ),*(undefined1 *)(lVar11 + 0xaa1 + uVar2),
                                       (byte)local_res8);
                  uVar15 = (ulonglong)uVar6;
                }
              }
              else if (*(char *)(lVar4 + 0x23) != '\0') {
                FUN_000121dc();
                FUN_00021198(param_1,*(char *)(lVar3 + 0x24),*(char *)(lVar4 + 0x22),
                             *(undefined8 *)(pbVar17 + 6),*(undefined1 *)(lVar8 + 5),*pbVar17,
                             (byte *)&local_res20);
              }
            }
            iVar14 = (int)uVar15;
            uVar19 = *(undefined8 *)(pbVar17 + 6);
            iVar12 = 2;
            FUN_000121dc();
            local_50 = (byte *)USBD_ParseDescriptors
                                         (lVar5,*(undefined2 *)(lVar5 + 2),local_50 + *local_50,
                                          iVar12 + 3,uVar19);
            pbVar17 = pbVar17 + 0x18;
            local_58 = local_58 + 1;
          } while (local_58 < (int)(uint)*(byte *)(lVar8 + 4));
          param_3 = local_res18;
          param_2 = local_res10;
        }
        goto LAB_0001d3dc;
      }
    }
    iVar14 = -0x3fffffff;
  }
LAB_0001d3dc:
  if ((((*(byte *)(param_3 + 0x10) & 2) == 0) && ((*(byte *)(param_3 + 0x10) & 4) == 0)) &&
     (iVar14 == 0)) {
    *(undefined4 *)(lVar4 + 4) = 0;
    *(undefined4 *)(lVar4 + 0x10) = 0;
    *(longlong *)(lVar4 + 8) = lVar3;
    *(undefined8 *)(lVar4 + 0x18) =
         *(undefined8 *)(lVar3 + 0x88 + (ulonglong)*(byte *)(lVar3 + 0x108) * 8);
  }
  else {
    uVar7 = 0xc0002000;
    if (iVar14 == -0x3fffff66) {
      uVar7 = 0xc0001000;
    }
    *(undefined4 *)(lVar4 + 4) = uVar7;
  }
  FUN_00017594(param_2,iVar14);
  return iVar14;
}



/* ===== FUNC FUN_0001d448 @ 0001d448 ===== */

undefined8 FUN_0001d448(longlong param_1,longlong param_2)

{
  longlong lVar1;
  byte bVar2;
  int iVar3;
  byte bVar4;
  longlong lVar5;
  
  lVar1 = *(longlong *)(param_1 + 0x40);
  lVar5 = param_1;
  FUN_000121dc();
  bVar2 = 0;
  iVar3 = -0x3ffffff2;
  while ((*(char *)(param_2 + 6) !=
          *(char *)((ulonglong)bVar2 * 0xf8 + 0xaa0 + *(longlong *)(param_1 + 0x40)) ||
         (*(byte *)(param_2 + 0x1e) >> 4 !=
          *(byte *)((ulonglong)bVar2 * 0xf8 + 0xaa2 + *(longlong *)(param_1 + 0x40))))) {
    bVar2 = bVar2 + 1;
    bVar4 = 0xff;
    if (3 < bVar2) {
LAB_0001d4c5:
      FUN_000121dc();
      if (iVar3 == 0) {
        FUN_00020f4c(lVar5,lVar1,bVar4);
      }
      return 0;
    }
  }
  iVar3 = 0;
  bVar4 = bVar2;
  goto LAB_0001d4c5;
}



/* ===== FUNC FUN_0001d504 @ 0001d504 ===== */

int FUN_0001d504(undefined8 param_1,longlong param_2,longlong param_3)

{
  char cVar1;
  uint uVar2;
  longlong lVar3;
  longlong lVar4;
  longlong lVar5;
  void *_Dst;
  byte *_Src;
  size_t _Size;
  int iVar6;
  
  lVar3 = *(longlong *)(param_2 + 0x78);
  iVar6 = 0;
  lVar4 = *(longlong *)(*(longlong *)(param_2 + 0xb8) + 8);
  uVar2 = *(uint *)(lVar4 + 0x24);
  cVar1 = *(char *)(lVar4 + 0x83);
  FUN_000121dc();
  _Dst = *(void **)(lVar4 + 0x28);
  if (_Dst == (void *)0x0) {
    lVar5 = *(longlong *)(lVar4 + 0x30);
    if (lVar5 == 0) {
      FUN_000121dc();
      iVar6 = -0x3fffffff;
      goto LAB_0001d661;
    }
    if ((*(byte *)(lVar5 + 10) & 5) == 0) {
      _Dst = (void *)MmMapLockedPagesSpecifyCache(lVar5,0,1,0,0,0x10);
    }
    else {
      _Dst = *(void **)(lVar5 + 0x18);
    }
  }
  if (cVar1 == '\x02') {
    FUN_000121dc();
    _Src = *(byte **)(lVar3 + 0x88 + (ulonglong)*(byte *)(lVar3 + 0x108) * 8);
    _Size = (size_t)*(ushort *)(_Src + 2);
LAB_0001d5c6:
    if ((uint)_Size < uVar2) {
LAB_0001d5cd:
      memcpy(_Dst,_Src,_Size);
      *(int *)(lVar4 + 0x24) = (int)_Size;
    }
    else {
LAB_0001d636:
      memcpy(_Dst,_Src,(ulonglong)uVar2);
    }
  }
  else {
    if (cVar1 == '\x01') {
      FUN_000121dc();
      _Src = (byte *)(lVar3 + 0x74);
      _Size = (size_t)*_Src;
      goto LAB_0001d5c6;
    }
    if (cVar1 == '\x03') {
      FUN_000121dc();
      _Size = (size_t)*(byte *)(param_3 + 0x28);
      _Src = (byte *)(param_3 + 0x28);
      if (uVar2 < *(byte *)(param_3 + 0x28)) goto LAB_0001d636;
      goto LAB_0001d5cd;
    }
  }
  *(undefined4 *)(lVar4 + 4) = 0;
  *(longlong *)(lVar4 + 8) = lVar3;
  *(undefined4 *)(lVar4 + 0x10) = 0x22;
LAB_0001d661:
  FUN_00017594(param_2,iVar6);
  return iVar6;
}



/* ===== FUNC FUN_0001d690 @ 0001d690 ===== */

undefined8 FUN_0001d690(undefined8 param_1,longlong param_2,longlong param_3)

{
  longlong lVar1;
  void *_Dst;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint local_res10;
  
  uVar4 = *(uint *)(param_2 + 0x24);
  uVar3 = (*(byte *)(param_3 + 0x15) & 0xf) * 0x100 + -8 + (uint)*(byte *)(param_3 + 0x14);
  _Dst = (void *)FUN_000121dc();
  if (((*(byte *)(param_3 + 0x10) & 2) == 0) && ((*(byte *)(param_3 + 0x10) & 4) == 0)) {
    iVar2 = (uint)_Dst + 1;
    if ((*(byte *)(param_2 + 0x20) & (byte)iVar2) != 0) {
      local_res10 = uVar4;
      if (uVar3 <= uVar4) {
        local_res10 = uVar3;
      }
      if ((uVar4 != 0) && (_Dst = *(void **)(param_2 + 0x28), _Dst == (void *)0x0)) {
        lVar1 = *(longlong *)(param_2 + 0x30);
        if (lVar1 == 0) {
          FUN_000121dc();
          return 0;
        }
        if ((*(byte *)(lVar1 + 10) & 5) == 0) {
          _Dst = (void *)MmMapLockedPagesSpecifyCache(lVar1,0,iVar2,0,0,0x10);
        }
        else {
          _Dst = *(void **)(lVar1 + 0x18);
        }
      }
      *(uint *)(param_2 + 0x24) = local_res10;
    }
    *(uint *)(param_2 + 0x20) = *(uint *)(param_2 + 0x20) | 8;
    if (_Dst != (void *)0x0) {
      memcpy(_Dst,(void *)(param_3 + 0x28),(ulonglong)local_res10);
    }
    *(undefined4 *)(param_2 + 0x40) = 0xffffffff;
    *(undefined4 *)(param_2 + 0x44) = 0xdeadf00d;
    *(undefined4 *)(param_2 + 0x48) = 0xe2ffa4a8;
    *(undefined4 *)(param_2 + 4) = 0;
    *(undefined4 *)(param_2 + 0x10) = 0x22;
  }
  else {
    *(uint *)(param_2 + 0x24) = *(uint *)(param_2 + 0x24) & (uint)_Dst;
    *(undefined4 *)(param_2 + 4) = 0xc0008000;
  }
  return 0;
}



/* ===== FUNC FUN_0001d7b0 @ 0001d7b0 ===== */

undefined4
FUN_0001d7b0(longlong param_1,undefined8 param_2,undefined1 param_3,longlong param_4,
            longlong param_5)

{
  longlong lVar1;
  longlong lVar2;
  byte bVar3;
  int iVar4;
  undefined8 uVar5;
  undefined4 uVar6;
  char *pcVar7;
  undefined7 uVar8;
  longlong lVar9;
  
  lVar1 = *(longlong *)(param_4 + 0x78);
  uVar6 = 0;
  lVar2 = *(longlong *)(*(longlong *)(param_4 + 0xb8) + 8);
  bVar3 = 3;
  iVar4 = 0;
  lVar9 = param_4;
  uVar5 = param_2;
  FUN_000121dc();
  bVar3 = *(byte *)(param_5 + 0x1f) >> 2 & bVar3;
  if (bVar3 == 1) {
    iVar4 = FUN_0001d924(param_1,lVar9,param_5);
  }
  else {
    if (bVar3 != 0) {
      FUN_000121dc();
      goto LAB_0001d84d;
    }
    uVar5 = FUN_0001dc40(param_1,lVar9,param_5);
    iVar4 = (int)uVar5;
  }
  uVar5 = param_2;
LAB_0001d84d:
  FUN_00021370(iVar4);
  pcVar7 = "    BoI_TransferCompletion_2: %s \n";
  FUN_000121dc();
  uVar8 = (undefined7)((ulonglong)pcVar7 >> 8);
  if ((*(char *)(lVar1 + 0x69) == '\0') || (*(char *)(lVar1 + 0x6d) == '\0')) {
    *(undefined8 *)(param_4 + 0x38) = 0;
    iVar4 = -0x3fffff63;
    *(undefined4 *)(lVar2 + 4) = 0xc0007000;
    uVar6 = 0xc000009d;
    FUN_0001e010(param_1,uVar5,CONCAT71(uVar8,param_3),*(longlong *)(lVar2 + 0x18));
  }
  else {
    if (iVar4 == 0x103) {
      return 0;
    }
    if ((iVar4 == 0) && ((*(byte *)(param_5 + 0x1f) & 0xc) == 4)) {
      *(undefined8 *)(param_4 + 0x38) = *(undefined8 *)(param_4 + 0x80);
    }
    else {
      *(undefined8 *)(param_4 + 0x38) = 0;
    }
    FUN_0001e010(param_1,uVar5,CONCAT71(uVar8,param_3),*(longlong *)(lVar2 + 0x18));
    *(undefined8 *)(lVar2 + 8) = *(undefined8 *)(param_4 + 0x78);
    FUN_000121dc();
  }
  FUN_00017594(param_4,iVar4);
  return uVar6;
}



/* ===== FUNC FUN_0001d924 @ 0001d924 ===== */

int FUN_0001d924(longlong param_1,longlong param_2,longlong param_3)

{
  int *piVar1;
  undefined4 uVar2;
  longlong lVar3;
  longlong lVar4;
  uint uVar5;
  longlong lVar6;
  undefined8 uVar7;
  int iVar8;
  ushort uVar9;
  uint uVar10;
  uint uVar11;
  ushort uVar12;
  ulonglong uVar13;
  ushort uVar14;
  
  lVar3 = *(longlong *)(param_1 + 0x40);
  lVar4 = *(longlong *)(*(longlong *)(param_2 + 0xb8) + 8);
  uVar5 = *(uint *)(lVar4 + 0x24);
  uVar11 = (*(byte *)(param_3 + 0x15) & 0xf) * 0x100 + (uint)*(byte *)(param_3 + 0x14);
  FUN_000121dc();
  lVar6 = FUN_00018ef0(param_1,lVar4);
  if (lVar6 == 0) {
    return -0x3fffffff;
  }
  uVar10 = *(uint *)(param_2 + 0x80);
  if (((*(byte *)(param_3 + 0x1a) & 0x80) != 0) && (uVar11 != 0)) {
    uVar9 = (ushort)uVar11;
    uVar14 = *(ushort *)(param_3 + 0x1c) & 0xfff;
    uVar13 = 0;
    do {
      uVar12 = uVar14;
      if (uVar9 <= uVar14) {
        uVar12 = uVar9;
      }
      FUN_00015e9c(*(byte *)(param_3 + 0x1b),(byte *)(uVar13 + param_3 + 0x20),uVar12);
      uVar12 = (short)uVar13 + uVar14;
      uVar13 = (ulonglong)uVar12;
      uVar9 = uVar9 - uVar14;
    } while (uVar12 < uVar11);
  }
  iVar8 = 0;
  memcpy((void *)(lVar6 + (ulonglong)uVar10),(void *)(param_3 + 0x20),(ulonglong)uVar11);
  uVar10 = uVar10 + uVar11;
  *(ulonglong *)(param_2 + 0x80) = (ulonglong)uVar10;
  if ((*(char *)(param_3 + 7) == '\x05') && ((*(byte *)(param_3 + 0x11) & 0xf) == 10)) {
    FUN_000121dc();
    uVar7 = FUN_0001c704(param_1,param_2,*(byte *)(param_3 + 6));
    iVar8 = (int)uVar7;
  }
  else {
    if (uVar5 == uVar10) {
      uVar2 = *(undefined4 *)(param_2 + 0x80);
      *(undefined4 *)(lVar4 + 4) = 0;
      *(undefined4 *)(lVar4 + 0x24) = uVar2;
      goto LAB_0001dacc;
    }
    if (uVar5 <= uVar10) goto LAB_0001dacc;
    uVar9 = *(ushort *)(*(longlong *)(*(longlong *)(lVar4 + 0x18) + 0x10) + 4) & 0x7ff;
    if ((uVar11 == 0) ||
       (uVar5 = (uint)(ushort)((short)(((ulonglong)*(ushort *)(lVar3 + 0x2000) - 0x30) /
                                      (ulonglong)uVar9) * uVar9), uVar11 < uVar5)) {
      uVar2 = *(undefined4 *)(param_2 + 0x80);
      *(undefined4 *)(lVar4 + 4) = 0;
      iVar8 = 0;
      *(undefined4 *)(lVar4 + 0x24) = uVar2;
    }
    else if (uVar11 == uVar5) {
      if (*(byte *)(param_3 + 0xf) < *(byte *)(param_3 + 0xe)) {
        lVar6 = ExAllocatePoolWithTag(0,0x38,0x53747345);
        if (lVar6 != 0) {
          *(byte *)(lVar6 + 0x12) = *(byte *)(param_3 + 0x1e) & 0xf;
          *(byte *)(lVar6 + 0x13) = *(byte *)(param_3 + 0x1e) >> 4;
          *(char *)(lVar6 + 0x14) = *(char *)(param_3 + 7) + -1;
          FUN_00017da0(param_1,param_2,lVar6);
          return 0x103;
        }
        uVar2 = *(undefined4 *)(param_2 + 0x80);
        *(undefined4 *)(lVar4 + 4) = 0;
        *(undefined4 *)(lVar4 + 0x24) = uVar2;
        goto LAB_0001dacc;
      }
      if (*(byte *)(param_3 + 0xf) != *(byte *)(param_3 + 0xe)) goto LAB_0001dacc;
      uVar7 = FUN_0001c704(param_1,param_2,*(byte *)(param_3 + 6));
      iVar8 = (int)uVar7;
    }
    else {
      FUN_000121dc();
    }
  }
  if (iVar8 != 0) {
    return iVar8;
  }
LAB_0001dacc:
  if (*(char *)(param_3 + 7) == '\x05') {
    FUN_000121dc();
    LOCK();
    piVar1 = (int *)((ulonglong)*(byte *)(param_3 + 6) * 0x268 + 0x1088 + lVar3);
    *piVar1 = *piVar1 + *(int *)(lVar4 + 0x24);
    UNLOCK();
  }
  return 0;
}



/* ===== FUNC FUN_0001dc40 @ 0001dc40 ===== */

undefined8 FUN_0001dc40(longlong param_1,longlong param_2,longlong param_3)

{
  int *piVar1;
  longlong lVar2;
  longlong lVar3;
  longlong lVar4;
  undefined8 *puVar5;
  undefined8 uVar6;
  uint uVar7;
  ushort uVar8;
  uint uVar9;
  uint uVar10;
  
  lVar2 = *(longlong *)(param_1 + 0x40);
  lVar3 = *(longlong *)(*(longlong *)(param_2 + 0xb8) + 8);
  uVar10 = *(uint *)(lVar3 + 0x24);
  lVar4 = *(longlong *)(*(longlong *)(lVar3 + 0x18) + 0x10);
  uVar9 = (*(byte *)(param_3 + 0x15) & 0xf) * 0x100 + (uint)*(byte *)(param_3 + 0x14);
  uVar8 = *(ushort *)(lVar4 + 4) & 0x7ff;
  uVar6 = 0;
  uVar8 = (short)(((ulonglong)*(ushort *)(lVar2 + 0x2000) - 0x30) / (ulonglong)uVar8) * uVar8;
  uVar7 = (*(byte *)(param_3 + 0xf) - 1) * (uint)uVar8 + *(int *)(param_2 + 0x80) + uVar9;
  if ((*(char *)(*(longlong *)(*(longlong *)(lVar3 + 0x18) + 8) + 5) == '\a') &&
     ((*(byte *)(lVar4 + 3) & 3) == 2)) {
    for (puVar5 = *(undefined8 **)(lVar2 + 0xef8); puVar5 != (undefined8 *)(lVar2 + 0xef8);
        puVar5 = (undefined8 *)*puVar5) {
      if ((((char *)(puVar5 + -1) != (char *)0x0) &&
          (*(char *)(puVar5 + -1) == *(char *)(param_3 + 6))) &&
         (*(char *)((longlong)puVar5 + -7) == *(char *)(lVar4 + 2))) {
        if ((*(byte *)(param_3 + 0x11) & 0xf) == 10) {
          if (*(ushort *)((longlong)puVar5 + -6) < 10) {
            *(ulonglong *)(param_2 + 0x80) = (ulonglong)uVar7;
            FUN_0001f9e0(param_1,param_2);
            uVar6 = 0x103;
            FUN_000121dc();
            goto LAB_0001dedd;
          }
          *(undefined2 *)((longlong)puVar5 + -6) = 0;
          *(undefined1 *)(puVar5 + 2) = 0;
          *(undefined4 *)(lVar3 + 4) = 0;
          *(uint *)(lVar3 + 0x24) = uVar7;
          FUN_000121dc();
          goto LAB_0001dea3;
        }
        *(undefined2 *)((longlong)puVar5 + -6) = 0;
        *(undefined1 *)(puVar5 + 2) = 0;
        FUN_000121dc();
        break;
      }
    }
  }
  if ((uVar9 == 0) || (uVar9 < uVar8)) {
LAB_0001de9d:
    *(undefined4 *)(lVar3 + 4) = 0;
    *(uint *)(lVar3 + 0x24) = uVar7;
  }
  else if (uVar9 == uVar8) {
    if (uVar7 == uVar10) goto LAB_0001de9d;
    if (uVar7 < uVar10) {
      *(ulonglong *)(param_2 + 0x80) = (ulonglong)uVar7;
      FUN_0001f9e0(param_1,param_2);
      uVar6 = 0x103;
      goto LAB_0001dedd;
    }
  }
LAB_0001dea3:
  if (*(char *)(param_3 + 7) == '\x03') {
    FUN_000121dc();
    LOCK();
    piVar1 = (int *)((ulonglong)*(byte *)(param_3 + 6) * 0x268 + 0x108c + lVar2);
    *piVar1 = *piVar1 + *(int *)(lVar3 + 0x24);
    UNLOCK();
  }
LAB_0001dedd:
  KeSetEvent((ulonglong)*(byte *)(param_3 + 6) * 0xd0 + 0x610 + lVar2,0,0);
  return uVar6;
}



/* ===== FUNC FUN_0001df20 @ 0001df20 ===== */

int FUN_0001df20(undefined8 param_1,longlong param_2,longlong param_3)

{
  uint uVar1;
  longlong lVar2;
  longlong lVar3;
  void *_Dst;
  int iVar4;
  
  iVar4 = 0;
  lVar2 = *(longlong *)(*(longlong *)(param_2 + 0xb8) + 8);
  FUN_000121dc();
  _Dst = *(void **)(lVar2 + 0x28);
  if (_Dst == (void *)0x0) {
    lVar3 = *(longlong *)(lVar2 + 0x30);
    if (lVar3 == 0) {
      FUN_000121dc();
      uVar1 = *(uint *)(param_2 + 0x38);
      iVar4 = -0x3fffffff;
      goto LAB_0001dfd7;
    }
    if ((*(byte *)(lVar3 + 10) & 5) == 0) {
      _Dst = (void *)MmMapLockedPagesSpecifyCache(lVar3,0,1,0,0,0x10);
    }
    else {
      _Dst = *(void **)(lVar3 + 0x18);
    }
  }
  uVar1 = (*(byte *)(param_3 + 0x15) & 0xf) * 0x100 + -8 + (uint)*(byte *)(param_3 + 0x14);
  memcpy(_Dst,(void *)(param_3 + 0x28),(ulonglong)uVar1);
LAB_0001dfd7:
  *(undefined4 *)(lVar2 + 4) = 0;
  *(ulonglong *)(param_2 + 0x38) = (ulonglong)uVar1;
  FUN_00017594(param_2,iVar4);
  return iVar4;
}



/* ===== FUNC FUN_0001e010 @ 0001e010 ===== */

int FUN_0001e010(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  char *pcVar1;
  int iVar2;
  longlong lVar3;
  int iVar4;
  undefined8 local_res20;
  
  local_res20 = 0xfffffffffff0bdc0;
  iVar2 = KeWaitForSingleObject(param_4 + 0x30,0,0,0,&local_res20);
  if (((iVar2 == 0) || (iVar2 == 0x102)) && (1 < *(byte *)(param_4 + 0x1c))) {
    lVar3 = FUN_00017df4(param_1);
    iVar4 = 2;
    if (lVar3 == 0) {
      FUN_000121dc();
    }
    else {
      *(longlong *)(lVar3 + 0x20) = param_4;
      lVar3 = FUN_000121dc();
      IoQueueWorkItem(*(undefined8 *)(lVar3 + 0x18),FUN_0001e0e0,iVar4 + -1,lVar3);
    }
  }
  pcVar1 = (char *)(param_4 + 0x1c);
  *pcVar1 = *pcVar1 + -1;
  if (*pcVar1 == '\0') {
    KeSetEvent(param_4 + 0x30,0,0);
  }
  return iVar2;
}



/* ===== FUNC FUN_0001e0e0 @ 0001e0e0 ===== */

void FUN_0001e0e0(longlong param_1,longlong param_2)

{
  longlong lVar1;
  longlong lVar2;
  longlong lVar3;
  longlong lVar4;
  
  lVar1 = *(longlong *)(param_2 + 0x20);
  lVar2 = *(longlong *)(param_1 + 0x40);
  FUN_000121dc();
  if (lVar1 != 0) {
    FUN_000121dc();
    lVar3 = IoCsqRemoveNextIrp(lVar1 + 0x50,0);
    if (lVar3 != 0) {
      lVar4 = FUN_000121dc();
      lVar3 = *(longlong *)(lVar4 + 0x78);
      FUN_0001f9e0(param_1,lVar4);
      KeSetEvent((ulonglong)*(byte *)(lVar3 + 0x24) * 0xd0 + 0x610 + lVar2,0,0);
    }
    if (*(longlong *)(param_2 + 0x18) != 0) {
      IoFreeWorkItem();
      *(undefined8 *)(param_2 + 0x18) = 0;
    }
    ExFreePoolWithTag(param_2,0x53747345);
    KeSetEvent(lVar1 + 0x30,0,0);
  }
  return;
}



/* ===== FUNC FUN_0001e1dc @ 0001e1dc ===== */

undefined8 FUN_0001e1dc(longlong param_1,longlong param_2)

{
  longlong lVar1;
  int *piVar2;
  longlong lVar3;
  longlong lVar4;
  longlong lVar5;
  longlong lVar6;
  longlong lVar7;
  ulonglong uVar8;
  uint uVar9;
  int iVar10;
  byte bVar11;
  ushort *puVar12;
  ulonglong uVar13;
  uint uVar14;
  byte local_res10;
  byte local_res18 [8];
  byte local_res20;
  uint local_84;
  undefined1 local_68 [16];
  byte local_58;
  byte local_57;
  
  lVar3 = *(longlong *)(param_1 + 0x40);
  uVar14 = 0;
  local_84 = 0;
  local_res18[0] = 0;
  FUN_000121dc();
  local_res10 = *(byte *)(param_2 + 0xf);
  lVar1 = (ulonglong)(byte)(*(char *)(param_2 + 0xe) * '\x02') + 0x20 + param_2;
  local_res20 = local_res10;
  while( true ) {
    if (local_res10 == 0) {
      return 0;
    }
    local_58 = *(byte *)(param_2 + 0x1e) & 0xf;
    local_57 = *(byte *)(param_2 + 0x1e) >> 4;
    lVar5 = IoCsqRemoveNextIrp(*(longlong *)(param_1 + 0x40) + 0x270,local_68);
    if (lVar5 == 0) break;
    lVar6 = FUN_000121dc();
    lVar4 = *(longlong *)(lVar6 + 0x88);
    lVar6 = *(longlong *)(*(longlong *)(lVar6 + 0xb8) + 8);
    if ((uint)local_res10 < *(uint *)(lVar4 + 0x14)) {
      uVar9 = 0;
      if (local_res10 != 0) {
        puVar12 = (ushort *)
                  (param_2 + 0x20 + ((longlong)(int)-(uint)local_res10 + (ulonglong)local_res20) * 2
                  );
        do {
          uVar14 = (uint)*puVar12;
          *(uint *)(lVar6 + ((ulonglong)((uVar9 - *(int *)(lVar4 + 0x14)) + *(int *)(lVar6 + 0x84))
                             * 3 + 0x24) * 4) = uVar14;
          *(undefined4 *)
           (lVar6 + 0x94 +
           (ulonglong)((uVar9 - *(int *)(lVar4 + 0x14)) + *(int *)(lVar6 + 0x84)) * 0xc) = 0;
          memcpy((void *)((ulonglong)
                          *(uint *)(lVar6 + 0x8c +
                                   (ulonglong)
                                   ((uVar9 - *(int *)(lVar4 + 0x14)) + *(int *)(lVar6 + 0x84)) * 0xc
                                   ) + *(longlong *)(lVar6 + 0x28)),
                 (void *)((ulonglong)local_84 + lVar1),(ulonglong)uVar14);
          bVar11 = (char)uVar9 + 1;
          uVar9 = (uint)bVar11;
          local_84 = local_84 + uVar14;
          puVar12 = puVar12 + 1;
        } while (bVar11 < local_res10);
      }
      *(int *)(lVar4 + 0x14) = *(int *)(lVar4 + 0x14) - (uint)local_res10;
      *(uint *)(lVar4 + 0x18) =
           uVar14 + *(int *)(lVar6 + 0x8c +
                            (ulonglong)((*(int *)(lVar6 + 0x84) - *(int *)(lVar4 + 0x14)) - 1) * 0xc
                            );
      FUN_000121dc();
      FUN_00020fc4(param_1,lVar5,lVar4,'\0');
      return 0;
    }
    if (*(int *)(lVar4 + 0x14) != 0) {
      uVar13 = (ulonglong)local_res20;
      uVar9 = 0;
      uVar8 = 0;
      do {
        lVar7 = uVar8 + uVar13 + (longlong)(int)-(uint)local_res10;
        uVar14 = (uint)CONCAT11(*(undefined1 *)(param_2 + 0x21 + lVar7 * 2),
                                *(undefined1 *)(param_2 + 0x20 + lVar7 * 2));
        *(uint *)(lVar6 + ((ulonglong)((uVar9 - *(int *)(lVar4 + 0x14)) + *(int *)(lVar6 + 0x84)) *
                           3 + 0x24) * 4) = uVar14;
        *(undefined4 *)
         (lVar6 + 0x94 +
         (ulonglong)((uVar9 - *(int *)(lVar4 + 0x14)) + *(int *)(lVar6 + 0x84)) * 0xc) = 0;
        memcpy((void *)((ulonglong)
                        *(uint *)(lVar6 + 0x8c +
                                 (ulonglong)
                                 ((uVar9 - *(int *)(lVar4 + 0x14)) + *(int *)(lVar6 + 0x84)) * 0xc)
                       + *(longlong *)(lVar6 + 0x28)),(void *)((ulonglong)local_84 + lVar1),
               (ulonglong)uVar14);
        bVar11 = (char)uVar8 + 1;
        uVar8 = (ulonglong)bVar11;
        local_84 = local_84 + uVar14;
        uVar9 = (uint)bVar11;
      } while (uVar9 < *(uint *)(lVar4 + 0x14));
    }
    local_res10 = local_res10 - *(char *)(lVar4 + 0x14);
    iVar10 = *(int *)(lVar6 + 0x8c +
                     (ulonglong)((*(int *)(lVar6 + 0x84) - *(int *)(lVar4 + 0x14)) - 1) * 0xc) +
             uVar14;
    *(int *)(lVar4 + 0x18) = iVar10;
    *(int *)(lVar6 + 0x24) = iVar10;
    FUN_000121dc();
    FUN_00021144(param_1,*(byte *)(param_2 + 0x1e) & 0xf,*(byte *)(param_2 + 0x1e) >> 4 | 0x80,
                 local_res18);
    uVar8 = (ulonglong)local_res18[0];
    *(undefined1 *)(lVar3 + 0x2fc + uVar8 * 0x48) = 1;
    uVar9 = *(uint *)(lVar6 + 0x84);
    if (*(char *)(*(longlong *)(lVar5 + 0x78) + 0x41) == '\x02') {
      uVar9 = uVar9 >> 3;
    }
    piVar2 = (int *)(lVar3 + 0x2f0 + uVar8 * 0x48);
    *piVar2 = *piVar2 + uVar9;
    *(undefined4 *)(lVar6 + 0x80) = *(undefined4 *)(lVar3 + 0x2f0 + uVar8 * 0x48);
    FUN_000121dc();
    ExFreePoolWithTag(lVar4);
    FUN_00017594(lVar5,0);
  }
  FUN_000121dc();
  return 0;
}



/* ===== FUNC FUN_0001e5bc @ 0001e5bc ===== */

void FUN_0001e5bc(longlong param_1,undefined1 param_2,longlong param_3,undefined1 param_4)

{
  int *piVar1;
  int iVar2;
  longlong lVar3;
  longlong *plVar4;
  short sVar5;
  
  lVar3 = *(longlong *)(param_1 + 0x40);
  plVar4 = (longlong *)FUN_00017df4(param_1);
  if (plVar4 != (longlong *)0x0) {
    plVar4[1] = 0;
    *plVar4 = param_1;
    do {
      LOCK();
      piVar1 = (int *)(lVar3 + 0x210);
      iVar2 = *piVar1;
      *piVar1 = *piVar1 + 1;
      UNLOCK();
      sVar5 = (short)iVar2 + 1;
    } while (sVar5 == 0);
    *(short *)(plVar4 + 2) = sVar5;
    *(undefined1 *)((longlong)plVar4 + 0x12) = param_2;
    *(undefined1 *)((longlong)plVar4 + 0x13) = param_4;
    plVar4[4] = param_3;
    IoQueueWorkItem(plVar4[3],FUN_00018410,1,plVar4);
  }
  return;
}



/* ===== FUNC FUN_0001e658 @ 0001e658 ===== */

undefined8 FUN_0001e658(longlong param_1,longlong param_2)

{
  void *_Src;
  char cVar1;
  longlong lVar2;
  uint uVar3;
  void *_Dst;
  ulonglong *_Dst_00;
  byte *pbVar4;
  char cVar5;
  ulonglong uVar6;
  byte bVar7;
  ushort uVar8;
  uint uVar9;
  longlong lVar10;
  byte bVar11;
  
  lVar2 = *(longlong *)(param_1 + 0x40);
  _Src = (void *)(param_2 + 0x28);
  bVar11 = *(byte *)(param_2 + 0x1e) & 0xf;
  cVar5 = '\x02';
  uVar8 = (*(ushort *)(param_2 + 4) >> 8 | *(ushort *)(param_2 + 4) << 8) - 8;
  FUN_000121dc();
  cVar1 = *(char *)(param_2 + 0x29);
  if (cVar1 == '\x01') {
    FUN_000121dc();
    memcpy((void *)(((ulonglong)bVar11 + 7) * 0x268 + lVar2),_Src,(ulonglong)uVar8);
  }
  else if (cVar1 == cVar5) {
    FUN_000121dc();
    _Dst = (void *)ExAllocatePoolWithTag(0,(ulonglong)uVar8,0x34747345);
    if (_Dst != (void *)0x0) {
      memcpy(_Dst,_Src,(ulonglong)uVar8);
      lVar10 = (ulonglong)bVar11 * 0x268;
      *(void **)((ulonglong)*(byte *)(lVar10 + 0x11f0 + lVar2) * 0x10 + lVar10 + 0x10f8 + lVar2) =
           _Dst;
      *(ushort *)(((ulonglong)*(byte *)(lVar10 + 0x11f0 + lVar2) + 0x10f) * 0x10 + lVar10 + lVar2) =
           uVar8;
    }
  }
  else {
    if (cVar1 != '\x03') {
      FUN_000121dc();
      return 0xc0000001;
    }
    FUN_000121dc();
    _Dst_00 = (ulonglong *)ExAllocatePoolWithTag(1,uVar8,0x34747345);
    if (_Dst_00 != (ulonglong *)0x0) {
      FUN_000251f0(_Dst_00,0xff,(ulonglong)uVar8);
      memcpy(_Dst_00,_Src,(ulonglong)uVar8);
      lVar10 = (ulonglong)bVar11 * 0x268;
      cVar1 = *(char *)(param_2 + 0x22);
      if (cVar1 == *(char *)(lVar10 + 0x10e6 + lVar2)) {
        FUN_000121dc();
        *(ushort *)(lVar10 + 0x11f8 + lVar2) = uVar8;
        *(ulonglong **)(lVar10 + 0x1200 + lVar2) = _Dst_00;
      }
      else if (cVar1 == *(char *)(lVar10 + 0x10e7 + lVar2)) {
        FUN_000121dc();
        *(ushort *)(lVar10 + 0x1208 + lVar2) = uVar8;
        *(ulonglong **)(lVar10 + 0x1210 + lVar2) = _Dst_00;
      }
      else if (cVar1 == *(char *)(lVar10 + 0x10e8 + lVar2)) {
        uVar9 = (uint)uVar8;
        *(ushort *)(lVar10 + 0x1218 + lVar2) = uVar8;
        *(ulonglong **)(lVar10 + 0x1220 + lVar2) = _Dst_00;
        uVar6 = 3;
        if (2 < (int)(uVar8 - 1)) {
          do {
            bVar7 = (char)uVar6 + 2;
            *(undefined1 *)(uVar6 + (longlong)_Dst_00) = 0;
            uVar6 = (ulonglong)bVar7;
          } while ((int)(uint)bVar7 <= (int)(uVar8 - 1));
        }
        uVar6 = 2;
        FUN_000121dc();
        uVar3 = (uint)uVar6;
        while ((int)uVar3 <= (int)(uVar9 - 2)) {
          pbVar4 = (byte *)((uVar6 & 0xff) + (longlong)_Dst_00);
          if (*pbVar4 < 0x20) {
            *pbVar4 = 0x20;
          }
          if (0x7e < *pbVar4) {
            *pbVar4 = 0x7e;
          }
          bVar7 = (char)uVar6 + 2;
          uVar6 = (ulonglong)bVar7;
          uVar3 = (uint)bVar7;
        }
      }
      else {
        FUN_000121dc();
      }
    }
  }
  KeSetEvent((ulonglong)bVar11 * 0x268 + 0xff8 + lVar2,0,0);
  return 0;
}



/* ===== FUNC FUN_0001e930 @ 0001e930 ===== */

void FUN_0001e930(longlong param_1,longlong param_2,longlong param_3,longlong param_4,
                 longlong param_5)

{
  char cVar1;
  char *pcVar2;
  
  cVar1 = '\x01';
  FUN_000121dc();
  if ((*(char *)(param_5 + 1) == '\f') || (*(char *)(param_5 + 1) == cVar1)) {
    FUN_000121dc();
    *(undefined4 *)(param_3 + 4) = 0xc0000011;
  }
  else {
    *(undefined4 *)(param_3 + 4) = 0xc0000004;
  }
  cVar1 = *(char *)(param_4 + 7);
  if ((((cVar1 == '\x03') || (cVar1 == '\x05')) || (cVar1 == ')')) || (cVar1 == '\t')) {
    pcVar2 = " !  Receives Halted error. TransferBufferLength_%d %s\n";
    FUN_000121dc();
    FUN_0001e010(param_1,*(undefined8 *)(param_1 + 0x40),
                 CONCAT71((int7)((ulonglong)pcVar2 >> 8),*(undefined1 *)(param_4 + 6)),
                 *(longlong *)(param_3 + 0x18));
  }
  FUN_00017594(param_2,-0x3fffffff);
  return;
}



/* ===== FUNC FUN_0001e9ec @ 0001e9ec ===== */

ulonglong FUN_0001e9ec(longlong param_1,longlong param_2)

{
  int iVar1;
  uint uVar2;
  int *piVar3;
  longlong lVar4;
  undefined8 uVar5;
  char cVar6;
  int iVar7;
  ulonglong uVar8;
  
  iVar1 = *(int *)(*(longlong *)(param_2 + 0xb8) + 8);
  iVar7 = *(int *)(*(longlong *)(param_2 + 0xb8) + 0x18);
  uVar8 = 0xc00000bb;
  FUN_000121dc();
  if (iVar7 == 0x220408) {
    if (iVar1 == 0x4c) {
      piVar3 = (int *)FUN_000121dc();
      uVar8 = 0;
      if (*piVar3 == 0) {
        lVar4 = FUN_000121dc();
        *(undefined2 *)(lVar4 + 7) = 0xd;
        *(undefined1 *)(lVar4 + 9) = 0x32;
LAB_0001eb10:
        *(undefined1 *)(lVar4 + 0x4b) = 1;
        *(char *)(lVar4 + 10) = (char)uVar8;
        *(undefined1 *)(lVar4 + 6) = 5;
        *(undefined1 *)(lVar4 + 5) = 0x29;
        *(undefined1 *)(lVar4 + 4) = 0x47;
      }
      else {
        if (*piVar3 != 1) {
          lVar4 = FUN_000121dc();
          *(short *)(lVar4 + 7) = (short)uVar8;
          *(char *)(lVar4 + 9) = (char)uVar8;
          goto LAB_0001eb10;
        }
        lVar4 = FUN_000121dc();
        *(undefined4 *)(lVar4 + 4) = 1;
      }
      *(undefined8 *)(param_2 + 0x38) = 0x4c;
      goto LAB_0001eb3c;
    }
    uVar5 = FUN_0001eb7c(param_1,param_2);
    uVar2 = (uint)uVar5;
  }
  else if (iVar7 == 0x22040c) {
    cVar6 = '\0';
LAB_0001ea60:
    uVar2 = FUN_0001f0f8(param_1,param_2,cVar6);
  }
  else if (iVar7 == 0x220410) {
    uVar8 = FUN_0001ed50(param_1,param_2);
    uVar2 = (uint)uVar8;
  }
  else if (iVar7 == 0x220420) {
    uVar2 = FUN_0001f028(param_1,param_2);
  }
  else {
    if (iVar7 != 0x220424) {
      if (iVar7 != 0x220448) goto LAB_0001eb3c;
      cVar6 = '\x01';
      goto LAB_0001ea60;
    }
    uVar2 = FUN_0001ec7c(param_1,param_2);
  }
  uVar8 = (ulonglong)uVar2;
LAB_0001eb3c:
  FUN_00021370((int)uVar8);
  FUN_000121dc();
  return uVar8 & 0xffffffff;
}



/* ===== FUNC FUN_0001eb7c @ 0001eb7c ===== */

undefined8 FUN_0001eb7c(longlong param_1,longlong param_2)

{
  uint *puVar1;
  longlong lVar2;
  uint uVar3;
  ulonglong uVar4;
  
  puVar1 = *(uint **)(param_2 + 0x18);
  lVar2 = *(longlong *)(param_1 + 0x40);
  uVar4 = (ulonglong)*(uint *)(*(longlong *)(param_2 + 0xb8) + 8);
  FUN_000121dc();
  uVar3 = FUN_000121dc();
  if (puVar1 != (uint *)0x0) {
    *puVar1 = uVar3 + 6;
    uVar3 = FUN_000121dc();
  }
  if ((uint)uVar4 < uVar3) {
    *(ulonglong *)(param_2 + 0x38) = uVar4;
  }
  else {
    FUN_000251f0((ulonglong *)(puVar1 + 1),0,(ulonglong)uVar3 + 2);
    memcpy(puVar1 + 1,(void *)(*(longlong *)(lVar2 + 0x70) + 8),
           (ulonglong)*(ushort *)(lVar2 + 0x68) - 8);
    FUN_000121dc();
    *(ulonglong *)(param_2 + 0x38) = (ulonglong)*puVar1;
  }
  return 0;
}



/* ===== FUNC FUN_0001ec7c @ 0001ec7c ===== */

void FUN_0001ec7c(longlong param_1,longlong param_2)

{
  uint uVar1;
  uint *puVar2;
  undefined1 auStack_258 [32];
  uint *local_238;
  uint local_228 [4];
  undefined1 local_218 [512];
  ulonglong local_18;
  
  local_18 = DAT_00037100 ^ (ulonglong)auStack_258;
  puVar2 = *(uint **)(param_2 + 0x18);
  uVar1 = *(uint *)(*(longlong *)(param_2 + 0xb8) + 8);
  FUN_000121dc();
  local_238 = local_228;
  IoGetDeviceProperty(*(undefined8 *)(*(longlong *)(param_1 + 0x40) + 0x30),7,0x100,local_218);
  if (puVar2 != (uint *)0x0) {
    *puVar2 = local_228[0] + 6;
  }
  if (uVar1 < local_228[0]) {
    *(ulonglong *)(param_2 + 0x38) = (ulonglong)uVar1;
  }
  else {
    memcpy(puVar2 + 1,local_218,(ulonglong)local_228[0]);
    *(ulonglong *)(param_2 + 0x38) = (ulonglong)*puVar2;
  }
  FUN_00025050(local_18 ^ (ulonglong)auStack_258);
  return;
}



/* ===== FUNC FUN_0001ed50 @ 0001ed50 ===== */

ulonglong FUN_0001ed50(longlong param_1,longlong param_2)

{
  char cVar1;
  char cVar2;
  byte bVar3;
  uint *puVar4;
  byte *_Src;
  longlong *plVar5;
  uint uVar6;
  uint uVar7;
  longlong *plVar8;
  ulonglong uVar9;
  
  puVar4 = *(uint **)(param_2 + 0x18);
  uVar7 = *(uint *)(*(longlong *)(param_2 + 0xb8) + 8);
  cVar1 = *(char *)((longlong)puVar4 + 7);
  cVar2 = *(char *)((longlong)puVar4 + 6);
  plVar5 = (longlong *)(*(longlong *)(param_1 + 0x40) + 0xa0);
  plVar8 = (longlong *)*plVar5;
  uVar9 = 0xc00000bb;
  if (plVar8 != plVar5) {
    do {
      if ((*puVar4 == (uint)*(byte *)((longlong)plVar8 + -0x34)) &&
         (*(int *)((longlong)plVar8 + -0x4c) == 1)) {
        FUN_000121dc();
        if (cVar1 == '\x01') {
          FUN_000121dc();
          bVar3 = *(byte *)((longlong)plVar8 + 0x1c);
          if ((ulonglong)uVar7 < (ulonglong)bVar3 + 0xc) {
            uVar9 = 0xc000009a;
          }
          else {
            memcpy(puVar4 + 3,(void *)((longlong)plVar8 + 0x1c),(ulonglong)bVar3);
            bVar3 = *(byte *)((longlong)plVar8 + 0x1c);
            uVar9 = 0;
          }
          uVar7 = bVar3 + 0xc;
        }
        else if (cVar1 == '\x02') {
          FUN_000121dc();
          _Src = (byte *)plVar8[(ulonglong)*(byte *)(plVar8 + 0x16) + 6];
          uVar9 = (ulonglong)uVar7;
          uVar7 = *_Src + 0xc;
          if (uVar9 < (ulonglong)*_Src + 0xc) {
LAB_0001ef89:
            uVar9 = 0xc000009a;
          }
          else {
            memcpy(puVar4 + 3,_Src,(ulonglong)*_Src);
            uVar9 = 0;
          }
        }
        else if (cVar1 == '\x03') {
          FUN_000121dc();
          if (cVar2 == *(char *)((longlong)plVar8 + 0x2c)) {
            uVar6 = (uint)*(byte *)plVar8[0x1a];
            if (uVar7 < *(byte *)plVar8[0x1a] + 0xc) goto LAB_0001ef86;
            bVar3 = *(byte *)plVar8[0x1a];
            uVar7 = bVar3 + 0xc;
            memcpy(puVar4 + 3,(byte *)plVar8[0x1a],(ulonglong)bVar3);
            uVar9 = 0;
            FUN_000121dc();
          }
          else if (cVar2 == *(char *)((longlong)plVar8 + 0x2a)) {
            uVar6 = (uint)*(byte *)plVar8[0x18];
            if (uVar7 < *(byte *)plVar8[0x18] + 0xc) goto LAB_0001ef86;
            bVar3 = *(byte *)plVar8[0x18];
            memcpy(puVar4 + 3,(byte *)plVar8[0x18],(ulonglong)bVar3);
LAB_0001ef2d:
            uVar7 = bVar3 + 0xc;
            uVar9 = 0;
            FUN_000121dc();
          }
          else {
            if (cVar2 == *(char *)((longlong)plVar8 + 0x2b)) {
              uVar6 = (uint)*(byte *)plVar8[0x19];
              if (*(byte *)plVar8[0x19] + 0xc <= uVar7) {
                bVar3 = *(byte *)plVar8[0x19];
                memcpy(puVar4 + 3,(byte *)plVar8[0x19],(ulonglong)bVar3);
                goto LAB_0001ef2d;
              }
LAB_0001ef86:
              uVar7 = uVar6 + 0xc;
              goto LAB_0001ef89;
            }
            if (cVar2 == '\0') {
              if (uVar7 < 0x10) goto LAB_0001ef89;
              uVar7 = 0x10;
              *(undefined1 *)(puVar4 + 3) = 4;
              *(undefined1 *)((longlong)puVar4 + 0xd) = 3;
              *(undefined1 *)((longlong)puVar4 + 0xe) = 9;
              *(undefined1 *)((longlong)puVar4 + 0xf) = 4;
              uVar9 = 0;
              goto LAB_0001efd8;
            }
          }
        }
        else if ((cVar1 == '\x04') || (cVar1 == '\x05')) {
LAB_0001efd8:
          FUN_000121dc();
        }
      }
      plVar8 = (longlong *)*plVar8;
    } while (plVar8 != plVar5);
  }
  *(short *)((longlong)puVar4 + 10) = (short)uVar7;
  *(undefined1 *)(puVar4 + 1) = 0x80;
  *(undefined1 *)((longlong)puVar4 + 5) = 6;
  *(ulonglong *)(param_2 + 0x38) = (ulonglong)uVar7;
  *(int *)(param_2 + 0x30) = (int)uVar9;
  return uVar9 & 0xffffffff;
}



/* ===== FUNC FUN_0001f028 @ 0001f028 ===== */

void FUN_0001f028(longlong param_1,longlong param_2)

{
  uint uVar1;
  longlong lVar2;
  undefined1 auStack_258 [32];
  uint *local_238;
  uint local_228 [4];
  undefined1 local_218 [512];
  ulonglong local_18;
  
  local_18 = DAT_00037100 ^ (ulonglong)auStack_258;
  lVar2 = *(longlong *)(param_2 + 0x18);
  uVar1 = *(uint *)(*(longlong *)(param_2 + 0xb8) + 8);
  FUN_000121dc();
  local_238 = local_228;
  IoGetDeviceProperty(*(undefined8 *)(*(longlong *)(param_1 + 0x40) + 0x30),7,0x100,local_218);
  *(uint *)(lVar2 + 4) = local_228[0] + 6;
  if (uVar1 < local_228[0]) {
    *(ulonglong *)(param_2 + 0x38) = (ulonglong)uVar1;
  }
  else {
    memcpy((void *)(lVar2 + 8),local_218,(ulonglong)local_228[0]);
    *(ulonglong *)(param_2 + 0x38) = (ulonglong)*(uint *)(lVar2 + 4);
  }
  FUN_00025050(local_18 ^ (ulonglong)auStack_258);
  return;
}



/* ===== FUNC FUN_0001f0f8 @ 0001f0f8 ===== */

void FUN_0001f0f8(longlong param_1,longlong param_2,char param_3)

{
  longlong lVar1;
  longlong lVar2;
  byte *pbVar3;
  byte *pbVar4;
  byte *pbVar5;
  undefined8 *puVar6;
  byte *pbVar7;
  byte *pbVar8;
  undefined8 *puVar9;
  ulonglong uVar10;
  ulonglong uVar11;
  uint uVar12;
  ulonglong uVar13;
  byte bVar14;
  ulonglong uVar15;
  undefined1 auStack_4a8 [32];
  uint local_488;
  uint local_480;
  undefined4 local_478;
  byte local_468;
  byte *local_460;
  ulonglong local_458;
  longlong local_450;
  longlong local_448;
  uint local_438;
  undefined8 local_434;
  undefined8 local_42c;
  undefined2 local_424;
  undefined1 local_422;
  undefined1 local_421;
  byte local_420;
  ushort local_41f;
  uint local_41d;
  undefined4 local_419;
  byte abStack_415 [973];
  ulonglong local_48;
  
  local_48 = DAT_00037100 ^ (ulonglong)auStack_4a8;
  lVar1 = *(longlong *)(param_2 + 0xb8);
  lVar2 = *(longlong *)(param_1 + 0x40);
  local_450 = param_2;
  local_448 = lVar1;
  memcpy(&local_438,*(void **)(param_2 + 0x18),(ulonglong)*(uint *)(lVar1 + 0x10));
  local_488 = *(uint *)(lVar1 + 8);
  local_480 = local_438;
  FUN_000121dc();
  uVar10 = 0;
  puVar9 = (undefined8 *)(lVar2 + 0xa0);
  puVar6 = (undefined8 *)*puVar9;
  while( true ) {
    local_419 = 0;
    local_41d = 0;
    local_420 = 0;
    local_422 = 0;
    if (puVar6 == puVar9) goto LAB_0001f473;
    if (((local_438 == *(byte *)((longlong)puVar6 + -0x34)) &&
        (*(int *)((longlong)puVar6 + -0x4c) == 1)) && (*(char *)((longlong)puVar6 + 0x11) == '\x01')
       ) break;
    puVar6 = (undefined8 *)*puVar6;
  }
  pbVar3 = (byte *)puVar6[(ulonglong)*(byte *)(puVar6 + 0x16) + 6];
  local_460 = (byte *)puVar6[0x17];
  FUN_000121dc();
  local_434 = *(undefined8 *)((longlong)puVar6 + 0x1c);
  local_42c._2_2_ = (ushort)((ulonglong)*(undefined8 *)((longlong)puVar6 + 0x24) >> 0x10);
  local_424._1_1_ = (byte)((ushort)*(undefined2 *)((longlong)puVar6 + 0x2c) >> 8);
  local_480 = (uint)local_424._1_1_;
  local_488 = (uint)local_42c._2_2_;
  local_42c = *(undefined8 *)((longlong)puVar6 + 0x24);
  local_424 = *(undefined2 *)((longlong)puVar6 + 0x2c);
  FUN_000121dc();
  local_422 = 1;
  local_420 = (byte)uVar10;
  if (param_3 == '\x01') {
    local_421 = *(undefined1 *)((longlong)puVar6 + -0x17);
  }
  else {
    local_421 = *(byte *)((longlong)puVar6 + -0x17) == local_420;
  }
  local_41f = (ushort)*(byte *)((longlong)puVar6 + -0x34);
  local_419 = 1;
  uVar12 = (uint)uVar10;
  uVar13 = uVar10 & 0xffffffff;
  uVar15 = uVar10 & 0xff;
  local_458 = uVar10;
  if (local_420 < pbVar3[4]) {
    pbVar7 = local_460;
    pbVar8 = pbVar3;
    local_41d = uVar12;
    do {
      local_478 = 0xffffffff;
      local_480 = 0xffffffff;
      local_488 = 0xffffffff;
      if (*(char *)((longlong)puVar6 + 0x19c) == '\x01') {
        uVar11 = (ulonglong)pbVar7[1];
        uVar10 = (ulonglong)*pbVar7;
      }
      else {
        uVar11 = 0xffffffff;
        uVar10 = 0xffffffff;
      }
      pbVar4 = (byte *)USBD_ParseConfigurationDescriptorEx(pbVar3,pbVar8,uVar10,uVar11);
      uVar10 = 0;
      if (pbVar4 != (byte *)0x0) {
        if (*(char *)((longlong)puVar6 + 0x19c) == '\x01') {
          pbVar7 = pbVar7 + 2;
        }
        if (pbVar4[4] == 0) {
          FUN_000121dc();
          pbVar8 = pbVar4 + *pbVar4;
        }
        else {
          FUN_000121dc();
          local_468 = (byte)uVar10;
          pbVar8 = pbVar4 + *pbVar4;
          if (local_468 < pbVar4[4]) {
            local_460 = abStack_415 + local_458 * 0xb;
            do {
              pbVar5 = (byte *)USBD_ParseDescriptors(pbVar3,*(undefined2 *)(pbVar3 + 2),pbVar8,5);
              if (pbVar5 == (byte *)0x0) {
                FUN_000121dc();
                break;
              }
              *(undefined4 *)local_460 = *(undefined4 *)pbVar5;
              *(undefined2 *)(local_460 + 4) = *(undefined2 *)(pbVar5 + 4);
              local_460[6] = pbVar5[6];
              local_480 = (uint)local_460[3];
              local_488 = (uint)local_460[2];
              FUN_000121dc();
              local_460[7] = 0;
              local_460[8] = 0;
              local_460[9] = 0;
              local_460[10] = 0;
              local_458 = local_458 + 1;
              local_468 = local_468 + 1;
              local_460 = local_460 + 0xb;
              uVar13 = (ulonglong)((int)uVar13 + 1);
              pbVar8 = pbVar5 + *pbVar5;
            } while (local_468 < pbVar4[4]);
            uVar10 = 0;
          }
        }
      }
      uVar12 = (uint)uVar13;
      bVar14 = (char)uVar15 + 1;
      uVar15 = (ulonglong)bVar14;
    } while (bVar14 < pbVar3[4]);
    param_2 = local_450;
  }
  local_41d = uVar12;
  if ((uint)uVar10 < uVar12) {
    *(ulonglong *)(param_2 + 0x38) = (ulonglong)uVar12 * 0xb + 0x23;
  }
  else {
LAB_0001f473:
    *(undefined8 *)(param_2 + 0x38) = 0x23;
  }
  FUN_000121dc();
  lVar1 = local_448;
  if (*(size_t *)(param_2 + 0x38) <= (ulonglong)*(uint *)(local_448 + 8)) {
    memcpy(*(void **)(param_2 + 0x18),&local_438,*(size_t *)(param_2 + 0x38));
    *(undefined4 *)(lVar1 + 8) = *(undefined4 *)(param_2 + 0x38);
  }
  FUN_00025050(local_48 ^ (ulonglong)auStack_4a8);
  return;
}



/* ===== FUNC FUN_0001f4f4 @ 0001f4f4 ===== */

void FUN_0001f4f4(byte *param_1)

{
  byte bVar1;
  longlong *plVar2;
  longlong lVar3;
  int iVar4;
  undefined8 *puVar5;
  undefined8 *puVar6;
  longlong lVar7;
  int iVar8;
  ulonglong uVar9;
  undefined1 auStackY_618 [32];
  longlong *local_5d8;
  longlong *local_5d0;
  undefined1 local_5c8 [1424];
  ulonglong local_38;
  
  local_38 = DAT_00037100 ^ (ulonglong)auStackY_618;
  plVar2 = *(longlong **)(param_1 + 1);
  bVar1 = *param_1;
  uVar9 = (ulonglong)bVar1;
  lVar3 = *plVar2;
  local_5d0 = plVar2 + uVar9 * 0x1a + 0xc2;
  iVar8 = 1;
  local_5d8 = plVar2 + uVar9 * 0x1a + 0xb7;
  FUN_000121dc();
  puVar5 = (undefined8 *)ExAllocatePoolWithTag();
  if (puVar5 != (undefined8 *)0x0) {
    while( true ) {
      FUN_000121dc();
      KeWaitForMultipleObjects(2,&local_5d8,iVar8);
      iVar4 = FUN_000121dc();
      if ((iVar4 < 0) || (iVar4 == 0)) break;
      if ((iVar4 == iVar8) || (iVar4 == 0x102)) {
        while (puVar6 = (undefined8 *)FUN_0001fa20(lVar3,param_1), puVar6 != (undefined8 *)0x0) {
          FUN_0001834c(lVar3,uVar9,(longlong)plVar2);
          iVar8 = FUN_0001fa8c(lVar3,bVar1,puVar6,puVar5,local_5c8);
          FUN_000183ac(lVar3,(ulonglong)bVar1,(longlong)plVar2);
          if ((iVar8 != 0) && (iVar8 != 0x103)) {
            FUN_00021370(iVar8);
            FUN_000121dc();
            KeWaitForSingleObject(plVar2 + uVar9 * 0x1a + 0xb7,0,0,0);
            goto LAB_0001f6da;
          }
        }
        iVar8 = 3;
        FUN_000121dc();
        iVar8 = iVar8 + -2;
      }
    }
    FUN_000121dc();
  }
LAB_0001f6da:
  while (lVar7 = FUN_0001fa20(lVar3,param_1), lVar7 != 0) {
    lVar7 = FUN_000121dc();
    FUN_00017594(lVar7,0);
  }
  if (puVar5 != (undefined8 *)0x0) {
    ExFreePoolWithTag(puVar5,0x36747345);
  }
  FUN_000121dc();
  PsTerminateSystemThread(0);
  FUN_00025050(local_38 ^ (ulonglong)auStackY_618);
  return;
}



/* ===== FUNC FUN_0001f788 @ 0001f788 ===== */

int FUN_0001f788(longlong param_1)

{
  int iVar1;
  longlong lVar2;
  undefined8 local_res8;
  undefined4 local_48 [2];
  undefined8 local_40;
  undefined8 local_38;
  undefined4 local_30;
  undefined8 local_28;
  undefined8 local_20;
  
  lVar2 = FUN_000121dc();
  local_40 = 0;
  local_38 = 0;
  local_28 = 0;
  local_20 = 0;
  local_48[0] = 0x30;
  local_30 = 0x200;
  iVar1 = PsCreateSystemThread
                    (&local_res8,0x1f03ff,local_48,0,0,FUN_0001f4f4,param_1 + 0x668 + lVar2 * 0xd0);
  if (-1 < iVar1) {
    ObReferenceObjectByHandle(local_res8,0x1f03ff,0,0,param_1 + 0x5d0 + lVar2 * 0xd0,0);
    ZwClose(local_res8);
  }
  FUN_000121dc();
  return iVar1;
}



/* ===== FUNC FUN_0001f89c @ 0001f89c ===== */

void FUN_0001f89c(longlong param_1)

{
  longlong lVar1;
  longlong lVar2;
  
  lVar2 = FUN_000121dc();
  lVar2 = lVar2 * 0xd0;
  if (*(longlong *)(param_1 + 0x5d0 + lVar2) != 0) {
    lVar1 = param_1 + 0x5b8 + lVar2;
    KeSetEvent(lVar1,0,0);
    KeWaitForSingleObject(*(undefined8 *)(param_1 + 0x5d0 + lVar2),0,0,0,0);
    ObfDereferenceObject(*(undefined8 *)(param_1 + 0x5d0 + lVar2));
    *(undefined8 *)(param_1 + 0x5d0 + lVar2) = 0;
    KeClearEvent(lVar1);
  }
  FUN_000121dc();
  return;
}



/* ===== FUNC FUN_0001f978 @ 0001f978 ===== */

void FUN_0001f978(longlong param_1)

{
  byte bVar1;
  
  bVar1 = 1;
  FUN_000121dc();
  do {
    FUN_0001f89c(param_1);
    bVar1 = bVar1 + 1;
  } while (bVar1 < 6);
  FUN_000121dc();
  return;
}



/* ===== FUNC FUN_0001f9e0 @ 0001f9e0 ===== */

void FUN_0001f9e0(longlong param_1,longlong param_2)

{
  longlong lVar1;
  longlong lVar2;
  longlong lVar3;
  
  lVar1 = *(longlong *)(param_1 + 0x40);
  if (*(char *)(lVar1 + 8) == '\x01') {
    lVar2 = *(longlong *)(param_2 + 0x78);
    lVar3 = lVar1;
  }
  else {
    lVar3 = *(longlong *)(*(longlong *)(lVar1 + 0x28) + 0x40);
    lVar2 = lVar1;
  }
                    /* WARNING: Could not recover jumptable at 0x0001fa12. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  IoCsqInsertIrp((ulonglong)*(byte *)(lVar2 + 0x24) * 0xd0 + 0x628 + lVar3,param_2,0);
  return;
}



/* ===== FUNC FUN_0001fa20 @ 0001fa20 ===== */

void FUN_0001fa20(longlong param_1,byte *param_2)

{
  longlong lVar1;
  
  lVar1 = *(longlong *)(param_1 + 0x40);
  FUN_000121dc();
  IoCsqRemoveNextIrp((ulonglong)*param_2 * 0xd0 + 0x628 + lVar1,param_2);
  FUN_000121dc();
  return;
}



/* ===== FUNC FUN_0001fa8c @ 0001fa8c ===== */

int FUN_0001fa8c(longlong param_1,undefined1 param_2,undefined8 *param_3,undefined8 *param_4,
                undefined8 param_5)

{
  int *piVar1;
  int iVar2;
  short sVar3;
  ushort uVar4;
  longlong lVar5;
  int iVar6;
  longlong lVar7;
  ulonglong uVar8;
  undefined8 uVar9;
  longlong lVar10;
  char cVar11;
  char *pcVar12;
  undefined1 uVar13;
  uint uVar14;
  short sVar15;
  ulonglong local_res8;
  undefined1 local_res10;
  undefined1 local_res18 [8];
  undefined8 local_80;
  undefined8 local_78;
  undefined1 local_70 [16];
  short local_60;
  undefined1 local_5e;
  undefined1 local_5d;
  undefined1 local_5c;
  
  lVar7 = 0;
  local_res8 = local_res8 & 0xffffffffffffff00;
  local_res18[0] = 0;
  lVar5 = *(longlong *)(param_1 + 0x40);
  iVar6 = -0x3fffff45;
  do {
    LOCK();
    piVar1 = (int *)(lVar5 + 0x210);
    iVar2 = *piVar1;
    *piVar1 = *piVar1 + 1;
    UNLOCK();
    sVar15 = (short)iVar2 + 1;
  } while (sVar15 == 0);
  local_res10 = param_2;
  FUN_000121dc();
  lVar5 = *(longlong *)(param_3[0x17] + 8);
  uVar8 = param_3[0xf];
  sVar3 = *(short *)(lVar5 + 2);
  if ((uVar8 < 0xffffffffffffff00) &&
     ((*(char *)(uVar8 + 0x69) == '\0' || (*(char *)(uVar8 + 0x6d) == '\0')))) {
    FUN_000121dc();
    *(undefined4 *)(lVar5 + 4) = 0xc0007000;
    iVar6 = -0x3fffff63;
  }
  else {
    local_78 = *(undefined8 *)(param_1 + 0x40);
    lVar7 = ExAllocatePoolWithTag(0,0x38,0x53747345);
    if (lVar7 == 0) {
      iVar6 = -0x3fffff66;
    }
    else {
      *(short *)(lVar7 + 0x10) = sVar15;
      uVar4 = *(ushort *)(lVar5 + 2);
      if (uVar4 < 0x18) {
        if (uVar4 == 0x17) {
          lVar10 = FUN_000121dc();
          iVar6 = FUN_0001762c(param_1,(longlong)param_3,lVar5,lVar10);
          if (iVar6 == -0x3fffff66) {
LAB_0001fd20:
            *(undefined4 *)(lVar5 + 4) = 0xc0001000;
            iVar6 = 0;
          }
        }
        else if (uVar4 < 0xc) {
          if (uVar4 == 0xb) {
LAB_0001fc98:
            iVar6 = FUN_0001728c(param_1,(longlong)param_3,lVar7);
          }
          else if (uVar4 == 0) {
            iVar6 = FUN_00016c48(param_1,(longlong)param_3,lVar7);
          }
          else if (uVar4 == 1) {
            lVar10 = *(longlong *)(param_3[0x17] + 8);
            iVar6 = -0x3fffffff;
            FUN_000121dc();
            uVar9 = FUN_000175e4(*(short *)(lVar10 + 2),&local_80);
            if ((char)uVar9 != '\0') {
              local_80._2_2_ = (ushort)*(byte *)(lVar10 + 0x23);
              local_80._4_2_ = (ushort)*(byte *)(lVar10 + 0x22);
              iVar6 = FUN_00018f58(param_1,(longlong)param_3,&local_80,lVar7);
              if (iVar6 == 0) {
                iVar6 = 0x103;
              }
            }
          }
          else if (uVar4 == 8) {
LAB_0001fd63:
            uVar8 = FUN_0001b34c(param_1,(longlong)param_3,lVar7);
            iVar6 = (int)uVar8;
          }
          else if (uVar4 == 9) {
            uVar8 = FUN_000170c8(param_1,param_3,lVar7,param_4,param_5,(byte *)&local_res8,
                                 local_res18);
            iVar6 = (int)uVar8;
          }
        }
        else if (((uVar4 == 0x10) || (uVar4 == 0x11)) || (uVar4 == 0x12)) {
          iVar6 = FUN_00017378(param_1,(longlong)param_3,lVar5,lVar7);
        }
        else if (uVar4 - 0x13 < 3) {
          iVar6 = FUN_00017454(param_1,(longlong)param_3,lVar5,lVar7);
        }
      }
      else {
        lVar10 = lVar7;
        if (uVar4 == 0x18) {
LAB_0001fd8a:
          iVar6 = FUN_0001762c(param_1,(longlong)param_3,lVar5,lVar10);
        }
        else if (uVar4 == 0x1b) {
          cVar11 = '\x02';
          FUN_000121dc();
          if (((*(byte *)(lVar5 + 0x20) & 1) == 0) && (*(char *)(lVar5 + 0x81) == cVar11)) {
            *(ushort *)(lVar5 + 0x84) =
                 *(ushort *)(lVar5 + 0x84) >> 8 | *(ushort *)(lVar5 + 0x84) << 8;
          }
          iVar6 = FUN_0001762c(param_1,(longlong)param_3,lVar5,lVar7);
          if (iVar6 == 0) {
            *(undefined4 *)(lVar5 + 4) = 0;
          }
          else {
            if (iVar6 == -0x3fffff66) goto LAB_0001fd20;
            if (iVar6 == -0x3fffff63) {
              *(undefined4 *)(lVar5 + 4) = 0xc0007000;
            }
          }
        }
        else {
          if (uVar4 == 0x1c) goto LAB_0001fd8a;
          if (uVar4 == 0x1e) {
            iVar6 = FUN_000171b0(param_1,(longlong)param_3,lVar7);
          }
          else if (uVar4 == 0x1f) {
            iVar6 = FUN_0001762c(param_1,(longlong)param_3,lVar5,lVar7);
            if (iVar6 == -0x3fffff66) {
              *(undefined4 *)(lVar5 + 4) = 0xc0001000;
              iVar6 = 0;
            }
          }
          else {
            if (uVar4 == 0x20) {
              lVar10 = FUN_000121dc();
              goto LAB_0001fd8a;
            }
            if (uVar4 == 0x28) goto LAB_0001fc98;
            if (uVar4 == 0x32) goto LAB_0001fd63;
          }
        }
      }
      if (sVar3 != 0x1e) {
        lVar7 = 0;
        param_3 = (undefined8 *)0x0;
      }
      if (iVar6 == 0x103) goto LAB_000200c5;
    }
    param_2 = local_res10;
  }
  FUN_00021370(iVar6);
  FUN_000121dc();
  if ((((iVar6 == -0x3fffff4b) || (iVar6 == -0x3ffffdf4)) || (iVar6 == -0x3fffffff)) &&
     (sVar3 != 0x1e)) {
    uVar14 = 0;
    local_5c = local_res18[0];
    local_5d = (undefined1)local_res8;
    local_res8 = *(longlong *)(param_1 + 0x40) + 0x218;
    local_60 = sVar15;
    local_5e = param_2;
    do {
      param_3 = (undefined8 *)IoCsqRemoveNextIrp(local_res8,local_70);
      if (param_3 != (undefined8 *)0x0) {
        lVar10 = FUN_000121dc();
        if (*(longlong *)(lVar10 + 0x88) != 0) {
          ExFreePoolWithTag(*(longlong *)(lVar10 + 0x88),0x53747345);
        }
        break;
      }
      uVar14 = uVar14 + 1;
    } while (uVar14 < 10);
    if (param_3 == (undefined8 *)0x0) {
      FUN_000121dc();
    }
    else {
      lVar7 = param_3[0x11];
      pcVar12 = 
      "    UrbFunctions()  Got IRP_0x%0p CSQContextEntry_from_IRP_0x%p \n     SeqNum_0x%04X, PortAddr_%d, EndPt_0x%02X, Command_0x%02X\n"
      ;
      uVar13 = local_res10;
      FUN_000121dc();
      if (*(short *)(lVar5 + 2) == 9) {
        *(undefined4 *)(lVar5 + 0x24) = 0;
        FUN_0001e010(param_1,local_78,CONCAT71((int7)((ulonglong)pcVar12 >> 8),uVar13),
                     *(longlong *)(lVar5 + 0x18));
      }
    }
  }
  if ((((lVar7 != 0) && (iVar6 != -0x3fffff4b)) && (iVar6 != -0x3ffffdf4)) && (iVar6 != -0x3fffffff)
     ) {
    ExFreePoolWithTag(lVar7,0);
  }
  if (param_3 != (undefined8 *)0x0) {
    if (((iVar6 == -0x3fffff63) || (iVar6 == -0x3fffff4b)) || (iVar6 == -0x3ffffdf4)) {
      param_3[7] = 0;
      iVar6 = -0x3ffffee0;
      *(undefined4 *)(lVar5 + 4) = 0xc0010000;
    }
    else if (iVar6 != 0) {
      iVar6 = -0x3fffffff;
    }
    FUN_00021370(iVar6);
    FUN_000121dc();
    FUN_00017594((longlong)param_3,iVar6);
  }
LAB_000200c5:
  FUN_00021370(iVar6);
  FUN_000121dc();
  return iVar6;
}



/* ===== FUNC FUN_0002010c @ 0002010c ===== */

void FUN_0002010c(byte *param_1)

{
  byte bVar1;
  longlong *plVar2;
  int iVar3;
  ulonglong in_stack_ffffffffffffffc8;
  ulonglong uVar4;
  longlong *local_18;
  longlong *local_10;
  
  plVar2 = *(longlong **)(param_1 + 1);
  bVar1 = *param_1;
  local_10 = plVar2 + (ulonglong)bVar1 * 0x1a + 0xbb;
  uVar4 = in_stack_ffffffffffffffc8 & 0xffffffff00000000;
  iVar3 = 1;
  local_18 = plVar2 + (ulonglong)bVar1 * 0x1a + 0xbe;
  FUN_000121dc();
  iVar3 = KeWaitForMultipleObjects(iVar3 + 1,&local_18,iVar3,0,uVar4 & 0xffffffffffffff00,0,0,0);
  if (iVar3 < 0) {
    FUN_00021370(iVar3);
    FUN_000121dc();
  }
  else if (iVar3 == 0) {
    FUN_000121dc();
  }
  else if (iVar3 == 1) {
    FUN_000121dc();
    iVar3 = FUN_000204e0(plVar2,bVar1);
    if ((iVar3 != 0) && (iVar3 != 0x103)) {
      FUN_00021370(iVar3);
      FUN_000121dc();
      KeWaitForSingleObject(plVar2 + (ulonglong)bVar1 * 0x1a + 0xbe,0,0,0,0);
    }
  }
  FUN_000121dc();
  PsTerminateSystemThread(0);
  return;
}



/* ===== FUNC FUN_0002028c @ 0002028c ===== */

int FUN_0002028c(longlong param_1)

{
  int iVar1;
  longlong lVar2;
  undefined8 local_res8;
  undefined4 local_48 [2];
  undefined8 local_40;
  undefined8 local_38;
  undefined4 local_30;
  undefined8 local_28;
  undefined8 local_20;
  
  lVar2 = FUN_000121dc();
  local_40 = 0;
  local_38 = 0;
  local_28 = 0;
  local_20 = 0;
  local_48[0] = 0x30;
  local_30 = 0x200;
  iVar1 = PsCreateSystemThread
                    (&local_res8,0x1f03ff,local_48,0,0,FUN_0002010c,param_1 + 0x668 + lVar2 * 0xd0);
  if (-1 < iVar1) {
    ObReferenceObjectByHandle(local_res8,0x1f03ff,0,0,param_1 + 0x608 + lVar2 * 0xd0,0);
    ZwClose(local_res8);
  }
  FUN_000121dc();
  return iVar1;
}



/* ===== FUNC FUN_000203a0 @ 000203a0 ===== */

void FUN_000203a0(longlong param_1)

{
  longlong lVar1;
  longlong lVar2;
  undefined8 local_res8;
  
  local_res8 = 0xffffffffff676980;
  lVar2 = FUN_000121dc();
  lVar2 = lVar2 * 0xd0;
  if (*(longlong *)(lVar2 + 0x608 + param_1) != 0) {
    lVar1 = lVar2 + 0x5f0 + param_1;
    KeSetEvent(lVar1,0,0);
    KeWaitForSingleObject(*(undefined8 *)(lVar2 + 0x608 + param_1),0,0,0,&local_res8);
    ObfDereferenceObject(*(undefined8 *)(lVar2 + 0x608 + param_1));
    *(undefined8 *)(lVar2 + 0x608 + param_1) = 0;
    KeClearEvent(lVar1);
  }
  FUN_000121dc();
  return;
}



/* ===== FUNC FUN_00020478 @ 00020478 ===== */

void FUN_00020478(longlong param_1)

{
  byte bVar1;
  
  bVar1 = 1;
  FUN_000121dc();
  do {
    FUN_000203a0(param_1);
    bVar1 = bVar1 + 1;
  } while (bVar1 < 6);
  FUN_000121dc();
  return;
}



/* ===== FUNC FUN_000204e0 @ 000204e0 ===== */

int FUN_000204e0(longlong *param_1,byte param_2)

{
  char cVar1;
  longlong lVar2;
  ushort uVar3;
  int iVar4;
  int *piVar5;
  ulonglong *puVar6;
  uint uVar7;
  char *pcVar8;
  ulonglong uVar9;
  uint uVar10;
  uint local_res10 [2];
  
  lVar2 = *param_1;
  iVar4 = 0;
  piVar5 = (int *)ExAllocatePoolWithTag(0,0x5b4,0x35747345);
  puVar6 = (ulonglong *)FUN_000121dc();
  if (puVar6 == (ulonglong *)0x0) {
LAB_0002078a:
    FUN_000121dc();
    return iVar4;
  }
  FUN_000251f0(puVar6,0,0x5b4);
  do {
    uVar7 = 0;
    pcVar8 = "    GetDataFromTDI(_%d_) Getting Headers\n";
    local_res10[0] = 0;
    FUN_000121dc();
    do {
      pcVar8 = (char *)CONCAT62((int6)((ulonglong)pcVar8 >> 0x10),0x20);
      iVar4 = FUN_00024990(lVar2,param_1[(ulonglong)param_2 * 6 + 0x3ce],pcVar8,
                           (ulonglong)uVar7 + (longlong)piVar5,0x20 - uVar7,(int *)local_res10);
      if (iVar4 != 0) {
        if ((iVar4 != -0x3ffffdf4) && (iVar4 != -0x3fffff4b)) goto LAB_0002077c;
        FUN_00021370(iVar4);
        goto LAB_00020762;
      }
      uVar7 = uVar7 + local_res10[0];
    } while (uVar7 < 0x20);
    FUN_000121dc();
    pcVar8 = "    GetDataFromTDI(_%d_) Getting %d bytes of payload.\n";
    uVar3 = *(ushort *)(piVar5 + 1) >> 8 | *(ushort *)(piVar5 + 1) << 8;
    local_res10[0] = (uint)uVar3;
    uVar10 = uVar3 + 0x20;
    FUN_000121dc();
    for (; uVar7 < uVar10; uVar7 = uVar7 + local_res10[0]) {
      pcVar8 = (char *)CONCAT62((int6)((ulonglong)pcVar8 >> 0x10),0x20);
      iVar4 = FUN_00024990(lVar2,param_1[(ulonglong)param_2 * 6 + 0x3ce],pcVar8,
                           (ulonglong)uVar7 + (longlong)piVar5,uVar10 - uVar7,(int *)local_res10);
      if (iVar4 != 0) {
        if ((iVar4 == -0x3ffffdf4) || (iVar4 == -0x3fffff4b)) {
          FUN_00021370(iVar4);
LAB_00020762:
          FUN_000121dc();
        }
LAB_0002077c:
        ExFreePoolWithTag(piVar5,0x35747345);
        goto LAB_0002078a;
      }
    }
    cVar1 = *(char *)((longlong)piVar5 + 7);
    if (((((cVar1 == '\x05') || (cVar1 == '\x03')) || (cVar1 == '\t')) ||
        ((cVar1 == ')' || (cVar1 == '\x0f')))) || ((cVar1 == '\x17' || (cVar1 == '\x01')))) {
      if ((*(byte *)((longlong)piVar5 + 10) & 0x80) == 0) {
        FUN_0001ca80(lVar2,piVar5);
      }
      else {
        FUN_0001e658(lVar2,(longlong)piVar5);
      }
    }
    else if (((cVar1 == '\v') || (cVar1 == '\x1f')) || (cVar1 == '\x1d')) {
      uVar9 = (ulonglong)*(byte *)(piVar5 + 4);
      FUN_000121dc();
      if ((*(char *)((longlong)piVar5 + 7) == '\n') || (*(char *)((longlong)piVar5 + 7) == '\x1c'))
      {
        *(ushort *)(param_1 + 0x400) =
             *(ushort *)((longlong)piVar5 + 0x12) >> 8 | *(ushort *)((longlong)piVar5 + 0x12) << 8;
      }
      *(undefined1 *)(param_1 + (uVar9 & 0xff) * 0x4d + 0x202) =
           *(undefined1 *)((longlong)piVar5 + 6);
      KeSetEvent(param_1 + (uVar9 & 0xff) * 0x4d + 0x1ff,0,0);
    }
  } while( true );
}



/* ===== FUNC FUN_000207c8 @ 000207c8 ===== */

void FUN_000207c8(longlong *param_1)

{
  bool bVar1;
  byte bVar2;
  int iVar3;
  ulonglong uVar4;
  longlong lVar5;
  longlong lVar6;
  ushort uVar7;
  longlong *plVar8;
  
  plVar8 = (longlong *)*param_1;
  lVar5 = *plVar8;
  bVar1 = false;
  lVar6 = 0;
  FUN_000121dc();
  if (param_1[7] == lVar6) {
    FUN_000121dc();
  }
  else {
    *(uint *)(param_1 + 0x1a) = *(uint *)(param_1 + 0x1a) & (uint)lVar6;
    uVar7 = *(ushort *)(*(longlong *)(param_1[2] + 0x10) + 4) & 0x7ff;
    if (uVar7 != 0) {
      bVar2 = (byte)(((ulonglong)*(ushort *)(plVar8 + 0x400) - 0x6f) / (ulonglong)uVar7);
      if (0x20 < bVar2) {
        bVar2 = 0x20;
      }
      do {
        FUN_000121dc();
        KeWaitForMultipleObjects();
        iVar3 = FUN_000121dc();
        if ((iVar3 < 0) || (iVar3 == 0)) {
          FUN_000121dc();
          break;
        }
        if (iVar3 == 1) {
          FUN_000121dc();
          if (DAT_00037820 == 0x6000000) {
            iVar3 = FUN_0001aedc(lVar5,param_1,bVar2,uVar7);
          }
          else {
            uVar4 = FUN_0001ac2c(lVar5,(longlong)param_1,bVar2,uVar7);
            iVar3 = (int)uVar4;
          }
          if (iVar3 == -0x3fffffb5) {
            FUN_000121dc();
            bVar1 = true;
          }
        }
      } while (!bVar1);
      while (lVar5 = IoCsqRemoveNextIrp(param_1 + 0xb,0), lVar5 != 0) {
        if (*(longlong *)(lVar5 + 0x80) != 0) {
          ExFreePoolWithTag(*(longlong *)(lVar5 + 0x80),0x53747345);
        }
        *(undefined4 *)(*(longlong *)(*(longlong *)(lVar5 + 0xb8) + 8) + 4) = 0;
        FUN_00017594(lVar5,0);
      }
    }
  }
  PsTerminateSystemThread(0);
  return;
}



/* ===== FUNC FUN_000209dc @ 000209dc ===== */

int FUN_000209dc(longlong param_1,undefined8 param_2,undefined1 param_3,byte param_4)

{
  undefined1 uVar1;
  int iVar2;
  longlong lVar3;
  ulonglong uVar4;
  undefined8 local_res8;
  undefined4 local_48 [2];
  undefined8 local_40;
  undefined8 local_38;
  undefined4 local_30;
  undefined8 local_28;
  undefined8 local_20;
  
  uVar4 = (ulonglong)param_4;
  uVar1 = FUN_000121dc();
  local_40 = 0;
  local_38 = 0;
  local_28 = 0;
  local_20 = 0;
  local_48[0] = 0x30;
  lVar3 = uVar4 * 0xf8;
  *(undefined1 *)(lVar3 + 0xaa0 + param_1) = uVar1;
  *(undefined1 *)(lVar3 + 0xaa1 + param_1) = param_3;
  *(char *)(lVar3 + 0xab0 + param_1) = (char)uVar4;
  local_30 = 0x200;
  iVar2 = PsCreateSystemThread
                    (&local_res8,0x1f03ff,local_48,0,0,FUN_000207c8,lVar3 + 0xa98 + param_1);
  if (-1 < iVar2) {
    ObReferenceObjectByHandle(local_res8,0x1f03ff,0,0,lVar3 + 0xad0 + param_1,0);
    ZwClose(local_res8);
  }
  FUN_000121dc();
  return iVar2;
}



/* ===== FUNC FUN_00020b10 @ 00020b10 ===== */

void FUN_00020b10(longlong param_1,byte param_2)

{
  longlong lVar1;
  
  FUN_000121dc();
  lVar1 = (ulonglong)param_2 * 0xf8;
  if (*(longlong *)(lVar1 + 0xad0 + param_1) != 0) {
    KeSetEvent(lVar1 + 0xab8 + param_1,0,0);
    KeWaitForSingleObject(*(undefined8 *)(lVar1 + 0xad0 + param_1),0,0,0,0);
    ObfDereferenceObject(*(undefined8 *)(lVar1 + 0xad0 + param_1));
    *(undefined8 *)(lVar1 + 0xad0 + param_1) = 0;
    FUN_00020e50(param_1,param_2);
  }
  FUN_000121dc();
  return;
}



/* ===== FUNC FUN_00020bec @ 00020bec ===== */

undefined8
FUN_00020bec(longlong param_1,longlong param_2,char param_3,byte param_4,byte param_5,char *param_6)

{
  longlong lVar1;
  
  lVar1 = *(longlong *)(param_1 + 0x40);
  FUN_000121dc();
  if (param_6 == (char *)0x0) {
    param_6 = (char *)ExAllocatePoolWithTag(0,0xc,0x53747345);
    if (param_6 == (char *)0x0) {
      return 0xc000009a;
    }
    param_6[0] = '\0';
    param_6[1] = '\0';
    param_6[2] = '\0';
    param_6[3] = '\0';
    param_6[4] = '\0';
    param_6[5] = '\0';
    param_6[6] = '\0';
    param_6[7] = '\0';
    param_6[8] = '\0';
    param_6[9] = '\0';
    param_6[10] = '\0';
    param_6[0xb] = '\0';
    *(char **)(param_2 + 0x80) = param_6;
  }
  if (param_3 != '\0') {
    param_6[8] = '\0';
  }
  *param_6 = param_3;
  *(uint *)(param_6 + 4) = (uint)param_4;
  IoCsqInsertIrp((ulonglong)param_5 * 0xf8 + 0xaf0 + lVar1,param_2,0);
  return 0;
}



/* ===== FUNC FUN_00020cc4 @ 00020cc4 ===== */

undefined8
FUN_00020cc4(longlong param_1,undefined1 param_2,undefined1 param_3,longlong param_4,byte *param_5)

{
  longlong *plVar1;
  undefined1 uVar2;
  longlong lVar3;
  longlong lVar4;
  longlong lVar5;
  byte bVar6;
  
  lVar4 = *(longlong *)(param_4 + 0x10);
  lVar3 = *(longlong *)(param_1 + 0x40);
  *param_5 = 0xff;
  bVar6 = 0;
  while ((*(char *)((ulonglong)bVar6 * 0xf8 + 0xaa0 + lVar3) != -1 ||
         (*(char *)((ulonglong)bVar6 * 0xf8 + 0xaa1 + lVar3) != -1))) {
    bVar6 = bVar6 + 1;
    if (3 < bVar6) {
      return 0xc000009a;
    }
  }
  *param_5 = bVar6;
  lVar5 = (ulonglong)bVar6 * 0xf8;
  plVar1 = (longlong *)(lVar5 + 0xa98 + lVar3);
  *(undefined1 *)(lVar5 + 0xaa0 + lVar3) = param_2;
  *(undefined1 *)(lVar5 + 0xaa1 + lVar3) = param_3;
  *plVar1 = lVar3;
  uVar2 = *(undefined1 *)(lVar4 + 2);
  *(undefined4 *)(lVar5 + 0xb6c + lVar3) = 0;
  *(undefined1 *)(lVar5 + 0xaa2 + lVar3) = uVar2;
  *(byte *)(lVar5 + 0xab0 + lVar3) = bVar6;
  *(longlong *)(((ulonglong)bVar6 + 0xb) * 0xf8 + lVar3) = param_4;
  plVar1[0x1b] = 0;
  lVar4 = ExAllocatePoolWithTag(0,&DAT_00016d00,0x62747345);
  plVar1[0x1c] = 0;
  plVar1[0x1d] = 0;
  plVar1[0x1e] = lVar4;
  bVar6 = 0;
  do {
    lVar4 = ExAllocatePoolWithTag(0,0x48,0x61747345);
    if (lVar4 == 0) {
      return 0;
    }
    lVar3 = plVar1[0x1e];
    *(undefined1 *)(lVar4 + 0x10) = 0;
    *(longlong **)(lVar4 + 0x18) = plVar1;
    *(longlong *)(lVar4 + 8) = (int)((uint)bVar6 * 0x5b4) + lVar3;
    KeInitializeEvent(lVar4 + 0x20,0,0);
    ExInterlockedPushEntryList(plVar1 + 0x1c,lVar4,plVar1 + 0x1b);
    bVar6 = bVar6 + 1;
  } while (bVar6 < 0x40);
  return 0;
}



/* ===== FUNC FUN_00020e50 @ 00020e50 ===== */

void FUN_00020e50(longlong param_1,byte param_2)

{
  int iVar1;
  longlong lVar2;
  longlong lVar3;
  
  lVar3 = (ulonglong)param_2 * 0xf8;
  *(undefined8 *)(((ulonglong)param_2 + 0xb) * 0xf8 + param_1) = 0;
  *(undefined4 *)(lVar3 + 0xb6c + param_1) = 0;
  *(undefined1 *)(lVar3 + 0xaa0 + param_1) = 0xff;
  *(undefined1 *)(lVar3 + 0xaa1 + param_1) = 0xff;
  *(undefined1 *)(lVar3 + 0xaa2 + param_1) = 0xff;
  KeInitializeSemaphore(lVar3 + 0xb30 + param_1,0x40,0x40);
  lVar2 = lVar3 + 0xab8 + param_1;
  iVar1 = KeReadStateEvent(lVar2);
  if (iVar1 != 0) {
    KeClearEvent(lVar2);
  }
  lVar2 = lVar3 + 0xad8 + param_1;
  iVar1 = KeReadStateEvent(lVar2);
  if (iVar1 != 0) {
    KeClearEvent(lVar2);
  }
  ExFreePoolWithTag(*(undefined8 *)(lVar3 + 0xb88 + param_1),0x62747345);
  while( true ) {
    lVar2 = ExInterlockedPopEntryList(lVar3 + 0xb78 + param_1,lVar3 + 0xb70 + param_1);
    if (lVar2 == 0) break;
    ExFreePoolWithTag(lVar2,0x61747345);
  }
  return;
}



/* ===== FUNC FUN_00020f4c @ 00020f4c ===== */

void FUN_00020f4c(undefined8 param_1,longlong param_2,byte param_3)

{
  KeReleaseSemaphore((ulonglong)param_3 * 0xf8 + 0xb30 + param_2,0,1);
  return;
}



/* ===== FUNC FUN_00020f9c @ 00020f9c ===== */

bool FUN_00020f9c(undefined8 *param_1)

{
  return *(int *)*param_1 == -0x3fffffb9;
}



/* ===== FUNC FUN_00020fc4 @ 00020fc4 ===== */

undefined8 FUN_00020fc4(longlong param_1,longlong param_2,longlong param_3,char param_4)

{
  undefined4 uVar1;
  longlong lVar2;
  longlong lVar3;
  longlong lVar4;
  longlong lVar5;
  
  lVar2 = *(longlong *)(param_1 + 0x40);
  lVar3 = *(longlong *)(param_2 + 0x78);
  lVar4 = *(longlong *)(*(longlong *)(param_2 + 0xb8) + 8);
  lVar5 = *(longlong *)(*(longlong *)(lVar4 + 0x18) + 0x10);
  if (param_3 == 0) {
    param_3 = ExAllocatePoolWithTag(0,0x20,0x53747345);
    if (param_3 == 0) {
      return 0xc000009a;
    }
    *(longlong *)(param_2 + 0x88) = param_3;
    uVar1 = *(undefined4 *)(lVar4 + 0x84);
    *(undefined4 *)(param_3 + 0x18) = 0;
    *(undefined4 *)(param_3 + 0x14) = uVar1;
  }
  *(char *)(param_3 + 0x12) = param_4;
  *(undefined1 *)(param_3 + 0x10) = *(undefined1 *)(lVar3 + 0x24);
  *(byte *)(param_3 + 0x11) = *(byte *)(lVar5 + 2) & 0x7f;
  if (param_4 == '\x01') {
    *(undefined4 *)(param_3 + 0x18) = 0;
  }
  FUN_000121dc();
  IoCsqInsertIrp(lVar2 + 0x270,param_2,0);
  return 0;
}



/* ===== FUNC FUN_000210d4 @ 000210d4 ===== */

void FUN_000210d4(longlong param_1,byte param_2)

{
  longlong lVar1;
  ulonglong uVar2;
  
  lVar1 = *(longlong *)(param_1 + 0x40);
  uVar2 = (ulonglong)param_2;
  *(undefined1 *)(lVar1 + 0x2c8 + uVar2 * 0x48) = 0xff;
  *(undefined1 *)(lVar1 + 0x2ca + uVar2 * 0x48) = 0xff;
  *(undefined1 *)(lVar1 + 0x2c9 + uVar2 * 0x48) = 0xff;
  *(undefined8 *)(lVar1 + 0x300 + uVar2 * 0x48) = 0;
  *(undefined1 *)(lVar1 + 0x2e8 + uVar2 * 0x48) = 0;
  *(undefined4 *)(lVar1 + 0x2ec + uVar2 * 0x48) = 0;
  *(undefined4 *)(lVar1 + 0x2f0 + uVar2 * 0x48) = 0xf0;
  *(undefined1 *)(lVar1 + 0x2fc + uVar2 * 0x48) = 0;
  *(undefined4 *)(lVar1 + 0x2f4 + uVar2 * 0x48) = 0;
  *(undefined4 *)(lVar1 + 0x308 + uVar2 * 0x48) = 2000000;
  return;
}



/* ===== FUNC FUN_00021144 @ 00021144 ===== */

undefined8 FUN_00021144(longlong param_1,char param_2,char param_3,byte *param_4)

{
  longlong lVar1;
  byte bVar2;
  
  lVar1 = *(longlong *)(param_1 + 0x40);
  bVar2 = 0;
  *param_4 = 0xff;
  while ((param_2 != *(char *)(lVar1 + 0x2c8 + (ulonglong)bVar2 * 0x48) ||
         (param_3 != *(char *)(lVar1 + 0x2c9 + (ulonglong)bVar2 * 0x48)))) {
    bVar2 = bVar2 + 1;
    if (2 < bVar2) {
      return 0xc000000e;
    }
  }
  *param_4 = bVar2;
  return 0;
}



/* ===== FUNC FUN_00021198 @ 00021198 ===== */

undefined8
FUN_00021198(longlong param_1,char param_2,char param_3,undefined8 param_4,undefined1 param_5,
            char param_6,byte *param_7)

{
  longlong lVar1;
  ulonglong uVar2;
  byte bVar3;
  
  lVar1 = *(longlong *)(param_1 + 0x40);
  bVar3 = 0;
  *param_7 = 0xff;
  while (((uVar2 = (ulonglong)bVar3, *(char *)(lVar1 + 0x2c9 + uVar2 * 0x48) != param_6 ||
          (*(char *)(lVar1 + 0x2c8 + uVar2 * 0x48) != param_2)) ||
         (*(char *)(lVar1 + 0x2ca + uVar2 * 0x48) != param_3))) {
    bVar3 = bVar3 + 1;
    if (2 < bVar3) {
      bVar3 = 0;
      do {
        if (*(char *)(lVar1 + 0x2c8 + (ulonglong)bVar3 * 0x48) == -1) {
          uVar2 = (ulonglong)bVar3;
          *param_7 = bVar3;
          *(undefined1 *)(lVar1 + 0x2fd + uVar2 * 0x48) = param_5;
          *(char *)(lVar1 + 0x2c8 + uVar2 * 0x48) = param_2;
          *(char *)(lVar1 + 0x2c9 + uVar2 * 0x48) = param_6;
          *(undefined8 *)(lVar1 + 0x300 + uVar2 * 0x48) = param_4;
          *(char *)(lVar1 + 0x2ca + uVar2 * 0x48) = param_3;
          return 0;
        }
        bVar3 = bVar3 + 1;
      } while (bVar3 < 3);
      return 0xc000009a;
    }
  }
  *param_7 = bVar3;
  *(undefined1 *)(lVar1 + 0x2fd + (ulonglong)bVar3 * 0x48) = param_5;
  *(undefined8 *)(lVar1 + 0x300 + (ulonglong)bVar3 * 0x48) = param_4;
  return 0;
}



/* ===== FUNC FUN_00021298 @ 00021298 ===== */

void FUN_00021298(longlong param_1,undefined1 param_2,byte param_3)

{
  longlong lVar1;
  longlong lVar2;
  longlong lVar3;
  undefined1 local_28 [16];
  undefined1 local_18;
  byte local_17;
  
  lVar1 = *(longlong *)(param_1 + 0x40);
  FUN_000121dc();
  while( true ) {
    local_18 = param_2;
    local_17 = param_3 & 0x7f;
    lVar3 = IoCsqRemoveNextIrp(lVar1 + 0x270,local_28);
    if (lVar3 == 0) break;
    if (*(longlong *)(lVar3 + 0x88) != 0) {
      ExFreePoolWithTag(*(longlong *)(lVar3 + 0x88),0x53747345);
    }
    lVar2 = *(longlong *)(*(longlong *)(lVar3 + 0xb8) + 8);
    *(undefined4 *)(lVar2 + 0x24) = 0;
    *(undefined4 *)(lVar2 + 4) = 0;
    FUN_000121dc();
    FUN_00017594(lVar3,0);
  }
  return;
}



/* ===== FUNC FUN_00021370 @ 00021370 ===== */

char * FUN_00021370(int param_1)

{
  if (param_1 < -0x7ffffd77) {
    if (param_1 == -0x7ffffd78) {
      return "STATUS_DEVICE_REQUIRES_CLEANING";
    }
    switch(param_1) {
    case -0x7fffffff:
      return "STATUS_GUARD_PAGE_VIOLATION";
    case -0x7ffffffe:
      return "STATUS_DATATYPE_MISALIGNMENT";
    case -0x7ffffffd:
      return "STATUS_BREAKPOINT";
    case -0x7ffffffc:
      return "STATUS_SINGLE_STEP";
    case -0x7ffffffb:
      return "STATUS_BUFFER_OVERFLOW";
    case -0x7ffffffa:
      return "STATUS_NO_MORE_FILES";
    case -0x7ffffff9:
      return "STATUS_WAKE_SYSTEM_DEBUGGER";
    case -0x7ffffff6:
      return "STATUS_HANDLES_CLOSED";
    case -0x7ffffff5:
      return "STATUS_NO_INHERITANCE";
    case -0x7ffffff4:
      return "STATUS_GUID_SUBSTITUTION_MADE";
    case -0x7ffffff3:
      return "STATUS_PARTIAL_COPY";
    case -0x7ffffff2:
      return "STATUS_DEVICE_PAPER_EMPTY";
    case -0x7ffffff1:
      return "STATUS_DEVICE_POWERED_OFF";
    case -0x7ffffff0:
      return "STATUS_DEVICE_OFF_LINE";
    case -0x7fffffef:
      return "STATUS_DEVICE_BUSY";
    case -0x7fffffee:
      return "STATUS_NO_MORE_EAS";
    case -0x7fffffed:
      return "STATUS_INVALID_EA_NAME";
    case -0x7fffffec:
      return "STATUS_EA_LIST_INCONSISTENT";
    case -0x7fffffeb:
      return "STATUS_INVALID_EA_FLAG";
    case -0x7fffffea:
      return "STATUS_VERIFY_REQUIRED";
    case -0x7fffffe9:
      return "STATUS_EXTRANEOUS_INFORMATION";
    case -0x7fffffe8:
      return "STATUS_RXACT_COMMIT_NECESSARY";
    case -0x7fffffe6:
      return "STATUS_NO_MORE_ENTRIES";
    case -0x7fffffe5:
      return "STATUS_FILEMARK_DETECTED";
    case -0x7fffffe4:
      return "STATUS_MEDIA_CHANGED";
    case -0x7fffffe3:
      return "STATUS_BUS_RESET";
    case -0x7fffffe2:
      return "STATUS_END_OF_MEDIA";
    case -0x7fffffe1:
      return "STATUS_BEGINNING_OF_MEDIA";
    case -0x7fffffe0:
      return "STATUS_MEDIA_CHECK";
    case -0x7fffffdf:
      return "STATUS_SETMARK_DETECTED";
    case -0x7fffffde:
      return "STATUS_NO_DATA_DETECTED";
    case -0x7fffffdd:
      return "STATUS_REDIRECTOR_HAS_OPEN_HANDLES";
    case -0x7fffffdc:
      return "STATUS_SERVER_HAS_OPEN_HANDLES";
    case -0x7fffffdb:
      return "STATUS_ALREADY_DISCONNECTED";
    case -0x7fffffda:
      return "STATUS_LONGJUMP";
    }
  }
  else if (param_1 < -0x3ffffddd) {
    if (param_1 == -0x3ffffdde) {
      return "STATUS_LOST_WRITEBEHIND_DATA";
    }
    if (param_1 < -0x3fffff23) {
      if (param_1 == -0x3fffff24) {
        return "STATUS_INVALID_SERVER_STATE";
      }
      if (param_1 < -0x3fffff91) {
        if (param_1 == -0x3fffff92) {
          return "STATUS_ACCOUNT_RESTRICTION";
        }
        if (param_1 < -0x3fffffc8) {
          if (param_1 == -0x3fffffc9) {
            return "STATUS_PORT_DISCONNECTED";
          }
          if (param_1 < -0x3fffffe5) {
            if (param_1 == -0x3fffffe6) {
              return "STATUS_UNABLE_TO_FREE_VM";
            }
            if (param_1 < -0x3ffffff3) {
              if (param_1 == -0x3ffffff4) {
                return "STATUS_TIMER_NOT_CANCELED";
              }
              if (param_1 < -0x3ffffffa) {
                if (param_1 == -0x3ffffffb) {
                  return "STATUS_ACCESS_VIOLATION";
                }
                if (param_1 == -0x7ffffd77) {
                  return "STATUS_DEVICE_DOOR_OPEN";
                }
                if (param_1 == -0x7ffeffff) {
                  return "DBG_EXCEPTION_NOT_HANDLED";
                }
                if (param_1 == -0x3fffffff) {
                  return "STATUS_UNSUCCESSFUL";
                }
                if (param_1 == -0x3ffffffe) {
                  return "STATUS_NOT_IMPLEMENTED";
                }
                if (param_1 == -0x3ffffffd) {
                  return "STATUS_INVALID_INFO_CLASS";
                }
                if (param_1 == -0x3ffffffc) {
                  return "STATUS_INFO_LENGTH_MISMATCH";
                }
              }
              else {
                if (param_1 == -0x3ffffffa) {
                  return "STATUS_IN_PAGE_ERROR";
                }
                if (param_1 == -0x3ffffff9) {
                  return "STATUS_PAGEFILE_QUOTA";
                }
                if (param_1 == -0x3ffffff8) {
                  return "STATUS_INVALID_HANDLE";
                }
                if (param_1 == -0x3ffffff7) {
                  return "STATUS_BAD_INITIAL_STACK";
                }
                if (param_1 == -0x3ffffff6) {
                  return "STATUS_BAD_INITIAL_PC";
                }
                if (param_1 == -0x3ffffff5) {
                  return "STATUS_INVALID_CID";
                }
              }
            }
            else {
              switch(param_1) {
              case -0x3ffffff3:
                return "STATUS_INVALID_PARAMETER";
              case -0x3ffffff2:
                return "STATUS_NO_SUCH_DEVICE";
              case -0x3ffffff1:
                return "STATUS_NO_SUCH_FILE";
              case -0x3ffffff0:
                return "STATUS_INVALID_DEVICE_REQUEST";
              case -0x3fffffef:
                return "STATUS_END_OF_FILE";
              case -0x3fffffee:
                return "STATUS_WRONG_VOLUME";
              case -0x3fffffed:
                return "STATUS_NO_MEDIA_IN_DEVICE";
              case -0x3fffffec:
                return "STATUS_UNRECOGNIZED_MEDIA";
              case -0x3fffffeb:
                return "STATUS_NONEXISTENT_SECTOR";
              case -0x3fffffea:
                return "STATUS_MORE_PROCESSING_REQUIRED";
              case -0x3fffffe9:
                return "STATUS_NO_MEMORY";
              case -0x3fffffe8:
                return "STATUS_CONFLICTING_ADDRESSES";
              case -0x3fffffe7:
                return "STATUS_NOT_MAPPED_VIEW";
              }
            }
          }
          else {
            switch(param_1) {
            case -0x3fffffe5:
              return "STATUS_UNABLE_TO_DELETE_SECTION";
            case -0x3fffffe4:
              return "STATUS_INVALID_SYSTEM_SERVICE";
            case -0x3fffffe3:
              return "STATUS_ILLEGAL_INSTRUCTION";
            case -0x3fffffe2:
              return "STATUS_INVALID_LOCK_SEQUENCE";
            case -0x3fffffe1:
              return "STATUS_INVALID_VIEW_SIZE";
            case -0x3fffffe0:
              return "STATUS_INVALID_FILE_FOR_SECTION";
            case -0x3fffffdf:
              return "STATUS_ALREADY_COMMITTED";
            case -0x3fffffde:
              return "STATUS_ACCESS_DENIED";
            case -0x3fffffdd:
              return "STATUS_BUFFER_TOO_SMALL";
            case -0x3fffffdc:
              return "STATUS_OBJECT_TYPE_MISMATCH";
            case -0x3fffffdb:
              return "STATUS_NONCONTINUABLE_EXCEPTION";
            case -0x3fffffda:
              return "STATUS_INVALID_DISPOSITION";
            case -0x3fffffd9:
              return "STATUS_UNWIND";
            case -0x3fffffd8:
              return "STATUS_BAD_STACK";
            case -0x3fffffd7:
              return "STATUS_INVALID_UNWIND_TARGET";
            case -0x3fffffd6:
              return "STATUS_NOT_LOCKED";
            case -0x3fffffd5:
              return "STATUS_PARITY_ERROR";
            case -0x3fffffd4:
              return "STATUS_UNABLE_TO_DECOMMIT_VM";
            case -0x3fffffd3:
              return "STATUS_NOT_COMMITTED";
            case -0x3fffffd2:
              return "STATUS_INVALID_PORT_ATTRIBUTES";
            case -0x3fffffd1:
              return "STATUS_PORT_MESSAGE_TOO_LONG";
            case -0x3fffffd0:
              return "STATUS_INVALID_PARAMETER_MIX";
            case -0x3fffffcf:
              return "STATUS_INVALID_QUOTA_LOWER";
            case -0x3fffffce:
              return "STATUS_DISK_CORRUPT_ERROR";
            case -0x3fffffcd:
              return "STATUS_OBJECT_NAME_INVALID";
            case -0x3fffffcc:
              return "STATUS_OBJECT_NAME_NOT_FOUND";
            case -0x3fffffcb:
              return "STATUS_OBJECT_NAME_COLLISION";
            }
          }
        }
        else {
          switch(param_1) {
          case -0x3fffffc8:
            return "STATUS_DEVICE_ALREADY_ATTACHED";
          case -0x3fffffc7:
            return "STATUS_OBJECT_PATH_INVALID";
          case -0x3fffffc6:
            return "STATUS_OBJECT_PATH_NOT_FOUND";
          case -0x3fffffc5:
            return "STATUS_OBJECT_PATH_SYNTAX_BAD";
          case -0x3fffffc4:
            return "STATUS_DATA_OVERRUN";
          case -0x3fffffc3:
            return "STATUS_DATA_LATE_ERROR";
          case -0x3fffffc2:
            return "STATUS_DATA_ERROR";
          case -0x3fffffc1:
            return "STATUS_CRC_ERROR";
          case -0x3fffffc0:
            return "STATUS_SECTION_TOO_BIG";
          case -0x3fffffbf:
            return "STATUS_PORT_CONNECTION_REFUSED";
          case -0x3fffffbe:
            return "STATUS_INVALID_PORT_HANDLE";
          case -0x3fffffbd:
            return "STATUS_SHARING_VIOLATION";
          case -0x3fffffbc:
            return "STATUS_QUOTA_EXCEEDED";
          case -0x3fffffbb:
            return "STATUS_INVALID_PAGE_PROTECTION";
          case -0x3fffffba:
            return "STATUS_MUTANT_NOT_OWNED";
          case -0x3fffffb9:
            return "STATUS_SEMAPHORE_LIMIT_EXCEEDED";
          case -0x3fffffb8:
            return "STATUS_PORT_ALREADY_SET";
          case -0x3fffffb7:
            return "STATUS_SECTION_NOT_IMAGE";
          case -0x3fffffb6:
            return "STATUS_SUSPEND_COUNT_EXCEEDED";
          case -0x3fffffb5:
            return "STATUS_THREAD_IS_TERMINATING";
          case -0x3fffffb4:
            return "STATUS_BAD_WORKING_SET_LIMIT";
          case -0x3fffffb3:
            return "STATUS_INCOMPATIBLE_FILE_MAP";
          case -0x3fffffb2:
            return "STATUS_SECTION_PROTECTION";
          case -0x3fffffb1:
            return "STATUS_EAS_NOT_SUPPORTED";
          case -0x3fffffb0:
            return "STATUS_EA_TOO_LARGE";
          case -0x3fffffaf:
            return "STATUS_NONEXISTENT_EA_ENTRY";
          case -0x3fffffae:
            return "STATUS_NO_EAS_ON_FILE";
          case -0x3fffffad:
            return "STATUS_EA_CORRUPT_ERROR";
          case -0x3fffffac:
            return "STATUS_FILE_LOCK_CONFLICT";
          case -0x3fffffab:
            return "STATUS_LOCK_NOT_GRANTED";
          case -0x3fffffaa:
            return "STATUS_DELETE_PENDING";
          case -0x3fffffa9:
            return "STATUS_CTL_FILE_NOT_SUPPORTED";
          case -0x3fffffa8:
            return "STATUS_UNKNOWN_REVISION";
          case -0x3fffffa7:
            return "STATUS_REVISION_MISMATCH";
          case -0x3fffffa6:
            return "STATUS_INVALID_OWNER";
          case -0x3fffffa5:
            return "STATUS_INVALID_PRIMARY_GROUP";
          case -0x3fffffa4:
            return "STATUS_NO_IMPERSONATION_TOKEN";
          case -0x3fffffa3:
            return "STATUS_CANT_DISABLE_MANDATORY";
          case -0x3fffffa2:
            return "STATUS_NO_LOGON_SERVERS";
          case -0x3fffffa1:
            return "STATUS_NO_SUCH_LOGON_SESSION";
          case -0x3fffffa0:
            return "STATUS_NO_SUCH_PRIVILEGE";
          case -0x3fffff9f:
            return "STATUS_PRIVILEGE_NOT_HELD";
          case -0x3fffff9e:
            return "STATUS_INVALID_ACCOUNT_NAME";
          case -0x3fffff9d:
            return "STATUS_USER_EXISTS";
          case -0x3fffff9c:
            return "STATUS_NO_SUCH_USER";
          case -0x3fffff9b:
            return "STATUS_GROUP_EXISTS";
          case -0x3fffff9a:
            return "STATUS_NO_SUCH_GROUP";
          case -0x3fffff99:
            return "STATUS_MEMBER_IN_GROUP";
          case -0x3fffff98:
            return "STATUS_MEMBER_NOT_IN_GROUP";
          case -0x3fffff97:
            return "STATUS_LAST_ADMIN";
          case -0x3fffff96:
            return "STATUS_WRONG_PASSWORD";
          case -0x3fffff95:
            return "STATUS_ILL_FORMED_PASSWORD";
          case -0x3fffff94:
            return "STATUS_PASSWORD_RESTRICTION";
          case -0x3fffff93:
            return "STATUS_LOGON_FAILURE";
          }
        }
      }
      else {
        switch(param_1) {
        case -0x3fffff91:
          return "STATUS_INVALID_LOGON_HOURS";
        case -0x3fffff90:
          return "STATUS_INVALID_WORKSTATION";
        case -0x3fffff8f:
          return "STATUS_PASSWORD_EXPIRED";
        case -0x3fffff8e:
          return "STATUS_ACCOUNT_DISABLED";
        case -0x3fffff8d:
          return "STATUS_NONE_MAPPED";
        case -0x3fffff8c:
          return "STATUS_TOO_MANY_LUIDS_REQUESTED";
        case -0x3fffff8b:
          return "STATUS_LUIDS_EXHAUSTED";
        case -0x3fffff8a:
          return "STATUS_INVALID_SUB_AUTHORITY";
        case -0x3fffff89:
          return "STATUS_INVALID_ACL";
        case -0x3fffff88:
          return "STATUS_INVALID_SID";
        case -0x3fffff87:
          return "STATUS_INVALID_SECURITY_DESCR";
        case -0x3fffff86:
          return "STATUS_PROCEDURE_NOT_FOUND";
        case -0x3fffff85:
          return "STATUS_INVALID_IMAGE_FORMAT";
        case -0x3fffff84:
          return "STATUS_NO_TOKEN";
        case -0x3fffff83:
          return "STATUS_BAD_INHERITANCE_ACL";
        case -0x3fffff82:
          return "STATUS_RANGE_NOT_LOCKED";
        case -0x3fffff81:
          return "STATUS_DISK_FULL";
        case -0x3fffff80:
          return "STATUS_SERVER_DISABLED";
        case -0x3fffff7f:
          return "STATUS_SERVER_NOT_DISABLED";
        case -0x3fffff7e:
          return "STATUS_TOO_MANY_GUIDS_REQUESTED";
        case -0x3fffff7d:
          return "STATUS_GUIDS_EXHAUSTED";
        case -0x3fffff7c:
          return "STATUS_INVALID_ID_AUTHORITY";
        case -0x3fffff7b:
          return "STATUS_AGENTS_EXHAUSTED";
        case -0x3fffff7a:
          return "STATUS_INVALID_VOLUME_LABEL";
        case -0x3fffff79:
          return "STATUS_SECTION_NOT_EXTENDED";
        case -0x3fffff78:
          return "STATUS_NOT_MAPPED_DATA";
        case -0x3fffff77:
          return "STATUS_RESOURCE_DATA_NOT_FOUND";
        case -0x3fffff76:
          return "STATUS_RESOURCE_TYPE_NOT_FOUND";
        case -0x3fffff75:
          return "STATUS_RESOURCE_NAME_NOT_FOUND";
        case -0x3fffff74:
          return "STATUS_ARRAY_BOUNDS_EXCEEDED";
        case -0x3fffff73:
          return "STATUS_FLOAT_DENORMAL_OPERAND";
        case -0x3fffff72:
          return "STATUS_FLOAT_DIVIDE_BY_ZERO";
        case -0x3fffff71:
          return "STATUS_FLOAT_INEXACT_RESULT";
        case -0x3fffff70:
          return "STATUS_FLOAT_INVALID_OPERATION";
        case -0x3fffff6f:
          return "STATUS_FLOAT_OVERFLOW";
        case -0x3fffff6e:
          return "STATUS_FLOAT_STACK_CHECK";
        case -0x3fffff6d:
          return "STATUS_FLOAT_UNDERFLOW";
        case -0x3fffff6c:
          return "STATUS_INTEGER_DIVIDE_BY_ZERO";
        case -0x3fffff6b:
          return "STATUS_INTEGER_OVERFLOW";
        case -0x3fffff6a:
          return "STATUS_PRIVILEGED_INSTRUCTION";
        case -0x3fffff69:
          return "STATUS_TOO_MANY_PAGING_FILES";
        case -0x3fffff68:
          return "STATUS_FILE_INVALID";
        case -0x3fffff67:
          return "STATUS_ALLOTTED_SPACE_EXCEEDED";
        case -0x3fffff66:
          return "STATUS_INSUFFICIENT_RESOURCES";
        case -0x3fffff65:
          return "STATUS_DFS_EXIT_PATH_FOUND";
        case -0x3fffff64:
          return "STATUS_DEVICE_DATA_ERROR";
        case -0x3fffff63:
          return "STATUS_DEVICE_NOT_CONNECTED";
        case -0x3fffff62:
          return "STATUS_DEVICE_POWER_FAILURE";
        case -0x3fffff61:
          return "STATUS_FREE_VM_NOT_AT_BASE";
        case -0x3fffff60:
          return "STATUS_MEMORY_NOT_ALLOCATED";
        case -0x3fffff5f:
          return "STATUS_WORKING_SET_QUOTA";
        case -0x3fffff5e:
          return "STATUS_MEDIA_WRITE_PROTECTED";
        case -0x3fffff5d:
          return "STATUS_DEVICE_NOT_READY";
        case -0x3fffff5c:
          return "STATUS_INVALID_GROUP_ATTRIBUTES";
        case -0x3fffff5b:
          return "STATUS_BAD_IMPERSONATION_LEVEL";
        case -0x3fffff5a:
          return "STATUS_CANT_OPEN_ANONYMOUS";
        case -0x3fffff59:
          return "STATUS_BAD_VALIDATION_CLASS";
        case -0x3fffff58:
          return "STATUS_BAD_TOKEN_TYPE";
        case -0x3fffff57:
          return "STATUS_BAD_MASTER_BOOT_RECORD";
        case -0x3fffff56:
          return "STATUS_INSTRUCTION_MISALIGNMENT";
        case -0x3fffff55:
          return "STATUS_INSTANCE_NOT_AVAILABLE";
        case -0x3fffff54:
          return "STATUS_PIPE_NOT_AVAILABLE";
        case -0x3fffff53:
          return "STATUS_INVALID_PIPE_STATE";
        case -0x3fffff52:
          return "STATUS_PIPE_BUSY";
        case -0x3fffff51:
          return "STATUS_ILLEGAL_FUNCTION";
        case -0x3fffff50:
          return "STATUS_PIPE_DISCONNECTED";
        case -0x3fffff4f:
          return "STATUS_PIPE_CLOSING";
        case -0x3fffff4e:
          return "STATUS_PIPE_CONNECTED";
        case -0x3fffff4d:
          return "STATUS_PIPE_LISTENING";
        case -0x3fffff4c:
          return "STATUS_INVALID_READ_MODE";
        case -0x3fffff4b:
          return "STATUS_IO_TIMEOUT";
        case -0x3fffff4a:
          return "STATUS_FILE_FORCED_CLOSED";
        case -0x3fffff49:
          return "STATUS_PROFILING_NOT_STARTED";
        case -0x3fffff48:
          return "STATUS_PROFILING_NOT_STOPPED";
        case -0x3fffff47:
          return "STATUS_COULD_NOT_INTERPRET";
        case -0x3fffff46:
          return "STATUS_FILE_IS_A_DIRECTORY";
        case -0x3fffff45:
          return "STATUS_NOT_SUPPORTED";
        case -0x3fffff44:
          return "STATUS_REMOTE_NOT_LISTENING";
        case -0x3fffff43:
          return "STATUS_DUPLICATE_NAME";
        case -0x3fffff42:
          return "STATUS_BAD_NETWORK_PATH";
        case -0x3fffff41:
          return "STATUS_NETWORK_BUSY";
        case -0x3fffff40:
          return "STATUS_DEVICE_DOES_NOT_EXIST";
        case -0x3fffff3f:
          return "STATUS_TOO_MANY_COMMANDS";
        case -0x3fffff3e:
          return "STATUS_ADAPTER_HARDWARE_ERROR";
        case -0x3fffff3d:
          return "STATUS_INVALID_NETWORK_RESPONSE";
        case -0x3fffff3c:
          return "STATUS_UNEXPECTED_NETWORK_ERROR";
        case -0x3fffff3b:
          return "STATUS_BAD_REMOTE_ADAPTER";
        case -0x3fffff3a:
          return "STATUS_PRINT_QUEUE_FULL";
        case -0x3fffff39:
          return "STATUS_NO_SPOOL_SPACE";
        case -0x3fffff38:
          return "STATUS_PRINT_CANCELLED";
        case -0x3fffff37:
          return "STATUS_NETWORK_NAME_DELETED";
        case -0x3fffff36:
          return "STATUS_NETWORK_ACCESS_DENIED";
        case -0x3fffff35:
          return "STATUS_BAD_DEVICE_TYPE";
        case -0x3fffff34:
          return "STATUS_BAD_NETWORK_NAME";
        case -0x3fffff33:
          return "STATUS_TOO_MANY_NAMES";
        case -0x3fffff32:
          return "STATUS_TOO_MANY_SESSIONS";
        case -0x3fffff31:
          return "STATUS_SHARING_PAUSED";
        case -0x3fffff30:
          return "STATUS_REQUEST_NOT_ACCEPTED";
        case -0x3fffff2f:
          return "STATUS_REDIRECTOR_PAUSED";
        case -0x3fffff2e:
          return "STATUS_NET_WRITE_FAULT";
        case -0x3fffff2d:
          return "STATUS_PROFILING_AT_LIMIT";
        case -0x3fffff2c:
          return "STATUS_NOT_SAME_DEVICE";
        case -0x3fffff2b:
          return "STATUS_FILE_RENAMED";
        case -0x3fffff2a:
          return "STATUS_VIRTUAL_CIRCUIT_CLOSED";
        case -0x3fffff29:
          return "STATUS_NO_SECURITY_ON_OBJECT";
        case -0x3fffff28:
          return "STATUS_CANT_WAIT";
        case -0x3fffff27:
          return "STATUS_PIPE_EMPTY";
        case -0x3fffff26:
          return "STATUS_CANT_ACCESS_DOMAIN_INFO";
        case -0x3fffff25:
          return "STATUS_CANT_TERMINATE_SELF";
        }
      }
    }
    else if (param_1 + 0x3fffff23U < 0x145) {
                    /* WARNING (jumptable): Sanity check requires truncation of jumptable */
                    /* WARNING: Could not find normalized switch variable to match jumptable */
      switch((&DAT_00023e44)[(int)(param_1 + 0x3fffff23U)]) {
      case 0:
        return "STATUS_INVALID_DOMAIN_STATE";
      case 1:
        return "STATUS_INVALID_DOMAIN_ROLE";
      case 2:
        return "STATUS_NO_SUCH_DOMAIN";
      case 3:
        return "STATUS_DOMAIN_EXISTS";
      case 4:
        return "STATUS_DOMAIN_LIMIT_EXCEEDED";
      case 5:
        return "STATUS_OPLOCK_NOT_GRANTED";
      case 6:
        return "STATUS_INVALID_OPLOCK_PROTOCOL";
      case 7:
        return "STATUS_INTERNAL_DB_CORRUPTION";
      case 8:
        return "STATUS_INTERNAL_ERROR";
      case 9:
        return "STATUS_GENERIC_NOT_MAPPED";
      case 10:
        return "STATUS_BAD_DESCRIPTOR_FORMAT";
      case 0xb:
        return "STATUS_INVALID_USER_BUFFER";
      case 0xc:
        return "STATUS_UNEXPECTED_IO_ERROR";
      case 0xd:
        return "STATUS_UNEXPECTED_MM_CREATE_ERR";
      case 0xe:
        return "STATUS_UNEXPECTED_MM_MAP_ERROR";
      case 0xf:
        return "STATUS_UNEXPECTED_MM_EXTEND_ERR";
      case 0x10:
        return "STATUS_NOT_LOGON_PROCESS";
      case 0x11:
        return "STATUS_LOGON_SESSION_EXISTS";
      case 0x12:
        return "STATUS_INVALID_PARAMETER_1";
      case 0x13:
        return "STATUS_INVALID_PARAMETER_2";
      case 0x14:
        return "STATUS_INVALID_PARAMETER_3";
      case 0x15:
        return "STATUS_INVALID_PARAMETER_4";
      case 0x16:
        return "STATUS_INVALID_PARAMETER_5";
      case 0x17:
        return "STATUS_INVALID_PARAMETER_6";
      case 0x18:
        return "STATUS_INVALID_PARAMETER_7";
      case 0x19:
        return "STATUS_INVALID_PARAMETER_8";
      case 0x1a:
        return "STATUS_INVALID_PARAMETER_9";
      case 0x1b:
        return "STATUS_INVALID_PARAMETER_10";
      case 0x1c:
        return "STATUS_INVALID_PARAMETER_11";
      case 0x1d:
        return "STATUS_INVALID_PARAMETER_12";
      case 0x1e:
        return "STATUS_REDIRECTOR_NOT_STARTED";
      case 0x1f:
        return "STATUS_REDIRECTOR_STARTED";
      case 0x20:
        return "STATUS_STACK_OVERFLOW";
      case 0x21:
        return "STATUS_NO_SUCH_PACKAGE";
      case 0x22:
        return "STATUS_BAD_FUNCTION_TABLE";
      case 0x23:
        return "STATUS_VARIABLE_NOT_FOUND";
      case 0x24:
        return "STATUS_DIRECTORY_NOT_EMPTY";
      case 0x25:
        return "STATUS_FILE_CORRUPT_ERROR";
      case 0x26:
        return "STATUS_NOT_A_DIRECTORY";
      case 0x27:
        return "STATUS_BAD_LOGON_SESSION_STATE";
      case 0x28:
        return "STATUS_LOGON_SESSION_COLLISION";
      case 0x29:
        return "STATUS_NAME_TOO_LONG";
      case 0x2a:
        return "STATUS_FILES_OPEN";
      case 0x2b:
        return "STATUS_CONNECTION_IN_USE";
      case 0x2c:
        return "STATUS_MESSAGE_NOT_FOUND";
      case 0x2d:
        return "STATUS_PROCESS_IS_TERMINATING";
      case 0x2e:
        return "STATUS_INVALID_LOGON_TYPE";
      case 0x2f:
        return "STATUS_NO_GUID_TRANSLATION";
      case 0x30:
        return "STATUS_CANNOT_IMPERSONATE";
      case 0x31:
        return "STATUS_IMAGE_ALREADY_LOADED";
      case 0x32:
        return "STATUS_ABIOS_NOT_PRESENT";
      case 0x33:
        return "STATUS_ABIOS_LID_NOT_EXIST";
      case 0x34:
        return "STATUS_ABIOS_LID_ALREADY_OWNED";
      case 0x35:
        return "STATUS_ABIOS_NOT_LID_OWNER";
      case 0x36:
        return "STATUS_ABIOS_INVALID_COMMAND";
      case 0x37:
        return "STATUS_ABIOS_INVALID_LID";
      case 0x38:
        return "STATUS_ABIOS_SELECTOR_NOT_AVAILABLE";
      case 0x39:
        return "STATUS_ABIOS_INVALID_SELECTOR";
      case 0x3a:
        return "STATUS_NO_LDT";
      case 0x3b:
        return "STATUS_INVALID_LDT_SIZE";
      case 0x3c:
        return "STATUS_INVALID_LDT_OFFSET";
      case 0x3d:
        return "STATUS_INVALID_LDT_DESCRIPTOR";
      case 0x3e:
        return "STATUS_INVALID_IMAGE_NE_FORMAT";
      case 0x3f:
        return "STATUS_RXACT_INVALID_STATE";
      case 0x40:
        return "STATUS_RXACT_COMMIT_FAILURE";
      case 0x41:
        return "STATUS_MAPPED_FILE_SIZE_ZERO";
      case 0x42:
        return "STATUS_TOO_MANY_OPENED_FILES";
      case 0x43:
        return "STATUS_CANCELLED";
      case 0x44:
        return "STATUS_CANNOT_DELETE";
      case 0x45:
        return "STATUS_INVALID_COMPUTER_NAME";
      case 0x46:
        return "STATUS_FILE_DELETED";
      case 0x47:
        return "STATUS_SPECIAL_ACCOUNT";
      case 0x48:
        return "STATUS_SPECIAL_GROUP";
      case 0x49:
        return "STATUS_SPECIAL_USER";
      case 0x4a:
        return "STATUS_MEMBERS_PRIMARY_GROUP";
      case 0x4b:
        return "STATUS_FILE_CLOSED";
      case 0x4c:
        return "STATUS_TOO_MANY_THREADS";
      case 0x4d:
        return "STATUS_THREAD_NOT_IN_PROCESS";
      case 0x4e:
        return "STATUS_TOKEN_ALREADY_IN_USE";
      case 0x4f:
        return "STATUS_PAGEFILE_QUOTA_EXCEEDED";
      case 0x50:
        return "STATUS_COMMITMENT_LIMIT";
      case 0x51:
        return "STATUS_INVALID_IMAGE_LE_FORMAT";
      case 0x52:
        return "STATUS_INVALID_IMAGE_NOT_MZ";
      case 0x53:
        return "STATUS_INVALID_IMAGE_PROTECT";
      case 0x54:
        return "STATUS_INVALID_IMAGE_WIN_16";
      case 0x55:
        return "STATUS_LOGON_SERVER_CONFLICT";
      case 0x56:
        return "STATUS_TIME_DIFFERENCE_AT_DC";
      case 0x57:
        return "STATUS_SYNCHRONIZATION_REQUIRED";
      case 0x58:
        return "STATUS_DLL_NOT_FOUND";
      case 0x59:
        return "STATUS_OPEN_FAILED";
      case 0x5a:
        return "STATUS_IO_PRIVILEGE_FAILED";
      case 0x5b:
        return "STATUS_ORDINAL_NOT_FOUND";
      case 0x5c:
        return "STATUS_ENTRYPOINT_NOT_FOUND";
      case 0x5d:
        return "STATUS_CONTROL_C_EXIT";
      case 0x5e:
        return "STATUS_LOCAL_DISCONNECT";
      case 0x5f:
        return "STATUS_REMOTE_DISCONNECT";
      case 0x60:
        return "STATUS_REMOTE_RESOURCES";
      case 0x61:
        return "STATUS_LINK_FAILED";
      case 0x62:
        return "STATUS_LINK_TIMEOUT";
      case 99:
        return "STATUS_INVALID_CONNECTION";
      case 100:
        return "STATUS_INVALID_ADDRESS";
      case 0x65:
        return "STATUS_DLL_INIT_FAILED";
      case 0x66:
        return "STATUS_MISSING_SYSTEMFILE";
      case 0x67:
        return "STATUS_UNHANDLED_EXCEPTION";
      case 0x68:
        return "STATUS_APP_INIT_FAILURE";
      case 0x69:
        return "STATUS_PAGEFILE_CREATE_FAILED";
      case 0x6a:
        return "STATUS_NO_PAGEFILE";
      case 0x6b:
        return "STATUS_INVALID_LEVEL";
      case 0x6c:
        return "STATUS_WRONG_PASSWORD_CORE";
      case 0x6d:
        return "STATUS_ILLEGAL_FLOAT_CONTEXT";
      case 0x6e:
        return "STATUS_PIPE_BROKEN";
      case 0x6f:
        return "STATUS_REGISTRY_CORRUPT";
      case 0x70:
        return "STATUS_REGISTRY_IO_FAILED";
      case 0x71:
        return "STATUS_NO_EVENT_PAIR";
      case 0x72:
        return "STATUS_UNRECOGNIZED_VOLUME";
      case 0x73:
        return "STATUS_SERIAL_NO_DEVICE_INITED";
      case 0x74:
        return "STATUS_NO_SUCH_ALIAS";
      case 0x75:
        return "STATUS_MEMBER_NOT_IN_ALIAS";
      case 0x76:
        return "STATUS_MEMBER_IN_ALIAS";
      case 0x77:
        return "STATUS_ALIAS_EXISTS";
      case 0x78:
        return "STATUS_LOGON_NOT_GRANTED";
      case 0x79:
        return "STATUS_TOO_MANY_SECRETS";
      case 0x7a:
        return "STATUS_SECRET_TOO_LONG";
      case 0x7b:
        return "STATUS_INTERNAL_DB_ERROR";
      case 0x7c:
        return "STATUS_FULLSCREEN_MODE";
      case 0x7d:
        return "STATUS_TOO_MANY_CONTEXT_IDS";
      case 0x7e:
        return "STATUS_LOGON_TYPE_NOT_GRANTED";
      case 0x7f:
        return "STATUS_NOT_REGISTRY_FILE";
      case 0x80:
        return "STATUS_NT_CROSS_ENCRYPTION_REQUIRED";
      case 0x81:
        return "STATUS_DOMAIN_CTRLR_CONFIG_ERROR";
      case 0x82:
        return "STATUS_FT_MISSING_MEMBER";
      case 0x83:
        return "STATUS_ILL_FORMED_SERVICE_ENTRY";
      case 0x84:
        return "STATUS_ILLEGAL_CHARACTER";
      case 0x85:
        return "STATUS_UNMAPPABLE_CHARACTER";
      case 0x86:
        return "STATUS_UNDEFINED_CHARACTER";
      case 0x87:
        return "STATUS_FLOPPY_VOLUME";
      case 0x88:
        return "STATUS_FLOPPY_ID_MARK_NOT_FOUND";
      case 0x89:
        return "STATUS_FLOPPY_WRONG_CYLINDER";
      case 0x8a:
        return "STATUS_FLOPPY_UNKNOWN_ERROR";
      case 0x8b:
        return "STATUS_FLOPPY_BAD_REGISTERS";
      case 0x8c:
        return "STATUS_DISK_RECALIBRATE_FAILED";
      case 0x8d:
        return "STATUS_DISK_OPERATION_FAILED";
      case 0x8e:
        return "STATUS_DISK_RESET_FAILED";
      case 0x8f:
        return "STATUS_SHARED_IRQ_BUSY";
      case 0x90:
        return "STATUS_FT_ORPHANING";
      case 0x91:
        return "STATUS_BIOS_FAILED_TO_CONNECT_INTERRUPT";
      case 0x92:
        return "STATUS_PARTITION_FAILURE";
      case 0x93:
        return "STATUS_INVALID_BLOCK_LENGTH";
      case 0x94:
        return "STATUS_DEVICE_NOT_PARTITIONED";
      case 0x95:
        return "STATUS_UNABLE_TO_LOCK_MEDIA";
      case 0x96:
        return "STATUS_UNABLE_TO_UNLOAD_MEDIA";
      case 0x97:
        return "STATUS_EOM_OVERFLOW";
      case 0x98:
        return "STATUS_NO_MEDIA";
      case 0x99:
        return "STATUS_NO_SUCH_MEMBER";
      case 0x9a:
        return "STATUS_INVALID_MEMBER";
      case 0x9b:
        return "STATUS_KEY_DELETED";
      case 0x9c:
        return "STATUS_NO_LOG_SPACE";
      case 0x9d:
        return "STATUS_TOO_MANY_SIDS";
      case 0x9e:
        return "STATUS_LM_CROSS_ENCRYPTION_REQUIRED";
      case 0x9f:
        return "STATUS_KEY_HAS_CHILDREN";
      case 0xa0:
        return "STATUS_CHILD_MUST_BE_VOLATILE";
      case 0xa1:
        return "STATUS_DEVICE_CONFIGURATION_ERROR";
      case 0xa2:
        return "STATUS_DRIVER_INTERNAL_ERROR";
      case 0xa3:
        return "STATUS_INVALID_DEVICE_STATE";
      case 0xa4:
        return "STATUS_IO_DEVICE_ERROR";
      case 0xa5:
        return "STATUS_DEVICE_PROTOCOL_ERROR";
      case 0xa6:
        return "STATUS_BACKUP_CONTROLLER";
      case 0xa7:
        return "STATUS_LOG_FILE_FULL";
      case 0xa8:
        return "STATUS_TOO_LATE";
      case 0xa9:
        return "STATUS_NO_TRUST_LSA_SECRET";
      case 0xaa:
        return "STATUS_NO_TRUST_SAM_ACCOUNT";
      case 0xab:
        return "STATUS_TRUSTED_DOMAIN_FAILURE";
      case 0xac:
        return "STATUS_TRUSTED_RELATIONSHIP_FAILURE";
      case 0xad:
        return "STATUS_EVENTLOG_FILE_CORRUPT";
      case 0xae:
        return "STATUS_EVENTLOG_CANT_START";
      case 0xaf:
        return "STATUS_TRUST_FAILURE";
      case 0xb0:
        return "STATUS_MUTANT_LIMIT_EXCEEDED";
      case 0xb1:
        return "STATUS_NETLOGON_NOT_STARTED";
      case 0xb2:
        return "STATUS_ACCOUNT_EXPIRED";
      case 0xb3:
        return "STATUS_POSSIBLE_DEADLOCK";
      case 0xb4:
        return "STATUS_NETWORK_CREDENTIAL_CONFLICT";
      case 0xb5:
        return "STATUS_REMOTE_SESSION_LIMIT";
      case 0xb6:
        return "STATUS_EVENTLOG_FILE_CHANGED";
      case 0xb7:
        return "STATUS_NOLOGON_INTERDOMAIN_TRUST_ACCOUNT";
      case 0xb8:
        return "STATUS_NOLOGON_WORKSTATION_TRUST_ACCOUNT";
      case 0xb9:
        return "STATUS_NOLOGON_SERVER_TRUST_ACCOUNT";
      case 0xba:
        return "STATUS_DOMAIN_TRUST_INCONSISTENT";
      case 0xbb:
        return "STATUS_FS_DRIVER_REQUIRED";
      case 0xbc:
        return "STATUS_NO_USER_SESSION_KEY";
      case 0xbd:
        return "STATUS_USER_SESSION_DELETED";
      case 0xbe:
        return "STATUS_RESOURCE_LANG_NOT_FOUND";
      case 0xbf:
        return "STATUS_INSUFF_SERVER_RESOURCES";
      case 0xc0:
        return "STATUS_INVALID_BUFFER_SIZE";
      case 0xc1:
        return "STATUS_INVALID_ADDRESS_COMPONENT";
      case 0xc2:
        return "STATUS_INVALID_ADDRESS_WILDCARD";
      case 0xc3:
        return "STATUS_TOO_MANY_ADDRESSES";
      case 0xc4:
        return "STATUS_ADDRESS_ALREADY_EXISTS";
      case 0xc5:
        return "STATUS_ADDRESS_CLOSED";
      case 0xc6:
        return "STATUS_CONNECTION_DISCONNECTED";
      case 199:
        return "STATUS_CONNECTION_RESET";
      case 200:
        return "STATUS_TOO_MANY_NODES";
      case 0xc9:
        return "STATUS_TRANSACTION_ABORTED";
      case 0xca:
        return "STATUS_TRANSACTION_TIMED_OUT";
      case 0xcb:
        return "STATUS_TRANSACTION_NO_RELEASE";
      case 0xcc:
        return "STATUS_TRANSACTION_NO_MATCH";
      case 0xcd:
        return "STATUS_TRANSACTION_RESPONDED";
      case 0xce:
        return "STATUS_TRANSACTION_INVALID_ID";
      case 0xcf:
        return "STATUS_TRANSACTION_INVALID_TYPE";
      case 0xd0:
        return "STATUS_NOT_SERVER_SESSION";
      case 0xd1:
        return "STATUS_NOT_CLIENT_SESSION";
      case 0xd2:
        return "STATUS_CANNOT_LOAD_REGISTRY_FILE";
      case 0xd3:
        return "STATUS_DEBUG_ATTACH_FAILED";
      case 0xd4:
        return "STATUS_SYSTEM_PROCESS_TERMINATED";
      case 0xd5:
        return "STATUS_DATA_NOT_ACCEPTED";
      case 0xd6:
        return "STATUS_NO_BROWSER_SERVERS_FOUND";
      case 0xd7:
        return "STATUS_VDM_HARD_ERROR";
      case 0xd8:
        return "STATUS_DRIVER_CANCEL_TIMEOUT";
      case 0xd9:
        return "STATUS_REPLY_MESSAGE_MISMATCH";
      case 0xda:
        return "STATUS_MAPPED_ALIGNMENT";
      case 0xdb:
        return "STATUS_IMAGE_CHECKSUM_MISMATCH";
      }
    }
  }
  else if (param_1 < -0x3ffffcff) {
    if (param_1 == -0x3ffffd00) {
      return "STATUS_NOT_SUPPORTED_ON_SBS";
    }
    switch(param_1) {
    case -0x3ffffddd:
      return "STATUS_CLIENT_SERVER_PARAMETERS_INVALID";
    case -0x3ffffddc:
      return "STATUS_PASSWORD_MUST_CHANGE";
    case -0x3ffffddb:
      return "STATUS_NOT_FOUND";
    case -0x3ffffdda:
      return "STATUS_NOT_TINY_STREAM";
    case -0x3ffffdd9:
      return "STATUS_RECOVERY_FAILURE";
    case -0x3ffffdd8:
      return "STATUS_STACK_OVERFLOW_READ";
    case -0x3ffffdd7:
      return "STATUS_FAIL_CHECK";
    case -0x3ffffdd6:
      return "STATUS_DUPLICATE_OBJECTID";
    case -0x3ffffdd5:
      return "STATUS_OBJECTID_EXISTS";
    case -0x3ffffdd4:
      return "STATUS_CONVERT_TO_LARGE";
    case -0x3ffffdd3:
      return "STATUS_RETRY";
    case -0x3ffffdd2:
      return "STATUS_FOUND_OUT_OF_SCOPE";
    case -0x3ffffdd1:
      return "STATUS_ALLOCATE_BUCKET";
    case -0x3ffffdd0:
      return "STATUS_PROPSET_NOT_FOUND";
    case -0x3ffffdcf:
      return "STATUS_MARSHALL_OVERFLOW";
    case -0x3ffffdce:
      return "STATUS_INVALID_VARIANT";
    case -0x3ffffdcd:
      return "STATUS_DOMAIN_CONTROLLER_NOT_FOUND";
    case -0x3ffffdcc:
      return "STATUS_ACCOUNT_LOCKED_OUT";
    case -0x3ffffdcb:
      return "STATUS_HANDLE_NOT_CLOSABLE";
    case -0x3ffffdca:
      return "STATUS_CONNECTION_REFUSED";
    case -0x3ffffdc9:
      return "STATUS_GRACEFUL_DISCONNECT";
    case -0x3ffffdc8:
      return "STATUS_ADDRESS_ALREADY_ASSOCIATED";
    case -0x3ffffdc7:
      return "STATUS_ADDRESS_NOT_ASSOCIATED";
    case -0x3ffffdc6:
      return "STATUS_CONNECTION_INVALID";
    case -0x3ffffdc5:
      return "STATUS_CONNECTION_ACTIVE";
    case -0x3ffffdc4:
      return "STATUS_NETWORK_UNREACHABLE";
    case -0x3ffffdc3:
      return "STATUS_HOST_UNREACHABLE";
    case -0x3ffffdc2:
      return "STATUS_PROTOCOL_UNREACHABLE";
    case -0x3ffffdc1:
      return "STATUS_PORT_UNREACHABLE";
    case -0x3ffffdc0:
      return "STATUS_REQUEST_ABORTED";
    case -0x3ffffdbf:
      return "STATUS_CONNECTION_ABORTED";
    case -0x3ffffdbe:
      return "STATUS_BAD_COMPRESSION_BUFFER";
    case -0x3ffffdbd:
      return "STATUS_USER_MAPPED_FILE";
    case -0x3ffffdbc:
      return "STATUS_AUDIT_FAILED";
    case -0x3ffffdbb:
      return "STATUS_TIMER_RESOLUTION_NOT_SET";
    case -0x3ffffdba:
      return "STATUS_CONNECTION_COUNT_LIMIT";
    case -0x3ffffdb9:
      return "STATUS_LOGIN_TIME_RESTRICTION";
    case -0x3ffffdb8:
      return "STATUS_LOGIN_WKSTA_RESTRICTION";
    case -0x3ffffdb7:
      return "STATUS_IMAGE_MP_UP_MISMATCH";
    case -0x3ffffdb0:
      return "STATUS_INSUFFICIENT_LOGON_INFO";
    case -0x3ffffdaf:
      return "STATUS_BAD_DLL_ENTRYPOINT";
    case -0x3ffffdae:
      return "STATUS_BAD_SERVICE_ENTRYPOINT";
    case -0x3ffffdad:
      return "STATUS_LPC_REPLY_LOST";
    case -0x3ffffdac:
      return "STATUS_IP_ADDRESS_CONFLICT1";
    case -0x3ffffdab:
      return "STATUS_IP_ADDRESS_CONFLICT2";
    case -0x3ffffdaa:
      return "STATUS_REGISTRY_QUOTA_LIMIT";
    case -0x3ffffda9:
      return "STATUS_PATH_NOT_COVERED";
    case -0x3ffffda8:
      return "STATUS_NO_CALLBACK_ACTIVE";
    case -0x3ffffda7:
      return "STATUS_LICENSE_QUOTA_EXCEEDED";
    case -0x3ffffda6:
      return "STATUS_PWD_TOO_SHORT";
    case -0x3ffffda5:
      return "STATUS_PWD_TOO_RECENT";
    case -0x3ffffda4:
      return "STATUS_PWD_HISTORY_CONFLICT";
    case -0x3ffffda2:
      return "STATUS_PLUGPLAY_NO_DEVICE";
    case -0x3ffffda1:
      return "STATUS_UNSUPPORTED_COMPRESSION";
    case -0x3ffffda0:
      return "STATUS_INVALID_HW_PROFILE";
    case -0x3ffffd9f:
      return "STATUS_INVALID_PLUGPLAY_DEVICE_PATH";
    case -0x3ffffd9e:
      return "STATUS_DRIVER_ORDINAL_NOT_FOUND";
    case -0x3ffffd9d:
      return "STATUS_DRIVER_ENTRYPOINT_NOT_FOUND";
    case -0x3ffffd9c:
      return "STATUS_RESOURCE_NOT_OWNED";
    case -0x3ffffd9b:
      return "STATUS_TOO_MANY_LINKS";
    case -0x3ffffd9a:
      return "STATUS_QUOTA_LIST_INCONSISTENT";
    case -0x3ffffd99:
      return "STATUS_FILE_IS_OFFLINE";
    case -0x3ffffd98:
      return "STATUS_EVALUATION_EXPIRATION";
    case -0x3ffffd97:
      return "STATUS_ILLEGAL_DLL_RELOCATION";
    case -0x3ffffd96:
      return "STATUS_LICENSE_VIOLATION";
    case -0x3ffffd95:
      return "STATUS_DLL_INIT_FAILED_LOGOFF";
    case -0x3ffffd94:
      return "STATUS_DRIVER_UNABLE_TO_LOAD";
    case -0x3ffffd93:
      return "STATUS_DFS_UNAVAILABLE";
    case -0x3ffffd92:
      return "STATUS_VOLUME_DISMOUNTED";
    case -0x3ffffd91:
      return "STATUS_WX86_INTERNAL_ERROR";
    case -0x3ffffd90:
      return "STATUS_WX86_FLOAT_STACK_CHECK";
    case -0x3ffffd8f:
      return "STATUS_VALIDATE_CONTINUE";
    case -0x3ffffd8e:
      return "STATUS_NO_MATCH";
    case -0x3ffffd8d:
      return "STATUS_NO_MORE_MATCHES";
    case -0x3ffffd8b:
      return "STATUS_NOT_A_REPARSE_POINT";
    case -0x3ffffd8a:
      return "STATUS_IO_REPARSE_TAG_INVALID";
    case -0x3ffffd89:
      return "STATUS_IO_REPARSE_TAG_MISMATCH";
    case -0x3ffffd88:
      return "STATUS_IO_REPARSE_DATA_INVALID";
    case -0x3ffffd87:
      return "STATUS_IO_REPARSE_TAG_NOT_HANDLED";
    case -0x3ffffd80:
      return "STATUS_REPARSE_POINT_NOT_RESOLVED";
    case -0x3ffffd7f:
      return "STATUS_DIRECTORY_IS_A_REPARSE_POINT";
    case -0x3ffffd7e:
      return "STATUS_RANGE_LIST_CONFLICT";
    case -0x3ffffd7d:
      return "STATUS_SOURCE_ELEMENT_EMPTY";
    case -0x3ffffd7c:
      return "STATUS_DESTINATION_ELEMENT_FULL";
    case -0x3ffffd7b:
      return "STATUS_ILLEGAL_ELEMENT_ADDRESS";
    case -0x3ffffd7a:
      return "STATUS_MAGAZINE_NOT_PRESENT";
    case -0x3ffffd79:
      return "STATUS_REINITIALIZATION_NEEDED";
    case -0x3ffffd76:
      return "STATUS_ENCRYPTION_FAILED";
    case -0x3ffffd75:
      return "STATUS_DECRYPTION_FAILED";
    case -0x3ffffd74:
      return "STATUS_RANGE_NOT_FOUND";
    case -0x3ffffd73:
      return "STATUS_NO_RECOVERY_POLICY";
    case -0x3ffffd72:
      return "STATUS_NO_EFS";
    case -0x3ffffd71:
      return "STATUS_WRONG_EFS";
    case -0x3ffffd70:
      return "STATUS_NO_USER_KEYS";
    case -0x3ffffd6f:
      return "STATUS_FILE_NOT_ENCRYPTED";
    case -0x3ffffd6e:
      return "STATUS_NOT_EXPORT_FORMAT";
    case -0x3ffffd6d:
      return "STATUS_FILE_ENCRYPTED";
    case -0x3ffffd6b:
      return "STATUS_WMI_GUID_NOT_FOUND";
    case -0x3ffffd6a:
      return "STATUS_WMI_INSTANCE_NOT_FOUND";
    case -0x3ffffd69:
      return "STATUS_WMI_ITEMID_NOT_FOUND";
    case -0x3ffffd68:
      return "STATUS_WMI_TRY_AGAIN";
    case -0x3ffffd67:
      return "STATUS_SHARED_POLICY";
    case -0x3ffffd66:
      return "STATUS_POLICY_OBJECT_NOT_FOUND";
    case -0x3ffffd65:
      return "STATUS_POLICY_ONLY_IN_DS";
    case -0x3ffffd64:
      return "STATUS_VOLUME_NOT_UPGRADED";
    case -0x3ffffd63:
      return "STATUS_REMOTE_STORAGE_NOT_ACTIVE";
    case -0x3ffffd62:
      return "STATUS_REMOTE_STORAGE_MEDIA_ERROR";
    case -0x3ffffd61:
      return "STATUS_NO_TRACKING_SERVICE";
    case -0x3ffffd60:
      return "STATUS_SERVER_SID_MISMATCH";
    case -0x3ffffd5f:
      return "STATUS_DS_NO_ATTRIBUTE_OR_VALUE";
    case -0x3ffffd5e:
      return "STATUS_DS_INVALID_ATTRIBUTE_SYNTAX";
    case -0x3ffffd5d:
      return "STATUS_DS_ATTRIBUTE_TYPE_UNDEFINED";
    case -0x3ffffd5c:
      return "STATUS_DS_ATTRIBUTE_OR_VALUE_EXISTS";
    case -0x3ffffd5b:
      return "STATUS_DS_BUSY";
    case -0x3ffffd5a:
      return "STATUS_DS_UNAVAILABLE";
    case -0x3ffffd59:
      return "STATUS_DS_NO_RIDS_ALLOCATED";
    case -0x3ffffd58:
      return "STATUS_DS_NO_MORE_RIDS";
    case -0x3ffffd57:
      return "STATUS_DS_INCORRECT_ROLE_OWNER";
    case -0x3ffffd56:
      return "STATUS_DS_RIDMGR_INIT_ERROR";
    case -0x3ffffd55:
      return "STATUS_DS_OBJ_CLASS_VIOLATION";
    case -0x3ffffd54:
      return "STATUS_DS_CANT_ON_NON_LEAF";
    case -0x3ffffd53:
      return "STATUS_DS_CANT_ON_RDN";
    case -0x3ffffd52:
      return "STATUS_DS_CANT_MOD_OBJ_CLASS";
    case -0x3ffffd51:
      return "STATUS_DS_CROSS_DOM_MOVE_FAILED";
    case -0x3ffffd50:
      return "STATUS_DS_GC_NOT_AVAILABLE";
    case -0x3ffffd4f:
      return "STATUS_DIRECTORY_SERVICE_REQUIRED";
    case -0x3ffffd4e:
      return "STATUS_REPARSE_ATTRIBUTE_CONFLICT";
    case -0x3ffffd4d:
      return "STATUS_CANT_ENABLE_DENY_ONLY";
    case -0x3ffffd4c:
      return "STATUS_FLOAT_MULTIPLE_FAULTS";
    case -0x3ffffd4b:
      return "STATUS_FLOAT_MULTIPLE_TRAPS";
    case -0x3ffffd4a:
      return "STATUS_DEVICE_REMOVED";
    case -0x3ffffd49:
      return "STATUS_JOURNAL_DELETE_IN_PROGRESS";
    case -0x3ffffd48:
      return "STATUS_JOURNAL_NOT_ACTIVE";
    case -0x3ffffd47:
      return "STATUS_NOINTERFACE";
    case -0x3ffffd3f:
      return "STATUS_DS_ADMIN_LIMIT_EXCEEDED";
    case -0x3ffffd3e:
      return "STATUS_DRIVER_FAILED_SLEEP";
    case -0x3ffffd3d:
      return "STATUS_MUTUAL_AUTHENTICATION_FAILED";
    case -0x3ffffd3c:
      return "STATUS_CORRUPT_SYSTEM_FILE";
    case -0x3ffffd3b:
      return "STATUS_DATATYPE_MISALIGNMENT_ERROR";
    case -0x3ffffd3a:
      return "STATUS_WMI_READ_ONLY";
    case -0x3ffffd39:
      return "STATUS_WMI_SET_FAILURE";
    case -0x3ffffd38:
      return "STATUS_COMMITMENT_MINIMUM";
    case -0x3ffffd37:
      return "STATUS_REG_NAT_CONSUMPTION";
    case -0x3ffffd36:
      return "STATUS_TRANSPORT_FULL";
    case -0x3ffffd35:
      return "STATUS_DS_SAM_INIT_FAILURE";
    case -0x3ffffd34:
      return "STATUS_ONLY_IF_CONNECTED";
    case -0x3ffffd33:
      return "STATUS_DS_SENSITIVE_GROUP_VIOLATION";
    case -0x3ffffd32:
      return "STATUS_PNP_RESTART_ENUMERATION";
    case -0x3ffffd31:
      return "STATUS_JOURNAL_ENTRY_DELETED";
    case -0x3ffffd30:
      return "STATUS_DS_CANT_MOD_PRIMARYGROUPID";
    case -0x3ffffd2f:
      return "STATUS_SYSTEM_IMAGE_BAD_SIGNATURE";
    case -0x3ffffd2e:
      return "STATUS_PNP_REBOOT_REQUIRED";
    case -0x3ffffd2d:
      return "STATUS_POWER_STATE_INVALID";
    case -0x3ffffd2c:
      return "STATUS_DS_INVALID_GROUP_TYPE";
    case -0x3ffffd2b:
      return "STATUS_DS_NO_NEST_GLOBALGROUP_IN_MIXEDDOMAIN";
    case -0x3ffffd2a:
      return "STATUS_DS_NO_NEST_LOCALGROUP_IN_MIXEDDOMAIN";
    case -0x3ffffd29:
      return "STATUS_DS_GLOBAL_CANT_HAVE_LOCAL_MEMBER";
    case -0x3ffffd28:
      return "STATUS_DS_GLOBAL_CANT_HAVE_UNIVERSAL_MEMBER";
    case -0x3ffffd27:
      return "STATUS_DS_UNIVERSAL_CANT_HAVE_LOCAL_MEMBER";
    case -0x3ffffd26:
      return "STATUS_DS_GLOBAL_CANT_HAVE_CROSSDOMAIN_MEMBER";
    case -0x3ffffd25:
      return "STATUS_DS_LOCAL_CANT_HAVE_CROSSDOMAIN_LOCAL_MEMBER";
    case -0x3ffffd24:
      return "STATUS_DS_HAVE_PRIMARY_MEMBERS";
    case -0x3ffffd23:
      return "STATUS_WMI_NOT_SUPPORTED";
    case -0x3ffffd22:
      return "STATUS_INSUFFICIENT_POWER";
    case -0x3ffffd21:
      return "STATUS_SAM_NEED_BOOTKEY_PASSWORD";
    case -0x3ffffd20:
      return "STATUS_SAM_NEED_BOOTKEY_FLOPPY";
    case -0x3ffffd1f:
      return "STATUS_DS_CANT_START";
    case -0x3ffffd1e:
      return "STATUS_DS_INIT_FAILURE";
    case -0x3ffffd1d:
      return "STATUS_SAM_INIT_FAILURE";
    case -0x3ffffd1c:
      return "STATUS_DS_GC_REQUIRED";
    case -0x3ffffd1b:
      return "STATUS_DS_LOCAL_MEMBER_OF_LOCAL_ONLY";
    case -0x3ffffd1a:
      return "STATUS_DS_NO_FPO_IN_UNIVERSAL_GROUPS";
    case -0x3ffffd19:
      return "STATUS_DS_MACHINE_ACCOUNT_QUOTA_EXCEEDED";
    case -0x3ffffd18:
      return "STATUS_MULTIPLE_FAULT_VIOLATION";
    }
  }
  else if (param_1 < -0x3ff5ffdd) {
    if (param_1 == -0x3ff5ffde) {
      return "STATUS_CTX_GRAPHICS_INVALID";
    }
    if (param_1 < -0x3ffdffbc) {
      if (param_1 == -0x3ffdffbd) {
        return "RPC_NT_INTERNAL_ERROR";
      }
      if (param_1 < -0x3ffdffde) {
        if (param_1 == -0x3ffdffdf) {
          return "RPC_NT_UNSUPPORTED_TYPE";
        }
        if (param_1 < -0x3ffdfff1) {
          if (param_1 == -0x3ffdfff2) {
            return "RPC_NT_ALREADY_LISTENING";
          }
          if (param_1 < -0x3ffdfff9) {
            if (param_1 == -0x3ffdfffa) {
              return "RPC_NT_INVALID_STRING_UUID";
            }
            if (param_1 == -0x3fff6768) {
              return "STATUS_WOW_ASSERTION";
            }
            if (param_1 == -0x3ffeffff) {
              return "DBG_NO_STATE_CHANGE";
            }
            if (param_1 == -0x3ffefffe) {
              return "DBG_APP_NOT_IDLE";
            }
            if (param_1 == -0x3ffdffff) {
              return "RPC_NT_INVALID_STRING_BINDING";
            }
            if (param_1 == -0x3ffdfffe) {
              return "RPC_NT_WRONG_KIND_OF_BINDING";
            }
            if (param_1 == -0x3ffdfffd) {
              return "RPC_NT_INVALID_BINDING";
            }
            if (param_1 == -0x3ffdfffc) {
              return "RPC_NT_PROTSEQ_NOT_SUPPORTED";
            }
            if (param_1 == -0x3ffdfffb) {
              return "RPC_NT_INVALID_RPC_PROTSEQ";
            }
          }
          else {
            if (param_1 == -0x3ffdfff9) {
              return "RPC_NT_INVALID_ENDPOINT_FORMAT";
            }
            if (param_1 == -0x3ffdfff8) {
              return "RPC_NT_INVALID_NET_ADDR";
            }
            if (param_1 == -0x3ffdfff7) {
              return "RPC_NT_NO_ENDPOINT_FOUND";
            }
            if (param_1 == -0x3ffdfff6) {
              return "RPC_NT_INVALID_TIMEOUT";
            }
            if (param_1 == -0x3ffdfff5) {
              return "RPC_NT_OBJECT_NOT_FOUND";
            }
            if (param_1 == -0x3ffdfff4) {
              return "RPC_NT_ALREADY_REGISTERED";
            }
            if (param_1 == -0x3ffdfff3) {
              return "RPC_NT_TYPE_ALREADY_REGISTERED";
            }
          }
        }
        else {
          switch(param_1) {
          case -0x3ffdfff1:
            return "RPC_NT_NO_PROTSEQS_REGISTERED";
          case -0x3ffdfff0:
            return "RPC_NT_NOT_LISTENING";
          case -0x3ffdffef:
            return "RPC_NT_UNKNOWN_MGR_TYPE";
          case -0x3ffdffee:
            return "RPC_NT_UNKNOWN_IF";
          case -0x3ffdffed:
            return "RPC_NT_NO_BINDINGS";
          case -0x3ffdffec:
            return "RPC_NT_NO_PROTSEQS";
          case -0x3ffdffeb:
            return "RPC_NT_CANT_CREATE_ENDPOINT";
          case -0x3ffdffea:
            return "RPC_NT_OUT_OF_RESOURCES";
          case -0x3ffdffe9:
            return "RPC_NT_SERVER_UNAVAILABLE";
          case -0x3ffdffe8:
            return "RPC_NT_SERVER_TOO_BUSY";
          case -0x3ffdffe7:
            return "RPC_NT_INVALID_NETWORK_OPTIONS";
          case -0x3ffdffe6:
            return "RPC_NT_NO_CALL_ACTIVE";
          case -0x3ffdffe5:
            return "RPC_NT_CALL_FAILED";
          case -0x3ffdffe4:
            return "RPC_NT_CALL_FAILED_DNE";
          case -0x3ffdffe3:
            return "RPC_NT_PROTOCOL_ERROR";
          case -0x3ffdffe1:
            return "RPC_NT_UNSUPPORTED_TRANS_SYN";
          }
        }
      }
      else {
        switch(param_1) {
        case -0x3ffdffde:
          return "RPC_NT_INVALID_TAG";
        case -0x3ffdffdd:
          return "RPC_NT_INVALID_BOUND";
        case -0x3ffdffdc:
          return "RPC_NT_NO_ENTRY_NAME";
        case -0x3ffdffdb:
          return "RPC_NT_INVALID_NAME_SYNTAX";
        case -0x3ffdffda:
          return "RPC_NT_UNSUPPORTED_NAME_SYNTAX";
        case -0x3ffdffd8:
          return "RPC_NT_UUID_NO_ADDRESS";
        case -0x3ffdffd7:
          return "RPC_NT_DUPLICATE_ENDPOINT";
        case -0x3ffdffd6:
          return "RPC_NT_UNKNOWN_AUTHN_TYPE";
        case -0x3ffdffd5:
          return "RPC_NT_MAX_CALLS_TOO_SMALL";
        case -0x3ffdffd4:
          return "RPC_NT_STRING_TOO_LONG";
        case -0x3ffdffd3:
          return "RPC_NT_PROTSEQ_NOT_FOUND";
        case -0x3ffdffd2:
          return "RPC_NT_PROCNUM_OUT_OF_RANGE";
        case -0x3ffdffd1:
          return "RPC_NT_BINDING_HAS_NO_AUTH";
        case -0x3ffdffd0:
          return "RPC_NT_UNKNOWN_AUTHN_SERVICE";
        case -0x3ffdffcf:
          return "RPC_NT_UNKNOWN_AUTHN_LEVEL";
        case -0x3ffdffce:
          return "RPC_NT_INVALID_AUTH_IDENTITY";
        case -0x3ffdffcd:
          return "RPC_NT_UNKNOWN_AUTHZ_SERVICE";
        case -0x3ffdffcc:
          return "EPT_NT_INVALID_ENTRY";
        case -0x3ffdffcb:
          return "EPT_NT_CANT_PERFORM_OP";
        case -0x3ffdffca:
          return "EPT_NT_NOT_REGISTERED";
        case -0x3ffdffc9:
          return "RPC_NT_NOTHING_TO_EXPORT";
        case -0x3ffdffc8:
          return "RPC_NT_INCOMPLETE_NAME";
        case -0x3ffdffc7:
          return "RPC_NT_INVALID_VERS_OPTION";
        case -0x3ffdffc6:
          return "RPC_NT_NO_MORE_MEMBERS";
        case -0x3ffdffc5:
          return "RPC_NT_NOT_ALL_OBJS_UNEXPORTED";
        case -0x3ffdffc4:
          return "RPC_NT_INTERFACE_NOT_FOUND";
        case -0x3ffdffc3:
          return "RPC_NT_ENTRY_ALREADY_EXISTS";
        case -0x3ffdffc2:
          return "RPC_NT_ENTRY_NOT_FOUND";
        case -0x3ffdffc1:
          return "RPC_NT_NAME_SERVICE_UNAVAILABLE";
        case -0x3ffdffc0:
          return "RPC_NT_INVALID_NAF_ID";
        case -0x3ffdffbf:
          return "RPC_NT_CANNOT_SUPPORT";
        case -0x3ffdffbe:
          return "RPC_NT_NO_CONTEXT_AVAILABLE";
        }
      }
    }
    else if (param_1 < -0x3ffcfffe) {
      if (param_1 == -0x3ffcffff) {
        return "RPC_NT_NO_MORE_ENTRIES";
      }
      switch(param_1) {
      case -0x3ffdffbc:
        return "RPC_NT_ZERO_DIVIDE";
      case -0x3ffdffbb:
        return "RPC_NT_ADDRESS_ERROR";
      case -0x3ffdffba:
        return "RPC_NT_FP_DIV_ZERO";
      case -0x3ffdffb9:
        return "RPC_NT_FP_UNDERFLOW";
      case -0x3ffdffb8:
        return "RPC_NT_FP_OVERFLOW";
      case -0x3ffdffb7:
        return "RPC_NT_CALL_IN_PROGRESS";
      case -0x3ffdffb6:
        return "RPC_NT_NO_MORE_BINDINGS";
      case -0x3ffdffb5:
        return "RPC_NT_GROUP_MEMBER_NOT_FOUND";
      case -0x3ffdffb4:
        return "EPT_NT_CANT_CREATE";
      case -0x3ffdffb3:
        return "RPC_NT_INVALID_OBJECT";
      case -0x3ffdffb1:
        return "RPC_NT_NO_INTERFACES";
      case -0x3ffdffb0:
        return "RPC_NT_CALL_CANCELLED";
      case -0x3ffdffaf:
        return "RPC_NT_BINDING_INCOMPLETE";
      case -0x3ffdffae:
        return "RPC_NT_COMM_FAILURE";
      case -0x3ffdffad:
        return "RPC_NT_UNSUPPORTED_AUTHN_LEVEL";
      case -0x3ffdffac:
        return "RPC_NT_NO_PRINC_NAME";
      case -0x3ffdffab:
        return "RPC_NT_NOT_RPC_ERROR";
      case -0x3ffdffa9:
        return "RPC_NT_SEC_PKG_ERROR";
      case -0x3ffdffa8:
        return "RPC_NT_NOT_CANCELLED";
      case -0x3ffdff9e:
        return "RPC_NT_INVALID_ASYNC_HANDLE";
      case -0x3ffdff9d:
        return "RPC_NT_INVALID_ASYNC_CALL";
      }
    }
    else if (param_1 < -0x3ffcffa6) {
      if (param_1 == -0x3ffcffa7) {
        return "RPC_NT_INVALID_ES_ACTION";
      }
      switch(param_1) {
      case -0x3ffcfffe:
        return "RPC_NT_SS_CHAR_TRANS_OPEN_FAIL";
      case -0x3ffcfffd:
        return "RPC_NT_SS_CHAR_TRANS_SHORT_FILE";
      case -0x3ffcfffc:
        return "RPC_NT_SS_IN_NULL_CONTEXT";
      case -0x3ffcfffb:
        return "RPC_NT_SS_CONTEXT_MISMATCH";
      case -0x3ffcfffa:
        return "RPC_NT_SS_CONTEXT_DAMAGED";
      case -0x3ffcfff9:
        return "RPC_NT_SS_HANDLES_MISMATCH";
      case -0x3ffcfff8:
        return "RPC_NT_SS_CANNOT_GET_CALL_HANDLE";
      case -0x3ffcfff7:
        return "RPC_NT_NULL_REF_POINTER";
      case -0x3ffcfff6:
        return "RPC_NT_ENUM_VALUE_OUT_OF_RANGE";
      case -0x3ffcfff5:
        return "RPC_NT_BYTE_COUNT_TOO_SMALL";
      case -0x3ffcfff4:
        return "RPC_NT_BAD_STUB_DATA";
      }
    }
    else if (param_1 < -0x3ff5fff7) {
      if (param_1 == -0x3ff5fff8) {
        return "STATUS_CTX_MODEM_INF_NOT_FOUND";
      }
      if (param_1 < -0x3ffbffca) {
        if (param_1 == -0x3ffbffcb) {
          return "STATUS_PNP_BAD_MPS_TABLE";
        }
        if (param_1 == -0x3ffcffa6) {
          return "RPC_NT_WRONG_ES_VERSION";
        }
        if (param_1 == -0x3ffcffa5) {
          return "RPC_NT_WRONG_STUB_VERSION";
        }
        if (param_1 == -0x3ffcffa4) {
          return "RPC_NT_INVALID_PIPE_OBJECT";
        }
        if (param_1 == -0x3ffcffa3) {
          return "RPC_NT_INVALID_PIPE_OPERATION";
        }
        if (param_1 == -0x3ffcffa2) {
          return "RPC_NT_WRONG_PIPE_VERSION";
        }
        if (param_1 == -0x3ffcffa1) {
          return "RPC_NT_PIPE_CLOSED";
        }
        if (param_1 == -0x3ffcffa0) {
          return "RPC_NT_PIPE_DISCIPLINE_ERROR";
        }
        if (param_1 == -0x3ffcff9f) {
          return "RPC_NT_PIPE_EMPTY";
        }
      }
      else {
        if (param_1 == -0x3ffbffca) {
          return "STATUS_PNP_TRANSLATION_FAILED";
        }
        if (param_1 == -0x3ffbffc9) {
          return "STATUS_PNP_IRQ_TRANSLATION_FAILED";
        }
        if (param_1 == -0x3ff5ffff) {
          return "STATUS_CTX_WINSTATION_NAME_INVALID";
        }
        if (param_1 == -0x3ff5fffe) {
          return "STATUS_CTX_INVALID_PD";
        }
        if (param_1 == -0x3ff5fffd) {
          return "STATUS_CTX_PD_NOT_FOUND";
        }
        if (param_1 == -0x3ff5fffa) {
          return "STATUS_CTX_CLOSE_PENDING";
        }
        if (param_1 == -0x3ff5fff9) {
          return "STATUS_CTX_NO_OUTBUF";
        }
      }
    }
    else {
      switch(param_1) {
      case -0x3ff5fff7:
        return "STATUS_CTX_INVALID_MODEMNAME";
      case -0x3ff5fff6:
        return "STATUS_CTX_RESPONSE_ERROR";
      case -0x3ff5fff5:
        return "STATUS_CTX_MODEM_RESPONSE_TIMEOUT";
      case -0x3ff5fff4:
        return "STATUS_CTX_MODEM_RESPONSE_NO_CARRIER";
      case -0x3ff5fff3:
        return "STATUS_CTX_MODEM_RESPONSE_NO_DIALTONE";
      case -0x3ff5fff2:
        return "STATUS_CTX_MODEM_RESPONSE_BUSY";
      case -0x3ff5fff1:
        return "STATUS_CTX_MODEM_RESPONSE_VOICE";
      case -0x3ff5fff0:
        return "STATUS_CTX_TD_ERROR";
      case -0x3ff5ffee:
        return "STATUS_CTX_LICENSE_CLIENT_INVALID";
      case -0x3ff5ffed:
        return "STATUS_CTX_LICENSE_NOT_AVAILABLE";
      case -0x3ff5ffec:
        return "STATUS_CTX_LICENSE_EXPIRED";
      case -0x3ff5ffeb:
        return "STATUS_CTX_WINSTATION_NOT_FOUND";
      case -0x3ff5ffea:
        return "STATUS_CTX_WINSTATION_NAME_COLLISION";
      case -0x3ff5ffe9:
        return "STATUS_CTX_WINSTATION_BUSY";
      case -0x3ff5ffe8:
        return "STATUS_CTX_BAD_VIDEO_MODE";
      }
    }
  }
  else if (param_1 < -0x3febfffe) {
    if (param_1 == -0x3febffff) {
      return "STATUS_ACPI_INVALID_OPCODE";
    }
    switch(param_1) {
    case -0x3ff5ffdc:
      return "STATUS_CTX_NOT_CONSOLE";
    case -0x3ff5ffda:
      return "STATUS_CTX_CLIENT_QUERY_TIMEOUT";
    case -0x3ff5ffd9:
      return "STATUS_CTX_CONSOLE_DISCONNECT";
    case -0x3ff5ffd8:
      return "STATUS_CTX_CONSOLE_CONNECT";
    case -0x3ff5ffd6:
      return "STATUS_CTX_SHADOW_DENIED";
    case -0x3ff5ffd5:
      return "STATUS_CTX_WINSTATION_ACCESS_DENIED";
    case -0x3ff5ffd2:
      return "STATUS_CTX_INVALID_WD";
    case -0x3ff5ffd1:
      return "STATUS_CTX_WD_NOT_FOUND";
    case -0x3ff5ffd0:
      return "STATUS_CTX_SHADOW_INVALID";
    case -0x3ff5ffcf:
      return "STATUS_CTX_SHADOW_DISABLED";
    case -0x3ff5ffce:
      return "STATUS_RDP_PROTOCOL_ERROR";
    case -0x3ff5ffcd:
      return "STATUS_CTX_CLIENT_LICENSE_NOT_SET";
    case -0x3ff5ffcc:
      return "STATUS_CTX_CLIENT_LICENSE_IN_USE";
    }
  }
  else if (param_1 < 1) {
    if (param_1 == 0) {
      return "STATUS_SUCCESS";
    }
    switch(param_1) {
    case -0x3febfffe:
      return "STATUS_ACPI_STACK_OVERFLOW";
    case -0x3febfffd:
      return "STATUS_ACPI_ASSERT_FAILED";
    case -0x3febfffc:
      return "STATUS_ACPI_INVALID_INDEX";
    case -0x3febfffb:
      return "STATUS_ACPI_INVALID_ARGUMENT";
    case -0x3febfffa:
      return "STATUS_ACPI_FATAL";
    case -0x3febfff9:
      return "STATUS_ACPI_INVALID_SUPERNAME";
    case -0x3febfff8:
      return "STATUS_ACPI_INVALID_ARGTYPE";
    case -0x3febfff7:
      return "STATUS_ACPI_INVALID_OBJTYPE";
    case -0x3febfff6:
      return "STATUS_ACPI_INVALID_TARGETTYPE";
    case -0x3febfff5:
      return "STATUS_ACPI_INCORRECT_ARGUMENT_COUNT";
    case -0x3febfff4:
      return "STATUS_ACPI_ADDRESS_NOT_MAPPED";
    case -0x3febfff3:
      return "STATUS_ACPI_INVALID_EVENTTYPE";
    case -0x3febfff2:
      return "STATUS_ACPI_HANDLER_COLLISION";
    case -0x3febfff1:
      return "STATUS_ACPI_INVALID_DATA";
    case -0x3febfff0:
      return "STATUS_ACPI_INVALID_REGION";
    case -0x3febffef:
      return "STATUS_ACPI_INVALID_ACCESS_SIZE";
    case -0x3febffee:
      return "STATUS_ACPI_ACQUIRE_GLOBAL_LOCK";
    case -0x3febffed:
      return "STATUS_ACPI_ALREADY_INITIALIZED";
    case -0x3febffec:
      return "STATUS_ACPI_NOT_INITIALIZED";
    case -0x3febffeb:
      return "STATUS_ACPI_INVALID_MUTEX_LEVEL";
    case -0x3febffea:
      return "STATUS_ACPI_MUTEX_NOT_OWNED";
    case -0x3febffe9:
      return "STATUS_ACPI_MUTEX_NOT_OWNER";
    case -0x3febffe8:
      return "STATUS_ACPI_RS_ACCESS";
    case -0x3febffe7:
      return "STATUS_ACPI_INVALID_TABLE";
    case -0x3febffe0:
      return "STATUS_ACPI_REG_HANDLER_FAILED";
    case -0x3febffdf:
      return "STATUS_ACPI_POWER_REQUEST_FAILED";
    }
  }
  else if (param_1 < 0x4000000a) {
    if (param_1 == 0x40000009) {
      return "STATUS_REGISTRY_RECOVERED";
    }
    if (param_1 < 0x111) {
      if (param_1 == 0x110) {
        return "STATUS_PAGE_FAULT_TRANSITION";
      }
      if (param_1 < 0x105) {
        if (param_1 == 0x104) {
          return "STATUS_REPARSE";
        }
        if (param_1 < 0xc0) {
          if (param_1 == 0xbf) {
            return "STATUS_ABANDONED_WAIT_63";
          }
          if (param_1 == 1) {
            return "STATUS_WAIT_1";
          }
          if (param_1 == 2) {
            return "STATUS_WAIT_2";
          }
          if (param_1 == 3) {
            return "STATUS_WAIT_3";
          }
          if (param_1 == 0x3f) {
            return "STATUS_WAIT_63";
          }
          if (param_1 == 0x80) {
            return "STATUS_ABANDONED";
          }
        }
        else {
          if (param_1 == 0xc0) {
            return "STATUS_USER_APC";
          }
          if (param_1 == 0x100) {
            return "STATUS_KERNEL_APC";
          }
          if (param_1 == 0x101) {
            return "STATUS_ALERTED";
          }
          if (param_1 == 0x102) {
            return "STATUS_TIMEOUT";
          }
          if (param_1 == 0x103) {
            return "STATUS_PENDING";
          }
        }
      }
      else if (param_1 < 0x10b) {
        if (param_1 == 0x10a) {
          return "STATUS_RXACT_COMMITTED";
        }
        if (param_1 == 0x105) {
          return "STATUS_MORE_ENTRIES";
        }
        if (param_1 == 0x106) {
          return "STATUS_NOT_ALL_ASSIGNED";
        }
        if (param_1 == 0x107) {
          return "STATUS_SOME_NOT_MAPPED";
        }
        if (param_1 == 0x108) {
          return "STATUS_OPLOCK_BREAK_IN_PROGRESS";
        }
        if (param_1 == 0x109) {
          return "STATUS_VOLUME_MOUNTED";
        }
      }
      else {
        if (param_1 == 0x10b) {
          return "STATUS_NOTIFY_CLEANUP";
        }
        if (param_1 == 0x10c) {
          return "STATUS_NOTIFY_ENUM_DIR";
        }
        if (param_1 == 0x10d) {
          return "STATUS_NO_QUOTAS_FOR_ACCOUNT";
        }
        if (param_1 == 0x10e) {
          return "STATUS_PRIMARY_TRANSPORT_CONNECT_FAILED";
        }
      }
    }
    else if (param_1 < 0x10002) {
      if (param_1 == 0x10001) {
        return "DBG_EXCEPTION_HANDLED";
      }
      if (param_1 < 0x117) {
        if (param_1 == 0x116) {
          return "STATUS_CRASH_DUMP";
        }
        if (param_1 == 0x111) {
          return "STATUS_PAGE_FAULT_DEMAND_ZERO";
        }
        if (param_1 == 0x112) {
          return "STATUS_PAGE_FAULT_COPY_ON_WRITE";
        }
        if (param_1 == 0x113) {
          return "STATUS_PAGE_FAULT_GUARD_PAGE";
        }
        if (param_1 == 0x114) {
          return "STATUS_PAGE_FAULT_PAGING_FILE";
        }
        if (param_1 == 0x115) {
          return "STATUS_CACHE_PAGE_LOCKED";
        }
      }
      else {
        if (param_1 == 0x117) {
          return "STATUS_BUFFER_ALL_ZEROS";
        }
        if (param_1 == 0x118) {
          return "STATUS_REPARSE_OBJECT";
        }
        if (param_1 == 0x119) {
          return "STATUS_RESOURCE_REQUIREMENTS_CHANGED";
        }
        if (param_1 == 0x120) {
          return "STATUS_TRANSLATION_COMPLETE";
        }
        if (param_1 == 0x121) {
          return "STATUS_DS_MEMBERSHIP_EVALUATED_LOCALLY";
        }
      }
    }
    else if (param_1 < 0x40000005) {
      if (param_1 == 0x40000004) {
        return "STATUS_RXACT_STATE_CREATED";
      }
      if (param_1 == 0x10002) {
        return "DBG_CONTINUE";
      }
      if (param_1 == 0x40000000) {
        return "STATUS_OBJECT_NAME_EXISTS";
      }
      if (param_1 == 0x40000001) {
        return "STATUS_THREAD_WAS_SUSPENDED";
      }
      if (param_1 == 0x40000002) {
        return "STATUS_WORKING_SET_LIMIT_RANGE";
      }
      if (param_1 == 0x40000003) {
        return "STATUS_IMAGE_NOT_AT_BASE";
      }
    }
    else {
      if (param_1 == 0x40000005) {
        return "STATUS_SEGMENT_NOTIFICATION";
      }
      if (param_1 == 0x40000006) {
        return "STATUS_LOCAL_USER_SESSION_KEY";
      }
      if (param_1 == 0x40000007) {
        return "STATUS_BAD_CURRENT_DIRECTORY";
      }
      if (param_1 == 0x40000008) {
        return "STATUS_SERIAL_MORE_WRITES";
      }
    }
  }
  else if (param_1 < 0x40000295) {
    if (param_1 == 0x40000294) {
      return "STATUS_WAKE_SYSTEM";
    }
    switch(param_1) {
    case 0x4000000a:
      return "STATUS_FT_READ_RECOVERY_FROM_BACKUP";
    case 0x4000000b:
      return "STATUS_FT_WRITE_RECOVERY";
    case 0x4000000c:
      return "STATUS_SERIAL_COUNTER_TIMEOUT";
    case 0x4000000d:
      return "STATUS_NULL_LM_PASSWORD";
    case 0x4000000e:
      return "STATUS_IMAGE_MACHINE_TYPE_MISMATCH";
    case 0x4000000f:
      return "STATUS_RECEIVE_PARTIAL";
    case 0x40000010:
      return "STATUS_RECEIVE_EXPEDITED";
    case 0x40000011:
      return "STATUS_RECEIVE_PARTIAL_EXPEDITED";
    case 0x40000012:
      return "STATUS_EVENT_DONE";
    case 0x40000013:
      return "STATUS_EVENT_PENDING";
    case 0x40000014:
      return "STATUS_CHECKING_FILE_SYSTEM";
    case 0x40000015:
      return "STATUS_FATAL_APP_EXIT";
    case 0x40000016:
      return "STATUS_PREDEFINED_HANDLE";
    case 0x40000017:
      return "STATUS_WAS_UNLOCKED";
    case 0x40000018:
      return "STATUS_SERVICE_NOTIFICATION";
    case 0x40000019:
      return "STATUS_WAS_LOCKED";
    case 0x4000001a:
      return "STATUS_LOG_HARD_ERROR";
    case 0x4000001b:
      return "STATUS_ALREADY_WIN32";
    case 0x4000001c:
      return "STATUS_WX86_UNSIMULATE";
    case 0x4000001d:
      return "STATUS_WX86_CONTINUE";
    case 0x4000001e:
      return "STATUS_WX86_SINGLE_STEP";
    case 0x4000001f:
      return "STATUS_WX86_BREAKPOINT";
    case 0x40000020:
      return "STATUS_WX86_EXCEPTION_CONTINUE";
    case 0x40000021:
      return "STATUS_WX86_EXCEPTION_LASTCHANCE";
    case 0x40000022:
      return "STATUS_WX86_EXCEPTION_CHAIN";
    case 0x40000023:
      return "STATUS_IMAGE_MACHINE_TYPE_MISMATCH_EXE";
    case 0x40000024:
      return "STATUS_NO_YIELD_PERFORMED";
    case 0x40000025:
      return "STATUS_TIMER_RESUME_IGNORED";
    case 0x40000026:
      return "STATUS_ARBITRATION_UNHANDLED";
    case 0x40000027:
      return "STATUS_CARDBUS_NOT_SUPPORTED";
    case 0x40000028:
      return "STATUS_WX86_CREATEWX86TIB";
    case 0x40000029:
      return "STATUS_MP_PROCESSOR_MISMATCH";
    }
  }
  else if (param_1 < 0x40010008) {
    if (param_1 == 0x40010007) {
      return "DBG_RIPEXCEPTION";
    }
    if (param_1 == 0x40010001) {
      return "DBG_REPLY_LATER";
    }
    if (param_1 == 0x40010002) {
      return "DBG_UNABLE_TO_PROVIDE_HANDLE";
    }
    if (param_1 == 0x40010003) {
      return "DBG_TERMINATE_THREAD";
    }
    if (param_1 == 0x40010004) {
      return "DBG_TERMINATE_PROCESS";
    }
    if (param_1 == 0x40010005) {
      return "DBG_CONTROL_C";
    }
    if (param_1 == 0x40010006) {
      return "DBG_PRINTEXCEPTION_C";
    }
  }
  else {
    if (param_1 == 0x40010008) {
      return "DBG_CONTROL_BREAK";
    }
    if (param_1 == 0x40020056) {
      return "RPC_NT_UUID_LOCAL_ONLY";
    }
    if (param_1 == 0x400200af) {
      return "RPC_NT_SEND_INCOMPLETE";
    }
    if (param_1 == 0x400a0004) {
      return "STATUS_CTX_CDM_CONNECT";
    }
    if (param_1 == 0x400a0005) {
      return "STATUS_CTX_CDM_DISCONNECT";
    }
  }
  return "NTSTATSTR_UNKNOWN_STATUS";
}



/* ===== FUNC FUN_000245a4 @ 000245a4 ===== */

void FUN_000245a4(undefined8 *param_1,undefined8 param_2)

{
  int iVar1;
  undefined1 auStack_218 [32];
  undefined8 local_1f8;
  undefined8 local_1f0;
  undefined4 local_1e8;
  undefined4 local_1e0;
  undefined4 local_1d8;
  undefined1 *local_1d0;
  undefined4 local_1c8;
  undefined4 local_1b8 [2];
  undefined8 local_1b0;
  undefined1 *local_1a8;
  undefined4 local_1a0;
  undefined8 local_198;
  undefined8 local_190;
  undefined1 local_188 [16];
  undefined1 local_178 [16];
  undefined1 local_168;
  undefined8 local_167;
  char cStack_15f;
  char cStack_15e;
  char cStack_15d;
  char cStack_15c;
  char cStack_15b;
  char cStack_15a;
  char cStack_159;
  char local_158 [8];
  char local_150;
  ulonglong local_18;
  
  local_18 = DAT_00037100 ^ (ulonglong)auStack_218;
  local_168 = 0;
  FUN_000251f0(&local_167,0,0x148);
  RtlInitUnicodeString(local_188,L"\\Device\\Tcp");
  local_1b0 = 0;
  local_198 = 0;
  local_190 = 0;
  local_1c8 = 0x149;
  local_1a8 = local_188;
  local_167._7_1_ = s_ConnectionContext_000342d0[0];
  cStack_15f = s_ConnectionContext_000342d0[1];
  cStack_15e = s_ConnectionContext_000342d0[2];
  cStack_15d = s_ConnectionContext_000342d0[3];
  cStack_15c = s_ConnectionContext_000342d0[4];
  cStack_15b = s_ConnectionContext_000342d0[5];
  cStack_15a = s_ConnectionContext_000342d0[6];
  cStack_159 = s_ConnectionContext_000342d0[7];
  local_1b8[0] = 0x30;
  local_158[0] = s_ConnectionContext_000342d0[8];
  local_158[1] = s_ConnectionContext_000342d0[9];
  local_158[2] = s_ConnectionContext_000342d0[10];
  local_158[3] = s_ConnectionContext_000342d0[0xb];
  local_158[4] = s_ConnectionContext_000342d0[0xc];
  local_158[5] = s_ConnectionContext_000342d0[0xd];
  local_158[6] = s_ConnectionContext_000342d0[0xe];
  local_158[7] = s_ConnectionContext_000342d0[0xf];
  local_1a0 = 0x240;
  local_150 = s_ConnectionContext_000342d0[0x10];
  local_1d0 = &local_168;
  local_1d8 = 0;
  local_1e0 = 3;
  local_1e8 = 0;
  local_1f0 = CONCAT44(local_1f0._4_4_,0x80);
  local_1f8 = 0;
  local_167._4_1_ = 0x11;
  local_167._5_2_ = 8;
  iVar1 = ZwCreateFile(param_1,0x18,local_1b8,local_178);
  if (-1 < iVar1) {
    local_1f0 = 0;
    local_1f8 = param_2;
    iVar1 = ObReferenceObjectByHandle(*param_1,0xc0000000,0,0);
    if (iVar1 < 0) {
      ZwClose(*param_1);
    }
  }
  FUN_00025050(local_18 ^ (ulonglong)auStack_218);
  return;
}



/* ===== FUNC FUN_00024720 @ 00024720 ===== */

undefined8 FUN_00024720(undefined8 param_1,undefined8 param_2,longlong param_3)

{
  longlong lVar1;
  
  lVar1 = *(longlong *)(param_3 + 0x18);
  *(undefined1 *)(param_3 + 0x10) = 0;
  KeClearEvent(param_3 + 0x20);
  ExInterlockedPopEntryList(lVar1 + 0xe8,lVar1 + 0xd8);
  ExInterlockedPushEntryList(lVar1 + 0xe0,param_3,lVar1 + 0xd8);
  return 0;
}



/* ===== FUNC FUN_00024788 @ 00024788 ===== */

/* WARNING: Removing unreachable block (ram,0x000248e6) */

int FUN_00024788(undefined8 param_1,longlong param_2,undefined8 param_3,int param_4,
                longlong *param_5,undefined4 *param_6,longlong param_7)

{
  longlong lVar1;
  longlong lVar2;
  int iVar3;
  undefined8 uVar4;
  longlong lVar5;
  longlong lVar6;
  
  iVar3 = -0x3fffff66;
  lVar1 = *param_5;
  if (param_4 == 0) {
    iVar3 = 0;
  }
  else {
    if (param_2 == 0) {
      iVar3 = 0;
      FUN_000121dc();
    }
    else {
      uVar4 = IoGetRelatedDeviceObject(param_2);
      *param_6 = 0;
      lVar5 = IoAllocateMdl(param_3,param_4,0,0,0);
      if (((lVar5 != 0) && (MmProbeAndLockPages(lVar5,0,2), lVar5 != 0)) &&
         (lVar6 = IoBuildDeviceIoControlRequest(3,uVar4,0,0,0,0,1,param_7 + 0x20,param_7 + 0x38),
         lVar6 != 0)) {
        lVar2 = *(longlong *)(lVar6 + 0xb8);
        *(code **)(lVar2 + -0x10) = FUN_00024720;
        *(longlong *)(lVar2 + -8) = param_7;
        *(undefined1 *)(lVar2 + -0x45) = 0xe0;
        lVar2 = *(longlong *)(lVar6 + 0xb8);
        *(undefined1 *)(lVar2 + -0x48) = 0xf;
        *(undefined1 *)(lVar2 + -0x47) = 7;
        *(undefined8 *)(lVar2 + -0x20) = uVar4;
        *(longlong *)(lVar2 + -0x18) = param_2;
        *(undefined4 *)(lVar2 + -0x3c) = 0x1a0;
        *(int *)(lVar2 + -0x40) = param_4;
        *(longlong *)(lVar6 + 8) = lVar5;
        iVar3 = IofCallDriver();
        LOCK();
        *(undefined4 *)((ulonglong)*(byte *)(param_5 + 1) * 0x268 + 0x1018 + lVar1) = 0;
        UNLOCK();
        if (iVar3 == 0x103) {
          iVar3 = 0;
        }
      }
    }
    if (iVar3 != 0) {
      FUN_00021370(iVar3);
      FUN_000121dc();
    }
  }
  return iVar3;
}



/* ===== FUNC FUN_00024990 @ 00024990 ===== */

/* WARNING: Removing unreachable block (ram,0x00024ae2) */
/* WARNING: Removing unreachable block (ram,0x00024ad1) */
/* WARNING: Removing unreachable block (ram,0x00024ae7) */

int FUN_00024990(undefined8 param_1,longlong param_2,undefined8 param_3,undefined8 param_4,
                undefined4 param_5,int *param_6)

{
  longlong lVar1;
  int iVar2;
  longlong lVar3;
  longlong lVar4;
  longlong lVar5;
  int local_50 [4];
  undefined1 local_40 [24];
  
  iVar2 = -0x3fffff66;
  local_50[0] = 0;
  local_50[1] = 0;
  local_50[2] = 0;
  local_50[3] = 0;
  FUN_000121dc();
  if (param_2 == 0) {
    FUN_000121dc();
    iVar2 = -0x3ffffdf4;
  }
  else {
    KeInitializeEvent(local_40,0,0);
    lVar3 = IoGetRelatedDeviceObject(param_2);
    if (lVar3 == 0) {
      return -0x3ffffff3;
    }
    *param_6 = 0;
    lVar4 = IoAllocateMdl(param_4,param_5,0,0,0);
    if (((lVar4 != 0) && (MmProbeAndLockPages(lVar4,0,2), lVar4 != 0)) &&
       (lVar5 = IoBuildDeviceIoControlRequest(3,lVar3,0,0,0,0,1,local_40,local_50), lVar5 != 0)) {
      lVar1 = *(longlong *)(lVar5 + 0xb8);
      *(undefined8 *)(lVar1 + -0x10) = 0;
      *(undefined8 *)(lVar1 + -8) = 0;
      *(undefined1 *)(lVar1 + -0x45) = 0;
      lVar1 = *(longlong *)(lVar5 + 0xb8);
      *(undefined1 *)(lVar1 + -0x48) = 0xf;
      *(undefined1 *)(lVar1 + -0x47) = 8;
      *(longlong *)(lVar1 + -0x20) = lVar3;
      *(longlong *)(lVar1 + -0x18) = param_2;
      *(undefined4 *)(lVar1 + -0x3c) = 0x20;
      *(undefined4 *)(lVar1 + -0x40) = param_5;
      *(longlong *)(lVar5 + 8) = lVar4;
      iVar2 = IofCallDriver(lVar3);
      if (iVar2 == 0x103) {
        KeWaitForSingleObject(local_40,0,0,0,0);
      }
      *param_6 = local_50[2];
      iVar2 = local_50[0];
      if (((local_50[0] == 0) || (local_50[0] == -0x3fffff4b)) && (local_50[2] == 0)) {
        FUN_000121dc();
        iVar2 = -0x3ffffdf4;
      }
    }
  }
  return iVar2;
}



/* ===== FUNC FUN_00024c10 @ 00024c10 ===== */

undefined8 FUN_00024c10(longlong *param_1)

{
  undefined8 *puVar1;
  char *pcVar2;
  char *pcVar3;
  undefined8 *puVar4;
  longlong lVar5;
  int iVar6;
  
  puVar1 = *(undefined8 **)(*param_1 + 0x40);
  pcVar2 = FUN_000157f4(*(int *)((longlong)puVar1 + 0x1c));
  pcVar3 = FUN_00015780(*(int *)(puVar1 + 3));
  iVar6 = 2;
  FUN_000121dc();
  *(undefined1 *)((ulonglong)*(byte *)(param_1 + 1) * 0x268 + 0x1014 + (longlong)puVar1) = 0;
  *(undefined1 *)((ulonglong)*(byte *)(param_1 + 1) * 0x268 + 0x101c + (longlong)puVar1) = 0;
  puVar4 = (undefined8 *)ExAllocatePoolWithTag(0,iVar6 + 0xe,0x38747345);
  if (puVar4 != (undefined8 *)0x0) {
    lVar5 = IoAllocateWorkItem(*puVar1);
    puVar4[1] = lVar5;
    if (lVar5 != 0) {
      *puVar4 = param_1;
      IoQueueWorkItem(lVar5,FUN_00024ea8,1,puVar4,pcVar3,pcVar2);
      return 0;
    }
  }
  if (puVar4[1] != 0) {
    IoFreeWorkItem();
  }
  ExFreePoolWithTag(puVar4,0x38747345);
  return 0;
}



/* ===== FUNC FUN_00024d00 @ 00024d00 ===== */

undefined4 FUN_00024d00(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  longlong lVar3;
  longlong lVar4;
  undefined4 uVar5;
  undefined8 in_stack_00000030;
  undefined4 *in_stack_00000038;
  undefined4 local_48;
  undefined4 local_44;
  undefined8 local_40;
  undefined1 local_38 [32];
  
  uVar5 = 0;
  local_48 = 0;
  local_44 = 0;
  local_40 = 0;
  FUN_000121dc();
  KeInitializeEvent(local_38,0,0);
  uVar2 = IoGetRelatedDeviceObject(param_2);
  lVar3 = IoAllocateMdl(in_stack_00000030,*in_stack_00000038,0,0,0);
  if (lVar3 != 0) {
    MmProbeAndLockPages(lVar3,0,2);
    if (lVar3 != 0) {
      lVar4 = IoBuildDeviceIoControlRequest(3,uVar2,0,0,0,0,1,local_38,&local_48);
      if (lVar4 != 0) {
        *(longlong *)(lVar4 + 8) = lVar3;
        lVar3 = *(longlong *)(lVar4 + 0xb8);
        *(undefined8 *)(lVar3 + -0x10) = 0;
        *(undefined8 *)(lVar3 + -8) = 0;
        *(undefined1 *)(lVar3 + -0x45) = 0;
        lVar3 = *(longlong *)(lVar4 + 0xb8);
        *(undefined1 *)(lVar3 + -0x48) = 0xf;
        *(undefined1 *)(lVar3 + -0x47) = 0xc;
        *(undefined8 *)(lVar3 + -0x20) = uVar2;
        *(undefined8 *)(lVar3 + -0x18) = param_2;
        *(undefined4 *)(lVar3 + -0x40) = 3;
        *(undefined8 *)(lVar3 + -0x38) = 0;
        iVar1 = IofCallDriver(uVar2);
        if (iVar1 == 0x103) {
          KeWaitForSingleObject(local_38,0,0,0,0);
        }
        *in_stack_00000038 = (undefined4)local_40;
        uVar5 = local_48;
      }
    }
  }
  return uVar5;
}



/* ===== FUNC FUN_00024ea8 @ 00024ea8 ===== */

void FUN_00024ea8(longlong param_1,longlong *param_2)

{
  undefined1 uVar1;
  longlong lVar2;
  longlong lVar3;
  byte bVar4;
  undefined8 *puVar5;
  undefined8 *puVar6;
  
  lVar2 = *(longlong *)(param_1 + 0x40);
  FUN_000121dc();
  FUN_00014bec(param_1,*param_2);
  FUN_000145ec(param_1,'\0',*(undefined1 *)(*param_2 + 8),0xff);
  puVar6 = (undefined8 *)(lVar2 + 0xa0);
  for (puVar5 = (undefined8 *)*puVar6; puVar5 != puVar6; puVar5 = (undefined8 *)*puVar5) {
    FUN_000121dc();
    if (*(char *)(*param_2 + 8) == *(char *)((longlong)puVar5 + -0x34)) {
      FUN_000121dc();
      *(undefined1 *)((longlong)puVar5 + 0x15) = 0;
      bVar4 = 0;
      goto LAB_00024f5d;
    }
  }
  goto LAB_00024fea;
  while( true ) {
    FUN_000120dc(100);
    bVar4 = bVar4 + 1;
    if (0x16 < bVar4) break;
LAB_00024f5d:
    lVar3 = IoCsqRemoveIrp(lVar2 + 0x218,lVar2 + 0x3a0);
    if (lVar3 != 0) {
      lVar2 = *(longlong *)(lVar3 + 0x18);
      *(undefined4 *)(lVar2 + 4) = 0x24544e55;
      *(undefined2 *)(lVar2 + 2) = 0x200;
      uVar1 = *(undefined1 *)(*param_2 + 8);
      *(undefined4 *)(lVar2 + 9) = 0xc000020c;
      *(undefined1 *)(lVar2 + 8) = uVar1;
      *(undefined4 *)(lVar3 + 0x30) = 0;
      *(undefined8 *)(lVar3 + 0x38) = 0x40d;
      FUN_000121dc();
      FUN_000120dc(2000);
      IofCompleteRequest(lVar3,0);
      break;
    }
  }
LAB_00024fea:
  if (param_2[1] != 0) {
    IoFreeWorkItem();
  }
  ExFreePoolWithTag(param_2,0x38747345);
  FUN_000121dc();
  return;
}



/* ===== FUNC FUN_0002503c @ 0002503c ===== */

undefined8 FUN_0002503c(void)

{
  return 0;
}



/* ===== FUNC FUN_00025050 @ 00025050 ===== */

void FUN_00025050(longlong param_1)

{
  if ((param_1 == DAT_00037100) && ((short)((ulonglong)param_1 >> 0x30) == 0)) {
    return;
  }
  FUN_00025078(param_1);
  return;
}



/* ===== FUNC FUN_00025078 @ 00025078 ===== */

void FUN_00025078(undefined8 param_1)

{
                    /* WARNING: Subroutine does not return */
  KeBugCheckEx(0xf7,param_1,DAT_00037100,DAT_00037108,0);
}



/* ===== FUNC DbgPrint @ 000250a6 ===== */

void DbgPrint(void)

{
                    /* WARNING: Could not recover jumptable at 0x000250a6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  DbgPrint();
  return;
}



/* ===== FUNC WmiSystemControl @ 000250b2 ===== */

void WmiSystemControl(void)

{
                    /* WARNING: Could not recover jumptable at 0x000250b2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  WmiSystemControl();
  return;
}



/* ===== FUNC WmiCompleteRequest @ 000250be ===== */

void WmiCompleteRequest(void)

{
                    /* WARNING: Could not recover jumptable at 0x000250be. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  WmiCompleteRequest();
  return;
}



/* ===== FUNC FUN_000250cc @ 000250cc ===== */

undefined8 FUN_000250cc(short *param_1,short *param_2)

{
  short sVar1;
  ulonglong uVar2;
  short *psVar3;
  
  if (param_2 == (short *)0x0) {
    *param_1 = 0;
    param_1[1] = 0;
    param_1[4] = 0;
    param_1[5] = 0;
    param_1[6] = 0;
    param_1[7] = 0;
  }
  else {
    uVar2 = 0xffffffffffffffff;
    psVar3 = param_2;
    do {
      if (uVar2 == 0) break;
      uVar2 = uVar2 - 1;
      sVar1 = *psVar3;
      psVar3 = psVar3 + 1;
    } while (sVar1 != 0);
    if (0x7ffe < ~uVar2 - 1) {
      return 0xc0000106;
    }
    sVar1 = (short)(~uVar2 - 1) * 2;
    *(short **)(param_1 + 4) = param_2;
    *param_1 = sVar1;
    param_1[1] = sVar1 + 2;
  }
  return 0;
}



/* ===== FUNC _snwprintf @ 0002512c ===== */

int __cdecl _snwprintf(wchar_t *_Dest,size_t _Count,wchar_t *_Format,...)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x0002512c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = _snwprintf(_Dest,_Count,_Format);
  return iVar1;
}



/* ===== FUNC __GSHandlerCheckCommon @ 00025138 ===== */

/* Library Function - Single Match
    __GSHandlerCheckCommon
   
   Libraries: Visual Studio 2008 Release, Visual Studio 2010 Release, Visual Studio 2012 Release,
   Visual Studio 2019 Release */

void __GSHandlerCheckCommon(ulonglong param_1,longlong param_2,uint *param_3)

{
  longlong lVar1;
  ulonglong uVar2;
  
  uVar2 = param_1;
  if ((*param_3 & 4) != 0) {
    uVar2 = (longlong)(int)param_3[1] + param_1 & (longlong)(int)-param_3[2];
  }
  lVar1 = (ulonglong)*(uint *)(*(longlong *)(param_2 + 0x10) + 8) + *(longlong *)(param_2 + 8);
  if ((*(byte *)(lVar1 + 3) & 0xf) != 0) {
    param_1 = param_1 + (longlong)(int)(*(byte *)(lVar1 + 3) & 0xfffffff0);
  }
  FUN_00025050(param_1 ^ *(ulonglong *)((longlong)(int)(*param_3 & 0xfffffff8) + uVar2));
  return;
}



/* ===== FUNC __GSHandlerCheck @ 000251a4 ===== */

/* Library Function - Single Match
    __GSHandlerCheck
   
   Libraries: Visual Studio 2008 Release, Visual Studio 2010 Release, Visual Studio 2012 Release,
   Visual Studio 2019 Release */

undefined8
__GSHandlerCheck(undefined8 param_1,ulonglong param_2,undefined8 param_3,longlong param_4)

{
  __GSHandlerCheckCommon(param_2,param_4,*(uint **)(param_4 + 0x38));
  return 1;
}



/* ===== FUNC wcschr @ 000251c8 ===== */

wchar_t * __cdecl wcschr(wchar_t *_Str,wchar_t _Ch)

{
  wchar_t *pwVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000251c8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pwVar1 = wcschr(_Str,_Ch);
  return pwVar1;
}



/* ===== FUNC _wcsnicmp @ 000251d4 ===== */

int __cdecl _wcsnicmp(wchar_t *_Str1,wchar_t *_Str2,size_t _MaxCount)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000251d4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = _wcsnicmp(_Str1,_Str2,_MaxCount);
  return iVar1;
}



/* ===== FUNC FUN_000251f0 @ 000251f0 ===== */

void FUN_000251f0(ulonglong *param_1,ulonglong param_2,ulonglong param_3)

{
  uint uVar1;
  ulonglong *puVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  
  uVar3 = param_3;
  if (7 < param_3) {
    param_2 = (param_2 & 0xff) * 0x101010101010101;
    if (0x3f < param_3) {
      uVar1 = -(int)param_1 & 7;
      if (uVar1 != 0) {
        uVar3 = param_3 - uVar1;
        *param_1 = param_2;
      }
      param_1 = (ulonglong *)((ulonglong)uVar1 + (longlong)param_1);
      param_3 = uVar3 & 0x3f;
      uVar3 = uVar3 >> 6;
      if (uVar3 != 0) {
        puVar2 = param_1;
        if (uVar3 < 0x1c00) {
          do {
            *puVar2 = param_2;
            puVar2[1] = param_2;
            puVar2[2] = param_2;
            param_1 = puVar2 + 8;
            puVar2[3] = param_2;
            puVar2[4] = param_2;
            uVar3 = uVar3 - 1;
            puVar2[5] = param_2;
            puVar2[6] = param_2;
            puVar2[7] = param_2;
            puVar2 = param_1;
          } while (uVar3 != 0);
        }
        else {
          do {
            *puVar2 = param_2;
            puVar2[1] = param_2;
            puVar2[2] = param_2;
            param_1 = puVar2 + 8;
            puVar2[3] = param_2;
            puVar2[4] = param_2;
            uVar3 = uVar3 - 1;
            puVar2[5] = param_2;
            puVar2[6] = param_2;
            puVar2[7] = param_2;
            puVar2 = param_1;
          } while (uVar3 != 0);
          LOCK();
          UNLOCK();
        }
      }
    }
    uVar3 = param_3 & 7;
    for (uVar4 = param_3 >> 3; uVar4 != 0; uVar4 = uVar4 - 1) {
      *param_1 = param_2;
      param_1 = param_1 + 1;
    }
  }
  for (; uVar3 != 0; uVar3 = uVar3 - 1) {
    *(char *)param_1 = (char)param_2;
    param_1 = (ulonglong *)((longlong)param_1 + 1);
  }
  return;
}



/* ===== FUNC memcpy @ 000252f0 ===== */

/* Library Function - Single Match
    memcpy
   
   Libraries: Visual Studio 2005, Visual Studio 2008, Visual Studio 2010 */

void * __cdecl memcpy(void *_Dst,void *_Src,size_t _Size)

{
  undefined8 uVar1;
  int iVar2;
  undefined8 *puVar3;
  undefined8 *puVar4;
  ulonglong uVar5;
  ulonglong uVar6;
  
  uVar5 = (longlong)_Src - (longlong)_Dst;
  if (_Src < _Dst) {
    puVar4 = (undefined8 *)((longlong)_Dst + _Size);
    puVar3 = puVar4;
    if (_Size < 8) goto LAB_00025504;
    if (((ulonglong)puVar4 & 7) != 0) {
      if (((ulonglong)puVar4 & 1) != 0) {
        puVar4 = (undefined8 *)((longlong)puVar4 + -1);
        _Size = _Size - 1;
        *(undefined1 *)puVar4 = *(undefined1 *)(uVar5 + (longlong)puVar4);
      }
      if (((ulonglong)puVar4 & 2) != 0) {
        puVar4 = (undefined8 *)((longlong)puVar4 + -2);
        _Size = _Size - 2;
        *(undefined2 *)puVar4 = *(undefined2 *)(uVar5 + (longlong)puVar4);
      }
      if (((ulonglong)puVar4 & 4) != 0) {
        puVar4 = (undefined8 *)((longlong)puVar4 + -4);
        _Size = _Size - 4;
        *(undefined4 *)puVar4 = *(undefined4 *)(uVar5 + (longlong)puVar4);
      }
    }
    while (uVar6 = _Size >> 5, puVar3 = puVar4, uVar6 != 0) {
      if ((uVar6 < 0x2000) || (0xfffffffffffff000 < uVar5)) goto LAB_00025540;
      do {
        iVar2 = 0x20;
        do {
          puVar3 = puVar4;
          iVar2 = iVar2 + -1;
          puVar4 = puVar3 + -0x10;
        } while (iVar2 != 0);
        iVar2 = 0x40;
        puVar3 = puVar3 + 0x1f0;
        do {
          uVar1 = *(undefined8 *)((uVar5 - 0x10) + (longlong)puVar3);
          puVar3[-1] = *(undefined8 *)((uVar5 - 8) + (longlong)puVar3);
          puVar3[-2] = uVar1;
          uVar1 = *(undefined8 *)((uVar5 - 0x20) + (longlong)puVar3);
          puVar3[-3] = *(undefined8 *)((uVar5 - 0x18) + (longlong)puVar3);
          puVar3[-4] = uVar1;
          uVar1 = *(undefined8 *)((uVar5 - 0x30) + (longlong)puVar3);
          puVar4 = puVar3 + -8;
          puVar3[-5] = *(undefined8 *)((uVar5 - 0x28) + (longlong)puVar3);
          puVar3[-6] = uVar1;
          uVar1 = *(undefined8 *)(uVar5 + (longlong)puVar4);
          iVar2 = iVar2 + -1;
          puVar3[-7] = *(undefined8 *)(uVar5 + 8 + (longlong)puVar4);
          *puVar4 = uVar1;
          puVar3 = puVar4;
        } while (iVar2 != 0);
        _Size = _Size - 0x1000;
      } while (0xfff < _Size);
      LOCK();
      UNLOCK();
    }
    goto LAB_000254e7;
  }
  puVar4 = _Dst;
  if (_Size < 8) goto LAB_00025363;
  puVar3 = _Dst;
  if (((ulonglong)_Dst & 7) != 0) {
    if (((ulonglong)_Dst & 1) != 0) {
      _Size = _Size - 1;
      *(undefined1 *)_Dst = *(undefined1 *)(uVar5 + (longlong)_Dst);
      puVar3 = (undefined8 *)((longlong)_Dst + 1);
    }
    if (((ulonglong)puVar3 & 2) != 0) {
      _Size = _Size - 2;
      *(undefined2 *)puVar3 = *(undefined2 *)(uVar5 + (longlong)puVar3);
      puVar3 = (undefined8 *)((longlong)puVar3 + 2);
    }
    if (((ulonglong)puVar3 & 4) != 0) {
      _Size = _Size - 4;
      *(undefined4 *)puVar3 = *(undefined4 *)(uVar5 + (longlong)puVar3);
      puVar3 = (undefined8 *)((longlong)puVar3 + 4);
    }
  }
  while (uVar6 = _Size >> 5, puVar4 = puVar3, uVar6 != 0) {
    if ((uVar6 < 0x2000) || (uVar5 < 0x1000)) goto LAB_000253a0;
    do {
      iVar2 = 0x20;
      do {
        puVar4 = puVar3;
        iVar2 = iVar2 + -1;
        puVar3 = puVar4 + 0x10;
      } while (iVar2 != 0);
      iVar2 = 0x40;
      puVar4 = puVar4 + -0x1f0;
      do {
        uVar1 = *(undefined8 *)(uVar5 + 8 + (longlong)puVar4);
        *puVar4 = *(undefined8 *)(uVar5 + (longlong)puVar4);
        puVar4[1] = uVar1;
        uVar1 = *(undefined8 *)(uVar5 + 0x18 + (longlong)puVar4);
        puVar4[2] = *(undefined8 *)(uVar5 + 0x10 + (longlong)puVar4);
        puVar4[3] = uVar1;
        uVar1 = *(undefined8 *)(uVar5 + 0x28 + (longlong)puVar4);
        puVar3 = puVar4 + 8;
        puVar4[4] = *(undefined8 *)(uVar5 + 0x20 + (longlong)puVar4);
        puVar4[5] = uVar1;
        uVar1 = *(undefined8 *)((uVar5 - 8) + (longlong)puVar3);
        iVar2 = iVar2 + -1;
        puVar4[6] = *(undefined8 *)((uVar5 - 0x10) + (longlong)puVar3);
        puVar4[7] = uVar1;
        puVar4 = puVar3;
      } while (iVar2 != 0);
      _Size = _Size - 0x1000;
    } while (0xfff < _Size);
    LOCK();
    UNLOCK();
  }
  goto LAB_00025346;
LAB_00025540:
  do {
    uVar1 = *(undefined8 *)((uVar5 - 0x10) + (longlong)puVar4);
    puVar3 = puVar4 + -4;
    puVar4[-1] = *(undefined8 *)((uVar5 - 8) + (longlong)puVar4);
    puVar4[-2] = uVar1;
    uVar1 = *(undefined8 *)(uVar5 + (longlong)puVar3);
    uVar6 = uVar6 - 1;
    puVar4[-3] = *(undefined8 *)(uVar5 + 8 + (longlong)puVar3);
    *puVar3 = uVar1;
    puVar4 = puVar3;
  } while (uVar6 != 0);
  _Size = _Size & 0x1f;
LAB_000254e7:
  uVar6 = _Size >> 3;
  if (uVar6 != 0) {
    do {
      puVar3 = puVar3 + -1;
      uVar6 = uVar6 - 1;
      *puVar3 = *(undefined8 *)(uVar5 + (longlong)puVar3);
    } while (uVar6 != 0);
    _Size = _Size & 7;
  }
LAB_00025504:
  if (_Size == 0) {
    return _Dst;
  }
  do {
    puVar3 = (undefined8 *)((longlong)puVar3 + -1);
    _Size = _Size - 1;
    *(undefined1 *)puVar3 = *(undefined1 *)(uVar5 + (longlong)puVar3);
  } while (_Size != 0);
  return _Dst;
LAB_000253a0:
  do {
    uVar1 = *(undefined8 *)(uVar5 + 8 + (longlong)puVar3);
    puVar4 = puVar3 + 4;
    *puVar3 = *(undefined8 *)(uVar5 + (longlong)puVar3);
    puVar3[1] = uVar1;
    uVar1 = *(undefined8 *)((uVar5 - 8) + (longlong)puVar4);
    uVar6 = uVar6 - 1;
    puVar3[2] = *(undefined8 *)((uVar5 - 0x10) + (longlong)puVar4);
    puVar3[3] = uVar1;
    puVar3 = puVar4;
  } while (uVar6 != 0);
  _Size = _Size & 0x1f;
LAB_00025346:
  uVar6 = _Size >> 3;
  if (uVar6 != 0) {
    do {
      *puVar4 = *(undefined8 *)(uVar5 + (longlong)puVar4);
      puVar4 = puVar4 + 1;
      uVar6 = uVar6 - 1;
    } while (uVar6 != 0);
    _Size = _Size & 7;
  }
LAB_00025363:
  if (_Size == 0) {
    return _Dst;
  }
  do {
    *(undefined1 *)puVar4 = *(undefined1 *)(uVar5 + (longlong)puVar4);
    puVar4 = (undefined8 *)((longlong)puVar4 + 1);
    _Size = _Size - 1;
  } while (_Size != 0);
  return _Dst;
}



/* ===== FUNC StringVPrintfWorkerW @ 0002562c ===== */

/* Library Function - Single Match
    StringVPrintfWorkerW
   
   Library: Visual Studio 2008 Release */

HRESULT __stdcall
StringVPrintfWorkerW
          (STRSAFE_LPWSTR pszDest,size_t cchDest,size_t *pcchNewDestLength,STRSAFE_LPCWSTR pszFormat
          ,va_list argList)

{
  int iVar1;
  ulonglong uVar2;
  size_t _Count;
  HRESULT HVar3;
  
  _Count = cchDest - 1;
  HVar3 = 0;
  iVar1 = _vsnwprintf(pszDest,_Count,pszFormat,argList);
  if (-1 < iVar1) {
    uVar2 = (ulonglong)iVar1;
    if (uVar2 <= _Count) {
      if (uVar2 == _Count) {
        pszDest[_Count] = L'\0';
      }
      else {
        _Count = uVar2;
      }
      goto LAB_00025682;
    }
  }
  pszDest[_Count] = L'\0';
  HVar3 = -0x7ffffffb;
LAB_00025682:
  if (pcchNewDestLength != (size_t *)0x0) {
    *pcchNewDestLength = _Count;
  }
  return HVar3;
}



/* ===== FUNC StringLengthWorkerW @ 000256a8 ===== */

/* Library Function - Single Match
    StringLengthWorkerW
   
   Library: Visual Studio 2008 Release */

HRESULT __stdcall StringLengthWorkerW(STRSAFE_PCNZWCH psz,size_t cchMax,size_t *pcchLength)

{
  int iVar1;
  size_t sVar2;
  
  iVar1 = 0;
  sVar2 = cchMax;
  if (cchMax != 0) {
    do {
      if (*psz == L'\0') break;
      psz = psz + 1;
      sVar2 = sVar2 - 1;
    } while (sVar2 != 0);
    if (sVar2 != 0) goto LAB_000256cb;
  }
  iVar1 = -0x3ffffff3;
LAB_000256cb:
  if (pcchLength != (size_t *)0x0) {
    if (-1 < iVar1) {
      *pcchLength = cchMax - sVar2;
      return iVar1;
    }
    *pcchLength = 0;
  }
  return iVar1;
}



/* ===== FUNC StringValidateDestW @ 000256e8 ===== */

/* Library Function - Single Match
    StringValidateDestW
   
   Library: Visual Studio 2008 Release */

HRESULT __stdcall StringValidateDestW(STRSAFE_PCNZWCH pszDest,size_t cchDest,size_t cchMax)

{
  int iVar1;
  ulonglong in_R9;
  
  iVar1 = 0;
  if ((cchDest == 0) || (in_R9 < cchDest)) {
    iVar1 = -0x3ffffff3;
  }
  if (cchMax != 0) {
    if (iVar1 < 0) {
      *(undefined8 *)cchMax = 0;
    }
    else {
      iVar1 = StringLengthWorkerW(pszDest,cchDest,(size_t *)cchMax);
    }
  }
  return iVar1;
}



/* ===== FUNC FUN_0002571c @ 0002571c ===== */

ulonglong FUN_0002571c(undefined1 *param_1,ulonglong param_2,ushort *param_3,undefined8 param_4,
                      ulonglong *param_5)

{
  ulonglong uVar1;
  undefined1 *local_38;
  int local_30;
  undefined1 *local_28;
  undefined4 local_20;
  
  if ((param_3 == (ushort *)0x0) || ((param_2 != 0 && (param_1 == (undefined1 *)0x0)))) {
    FUN_0002619c();
    uVar1 = 0xffffffff;
  }
  else {
    local_20 = 0x42;
    if (param_2 < 0x40000000) {
      local_30 = (int)param_2 * 2;
    }
    else {
      local_30 = 0x7fffffff;
    }
    local_38 = param_1;
    local_28 = param_1;
    uVar1 = FUN_00025960((longlong *)&local_38,param_3,param_4,param_5);
    if (param_1 != (undefined1 *)0x0) {
      local_30 = local_30 + -1;
      if (local_30 < 0) {
        FUN_00025820(0,(longlong)&local_38);
      }
      else {
        *local_38 = 0;
        local_38 = local_38 + 1;
      }
      local_30 = local_30 + -1;
      if (local_30 < 0) {
        FUN_00025820(0,(longlong)&local_38);
      }
      else {
        *local_38 = 0;
      }
      uVar1 = uVar1 & 0xffffffff;
    }
  }
  return uVar1;
}



/* ===== FUNC _vsnwprintf @ 00025804 ===== */

/* Library Function - Single Match
    _vsnwprintf
   
   Library: Visual Studio 2008 Release */

int __cdecl _vsnwprintf(wchar_t *_Dest,size_t _Count,wchar_t *_Format,va_list _Args)

{
  ulonglong uVar1;
  
  uVar1 = FUN_0002571c((undefined1 *)_Dest,_Count,(ushort *)_Format,0,(ulonglong *)_Args);
  return (int)uVar1;
}



/* ===== FUNC FUN_00025820 @ 00025820 ===== */

undefined8 FUN_00025820(undefined8 param_1,longlong param_2)

{
  *(uint *)(param_2 + 0x18) = *(uint *)(param_2 + 0x18) | 0x20;
  return 0xffffffff;
}



/* ===== FUNC FUN_00025830 @ 00025830 ===== */

void FUN_00025830(ushort param_1,longlong *param_2,int *param_3)

{
  ulonglong uVar1;
  
  if (((*(byte *)(param_2 + 3) & 0x40) == 0) || (param_2[2] != 0)) {
    uVar1 = FUN_000261b0(param_1,param_2);
    if (((short)uVar1 == -1) && ((*(byte *)(param_2 + 3) & 0x20) != 0)) {
      *param_3 = -1;
    }
    else {
      *param_3 = *param_3 + 1;
    }
  }
  else {
    *param_3 = *param_3 + 1;
  }
  return;
}



/* ===== FUNC FUN_00025880 @ 00025880 ===== */

void FUN_00025880(ushort param_1,int param_2,longlong *param_3,int *param_4)

{
  if (0 < param_2) {
    do {
      param_2 = param_2 + -1;
      FUN_00025830(param_1,param_3,param_4);
      if (*param_4 == -1) {
        return;
      }
    } while (0 < param_2);
  }
  return;
}



/* ===== FUNC FUN_000258d8 @ 000258d8 ===== */

void FUN_000258d8(ushort *param_1,int param_2,longlong *param_3,int *param_4)

{
  if (((*(byte *)(param_3 + 3) & 0x40) == 0) || (param_3[2] != 0)) {
    while (0 < param_2) {
      param_2 = param_2 + -1;
      FUN_00025830(*param_1,param_3,param_4);
      param_1 = param_1 + 1;
      if (*param_4 == -1) {
        if (DAT_0003780c != 0x2a) {
          return;
        }
        FUN_00025830(0x3f,param_3,param_4);
      }
    }
  }
  else {
    *param_4 = *param_4 + param_2;
  }
  return;
}



/* ===== FUNC FUN_00025960 @ 00025960 ===== */

/* WARNING: Removing unreachable block (ram,0x00025cc9) */
/* WARNING: Removing unreachable block (ram,0x00025ca8) */
/* WARNING: Removing unreachable block (ram,0x00025dba) */
/* WARNING: Removing unreachable block (ram,0x00025dbe) */
/* WARNING: Removing unreachable block (ram,0x00025dc3) */

void FUN_00025960(longlong *param_1,ushort *param_2,undefined8 param_3,ulonglong *param_4)

{
  int *piVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  bool bVar5;
  bool bVar6;
  bool bVar7;
  char cVar8;
  bool bVar9;
  uint uVar10;
  int iVar11;
  ushort *puVar12;
  undefined7 extraout_var;
  longlong lVar13;
  uint uVar14;
  uint uVar15;
  ulonglong uVar16;
  char *pcVar17;
  ushort *puVar18;
  uint uVar19;
  ushort uVar20;
  ulonglong uVar21;
  longlong *plVar22;
  uint uVar23;
  ushort *puVar24;
  int iVar25;
  int iVar26;
  undefined1 auStack_4b8 [32];
  undefined8 local_498;
  int local_488;
  uint local_484;
  int local_480;
  uint local_47c;
  uint local_478;
  ushort local_474 [2];
  longlong *local_470;
  int local_468;
  char local_464 [4];
  ushort local_460 [2];
  int local_45c;
  undefined4 local_458;
  ushort *local_450;
  ushort local_448 [255];
  char local_249 [513];
  ulonglong local_48;
  
  local_48 = DAT_00037100 ^ (ulonglong)auStack_4b8;
  local_458 = 0;
  uVar19 = 0;
  bVar7 = false;
  bVar6 = false;
  bVar5 = false;
  bVar2 = false;
  bVar4 = false;
  bVar3 = false;
  uVar10 = 0;
  local_478 = 0;
  uVar15 = 0;
  local_47c = 0;
  uVar23 = 0;
  local_484 = 0;
  local_45c = 0;
  local_488 = 0;
  local_470 = param_1;
  if ((param_1 == (longlong *)0x0) || (param_2 == (ushort *)0x0)) {
    local_498 = 0;
    FUN_0002619c();
LAB_00026069:
    FUN_00025050(local_48 ^ (ulonglong)auStack_4b8);
    return;
  }
  uVar20 = *param_2;
  iVar25 = 0;
  local_480 = 0;
  uVar21 = 0;
  if (uVar20 == 0) goto LAB_00026069;
  puVar18 = local_450;
  iVar11 = 0;
LAB_000259ff:
  uVar16 = 0xffffffffffffffff;
  puVar24 = param_2 + 1;
  local_450 = puVar24;
  if (iVar25 < 0) goto LAB_00026069;
  if ((ushort)(uVar20 - 0x20) < 0x59) {
    uVar14 = (byte)"Invalid parameter passed to C runtime function.\n"[(ulonglong)uVar20 + 0x18] &
             0xf;
  }
  else {
    uVar14 = 0;
  }
  local_468 = (int)(char)(&DAT_000359f0)[(longlong)iVar11 + (longlong)(int)uVar14 * 8] >> 4;
  if (local_468 == 0) {
LAB_00026023:
    local_488 = 1;
    FUN_00025830(uVar20,param_1,&local_480);
LAB_00026040:
    iVar25 = local_480;
    uVar23 = local_484;
LAB_00026045:
    param_1 = local_470;
    param_2 = puVar24;
    uVar15 = local_47c;
    uVar10 = local_478;
LAB_00026058:
    uVar20 = *param_2;
    iVar11 = local_468;
    if (uVar20 == 0) goto LAB_00026069;
    goto LAB_000259ff;
  }
  if (local_468 == 1) {
    local_45c = 0;
    uVar10 = 0;
    uVar23 = 0;
    uVar19 = 0;
    bVar7 = false;
    bVar6 = false;
    bVar5 = false;
    bVar2 = false;
    bVar4 = false;
    bVar3 = false;
    local_478 = 0;
    local_484 = 0;
    local_47c = 0xffffffff;
    local_488 = 0;
    param_2 = puVar24;
    uVar15 = 0xffffffff;
    goto LAB_00026058;
  }
  if (local_468 == 2) {
    if (uVar20 == 0x20) {
      bVar7 = true;
      param_2 = puVar24;
    }
    else if (uVar20 == 0x23) {
      param_2 = puVar24;
    }
    else if (uVar20 == 0x2b) {
      bVar5 = true;
      param_2 = puVar24;
    }
    else if (uVar20 == 0x2d) {
      uVar19 = uVar19 | 4;
      param_2 = puVar24;
    }
    else {
      param_2 = puVar24;
      if (uVar20 == 0x30) {
        uVar19 = uVar19 | 8;
      }
    }
    goto LAB_00026058;
  }
  if (local_468 == 3) {
    if (uVar20 == 0x2a) {
      uVar10 = (uint)*param_4;
      param_4 = param_4 + 1;
      param_2 = puVar24;
      local_478 = uVar10;
      if (-1 < (int)uVar10) goto LAB_00026058;
      uVar19 = uVar19 | 4;
      uVar10 = -uVar10;
    }
    else {
      uVar10 = (uVar20 - 0x30) + uVar10 * 10;
    }
    param_2 = puVar24;
    local_478 = uVar10;
    goto LAB_00026058;
  }
  if (local_468 == 4) {
    local_47c = 0;
LAB_000260c5:
    param_2 = puVar24;
    uVar15 = local_47c;
    goto LAB_00026058;
  }
  if (local_468 == 5) {
    if (uVar20 != 0x2a) {
      local_47c = (uVar20 - 0x30) + uVar15 * 10;
      goto LAB_000260c5;
    }
    local_47c = (uint)*param_4;
    param_4 = param_4 + 1;
    param_2 = puVar24;
    uVar15 = local_47c;
    if ((int)local_47c < 0) {
      local_47c = 0xffffffff;
      uVar15 = 0xffffffff;
    }
    goto LAB_00026058;
  }
  if (local_468 == 6) {
    if (uVar20 == 0x49) {
      bVar3 = true;
      if ((*puVar24 == 0x36) && (param_2[2] == 0x34)) {
        bVar3 = true;
        param_2 = param_2 + 3;
      }
      else if ((*puVar24 == 0x33) && (param_2[2] == 0x32)) {
        bVar3 = false;
        param_2 = param_2 + 3;
      }
      else {
        param_2 = puVar24;
        if (((((*puVar24 != 100) && (*puVar24 != 0x69)) && (*puVar24 != 0x6f)) &&
            ((*puVar24 != 0x75 && (*puVar24 != 0x78)))) && (*puVar24 != 0x58)) {
          local_468 = 0;
          goto LAB_00026023;
        }
      }
    }
    else if (uVar20 == 0x68) {
      uVar19 = uVar19 | 0x20;
      param_2 = puVar24;
    }
    else if (uVar20 == 0x6c) {
      if (*puVar24 == 0x6c) {
        bVar4 = true;
        param_2 = param_2 + 2;
      }
      else {
        uVar19 = uVar19 | 0x10;
        param_2 = puVar24;
      }
    }
    else {
      param_2 = puVar24;
      if (uVar20 == 0x77) {
        uVar19 = uVar19 | 0x800;
      }
    }
    goto LAB_00026058;
  }
  param_2 = puVar24;
  if (local_468 != 7) goto LAB_00026058;
  if (uVar20 < 0x6a) {
    if (uVar20 == 0x69) {
LAB_00025ad2:
      bVar6 = true;
LAB_00025ad5:
      iVar11 = 10;
      goto LAB_00025ccd;
    }
    if (uVar20 == 0x43) {
      if ((uVar19 & 0x830) == 0) {
        uVar19 = uVar19 | 0x20;
      }
LAB_00025bc0:
      uVar21 = *param_4;
      local_460[0] = (ushort)uVar21;
      param_4 = param_4 + 1;
      local_488 = 1;
      if ((uVar19 & 0x20) == 0) {
        local_448[0] = local_460[0];
      }
      else {
        local_464[0] = (char)uVar21;
        local_464[1] = 0;
        lVar13 = FUN_0002621c(local_448,local_464,(longlong)DAT_000372f8);
        uVar23 = local_484;
        if ((int)lVar13 < 0) {
          local_45c = 1;
        }
      }
      puVar18 = local_448;
      uVar21 = 1;
      iVar11 = 1;
      goto LAB_00025e04;
    }
    if (uVar20 == 0x53) {
      if ((uVar19 & 0x830) == 0) {
        uVar19 = uVar19 | 0x20;
      }
LAB_00025b62:
      puVar18 = (ushort *)*param_4;
      if (uVar15 == 0xffffffff) {
        uVar15 = 0x7fffffff;
      }
      param_4 = param_4 + 1;
      if ((uVar19 & 0x20) != 0) {
        if (puVar18 == (ushort *)0x0) {
          puVar18 = (ushort *)PTR_DAT_000372e0;
        }
        uVar21 = 0;
        puVar12 = puVar18;
        if (0 < (int)uVar15) {
          do {
            if ((char)*puVar12 == '\0') break;
            uVar10 = (int)uVar21 + 1;
            uVar21 = (ulonglong)uVar10;
            puVar12 = (ushort *)((longlong)puVar12 + 1);
          } while ((int)uVar10 < (int)uVar15);
        }
        goto LAB_00025e00;
      }
      iVar11 = 1;
      if (puVar18 == (ushort *)0x0) {
        puVar18 = (ushort *)PTR_u__null__000372e8;
      }
      local_488 = 1;
      for (puVar12 = puVar18; (uVar15 != 0 && (uVar15 = uVar15 - 1, *puVar12 != 0));
          puVar12 = puVar12 + 1) {
      }
      uVar21 = (longlong)puVar12 - (longlong)puVar18 >> 1 & 0xffffffff;
      goto LAB_00025e04;
    }
    if (uVar20 == 0x58) goto LAB_00025c94;
    if (uVar20 == 0x5a) {
      puVar12 = (ushort *)*param_4;
      param_4 = param_4 + 1;
      if ((puVar12 == (ushort *)0x0) ||
         (puVar18 = *(ushort **)(puVar12 + 4), puVar18 == (ushort *)0x0)) {
        pcVar17 = PTR_DAT_000372e0;
        do {
          if (uVar16 == 0) break;
          uVar16 = uVar16 - 1;
          cVar8 = *pcVar17;
          pcVar17 = pcVar17 + 1;
        } while (cVar8 != '\0');
        uVar21 = ~uVar16 - 1;
        puVar18 = (ushort *)PTR_DAT_000372e0;
        goto LAB_00025e00;
      }
      uVar20 = *puVar12;
      if (uVar20 <= puVar12[1]) {
        if (uVar19 >> 0xb == 0) {
          local_488 = 0;
        }
        else {
          if (((~uVar20 & 1) == 0) || ((~(uint)puVar18 & 1) == 0)) goto LAB_00026177;
          uVar20 = uVar20 >> 1;
          local_488 = 1;
        }
        uVar21 = (ulonglong)uVar20;
        iVar11 = local_488;
        goto LAB_00025e04;
      }
LAB_00026177:
      local_498 = 0;
      FUN_0002619c();
      goto LAB_00026069;
    }
    if (uVar20 == 99) goto LAB_00025bc0;
    if (uVar20 == 100) goto LAB_00025ad2;
  }
  else {
    if (uVar20 == 0x6e) {
      piVar1 = (int *)*param_4;
      param_4 = param_4 + 1;
      bVar9 = FUN_000261fc();
      if ((int)CONCAT71(extraout_var,bVar9) == 0) goto LAB_00026177;
      if ((uVar19 & 0x20) == 0) {
        *piVar1 = iVar25;
      }
      else {
        *(short *)piVar1 = (short)iVar25;
      }
      local_45c = 1;
      uVar23 = local_484;
      goto LAB_00025e00;
    }
    if (uVar20 == 0x6f) {
      iVar11 = 8;
    }
    else {
      if (uVar20 == 0x70) {
        uVar15 = 0x10;
        bVar3 = true;
LAB_00025c94:
        local_458 = 7;
      }
      else {
        if (uVar20 == 0x73) goto LAB_00025b62;
        if (uVar20 == 0x75) goto LAB_00025ad5;
        if (uVar20 != 0x78) goto LAB_00025e00;
        local_458 = 0x27;
      }
      iVar11 = 0x10;
    }
LAB_00025ccd:
    if ((bVar3) || (bVar4)) {
      uVar21 = *param_4;
    }
    else if ((uVar19 & 0x20) == 0) {
      if (bVar6) {
        uVar21 = (ulonglong)(int)(uint)*param_4;
      }
      else {
        uVar21 = (ulonglong)(uint)*param_4;
      }
    }
    else if (bVar6) {
      uVar21 = (ulonglong)(short)(ushort)*param_4;
    }
    else {
      uVar21 = (ulonglong)(ushort)*param_4;
    }
    param_4 = param_4 + 1;
    if ((bVar6) && ((longlong)uVar21 < 0)) {
      uVar21 = -uVar21;
      bVar2 = true;
    }
    if ((!bVar3) && (!bVar4)) {
      uVar21 = uVar21 & 0xffffffff;
    }
    if ((int)uVar15 < 0) {
      uVar15 = 1;
    }
    else {
      uVar19 = uVar19 & 0xfffffff7;
      if (0x200 < (int)uVar15) {
        uVar15 = 0x200;
      }
    }
    pcVar17 = local_249;
    local_484 = -(uint)(uVar21 != 0) & uVar23;
    while ((local_47c = uVar15 - 1, 0 < (int)uVar15 || (uVar21 != 0))) {
      uVar10 = (int)(uVar21 % (ulonglong)(longlong)iVar11) + 0x30;
      cVar8 = (char)uVar10;
      if (0x39 < uVar10) {
        cVar8 = cVar8 + (char)local_458;
      }
      *pcVar17 = cVar8;
      pcVar17 = pcVar17 + -1;
      uVar21 = uVar21 / (ulonglong)(longlong)iVar11;
      uVar15 = local_47c;
    }
    uVar21 = (ulonglong)(uint)((int)local_249 - (int)pcVar17);
    puVar18 = (ushort *)(pcVar17 + 1);
    uVar23 = local_484;
  }
LAB_00025e00:
  iVar11 = local_488;
LAB_00025e04:
  if (local_45c == 0) {
    if (bVar6) {
      if (bVar2) {
        local_474[0] = 0x2d;
      }
      else if (bVar5) {
        local_474[0] = 0x2b;
      }
      else {
        if (!bVar7) goto LAB_00025e52;
        local_474[0] = 0x20;
      }
      local_484 = 1;
    }
LAB_00025e52:
    uVar10 = local_484;
    iVar26 = (int)uVar21;
    iVar25 = (local_478 - iVar26) - local_484;
    if ((uVar19 & 0xc) == 0) {
      FUN_00025880(0x20,iVar25,local_470,&local_480);
    }
    FUN_000258d8(local_474,uVar10,local_470,&local_480);
    if (((uVar19 & 8) != 0) && ((uVar19 & 4) == 0)) {
      FUN_00025880(0x30,iVar25,local_470,&local_480);
    }
    plVar22 = local_470;
    if ((iVar11 == 0) && (0 < iVar26)) {
      uVar16 = uVar21 & 0xffffffff;
      puVar24 = puVar18;
      do {
        uVar10 = (int)uVar16 - 1;
        lVar13 = FUN_0002621c(local_460,(char *)puVar24,(longlong)DAT_000372f8);
        iVar11 = (int)lVar13;
        if (iVar11 == 2) {
          uVar10 = (int)uVar16 - 2;
        }
        uVar16 = (ulonglong)uVar10;
        if (iVar11 < 1) {
          local_480 = -1;
          plVar22 = local_470;
          goto LAB_00025f3c;
        }
        FUN_00025830(local_460[0],local_470,&local_480);
        puVar24 = (ushort *)((longlong)puVar24 + (longlong)iVar11);
      } while (0 < (int)uVar10);
      plVar22 = local_470;
    }
    else {
      FUN_000258d8(puVar18,iVar26,local_470,&local_480);
    }
LAB_00025f3c:
    if ((-1 < local_480) && ((uVar19 & 4) != 0)) {
      FUN_00025880(0x20,iVar25,plVar22,&local_480);
    }
    puVar24 = local_450;
    goto LAB_00026040;
  }
  goto LAB_00026045;
}



/* ===== FUNC FUN_0002619c @ 0002619c ===== */

void FUN_0002619c(void)

{
  DbgPrint("Invalid parameter passed to C runtime function.\n");
  return;
}



/* ===== FUNC FUN_000261b0 @ 000261b0 ===== */

ulonglong FUN_000261b0(ushort param_1,longlong *param_2)

{
  longlong *plVar1;
  ushort *puVar2;
  undefined8 uVar3;
  ulonglong uVar4;
  
  if (param_2 == (longlong *)0x0) {
    uVar3 = FUN_0002619c();
    uVar4 = CONCAT62((int6)((ulonglong)uVar3 >> 0x10),0xffff);
  }
  else {
    plVar1 = param_2 + 1;
    *(int *)plVar1 = (int)*plVar1 + -2;
    if ((int)*plVar1 < 0) {
      uVar4 = FUN_00026274((ulonglong)param_1,(longlong)param_2);
    }
    else {
      puVar2 = (ushort *)*param_2;
      *puVar2 = param_1;
      *param_2 = *param_2 + 2;
      uVar4 = CONCAT62((int6)((ulonglong)puVar2 >> 0x10),param_1);
    }
  }
  return uVar4;
}



/* ===== FUNC FUN_000261fc @ 000261fc ===== */

bool FUN_000261fc(void)

{
  return DAT_00037800 == (DAT_00037100 | 1);
}



/* ===== FUNC FUN_0002621c @ 0002621c ===== */

longlong FUN_0002621c(undefined2 *param_1,char *param_2,longlong param_3)

{
  undefined2 uVar1;
  char *local_res10 [3];
  
  if ((param_2 != (char *)0x0) && (param_3 != 0)) {
    if (*param_2 != '\0') {
      local_res10[0] = param_2;
      uVar1 = RtlAnsiCharToUnicodeChar(local_res10);
      *param_1 = uVar1;
      return (longlong)local_res10[0] - (longlong)param_2;
    }
    if (param_1 != (undefined2 *)0x0) {
      *param_1 = 0;
    }
  }
  return 0;
}



/* ===== FUNC FUN_00026274 @ 00026274 ===== */

undefined8 FUN_00026274(undefined8 param_1,longlong param_2)

{
  *(uint *)(param_2 + 0x18) = *(uint *)(param_2 + 0x18) | 0x20;
  return 0xffff;
}



/* ===== FUNC USBD_GetInterfaceLength @ 00026284 ===== */

void USBD_GetInterfaceLength(void)

{
                    /* WARNING: Could not recover jumptable at 0x00026284. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  USBD_GetInterfaceLength();
  return;
}



/* ===== FUNC RtlAnsiCharToUnicodeChar @ 00026290 ===== */

void RtlAnsiCharToUnicodeChar(void)

{
                    /* WARNING: Could not recover jumptable at 0x00026290. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  RtlAnsiCharToUnicodeChar();
  return;
}



/* ===== FUNC FUN_00039008 @ 00039008 ===== */

undefined4 FUN_00039008(longlong param_1,longlong param_2)

{
  longlong lVar1;
  longlong lVar2;
  undefined4 uVar3;
  
  lVar1 = *(longlong *)(param_2 + 0xb8);
  lVar2 = *(longlong *)(param_1 + 0x40);
  FUN_000121dc();
  uVar3 = 0;
  if (*(char *)(lVar2 + 8) == '\0') {
    uVar3 = *(undefined4 *)(param_2 + 0x30);
    IofCompleteRequest(param_2,0);
  }
  else {
    FUN_00012134(param_1,lVar2);
    if (*(int *)(lVar2 + 0xc) == 6) {
      uVar3 = 0xc000000e;
    }
    else {
      if (*(longlong *)(lVar2 + 0x40) == 0) {
        *(undefined8 *)(lVar2 + 0x40) = *(undefined8 *)(lVar1 + 0x30);
        FUN_000121dc();
      }
      *(undefined8 *)(param_2 + 0x38) = 0;
    }
    *(undefined4 *)(param_2 + 0x30) = uVar3;
    IofCompleteRequest(param_2,0);
    FUN_0001216c(param_1,lVar2);
  }
  return uVar3;
}



/* ===== FUNC FUN_000390e0 @ 000390e0 ===== */

int FUN_000390e0(longlong param_1,longlong param_2)

{
  longlong lVar1;
  int iVar2;
  
  lVar1 = param_1;
  FUN_000121dc();
  lVar1 = *(longlong *)(lVar1 + 0x40);
  if (*(char *)(lVar1 + 8) == '\0') {
    *(undefined8 *)(param_2 + 0x38) = 0;
    iVar2 = -0x3fffff45;
    *(undefined4 *)(param_2 + 0x30) = 0xc00000bb;
    IofCompleteRequest(param_2,0);
  }
  else {
    FUN_00012134(param_1,lVar1);
    iVar2 = 0;
    *(undefined8 *)(param_2 + 0x38) = 0;
    *(undefined4 *)(param_2 + 0x30) = 0;
    IofCompleteRequest(param_2,0);
    FUN_0001216c(param_1,lVar1);
  }
  FUN_00021370(iVar2);
  FUN_000121dc();
  return iVar2;
}



/* ===== FUNC FUN_00039198 @ 00039198 ===== */

undefined8 FUN_00039198(longlong param_1,longlong param_2)

{
  byte *pbVar1;
  longlong lVar2;
  longlong lVar3;
  longlong lVar4;
  undefined8 uVar5;
  
  lVar4 = param_1;
  FUN_000121dc();
  lVar4 = *(longlong *)(lVar4 + 0x40);
  FUN_00012134(param_1,lVar4);
  if (*(int *)(lVar4 + 0xc) == 6) {
    uVar5 = 0xc000000e;
  }
  else {
    uVar5 = 0;
    if (*(int *)(lVar4 + 0x8c) == 0) {
      uVar5 = FUN_00011858(param_1,lVar4,param_2);
      return uVar5;
    }
    pbVar1 = *(byte **)(param_2 + 0xb8);
    if (*pbVar1 < 3) {
LAB_00039270:
      uVar5 = 0xc0000001;
      *(undefined4 *)(param_2 + 0x30) = 0xc0000001;
      goto LAB_0003927a;
    }
    if (*pbVar1 < 5) {
      FUN_000121dc();
    }
    else {
      if (*pbVar1 != 0xe) goto LAB_00039270;
      lVar3 = FUN_000121dc();
      lVar2 = *(longlong *)(param_1 + 0x40);
      if (*(int *)(lVar3 + 0x18) != 0x2a400c) {
        uVar5 = 0xc0000010;
        goto LAB_000391e0;
      }
      *(undefined1 *)(lVar2 + 300) = 1;
      IoInvalidateDeviceState(*(undefined8 *)(lVar2 + 0x30));
    }
    *(undefined8 *)(param_2 + 0x38) = 0;
  }
LAB_000391e0:
  *(int *)(param_2 + 0x30) = (int)uVar5;
LAB_0003927a:
  IofCompleteRequest(param_2,0);
  FUN_0001216c(param_1,lVar4);
  return uVar5;
}



/* ===== FUNC FUN_000392b0 @ 000392b0 ===== */

ulonglong FUN_000392b0(undefined8 param_1,longlong *param_2)

{
  int iVar1;
  uint uVar2;
  ulonglong uVar3;
  char cVar4;
  int iVar5;
  
  iVar5 = 2;
  FUN_000121dc();
  iVar5 = iVar5 + -1;
  *(int *)((longlong)param_2 + 0x1c) = iVar5;
  PoSetPowerState(*param_2,iVar5,iVar5);
  cVar4 = (char)iVar5;
  iVar1 = IoSetDeviceInterfaceState(param_2 + 9,cVar4);
  if ((((-1 < iVar1) && (iVar1 = IoSetDeviceInterfaceState(param_2 + 0xb,cVar4), -1 < iVar1)) &&
      (iVar1 = IoSetDeviceInterfaceState(param_2 + 0xd,cVar4), -1 < iVar1)) &&
     ((*(int *)((longlong)param_2 + 0xc) == 3 || (iVar1 = FUN_0003c0e8(param_1,param_2), -1 < iVar1)
      ))) {
    *(undefined4 *)(param_2 + 2) = *(undefined4 *)((longlong)param_2 + 0xc);
    *(int *)((longlong)param_2 + 0xc) = iVar5;
    *(int *)((longlong)param_2 + 0x8c) = iVar5;
    uVar2 = FUN_000393e8(*param_2,(ulonglong *)((longlong)param_2 + 0x184));
    if (-1 < (int)uVar2) {
      FUN_00011958(param_1,param_2);
      FUN_000158ec(*param_2);
      FUN_0003c754(param_1,(longlong)param_2,cVar4);
      return (ulonglong)uVar2;
    }
  }
  uVar3 = FUN_000121dc();
  return uVar3;
}



/* ===== FUNC FUN_000393e8 @ 000393e8 ===== */

int FUN_000393e8(undefined8 param_1,ulonglong *param_2)

{
  longlong lVar1;
  int iVar2;
  undefined8 uVar3;
  longlong lVar4;
  int local_38 [4];
  undefined1 local_28 [32];
  
  iVar2 = 2;
  FUN_000121dc();
  FUN_000251f0(param_2,0,(ulonglong)(iVar2 + 0x3e));
  *(undefined2 *)param_2 = 0x40;
  *(undefined2 *)((longlong)param_2 + 2) = 1;
  *(undefined4 *)(param_2 + 1) = 0xffffffff;
  *(undefined4 *)((longlong)param_2 + 0xc) = 0xffffffff;
  KeInitializeEvent(local_28,0,0);
  uVar3 = IoGetAttachedDeviceReference(param_1);
  lVar4 = IoBuildSynchronousFsdRequest(0x1b,uVar3,0,0,0,local_28,local_38);
  if (lVar4 == 0) {
    iVar2 = -0x3fffff66;
  }
  else {
    lVar1 = *(longlong *)(lVar4 + 0xb8);
    *(undefined4 *)(lVar4 + 0x30) = 0xc00000bb;
    FUN_000251f0((ulonglong *)(lVar1 + -0x48),0,0x48);
    *(undefined1 *)(lVar1 + -0x48) = 0x1b;
    *(undefined1 *)(lVar1 + -0x47) = 9;
    *(ulonglong **)(lVar1 + -0x40) = param_2;
    iVar2 = IofCallDriver(uVar3,lVar4);
    if (iVar2 == 0x103) {
      KeWaitForSingleObject(local_28,0,0,0,0);
      iVar2 = local_38[0];
    }
  }
  ObfDereferenceObject(uVar3);
  return iVar2;
}



/* ===== FUNC FUN_00039518 @ 00039518 ===== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_00039518(longlong param_1,longlong param_2,longlong param_3,undefined8 *param_4)

{
  int *piVar1;
  byte bVar2;
  undefined4 uVar3;
  longlong lVar4;
  longlong *plVar5;
  longlong lVar6;
  undefined8 uVar7;
  undefined4 uVar8;
  longlong lVar9;
  undefined8 uVar10;
  ulonglong uVar11;
  undefined8 *puVar12;
  int iVar13;
  
  lVar4 = *(longlong *)(param_4[5] + 0x40);
  uVar8 = 0xc00000bb;
  FUN_0002503c();
  lVar9 = param_1;
  FUN_000121dc();
  bVar2 = *(byte *)(param_3 + 1);
  if (bVar2 < 0xb) {
    if (bVar2 == 10) goto LAB_0003985c;
    if (bVar2 < 6) {
      if (bVar2 == 5) {
        uVar8 = *(undefined4 *)((longlong)param_4 + 0xc);
        *(undefined4 *)((longlong)param_4 + 0xc) = 2;
LAB_000397ad:
        *(undefined4 *)(param_4 + 2) = uVar8;
        goto LAB_000397b0;
      }
      uVar8 = 0;
      if (bVar2 == 0) {
        if (*(int *)(param_4 + 2) != 4) {
          FUN_00012304(param_1,(longlong)param_4);
        }
        FUN_00012478(param_1,(longlong)param_4);
        *(undefined4 *)((longlong)param_4 + 0x1c) = 1;
        *(undefined4 *)(param_4 + 2) = *(undefined4 *)((longlong)param_4 + 0xc);
        *(undefined4 *)((longlong)param_4 + 0xc) = 1;
        goto LAB_0003985c;
      }
      if (bVar2 == 1) {
        uVar3 = *(undefined4 *)((longlong)param_4 + 0xc);
        *(undefined4 *)((longlong)param_4 + 0xc) = 4;
        *(undefined4 *)(param_4 + 2) = uVar3;
        goto LAB_0003985c;
      }
      if (bVar2 == 2) {
        FUN_00012520((longlong)param_4);
        if (*(char *)((longlong)param_4 + 0x6a) == '\0') {
          if (*(char *)((longlong)param_4 + 0x69) != '\0') {
            uVar3 = *(undefined4 *)((longlong)param_4 + 0xc);
            *(undefined4 *)((longlong)param_4 + 0xc) = 0;
            *(undefined4 *)(param_4 + 2) = uVar3;
          }
        }
        else {
          bVar2 = *(byte *)((longlong)param_4 + 0x24);
          *(undefined4 *)(param_4 + 2) = *(undefined4 *)((longlong)param_4 + 0xc);
          *(undefined4 *)((longlong)param_4 + 0xc) = 6;
          FUN_000121dc();
          if (((param_4[5] != 0) && (lVar4 != 0)) && (*(char *)(param_4 + 0xd) == '\0')) {
            ExAcquireFastMutex(lVar4 + 0xb8);
            plVar5 = (longlong *)param_4[0xc];
            lVar9 = param_4[0xb];
            *plVar5 = lVar9;
            *(longlong **)(lVar9 + 8) = plVar5;
            piVar1 = (int *)(lVar4 + 0xb0);
            *piVar1 = *piVar1 + -1;
            if (*piVar1 == 0) {
              IoCsqRemoveIrp(lVar4 + 0x218,lVar4 + 0x3a0);
              lVar9 = FUN_000121dc();
              if (lVar9 != 0) {
                lVar6 = *(longlong *)(lVar9 + 0x18);
                *(undefined4 *)(lVar6 + 4) = 0x24544e55;
                *(undefined2 *)(lVar6 + 2) = 0x300;
                *(undefined8 *)(lVar9 + 0x38) = 0x40d;
                *(undefined4 *)(lVar9 + 0x30) = 0;
                IofCompleteRequest(lVar9);
              }
            }
            lVar9 = (ulonglong)bVar2 * 0x268;
            LOCK();
            piVar1 = (int *)(lVar9 + 0xfd8 + lVar4);
            iVar13 = *piVar1;
            *piVar1 = *piVar1 + -1;
            UNLOCK();
            if (*(int *)(lVar4 + 0xb0) == 0) {
              LOCK();
              *(undefined4 *)(lVar9 + 0xfd8 + lVar4) = 0;
              UNLOCK();
            }
            if (iVar13 == 1) {
              KeSetEvent(lVar9 + 0xfe0 + lVar4,0,0);
            }
            ExReleaseFastMutex(lVar4 + 0xb8);
          }
          uVar10 = FUN_0003b0ac(param_1,(longlong)param_4);
          uVar8 = (undefined4)uVar10;
        }
        goto LAB_0003985c;
      }
      if (bVar2 == 3) {
        if (*(int *)((longlong)param_4 + 0xc) == 4) {
          *(undefined4 *)((longlong)param_4 + 0xc) = *(undefined4 *)(param_4 + 2);
        }
        goto LAB_0003985c;
      }
      if (bVar2 == 4) {
        uVar3 = *(undefined4 *)((longlong)param_4 + 0xc);
        *(undefined4 *)((longlong)param_4 + 0xc) = 3;
        *(undefined4 *)(param_4 + 2) = uVar3;
        FUN_00012520((longlong)param_4);
        goto LAB_0003985c;
      }
    }
    else {
      if (bVar2 == 6) {
        if (*(int *)((longlong)param_4 + 0xc) == 2) {
          *(undefined4 *)((longlong)param_4 + 0xc) = *(undefined4 *)(param_4 + 2);
        }
LAB_000397b0:
        uVar8 = 0;
        goto LAB_0003985c;
      }
      if (bVar2 == 7) {
        uVar8 = FUN_0003a6f0(param_1,param_4,param_2);
        goto LAB_0003985c;
      }
      if (bVar2 == 8) {
        uVar11 = FUN_0003a7b0((longlong)param_4,param_2);
        uVar8 = (undefined4)uVar11;
        goto LAB_0003985c;
      }
      if (bVar2 == 9) {
        uVar10 = FUN_00039968(param_1,(longlong)param_4);
        uVar8 = (undefined4)uVar10;
        goto LAB_0003985c;
      }
    }
LAB_00039848:
    FUN_000121dc();
  }
  else if (bVar2 != 0xb) {
    if (bVar2 == 0xc) {
      uVar8 = FUN_0003a37c(param_1,param_4,param_2,lVar9);
      goto LAB_0003985c;
    }
    if ((bVar2 == 0xd) || (bVar2 == 0x11)) goto LAB_0003985c;
    if (bVar2 == 0x13) {
      if (DAT_00037820 == 0x5000000) {
        uVar8 = FUN_00039a70(param_1,(longlong)param_4,param_2);
      }
      else {
        uVar8 = FUN_00039eb8(param_1,(longlong)param_4,param_2);
      }
      goto LAB_0003985c;
    }
    if (bVar2 == 0x14) {
      FUN_000121dc();
      if (*(int *)((longlong)param_4 + 0xc) == 1) {
        *(uint *)(param_2 + 0x38) = *(uint *)(param_2 + 0x38) & 0xfffffffe;
      }
      else {
        *(uint *)(param_2 + 0x38) = *(uint *)(param_2 + 0x38) | 1;
      }
      FUN_000121dc();
      goto LAB_000397b0;
    }
    if (bVar2 == 0x15) {
      iVar13 = 2;
      FUN_000121dc();
      puVar12 = (undefined8 *)ExAllocatePoolWithTag(1,iVar13 + 0x16,0x31747345);
      uVar7 = _UNK_00035fd8;
      uVar10 = _DAT_00035fd0;
      uVar8 = 0;
      if (puVar12 == (undefined8 *)0x0) {
        uVar8 = 0xc000009a;
      }
      else {
        *(undefined4 *)(puVar12 + 2) = 0xf;
        *(undefined4 *)((longlong)puVar12 + 0x14) = 0;
        *puVar12 = uVar10;
        puVar12[1] = uVar7;
        *(undefined8 **)(param_2 + 0x38) = puVar12;
      }
      goto LAB_0003985c;
    }
    if (bVar2 == 0x17) {
      uVar8 = *(undefined4 *)((longlong)param_4 + 0xc);
      *(undefined4 *)((longlong)param_4 + 0xc) = 5;
      goto LAB_000397ad;
    }
    if (bVar2 == 0x18) goto LAB_0003985c;
    goto LAB_00039848;
  }
  uVar8 = *(undefined4 *)(param_2 + 0x30);
LAB_0003985c:
  *(undefined4 *)(param_2 + 0x30) = uVar8;
  IofCompleteRequest(param_2,0);
  return uVar8;
}



/* ===== FUNC FUN_00039968 @ 00039968 ===== */

undefined8 FUN_00039968(undefined8 param_1,longlong param_2)

{
  ushort *puVar1;
  uint uVar2;
  longlong lVar3;
  undefined8 uVar4;
  
  lVar3 = FUN_000121dc();
  puVar1 = *(ushort **)(lVar3 + 8);
  if ((puVar1[1] == 1) && (0x3f < *puVar1)) {
    puVar1[10] = 1;
    puVar1[0xb] = 0;
    if (*(int *)(puVar1 + 0xc) != 1) {
      puVar1[0xc] = 4;
      puVar1[0xd] = 0;
    }
    if (*(int *)(puVar1 + 0xe) != 1) {
      puVar1[0xe] = 4;
      puVar1[0xf] = 0;
    }
    if (*(int *)(puVar1 + 0x10) != 1) {
      puVar1[0x10] = 4;
      puVar1[0x11] = 0;
    }
    puVar1[0x12] = 4;
    puVar1[0x13] = 0;
    puVar1[0x14] = 4;
    puVar1[0x15] = 0;
    if (*(char *)(param_2 + 0x211) == '\0') {
      puVar1[0x18] = 1;
      puVar1[0x19] = 0;
      puVar1[0x16] = 1;
      puVar1[0x17] = 0;
    }
    else {
      puVar1[0x18] = 3;
      puVar1[0x19] = 0;
      puVar1[0x16] = 5;
      puVar1[0x17] = 0;
    }
    if (*(char *)(param_2 + 0x211) == '\0') {
      *(uint *)(puVar1 + 2) = *(uint *)(puVar1 + 2) & 0xfffffffc;
    }
    else {
      *(uint *)(puVar1 + 2) = *(uint *)(puVar1 + 2) | 3;
    }
    if (*(char *)(param_2 + 0x211) == '\0') {
      uVar2 = *(uint *)(puVar1 + 2) & 0xffffd3ff | 0x1000;
    }
    else {
      uVar2 = *(uint *)(puVar1 + 2) & 0xffffdfff | 0x1c00;
    }
    *(uint *)(puVar1 + 2) = uVar2;
    puVar1[0x1a] = 0;
    puVar1[0x1b] = 0;
    puVar1[0x1c] = 0;
    puVar1[0x1d] = 0;
    puVar1[0x1e] = 0;
    puVar1[0x1f] = 0;
    *(uint *)(puVar1 + 2) = uVar2 & 0xffffbdf7 | 0x10;
    if (*(char *)(param_2 + 0x84) == '\0') {
      uVar2 = uVar2 & 0xffffbdb7 | 0x10;
    }
    else {
      uVar2 = uVar2 & 0xffffbdf7 | 0x50;
    }
    *(uint *)(puVar1 + 2) = uVar2;
    *(uint *)(puVar1 + 2) = *(uint *)(puVar1 + 2) & 0xffffff7f;
    *(uint *)(puVar1 + 4) = (uint)*(byte *)(param_2 + 0x24);
    puVar1[6] = 0;
    puVar1[7] = 0;
    uVar4 = 0;
  }
  else {
    uVar4 = 0xc0000001;
  }
  return uVar4;
}



/* ===== FUNC FUN_00039a70 @ 00039a70 ===== */

undefined4 FUN_00039a70(longlong param_1,longlong param_2,longlong param_3)

{
  int iVar1;
  longlong lVar2;
  byte *pbVar3;
  longlong lVar4;
  ulonglong *_Dst;
  STRSAFE_PCNZWCH pwVar5;
  ulonglong uVar6;
  undefined1 *puVar7;
  uint uVar8;
  
  lVar2 = *(longlong *)(param_3 + 0xb8);
  FUN_0002503c();
  FUN_000121dc();
  lVar4 = *(longlong *)(param_2 + 0x88 + (ulonglong)*(byte *)(param_2 + 0x108) * 8);
  lVar4 = USBD_ParseDescriptors(lVar4,*(undefined2 *)(lVar4 + 2),lVar4,4);
  iVar1 = *(int *)(lVar2 + 8);
  if (iVar1 == 0) {
    if (*(char *)(param_2 + 0x25) == '\x01') {
      pwVar5 = (STRSAFE_PCNZWCH)ExAllocatePoolWithTag(1,0x38);
      if (pwVar5 == (STRSAFE_PCNZWCH)0x0) {
        return 0xc000009a;
      }
      FUN_000122b0(pwVar5,0x38,L"USB\\VID_%04X&PID_%04X&MI_%02X",
                   (ulonglong)*(ushort *)(param_2 + 0x7c));
    }
    else {
      pwVar5 = (STRSAFE_PCNZWCH)ExAllocatePoolWithTag(1,0x2c,0x31747345);
      if (pwVar5 == (STRSAFE_PCNZWCH)0x0) {
        return 0xc000009a;
      }
      FUN_000122b0(pwVar5,0x2c,L"USB\\Vid_%04X&Pid_%04X",(ulonglong)*(ushort *)(param_2 + 0x7c));
    }
    FUN_000121dc();
    goto LAB_00039e8d;
  }
  if (iVar1 == 1) {
    if (*(char *)(*(longlong *)(param_1 + 0x40) + 0x25) == '\x01') {
      pwVar5 = (STRSAFE_PCNZWCH)ExAllocatePoolWithTag();
      if (pwVar5 != (STRSAFE_PCNZWCH)0x0) {
        FUN_000251f0((ulonglong *)pwVar5,0,0x84);
        FUN_000122b0(pwVar5,0x48,L"USB\\VID_%04X&PID_%04X&REV_%04X&MI_%02X",
                     (ulonglong)*(ushort *)(param_2 + 0x7c));
        FUN_000122b0(pwVar5 + 0x25,0x36,L"USB\\VID_%04X&PID_%04X&MI_%02X",
                     (ulonglong)*(ushort *)(param_2 + 0x7c));
LAB_00039e8d:
        *(STRSAFE_PCNZWCH *)(param_3 + 0x38) = pwVar5;
        return 0;
      }
    }
    else {
      pwVar5 = (STRSAFE_PCNZWCH)ExAllocatePoolWithTag(1,0x6c,0x31747345);
      if (pwVar5 != (STRSAFE_PCNZWCH)0x0) {
        FUN_000251f0((ulonglong *)pwVar5,0,0x6c);
        FUN_000122b0(pwVar5,0x3c,L"USB\\VID_%04X&PID_%04X&REV_%04X",
                     (ulonglong)*(ushort *)(param_2 + 0x7c));
        FUN_000122b0(pwVar5 + 0x1f,0x2a,L"USB\\VID_%04X&PID_%04X",
                     (ulonglong)*(ushort *)(param_2 + 0x7c));
        goto LAB_00039e8d;
      }
    }
  }
  else if (iVar1 == 2) {
    pwVar5 = (STRSAFE_PCNZWCH)ExAllocatePoolWithTag(1,0x90,0x31747345);
    if ((pwVar5 != (STRSAFE_PCNZWCH)0x0) && (FUN_000251f0((ulonglong *)pwVar5,0,0x90), lVar4 != 0))
    {
      FUN_000122b0(pwVar5,0x40,L"USB\\Class_%02X&SubClass_%02X&Prot_%02X",
                   (ulonglong)*(byte *)(lVar4 + 5));
      FUN_000122b0(pwVar5 + 0x21,0x30,L"USB\\Class_%02X&SubClass_%02X",
                   (ulonglong)*(byte *)(lVar4 + 5));
      FUN_000122b0(pwVar5 + 0x3a,0x18,L"USB\\Class_%02X",(ulonglong)*(byte *)(lVar4 + 5));
      goto LAB_00039e8d;
    }
  }
  else {
    if (iVar1 != 3) {
      FUN_000121dc();
      return *(undefined4 *)(param_3 + 0x30);
    }
    pbVar3 = *(byte **)(param_2 + 0x128);
    if (*(char *)(param_2 + 0x25) == '\x01') {
      uVar8 = *pbVar3 + 6;
      _Dst = (ulonglong *)ExAllocatePoolWithTag();
      if (_Dst != (ulonglong *)0x0) {
        FUN_000251f0(_Dst,0,(ulonglong)uVar8);
        memcpy(_Dst,pbVar3 + 2,(longlong)(int)(*pbVar3 - 2));
        FUN_000122b0((STRSAFE_PCNZWCH)((longlong)_Dst + (longlong)((int)(*pbVar3 - 2) / 2) * 2),
                     (ulonglong)((uVar8 - *pbVar3) + 2),L"_%02d",
                     (ulonglong)*(byte *)(param_2 + 0x26));
LAB_00039bf7:
        if (uVar8 != 0) {
          puVar7 = (undefined1 *)((longlong)_Dst + 1);
          uVar6 = (ulonglong)(uVar8 + 1 >> 1);
          do {
            *puVar7 = 0;
            puVar7 = puVar7 + 2;
            uVar6 = uVar6 - 1;
          } while (uVar6 != 0);
        }
        FUN_000121dc();
        *(ulonglong **)(param_3 + 0x38) = _Dst;
        return 0;
      }
    }
    else {
      uVar8 = (uint)*pbVar3;
      _Dst = (ulonglong *)ExAllocatePoolWithTag(1,*pbVar3,0x31747345);
      if (_Dst != (ulonglong *)0x0) {
        FUN_000251f0(_Dst,0,(ulonglong)*pbVar3);
        memcpy(_Dst,pbVar3 + 2,(longlong)(int)(*pbVar3 - 2));
        goto LAB_00039bf7;
      }
    }
  }
  return 0xc000009a;
}



/* ===== FUNC FUN_00039eb8 @ 00039eb8 ===== */

undefined4 FUN_00039eb8(undefined8 param_1,longlong param_2,longlong param_3)

{
  byte bVar1;
  char cVar2;
  int iVar3;
  byte *pbVar4;
  uint uVar5;
  longlong lVar6;
  STRSAFE_PCNZWCH pwVar7;
  ulonglong *_Dst;
  ulonglong uVar8;
  STRSAFE_PCNZWCH pwVar9;
  undefined1 *puVar10;
  size_t sVar11;
  wchar_t *pwVar12;
  undefined8 uVar13;
  longlong lVar14;
  
  lVar14 = *(longlong *)(param_3 + 0xb8);
  FUN_0002503c();
  FUN_000121dc();
  lVar6 = *(longlong *)(param_2 + 0x88 + (ulonglong)*(byte *)(param_2 + 0x108) * 8);
  uVar13 = 4;
  lVar6 = USBD_ParseDescriptors(lVar6,*(undefined2 *)(lVar6 + 2),lVar6);
  iVar3 = *(int *)(lVar14 + 8);
  if (iVar3 == 0) {
    pwVar7 = (STRSAFE_PCNZWCH)ExAllocatePoolWithTag(1,0x2c,0x31747345);
    if (pwVar7 == (STRSAFE_PCNZWCH)0x0) {
      return 0xc000009a;
    }
    FUN_000122b0(pwVar7,0x2c,L"USB\\Vid_%04x&Pid_%04x",(ulonglong)*(ushort *)(param_2 + 0x7c));
LAB_0003a344:
    FUN_000121dc();
LAB_0003a351:
    *(STRSAFE_PCNZWCH *)(param_3 + 0x38) = pwVar7;
    return 0;
  }
  if (iVar3 == 1) {
    pwVar7 = (STRSAFE_PCNZWCH)ExAllocatePoolWithTag(1,0x6c,0x31747345);
    if (pwVar7 == (STRSAFE_PCNZWCH)0x0) {
      return 0xc000009a;
    }
    FUN_000251f0((ulonglong *)pwVar7,0,0x6c);
    FUN_000122b0(pwVar7,0x3c,L"USB\\Vid_%04x&Pid_%04x&Rev_%04x",
                 (ulonglong)*(ushort *)(param_2 + 0x7c));
    FUN_000122b0(pwVar7 + 0x1f,0x2a,L"USB\\Vid_%04x&Pid_%04x",(ulonglong)*(ushort *)(param_2 + 0x7c)
                );
    goto LAB_0003a351;
  }
  if (iVar3 != 2) {
    if (iVar3 != 3) {
      FUN_000121dc();
      return *(undefined4 *)(param_3 + 0x30);
    }
    if (*(char *)(param_2 + 0x84) != '\0') {
      pbVar4 = *(byte **)(param_2 + 0x128);
      bVar1 = *pbVar4;
      _Dst = (ulonglong *)ExAllocatePoolWithTag(1,bVar1,0x31747345);
      if (_Dst == (ulonglong *)0x0) {
        return 0xc000009a;
      }
      FUN_000251f0(_Dst,0,(ulonglong)*pbVar4);
      memcpy(_Dst,pbVar4 + 2,(longlong)(int)(*pbVar4 - 2));
      if (bVar1 != 0) {
        puVar10 = (undefined1 *)((longlong)_Dst + 1);
        uVar8 = (ulonglong)(bVar1 + 1 >> 1);
        do {
          *puVar10 = 0;
          puVar10 = puVar10 + 2;
          uVar8 = uVar8 - 1;
        } while (uVar8 != 0);
      }
      FUN_000121dc();
      *(ulonglong **)(param_3 + 0x38) = _Dst;
      return 0;
    }
    pwVar7 = (STRSAFE_PCNZWCH)ExAllocatePoolWithTag(1,4);
    if (pwVar7 == (STRSAFE_PCNZWCH)0x0) {
      return 0xc000009a;
    }
    pwVar7[0] = L'\0';
    pwVar7[1] = L'\0';
    FUN_000122b0(pwVar7,4,L"%d",(ulonglong)*(byte *)(param_2 + 0x24));
    goto LAB_0003a344;
  }
  cVar2 = *(char *)(param_2 + 0x211);
  if (cVar2 == '\0') {
    lVar14 = 0x48;
    if (*(char *)(param_2 + 0x25) == '\x01') {
      lVar14 = 0x5f;
    }
    pwVar7 = (STRSAFE_PCNZWCH)ExAllocatePoolWithTag(1,lVar14 * 2,0x31747345);
    if (pwVar7 == (STRSAFE_PCNZWCH)0x0) {
      return 0xc000009a;
    }
    FUN_000251f0((ulonglong *)pwVar7,0,lVar14 * 2);
    if (lVar6 == 0) {
      return 0xc000009a;
    }
    if (*(char *)(param_2 + 0x25) == '\x01') {
      FUN_000122b0(pwVar7,0x46,L"USB\\DevClass_%02X&SubClass_%02X&Prot_%02X",0);
      FUN_000122b0(pwVar7 + 0x24,0x36,L"USB\\DevClass_%02X&SubClass_%02X",0);
      uVar13 = 0;
      FUN_000122b0(pwVar7 + 0x40,0x1e,L"USB\\DevClass_%02X",0);
      FUN_000122b0(pwVar7 + 0x50,0x1a,L"USB\\COMPOSITE",uVar13);
      goto LAB_0003a274;
    }
    FUN_000122b0(pwVar7,0x40,L"USB\\Class_%02X&SubClass_%02X&Prot_%02X",
                 (ulonglong)*(byte *)(lVar6 + 5));
    FUN_000122b0(pwVar7 + 0x21,0x30,L"USB\\Class_%02X&SubClass_%02X",(ulonglong)*(byte *)(lVar6 + 5)
                );
    pwVar9 = pwVar7 + 0x3a;
  }
  else {
    uVar5 = 0x22;
    if ((cVar2 != '\x02') && (uVar5 = 0x25, cVar2 == '\x01')) {
      uVar5 = 0x22;
    }
    uVar8 = (ulonglong)(uVar5 + 0x5c) * 2;
    pwVar7 = (STRSAFE_PCNZWCH)ExAllocatePoolWithTag(1,uVar8,0x31747345);
    if (pwVar7 == (STRSAFE_PCNZWCH)0x0) {
      return 0xc000009a;
    }
    FUN_000251f0((ulonglong *)pwVar7,0,uVar8);
    if (lVar6 == 0) {
      return 0xc000009a;
    }
    if (*(char *)(param_2 + 0x211) == '\x02') {
      pwVar12 = L"USB\\MS_COMP_USBCIR&MS_SUBCOMP_IRV2";
LAB_0003a1c3:
      sVar11 = 0x44;
    }
    else {
      if (*(char *)(param_2 + 0x211) == '\x01') {
        pwVar12 = L"USB\\MS_COMP_USBCIR&MS_SUBCOMP_IRRX";
        goto LAB_0003a1c3;
      }
      pwVar12 = L"USB\\MS_COMP_USBCIR&MS_SUBCOMP_IR2CMPT";
      sVar11 = 0x4a;
    }
    FUN_000122b0(pwVar7,sVar11,pwVar12,uVar13);
    FUN_000122b0(pwVar7 + (ulonglong)uVar5 + 1,0x24,L"USB\\MS_COMP_USBCIR",uVar13);
    FUN_000122b0(pwVar7 + (ulonglong)uVar5 + 0x14,0x40,L"USB\\Class_%02X&SubClass_%02X&Prot_%02X",
                 (ulonglong)*(byte *)(lVar6 + 5));
    FUN_000122b0(pwVar7 + (ulonglong)uVar5 + 0x35,0x30,L"USB\\Class_%02X&SubClass_%02X",
                 (ulonglong)*(byte *)(lVar6 + 5));
    pwVar9 = pwVar7 + (ulonglong)uVar5 + 0x4e;
  }
  FUN_000122b0(pwVar9,0x18,L"USB\\Class_%02X",(ulonglong)*(byte *)(lVar6 + 5));
LAB_0003a274:
  *(STRSAFE_PCNZWCH *)(param_3 + 0x38) = pwVar7;
  return 0;
}



/* ===== FUNC FUN_0003a37c @ 0003a37c ===== */

undefined4 FUN_0003a37c(undefined8 param_1,undefined8 param_2,longlong param_3,undefined8 param_4)

{
  byte bVar1;
  char cVar2;
  byte *pbVar3;
  longlong lVar4;
  STRSAFE_PCNZWCH _Dst;
  size_t sVar5;
  wchar_t *pwVar6;
  
  lVar4 = FUN_000121dc();
  if (1 < *(uint *)(*(longlong *)(param_3 + 0xb8) + 8)) {
    return *(undefined4 *)(param_3 + 0x30);
  }
  pbVar3 = *(byte **)(lVar4 + 0x120);
  if ((*pbVar3 < 3) || (pbVar3[1] != 3)) {
    cVar2 = *(char *)(lVar4 + 0x1f1);
    if (cVar2 == '\x01') {
      sVar5 = 0x22;
      _Dst = (STRSAFE_PCNZWCH)ExAllocatePoolWithTag(1,0x22,0x31747345);
      if (_Dst == (STRSAFE_PCNZWCH)0x0) {
        return 0xc000009a;
      }
      FUN_000251f0((ulonglong *)_Dst,0,0x22);
      pwVar6 = L"USB Audio Device";
    }
    else if ((cVar2 == '\x02') || (cVar2 == '\n')) {
      sVar5 = 0x32;
      _Dst = (STRSAFE_PCNZWCH)ExAllocatePoolWithTag(1,0x32,0x31747345);
      if (_Dst == (STRSAFE_PCNZWCH)0x0) {
        return 0xc000009a;
      }
      FUN_000251f0((ulonglong *)_Dst,0,0x32);
      pwVar6 = L"USB Communication Device";
    }
    else if (cVar2 == '\x03') {
      sVar5 = 0x1e;
      _Dst = (STRSAFE_PCNZWCH)ExAllocatePoolWithTag(1,0x1e);
      if (_Dst == (STRSAFE_PCNZWCH)0x0) {
        return 0xc000009a;
      }
      pwVar6 = L"USB HID Device";
      _Dst[0] = L'\0';
      _Dst[1] = L'\0';
      _Dst[2] = L'\0';
      _Dst[3] = L'\0';
      _Dst[4] = L'\0';
      _Dst[5] = L'\0';
      _Dst[6] = L'\0';
      _Dst[7] = L'\0';
      _Dst[8] = L'\0';
      _Dst[9] = L'\0';
      _Dst[10] = L'\0';
      _Dst[0xb] = L'\0';
      _Dst[0xc] = L'\0';
      _Dst[0xd] = L'\0';
      _Dst[0xe] = L'\0';
    }
    else if (cVar2 == '\x04') {
      sVar5 = 0x26;
      _Dst = (STRSAFE_PCNZWCH)ExAllocatePoolWithTag();
      if (_Dst == (STRSAFE_PCNZWCH)0x0) {
        return 0xc000009a;
      }
      FUN_000251f0((ulonglong *)_Dst,0,0x26);
      pwVar6 = L"USB Monitor Device";
    }
    else if (cVar2 == '\x06') {
      sVar5 = 0x22;
      _Dst = (STRSAFE_PCNZWCH)ExAllocatePoolWithTag();
      if (_Dst == (STRSAFE_PCNZWCH)0x0) {
        return 0xc000009a;
      }
      FUN_000251f0((ulonglong *)_Dst,0,0x22);
      pwVar6 = L"USB Image Device";
    }
    else if (cVar2 == '\a') {
      sVar5 = 0x26;
      _Dst = (STRSAFE_PCNZWCH)ExAllocatePoolWithTag();
      if (_Dst == (STRSAFE_PCNZWCH)0x0) {
        return 0xc000009a;
      }
      FUN_000251f0((ulonglong *)_Dst,0,0x26);
      pwVar6 = L"USB Printer Device";
    }
    else if (cVar2 == '\b') {
      sVar5 = 0x30;
      _Dst = (STRSAFE_PCNZWCH)ExAllocatePoolWithTag();
      if (_Dst == (STRSAFE_PCNZWCH)0x0) {
        return 0xc000009a;
      }
      FUN_000251f0((ulonglong *)_Dst,0,0x30);
      pwVar6 = L"USB Mass Storage Device";
    }
    else if (cVar2 == '\v') {
      sVar5 = 0x1e;
      _Dst = (STRSAFE_PCNZWCH)ExAllocatePoolWithTag(1,0x1e);
      if (_Dst == (STRSAFE_PCNZWCH)0x0) {
        return 0xc000009a;
      }
      pwVar6 = L"USB Smart Card";
      _Dst[0] = L'\0';
      _Dst[1] = L'\0';
      _Dst[2] = L'\0';
      _Dst[3] = L'\0';
      _Dst[4] = L'\0';
      _Dst[5] = L'\0';
      _Dst[6] = L'\0';
      _Dst[7] = L'\0';
      _Dst[8] = L'\0';
      _Dst[9] = L'\0';
      _Dst[10] = L'\0';
      _Dst[0xb] = L'\0';
      _Dst[0xc] = L'\0';
      _Dst[0xd] = L'\0';
      _Dst[0xe] = L'\0';
    }
    else if (cVar2 == '\x0e') {
      sVar5 = 0x22;
      _Dst = (STRSAFE_PCNZWCH)ExAllocatePoolWithTag();
      if (_Dst == (STRSAFE_PCNZWCH)0x0) {
        return 0xc000009a;
      }
      FUN_000251f0((ulonglong *)_Dst,0,0x22);
      pwVar6 = L"USB Video Device";
    }
    else {
      sVar5 = 0x16;
      _Dst = (STRSAFE_PCNZWCH)ExAllocatePoolWithTag(1,0x16,0x31747345);
      if (_Dst == (STRSAFE_PCNZWCH)0x0) {
        return 0xc000009a;
      }
      pwVar6 = L"USB Device";
      _Dst[0] = L'\0';
      _Dst[1] = L'\0';
      _Dst[2] = L'\0';
      _Dst[3] = L'\0';
      _Dst[4] = L'\0';
      _Dst[5] = L'\0';
      _Dst[6] = L'\0';
      _Dst[7] = L'\0';
      _Dst[8] = L'\0';
      _Dst[9] = L'\0';
      _Dst[10] = L'\0';
    }
    FUN_000122b0(_Dst,sVar5,pwVar6,param_4);
  }
  else {
    bVar1 = *pbVar3;
    _Dst = (STRSAFE_PCNZWCH)ExAllocatePoolWithTag(1,bVar1,0x31747345);
    if (_Dst == (STRSAFE_PCNZWCH)0x0) {
      return 0xc000009a;
    }
    FUN_000251f0((ulonglong *)_Dst,0,(ulonglong)*pbVar3);
    memcpy(_Dst,pbVar3 + 2,(longlong)(int)(bVar1 - 2));
  }
  FUN_000121dc();
  *(STRSAFE_PCNZWCH *)(param_3 + 0x38) = _Dst;
  return 0;
}



/* ===== FUNC FUN_0003a6f0 @ 0003a6f0 ===== */

undefined4 FUN_0003a6f0(undefined8 param_1,undefined8 *param_2,longlong param_3)

{
  int iVar1;
  undefined4 *puVar2;
  longlong lVar3;
  
  lVar3 = *(longlong *)(param_3 + 0xb8);
  FUN_0002503c();
  FUN_000121dc();
  iVar1 = *(int *)(lVar3 + 8);
  if (iVar1 != 0) {
    if ((iVar1 == 1) || (iVar1 == 3)) {
      return 0xc00000bb;
    }
    if (iVar1 == 4) {
      puVar2 = (undefined4 *)ExAllocatePoolWithTag(1,0x10,0x31747345);
      if (puVar2 == (undefined4 *)0x0) {
        return 0xc000009a;
      }
      *puVar2 = 1;
      *(undefined8 *)(puVar2 + 2) = *param_2;
      ObfReferenceObject(*param_2);
      *(undefined4 **)(param_3 + 0x38) = puVar2;
      return 0;
    }
  }
  return *(undefined4 *)(param_3 + 0x30);
}



/* ===== FUNC FUN_0003a7b0 @ 0003a7b0 ===== */

ulonglong FUN_0003a7b0(longlong param_1,longlong param_2)

{
  ulonglong *puVar1;
  int iVar2;
  ulonglong uVar3;
  bool bVar4;
  
  FUN_000121dc();
  puVar1 = *(ulonglong **)(*(longlong *)(param_2 + 0xb8) + 8);
  uVar3 = *puVar1;
  bVar4 = uVar3 < DAT_00035fb0;
  if ((uVar3 == DAT_00035fb0) &&
     (uVar3 = puVar1[1], bVar4 = uVar3 < DAT_00035fb8, uVar3 == DAT_00035fb8)) {
    iVar2 = 0;
  }
  else {
    iVar2 = (1 - (uint)bVar4) - (uint)(bVar4 != 0);
  }
  if (iVar2 == 0) {
    FUN_000121dc();
    uVar3 = FUN_0001be2c(param_1,param_2);
  }
  else {
    FUN_000121dc();
    uVar3 = (ulonglong)*(uint *)(param_2 + 0x30);
  }
  return uVar3;
}



/* ===== FUNC FUN_0003a878 @ 0003a878 ===== */

ulonglong FUN_0003a878(longlong param_1,longlong param_2)

{
  longlong lVar1;
  undefined4 uVar2;
  ulonglong uVar3;
  undefined4 extraout_var;
  undefined8 *puVar4;
  
  lVar1 = *(longlong *)(param_2 + 0xb8);
  puVar4 = *(undefined8 **)(param_1 + 0x40);
  FUN_0002503c();
  FUN_000121dc();
  if (*(int *)((longlong)puVar4 + 0xc) == 6) {
    *(undefined4 *)(param_2 + 0x30) = 0xc000000e;
    IofCompleteRequest(param_2,0);
    uVar3 = 0xc000000e;
  }
  else if (*(char *)(puVar4 + 1) == '\0') {
    uVar2 = FUN_00039518(param_1,param_2,lVar1,puVar4);
    uVar3 = CONCAT44(extraout_var,uVar2);
  }
  else {
    uVar3 = FUN_0003a91c(param_1,param_2);
  }
  return uVar3;
}



/* ===== FUNC FUN_0003a91c @ 0003a91c ===== */

ulonglong FUN_0003a91c(longlong param_1,longlong param_2)

{
  uint *puVar1;
  byte bVar2;
  undefined4 uVar3;
  longlong *plVar4;
  uint uVar5;
  int iVar6;
  ulonglong uVar7;
  ulonglong uVar8;
  
  plVar4 = *(longlong **)(param_1 + 0x40);
  bVar2 = *(byte *)(*(longlong *)(param_2 + 0xb8) + 1);
  FUN_0002503c();
  FUN_000121dc();
  FUN_00012134(param_1,(longlong)plVar4);
  if (bVar2 < 6) {
    if (bVar2 == 5) {
      uVar7 = FUN_00011b68();
      uVar8 = uVar7 & 0xffffffff;
      if (-1 < (int)uVar7) {
        *(undefined4 *)((longlong)plVar4 + 0x8c) = 0;
        *(undefined4 *)(plVar4 + 2) = *(undefined4 *)((longlong)plVar4 + 0xc);
        *(undefined4 *)((longlong)plVar4 + 0xc) = 2;
        FUN_000121dc();
        FUN_0001216c(param_1,(longlong)plVar4);
LAB_0003ab53:
        KeWaitForSingleObject(plVar4 + 0x22,0,0,0,0);
        *(undefined4 *)(param_2 + 0x30) = 0;
        *(char *)(param_2 + 0x43) = *(char *)(param_2 + 0x43) + '\x01';
        *(longlong *)(param_2 + 0xb8) = *(longlong *)(param_2 + 0xb8) + 0x48;
        uVar5 = IofCallDriver(plVar4[7],param_2);
LAB_0003ab8b:
        uVar8 = (ulonglong)uVar5;
        FUN_00021370(uVar5);
        FUN_000121dc();
        return uVar8 & 0xffffffff;
      }
    }
    else if (bVar2 == 0) {
      uVar7 = FUN_0003aff0(param_1,param_2);
      uVar8 = uVar7 & 0xffffffff;
      if (-1 < (int)uVar7) {
        uVar8 = FUN_000392b0(param_1,plVar4);
        uVar8 = uVar8 & 0xffffffff;
      }
    }
    else if (bVar2 == 1) {
      uVar7 = FUN_00011b90();
      uVar8 = uVar7 & 0xffffffff;
      if (-1 < (int)uVar7) {
        *(undefined4 *)((longlong)plVar4 + 0x8c) = 0;
        *(undefined4 *)(plVar4 + 2) = *(undefined4 *)((longlong)plVar4 + 0xc);
        *(undefined4 *)((longlong)plVar4 + 0xc) = 4;
        FUN_000121dc();
        FUN_0001216c(param_1,(longlong)plVar4);
        FUN_0003c880(param_1,(longlong)plVar4,'\x01');
        goto LAB_0003ab53;
      }
    }
    else {
      if (bVar2 == 2) {
        uVar5 = FUN_00014458(param_1,param_2);
        goto LAB_0003ab8b;
      }
      if (bVar2 != 3) {
        if (bVar2 != 4) goto LAB_0003abe0;
        uVar3 = *(undefined4 *)((longlong)plVar4 + 0xc);
        *(undefined4 *)((longlong)plVar4 + 0xc) = 3;
        *(undefined4 *)(plVar4 + 2) = uVar3;
        FUN_00011bb8(param_1);
        FUN_0003c880(param_1,(longlong)plVar4,'\x01');
        goto LAB_0003a9e5;
      }
      uVar7 = FUN_0003aff0(param_1,param_2);
      uVar8 = uVar7 & 0xffffffff;
      if ((-1 < (int)uVar7) && (*(int *)((longlong)plVar4 + 0xc) == 4)) {
        *(undefined4 *)((longlong)plVar4 + 0x8c) = 1;
        *(int *)((longlong)plVar4 + 0xc) = (int)plVar4[2];
        FUN_00011958(param_1,plVar4);
        FUN_0003c754(param_1,(longlong)plVar4,'\x01');
      }
    }
  }
  else {
    if (bVar2 != 6) {
      if (bVar2 == 7) {
        uVar5 = FUN_0003adac(param_1,param_2);
LAB_0003aa02:
        FUN_00021370(uVar5);
      }
      else {
        if (bVar2 == 0x14) {
          uVar8 = FUN_0003aff0(param_1,param_2);
          uVar8 = uVar8 & 0xffffffff;
          if (*(char *)((longlong)plVar4 + 300) == '\x01') {
            puVar1 = (uint *)(param_2 + 0x38);
            if (puVar1 != (uint *)0x0) {
              *puVar1 = *puVar1 | 2;
            }
            uVar8 = 0;
          }
          goto LAB_0003ad3a;
        }
        if (bVar2 == 0x17) {
          uVar3 = *(undefined4 *)((longlong)plVar4 + 0xc);
          *(undefined4 *)((longlong)plVar4 + 0xc) = 5;
          *(undefined4 *)((longlong)plVar4 + 0x8c) = 2;
          *(undefined4 *)(plVar4 + 2) = uVar3;
          FUN_00011958(param_1,plVar4);
          iVar6 = IoSetDeviceInterfaceState(plVar4 + 9,0);
          if (iVar6 < 0) {
            FUN_000121dc();
          }
          iVar6 = IoSetDeviceInterfaceState(plVar4 + 0xb,0);
          if (iVar6 < 0) {
            FUN_000121dc();
          }
          iVar6 = IoSetDeviceInterfaceState(plVar4 + 0xd,0);
          if (iVar6 < 0) {
            FUN_000121dc();
          }
          FUN_00011bb8(param_1);
          FUN_0003c880(param_1,(longlong)plVar4,'\x01');
          FUN_000121dc();
          IoWMIRegistrationControl(*plVar4,2);
LAB_0003a9e5:
          *(undefined4 *)(param_2 + 0x30) = 0;
          *(char *)(param_2 + 0x43) = *(char *)(param_2 + 0x43) + '\x01';
          *(longlong *)(param_2 + 0xb8) = *(longlong *)(param_2 + 0xb8) + 0x48;
          uVar5 = IofCallDriver(plVar4[7],param_2);
          goto LAB_0003aa02;
        }
LAB_0003abe0:
        *(char *)(param_2 + 0x43) = *(char *)(param_2 + 0x43) + '\x01';
        *(longlong *)(param_2 + 0xb8) = *(longlong *)(param_2 + 0xb8) + 0x48;
        uVar5 = IofCallDriver(plVar4[7],param_2);
        FUN_00021370(uVar5);
      }
      uVar8 = (ulonglong)uVar5;
      FUN_000121dc();
      goto LAB_0003ad7a;
    }
    uVar7 = FUN_0003aff0(param_1,param_2);
    uVar8 = uVar7 & 0xffffffff;
    if ((-1 < (int)uVar7) && (*(int *)((longlong)plVar4 + 0xc) == 2)) {
      *(int *)((longlong)plVar4 + 0xc) = (int)plVar4[2];
      *(undefined4 *)((longlong)plVar4 + 0x8c) = 1;
      FUN_00011958(param_1,plVar4);
    }
  }
LAB_0003ad3a:
  *(int *)(param_2 + 0x30) = (int)uVar8;
  FUN_00021370((int)uVar8);
  FUN_0002503c();
  FUN_000121dc();
  IofCompleteRequest(param_2,0);
LAB_0003ad7a:
  FUN_0001216c(param_1,(longlong)plVar4);
  return uVar8;
}



/* ===== FUNC FUN_0003adac @ 0003adac ===== */

undefined4 FUN_0003adac(longlong param_1,longlong param_2)

{
  longlong *plVar1;
  longlong lVar2;
  longlong lVar3;
  uint *puVar4;
  undefined4 uVar5;
  longlong *plVar6;
  int *piVar7;
  int iVar8;
  uint uVar9;
  longlong *plVar10;
  longlong lVar11;
  
  lVar2 = *(longlong *)(param_2 + 0xb8);
  lVar3 = *(longlong *)(param_1 + 0x40);
  lVar11 = param_1;
  FUN_0002503c();
  FUN_000121dc();
  FUN_00012134(lVar11,lVar3);
  if (*(int *)(lVar2 + 8) == 0) {
    ExAcquireFastMutex(lVar3 + 0xb8);
    puVar4 = *(uint **)(param_2 + 0x38);
    if (puVar4 == (uint *)0x0) {
      uVar9 = 0;
    }
    else {
      uVar9 = *puVar4;
      if (*(int *)(lVar3 + 0xb0) == 0) {
        ExReleaseFastMutex(lVar3 + 0xb8);
        goto LAB_0003ae44;
      }
    }
    plVar1 = (longlong *)(lVar3 + 0xa0);
    iVar8 = 0;
    plVar6 = (longlong *)*plVar1;
    if (plVar6 == plVar1) {
LAB_0003aeb4:
      KeCancelTimer(lVar3 + 0x3b8);
      KeCancelTimer(lVar3 + 0x438);
      KeCancelTimer(lVar3 + 0xf08);
      KeCancelTimer(lVar3 + 0x538);
      KeCancelTimer(lVar3 + 0x4b8);
    }
    else {
      do {
        if (*(char *)((longlong)plVar6 + 0x11) != '\0') {
          iVar8 = iVar8 + 1;
        }
        plVar6 = (longlong *)*plVar6;
      } while (plVar6 != plVar1);
      if (iVar8 == 0) goto LAB_0003aeb4;
    }
    piVar7 = (int *)ExAllocatePoolWithTag(1,(iVar8 + uVar9) * 8 + 0xf,0x31747345);
    if (piVar7 == (int *)0x0) {
      ExReleaseFastMutex(lVar3 + 0xb8);
      uVar5 = 0xc000009a;
      *(undefined4 *)(param_2 + 0x30) = 0xc000009a;
      IofCompleteRequest(param_2,0);
      goto LAB_0003ae5f;
    }
    if (uVar9 != 0) {
      memcpy(piVar7 + 2,puVar4 + 2,(ulonglong)uVar9 << 3);
    }
    *piVar7 = iVar8 + uVar9;
    plVar6 = (longlong *)*plVar1;
    if (plVar6 != plVar1) {
      plVar10 = (longlong *)(piVar7 + (longlong)(int)uVar9 * 2 + 2);
      do {
        if (*(char *)((longlong)plVar6 + 0x11) == '\0') {
          *(undefined1 *)((longlong)plVar6 + 0x12) = 1;
        }
        else {
          *plVar10 = plVar6[-0xb];
          ObfReferenceObject(plVar6[-0xb]);
          plVar10 = plVar10 + 1;
        }
        plVar6 = (longlong *)*plVar6;
      } while (plVar6 != plVar1);
    }
    FUN_000121dc();
    if (puVar4 != (uint *)0x0) {
      ExFreePoolWithTag(puVar4,0);
    }
    *(int **)(param_2 + 0x38) = piVar7;
    ExReleaseFastMutex(lVar3 + 0xb8);
    *(undefined4 *)(param_2 + 0x30) = 0;
  }
LAB_0003ae44:
  *(char *)(param_2 + 0x43) = *(char *)(param_2 + 0x43) + '\x01';
  *(longlong *)(param_2 + 0xb8) = *(longlong *)(param_2 + 0xb8) + 0x48;
  uVar5 = IofCallDriver(*(undefined8 *)(lVar3 + 0x38),param_2);
LAB_0003ae5f:
  FUN_0001216c(param_1,lVar3);
  return uVar5;
}



/* ===== FUNC FUN_0003aff0 @ 0003aff0 ===== */

ulonglong FUN_0003aff0(longlong param_1,longlong param_2)

{
  longlong lVar1;
  void *_Src;
  longlong lVar2;
  ulonglong uVar3;
  undefined1 local_28 [32];
  
  lVar1 = *(longlong *)(param_1 + 0x40);
  FUN_000121dc();
  KeInitializeEvent(local_28,0,0);
  _Src = *(void **)(param_2 + 0xb8);
  memcpy((void *)((longlong)_Src + -0x48),_Src,0x38);
  *(undefined1 *)((longlong)_Src + -0x45) = 0;
  lVar2 = *(longlong *)(param_2 + 0xb8);
  *(undefined1 *)(lVar2 + -0x45) = 0xe0;
  *(code **)(lVar2 + -0x10) = FUN_00012ff0;
  *(undefined1 **)(lVar2 + -8) = local_28;
  uVar3 = IofCallDriver(*(undefined8 *)(lVar1 + 0x38),param_2);
  if ((int)uVar3 == 0x103) {
    KeWaitForSingleObject(local_28,0,0,0,0);
    uVar3 = (ulonglong)*(uint *)(param_2 + 0x30);
  }
  return uVar3;
}



/* ===== FUNC FUN_0003b0ac @ 0003b0ac ===== */

undefined8 FUN_0003b0ac(undefined8 param_1,longlong param_2)

{
  longlong *plVar1;
  int iVar2;
  longlong *plVar3;
  longlong lVar4;
  undefined8 local_res10;
  
  if (*(longlong *)(param_2 + 0x30) != 0) {
    ExFreePoolWithTag(*(longlong *)(param_2 + 0x30),0);
    *(undefined8 *)(param_2 + 0x30) = 0;
  }
  if (*(longlong *)(param_2 + 0x118) != 0) {
    ExFreePoolWithTag(*(longlong *)(param_2 + 0x118),0);
    *(undefined8 *)(param_2 + 0x118) = 0;
  }
  if (*(longlong *)(param_2 + 0x120) != 0) {
    ExFreePoolWithTag(*(longlong *)(param_2 + 0x120),0);
    *(undefined8 *)(param_2 + 0x120) = 0;
  }
  if (*(longlong *)(param_2 + 0x128) != 0) {
    ExFreePoolWithTag(*(longlong *)(param_2 + 0x128),0);
    *(undefined8 *)(param_2 + 0x128) = 0;
  }
  if (*(longlong *)(param_2 + 0x110) != 0) {
    ExFreePoolWithTag(*(longlong *)(param_2 + 0x110),0);
    *(undefined8 *)(param_2 + 0x110) = 0;
  }
  plVar3 = (longlong *)(param_2 + 0x88);
  lVar4 = 0x10;
  do {
    if (*plVar3 != 0) {
      ExFreePoolWithTag(*plVar3,0);
      *plVar3 = 0;
    }
    plVar3 = plVar3 + 1;
    lVar4 = lVar4 + -1;
  } while (lVar4 != 0);
  plVar3 = (longlong *)(param_2 + 0x48);
  while ((longlong *)*plVar3 != plVar3) {
    plVar1 = (longlong *)*plVar3;
    lVar4 = *plVar1;
    *plVar3 = lVar4;
    *(longlong **)(lVar4 + 8) = plVar3;
    if (plVar1 + -4 != (longlong *)0x0) {
      local_res10 = 0xfffffffffeced300;
      iVar2 = KeWaitForSingleObject(plVar1 + 2,0,0,0,&local_res10);
      if (iVar2 == 0) {
        while ((longlong *)plVar1[0xe] != plVar1 + 0xe) {
          lVar4 = IoCsqRemoveNextIrp(plVar1 + 6,0);
          if (lVar4 != 0) {
            *(undefined4 *)(*(longlong *)(*(longlong *)(lVar4 + 0xb8) + 8) + 4) = 0xc0007000;
            FUN_00017594(lVar4,-0x3fffff63);
          }
        }
        *(undefined1 *)((longlong)plVar1 + -4) = 0;
      }
      KeSetEvent(plVar1 + 2,0);
    }
    ExFreePoolWithTag(plVar1 + -4);
  }
  FUN_000121dc();
  IoDeleteDevice(param_1);
  return 0;
}



/* ===== FUNC FUN_0003b26c @ 0003b26c ===== */

void FUN_0003b26c(longlong *param_1,longlong param_2)

{
  longlong lVar1;
  uint uVar2;
  longlong lVar3;
  longlong *plVar4;
  longlong *plVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  longlong *plVar9;
  char *pcVar10;
  byte bVar11;
  char *pcVar12;
  uint *puVar13;
  longlong *plVar14;
  uint uVar15;
  uint uVar16;
  char cVar17;
  uint uVar18;
  uint uVar19;
  longlong *plVar20;
  uint uVar21;
  longlong *plVar22;
  longlong *local_res8;
  char local_res10;
  undefined8 in_stack_ffffffffffffff70;
  undefined4 uVar24;
  ulonglong uVar23;
  uint uVar25;
  
  uVar24 = (undefined4)((ulonglong)in_stack_ffffffffffffff70 >> 0x20);
  lVar3 = param_1[8];
  cVar17 = '\0';
  local_res10 = '\0';
  local_res8 = param_1;
  FUN_000121dc();
  plVar5 = local_res8;
  uVar2 = *(uint *)(param_2 + 2);
  uVar25 = *(uint *)(param_2 + 6);
  pcVar10 = "FALSE";
  uVar15 = uVar25 & 0xff;
  pcVar12 = "FALSE";
  uVar21 = uVar2 & 0xff;
  if (*(char *)(param_2 + 0xc) != cVar17) {
    pcVar12 = "TRUE";
  }
  if (*(char *)(param_2 + 0xb) != cVar17) {
    pcVar10 = "TRUE";
  }
  uVar8 = (uint)*(byte *)(param_2 + 10);
  uVar18 = uVar25 >> 8 & 0xff;
  uVar19 = uVar25 >> 0x18;
  uVar16 = uVar25 >> 0x10 & 0xff;
  uVar7 = uVar2 >> 8 & 0xff;
  uVar23 = CONCAT44(uVar24,uVar2 >> 0x10) & 0xffffffff000000ff;
  FUN_000121dc();
  FUN_00015780(*(int *)(lVar3 + 0x18));
  FUN_000121dc();
  if ((DAT_00037820 == 0x6000000) && (*(int *)(lVar3 + 0x18) != 1)) {
    FUN_0001216c(plVar5,lVar3);
    KeWaitForSingleObject
              (lVar3 + 4000,0,0,0,0,uVar23,uVar7,uVar21,uVar25,uVar19,uVar16,uVar18,uVar15,uVar8,
               pcVar10,pcVar12);
    FUN_00012134(plVar5,lVar3);
  }
  cVar17 = *(char *)(param_2 + 0xb);
  lVar1 = lVar3 + 0xb8;
  ExAcquireFastMutex(lVar1);
  if (cVar17 == '\0') {
    FUN_000121dc();
  }
  else {
    FUN_000121dc();
  }
  if (*(int *)(lVar3 + 0xb0) == 0) {
    FUN_000121dc();
    ExReleaseFastMutex(lVar1);
  }
  else {
    plVar22 = (longlong *)(lVar3 + 0xa0);
    plVar14 = (longlong *)*plVar22;
    if (plVar14 == plVar22) {
      plVar9 = local_res8;
    }
    else {
      do {
        plVar9 = plVar14 + -0xb;
        plVar20 = plVar14;
        FUN_0002503c();
        FUN_000121dc();
        if ((((*(char *)(param_2 + 10) == *(char *)((longlong)plVar14 + -0x34)) &&
             (*(int *)(param_2 + 2) == (int)plVar14[-4])) &&
            (*(char *)((longlong)plVar14 + 0x11) == '\x01')) &&
           (((iVar6 = *(int *)((longlong)plVar14 + -0x4c), iVar6 == 1 || (iVar6 == 0)) ||
            (iVar6 == 3)))) {
          FUN_000121dc();
          *(undefined1 *)((longlong)plVar14 + 0x11) = 0;
          *(undefined1 *)((ulonglong)*(byte *)(param_2 + 10) * 0x268 + 0x1014 + lVar3) = 0;
          local_res10 = '\x01';
          *(undefined1 *)((ulonglong)*(byte *)(param_2 + 10) * 0x268 + 0x101c + lVar3) = 0;
          break;
        }
        plVar14 = (longlong *)*plVar20;
      } while (plVar14 != plVar22);
    }
    ExReleaseFastMutex(lVar1);
    if (local_res10 == '\0') {
      FUN_000121dc();
    }
    else {
      FUN_0001210c();
      iVar6 = FUN_0003d4f0(plVar5,*(longlong *)
                                   (lVar3 + 0x1e68 + (ulonglong)*(byte *)(param_2 + 10) * 0x30),1,0,
                           0);
      FUN_00021370(iVar6);
      FUN_000121dc();
      if (*(char *)((longlong)plVar9 + 0x6d) == '\x01') {
        iVar6 = FUN_00014db0((longlong)plVar5,*(byte *)((longlong)plVar9 + 0x24),
                             (-(*(char *)(param_2 + 0xc) != '\0') & 0x12U) + 0xc);
        *(undefined1 *)((longlong)plVar9 + 0x6d) = 0;
        FUN_00021370(iVar6);
        FUN_000121dc();
      }
      local_res8 = (longlong *)0xffffffffa697d100;
      iVar6 = KeWaitForSingleObject
                        ((ulonglong)*(byte *)(param_2 + 10) * 0x268 + 0x10a8 + lVar3,0,0,0,
                         &local_res8);
      FUN_00021370(iVar6);
      FUN_000121dc();
      FUN_0001f89c(lVar3);
      FUN_000203a0(lVar3);
      bVar11 = 0;
      pcVar10 = (char *)(lVar3 + 0xaa0);
      do {
        if (*(char *)(param_2 + 10) == *pcVar10) {
          FUN_00020b10(lVar3,bVar11);
        }
        bVar11 = bVar11 + 1;
        pcVar10 = pcVar10 + 0xf8;
      } while (bVar11 < 4);
      bVar11 = 0;
      puVar13 = (uint *)(lVar3 + 0x308);
      do {
        if (*(char *)(param_2 + 10) == (char)puVar13[-0x10]) {
          FUN_00021298((longlong)plVar5,*(char *)(param_2 + 10),*(byte *)((longlong)puVar13 + -0x3f)
                      );
          if (*puVar13 < *(uint *)(lVar3 + 0x2070)) {
            *(uint *)(lVar3 + 0x2070) = *(uint *)(lVar3 + 0x2070) - *puVar13;
          }
          else {
            *(undefined4 *)(lVar3 + 0x2070) = 0;
          }
          FUN_000210d4((longlong)plVar5,bVar11);
        }
        bVar11 = bVar11 + 1;
        puVar13 = puVar13 + 0x12;
      } while (bVar11 < 3);
      iVar6 = FUN_00014bec(plVar5,lVar3 + 0x1e48 + (ulonglong)*(byte *)(param_2 + 10) * 0x30);
      FUN_00021370(iVar6);
      FUN_000121dc();
      FUN_000145ec((longlong)plVar5,'\0',*(undefined1 *)(param_2 + 10),0xff);
      plVar22 = (longlong *)(lVar3 + 0xef8);
      if ((longlong *)*plVar22 != plVar22) {
        for (plVar14 = (longlong *)*plVar22; plVar14 != plVar22; plVar14 = (longlong *)*plVar14) {
          plVar20 = plVar14 + -1;
          if ((plVar20 != (longlong *)0x0) && (*(char *)((longlong)plVar9 + 0x24) == (char)*plVar20)
             ) {
            plVar4 = (longlong *)plVar14[1];
            lVar1 = *plVar14;
            *plVar4 = lVar1;
            *(longlong **)(lVar1 + 8) = plVar4;
            FUN_00014778((longlong)plVar20);
          }
        }
      }
      if (*(char *)(param_2 + 0xb) == '\x01') {
        FUN_000121dc();
      }
      else {
        FUN_000121dc();
      }
      IoInvalidateDeviceRelations(*(undefined8 *)(lVar3 + 0x30),0);
      FUN_00014a38((longlong)plVar5);
      LOCK();
      *(undefined4 *)((ulonglong)*(byte *)(param_2 + 10) * 0x268 + 0x1040 + lVar3) = 0;
      UNLOCK();
      FUN_000121dc();
      *(undefined1 *)((ulonglong)*(byte *)(param_2 + 10) * 0x268 + 0x1014 + lVar3) = 0;
      *(undefined1 *)((ulonglong)*(byte *)(param_2 + 10) * 0x268 + 0x101c + lVar3) = 0;
      local_res8 = (longlong *)0xffffffffee1e5d00;
      iVar6 = KeWaitForSingleObject
                        ((ulonglong)*(byte *)(param_2 + 10) * 0x268 + 0xfe0 + lVar3,0,0,0,
                         &local_res8);
      if (iVar6 == 0) {
        FUN_000121dc();
      }
      else if (iVar6 == 0x102) {
        FUN_000121dc();
        *(undefined4 *)((ulonglong)*(byte *)(param_2 + 10) * 0x268 + 0xfd8 + lVar3) = 0;
      }
      else {
        FUN_000121dc();
        *(undefined4 *)((ulonglong)*(byte *)(param_2 + 10) * 0x268 + 0xfd8 + lVar3) = 0;
      }
    }
  }
  FUN_000121dc();
  return;
}



/* ===== FUNC FUN_0003b924 @ 0003b924 ===== */

int FUN_0003b924(longlong param_1,longlong param_2)

{
  int iVar1;
  longlong lVar2;
  
  lVar2 = FUN_000121dc();
  if (*(int *)(*(longlong *)(param_1 + 0x40) + 0xc) == 6) {
    PoStartNextPowerIrp(param_2);
    *(undefined4 *)(param_2 + 0x30) = 0xc000000e;
    IofCompleteRequest(param_2,0);
    iVar1 = -0x3ffffff2;
  }
  else if (*(char *)(*(longlong *)(param_1 + 0x40) + 8) == '\0') {
    iVar1 = FUN_00015094(lVar2,param_2);
  }
  else {
    iVar1 = FUN_0003b994(lVar2,param_2);
  }
  return iVar1;
}



/* ===== FUNC FUN_0003b994 @ 0003b994 ===== */

int FUN_0003b994(longlong param_1,longlong param_2)

{
  char cVar1;
  int iVar2;
  longlong lVar3;
  int iVar4;
  int iVar5;
  undefined8 uVar6;
  longlong lVar7;
  
  lVar7 = *(longlong *)(param_2 + 0xb8);
  lVar3 = *(longlong *)(param_1 + 0x40);
  iVar5 = 0;
  iVar4 = *(int *)(lVar7 + 0x10);
  iVar2 = *(int *)(lVar7 + 0x18);
  if (iVar4 == 0) {
    FUN_00015780(iVar2);
  }
  else {
    FUN_000157f4(iVar2);
  }
  FUN_00015850(*(int *)(lVar7 + 0x20));
  FUN_000157f4(*(int *)(lVar3 + 0x1c));
  FUN_00015780(*(int *)(lVar3 + 0x18));
  FUN_0001573c(*(char *)(lVar7 + 1));
  FUN_000121dc();
  FUN_00012134(param_1,lVar3);
  if (*(int *)(lVar3 + 0xc) == 6) {
    PoStartNextPowerIrp(param_2);
    iVar4 = -0x3ffffff2;
    *(undefined4 *)(param_2 + 0x30) = 0xc000000e;
    IofCompleteRequest(param_2,0);
  }
  else {
    if (*(int *)(lVar3 + 0xc) != 0) {
      cVar1 = *(char *)(lVar7 + 1);
      if (cVar1 == '\0') {
        uVar6 = FUN_0003c66c(param_1,param_2);
        return (int)uVar6;
      }
      if (cVar1 == '\x02') {
        if (iVar4 == 0) {
          if (iVar2 == 1) {
            KeSetEvent(lVar3 + 4000,0,0);
          }
          else {
            KeClearEvent(lVar3 + 4000);
            FUN_0001561c(param_1);
          }
        }
        FUN_000121dc();
        if (*(int *)(*(longlong *)(param_2 + 0xb8) + 0x10) != 0) {
          iVar4 = FUN_0003bd28(param_1,param_2);
          return iVar4;
        }
      }
      else {
        if (cVar1 != '\x03') {
          iVar4 = FUN_0003bc0c(param_1,param_2);
          goto LAB_0003baea;
        }
        FUN_000121dc();
        if (*(int *)(*(longlong *)(param_2 + 0xb8) + 0x10) != 0) {
          lVar7 = FUN_000121dc();
          if (*(int *)(lVar7 + 0x18) != 1) {
            uVar6 = FUN_00015548(param_1,param_2,1,FUN_0003be74);
            iVar5 = (int)uVar6;
            if (iVar5 == 0x103) {
              return 0x103;
            }
          }
          iVar4 = FUN_000154b4(param_1,param_2,1,iVar5);
          return iVar4;
        }
      }
      uVar6 = FUN_0003bc68(param_1,param_2);
      return (int)uVar6;
    }
    PoStartNextPowerIrp(param_2);
    *(char *)(param_2 + 0x43) = *(char *)(param_2 + 0x43) + '\x01';
    *(longlong *)(param_2 + 0xb8) = *(longlong *)(param_2 + 0xb8) + 0x48;
    iVar4 = PoCallDriver(*(undefined8 *)(lVar3 + 0x38),param_2);
  }
LAB_0003baea:
  FUN_0001216c(param_1,lVar3);
  return iVar4;
}



/* ===== FUNC FUN_0003bc0c @ 0003bc0c ===== */

void FUN_0003bc0c(longlong param_1,longlong param_2)

{
  FUN_000121dc();
  PoStartNextPowerIrp(param_2);
  *(char *)(param_2 + 0x43) = *(char *)(param_2 + 0x43) + '\x01';
  *(longlong *)(param_2 + 0xb8) = *(longlong *)(param_2 + 0xb8) + 0x48;
                    /* WARNING: Could not recover jumptable at 0x0003bc5a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  PoCallDriver(*(undefined8 *)(*(longlong *)(param_1 + 0x40) + 0x38),param_2);
  return;
}



/* ===== FUNC FUN_0003bc68 @ 0003bc68 ===== */

undefined8 FUN_0003bc68(longlong param_1,longlong param_2)

{
  byte *pbVar1;
  int iVar2;
  longlong lVar3;
  void *_Src;
  longlong lVar4;
  char cVar5;
  
  lVar3 = *(longlong *)(param_1 + 0x40);
  cVar5 = '\x02';
  lVar4 = FUN_000121dc();
  if (*(char *)(lVar4 + 1) == cVar5) {
    iVar2 = *(int *)(lVar4 + 0x18);
    *(int *)(lVar3 + 0x18) = iVar2;
    FUN_00015780(iVar2);
    FUN_000121dc();
  }
  pbVar1 = (byte *)(*(longlong *)(param_2 + 0xb8) + 3);
  *pbVar1 = *pbVar1 | 1;
  _Src = *(void **)(param_2 + 0xb8);
  memcpy((void *)((longlong)_Src + -0x48),_Src,0x38);
  *(undefined1 *)((longlong)_Src + -0x45) = 0;
  lVar4 = *(longlong *)(param_2 + 0xb8);
  *(undefined8 *)(lVar4 + -8) = 0;
  *(undefined1 *)(lVar4 + -0x45) = 0xe0;
  *(code **)(lVar4 + -0x10) = FUN_000151ec;
  PoCallDriver(*(undefined8 *)(lVar3 + 0x38),param_2);
  return 0x103;
}



/* ===== FUNC FUN_0003bd28 @ 0003bd28 ===== */

int FUN_0003bd28(longlong param_1,longlong param_2)

{
  byte *pbVar1;
  longlong lVar2;
  void *_Src;
  longlong lVar3;
  int iVar4;
  undefined8 uVar5;
  char cVar6;
  
  lVar2 = *(longlong *)(param_1 + 0x40);
  iVar4 = *(int *)(*(longlong *)(param_2 + 0xb8) + 0x18);
  cVar6 = '\x02';
  FUN_000121dc();
  if (((*(longlong *)(lVar2 + 0x1c8) != 0) &&
      (*(char *)(*(longlong *)(*(longlong *)(lVar2 + 0x1c8) + 0xb8) + 1) == cVar6)) && (iVar4 == 1))
  {
    FUN_000121dc();
    *(undefined4 *)(*(longlong *)(lVar2 + 0x1c8) + 0x30) = 0;
    PoStartNextPowerIrp(*(undefined8 *)(lVar2 + 0x1c8));
    IofCompleteRequest(*(undefined8 *)(lVar2 + 0x1c8),0);
    *(undefined8 *)(lVar2 + 0x1c8) = 0;
    FUN_0001216c(param_1,lVar2);
  }
  if (iVar4 < *(int *)(lVar2 + 0x1c)) {
    pbVar1 = (byte *)(*(longlong *)(param_2 + 0xb8) + 3);
    *pbVar1 = *pbVar1 | 1;
    _Src = *(void **)(param_2 + 0xb8);
    memcpy((void *)((longlong)_Src + -0x48),_Src,0x38);
    *(undefined1 *)((longlong)_Src + -0x45) = 0;
    lVar3 = *(longlong *)(param_2 + 0xb8);
    *(undefined8 *)(lVar3 + -8) = 0;
    *(undefined1 *)(lVar3 + -0x45) = 0xe0;
    *(code **)(lVar3 + -0x10) = FUN_0001541c;
    PoCallDriver(*(undefined8 *)(lVar2 + 0x38),param_2);
    iVar4 = 0x103;
  }
  else {
    uVar5 = FUN_00015548(param_1,param_2,1,FUN_0003bfd8);
    iVar4 = 0x103;
    if ((int)uVar5 != 0x103) {
      iVar4 = FUN_000154b4(param_1,param_2,1,(int)uVar5);
    }
  }
  return iVar4;
}



/* ===== FUNC FUN_0003be74 @ 0003be74 ===== */

void FUN_0003be74(longlong param_1,longlong param_2,uint param_3)

{
  undefined8 uVar1;
  uint uVar2;
  
  uVar2 = 2;
  FUN_000121dc();
  uVar1 = FUN_0003bf20(param_1,(ulonglong)uVar2,'\x01');
  FUN_000154b4(param_1,param_2,(ulonglong)param_3,(int)uVar1);
  return;
}



/* ===== FUNC FUN_0003bed4 @ 0003bed4 ===== */

void FUN_0003bed4(undefined8 param_1,undefined8 *param_2)

{
  FUN_000121dc();
  (*(code *)param_2[3])(*param_2,param_2[1],*(undefined4 *)(param_2 + 2));
  IoFreeWorkItem(param_2[4]);
                    /* WARNING: Could not recover jumptable at 0x0003bf13. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ExFreePoolWithTag(param_2,0);
  return;
}



/* ===== FUNC FUN_0003bf20 @ 0003bf20 ===== */

undefined8 FUN_0003bf20(longlong param_1,undefined8 param_2,char param_3)

{
  longlong lVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = 2;
  lVar1 = param_1;
  FUN_000121dc();
  lVar1 = *(longlong *)(lVar1 + 0x40);
  iVar3 = 2;
  *(undefined4 *)(lVar1 + 0x8c) = 0;
  do {
    FUN_0001216c(param_1,lVar1);
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  KeWaitForSingleObject(lVar1 + 0x110,0,0,0,0);
  if (param_3 != '\0') {
    FUN_000121dc();
  }
  do {
    FUN_00012134(param_1,lVar1);
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return 0;
}



/* ===== FUNC FUN_0003bfd8 @ 0003bfd8 ===== */

void FUN_0003bfd8(longlong param_1,longlong param_2,uint param_3)

{
  int iVar1;
  int iVar2;
  longlong *plVar3;
  undefined8 uVar4;
  int iVar5;
  ulonglong uVar6;
  
  plVar3 = *(longlong **)(param_1 + 0x40);
  iVar5 = 0;
  uVar6 = 2;
  FUN_000121dc();
  iVar1 = *(int *)((longlong)plVar3 + 0x1c);
  iVar2 = *(int *)(*(longlong *)(param_2 + 0xb8) + 0x18);
  *(int *)((longlong)plVar3 + 0x1c) = iVar2;
  FUN_000157f4(iVar2);
  FUN_000121dc();
  if (iVar2 == iVar1) {
    if (iVar2 == 1) {
      *(undefined4 *)((longlong)plVar3 + 0x8c) = 1;
      FUN_00011958(param_1,plVar3);
    }
    iVar5 = 0;
  }
  else {
    if (iVar1 == 1) {
      uVar4 = FUN_0003bf20(param_1,uVar6 & 0xffffffff,'\0');
      iVar5 = (int)uVar4;
    }
    if ((iVar1 < iVar2) || (iVar2 < iVar1)) {
      PoSetPowerState(param_1,1,iVar2);
      iVar5 = 0;
    }
    if (iVar2 == 1) {
      *(undefined4 *)((longlong)plVar3 + 0x8c) = 1;
      FUN_00011958(param_1,plVar3);
    }
  }
  FUN_000154b4(param_1,param_2,(ulonglong)param_3,iVar5);
  return;
}



/* ===== FUNC FUN_0003c0e8 @ 0003c0e8 ===== */

void FUN_0003c0e8(undefined8 param_1,undefined8 *param_2)

{
  undefined4 uVar1;
  int iVar2;
  
  iVar2 = 2;
  FUN_000121dc();
  param_2[0x2c] = 0;
  param_2[0x27] = &PTR_DAT_000377c0;
  *(int *)(param_2 + 0x26) = iVar2;
  param_2[0x28] = FUN_0003c610;
  param_2[0x29] = FUN_0003c4c4;
  param_2[0x2a] = FUN_0003c3e0;
  param_2[0x2b] = FUN_0003c2ec;
  param_2[0x2d] = FUN_000158ac;
  IoWMIRegistrationControl(*param_2,iVar2 + -1);
  uVar1 = DAT_00037808;
  *(undefined4 *)(param_2 + 0x2f) = 0;
  *(undefined4 *)(param_2 + 0x30) = uVar1;
  *(undefined4 *)(param_2 + 0x2e) = 3;
  *(undefined4 *)((longlong)param_2 + 0x174) = 2000;
  *(undefined4 *)((longlong)param_2 + 0x17c) = 5;
  return;
}



/* ===== FUNC FUN_0003c1b0 @ 0003c1b0 ===== */

undefined4 FUN_0003c1b0(longlong param_1,longlong param_2)

{
  undefined4 uVar1;
  char *pcVar2;
  longlong lVar3;
  longlong lVar4;
  int local_res8 [2];
  
  lVar4 = *(longlong *)(param_2 + 0xb8);
  lVar3 = *(longlong *)(param_1 + 0x40);
  pcVar2 = FUN_00015b44(*(byte *)(lVar4 + 1));
  FUN_000121dc();
  if (*(char *)(lVar3 + 8) == '\0') {
    FUN_00021370(*(int *)(param_2 + 0x30));
    FUN_00015b44(*(byte *)(lVar4 + 1));
    FUN_000121dc();
    uVar1 = *(undefined4 *)(param_2 + 0x30);
    IofCompleteRequest(param_2,0);
    return uVar1;
  }
  lVar4 = *(longlong *)(param_1 + 0x40);
  FUN_00012134(param_1,lVar4);
  if (*(int *)(lVar4 + 0xc) == 6) {
    uVar1 = 0xc000000e;
    *(undefined4 *)(param_2 + 0x30) = 0xc000000e;
  }
  else {
    uVar1 = WmiSystemControl(lVar4 + 0x130,param_1,param_2,local_res8,pcVar2);
    if (local_res8[0] == 0) goto LAB_0003c27e;
    if (local_res8[0] != 1) {
      *(char *)(param_2 + 0x43) = *(char *)(param_2 + 0x43) + '\x01';
      *(longlong *)(param_2 + 0xb8) = *(longlong *)(param_2 + 0xb8) + 0x48;
      uVar1 = IofCallDriver(*(undefined8 *)(lVar4 + 0x38),param_2);
      goto LAB_0003c27e;
    }
  }
  IofCompleteRequest(param_2,0);
LAB_0003c27e:
  FUN_0001216c(param_1,lVar4);
  return uVar1;
}



/* ===== FUNC FUN_0003c2ec @ 0003c2ec ===== */

void FUN_0003c2ec(longlong param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                 int param_5,uint param_6,byte *param_7)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  longlong lVar4;
  undefined4 uVar5;
  undefined8 uVar6;
  
  uVar5 = 0;
  iVar3 = 2;
  lVar4 = param_1;
  iVar2 = FUN_000121dc();
  lVar4 = *(longlong *)(lVar4 + 0x40);
  if (iVar2 == 0) {
    if (param_5 != 5) {
      uVar6 = 0xc00002c6;
      goto LAB_0003c3aa;
    }
    uVar5 = 4;
    if (param_6 < 4) goto LAB_0003c384;
    DAT_00037808 = *(undefined4 *)param_7;
    *(undefined4 *)(lVar4 + 0x180) = DAT_00037808;
  }
  else {
    if (iVar2 != iVar3) {
      uVar6 = 0xc0000295;
      goto LAB_0003c3aa;
    }
    uVar5 = 1;
    if (param_6 == 0) {
LAB_0003c384:
      uVar6 = 0xc0000023;
      goto LAB_0003c3aa;
    }
    bVar1 = *param_7;
    FUN_0003ca28(param_1,lVar4,bVar1);
    if (bVar1 == 1) {
      FUN_0003c754(param_1,lVar4,'\0');
    }
    else {
      FUN_0003c880(param_1,lVar4,'\0');
    }
  }
  uVar6 = 0;
LAB_0003c3aa:
  WmiCompleteRequest(param_1,param_2,uVar6,uVar5,0);
  return;
}



/* ===== FUNC FUN_0003c3e0 @ 0003c3e0 ===== */

void FUN_0003c3e0(longlong param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                 uint param_5,byte *param_6)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  longlong lVar4;
  undefined4 uVar5;
  undefined8 uVar6;
  
  uVar5 = 0;
  iVar3 = 2;
  lVar4 = param_1;
  iVar2 = FUN_000121dc();
  lVar4 = *(longlong *)(lVar4 + 0x40);
  if (iVar2 == 0) {
    uVar5 = 0x14;
    if (param_5 < 0x14) {
LAB_0003c471:
      uVar6 = 0xc0000023;
      goto LAB_0003c490;
    }
    DAT_00037808 = *(undefined4 *)(param_6 + 0x10);
    *(undefined4 *)(lVar4 + 0x180) = DAT_00037808;
  }
  else {
    if (iVar2 != iVar3) {
      uVar6 = 0xc0000295;
      goto LAB_0003c490;
    }
    uVar5 = 1;
    if (param_5 == 0) goto LAB_0003c471;
    bVar1 = *param_6;
    FUN_0003ca28(param_1,lVar4,bVar1);
    if (bVar1 == 1) {
      FUN_0003c754(param_1,lVar4,'\0');
    }
    else {
      FUN_0003c880(param_1,lVar4,'\0');
    }
  }
  uVar6 = 0;
LAB_0003c490:
  WmiCompleteRequest(param_1,param_2,uVar6,uVar5,0);
  return;
}



/* ===== FUNC FUN_0003c4c4 @ 0003c4c4 ===== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0003c4c4(longlong param_1,undefined8 param_2,int param_3,undefined8 param_4,
                 undefined8 param_5,uint *param_6,uint param_7,void *param_8)

{
  wchar_t wVar1;
  ushort uVar2;
  bool bVar3;
  int iVar4;
  longlong lVar5;
  uint uVar6;
  wchar_t *pwVar7;
  undefined8 uVar8;
  undefined1 auStack_88 [32];
  undefined1 local_68;
  wchar_t local_58 [4];
  wchar_t local_50 [4];
  undefined8 local_48;
  undefined2 local_40;
  ulonglong local_38;
  
  local_38 = DAT_00037100 ^ (ulonglong)auStack_88;
  local_58 = (wchar_t  [4])u_EST_SERVER_000409c0._0_8_;
  uVar6 = 0;
  local_50 = (wchar_t  [4])u_EST_SERVER_000409c0._8_8_;
  local_48 = ram0x000409d0;
  local_40 = DAT_000409d8;
  lVar5 = -1;
  pwVar7 = local_58;
  do {
    if (lVar5 == 0) break;
    lVar5 = lVar5 + -1;
    wVar1 = *pwVar7;
    pwVar7 = pwVar7 + 1;
  } while (wVar1 != L'\0');
  iVar4 = 2;
  uVar2 = ~(ushort)lVar5 * 2;
  FUN_000121dc();
  if (param_3 == 0) {
    uVar6 = uVar2 + 0x16;
    if (param_7 < uVar6) {
LAB_0003c59b:
      uVar8 = 0xc0000023;
      goto LAB_0003c5d5;
    }
    memcpy(param_8,(void *)(*(longlong *)(param_1 + 0x40) + 0x170),0x14);
    *(ushort *)((longlong)param_8 + 0x14) = uVar2;
    memcpy((void *)((longlong)param_8 + 0x16),local_58,(ulonglong)uVar2);
  }
  else {
    if (param_3 != iVar4) {
      uVar8 = 0xc0000295;
      goto LAB_0003c5d5;
    }
    uVar6 = 1;
    if (param_7 == 0) goto LAB_0003c59b;
    bVar3 = FUN_0003cac4();
    *(bool *)param_8 = bVar3;
  }
  uVar8 = 0;
  *param_6 = uVar6;
LAB_0003c5d5:
  local_68 = 0;
  WmiCompleteRequest(param_1,param_2,uVar8,uVar6);
  FUN_00025050(local_38 ^ (ulonglong)auStack_88);
  return;
}



/* ===== FUNC FUN_0003c610 @ 0003c610 ===== */

undefined8
FUN_0003c610(longlong param_1,undefined8 param_2,undefined8 param_3,undefined8 *param_4,
            undefined8 param_5,undefined8 *param_6)

{
  longlong lVar1;
  undefined4 *puVar2;
  
  puVar2 = (undefined4 *)FUN_000121dc();
  lVar1 = *(longlong *)(param_1 + 0x40);
  *puVar2 = 0x20;
  *param_4 = &DAT_00037870;
  *param_6 = *(undefined8 *)(lVar1 + 0x30);
  RtlInitUnicodeString(param_5,&LAB_00040a20);
  return 0;
}



/* ===== FUNC FUN_0003c66c @ 0003c66c ===== */

undefined8 FUN_0003c66c(longlong param_1,longlong param_2)

{
  byte *pbVar1;
  int iVar2;
  void *_Src;
  longlong lVar3;
  int iVar4;
  longlong lVar5;
  undefined8 uVar6;
  
  lVar5 = param_1;
  iVar4 = FUN_000121dc();
  lVar5 = *(longlong *)(lVar5 + 0x40);
  *(longlong *)(lVar5 + 0x1d8) = param_2;
  LOCK();
  iVar2 = *(int *)(lVar5 + 0x1d4);
  if (iVar4 == iVar2) {
    *(int *)(lVar5 + 0x1d4) = iVar4 + 2;
  }
  else {
    iVar4 = iVar2;
  }
  UNLOCK();
  if (iVar4 == 3) {
    *(undefined4 *)(lVar5 + 0x1d4) = 7;
    uVar6 = 0xc0000120;
    *(undefined4 *)(param_2 + 0x30) = 0xc0000120;
    IofCompleteRequest(param_2,0);
  }
  else {
    pbVar1 = (byte *)(*(longlong *)(param_2 + 0xb8) + 3);
    *pbVar1 = *pbVar1 | 1;
    _Src = *(void **)(param_2 + 0xb8);
    memcpy((void *)((longlong)_Src + -0x48),_Src,0x38);
    *(undefined1 *)((longlong)_Src + -0x45) = 0;
    lVar3 = *(longlong *)(param_2 + 0xb8);
    *(undefined8 *)(lVar3 + -8) = 0;
    *(undefined1 *)(lVar3 + -0x45) = 0xe0;
    *(code **)(lVar3 + -0x10) = FUN_00015be8;
    PoCallDriver(*(undefined8 *)(lVar5 + 0x38),param_2);
    uVar6 = 0x103;
  }
  FUN_0001216c(param_1,lVar5);
  return uVar6;
}



/* ===== FUNC FUN_0003c754 @ 0003c754 ===== */

bool FUN_0003c754(undefined8 param_1,longlong param_2,char param_3)

{
  bool bVar1;
  int iVar2;
  
  FUN_000121dc();
  KeEnterCriticalRegion();
  KeWaitForSingleObject(param_2 + 0x1f8,0,0,0,0);
  if (param_3 == '\x01') {
    *(undefined1 *)(param_2 + 0x1d1) = 1;
  }
  if ((*(char *)(param_2 + 0x1d1) == '\x01') && (bVar1 = FUN_0003cac4(), bVar1)) {
    LOCK();
    bVar1 = *(int *)(param_2 + 0x1d4) == 1;
    if (bVar1) {
      *(int *)(param_2 + 0x1d4) = 2;
    }
    UNLOCK();
    if (bVar1) {
      KeClearEvent(param_2 + 0x1e0);
      iVar2 = PoRequestPowerIrp(*(undefined8 *)(param_2 + 0x30),0,*(undefined4 *)(param_2 + 0x1b0),
                                FUN_00015c2c,param_2,0);
      if (iVar2 < 0) {
        *(undefined4 *)(param_2 + 0x1d4) = 1;
        KeSetEvent(param_2 + 0x1e0,0,0);
      }
    }
    else {
      iVar2 = 0;
    }
  }
  else {
    iVar2 = -0x3fffffff;
  }
  KeSetEvent(param_2 + 0x1f8,0,0);
  KeLeaveCriticalRegion();
  return iVar2 == 0x103;
}



/* ===== FUNC FUN_0003c880 @ 0003c880 ===== */

void FUN_0003c880(undefined8 param_1,longlong param_2,char param_3)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  bool bVar5;
  
  FUN_000121dc();
  KeEnterCriticalRegion();
  KeWaitForSingleObject(param_2 + 0x1f8,0,0,0,0);
  if (param_3 == '\x01') {
    *(undefined1 *)(param_2 + 0x1d1) = 0;
  }
  uVar3 = *(uint *)(param_2 + 0x1d4);
  do {
    LOCK();
    uVar1 = *(uint *)(param_2 + 0x1d4);
    bVar5 = uVar3 == uVar1;
    if (bVar5) {
      *(uint *)(param_2 + 0x1d4) = uVar3 | 1;
    }
    else {
      uVar3 = uVar1;
    }
    UNLOCK();
  } while (!bVar5);
  if (uVar3 == 4) {
    FUN_000121dc();
    IoCancelIrp(*(undefined8 *)(param_2 + 0x1d8));
    iVar4 = 5;
    LOCK();
    iVar2 = *(int *)(param_2 + 0x1d4);
    if (iVar2 == 5) {
      *(int *)(param_2 + 0x1d4) = 4;
    }
    else {
      iVar4 = iVar2;
    }
    UNLOCK();
    if (iVar4 == 7) {
      IofCompleteRequest(*(undefined8 *)(param_2 + 0x1d8),0);
    }
  }
  KeWaitForSingleObject(param_2 + 0x1e0,0,0,0,0);
  KeSetEvent(param_2 + 0x1f8,0,0);
                    /* WARNING: Could not recover jumptable at 0x0003c982. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  KeLeaveCriticalRegion();
  return;
}



/* ===== FUNC FUN_0003c990 @ 0003c990 ===== */

void FUN_0003c990(longlong param_1,longlong param_2)

{
  undefined8 uVar1;
  
  uVar1 = FUN_000121dc();
  FUN_0003c754(uVar1,*(longlong *)(param_1 + 0x40),'\0');
  if (param_2 != 0) {
    IoFreeWorkItem(param_2);
  }
  return;
}



/* ===== FUNC FUN_0003c9dc @ 0003c9dc ===== */

void FUN_0003c9dc(longlong param_1,longlong param_2)

{
  undefined8 uVar1;
  
  uVar1 = FUN_000121dc();
  FUN_0003ca28(uVar1,*(longlong *)(param_1 + 0x40),0);
  if (param_2 != 0) {
    IoFreeWorkItem(param_2);
  }
  return;
}



/* ===== FUNC FUN_0003ca28 @ 0003ca28 ===== */

int FUN_0003ca28(undefined8 param_1,longlong param_2,byte param_3)

{
  int iVar1;
  undefined8 local_res10;
  uint local_res18 [4];
  undefined1 local_18 [16];
  
  local_res10 = 0;
  local_res18[0] = (uint)param_3;
  iVar1 = 2;
  FUN_000121dc();
  iVar1 = IoOpenDeviceRegistryKey(*(undefined8 *)(param_2 + 0x30),iVar1 + -1,0x1f0000,&local_res10);
  if (-1 < iVar1) {
    RtlInitUnicodeString(local_18,L"WaitWakeEnabled");
    ZwSetValueKey(local_res10,local_18,0,4,local_res18,4);
    ZwClose(local_res10);
  }
  return iVar1;
}



/* ===== FUNC FUN_0003cac4 @ 0003cac4 ===== */

bool FUN_0003cac4(void)

{
  int iVar1;
  longlong lVar2;
  bool bVar3;
  int local_res10 [2];
  int local_res18 [2];
  undefined8 local_res20;
  undefined1 local_18 [2];
  ushort local_16;
  
  bVar3 = false;
  local_res20 = 0;
  lVar2 = FUN_000121dc();
  iVar1 = IoOpenDeviceRegistryKey(*(undefined8 *)(lVar2 + 0x30),1,0x1f0000,&local_res20);
  if (-1 < iVar1) {
    RtlInitUnicodeString(local_18,L"WaitWakeEnabled");
    local_res10[0] = local_16 + 0x1c;
    lVar2 = ExAllocatePoolWithTag(1,local_res10[0],0x31747345);
    if (lVar2 != 0) {
      iVar1 = ZwQueryValueKey(local_res20,local_18,1,lVar2,local_res10[0],local_res10);
      if (-1 < iVar1) {
        memcpy(local_res18,(void *)((ulonglong)*(uint *)(lVar2 + 8) + lVar2),
               (ulonglong)*(uint *)(lVar2 + 0xc));
        bVar3 = local_res18[0] != 0;
      }
      ExFreePoolWithTag(lVar2,0);
    }
    ZwClose(local_res20);
  }
  return bVar3;
}



/* ===== FUNC FUN_0003cbb8 @ 0003cbb8 ===== */

void FUN_0003cbb8(longlong param_1)

{
  int iVar1;
  undefined1 auStack_238 [32];
  longlong *local_218;
  undefined8 local_210;
  undefined4 local_208;
  undefined4 local_200;
  undefined4 local_1f8;
  undefined1 *local_1f0;
  undefined4 local_1e8;
  longlong local_1d8;
  longlong local_1d0;
  longlong local_1c8;
  longlong local_1c0;
  undefined4 local_1b8 [2];
  undefined8 local_1b0;
  undefined1 *local_1a8;
  undefined4 local_1a0;
  undefined8 local_198;
  undefined8 local_190;
  undefined1 local_188 [16];
  undefined1 local_178 [16];
  undefined1 local_168;
  undefined8 local_167;
  char cStack_15f;
  char cStack_15e;
  char cStack_15d;
  char cStack_15c;
  char cStack_15b;
  char cStack_15a;
  char cStack_159;
  char acStack_158 [9];
  undefined4 local_14f;
  undefined2 local_14b;
  undefined2 local_149;
  undefined8 local_147;
  undefined4 local_13f;
  undefined2 local_13b;
  ulonglong local_18;
  
  local_18 = DAT_00037100 ^ (ulonglong)auStack_238;
  local_168 = 0;
  FUN_000251f0(&local_167,0,0x147);
  RtlInitUnicodeString(local_188,L"\\Device\\Tcp");
  local_1e8 = 0x148;
  local_1a8 = local_188;
  local_167._7_1_ = s_TransportAddress_00040b90[0];
  cStack_15f = s_TransportAddress_00040b90[1];
  cStack_15e = s_TransportAddress_00040b90[2];
  cStack_15d = s_TransportAddress_00040b90[3];
  cStack_15c = s_TransportAddress_00040b90[4];
  cStack_15b = s_TransportAddress_00040b90[5];
  cStack_15a = s_TransportAddress_00040b90[6];
  cStack_159 = s_TransportAddress_00040b90[7];
  acStack_158[0] = s_TransportAddress_00040b90[8];
  acStack_158[1] = s_TransportAddress_00040b90[9];
  acStack_158[2] = s_TransportAddress_00040b90[10];
  acStack_158[3] = s_TransportAddress_00040b90[0xb];
  acStack_158[4] = s_TransportAddress_00040b90[0xc];
  acStack_158[5] = s_TransportAddress_00040b90[0xd];
  acStack_158[6] = s_TransportAddress_00040b90[0xe];
  acStack_158[7] = s_TransportAddress_00040b90[0xf];
  local_147 = 0;
  local_13f = 0;
  local_13b = 0;
  local_1f0 = &local_168;
  local_1f8 = 0;
  local_200 = 3;
  local_208 = 0;
  local_210 = CONCAT44(local_210._4_4_,0x80);
  local_218 = (longlong *)0x0;
  local_1b8[0] = 0x30;
  local_1b0 = 0;
  local_1a0 = 0x240;
  local_198 = 0;
  local_190 = 0;
  local_167._4_1_ = 0x10;
  local_167._5_2_ = 0x2a;
  local_14f = 1;
  local_149 = 2;
  local_14b = 0xe;
  iVar1 = ZwCreateFile(&local_1d8,0x18,local_1b8,local_178);
  if (-1 < iVar1) {
    local_218 = &local_1c8;
    local_210 = 0;
    iVar1 = ObReferenceObjectByHandle(local_1d8,0xc0000000,0,0);
    if (iVar1 < 0) {
      ZwClose(local_1d8);
    }
  }
  if (-1 < iVar1) {
    iVar1 = FUN_000245a4(&local_1c0,&local_1d0);
    if (iVar1 < 0) {
LAB_0003cdb7:
      if (local_1c8 != 0) {
        ObfDereferenceObject();
      }
      if (local_1d8 != 0) {
        ZwClose(local_1d8);
      }
    }
    else {
      iVar1 = FUN_0003cf74(local_1d8,local_1d0);
      if (iVar1 < 0) {
        if (local_1d0 != 0) {
          ObfDereferenceObject();
        }
        if (local_1c0 != 0) {
          ZwClose(local_1c0);
        }
        goto LAB_0003cdb7;
      }
      *(longlong *)(param_1 + 0x18) = local_1c0;
      *(longlong *)(param_1 + 0x10) = local_1d8;
      *(longlong *)(param_1 + 0x28) = local_1d0;
      *(longlong *)(param_1 + 0x20) = local_1c8;
    }
    if (-1 < iVar1) goto LAB_0003cdee;
  }
  *(undefined8 *)(param_1 + 0x18) = 0;
  *(undefined8 *)(param_1 + 0x10) = 0;
  *(undefined8 *)(param_1 + 0x28) = 0;
  *(undefined8 *)(param_1 + 0x20) = 0;
LAB_0003cdee:
  FUN_00025050(local_18 ^ (ulonglong)auStack_238);
  return;
}



/* ===== FUNC FUN_0003ce20 @ 0003ce20 ===== */

void FUN_0003ce20(longlong param_1)

{
  longlong lVar1;
  longlong lVar2;
  int iVar3;
  undefined8 uVar4;
  longlong lVar5;
  undefined4 local_38;
  undefined4 local_34;
  undefined8 local_30;
  undefined1 local_28 [32];
  
  lVar1 = *(longlong *)(param_1 + 0x28);
  local_38 = 0;
  local_34 = 0;
  local_30 = 0;
  KeInitializeEvent(local_28,0,0);
  if (lVar1 != 0) {
    uVar4 = IoGetRelatedDeviceObject(lVar1);
    lVar5 = IoBuildDeviceIoControlRequest(3,uVar4,0,0,0,0,1,local_28,&local_38);
    if (lVar5 != 0) {
      lVar2 = *(longlong *)(lVar5 + 0xb8);
      *(undefined8 *)(lVar2 + -0x10) = 0;
      *(undefined8 *)(lVar2 + -8) = 0;
      *(undefined1 *)(lVar2 + -0x45) = 0;
      lVar2 = *(longlong *)(lVar5 + 0xb8);
      *(undefined1 *)(lVar2 + -0x48) = 0xf;
      *(undefined1 *)(lVar2 + -0x47) = 2;
      *(undefined8 *)(lVar2 + -0x20) = uVar4;
      *(longlong *)(lVar2 + -0x18) = lVar1;
      iVar3 = IofCallDriver(uVar4,lVar5);
      if (iVar3 == 0x103) {
        KeWaitForSingleObject(local_28,0,0,0,0);
      }
    }
  }
  lVar1 = *(longlong *)(param_1 + 0x18);
  if (*(longlong *)(param_1 + 0x28) != 0) {
    ObfDereferenceObject();
  }
  if (lVar1 != 0) {
    ZwClose(lVar1);
  }
  lVar1 = *(longlong *)(param_1 + 0x10);
  if (*(longlong *)(param_1 + 0x20) != 0) {
    ObfDereferenceObject();
  }
  if (lVar1 != 0) {
    ZwClose(lVar1);
  }
  *(undefined8 *)(param_1 + 0x18) = 0;
  *(undefined8 *)(param_1 + 0x10) = 0;
  *(undefined8 *)(param_1 + 0x28) = 0;
  *(undefined8 *)(param_1 + 0x20) = 0;
  return;
}



/* ===== FUNC FUN_0003cf74 @ 0003cf74 ===== */

int FUN_0003cf74(undefined8 param_1,undefined8 param_2)

{
  longlong lVar1;
  int iVar2;
  undefined8 uVar3;
  longlong lVar4;
  int local_38 [4];
  undefined1 local_28 [32];
  
  local_38[0] = 0;
  local_38[1] = 0;
  local_38[2] = 0;
  local_38[3] = 0;
  KeInitializeEvent(local_28,0,0);
  uVar3 = IoGetRelatedDeviceObject(param_2);
  lVar4 = IoBuildDeviceIoControlRequest(3,uVar3,0,0,0,0,1,local_28,local_38);
  iVar2 = -0x3fffff66;
  if (lVar4 != 0) {
    lVar1 = *(longlong *)(lVar4 + 0xb8);
    *(undefined8 *)(lVar1 + -0x10) = 0;
    *(undefined8 *)(lVar1 + -8) = 0;
    *(undefined1 *)(lVar1 + -0x45) = 0;
    lVar4 = *(longlong *)(lVar4 + 0xb8);
    *(undefined1 *)(lVar4 + -0x48) = 0xf;
    *(undefined1 *)(lVar4 + -0x47) = 1;
    *(undefined8 *)(lVar4 + -0x20) = uVar3;
    *(undefined8 *)(lVar4 + -0x18) = param_2;
    *(undefined8 *)(lVar4 + -0x40) = param_1;
    iVar2 = IofCallDriver(uVar3);
    if (iVar2 == 0x103) {
      KeWaitForSingleObject(local_28,0,0,0,0);
      iVar2 = local_38[0];
    }
  }
  return iVar2;
}



/* ===== FUNC FUN_0003d080 @ 0003d080 ===== */

void FUN_0003d080(undefined8 param_1,undefined4 param_2,undefined2 param_3)

{
  longlong lVar1;
  int iVar2;
  undefined8 uVar3;
  longlong lVar4;
  undefined1 auStack_208 [32];
  undefined8 local_1e8;
  undefined4 local_1e0;
  undefined1 local_1d8;
  undefined1 *local_1d0;
  undefined4 *local_1c8;
  undefined8 local_1b8;
  undefined4 local_1b0;
  undefined4 local_1ac;
  undefined8 local_1a8;
  undefined1 local_1a0 [24];
  undefined4 local_188 [2];
  ulonglong local_180 [3];
  undefined4 local_168;
  undefined1 *local_160;
  undefined4 local_158 [2];
  ulonglong local_150 [5];
  undefined1 local_128 [4];
  undefined2 local_124;
  undefined2 local_122;
  undefined2 local_120;
  undefined4 local_11e;
  ulonglong local_28;
  
  local_28 = DAT_00037100 ^ (ulonglong)auStack_208;
  local_1b0 = 0;
  local_188[0] = 0;
  local_1ac = 0;
  local_1a8 = 0;
  FUN_000251f0(local_180,0,0x28);
  local_158[0] = 0;
  FUN_000251f0(local_150,0,0x28);
  local_1b8 = 0;
  local_128 = (undefined1  [4])((uint)local_128 & 0xffffff00);
  FUN_000251f0((ulonglong *)(local_128 + 1),0,0xff);
  KeInitializeEvent(local_1a0,0,0);
  uVar3 = IoGetRelatedDeviceObject(param_1);
  local_1c8 = &local_1b0;
  local_1d0 = local_1a0;
  local_1d8 = 1;
  local_1e0 = 0;
  local_1e8 = 0;
  lVar4 = IoBuildDeviceIoControlRequest(3,uVar3,0);
  if (lVar4 != 0) {
    local_1b8 = 0xffffffff94b62e00;
    local_168 = 0x16;
    local_128 = (undefined1  [4])0x1;
    local_122 = 2;
    local_124 = 0xe;
    local_160 = local_128;
    lVar1 = *(longlong *)(lVar4 + 0xb8);
    *(undefined8 *)(lVar1 + -0x10) = 0;
    *(undefined8 *)(lVar1 + -8) = 0;
    *(undefined1 *)(lVar1 + -0x45) = 0;
    lVar4 = *(longlong *)(lVar4 + 0xb8);
    *(undefined1 *)(lVar4 + -0x48) = 0xf;
    *(undefined1 *)(lVar4 + -0x47) = 3;
    *(undefined8 *)(lVar4 + -0x20) = uVar3;
    *(undefined8 *)(lVar4 + -0x18) = param_1;
    *(undefined4 **)(lVar4 + -0x38) = local_188;
    *(undefined4 **)(lVar4 + -0x30) = local_158;
    *(undefined8 **)(lVar4 + -0x28) = &local_1b8;
    local_120 = param_3;
    local_11e = param_2;
    iVar2 = IofCallDriver(uVar3);
    if (iVar2 == 0x103) {
      local_1e8 = 0;
      KeWaitForSingleObject(local_1a0,0,0,0);
    }
  }
  FUN_00025050(local_28 ^ (ulonglong)auStack_208);
  return;
}



/* ===== FUNC FUN_0003d284 @ 0003d284 ===== */

int FUN_0003d284(longlong param_1,byte param_2,longlong param_3,undefined8 param_4,int param_5,
                uint *param_6)

{
  longlong lVar1;
  longlong lVar2;
  uint uVar3;
  int iVar4;
  undefined8 uVar5;
  longlong lVar6;
  longlong lVar7;
  int local_68 [4];
  undefined1 local_58 [40];
  
  iVar4 = -0x3fffff66;
  lVar1 = *(longlong *)(param_1 + 0x40);
  local_68[0] = 0;
  local_68[1] = 0;
  local_68[2] = 0;
  local_68[3] = 0;
  uVar3 = FUN_000121dc();
  if (param_5 == 0) {
    iVar4 = 0;
  }
  else {
    *param_6 = *param_6 & uVar3;
    if (param_3 == 0) {
      FUN_000121dc();
      iVar4 = -0x3ffffdf4;
    }
    else {
      KeInitializeEvent(local_58,0,0);
      uVar5 = IoGetRelatedDeviceObject(param_3);
      lVar6 = IoAllocateMdl(param_4,param_5,0,0,0);
      if (lVar6 != 0) {
        MmProbeAndLockPages(lVar6,0,2);
        if (lVar6 != 0) {
          lVar7 = IoBuildDeviceIoControlRequest(3,uVar5,0,0,0,0,1,local_58,local_68);
          if (lVar7 != 0) {
            lVar2 = *(longlong *)(lVar7 + 0xb8);
            *(undefined8 *)(lVar2 + -0x10) = 0;
            *(undefined8 *)(lVar2 + -8) = 0;
            *(undefined1 *)(lVar2 + -0x45) = 0;
            lVar2 = *(longlong *)(lVar7 + 0xb8);
            *(undefined1 *)(lVar2 + -0x48) = 0xf;
            *(undefined1 *)(lVar2 + -0x47) = 7;
            *(undefined8 *)(lVar2 + -0x20) = uVar5;
            *(longlong *)(lVar2 + -0x18) = param_3;
            *(undefined4 *)(lVar2 + -0x3c) = 0x180;
            *(int *)(lVar2 + -0x40) = param_5;
            *(longlong *)(lVar7 + 8) = lVar6;
            iVar4 = IofCallDriver(uVar5);
            LOCK();
            *(undefined4 *)((ulonglong)param_2 * 0x268 + 0x1018 + lVar1) = 0;
            UNLOCK();
            if (iVar4 == 0x103) {
              KeWaitForSingleObject(local_58,0,0,0,0);
            }
            *param_6 = local_68[2];
            iVar4 = local_68[0];
          }
        }
      }
    }
  }
  FUN_00021370(iVar4);
  FUN_000121dc();
  return iVar4;
}



/* ===== FUNC FUN_0003d4f0 @ 0003d4f0 ===== */

int FUN_0003d4f0(undefined8 param_1,longlong param_2,undefined8 param_3,undefined8 param_4,
                ulonglong param_5)

{
  longlong lVar1;
  int iVar2;
  undefined8 uVar3;
  longlong lVar4;
  ulonglong uVar5;
  int local_48 [4];
  undefined1 local_38 [32];
  
  local_48[0] = 0;
  local_48[1] = 0;
  local_48[2] = 0;
  local_48[3] = 0;
  uVar5 = param_5;
  FUN_000121dc();
  if (param_2 == 0) {
    FUN_000121dc();
    iVar2 = 0;
  }
  else {
    KeInitializeEvent(local_38,0,0);
    uVar3 = IoGetRelatedDeviceObject(param_2);
    FUN_000121dc();
    lVar4 = IoBuildDeviceIoControlRequest
                      (3,uVar3,0,0,0,uVar5 & 0xffffffff00000000,1,local_38,local_48);
    iVar2 = -0x3fffff66;
    if (lVar4 != 0) {
      lVar1 = *(longlong *)(lVar4 + 0xb8);
      *(undefined8 *)(lVar1 + -0x10) = 0;
      *(undefined8 *)(lVar1 + -8) = 0;
      *(undefined1 *)(lVar1 + -0x45) = 0;
      lVar4 = *(longlong *)(lVar4 + 0xb8);
      *(undefined1 *)(lVar4 + -0x48) = 0xf;
      *(undefined1 *)(lVar4 + -0x47) = 0xb;
      *(undefined8 *)(lVar4 + -0x20) = uVar3;
      *(longlong *)(lVar4 + -0x18) = param_2;
      *(undefined4 *)(lVar4 + -0x40) = 1;
      *(undefined8 *)(lVar4 + -0x38) = param_4;
      *(ulonglong *)(lVar4 + -0x30) = param_5;
      iVar2 = IofCallDriver(uVar3);
      FUN_00021370(iVar2);
      FUN_000121dc();
      if (iVar2 == 0x103) {
        KeWaitForSingleObject(local_38,0,0,0,0);
        iVar2 = local_48[0];
      }
    }
  }
  FUN_00021370(iVar2);
  FUN_000121dc();
  return iVar2;
}



/* ===== FUNC WdmlibInit @ 0003d6ac ===== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Library Function - Single Match
    WdmlibInit
   
   Library: Visual Studio 2019 Release */

void WdmlibInit(void)

{
  undefined1 local_18 [24];
  
  RtlInitUnicodeString(local_18,L"IoCreateDeviceSecure");
  DAT_000377e8 = (code *)MmGetSystemRoutineAddress(local_18);
  if (DAT_000377e8 == (code *)0x0) {
    DAT_000377e8 = FUN_0003d85c;
  }
  RtlInitUnicodeString(local_18,L"IoValidateDeviceIoControlAccess");
  _DAT_000377f0 = MmGetSystemRoutineAddress(local_18);
  DAT_000377e0 = 1;
  return;
}



/* ===== FUNC WdmlibIoCreateDeviceSecure @ 0003d718 ===== */

/* Library Function - Single Match
    WdmlibIoCreateDeviceSecure
   
   Library: Visual Studio 2019 Release */

void WdmlibIoCreateDeviceSecure
               (undefined8 param_1,undefined4 param_2,undefined8 param_3,undefined4 param_4,
               undefined4 param_5,undefined1 param_6,undefined8 param_7,undefined8 param_8,
               undefined8 param_9)

{
  if (DAT_000377e0 == '\0') {
    WdmlibInit();
  }
  (*DAT_000377e8)(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9);
  return;
}



/* ===== FUNC IopDevObjApplyPostCreationSettings @ 0003d7b0 ===== */

/* Library Function - Single Match
    IopDevObjApplyPostCreationSettings
   
   Library: Visual Studio 2019 Release */

ulonglong IopDevObjApplyPostCreationSettings(undefined8 param_1,byte *param_2)

{
  uint uVar1;
  ulonglong uVar2;
  undefined1 local_res10 [8];
  uint local_res18 [2];
  uint local_res20 [2];
  undefined8 local_18 [2];
  
  if ((*param_2 & 2) == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = SeUtilSecurityInfoFromSecurityDescriptor
                      (*(undefined8 *)(param_2 + 8),local_res10,local_res18);
    if (-1 < (int)uVar2) {
      SeSetSecurityAccessMask((byte)local_res18[0],local_res20);
      uVar2 = ObOpenObjectByPointer
                        (param_1,0x200,0,local_res20[0],*(undefined8 *)IoDeviceObjectType_exref,0,
                         local_18);
      if (-1 < (int)uVar2) {
        uVar1 = ZwSetSecurityObject(local_18[0],local_res18[0],*(undefined8 *)(param_2 + 8));
        uVar2 = (ulonglong)uVar1;
        ZwClose(local_18[0]);
      }
    }
  }
  return uVar2;
}



/* ===== FUNC FUN_0003d85c @ 0003d85c ===== */

ulonglong FUN_0003d85c(longlong param_1,undefined4 param_2,longlong param_3,undefined4 param_4,
                      undefined4 param_5,undefined1 param_6,ushort *param_7,longlong param_8,
                      undefined8 *param_9)

{
  undefined8 *puVar1;
  uint uVar2;
  ulonglong uVar3;
  longlong local_res18 [2];
  uint local_58;
  undefined4 local_54;
  undefined4 local_48;
  undefined1 local_44;
  undefined4 local_40 [6];
  
  puVar1 = param_9;
  param_9 = (undefined8 *)0x0;
  *puVar1 = 0;
  if ((param_3 == 0) && (-1 < (char)param_5)) {
    return 0xc000000d;
  }
  if (param_8 == 0) {
    FUN_0003dbe4(&local_58);
  }
  else {
    uVar3 = FUN_0003ddc8(param_8,param_1,&local_58);
    if ((int)uVar3 < 0) {
      return uVar3;
    }
  }
  if ((local_58 & 2) == 0) {
    uVar2 = FUN_0003e898(param_7,1,local_res18);
    if ((int)uVar2 < 0) goto LAB_0003d9e5;
    FUN_0003da14(local_res18[0],&local_58);
    if (param_8 != 0) {
      FUN_0003dbe4(local_40);
      FUN_0003da14(local_res18[0],local_40);
      uVar3 = PpRegStateUpdateStackCreationSettings(param_8,(longlong)local_40);
      uVar2 = (uint)uVar3;
      if ((int)uVar2 < 0) goto LAB_0003d9e5;
    }
  }
  if ((local_58 & 1) != 0) {
    param_4 = local_54;
  }
  if ((local_58 & 4) != 0) {
    param_5 = local_48;
  }
  if ((local_58 & 8) != 0) {
    param_6 = local_44;
  }
  uVar2 = IoCreateDevice(param_1,param_2,param_3,param_4,param_5,param_6,&param_9);
  if (-1 < (int)uVar2) {
    uVar3 = IopDevObjApplyPostCreationSettings(param_9,(byte *)&local_58);
    uVar2 = (uint)uVar3;
    if ((int)uVar2 < 0) {
      IoDeleteDevice(param_9);
    }
    else {
      *puVar1 = param_9;
    }
  }
LAB_0003d9e5:
  FUN_0003da28((byte *)&local_58);
  return (ulonglong)uVar2;
}



/* ===== FUNC FUN_0003da14 @ 0003da14 ===== */

void FUN_0003da14(undefined8 param_1,undefined4 *param_2)

{
  *param_2 = 2;
  *(undefined8 *)(param_2 + 2) = param_1;
  return;
}



/* ===== FUNC FUN_0003da28 @ 0003da28 ===== */

void FUN_0003da28(byte *param_1)

{
  if ((*param_1 & 2) != 0) {
    ExFreePoolWithTag(*(undefined8 *)(param_1 + 8),0);
  }
  return;
}



/* ===== FUNC FUN_0003da48 @ 0003da48 ===== */

void FUN_0003da48(uint *param_1,undefined4 param_2,int param_3,undefined4 *param_4,
                 undefined8 *param_5)

{
  int iVar1;
  undefined1 auStackY_128 [32];
  undefined4 local_b8 [2];
  undefined8 local_b0;
  undefined8 local_a8 [2];
  wchar_t local_98 [38];
  undefined2 local_4c;
  ulonglong local_48;
  
  local_48 = DAT_00037100 ^ (ulonglong)auStackY_128;
  *param_5 = 0;
  if (param_4 != (undefined4 *)0x0) {
    *param_4 = 0;
  }
  iVar1 = CmRegUtilOpenExistingWstrKey
                    (0,L"\\Registry\\Machine\\System\\CurrentControlSet\\Control\\Class",0x20019,
                     &local_b0);
  if (-1 < iVar1) {
    _snwprintf(local_98,0x27,L"{%08X-%04X-%04X-%02X%02X-%02X%02X%02X%02X%02X%02X}",*param_1,
               (uint)(ushort)param_1[1],(uint)*(ushort *)((longlong)param_1 + 6),
               (uint)(byte)param_1[2],(uint)*(byte *)((longlong)param_1 + 9),
               (uint)*(byte *)((longlong)param_1 + 10),(uint)*(byte *)((longlong)param_1 + 0xb),
               (uint)(byte)param_1[3],(uint)*(byte *)((longlong)param_1 + 0xd),
               (uint)*(byte *)((longlong)param_1 + 0xe),(uint)*(byte *)((longlong)param_1 + 0xf));
    local_4c = 0;
    if (param_3 == 0) {
      iVar1 = CmRegUtilOpenExistingWstrKey(local_b0,local_98,param_2,local_a8);
      local_b8[0] = 2;
    }
    else {
      iVar1 = CmRegUtilCreateWstrKey(local_b0,local_98,param_2,0,0,local_b8,local_a8);
    }
    ZwClose(local_b0);
    if ((-1 < iVar1) && (*param_5 = local_a8[0], param_4 != (undefined4 *)0x0)) {
      *param_4 = local_b8[0];
    }
  }
  FUN_00025050(local_48 ^ (ulonglong)auStackY_128);
  return;
}



/* ===== FUNC FUN_0003dbe4 @ 0003dbe4 ===== */

void FUN_0003dbe4(undefined4 *param_1)

{
  *param_1 = 0;
  *(undefined8 *)(param_1 + 2) = 0;
  param_1[1] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  return;
}



/* ===== FUNC PiRegStateReadStackCreationSettingsFromKey @ 0003dbfc ===== */

/* Library Function - Single Match
    PiRegStateReadStackCreationSettingsFromKey
   
   Library: Visual Studio 2019 Release */

ulonglong PiRegStateReadStackCreationSettingsFromKey(undefined8 param_1,uint *param_2)

{
  uint uVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  char local_res10 [8];
  uint local_res18 [2];
  longlong local_res20;
  longlong local_48 [2];
  
  *param_2 = 0;
  param_2[2] = 0;
  param_2[3] = 0;
  param_2[1] = 0;
  param_2[4] = 0;
  param_2[5] = 0;
  local_48[0] = 0;
  uVar1 = CmRegUtilWstrValueGetFullBuffer(param_1,L"Security",3,0,local_48);
  uVar3 = (ulonglong)uVar1;
  if ((int)uVar1 < 0) {
    if (uVar1 == 0xc0000034) {
      local_res20 = 0;
      uVar3 = 0;
    }
  }
  else {
    uVar1 = SeCaptureSecurityDescriptor
                      ((ulonglong)*(uint *)(local_48[0] + 8) + local_48[0],0,1,1,&local_res20);
    uVar3 = (ulonglong)uVar1;
  }
  if (local_48[0] != 0) {
    ExFreePoolWithTag(local_48[0],0);
  }
  if (-1 < (int)uVar3) {
    if (local_res20 != 0) {
      uVar2 = SeUtilSecurityInfoFromSecurityDescriptor(local_res20,local_res10,local_res18);
      uVar3 = uVar2 & 0xffffffff;
      if ((int)uVar2 < 0) goto LAB_0003dd82;
      if (local_res10[0] == '\0') {
        *param_2 = *param_2 | 2;
        *(longlong *)(param_2 + 2) = local_res20;
      }
      else {
        ExFreePoolWithTag(local_res20,0);
      }
    }
    uVar1 = CmRegUtilWstrValueGetDword(param_1,L"DeviceType",0,param_2 + 1);
    uVar3 = (ulonglong)uVar1;
    if ((int)uVar1 < 0) {
      if (uVar1 != 0xc0000034) goto LAB_0003dd82;
    }
    else {
      *param_2 = *param_2 | 1;
    }
    uVar1 = CmRegUtilWstrValueGetDword(param_1,L"DeviceCharacteristics",0,param_2 + 4);
    uVar3 = (ulonglong)uVar1;
    if ((int)uVar1 < 0) {
      if (uVar1 != 0xc0000034) goto LAB_0003dd82;
    }
    else {
      *param_2 = *param_2 | 4;
    }
    uVar1 = CmRegUtilWstrValueGetDword(param_1,L"Exclusive",0,param_2 + 5);
    uVar3 = (ulonglong)uVar1;
    if (-1 < (int)uVar1) {
      *param_2 = *param_2 | 8;
      return uVar3;
    }
    if (uVar1 == 0xc0000034) {
      return 0;
    }
  }
LAB_0003dd82:
  if (*(longlong *)(param_2 + 2) != 0) {
    ExFreePoolWithTag(*(longlong *)(param_2 + 2),0);
  }
  *param_2 = 0;
  param_2[2] = 0;
  param_2[3] = 0;
  param_2[1] = 0;
  param_2[4] = 0;
  param_2[5] = 0;
  return uVar3;
}



/* ===== FUNC FUN_0003ddc8 @ 0003ddc8 ===== */

ulonglong FUN_0003ddc8(undefined8 param_1,longlong param_2,uint *param_3)

{
  uint uVar1;
  ulonglong uVar2;
  undefined8 uVar3;
  ushort *puVar4;
  int local_res18 [2];
  undefined8 local_res20;
  undefined8 local_18 [2];
  
  *param_3 = 0;
  param_3[2] = 0;
  param_3[3] = 0;
  param_3[1] = 0;
  param_3[4] = 0;
  param_3[5] = 0;
  local_res20 = 0;
  local_18[0] = 0;
  uVar2 = FUN_0003da48(param_1,0xf003f,1,local_res18,&local_res20);
  uVar3 = local_res20;
  if ((int)uVar2 < 0) {
    return uVar2;
  }
  if (local_res18[0] == 2) {
    uVar1 = CmRegUtilOpenExistingWstrKey(local_res20,L"Properties",0x20019,local_18);
    ZwClose(local_res20);
    if ((int)uVar1 < 0) {
      if (uVar1 == 0xc0000034) {
        return 0;
      }
      return (ulonglong)uVar1;
    }
    uVar2 = PiRegStateReadStackCreationSettingsFromKey(local_18[0],param_3);
    uVar2 = uVar2 & 0xffffffff;
    uVar3 = local_18[0];
  }
  else {
    puVar4 = (ushort *)(*(longlong *)(param_2 + 0x30) + 0x18);
    if (puVar4 == (ushort *)0x0) {
      uVar2 = 0xc000009a;
    }
    else {
      uVar1 = CmRegUtilWstrValueSetUcString(local_res20,L"Class",puVar4);
      uVar2 = (ulonglong)uVar1;
      if (-1 < (int)uVar1) {
        local_res18[0] = 0x31;
        uVar1 = CmRegUtilWstrValueSetWstrString(uVar3,L"NoDisplayClass",(short *)local_res18);
        uVar2 = (ulonglong)uVar1;
        if (-1 < (int)uVar1) {
          uVar1 = CmRegUtilWstrValueSetWstrString(uVar3,L"NoUseClass",(short *)local_res18);
          uVar2 = (ulonglong)uVar1;
        }
      }
    }
  }
  ZwClose(uVar3);
  return uVar2;
}



/* ===== FUNC PpRegStateUpdateStackCreationSettings @ 0003def8 ===== */

/* Library Function - Single Match
    PpRegStateUpdateStackCreationSettings
   
   Library: Visual Studio 2019 Release */

ulonglong PpRegStateUpdateStackCreationSettings(undefined8 param_1,longlong param_2)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  ulonglong uVar4;
  undefined *puVar5;
  undefined *local_res18;
  undefined8 local_res20;
  undefined8 local_18 [2];
  
  uVar4 = FUN_0003da48(param_1,0xf003f,0,(undefined4 *)0x0,&local_res20);
  if (-1 < (int)uVar4) {
    puVar5 = &DAT_00037110;
    if (DAT_000377f8 == 0) {
      iVar1 = SeCaptureSecurityDescriptor(&DAT_00037110,0,1,1,&local_res18);
      if (iVar1 < 0) {
        DAT_000377f8 = 2;
      }
      else {
        DAT_000377f8 = 1;
        ExFreePoolWithTag(local_res18,0);
      }
    }
    if (DAT_000377f8 != 1) {
      puVar5 = (undefined *)0x0;
    }
    local_res18 = puVar5;
    uVar2 = CmRegUtilCreateWstrKey
                      (local_res20,L"Properties",0xf003f,0,puVar5,(undefined4 *)0x0,local_18);
    ZwClose(local_res20);
    if (-1 < (int)uVar2) {
      uVar3 = RtlLengthSecurityDescriptor(*(undefined8 *)(param_2 + 8));
      uVar2 = CmRegUtilWstrValueSetFullBuffer
                        (local_18[0],L"Security",3,*(undefined8 *)(param_2 + 8),uVar3);
      ZwClose(local_18[0]);
    }
    uVar4 = (ulonglong)uVar2;
  }
  return uVar4;
}



/* ===== FUNC FUN_0003e024 @ 0003e024 ===== */

undefined8 FUN_0003e024(ushort *param_1,undefined8 *param_2,uint *param_3)

{
  ushort uVar1;
  uint uVar2;
  undefined8 uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  ushort *puVar7;
  
  *param_3 = 0;
  *param_2 = param_1;
  uVar1 = *param_1;
  if (uVar1 == 0x30) {
    if ((param_1[1] != 0x78) && (param_1[1] != 0x58)) {
      uVar1 = *param_1;
      goto LAB_0003e05d;
    }
    param_1 = param_1 + 2;
  }
  else {
LAB_0003e05d:
    if ((0x2f < uVar1) && (iVar5 = 10, *param_1 < 0x3a)) goto LAB_0003e06f;
  }
  iVar5 = 0x10;
LAB_0003e06f:
  puVar7 = param_1;
  uVar6 = 0;
  while( true ) {
    uVar1 = *puVar7;
    uVar2 = (uint)uVar1;
    if (uVar1 == 0) break;
    if ((uVar1 < 0x30) || (0x39 < uVar1)) {
      if (iVar5 != 0x10) break;
      if ((uVar1 < 0x41) || (0x46 < uVar1)) {
        if ((uVar1 < 0x61) || (0x66 < uVar1)) break;
        iVar4 = uVar2 - 0x57;
      }
      else {
        iVar4 = uVar2 - 0x37;
      }
    }
    else {
      iVar4 = uVar2 - 0x30;
    }
    uVar2 = uVar6 * iVar5 + iVar4;
    if (uVar2 < uVar6) goto LAB_0003e0e6;
    puVar7 = puVar7 + 1;
    uVar6 = uVar2;
  }
  if (puVar7 == param_1) {
LAB_0003e0e6:
    uVar3 = 0;
  }
  else {
    *param_2 = puVar7;
    uVar3 = 1;
    *param_3 = uVar6;
  }
  return uVar3;
}



/* ===== FUNC FUN_0003e0f0 @ 0003e0f0 ===== */

undefined8
FUN_0003e0f0(longlong *param_1,uint *param_2,undefined8 param_3,undefined8 param_4,
            undefined4 param_5,int param_6,undefined8 param_7)

{
  uint uVar1;
  ulonglong *puVar2;
  int iVar3;
  ulonglong *_Dst;
  undefined8 uVar4;
  uint uVar5;
  uint uVar6;
  
  puVar2 = (ulonglong *)*param_1;
  uVar1 = *param_2;
  iVar3 = RtlLengthSid(param_7);
  uVar6 = iVar3 + 8 + uVar1;
  _Dst = puVar2;
  if (*(ushort *)((longlong)puVar2 + 2) < uVar6) {
    uVar5 = (iVar3 + 8) * param_6 + uVar1;
    _Dst = (ulonglong *)ExAllocatePoolWithTag(1,uVar5,0x6c416553);
    if (_Dst == (ulonglong *)0x0) {
      return 0xc000009a;
    }
    FUN_000251f0(_Dst,0,(ulonglong)uVar5);
    memcpy(_Dst,(void *)*param_1,(ulonglong)uVar1);
    *(short *)((longlong)_Dst + 2) = (short)uVar5;
    ExFreePoolWithTag(puVar2,0);
    *param_1 = (longlong)_Dst;
  }
  *param_2 = uVar6;
  uVar4 = RtlAddAccessAllowedAce(_Dst,2,param_5,param_7);
  return uVar4;
}



/* ===== FUNC FUN_0003e1d8 @ 0003e1d8 ===== */

undefined8 FUN_0003e1d8(wchar_t *param_1,undefined4 *param_2,longlong *param_3)

{
  int iVar1;
  uint uVar2;
  undefined **ppuVar3;
  
  uVar2 = 0;
  ppuVar3 = &PTR_DAT_00037260;
  do {
    iVar1 = _wcsnicmp(param_1,(wchar_t *)*ppuVar3,(ulonglong)*(uint *)(ppuVar3 + 1));
    if (iVar1 == 0) {
      *param_2 = (&DAT_0003726c)[(ulonglong)uVar2 * 4];
      *param_3 = (longlong)(param_1 + (uint)(&DAT_00037268)[(ulonglong)uVar2 * 4]);
      return 1;
    }
    uVar2 = uVar2 + 1;
    ppuVar3 = ppuVar3 + 2;
  } while (uVar2 < 8);
  *param_2 = 0;
  *param_3 = (longlong)param_1;
  return 0;
}



/* ===== FUNC FUN_0003e270 @ 0003e270 ===== */

undefined8 FUN_0003e270(wchar_t *param_1,undefined8 *param_2,longlong *param_3)

{
  char cVar1;
  int iVar2;
  uint *puVar3;
  uint uVar4;
  ulonglong uVar5;
  
  uVar5 = 0;
  puVar3 = &DAT_00037154;
  do {
    iVar2 = _wcsnicmp(param_1,(wchar_t *)(&DAT_0003714c + uVar5 * 0x18),(ulonglong)*puVar3);
    if (iVar2 == 0) {
      uVar4 = (&DAT_00037154)[uVar5 * 6];
      *param_3 = (longlong)(param_1 + uVar4);
      if (((&DAT_00037148)[uVar5 * 6] == 1) &&
         (cVar1 = IoIsWdmVersionAvailable
                            (1,CONCAT71((int7)((ulonglong)(param_1 + uVar4) >> 8),0x20)),
         cVar1 == '\0')) {
        *param_2 = 0;
      }
      else {
        *param_2 = *(undefined8 *)((&DAT_00037140)[uVar5 * 3] + *(longlong *)SeExports_exref);
      }
      return 0;
    }
    uVar4 = (int)uVar5 + 1;
    uVar5 = (ulonglong)uVar4;
    puVar3 = puVar3 + 6;
  } while (uVar4 < 0xc);
  *param_2 = 0;
  return 0xc0000073;
}



/* ===== FUNC FUN_0003e338 @ 0003e338 ===== */

int FUN_0003e338(wchar_t *param_1,longlong *param_2,ulonglong *param_3)

{
  wchar_t wVar1;
  bool bVar2;
  short *psVar3;
  int iVar4;
  int iVar5;
  wchar_t *pwVar6;
  undefined8 *puVar7;
  ulonglong *puVar8;
  longlong lVar9;
  undefined8 uVar10;
  ulonglong uVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  uint local_res8 [2];
  uint local_res10 [2];
  uint local_res18 [2];
  wchar_t *local_res20;
  short *local_48;
  longlong local_40;
  
  iVar5 = 0;
  *param_2 = 0;
  local_40 = 0;
  uVar12 = 0;
  pwVar6 = wcschr(param_1,L':');
  *param_3 = (ulonglong)pwVar6;
  if (pwVar6 == param_1) {
    return -0x3ffffff3;
  }
  if (pwVar6 == (wchar_t *)0x0) {
    uVar11 = 0xffffffffffffffff;
    pwVar6 = param_1;
    do {
      if (uVar11 == 0) break;
      uVar11 = uVar11 - 1;
      wVar1 = *pwVar6;
      pwVar6 = pwVar6 + 1;
    } while (wVar1 != L'\0');
    pwVar6 = param_1 + (~uVar11 - 1);
  }
  else {
    pwVar6 = pwVar6 + -1;
  }
  *param_3 = (ulonglong)pwVar6;
  bVar2 = false;
  if (param_1 < (wchar_t *)*param_3) {
    pwVar6 = param_1;
    do {
      if (*pwVar6 == L';') {
        uVar12 = uVar12 + 1;
      }
      else if (*pwVar6 != L' ') {
        bVar2 = true;
      }
      pwVar6 = pwVar6 + 1;
    } while (pwVar6 < (wchar_t *)*param_3);
  }
  uVar14 = uVar12 / 5;
  if ((uVar12 != uVar14 * 5) || ((uVar12 == 0 && (bVar2)))) {
    iVar5 = -0x3ffffff3;
  }
  else {
    if (uVar14 == 0) {
      puVar7 = (undefined8 *)ExAllocatePoolWithTag(1,8);
      *param_2 = (longlong)puVar7;
      if (puVar7 != (undefined8 *)0x0) {
        *puVar7 = 0;
        *(undefined1 *)*param_2 = 2;
        *(undefined1 *)(*param_2 + 1) = 0;
        *(undefined2 *)(*param_2 + 2) = 8;
        *(undefined2 *)(*param_2 + 4) = 0;
        *(undefined2 *)(*param_2 + 6) = 0;
        return 0;
      }
    }
    else {
      uVar12 = uVar14 * 0x30 + 8;
      if (0xffff < uVar12) {
        uVar12 = 0xffff;
      }
      puVar8 = (ulonglong *)ExAllocatePoolWithTag(1,uVar12,0x6c416553);
      *param_2 = (longlong)puVar8;
      if (puVar8 != (ulonglong *)0x0) {
        local_res10[0] = 8;
        FUN_000251f0(puVar8,0,(ulonglong)uVar12);
        *(undefined1 *)*param_2 = 2;
        uVar13 = 0;
        *(undefined1 *)(*param_2 + 1) = 0;
        *(short *)(*param_2 + 2) = (short)uVar12;
        *(undefined2 *)(*param_2 + 4) = 0;
        *(undefined2 *)(*param_2 + 6) = 0;
        uVar12 = 8;
        if (uVar14 != 0) {
          do {
            local_res8[0] = 0;
            for (; *param_1 == L' '; param_1 = param_1 + 1) {
            }
            if (*param_1 != L'(') goto LAB_0003e4e8;
            do {
              param_1 = param_1 + 1;
LAB_0003e4e8:
            } while (*param_1 == L' ');
            iVar4 = _wcsnicmp(param_1,L"A",1);
            if (iVar4 != 0) {
              iVar5 = -0x3ffffff3;
              break;
            }
            for (pwVar6 = param_1 + 2; *pwVar6 == L' '; pwVar6 = pwVar6 + 1) {
            }
            if (*pwVar6 != L';') {
              iVar5 = -0x3ffffff3;
              goto LAB_0003e69e;
            }
            do {
              pwVar6 = pwVar6 + 1;
            } while (*pwVar6 == L' ');
            wVar1 = *pwVar6;
            uVar12 = 0;
            while (wVar1 != L';') {
              for (; *pwVar6 == L' '; pwVar6 = pwVar6 + 1) {
              }
              uVar10 = FUN_0003e1d8(pwVar6,local_res18,(longlong *)&local_res20);
              if ((int)uVar10 == 0) {
                FUN_0003e024((ushort *)pwVar6,&local_res20,local_res8);
                if (local_res20 == pwVar6) {
                  iVar5 = -0x3ffffff3;
                  uVar12 = local_res8[0];
                  goto LAB_0003e539;
                }
              }
              else {
                local_res8[0] = uVar12 | local_res18[0];
              }
              uVar12 = local_res8[0];
              pwVar6 = local_res20;
              wVar1 = *local_res20;
            }
            pwVar6 = pwVar6 + 1;
LAB_0003e539:
            if (iVar5 != 0) goto LAB_0003e69e;
            lVar9 = 2;
            do {
              for (; *pwVar6 == L' '; pwVar6 = pwVar6 + 1) {
              }
              if (*pwVar6 != L';') {
                iVar5 = -0x3ffffff3;
              }
              pwVar6 = pwVar6 + 1;
              lVar9 = lVar9 + -1;
            } while (lVar9 != 0);
            if (iVar5 != 0) goto LAB_0003e69e;
            for (; *pwVar6 == L' '; pwVar6 = pwVar6 + 1) {
            }
            uVar10 = FUN_0003e270(pwVar6,&local_40,(longlong *)&local_48);
            iVar5 = (int)uVar10;
            if (iVar5 != 0) goto LAB_0003e69e;
            if (local_48 == (short *)0x0) {
LAB_0003e68d:
              iVar5 = -0x3fffff89;
              goto LAB_0003e69e;
            }
            if (*local_48 == 0x20) {
              do {
                local_48 = local_48 + 1;
              } while (*local_48 == 0x20);
            }
            psVar3 = local_48;
            if (*local_48 != 0x29) goto LAB_0003e68d;
            param_1 = local_48 + 1;
            if (local_40 != 0) {
              uVar10 = FUN_0003e0f0(param_2,local_res10,0,0,uVar12,uVar14 - uVar13,local_40);
              iVar5 = (int)uVar10;
              if (iVar5 != 0) goto LAB_0003e69e;
            }
            if (*param_1 == L'(') {
              param_1 = psVar3 + 2;
            }
            uVar13 = uVar13 + 1;
          } while (uVar13 < uVar14);
          if (iVar5 != 0) {
LAB_0003e69e:
            ExFreePoolWithTag(*param_2,0);
            *param_2 = 0;
            return iVar5;
          }
          uVar12 = local_res10[0];
        }
        *(short *)(*param_2 + 2) = (short)uVar12;
        return 0;
      }
    }
    iVar5 = -0x3fffff66;
  }
  return iVar5;
}



/* ===== FUNC FUN_0003e6e0 @ 0003e6e0 ===== */

int FUN_0003e6e0(short *param_1,int param_2,uint *param_3,longlong *param_4)

{
  int iVar1;
  wchar_t *pwVar2;
  uint uVar3;
  longlong local_res8;
  short *local_res18 [2];
  
  *param_4 = 0;
  *param_3 = 0;
  for (; *param_1 == 0x20; param_1 = param_1 + 1) {
  }
  if ((*param_1 != 0x44) || (param_1[1] != 0x3a)) {
    return -0x3ffffff3;
  }
  pwVar2 = param_1 + 2;
  uVar3 = -(uint)(param_2 != 0) & 8;
  if (*pwVar2 == L'P') {
    pwVar2 = param_1 + 3;
    uVar3 = uVar3 | 0x1000;
  }
  iVar1 = FUN_0003e338(pwVar2,&local_res8,(ulonglong *)local_res18);
  if (iVar1 == 0) {
    for (; *local_res18[0] == 0x20; local_res18[0] = local_res18[0] + 1) {
    }
    if (*local_res18[0] == 0) {
      *param_4 = local_res8;
      *param_3 = uVar3;
      return 0;
    }
    iVar1 = -0x3ffffff3;
  }
  if (local_res8 != 0) {
    ExFreePoolWithTag(local_res8,0);
  }
  return iVar1;
}



/* ===== FUNC FUN_0003e798 @ 0003e798 ===== */

int FUN_0003e798(short *param_1,int param_2,longlong *param_3)

{
  int iVar1;
  longlong lVar2;
  undefined4 local_res18 [2];
  ushort local_res20 [4];
  longlong local_38;
  undefined1 local_30 [2];
  ushort local_2e;
  
  local_38 = 0;
  lVar2 = 0;
  *param_3 = 0;
  iVar1 = FUN_0003e6e0(param_1,param_2,(uint *)local_res20,&local_38);
  if (-1 < iVar1) {
    RtlCreateSecurityDescriptor(local_30,1);
    RtlSetDaclSecurityDescriptor(local_30,1,local_38,0);
    local_res18[0] = 0;
    local_2e = local_2e | local_res20[0];
    RtlAbsoluteToSelfRelativeSD(local_30,0,local_res18);
    lVar2 = ExAllocatePoolWithTag(1,local_res18[0],0x64536553);
    if (lVar2 == 0) {
      iVar1 = -0x3fffff66;
    }
    else {
      iVar1 = RtlAbsoluteToSelfRelativeSD(local_30,lVar2,local_res18);
      if (-1 < iVar1) {
        ExFreePoolWithTag(local_38,0);
        *param_3 = lVar2;
        return iVar1;
      }
    }
  }
  if (local_38 != 0) {
    ExFreePoolWithTag(local_38,0);
  }
  if (lVar2 != 0) {
    ExFreePoolWithTag(lVar2,0);
  }
  return iVar1;
}



/* ===== FUNC FUN_0003e898 @ 0003e898 ===== */

int FUN_0003e898(ushort *param_1,int param_2,longlong *param_3)

{
  ulonglong uVar1;
  int iVar2;
  short *_Dst;
  
  uVar1 = (ulonglong)*param_1 + 2;
  if ((param_1[1] == uVar1) && ((*(short **)(param_1 + 4))[*param_1 >> 1] == 0)) {
    iVar2 = FUN_0003e798(*(short **)(param_1 + 4),param_2,param_3);
    return iVar2;
  }
  _Dst = (short *)ExAllocatePoolWithTag(1,uVar1,0x73546553);
  if (_Dst == (short *)0x0) {
    *param_3 = 0;
    iVar2 = -0x3fffff66;
  }
  else {
    memcpy(_Dst,*(void **)(param_1 + 4),(ulonglong)*param_1);
    _Dst[*param_1 >> 1] = 0;
    iVar2 = FUN_0003e798(_Dst,param_2,param_3);
    ExFreePoolWithTag(_Dst,0);
  }
  return iVar2;
}



/* ===== FUNC SeSetSecurityAccessMask @ 0003e954 ===== */

/* Library Function - Single Match
    SeSetSecurityAccessMask
   
   Library: Visual Studio 2019 Release */

void SeSetSecurityAccessMask(byte param_1,uint *param_2)

{
  *param_2 = 0;
  if (((param_1 & 1) != 0) || ((param_1 & 2) != 0)) {
    *param_2 = 0x80000;
  }
  if ((param_1 & 4) != 0) {
    *param_2 = *param_2 | 0x40000;
  }
  if ((param_1 & 8) != 0) {
    *param_2 = *param_2 | 0x1000000;
  }
  return;
}



/* ===== FUNC SeUtilSecurityInfoFromSecurityDescriptor @ 0003e980 ===== */

/* Library Function - Single Match
    SeUtilSecurityInfoFromSecurityDescriptor
   
   Library: Visual Studio 2019 Release */

undefined8
SeUtilSecurityInfoFromSecurityDescriptor(undefined8 param_1,undefined1 *param_2,uint *param_3)

{
  undefined8 uVar1;
  uint uVar2;
  undefined1 local_res10 [16];
  char local_res20 [8];
  longlong local_28;
  undefined1 local_20 [8];
  
  *param_2 = 0;
  *param_3 = 0;
  uVar1 = RtlGetOwnerSecurityDescriptor(param_1,&local_28,local_res10);
  if (-1 < (int)uVar1) {
    uVar2 = (uint)(local_28 != 0);
    uVar1 = RtlGetGroupSecurityDescriptor(param_1,&local_28,local_res10);
    if (-1 < (int)uVar1) {
      if (local_28 != 0) {
        uVar2 = uVar2 | 2;
      }
      uVar1 = RtlGetSaclSecurityDescriptor(param_1,local_res20,local_20,local_res10);
      if (-1 < (int)uVar1) {
        if (local_res20[0] != '\0') {
          uVar2 = uVar2 | 8;
        }
        uVar1 = RtlGetDaclSecurityDescriptor(param_1,local_res20,local_20,local_res10);
        if (-1 < (int)uVar1) {
          if (local_res20[0] != '\0') {
            uVar2 = uVar2 | 4;
          }
          *param_2 = local_res10[0];
          *param_3 = uVar2;
          uVar1 = 0;
        }
      }
    }
  }
  return uVar1;
}



/* ===== FUNC FUN_0003ea50 @ 0003ea50 ===== */

uint FUN_0003ea50(undefined2 *param_1,ushort param_2)

{
  longlong lVar1;
  
  *param_1 = 0;
  param_1[1] = param_2 + 2;
  lVar1 = ExAllocatePoolWithTag(1,(ulonglong)param_2 + 2,0x63557050);
  *(longlong *)(param_1 + 4) = lVar1;
  return ~-(uint)(lVar1 != 0) & 0xc000009a;
}



/* ===== FUNC FUN_0003ea98 @ 0003ea98 ===== */

uint FUN_0003ea98(undefined8 param_1,undefined8 param_2,ushort *param_3)

{
  ushort uVar1;
  uint uVar2;
  ushort local_18 [4];
  void *local_10;
  
  uVar1 = *param_3;
  if ((uint)param_3[1] - (uint)uVar1 < 2) {
    uVar2 = FUN_0003ea50(local_18,uVar1);
    if (-1 < (int)uVar2) {
      local_18[0] = *param_3;
      memcpy(local_10,*(void **)(param_3 + 4),(ulonglong)local_18[0]);
      *(undefined2 *)((longlong)local_10 + (ulonglong)(local_18[0] >> 1) * 2) = 0;
      uVar2 = ZwSetValueKey(param_1,param_2,0,1,local_10,local_18[0] + 2);
      RtlFreeUnicodeString(local_18);
    }
  }
  else {
    *(undefined2 *)(*(longlong *)(param_3 + 4) + (ulonglong)(uVar1 >> 1) * 2) = 0;
    uVar2 = ZwSetValueKey(param_1,param_2,0,1,*(undefined8 *)(param_3 + 4),*param_3 + 2);
  }
  return uVar2;
}



/* ===== FUNC CmRegUtilUcValueGetDword @ 0003eb90 ===== */

/* Library Function - Single Match
    CmRegUtilUcValueGetDword
   
   Library: Visual Studio 2019 Release */

void CmRegUtilUcValueGetDword
               (undefined8 param_1,undefined8 param_2,undefined4 param_3,undefined4 *param_4)

{
  int iVar1;
  undefined1 auStack_58 [32];
  undefined4 local_38;
  undefined1 *local_30;
  undefined1 local_28 [8];
  undefined1 local_20 [4];
  int local_1c;
  undefined4 local_14;
  ulonglong local_10;
  
  local_10 = DAT_00037100 ^ (ulonglong)auStack_58;
  local_30 = local_28;
  local_38 = 0x10;
  iVar1 = ZwQueryValueKey(param_1,param_2,2,local_20);
  if ((-1 < iVar1) && (local_1c == 4)) {
    param_3 = local_14;
  }
  *param_4 = param_3;
  FUN_00025050(local_10 ^ (ulonglong)auStack_58);
  return;
}



/* ===== FUNC FUN_0003ec08 @ 0003ec08 ===== */

int FUN_0003ec08(undefined8 param_1,undefined8 param_2,undefined4 param_3,undefined4 param_4,
                undefined8 param_5,undefined4 *param_6,undefined8 *param_7)

{
  int iVar1;
  undefined8 local_res8 [4];
  undefined4 local_38 [2];
  undefined8 local_30;
  undefined8 local_28;
  undefined4 local_20;
  undefined8 local_18;
  undefined8 local_10;
  
  local_38[0] = 0x30;
  local_20 = 0x240;
  local_10 = 0;
  local_18 = param_5;
  local_30 = param_1;
  local_28 = param_2;
  iVar1 = ZwCreateKey(local_res8,param_3,local_38,0,0,param_4,&param_5);
  if (iVar1 < 0) {
    local_res8[0] = 0;
    param_5._0_4_ = 0;
  }
  *param_7 = local_res8[0];
  if (param_6 != (undefined4 *)0x0) {
    *param_6 = (undefined4)param_5;
  }
  return iVar1;
}



/* ===== FUNC CmRegUtilOpenExistingUcKey @ 0003eca4 ===== */

/* Library Function - Single Match
    CmRegUtilOpenExistingUcKey
   
   Library: Visual Studio 2019 Release */

void CmRegUtilOpenExistingUcKey
               (undefined8 param_1,undefined8 param_2,undefined4 param_3,undefined8 *param_4)

{
  int iVar1;
  undefined8 local_res8 [4];
  undefined4 local_38 [2];
  undefined8 local_30;
  undefined8 local_28;
  undefined4 local_20;
  undefined8 local_18;
  undefined8 local_10;
  
  *param_4 = 0;
  local_38[0] = 0x30;
  local_20 = 0x240;
  local_18 = 0;
  local_10 = 0;
  local_30 = param_1;
  local_28 = param_2;
  iVar1 = ZwOpenKey(local_res8,param_3,local_38);
  if (-1 < iVar1) {
    *param_4 = local_res8[0];
  }
  return;
}



/* ===== FUNC CmRegUtilWstrValueSetWstrString @ 0003ed00 ===== */

/* Library Function - Single Match
    CmRegUtilWstrValueSetWstrString
   
   Library: Visual Studio 2019 Release */

void CmRegUtilWstrValueSetWstrString(undefined8 param_1,short *param_2,short *param_3)

{
  undefined8 uVar1;
  ushort local_28 [8];
  short local_18 [8];
  
  uVar1 = FUN_000250cc((short *)local_28,param_3);
  if (-1 < (int)uVar1) {
    uVar1 = FUN_000250cc(local_18,param_2);
    if (-1 < (int)uVar1) {
      FUN_0003ea98(param_1,local_18,local_28);
    }
  }
  return;
}



/* ===== FUNC CmRegUtilWstrValueSetUcString @ 0003ed58 ===== */

/* Library Function - Single Match
    CmRegUtilWstrValueSetUcString
   
   Library: Visual Studio 2019 Release */

void CmRegUtilWstrValueSetUcString(undefined8 param_1,short *param_2,ushort *param_3)

{
  undefined8 uVar1;
  short local_18 [8];
  
  uVar1 = FUN_000250cc(local_18,param_2);
  if (-1 < (int)uVar1) {
    FUN_0003ea98(param_1,local_18,param_3);
  }
  return;
}



/* ===== FUNC CmRegUtilWstrValueSetFullBuffer @ 0003ed98 ===== */

/* Library Function - Single Match
    CmRegUtilWstrValueSetFullBuffer
   
   Library: Visual Studio 2019 Release */

void CmRegUtilWstrValueSetFullBuffer
               (undefined8 param_1,short *param_2,undefined4 param_3,undefined8 param_4,
               undefined4 param_5)

{
  undefined8 uVar1;
  short local_18 [8];
  
  uVar1 = FUN_000250cc(local_18,param_2);
  if (-1 < (int)uVar1) {
    ZwSetValueKey(param_1,local_18,0,param_3,param_4,param_5);
  }
  return;
}



/* ===== FUNC CmRegUtilWstrValueGetDword @ 0003edf8 ===== */

/* Library Function - Single Match
    CmRegUtilWstrValueGetDword
   
   Library: Visual Studio 2019 Release */

void CmRegUtilWstrValueGetDword
               (undefined8 param_1,short *param_2,undefined4 param_3,undefined4 *param_4)

{
  undefined8 uVar1;
  short local_18 [8];
  
  uVar1 = FUN_000250cc(local_18,param_2);
  if (-1 < (int)uVar1) {
    CmRegUtilUcValueGetDword(param_1,local_18,param_3,param_4);
  }
  return;
}



/* ===== FUNC CmRegUtilCreateWstrKey @ 0003ee48 ===== */

/* Library Function - Single Match
    CmRegUtilCreateWstrKey
   
   Library: Visual Studio 2019 Release */

void CmRegUtilCreateWstrKey
               (undefined8 param_1,short *param_2,undefined4 param_3,undefined4 param_4,
               undefined8 param_5,undefined4 *param_6,undefined8 *param_7)

{
  undefined8 uVar1;
  short local_18 [8];
  
  uVar1 = FUN_000250cc(local_18,param_2);
  if (-1 < (int)uVar1) {
    FUN_0003ec08(param_1,local_18,param_3,param_4,param_5,param_6,param_7);
  }
  return;
}



/* ===== FUNC CmRegUtilOpenExistingWstrKey @ 0003eec0 ===== */

/* Library Function - Single Match
    CmRegUtilOpenExistingWstrKey
   
   Library: Visual Studio 2019 Release */

void CmRegUtilOpenExistingWstrKey
               (undefined8 param_1,short *param_2,undefined4 param_3,undefined8 *param_4)

{
  undefined8 uVar1;
  short local_18 [8];
  
  uVar1 = FUN_000250cc(local_18,param_2);
  if (-1 < (int)uVar1) {
    CmRegUtilOpenExistingUcKey(param_1,local_18,param_3,param_4);
  }
  return;
}



/* ===== FUNC FUN_0003ef10 @ 0003ef10 ===== */

int FUN_0003ef10(undefined8 param_1,ushort *param_2,int param_3,int param_4,longlong *param_5)

{
  uint uVar1;
  int iVar2;
  longlong lVar3;
  uint uVar4;
  undefined4 local_res20 [2];
  
  *param_5 = 0;
  uVar1 = *param_2 + 0x1f & 0xfffffff8;
  uVar4 = uVar1 + param_4;
  if (uVar4 < uVar1) {
    return -0x3fffff6b;
  }
  lVar3 = ExAllocatePoolWithTag(0,uVar4,0x62527050);
  if (lVar3 == 0) {
    return -0x3fffff66;
  }
  iVar2 = ZwQueryValueKey(param_1,param_2,1,lVar3,uVar4,local_res20);
  if (iVar2 < 0) {
    ExFreePoolWithTag(lVar3,0);
    if ((iVar2 != -0x7ffffffb) && (iVar2 != -0x3fffffdd)) {
      return iVar2;
    }
    lVar3 = ExAllocatePoolWithTag(0,local_res20[0],0x62527050);
    if (lVar3 == 0) {
      return -0x3fffff66;
    }
    iVar2 = ZwQueryValueKey(param_1,param_2,1,lVar3,local_res20[0],local_res20);
    if (iVar2 < 0) goto LAB_0003f00f;
  }
  if ((param_3 == 0) || (*(int *)(lVar3 + 4) == param_3)) {
    *param_5 = lVar3;
    return 0;
  }
  iVar2 = -0x3fffffdc;
LAB_0003f00f:
  ExFreePoolWithTag(lVar3,0);
  return iVar2;
}



/* ===== FUNC CmRegUtilWstrValueGetFullBuffer @ 0003f048 ===== */

/* Library Function - Single Match
    CmRegUtilWstrValueGetFullBuffer
   
   Library: Visual Studio 2019 Release */

void CmRegUtilWstrValueGetFullBuffer
               (undefined8 param_1,short *param_2,int param_3,int param_4,longlong *param_5)

{
  undefined8 uVar1;
  ushort local_18 [8];
  
  uVar1 = FUN_000250cc((short *)local_18,param_2);
  if (-1 < (int)uVar1) {
    FUN_0003ef10(param_1,local_18,param_3,param_4,param_5);
  }
  return;
}



/* ===== FUNC FUN_00041008 @ 00041008 ===== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00041008(longlong param_1,short *param_2)

{
  int iVar1;
  longlong lVar2;
  undefined1 auStack_1c8 [32];
  undefined4 local_1a8;
  uint *local_1a0;
  uint local_198 [2];
  undefined8 local_190;
  undefined1 local_188 [16];
  undefined4 local_178 [2];
  undefined8 local_170;
  short *local_168;
  undefined4 local_160;
  undefined8 local_158;
  undefined8 local_150;
  undefined4 local_148;
  uint local_144;
  ulonglong local_28;
  
  local_28 = DAT_00037100 ^ (ulonglong)auStack_1c8;
  DAT_00037824 = DAT_00037824 & 0xfffffff0;
  FUN_000121c8();
  FUN_000121c8();
  FUN_000121c8();
  FUN_000121c8();
  FUN_000121c8();
  FUN_000121c8();
  local_148 = 0x114;
  RtlGetVersion(&local_148);
  local_198[0] = 0;
  DAT_00037828 = 1;
  DAT_00037820 = (-(uint)(local_144 < 6) & 0xff010000) + 0x6000000;
  DAT_00037824 = DAT_00037824 ^ (DAT_00037808 ^ DAT_00037824) & 0xf;
  lVar2 = ExAllocatePoolWithTag(1,0x13,0x31747345);
  if (lVar2 != 0) {
    local_178[0] = 0x30;
    local_170 = 0;
    local_160 = 0x240;
    local_158 = 0;
    local_150 = 0;
    local_168 = param_2;
    iVar1 = ZwOpenKey(&local_190,0x20019,local_178);
    if (-1 < iVar1) {
      RtlInitUnicodeString(local_188,L"DbgAssertDisable");
      local_1a0 = local_198;
      local_1a8 = 0x13;
      iVar1 = ZwQueryValueKey(local_190,local_188,2,lVar2);
      if ((-1 < iVar1) && (local_198[0] = *(uint *)(lVar2 + 0xc), *(int *)(lVar2 + 4) == 4)) {
        DAT_00037828 = *(char *)(lVar2 + 0xc) == '\0';
      }
      RtlInitUnicodeString(local_188,L"DebugLevel");
      local_1a0 = local_198;
      local_1a8 = 0x13;
      iVar1 = ZwQueryValueKey(local_190,local_188,2,lVar2);
      if ((-1 < iVar1) && (*(int *)(lVar2 + 4) == 4)) {
        DAT_00037824 = *(uint *)(lVar2 + 0xc);
        local_198[0] = DAT_00037824 & 0xf;
      }
      ZwClose(local_190);
    }
    ExFreePoolWithTag(lVar2,0);
  }
  _DAT_00037872 = *param_2 + 2;
  _DAT_00037870 = *param_2;
  DAT_00037878 = ExAllocatePoolWithTag(1,_DAT_00037872,0x31747345);
  if (DAT_00037878 == 0) {
    FUN_000121c8();
  }
  else {
    RtlCopyUnicodeString(&DAT_00037870,param_2);
    iVar1 = FUN_00011f70();
    if (iVar1 == 0) {
      *(code **)(*(longlong *)(param_1 + 0x30) + 8) = FUN_0001257c;
      *(code **)(param_1 + 0x68) = FUN_0001158c;
      *(code **)(param_1 + 0x148) = FUN_0003a878;
      *(code **)(param_1 + 0x120) = FUN_0003b924;
      *(code **)(param_1 + 0x70) = FUN_00039008;
      *(code **)(param_1 + 0x80) = FUN_000390e0;
      *(code **)(param_1 + 0x100) = FUN_00011308;
      *(code **)(param_1 + 0xe0) = FUN_00011008;
      *(code **)(param_1 + 0x88) = FUN_00039198;
      *(code **)(param_1 + 0x90) = FUN_00039198;
      *(code **)(param_1 + 0x128) = FUN_0003c1b0;
      *(code **)(param_1 + 0xe8) = FUN_000115b0;
    }
  }
  FUN_000121c8();
  FUN_00025050(local_28 ^ (ulonglong)auStack_1c8);
  return;
}



/* ===== FUNC entry @ 00041344 ===== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void entry(longlong param_1,short *param_2)

{
  if (((DAT_00037100 == 0) || (DAT_00037100 == 0x2b992ddfa232)) &&
     (DAT_00037100 = (_DAT_fffff78000000320 ^ 0x37100) & 0xffffffffffff, DAT_00037100 == 0)) {
    DAT_00037100 = 0x2b992ddfa232;
  }
  DAT_00037108 = ~DAT_00037100;
  FUN_00041008(param_1,param_2);
  return;
}



