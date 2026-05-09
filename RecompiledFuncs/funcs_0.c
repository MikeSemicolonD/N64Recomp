#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void recomp_entrypoint(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80000400: lui         $sp, 0x803F
    ctx->r29 = S32(0X803F << 16);
    // 0x80000404: j           L_8000161C
    // 0x80000408: ori         $sp, $sp, 0xFFF0
    ctx->r29 = ctx->r29 | 0XFFF0;
    main(rdram, ctx);
    return;
    // 0x80000408: ori         $sp, $sp, 0xFFF0
    ctx->r29 = ctx->r29 | 0XFFF0;
;}
RECOMP_FUNC void func_8000040C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
;}
RECOMP_FUNC void loadOverlay(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80000B20: lui         $v0, 0x8003
    ctx->r2 = S32(0X8003 << 16);
    // 0x80000B24: lw          $v0, 0x75B0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X75B0);
    // 0x80000B28: addiu       $sp, $sp, -0x88
    ctx->r29 = ADD32(ctx->r29, -0X88);
    // 0x80000B2C: sw          $s0, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r16;
    // 0x80000B30: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x80000B34: beq         $s0, $v0, L_80000C34
    if (ctx->r16 == ctx->r2) {
        // 0x80000B38: sw          $ra, 0x84($sp)
        MEM_W(0X84, ctx->r29) = ctx->r31;
            goto L_80000C34;
    }
    // 0x80000B38: sw          $ra, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r31;
    // 0x80000B3C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80000B40: beq         $s0, $v1, L_80000BA8
    if (ctx->r16 == ctx->r3) {
        // 0x80000B44: slti        $v0, $s0, 0x2
        ctx->r2 = SIGNED(ctx->r16) < 0X2 ? 1 : 0;
            goto L_80000BA8;
    }
    // 0x80000B44: slti        $v0, $s0, 0x2
    ctx->r2 = SIGNED(ctx->r16) < 0X2 ? 1 : 0;
    // 0x80000B48: beql        $v0, $zero, L_80000B60
    if (ctx->r2 == 0) {
        // 0x80000B4C: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_80000B60;
    }
    goto skip_0;
    // 0x80000B4C: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    skip_0:
    // 0x80000B50: beq         $s0, $zero, L_80000B70
    if (ctx->r16 == 0) {
        // 0x80000B54: lui         $v0, 0xB00A
        ctx->r2 = S32(0XB00A << 16);
            goto L_80000B70;
    }
    // 0x80000B54: lui         $v0, 0xB00A
    ctx->r2 = S32(0XB00A << 16);
    // 0x80000B58: j           L_80000C24
    // 0x80000B5C: nop

        goto L_80000C24;
    // 0x80000B5C: nop

L_80000B60:
    // 0x80000B60: beq         $s0, $v0, L_80000BE8
    if (ctx->r16 == ctx->r2) {
        // 0x80000B64: lui         $v0, 0xB013
        ctx->r2 = S32(0XB013 << 16);
            goto L_80000BE8;
    }
    // 0x80000B64: lui         $v0, 0xB013
    ctx->r2 = S32(0XB013 << 16);
    // 0x80000B68: j           L_80000C24
    // 0x80000B6C: nop

        goto L_80000C24;
    // 0x80000B6C: nop

L_80000B70:
    // 0x80000B70: addiu       $v0, $v0, 0x5D30
    ctx->r2 = ADD32(ctx->r2, 0X5D30);
    // 0x80000B74: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x80000B78: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x80000B7C: addiu       $v0, $v0, 0x5130
    ctx->r2 = ADD32(ctx->r2, 0X5130);
    // 0x80000B80: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // 0x80000B84: lui         $v0, 0x6
    ctx->r2 = S32(0X6 << 16);
    // 0x80000B88: addiu       $v0, $v0, 0x65A0
    ctx->r2 = ADD32(ctx->r2, 0X65A0);
    // 0x80000B8C: sw          $v0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r2;
    // 0x80000B90: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80000B94: addiu       $v0, $v0, -0x4930
    ctx->r2 = ADD32(ctx->r2, -0X4930);
    // 0x80000B98: sw          $v0, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r2;
    // 0x80000B9C: lui         $v0, 0x0
    ctx->r2 = S32(0X0 << 16);
    // 0x80000BA0: j           L_80000C1C
    // 0x80000BA4: addiu       $v0, $v0, 0x1B30
    ctx->r2 = ADD32(ctx->r2, 0X1B30);
        goto L_80000C1C;
    // 0x80000BA4: addiu       $v0, $v0, 0x1B30
    ctx->r2 = ADD32(ctx->r2, 0X1B30);
L_80000BA8:
    // 0x80000BA8: lui         $v0, 0xB011
    ctx->r2 = S32(0XB011 << 16);
    // 0x80000BAC: addiu       $v0, $v0, -0x3D30
    ctx->r2 = ADD32(ctx->r2, -0X3D30);
    // 0x80000BB0: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x80000BB4: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x80000BB8: addiu       $v0, $v0, 0x5130
    ctx->r2 = ADD32(ctx->r2, 0X5130);
    // 0x80000BBC: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // 0x80000BC0: lui         $v0, 0x3
    ctx->r2 = S32(0X3 << 16);
    // 0x80000BC4: addiu       $v0, $v0, -0x7C10
    ctx->r2 = ADD32(ctx->r2, -0X7C10);
    // 0x80000BC8: sw          $v0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r2;
    // 0x80000BCC: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x80000BD0: addiu       $v0, $v0, -0x2AE0
    ctx->r2 = ADD32(ctx->r2, -0X2AE0);
    // 0x80000BD4: sw          $v0, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r2;
    // 0x80000BD8: lui         $v0, 0x0
    ctx->r2 = S32(0X0 << 16);
    // 0x80000BDC: addiu       $v0, $v0, 0x2EC0
    ctx->r2 = ADD32(ctx->r2, 0X2EC0);
    // 0x80000BE0: j           L_80000C20
    // 0x80000BE4: sw          $s0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r16;
        goto L_80000C20;
    // 0x80000BE4: sw          $s0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r16;
L_80000BE8:
    // 0x80000BE8: addiu       $v0, $v0, 0x7580
    ctx->r2 = ADD32(ctx->r2, 0X7580);
    // 0x80000BEC: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x80000BF0: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x80000BF4: addiu       $v0, $v0, 0x5130
    ctx->r2 = ADD32(ctx->r2, 0X5130);
    // 0x80000BF8: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // 0x80000BFC: lui         $v0, 0x1
    ctx->r2 = S32(0X1 << 16);
    // 0x80000C00: addiu       $v0, $v0, -0x47F0
    ctx->r2 = ADD32(ctx->r2, -0X47F0);
    // 0x80000C04: sw          $v0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r2;
    // 0x80000C08: lui         $v0, 0x800B
    ctx->r2 = S32(0X800B << 16);
    // 0x80000C0C: addiu       $v0, $v0, 0x940
    ctx->r2 = ADD32(ctx->r2, 0X940);
    // 0x80000C10: sw          $v0, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r2;
    // 0x80000C14: lui         $v0, 0x0
    ctx->r2 = S32(0X0 << 16);
    // 0x80000C18: addiu       $v0, $v0, 0x15B0
    ctx->r2 = ADD32(ctx->r2, 0X15B0);
L_80000C1C:
    // 0x80000C1C: sw          $v1, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r3;
L_80000C20:
    // 0x80000C20: sw          $v0, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r2;
L_80000C24:
    // 0x80000C24: jal         0x800033A0
    // 0x80000C28: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    func_800033A0(rdram, ctx);
        goto after_0;
    // 0x80000C28: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    after_0:
    // 0x80000C2C: lui         $v0, 0x8003
    ctx->r2 = S32(0X8003 << 16);
    // 0x80000C30: sw          $s0, 0x75B0($v0)
    MEM_W(0X75B0, ctx->r2) = ctx->r16;
L_80000C34:
    // 0x80000C34: lw          $ra, 0x84($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X84);
    // 0x80000C38: lw          $s0, 0x80($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X80);
    // 0x80000C3C: jr          $ra
    // 0x80000C40: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
    return;
    // 0x80000C40: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
;}
RECOMP_FUNC void func_80000C44(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80000C44: lui         $v0, 0x8003
    ctx->r2 = S32(0X8003 << 16);
    // 0x80000C48: jr          $ra
    // 0x80000C4C: addiu       $v0, $v0, 0x7560
    ctx->r2 = ADD32(ctx->r2, 0X7560);
    return;
    // 0x80000C4C: addiu       $v0, $v0, 0x7560
    ctx->r2 = ADD32(ctx->r2, 0X7560);
;}
RECOMP_FUNC void func_80000C50(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80000C50: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80000C54: lbu         $v0, -0x2DF0($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X2DF0);
    // 0x80000C58: jr          $ra
    // 0x80000C5C: nop

    return;
    // 0x80000C5C: nop

;}
RECOMP_FUNC void func_80000C60(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80000C60: jr          $ra
    // 0x80000C64: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    return;
    // 0x80000C64: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
;}
RECOMP_FUNC void func_80000C68(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80000C68: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x80000C6C: sw          $s2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r18;
    // 0x80000C70: addu        $s2, $a0, $zero
    ctx->r18 = ADD32(ctx->r4, 0);
    // 0x80000C74: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80000C78: addiu       $a0, $a0, -0x2C30
    ctx->r4 = ADD32(ctx->r4, -0X2C30);
    // 0x80000C7C: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x80000C80: sw          $s1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r17;
    // 0x80000C84: jal         0x80034630
    // 0x80000C88: sw          $s0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r16;
    osStopThread_recomp(rdram, ctx);
        goto after_0;
    // 0x80000C88: sw          $s0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r16;
    after_0:
    // 0x80000C8C: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x80000C90: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x80000C94: sw          $a0, -0x1FF8($at)
    MEM_W(-0X1FF8, ctx->r1) = ctx->r4;
    // 0x80000C98: jal         0x800246E8
    // 0x80000C9C: nop

    func_800246E8(rdram, ctx);
        goto after_1;
    // 0x80000C9C: nop

    after_1:
    // 0x80000CA0: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80000CA4: addiu       $v0, $v0, -0x2E00
    ctx->r2 = ADD32(ctx->r2, -0X2E00);
    // 0x80000CA8: lui         $v1, 0x8000
    ctx->r3 = S32(0X8000 << 16);
    // 0x80000CAC: addiu       $v1, $v1, 0x400
    ctx->r3 = ADD32(ctx->r3, 0X400);
    // 0x80000CB0: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x80000CB4: lui         $v1, 0xFFF0
    ctx->r3 = S32(0XFFF0 << 16);
    // 0x80000CB8: addu        $s1, $v0, $v1
    ctx->r17 = ADD32(ctx->r2, ctx->r3);
    // 0x80000CBC: blez        $s1, L_80000D2C
    if (SIGNED(ctx->r17) <= 0) {
        // 0x80000CC0: addiu       $s0, $sp, 0x28
        ctx->r16 = ADD32(ctx->r29, 0X28);
            goto L_80000D2C;
    }
    // 0x80000CC0: addiu       $s0, $sp, 0x28
    ctx->r16 = ADD32(ctx->r29, 0X28);
    // 0x80000CC4: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80000CC8: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    // 0x80000CCC: jal         0x8002B300
    // 0x80000CD0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_2;
    // 0x80000CD0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_2:
    // 0x80000CD4: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // 0x80000CD8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80000CDC: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    // 0x80000CE0: addiu       $v0, $s1, 0xF
    ctx->r2 = ADD32(ctx->r17, 0XF);
    // 0x80000CE4: addiu       $v1, $zero, -0x10
    ctx->r3 = ADD32(0, -0X10);
    // 0x80000CE8: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x80000CEC: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x80000CF0: lui         $v0, 0xB010
    ctx->r2 = S32(0XB010 << 16);
    // 0x80000CF4: addiu       $v0, $v0, 0x1000
    ctx->r2 = ADD32(ctx->r2, 0X1000);
    // 0x80000CF8: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80000CFC: lui         $v0, 0x8010
    ctx->r2 = S32(0X8010 << 16);
    // 0x80000D00: addiu       $v0, $v0, 0x400
    ctx->r2 = ADD32(ctx->r2, 0X400);
    // 0x80000D04: jal         0x8000569C
    // 0x80000D08: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    func_8000569C(rdram, ctx);
        goto after_3;
    // 0x80000D08: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    after_3:
    // 0x80000D0C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80000D10: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80000D14: jal         0x800331D0
    // 0x80000D18: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_4;
    // 0x80000D18: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_4:
    // 0x80000D1C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80000D20: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x80000D24: jal         0x8002C330
    // 0x80000D28: nop

    osInvalICache_recomp(rdram, ctx);
        goto after_5;
    // 0x80000D28: nop

    after_5:
L_80000D2C:
    // 0x80000D2C: jal         0x80003308
    // 0x80000D30: nop

    func_80003308(rdram, ctx);
        goto after_6;
    // 0x80000D30: nop

    after_6:
    // 0x80000D34: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80000D38: lw          $v0, -0x350($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X350);
    // 0x80000D3C: lw          $a0, 0x8($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X8);
    // 0x80000D40: beq         $a0, $zero, L_80000D54
    if (ctx->r4 == 0) {
        // 0x80000D44: nop
    
            goto L_80000D54;
    }
    // 0x80000D44: nop

    // 0x80000D48: lw          $a1, 0xC($v0)
    ctx->r5 = MEM_W(ctx->r2, 0XC);
    // 0x80000D4C: jal         0x80007380
    // 0x80000D50: nop

    func_80007380(rdram, ctx);
        goto after_7;
    // 0x80000D50: nop

    after_7:
L_80000D54:
    // 0x80000D54: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x80000D58: lw          $v1, -0x350($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X350);
    // 0x80000D5C: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x80000D60: sb          $zero, -0x2DEF($at)
    MEM_B(-0X2DEF, ctx->r1) = 0;
    // 0x80000D64: lbu         $a1, 0x20($v1)
    ctx->r5 = MEM_BU(ctx->r3, 0X20);
    // 0x80000D68: beq         $a1, $zero, L_80000DA4
    if (ctx->r5 == 0) {
        // 0x80000D6C: nop
    
            goto L_80000DA4;
    }
    // 0x80000D6C: nop

    // 0x80000D70: lhu         $v0, 0x24($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X24);
    // 0x80000D74: lbu         $a2, 0x21($v1)
    ctx->r6 = MEM_BU(ctx->r3, 0X21);
    // 0x80000D78: lbu         $a3, 0x22($v1)
    ctx->r7 = MEM_BU(ctx->r3, 0X22);
    // 0x80000D7C: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x80000D80: lw          $v0, 0x28($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X28);
    // 0x80000D84: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // 0x80000D88: lw          $a0, 0x1C($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X1C);
    // 0x80000D8C: jal         0x8008EA14
    // 0x80000D90: nop

    func_8008EA14(rdram, ctx);
        goto after_8;
    // 0x80000D90: nop

    after_8:
    // 0x80000D94: bne         $v0, $zero, L_80000DA4
    if (ctx->r2 != 0) {
        // 0x80000D98: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80000DA4;
    }
    // 0x80000D98: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80000D9C: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x80000DA0: sb          $v0, -0x2DEF($at)
    MEM_B(-0X2DEF, ctx->r1) = ctx->r2;
L_80000DA4:
    // 0x80000DA4: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80000DA8: lw          $v0, -0x350($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X350);
    // 0x80000DAC: lw          $v0, 0x4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X4);
    // 0x80000DB0: jalr        $v0
    // 0x80000DB4: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_9;
    // 0x80000DB4: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    after_9:
    // 0x80000DB8: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    // 0x80000DBC: lw          $s2, 0x50($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X50);
    // 0x80000DC0: lw          $s1, 0x4C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X4C);
    // 0x80000DC4: lw          $s0, 0x48($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X48);
    // 0x80000DC8: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x80000DCC: jr          $ra
    // 0x80000DD0: nop

    return;
    // 0x80000DD0: nop

;}
RECOMP_FUNC void func_80000DD4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80000DD4: addu        $t5, $a0, $zero
    ctx->r13 = ADD32(ctx->r4, 0);
    // 0x80000DD8: addu        $t6, $a1, $zero
    ctx->r14 = ADD32(ctx->r5, 0);
    // 0x80000DDC: addu        $a1, $a2, $zero
    ctx->r5 = ADD32(ctx->r6, 0);
    // 0x80000DE0: lh          $v0, 0x12($sp)
    ctx->r2 = MEM_H(ctx->r29, 0X12);
    // 0x80000DE4: lbu         $a0, 0x17($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X17);
    // 0x80000DE8: slti        $v0, $v0, 0x18
    ctx->r2 = SIGNED(ctx->r2) < 0X18 ? 1 : 0;
    // 0x80000DEC: bne         $v0, $zero, L_80000E14
    if (ctx->r2 != 0) {
        // 0x80000DF0: addu        $t1, $a3, $zero
        ctx->r9 = ADD32(ctx->r7, 0);
            goto L_80000E14;
    }
    // 0x80000DF0: addu        $t1, $a3, $zero
    ctx->r9 = ADD32(ctx->r7, 0);
    // 0x80000DF4: sll         $v1, $a2, 16
    ctx->r3 = S32(ctx->r6 << 16);
    // 0x80000DF8: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
    // 0x80000DFC: sll         $v0, $a3, 16
    ctx->r2 = S32(ctx->r7 << 16);
    // 0x80000E00: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80000E04: mult        $v1, $v0
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80000E08: mflo        $v1
    ctx->r3 = lo;
    // 0x80000E0C: j           L_80000E30
    // 0x80000E10: sll         $t0, $v1, 2
    ctx->r8 = S32(ctx->r3 << 2);
        goto L_80000E30;
    // 0x80000E10: sll         $t0, $v1, 2
    ctx->r8 = S32(ctx->r3 << 2);
L_80000E14:
    // 0x80000E14: sll         $v1, $a2, 16
    ctx->r3 = S32(ctx->r6 << 16);
    // 0x80000E18: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
    // 0x80000E1C: sll         $v0, $a3, 16
    ctx->r2 = S32(ctx->r7 << 16);
    // 0x80000E20: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80000E24: mult        $v1, $v0
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80000E28: mflo        $v1
    ctx->r3 = lo;
    // 0x80000E2C: sll         $t0, $v1, 1
    ctx->r8 = S32(ctx->r3 << 1);
L_80000E30:
    // 0x80000E30: beq         $a0, $zero, L_80000E54
    if (ctx->r4 == 0) {
        // 0x80000E34: sll         $v1, $a1, 16
        ctx->r3 = S32(ctx->r5 << 16);
            goto L_80000E54;
    }
    // 0x80000E34: sll         $v1, $a1, 16
    ctx->r3 = S32(ctx->r5 << 16);
    // 0x80000E38: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
    // 0x80000E3C: sll         $v0, $t1, 16
    ctx->r2 = S32(ctx->r9 << 16);
    // 0x80000E40: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80000E44: mult        $v1, $v0
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80000E48: mflo        $v1
    ctx->r3 = lo;
    // 0x80000E4C: j           L_80000E58
    // 0x80000E50: sll         $a3, $v1, 1
    ctx->r7 = S32(ctx->r3 << 1);
        goto L_80000E58;
    // 0x80000E50: sll         $a3, $v1, 1
    ctx->r7 = S32(ctx->r3 << 1);
L_80000E54:
    // 0x80000E54: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
L_80000E58:
    // 0x80000E58: addiu       $v0, $a3, 0x3F
    ctx->r2 = ADD32(ctx->r7, 0X3F);
    // 0x80000E5C: addiu       $a2, $zero, -0x40
    ctx->r6 = ADD32(0, -0X40);
    // 0x80000E60: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x80000E64: lw          $a1, -0x350($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X350);
    // 0x80000E68: and         $a3, $v0, $a2
    ctx->r7 = ctx->r2 & ctx->r6;
    // 0x80000E6C: addiu       $v1, $t0, 0x3F
    ctx->r3 = ADD32(ctx->r8, 0X3F);
    // 0x80000E70: and         $t0, $v1, $a2
    ctx->r8 = ctx->r3 & ctx->r6;
    // 0x80000E74: lw          $a0, 0x2C($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X2C);
    // 0x80000E78: lw          $v0, 0x30($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X30);
    // 0x80000E7C: lw          $v1, 0x34($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X34);
    // 0x80000E80: sll         $t1, $a0, 6
    ctx->r9 = S32(ctx->r4 << 6);
    // 0x80000E84: addiu       $v0, $v0, 0xF
    ctx->r2 = ADD32(ctx->r2, 0XF);
    // 0x80000E88: addiu       $a0, $zero, -0x10
    ctx->r4 = ADD32(0, -0X10);
    // 0x80000E8C: and         $t2, $v0, $a0
    ctx->r10 = ctx->r2 & ctx->r4;
    // 0x80000E90: addiu       $v1, $v1, 0xF
    ctx->r3 = ADD32(ctx->r3, 0XF);
    // 0x80000E94: lw          $v0, 0x38($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X38);
    // 0x80000E98: and         $t4, $v1, $a0
    ctx->r12 = ctx->r3 & ctx->r4;
    // 0x80000E9C: lw          $v1, 0x44($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X44);
    // 0x80000EA0: addiu       $v0, $v0, 0xF
    ctx->r2 = ADD32(ctx->r2, 0XF);
    // 0x80000EA4: andi        $v1, $v1, 0x2000
    ctx->r3 = ctx->r3 & 0X2000;
    // 0x80000EA8: beq         $v1, $zero, L_80000EB8
    if (ctx->r3 == 0) {
        // 0x80000EAC: and         $t3, $v0, $a0
        ctx->r11 = ctx->r2 & ctx->r4;
            goto L_80000EB8;
    }
    // 0x80000EAC: and         $t3, $v0, $a0
    ctx->r11 = ctx->r2 & ctx->r4;
    // 0x80000EB0: j           L_80000EC8
    // 0x80000EB4: lui         $a0, 0x8040
    ctx->r4 = S32(0X8040 << 16);
        goto L_80000EC8;
    // 0x80000EB4: lui         $a0, 0x8040
    ctx->r4 = S32(0X8040 << 16);
L_80000EB8:
    // 0x80000EB8: lui         $v1, 0x8000
    ctx->r3 = S32(0X8000 << 16);
    // 0x80000EBC: lw          $v1, 0x318($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X318);
    // 0x80000EC0: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x80000EC4: or          $a0, $v1, $v0
    ctx->r4 = ctx->r3 | ctx->r2;
L_80000EC8:
    // 0x80000EC8: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80000ECC: lw          $v0, -0x350($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X350);
    // 0x80000ED0: subu        $a1, $a0, $a3
    ctx->r5 = SUB32(ctx->r4, ctx->r7);
    // 0x80000ED4: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x80000ED8: sw          $a1, 0x63E4($at)
    MEM_W(0X63E4, ctx->r1) = ctx->r5;
    // 0x80000EDC: lw          $v0, 0x44($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X44);
    // 0x80000EE0: sltiu       $v1, $a3, 0x1
    ctx->r3 = ctx->r7 < 0X1 ? 1 : 0;
    // 0x80000EE4: srl         $v0, $v0, 10
    ctx->r2 = S32(U32(ctx->r2) >> 10);
    // 0x80000EE8: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x80000EEC: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x80000EF0: beq         $v0, $zero, L_80000F0C
    if (ctx->r2 == 0) {
        // 0x80000EF4: subu        $v0, $a1, $t0
        ctx->r2 = SUB32(ctx->r5, ctx->r8);
            goto L_80000F0C;
    }
    // 0x80000EF4: subu        $v0, $a1, $t0
    ctx->r2 = SUB32(ctx->r5, ctx->r8);
    // 0x80000EF8: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x80000EFC: sw          $v0, 0x63D8($at)
    MEM_W(0X63D8, ctx->r1) = ctx->r2;
    // 0x80000F00: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80000F04: j           L_80000F28
    // 0x80000F08: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
        goto L_80000F28;
    // 0x80000F08: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
L_80000F0C:
    // 0x80000F0C: lui         $v1, 0x10
    ctx->r3 = S32(0X10 << 16);
    // 0x80000F10: addu        $v0, $t0, $v1
    ctx->r2 = ADD32(ctx->r8, ctx->r3);
    // 0x80000F14: subu        $v0, $a0, $v0
    ctx->r2 = SUB32(ctx->r4, ctx->r2);
    // 0x80000F18: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x80000F1C: sw          $v0, 0x63D8($at)
    MEM_W(0X63D8, ctx->r1) = ctx->r2;
    // 0x80000F20: subu        $a1, $v1, $a3
    ctx->r5 = SUB32(ctx->r3, ctx->r7);
    // 0x80000F24: subu        $a0, $a0, $v1
    ctx->r4 = SUB32(ctx->r4, ctx->r3);
L_80000F28:
    // 0x80000F28: lui         $a3, 0x8011
    ctx->r7 = S32(0X8011 << 16);
    // 0x80000F2C: addiu       $a3, $a3, 0x63DC
    ctx->r7 = ADD32(ctx->r7, 0X63DC);
    // 0x80000F30: lw          $v0, -0x4($a3)
    ctx->r2 = MEM_W(ctx->r7, -0X4);
    // 0x80000F34: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x80000F38: lw          $v1, -0x350($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X350);
    // 0x80000F3C: subu        $a2, $v0, $t0
    ctx->r6 = SUB32(ctx->r2, ctx->r8);
    // 0x80000F40: sw          $a2, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r6;
    // 0x80000F44: lbu         $v0, 0x19($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X19);
    // 0x80000F48: beq         $v0, $zero, L_80000F58
    if (ctx->r2 == 0) {
        // 0x80000F4C: subu        $v0, $a2, $t0
        ctx->r2 = SUB32(ctx->r6, ctx->r8);
            goto L_80000F58;
    }
    // 0x80000F4C: subu        $v0, $a2, $t0
    ctx->r2 = SUB32(ctx->r6, ctx->r8);
    // 0x80000F50: j           L_80000F60
    // 0x80000F54: sw          $v0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r2;
        goto L_80000F60;
    // 0x80000F54: sw          $v0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r2;
L_80000F58:
    // 0x80000F58: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x80000F5C: sw          $zero, 0x63E0($at)
    MEM_W(0X63E0, ctx->r1) = 0;
L_80000F60:
    // 0x80000F60: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80000F64: lw          $v0, -0x350($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X350);
    // 0x80000F68: lw          $v0, 0x44($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X44);
    // 0x80000F6C: andi        $v0, $v0, 0x80
    ctx->r2 = ctx->r2 & 0X80;
    // 0x80000F70: beq         $v0, $zero, L_80000F88
    if (ctx->r2 == 0) {
        // 0x80000F74: sltu        $v0, $t1, $a1
        ctx->r2 = ctx->r9 < ctx->r5 ? 1 : 0;
            goto L_80000F88;
    }
    // 0x80000F74: sltu        $v0, $t1, $a1
    ctx->r2 = ctx->r9 < ctx->r5 ? 1 : 0;
    // 0x80000F78: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x80000F7C: lw          $v1, 0x63D8($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X63D8);
    // 0x80000F80: j           L_80000FA0
    // 0x80000F84: nop

        goto L_80000FA0;
    // 0x80000F84: nop

L_80000F88:
    // 0x80000F88: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x80000F8C: lw          $v1, 0x63E0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X63E0);
    // 0x80000F90: bne         $v1, $zero, L_80000FA0
    if (ctx->r3 != 0) {
        // 0x80000F94: nop
    
            goto L_80000FA0;
    }
    // 0x80000F94: nop

    // 0x80000F98: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x80000F9C: lw          $v1, 0x63DC($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X63DC);
L_80000FA0:
    // 0x80000FA0: beql        $v0, $zero, L_80000FBC
    if (ctx->r2 == 0) {
        // 0x80000FA4: subu        $v1, $v1, $t1
        ctx->r3 = SUB32(ctx->r3, ctx->r9);
            goto L_80000FBC;
    }
    goto skip_0;
    // 0x80000FA4: subu        $v1, $v1, $t1
    ctx->r3 = SUB32(ctx->r3, ctx->r9);
    skip_0:
    // 0x80000FA8: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x80000FAC: sw          $a0, 0x63F0($at)
    MEM_W(0X63F0, ctx->r1) = ctx->r4;
    // 0x80000FB0: addu        $a0, $a0, $t1
    ctx->r4 = ADD32(ctx->r4, ctx->r9);
    // 0x80000FB4: j           L_80000FC4
    // 0x80000FB8: subu        $a1, $a1, $t1
    ctx->r5 = SUB32(ctx->r5, ctx->r9);
        goto L_80000FC4;
    // 0x80000FB8: subu        $a1, $a1, $t1
    ctx->r5 = SUB32(ctx->r5, ctx->r9);
L_80000FBC:
    // 0x80000FBC: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x80000FC0: sw          $v1, 0x63F0($at)
    MEM_W(0X63F0, ctx->r1) = ctx->r3;
L_80000FC4:
    // 0x80000FC4: sltu        $v0, $t1, $a1
    ctx->r2 = ctx->r9 < ctx->r5 ? 1 : 0;
    // 0x80000FC8: beql        $v0, $zero, L_80000FE4
    if (ctx->r2 == 0) {
        // 0x80000FCC: subu        $v1, $v1, $t1
        ctx->r3 = SUB32(ctx->r3, ctx->r9);
            goto L_80000FE4;
    }
    goto skip_1;
    // 0x80000FCC: subu        $v1, $v1, $t1
    ctx->r3 = SUB32(ctx->r3, ctx->r9);
    skip_1:
    // 0x80000FD0: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x80000FD4: sw          $a0, 0x63F4($at)
    MEM_W(0X63F4, ctx->r1) = ctx->r4;
    // 0x80000FD8: addu        $a0, $a0, $t1
    ctx->r4 = ADD32(ctx->r4, ctx->r9);
    // 0x80000FDC: j           L_80000FEC
    // 0x80000FE0: subu        $a1, $a1, $t1
    ctx->r5 = SUB32(ctx->r5, ctx->r9);
        goto L_80000FEC;
    // 0x80000FE0: subu        $a1, $a1, $t1
    ctx->r5 = SUB32(ctx->r5, ctx->r9);
L_80000FE4:
    // 0x80000FE4: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x80000FE8: sw          $v1, 0x63F4($at)
    MEM_W(0X63F4, ctx->r1) = ctx->r3;
L_80000FEC:
    // 0x80000FEC: sltu        $v0, $t2, $a1
    ctx->r2 = ctx->r10 < ctx->r5 ? 1 : 0;
    // 0x80000FF0: beql        $v0, $zero, L_8000100C
    if (ctx->r2 == 0) {
        // 0x80000FF4: subu        $v1, $v1, $t2
        ctx->r3 = SUB32(ctx->r3, ctx->r10);
            goto L_8000100C;
    }
    goto skip_2;
    // 0x80000FF4: subu        $v1, $v1, $t2
    ctx->r3 = SUB32(ctx->r3, ctx->r10);
    skip_2:
    // 0x80000FF8: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x80000FFC: sw          $a0, 0x63E8($at)
    MEM_W(0X63E8, ctx->r1) = ctx->r4;
    // 0x80001000: addu        $a0, $a0, $t2
    ctx->r4 = ADD32(ctx->r4, ctx->r10);
    // 0x80001004: j           L_80001014
    // 0x80001008: subu        $a1, $a1, $t2
    ctx->r5 = SUB32(ctx->r5, ctx->r10);
        goto L_80001014;
    // 0x80001008: subu        $a1, $a1, $t2
    ctx->r5 = SUB32(ctx->r5, ctx->r10);
L_8000100C:
    // 0x8000100C: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x80001010: sw          $v1, 0x63E8($at)
    MEM_W(0X63E8, ctx->r1) = ctx->r3;
L_80001014:
    // 0x80001014: sltu        $v0, $t3, $a1
    ctx->r2 = ctx->r11 < ctx->r5 ? 1 : 0;
    // 0x80001018: beql        $v0, $zero, L_80001034
    if (ctx->r2 == 0) {
        // 0x8000101C: subu        $v1, $v1, $t3
        ctx->r3 = SUB32(ctx->r3, ctx->r11);
            goto L_80001034;
    }
    goto skip_3;
    // 0x8000101C: subu        $v1, $v1, $t3
    ctx->r3 = SUB32(ctx->r3, ctx->r11);
    skip_3:
    // 0x80001020: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x80001024: sw          $a0, 0x63F8($at)
    MEM_W(0X63F8, ctx->r1) = ctx->r4;
    // 0x80001028: addu        $a0, $a0, $t3
    ctx->r4 = ADD32(ctx->r4, ctx->r11);
    // 0x8000102C: j           L_8000103C
    // 0x80001030: subu        $a1, $a1, $t3
    ctx->r5 = SUB32(ctx->r5, ctx->r11);
        goto L_8000103C;
    // 0x80001030: subu        $a1, $a1, $t3
    ctx->r5 = SUB32(ctx->r5, ctx->r11);
L_80001034:
    // 0x80001034: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x80001038: sw          $v1, 0x63F8($at)
    MEM_W(0X63F8, ctx->r1) = ctx->r3;
L_8000103C:
    // 0x8000103C: sltu        $v0, $t4, $a1
    ctx->r2 = ctx->r12 < ctx->r5 ? 1 : 0;
    // 0x80001040: beql        $v0, $zero, L_80001058
    if (ctx->r2 == 0) {
        // 0x80001044: subu        $v1, $v1, $t4
        ctx->r3 = SUB32(ctx->r3, ctx->r12);
            goto L_80001058;
    }
    goto skip_4;
    // 0x80001044: subu        $v1, $v1, $t4
    ctx->r3 = SUB32(ctx->r3, ctx->r12);
    skip_4:
    // 0x80001048: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x8000104C: sw          $a0, 0x63EC($at)
    MEM_W(0X63EC, ctx->r1) = ctx->r4;
    // 0x80001050: j           L_80001060
    // 0x80001054: addu        $a0, $a0, $t4
    ctx->r4 = ADD32(ctx->r4, ctx->r12);
        goto L_80001060;
    // 0x80001054: addu        $a0, $a0, $t4
    ctx->r4 = ADD32(ctx->r4, ctx->r12);
L_80001058:
    // 0x80001058: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x8000105C: sw          $v1, 0x63EC($at)
    MEM_W(0X63EC, ctx->r1) = ctx->r3;
L_80001060:
    // 0x80001060: bne         $a0, $zero, L_80001074
    if (ctx->r4 != 0) {
        // 0x80001064: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80001074;
    }
    // 0x80001064: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80001068: sw          $v1, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r3;
    // 0x8000106C: j           L_80001080
    // 0x80001070: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
        goto L_80001080;
    // 0x80001070: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_80001074:
    // 0x80001074: sw          $v1, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r3;
    // 0x80001078: subu        $v1, $a0, $v1
    ctx->r3 = SUB32(ctx->r4, ctx->r3);
    // 0x8000107C: sw          $v1, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r3;
L_80001080:
    // 0x80001080: jr          $ra
    // 0x80001084: nop

    return;
    // 0x80001084: nop

;}
RECOMP_FUNC void thread3_video_handle(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80001088: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x8000108C: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80001090: addiu       $a0, $a0, -0x2A80
    ctx->r4 = ADD32(ctx->r4, -0X2A80);
    // 0x80001094: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x80001098: addiu       $a1, $a1, -0x2030
    ctx->r5 = ADD32(ctx->r5, -0X2030);
    // 0x8000109C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800010A0: sw          $ra, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r31;
    // 0x800010A4: sw          $s5, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r21;
    // 0x800010A8: sw          $s4, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r20;
    // 0x800010AC: sw          $s3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r19;
    // 0x800010B0: sw          $s2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r18;
    // 0x800010B4: sw          $s1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r17;
    // 0x800010B8: jal         0x8002B300
    // 0x800010BC: sw          $s0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r16;
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_0;
    // 0x800010BC: sw          $s0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r16;
    after_0:
    // 0x800010C0: lui         $s0, 0x8011
    ctx->r16 = S32(0X8011 << 16);
    // 0x800010C4: addiu       $s0, $s0, -0x2260
    ctx->r16 = ADD32(ctx->r16, -0X2260);
    // 0x800010C8: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800010CC: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x800010D0: lui         $a2, 0x8000
    ctx->r6 = S32(0X8000 << 16);
    // 0x800010D4: addiu       $a2, $a2, 0x16AC
    ctx->r6 = ADD32(ctx->r6, 0X16AC);
    // 0x800010D8: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // 0x800010DC: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800010E0: addiu       $v0, $v0, -0x2260
    ctx->r2 = ADD32(ctx->r2, -0X2260);
    // 0x800010E4: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x800010E8: addiu       $v0, $zero, 0x7F
    ctx->r2 = ADD32(0, 0X7F);
    // 0x800010EC: jal         0x8002B330
    // 0x800010F0: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    osCreateThread_recomp(rdram, ctx);
        goto after_1;
    // 0x800010F0: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    after_1:
    // 0x800010F4: jal         0x800344E0
    // 0x800010F8: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    osStartThread_recomp(rdram, ctx);
        goto after_2;
    // 0x800010F8: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_2:
    // 0x800010FC: jal         0x80000C44
    // 0x80001100: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    func_80000C44(rdram, ctx);
        goto after_3;
    // 0x80001100: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_3:
    // 0x80001104: addu        $a3, $v0, $zero
    ctx->r7 = ADD32(ctx->r2, 0);
    // 0x80001108: lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X0);
    // 0x8000110C: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x80001110: sw          $a3, -0x350($at)
    MEM_W(-0X350, ctx->r1) = ctx->r7;
    // 0x80001114: bne         $v0, $zero, L_80001134
    if (ctx->r2 != 0) {
        // 0x80001118: sll         $v0, $s1, 16
        ctx->r2 = S32(ctx->r17 << 16);
            goto L_80001134;
    }
    // 0x80001118: sll         $v0, $s1, 16
    ctx->r2 = S32(ctx->r17 << 16);
    // 0x8000111C: lhu         $s2, 0x12($a3)
    ctx->r18 = MEM_HU(ctx->r7, 0X12);
    // 0x80001120: lhu         $s3, 0x14($a3)
    ctx->r19 = MEM_HU(ctx->r7, 0X14);
    // 0x80001124: lhu         $s1, 0x16($a3)
    ctx->r17 = MEM_HU(ctx->r7, 0X16);
    // 0x80001128: lhu         $s4, 0x40($a3)
    ctx->r20 = MEM_HU(ctx->r7, 0X40);
    // 0x8000112C: lhu         $s5, 0x42($a3)
    ctx->r21 = MEM_HU(ctx->r7, 0X42);
    // 0x80001130: sll         $v0, $s1, 16
    ctx->r2 = S32(ctx->r17 << 16);
L_80001134:
    // 0x80001134: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80001138: addiu       $v1, $zero, 0x18
    ctx->r3 = ADD32(0, 0X18);
    // 0x8000113C: beql        $v0, $v1, L_80001144
    if (ctx->r2 == ctx->r3) {
        // 0x80001140: addiu       $s1, $zero, 0x20
        ctx->r17 = ADD32(0, 0X20);
            goto L_80001144;
    }
    goto skip_0;
    // 0x80001140: addiu       $s1, $zero, 0x20
    ctx->r17 = ADD32(0, 0X20);
    skip_0:
L_80001144:
    // 0x80001144: lui         $s0, 0x8011
    ctx->r16 = S32(0X8011 << 16);
    // 0x80001148: addiu       $s0, $s0, -0x2E00
    ctx->r16 = ADD32(ctx->r16, -0X2E00);
    // 0x8000114C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80001150: addiu       $a1, $sp, 0x48
    ctx->r5 = ADD32(ctx->r29, 0X48);
    // 0x80001154: sll         $a2, $s2, 16
    ctx->r6 = S32(ctx->r18 << 16);
    // 0x80001158: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
    // 0x8000115C: sll         $v0, $s1, 16
    ctx->r2 = S32(ctx->r17 << 16);
    // 0x80001160: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80001164: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x80001168: lw          $v0, 0x44($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X44);
    // 0x8000116C: sll         $a3, $s3, 16
    ctx->r7 = S32(ctx->r19 << 16);
    // 0x80001170: sra         $a3, $a3, 16
    ctx->r7 = S32(SIGNED(ctx->r7) >> 16);
    // 0x80001174: srl         $v0, $v0, 9
    ctx->r2 = S32(U32(ctx->r2) >> 9);
    // 0x80001178: xori        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 ^ 0X1;
    // 0x8000117C: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x80001180: jal         0x80000DD4
    // 0x80001184: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    func_80000DD4(rdram, ctx);
        goto after_4;
    // 0x80001184: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    after_4:
    // 0x80001188: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x8000118C: beq         $v0, $zero, L_800011A4
    if (ctx->r2 == 0) {
        // 0x80001190: addiu       $a0, $zero, 0x1
        ctx->r4 = ADD32(0, 0X1);
            goto L_800011A4;
    }
    // 0x80001190: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80001194: lui         $a3, 0x8011
    ctx->r7 = S32(0X8011 << 16);
    // 0x80001198: lw          $a3, 0x63E4($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X63E4);
    // 0x8000119C: j           L_800011B0
    // 0x800011A0: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
        goto L_800011B0;
    // 0x800011A0: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
L_800011A4:
    // 0x800011A4: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x800011A8: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x800011AC: lw          $a3, 0x48($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X48);
L_800011B0:
    // 0x800011B0: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800011B4: addiu       $v0, $v0, -0x2E00
    ctx->r2 = ADD32(ctx->r2, -0X2E00);
    // 0x800011B8: lui         $a2, 0x4
    ctx->r6 = S32(0X4 << 16);
    // 0x800011BC: addiu       $a2, $a2, 0x7490
    ctx->r6 = ADD32(ctx->r6, 0X7490);
    // 0x800011C0: jal         0x80002150
    // 0x800011C4: addu        $a2, $v0, $a2
    ctx->r6 = ADD32(ctx->r2, ctx->r6);
    func_80002150(rdram, ctx);
        goto after_5;
    // 0x800011C4: addu        $a2, $v0, $a2
    ctx->r6 = ADD32(ctx->r2, ctx->r6);
    after_5:
    // 0x800011C8: jal         0x80006C00
    // 0x800011CC: nop

    func_80006C00(rdram, ctx);
        goto after_6;
    // 0x800011CC: nop

    after_6:
    // 0x800011D0: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x800011D4: bne         $v0, $zero, L_800011E4
    if (ctx->r2 != 0) {
        // 0x800011D8: nop
    
            goto L_800011E4;
    }
    // 0x800011D8: nop

L_800011DC:
    // 0x800011DC: j           L_800011DC
    pause_self(rdram);
    // 0x800011E0: nop

L_800011E4:
    // 0x800011E4: lui         $a1, 0x8000
    ctx->r5 = S32(0X8000 << 16);
    // 0x800011E8: addiu       $a1, $a1, 0xC60
    ctx->r5 = ADD32(ctx->r5, 0XC60);
    // 0x800011EC: jal         0x800045E8
    // 0x800011F0: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    func_800045E8(rdram, ctx);
        goto after_7;
    // 0x800011F0: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_7:
    // 0x800011F4: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x800011F8: bne         $v0, $zero, L_80001208
    if (ctx->r2 != 0) {
        // 0x800011FC: nop
    
            goto L_80001208;
    }
    // 0x800011FC: nop

L_80001200:
    // 0x80001200: j           L_80001200
    pause_self(rdram);
    // 0x80001204: nop

L_80001208:
    // 0x80001208: jal         0x80003380
    // 0x8000120C: nop

    func_80003380(rdram, ctx);
        goto after_8;
    // 0x8000120C: nop

    after_8:
    // 0x80001210: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x80001214: bne         $v0, $zero, L_80001224
    if (ctx->r2 != 0) {
        // 0x80001218: nop
    
            goto L_80001224;
    }
    // 0x80001218: nop

L_8000121C:
    // 0x8000121C: j           L_8000121C
    pause_self(rdram);
    // 0x80001220: nop

L_80001224:
    // 0x80001224: jal         0x8000274C
    // 0x80001228: nop

    setViModeType(rdram, ctx);
        goto after_9;
    // 0x80001228: nop

    after_9:
    // 0x8000122C: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80001230: lw          $a0, 0x63E4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X63E4);
    // 0x80001234: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x80001238: lw          $a1, 0x63E8($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X63E8);
    // 0x8000123C: lui         $a2, 0x8011
    ctx->r6 = S32(0X8011 << 16);
    // 0x80001240: lw          $a2, -0x350($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X350);
    // 0x80001244: sll         $v0, $s1, 16
    ctx->r2 = S32(ctx->r17 << 16);
    // 0x80001248: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8000124C: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x80001250: addiu       $v1, $v1, 0x63D8
    ctx->r3 = ADD32(ctx->r3, 0X63D8);
    // 0x80001254: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x80001258: sw          $v1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r3;
    // 0x8000125C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80001260: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80001264: lw          $v0, 0x30($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X30);
    // 0x80001268: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x8000126C: lw          $a0, 0x63F8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X63F8);
    // 0x80001270: addiu       $v1, $v1, 0x18
    ctx->r3 = ADD32(ctx->r3, 0X18);
    // 0x80001274: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    // 0x80001278: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x8000127C: lw          $v1, 0x63EC($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X63EC);
    // 0x80001280: addiu       $v0, $v0, 0xF
    ctx->r2 = ADD32(ctx->r2, 0XF);
    // 0x80001284: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80001288: addiu       $a0, $zero, -0x10
    ctx->r4 = ADD32(0, -0X10);
    // 0x8000128C: and         $v0, $v0, $a0
    ctx->r2 = ctx->r2 & ctx->r4;
    // 0x80001290: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x80001294: lw          $v0, 0x38($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X38);
    // 0x80001298: sw          $v1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r3;
    // 0x8000129C: addiu       $v0, $v0, 0xF
    ctx->r2 = ADD32(ctx->r2, 0XF);
    // 0x800012A0: and         $v0, $v0, $a0
    ctx->r2 = ctx->r2 & ctx->r4;
    // 0x800012A4: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x800012A8: lw          $v0, 0x34($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X34);
    // 0x800012AC: addiu       $v0, $v0, 0xF
    ctx->r2 = ADD32(ctx->r2, 0XF);
    // 0x800012B0: and         $v0, $v0, $a0
    ctx->r2 = ctx->r2 & ctx->r4;
    // 0x800012B4: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x800012B8: lw          $v0, 0x44($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X44);
    // 0x800012BC: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    // 0x800012C0: lbu         $v0, 0x18($a2)
    ctx->r2 = MEM_BU(ctx->r6, 0X18);
    // 0x800012C4: addu        $a3, $s5, $zero
    ctx->r7 = ADD32(ctx->r21, 0);
    // 0x800012C8: sll         $a1, $s3, 16
    ctx->r5 = S32(ctx->r19 << 16);
    // 0x800012CC: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    // 0x800012D0: lhu         $v0, 0x3C($a2)
    ctx->r2 = MEM_HU(ctx->r6, 0X3C);
    // 0x800012D4: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x800012D8: sll         $a0, $s2, 16
    ctx->r4 = S32(ctx->r18 << 16);
    // 0x800012DC: sw          $v0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r2;
    // 0x800012E0: lhu         $v0, 0x3E($a2)
    ctx->r2 = MEM_HU(ctx->r6, 0X3E);
    // 0x800012E4: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x800012E8: addu        $a2, $s4, $zero
    ctx->r6 = ADD32(ctx->r20, 0);
    // 0x800012EC: jal         0x80018468
    // 0x800012F0: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    func_80018468(rdram, ctx);
        goto after_10;
    // 0x800012F0: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    after_10:
    // 0x800012F4: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800012F8: lw          $v0, -0x350($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X350);
    // 0x800012FC: lw          $v0, 0x4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X4);
    // 0x80001300: beq         $v0, $zero, L_80001324
    if (ctx->r2 == 0) {
        // 0x80001304: addiu       $a1, $zero, 0x2000
        ctx->r5 = ADD32(0, 0X2000);
            goto L_80001324;
    }
    // 0x80001304: addiu       $a1, $zero, 0x2000
    ctx->r5 = ADD32(0, 0X2000);
    // 0x80001308: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    // 0x8000130C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    // 0x80001310: addiu       $a3, $a3, 0xC68
    ctx->r7 = ADD32(ctx->r7, 0XC68);
    // 0x80001314: jal         0x80006C28
    // 0x80001318: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    func_80006C28(rdram, ctx);
        goto after_11;
    // 0x80001318: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    after_11:
    // 0x8000131C: jal         0x80006D9C
    // 0x80001320: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    func_80006D9C(rdram, ctx);
        goto after_12;
    // 0x80001320: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    after_12:
L_80001324:
    // 0x80001324: j           L_80001324
    pause_self(rdram);
    // 0x80001328: nop

    // 0x8000132C: lw          $ra, 0x68($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X68);
    // 0x80001330: lw          $s5, 0x64($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X64);
    // 0x80001334: lw          $s4, 0x60($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X60);
    // 0x80001338: lw          $s3, 0x5C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X5C);
    // 0x8000133C: lw          $s2, 0x58($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X58);
    // 0x80001340: lw          $s1, 0x54($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X54);
    // 0x80001344: lw          $s0, 0x50($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X50);
    // 0x80001348: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    // 0x8000134C: jr          $ra
    // 0x80001350: nop

    return;
    // 0x80001350: nop

;}
RECOMP_FUNC void func_80001354(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80001354: addiu       $sp, $sp, -0x80
    ctx->r29 = ADD32(ctx->r29, -0X80);
    // 0x80001358: sw          $s3, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r19;
    // 0x8000135C: addu        $s3, $a0, $zero
    ctx->r19 = ADD32(ctx->r4, 0);
    // 0x80001360: sw          $s0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r16;
    // 0x80001364: addu        $s0, $a1, $zero
    ctx->r16 = ADD32(ctx->r5, 0);
    // 0x80001368: sw          $s2, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r18;
    // 0x8000136C: addu        $s2, $a2, $zero
    ctx->r18 = ADD32(ctx->r6, 0);
    // 0x80001370: sw          $ra, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r31;
    // 0x80001374: sw          $fp, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r30;
    // 0x80001378: sw          $s7, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r23;
    // 0x8000137C: sw          $s6, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r22;
    // 0x80001380: sw          $s5, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r21;
    // 0x80001384: sw          $s4, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r20;
    // 0x80001388: jal         0x8008ED00
    // 0x8000138C: sw          $s1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r17;
    func_8008ED00(rdram, ctx);
        goto after_0;
    // 0x8000138C: sw          $s1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r17;
    after_0:
    // 0x80001390: lhu         $s1, 0x6($s3)
    ctx->r17 = MEM_HU(ctx->r19, 0X6);
    // 0x80001394: lhu         $s5, 0x2($s3)
    ctx->r21 = MEM_HU(ctx->r19, 0X2);
    // 0x80001398: lhu         $s6, 0x4($s3)
    ctx->r22 = MEM_HU(ctx->r19, 0X4);
    // 0x8000139C: lhu         $fp, 0x14($s0)
    ctx->r30 = MEM_HU(ctx->r16, 0X14);
    // 0x800013A0: lh          $v1, 0x6($s3)
    ctx->r3 = MEM_H(ctx->r19, 0X6);
    // 0x800013A4: lhu         $s7, 0x16($s0)
    ctx->r23 = MEM_HU(ctx->r16, 0X16);
    // 0x800013A8: addiu       $v0, $zero, 0x18
    ctx->r2 = ADD32(0, 0X18);
    // 0x800013AC: beql        $v1, $v0, L_800013B4
    if (ctx->r3 == ctx->r2) {
        // 0x800013B0: addiu       $s1, $zero, 0x20
        ctx->r17 = ADD32(0, 0X20);
            goto L_800013B4;
    }
    goto skip_0;
    // 0x800013B0: addiu       $s1, $zero, 0x20
    ctx->r17 = ADD32(0, 0X20);
    skip_0:
L_800013B4:
    // 0x800013B4: lui         $s4, 0x8011
    ctx->r20 = S32(0X8011 << 16);
    // 0x800013B8: addiu       $s4, $s4, -0x2DF8
    ctx->r20 = ADD32(ctx->r20, -0X2DF8);
    // 0x800013BC: addu        $a0, $s4, $zero
    ctx->r4 = ADD32(ctx->r20, 0);
    // 0x800013C0: addiu       $a1, $sp, 0x48
    ctx->r5 = ADD32(ctx->r29, 0X48);
    // 0x800013C4: sll         $a2, $s5, 16
    ctx->r6 = S32(ctx->r21 << 16);
    // 0x800013C8: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
    // 0x800013CC: sll         $v0, $s1, 16
    ctx->r2 = S32(ctx->r17 << 16);
    // 0x800013D0: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x800013D4: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x800013D8: lw          $v0, 0x18($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X18);
    // 0x800013DC: sll         $a3, $s6, 16
    ctx->r7 = S32(ctx->r22 << 16);
    // 0x800013E0: sra         $a3, $a3, 16
    ctx->r7 = S32(SIGNED(ctx->r7) >> 16);
    // 0x800013E4: srl         $v0, $v0, 9
    ctx->r2 = S32(U32(ctx->r2) >> 9);
    // 0x800013E8: xori        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 ^ 0X1;
    // 0x800013EC: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x800013F0: jal         0x80000DD4
    // 0x800013F4: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    func_80000DD4(rdram, ctx);
        goto after_1;
    // 0x800013F4: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    after_1:
    // 0x800013F8: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x800013FC: beq         $v0, $zero, L_80001414
    if (ctx->r2 == 0) {
        // 0x80001400: addiu       $a0, $zero, 0x1
        ctx->r4 = ADD32(0, 0X1);
            goto L_80001414;
    }
    // 0x80001400: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80001404: lui         $a3, 0x8011
    ctx->r7 = S32(0X8011 << 16);
    // 0x80001408: lw          $a3, 0x63E4($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X63E4);
    // 0x8000140C: j           L_80001420
    // 0x80001410: addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
        goto L_80001420;
    // 0x80001410: addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
L_80001414:
    // 0x80001414: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x80001418: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x8000141C: lw          $a3, 0x48($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X48);
L_80001420:
    // 0x80001420: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80001424: addiu       $v0, $v0, -0x2E00
    ctx->r2 = ADD32(ctx->r2, -0X2E00);
    // 0x80001428: lui         $a2, 0x4
    ctx->r6 = S32(0X4 << 16);
    // 0x8000142C: addiu       $a2, $a2, 0x7490
    ctx->r6 = ADD32(ctx->r6, 0X7490);
    // 0x80001430: jal         0x800022F8
    // 0x80001434: addu        $a2, $v0, $a2
    ctx->r6 = ADD32(ctx->r2, ctx->r6);
    func_800022F8(rdram, ctx);
        goto after_2;
    // 0x80001434: addu        $a2, $v0, $a2
    ctx->r6 = ADD32(ctx->r2, ctx->r6);
    after_2:
    // 0x80001438: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x8000143C: lw          $a0, 0x63E4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X63E4);
    // 0x80001440: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x80001444: lw          $a1, 0x63E8($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X63E8);
    // 0x80001448: sll         $v0, $s1, 16
    ctx->r2 = S32(ctx->r17 << 16);
    // 0x8000144C: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80001450: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x80001454: addiu       $v1, $v1, 0x63D8
    ctx->r3 = ADD32(ctx->r3, 0X63D8);
    // 0x80001458: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x8000145C: sw          $v1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r3;
    // 0x80001460: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80001464: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80001468: lw          $v0, 0x4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4);
    // 0x8000146C: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80001470: lw          $a0, 0x63F8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X63F8);
    // 0x80001474: addiu       $v1, $v1, 0x18
    ctx->r3 = ADD32(ctx->r3, 0X18);
    // 0x80001478: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    // 0x8000147C: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x80001480: lw          $v1, 0x63EC($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X63EC);
    // 0x80001484: addiu       $v0, $v0, 0xF
    ctx->r2 = ADD32(ctx->r2, 0XF);
    // 0x80001488: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8000148C: addiu       $a0, $zero, -0x10
    ctx->r4 = ADD32(0, -0X10);
    // 0x80001490: and         $v0, $v0, $a0
    ctx->r2 = ctx->r2 & ctx->r4;
    // 0x80001494: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x80001498: lw          $v0, 0xC($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XC);
    // 0x8000149C: sw          $v1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r3;
    // 0x800014A0: addiu       $v0, $v0, 0xF
    ctx->r2 = ADD32(ctx->r2, 0XF);
    // 0x800014A4: and         $v0, $v0, $a0
    ctx->r2 = ctx->r2 & ctx->r4;
    // 0x800014A8: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x800014AC: lw          $v0, 0x8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X8);
    // 0x800014B0: addiu       $v0, $v0, 0xF
    ctx->r2 = ADD32(ctx->r2, 0XF);
    // 0x800014B4: and         $v0, $v0, $a0
    ctx->r2 = ctx->r2 & ctx->r4;
    // 0x800014B8: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x800014BC: lw          $v0, 0x18($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X18);
    // 0x800014C0: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    // 0x800014C4: lbu         $v0, 0x8($s3)
    ctx->r2 = MEM_BU(ctx->r19, 0X8);
    // 0x800014C8: addu        $a2, $fp, $zero
    ctx->r6 = ADD32(ctx->r30, 0);
    // 0x800014CC: addu        $a3, $s7, $zero
    ctx->r7 = ADD32(ctx->r23, 0);
    // 0x800014D0: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    // 0x800014D4: lhu         $v0, 0x10($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X10);
    // 0x800014D8: sll         $a1, $s6, 16
    ctx->r5 = S32(ctx->r22 << 16);
    // 0x800014DC: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x800014E0: sw          $v0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r2;
    // 0x800014E4: lhu         $v0, 0x12($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X12);
    // 0x800014E8: sll         $a0, $s5, 16
    ctx->r4 = S32(ctx->r21 << 16);
    // 0x800014EC: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x800014F0: jal         0x8001818C
    // 0x800014F4: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    func_8001818C(rdram, ctx);
        goto after_3;
    // 0x800014F4: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    after_3:
    // 0x800014F8: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x800014FC: beq         $v0, $zero, L_800015E8
    if (ctx->r2 == 0) {
        // 0x80001500: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_800015E8;
    }
    // 0x80001500: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x80001504: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80001508: lbu         $v0, -0x2DEF($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X2DEF);
    // 0x8000150C: beq         $v0, $zero, L_800015E8
    if (ctx->r2 == 0) {
        // 0x80001510: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_800015E8;
    }
    // 0x80001510: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80001514: lbu         $a1, 0x4($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0X4);
    // 0x80001518: beq         $a1, $zero, L_800015E8
    if (ctx->r5 == 0) {
        // 0x8000151C: nop
    
            goto L_800015E8;
    }
    // 0x8000151C: nop

    // 0x80001520: lhu         $v0, 0x8($s2)
    ctx->r2 = MEM_HU(ctx->r18, 0X8);
    // 0x80001524: lbu         $a2, 0x5($s2)
    ctx->r6 = MEM_BU(ctx->r18, 0X5);
    // 0x80001528: lbu         $a3, 0x6($s2)
    ctx->r7 = MEM_BU(ctx->r18, 0X6);
    // 0x8000152C: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x80001530: lw          $v0, 0xC($s2)
    ctx->r2 = MEM_W(ctx->r18, 0XC);
    // 0x80001534: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // 0x80001538: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x8000153C: jal         0x8008EB5C
    // 0x80001540: nop

    func_8008EB5C(rdram, ctx);
        goto after_4;
    // 0x80001540: nop

    after_4:
    // 0x80001544: bnel        $v0, $zero, L_800015E8
    if (ctx->r2 != 0) {
        // 0x80001548: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_800015E8;
    }
    goto skip_1;
    // 0x80001548: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    skip_1:
    // 0x8000154C: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80001550: lw          $v0, -0x350($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X350);
    // 0x80001554: lwl         $v1, 0x0($s3)
    ctx->r3 = do_lwl(rdram, ctx->r3, ctx->r19, 0X0);
    // 0x80001558: lwr         $v1, 0x3($s3)
    ctx->r3 = do_lwr(rdram, ctx->r3, ctx->r19, 0X3);
    // 0x8000155C: lwl         $a0, 0x4($s3)
    ctx->r4 = do_lwl(rdram, ctx->r4, ctx->r19, 0X4);
    // 0x80001560: lwr         $a0, 0x7($s3)
    ctx->r4 = do_lwr(rdram, ctx->r4, ctx->r19, 0X7);
    // 0x80001564: lh          $a1, 0x8($s3)
    ctx->r5 = MEM_H(ctx->r19, 0X8);
    // 0x80001568: swl         $v1, 0x10($v0)
    do_swl(rdram, 0X10, ctx->r2, ctx->r3);
    // 0x8000156C: swr         $v1, 0x13($v0)
    do_swr(rdram, 0X13, ctx->r2, ctx->r3);
    // 0x80001570: swl         $a0, 0x14($v0)
    do_swl(rdram, 0X14, ctx->r2, ctx->r4);
    // 0x80001574: swr         $a0, 0x17($v0)
    do_swr(rdram, 0X17, ctx->r2, ctx->r4);
    // 0x80001578: sh          $a1, 0x18($v0)
    MEM_H(0X18, ctx->r2) = ctx->r5;
    // 0x8000157C: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80001580: lw          $v0, -0x350($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X350);
    // 0x80001584: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x80001588: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    // 0x8000158C: lw          $a1, 0x8($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X8);
    // 0x80001590: lw          $a2, 0xC($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XC);
    // 0x80001594: sw          $v1, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->r3;
    // 0x80001598: sw          $a0, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->r4;
    // 0x8000159C: sw          $a1, 0x34($v0)
    MEM_W(0X34, ctx->r2) = ctx->r5;
    // 0x800015A0: sw          $a2, 0x38($v0)
    MEM_W(0X38, ctx->r2) = ctx->r6;
    // 0x800015A4: lw          $v1, 0x10($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X10);
    // 0x800015A8: lw          $a0, 0x14($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X14);
    // 0x800015AC: lw          $a1, 0x18($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X18);
    // 0x800015B0: sw          $v1, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = ctx->r3;
    // 0x800015B4: sw          $a0, 0x40($v0)
    MEM_W(0X40, ctx->r2) = ctx->r4;
    // 0x800015B8: sw          $a1, 0x44($v0)
    MEM_W(0X44, ctx->r2) = ctx->r5;
    // 0x800015BC: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x800015C0: lw          $v1, -0x350($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X350);
    // 0x800015C4: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x800015C8: lw          $a1, 0x4($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X4);
    // 0x800015CC: lw          $a2, 0x8($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X8);
    // 0x800015D0: lw          $a3, 0xC($s2)
    ctx->r7 = MEM_W(ctx->r18, 0XC);
    // 0x800015D4: sw          $a0, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = ctx->r4;
    // 0x800015D8: sw          $a1, 0x20($v1)
    MEM_W(0X20, ctx->r3) = ctx->r5;
    // 0x800015DC: sw          $a2, 0x24($v1)
    MEM_W(0X24, ctx->r3) = ctx->r6;
    // 0x800015E0: sw          $a3, 0x28($v1)
    MEM_W(0X28, ctx->r3) = ctx->r7;
    // 0x800015E4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800015E8:
    // 0x800015E8: lw          $ra, 0x7C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X7C);
    // 0x800015EC: lw          $fp, 0x78($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X78);
    // 0x800015F0: lw          $s7, 0x74($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X74);
    // 0x800015F4: lw          $s6, 0x70($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X70);
    // 0x800015F8: lw          $s5, 0x6C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X6C);
    // 0x800015FC: lw          $s4, 0x68($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X68);
    // 0x80001600: lw          $s3, 0x64($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X64);
    // 0x80001604: lw          $s2, 0x60($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X60);
    // 0x80001608: lw          $s1, 0x5C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X5C);
    // 0x8000160C: lw          $s0, 0x58($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X58);
    // 0x80001610: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    // 0x80001614: jr          $ra
    // 0x80001618: nop

    return;
    // 0x80001618: nop

;}
RECOMP_FUNC void main(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000161C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80001620: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80001624: addiu       $a0, $a0, -0x2E00
    ctx->r4 = ADD32(ctx->r4, -0X2E00);
    // 0x80001628: lui         $a1, 0x2
    ctx->r5 = S32(0X2 << 16);
    // 0x8000162C: addiu       $a1, $a1, 0x38C2
    ctx->r5 = ADD32(ctx->r5, 0X38C2);
    // 0x80001630: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80001634: jal         0x8000040C
    // 0x80001638: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    func_8000040C(rdram, ctx);
        goto after_0;
    // 0x80001638: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    after_0:
    // 0x8000163C: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80001640: addiu       $a0, $a0, -0x2E00
    ctx->r4 = ADD32(ctx->r4, -0X2E00);
    // 0x80001644: lui         $a1, 0x4
    ctx->r5 = S32(0X4 << 16);
    // 0x80001648: addiu       $a1, $a1, 0x7490
    ctx->r5 = ADD32(ctx->r5, 0X7490);
    // 0x8000164C: jal         0x8000040C
    // 0x80001650: nop

    func_8000040C(rdram, ctx);
        goto after_1;
    // 0x80001650: nop

    after_1:
    // 0x80001654: jal         0x8002BFA0
    // 0x80001658: nop

    osInitialize_recomp(rdram, ctx);
        goto after_2;
    // 0x80001658: nop

    after_2:
    // 0x8000165C: lui         $s0, 0x8011
    ctx->r16 = S32(0X8011 << 16);
    // 0x80001660: addiu       $s0, $s0, -0x2DE8
    ctx->r16 = ADD32(ctx->r16, -0X2DE8);
    // 0x80001664: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80001668: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x8000166C: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80001670: addiu       $v0, $v0, -0x128
    ctx->r2 = ADD32(ctx->r2, -0X128);
    // 0x80001674: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x80001678: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
    // 0x8000167C: lui         $a2, 0x8000
    ctx->r6 = S32(0X8000 << 16);
    // 0x80001680: addiu       $a2, $a2, 0x17A0
    ctx->r6 = ADD32(ctx->r6, 0X17A0);
    // 0x80001684: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // 0x80001688: jal         0x8002B330
    // 0x8000168C: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    osCreateThread_recomp(rdram, ctx);
        goto after_3;
    // 0x8000168C: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    after_3:
    // 0x80001690: jal         0x800344E0
    // 0x80001694: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    osStartThread_recomp(rdram, ctx);
        goto after_4;
    // 0x80001694: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_4:
    // 0x80001698: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8000169C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800016A0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800016A4: jr          $ra
    // 0x800016A8: nop

    return;
    // 0x800016A8: nop

;}
RECOMP_FUNC void func_800016AC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800016AC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800016B0: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x800016B4: lui         $s0, 0x8011
    ctx->r16 = S32(0X8011 << 16);
    // 0x800016B8: addiu       $s0, $s0, -0x2028
    ctx->r16 = ADD32(ctx->r16, -0X2028);
    // 0x800016BC: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800016C0: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x800016C4: addiu       $a1, $a1, -0x2A68
    ctx->r5 = ADD32(ctx->r5, -0X2A68);
    // 0x800016C8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800016CC: jal         0x8002B300
    // 0x800016D0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_0;
    // 0x800016D0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x800016D4: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    // 0x800016D8: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x800016DC: jal         0x80033560
    // 0x800016E0: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    osSetEventMesg_recomp(rdram, ctx);
        goto after_1;
    // 0x800016E0: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    after_1:
    // 0x800016E4: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800016E8: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x800016EC: jal         0x800331D0
    // 0x800016F0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_2;
    // 0x800016F0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_2:
    // 0x800016F4: lui         $v1, 0x8000
    ctx->r3 = S32(0X8000 << 16);
    // 0x800016F8: lw          $v1, 0x300($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X300);
    // 0x800016FC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80001700: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x80001704: sb          $v0, -0x2DF0($at)
    MEM_B(-0X2DF0, ctx->r1) = ctx->r2;
    // 0x80001708: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8000170C: beq         $v1, $v0, L_8000174C
    if (ctx->r3 == ctx->r2) {
        // 0x80001710: slti        $v0, $v1, 0x2
        ctx->r2 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
            goto L_8000174C;
    }
    // 0x80001710: slti        $v0, $v1, 0x2
    ctx->r2 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
    // 0x80001714: beql        $v0, $zero, L_8000172C
    if (ctx->r2 == 0) {
        // 0x80001718: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_8000172C;
    }
    goto skip_0;
    // 0x80001718: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    skip_0:
    // 0x8000171C: beq         $v1, $zero, L_8000173C
    if (ctx->r3 == 0) {
        // 0x80001720: nop
    
            goto L_8000173C;
    }
    // 0x80001720: nop

    // 0x80001724: j           L_8000176C
    // 0x80001728: nop

        goto L_8000176C;
    // 0x80001728: nop

L_8000172C:
    // 0x8000172C: beq         $v1, $v0, L_8000175C
    if (ctx->r3 == ctx->r2) {
        // 0x80001730: nop
    
            goto L_8000175C;
    }
    // 0x80001730: nop

    // 0x80001734: j           L_8000176C
    // 0x80001738: nop

        goto L_8000176C;
    // 0x80001738: nop

L_8000173C:
    // 0x8000173C: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x80001740: addiu       $a0, $a0, -0x6870
    ctx->r4 = ADD32(ctx->r4, -0X6870);
    // 0x80001744: j           L_80001764
    // 0x80001748: nop

        goto L_80001764;
    // 0x80001748: nop

L_8000174C:
    // 0x8000174C: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x80001750: addiu       $a0, $a0, -0x6CD0
    ctx->r4 = ADD32(ctx->r4, -0X6CD0);
    // 0x80001754: j           L_80001764
    // 0x80001758: nop

        goto L_80001764;
    // 0x80001758: nop

L_8000175C:
    // 0x8000175C: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x80001760: addiu       $a0, $a0, -0x6410
    ctx->r4 = ADD32(ctx->r4, -0X6410);
L_80001764:
    // 0x80001764: jal         0x800352D0
    // 0x80001768: nop

    osViSetMode_recomp(rdram, ctx);
        goto after_3;
    // 0x80001768: nop

    after_3:
L_8000176C:
    // 0x8000176C: jal         0x80034BE0
    // 0x80001770: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    osViBlack_recomp(rdram, ctx);
        goto after_4;
    // 0x80001770: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_4:
    // 0x80001774: jal         0x80004FD0
    // 0x80001778: nop

    func_80004FD0(rdram, ctx);
        goto after_5;
    // 0x80001778: nop

    after_5:
    // 0x8000177C: jal         0x80002C5C
    // 0x80001780: nop

    func_80002C5C(rdram, ctx);
        goto after_6;
    // 0x80001780: nop

    after_6:
L_80001784:
    // 0x80001784: j           L_80001784
    pause_self(rdram);
    // 0x80001788: nop

    // 0x8000178C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80001790: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80001794: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80001798: jr          $ra
    // 0x8000179C: nop

    return;
    // 0x8000179C: nop

;}
RECOMP_FUNC void idle_thread_handle(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800017A0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800017A4: addiu       $a0, $zero, 0xFE
    ctx->r4 = ADD32(0, 0XFE);
    // 0x800017A8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800017AC: jal         0x80034DB0
    // 0x800017B0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    osCreateViManager_recomp(rdram, ctx);
        goto after_0;
    // 0x800017B0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    after_0:
    // 0x800017B4: jal         0x80034BE0
    // 0x800017B8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    osViBlack_recomp(rdram, ctx);
        goto after_1;
    // 0x800017B8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_1:
    // 0x800017BC: lui         $s0, 0x8011
    ctx->r16 = S32(0X8011 << 16);
    // 0x800017C0: addiu       $s0, $s0, -0x2C30
    ctx->r16 = ADD32(ctx->r16, -0X2C30);
    // 0x800017C4: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800017C8: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x800017CC: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800017D0: addiu       $v0, $v0, 0x63B0
    ctx->r2 = ADD32(ctx->r2, 0X63B0);
    // 0x800017D4: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x800017D8: addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
    // 0x800017DC: lui         $a2, 0x8000
    ctx->r6 = S32(0X8000 << 16);
    // 0x800017E0: addiu       $a2, $a2, 0x1088
    ctx->r6 = ADD32(ctx->r6, 0X1088);
    // 0x800017E4: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // 0x800017E8: jal         0x8002B330
    // 0x800017EC: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    osCreateThread_recomp(rdram, ctx);
        goto after_2;
    // 0x800017EC: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    after_2:
    // 0x800017F0: jal         0x800344E0
    // 0x800017F4: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    osStartThread_recomp(rdram, ctx);
        goto after_3;
    // 0x800017F4: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_3:
    // 0x800017F8: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x800017FC: jal         0x800336E0
    // 0x80001800: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    osSetThreadPri_recomp(rdram, ctx);
        goto after_4;
    // 0x80001800: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_4:
L_80001804:
    // 0x80001804: j           L_80001804
    pause_self(rdram);
    // 0x80001808: nop

    // 0x8000180C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80001810: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80001814: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80001818: jr          $ra
    // 0x8000181C: nop

    return;
    // 0x8000181C: nop

;}
RECOMP_FUNC void func_80001820(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80001820: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80001824: addu        $a3, $a0, $zero
    ctx->r7 = ADD32(ctx->r4, 0);
    // 0x80001828: sltu        $v0, $zero, $a3
    ctx->r2 = 0 < ctx->r7 ? 1 : 0;
    // 0x8000182C: sltu        $v1, $zero, $a1
    ctx->r3 = 0 < ctx->r5 ? 1 : 0;
    // 0x80001830: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x80001834: beq         $v0, $zero, L_80001868
    if (ctx->r2 == 0) {
        // 0x80001838: sw          $ra, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r31;
            goto L_80001868;
    }
    // 0x80001838: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x8000183C: addu        $v0, $a3, $a1
    ctx->r2 = ADD32(ctx->r7, ctx->r5);
    // 0x80001840: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x80001844: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80001848: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x8000184C: addiu       $a0, $a0, -0x100
    ctx->r4 = ADD32(ctx->r4, -0X100);
    // 0x80001850: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80001854: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x80001858: jal         0x80001F8C
    // 0x8000185C: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    func_80001F8C(rdram, ctx);
        goto after_0;
    // 0x8000185C: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    after_0:
    // 0x80001860: j           L_80001870
    // 0x80001864: nop

        goto L_80001870;
    // 0x80001864: nop

L_80001868:
    // 0x80001868: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x8000186C: sw          $zero, -0x100($at)
    MEM_W(-0X100, ctx->r1) = 0;
L_80001870:
    // 0x80001870: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x80001874: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80001878: jr          $ra
    // 0x8000187C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8000187C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_80001880(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80001880: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x80001884: sw          $zero, -0x104($at)
    MEM_W(-0X104, ctx->r1) = 0;
    // 0x80001888: jr          $ra
    // 0x8000188C: nop

    return;
    // 0x8000188C: nop

;}
RECOMP_FUNC void func_80001890(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80001890: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80001894: lw          $v0, -0x104($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X104);
    // 0x80001898: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8000189C: sw          $ra, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r31;
    // 0x800018A0: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x800018A4: bne         $v0, $zero, L_800019B4
    if (ctx->r2 != 0) {
        // 0x800018A8: sw          $s0, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r16;
            goto L_800019B4;
    }
    // 0x800018A8: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800018AC: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800018B0: lbu         $v0, -0x5766($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X5766);
    // 0x800018B4: bne         $v0, $zero, L_800019B4
    if (ctx->r2 != 0) {
        // 0x800018B8: nop
    
            goto L_800019B4;
    }
    // 0x800018B8: nop

    // 0x800018BC: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800018C0: lw          $v0, -0x350($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X350);
    // 0x800018C4: lw          $v0, 0x44($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X44);
    // 0x800018C8: andi        $v0, $v0, 0x80
    ctx->r2 = ctx->r2 & 0X80;
    // 0x800018CC: bne         $v0, $zero, L_800019B4
    if (ctx->r2 != 0) {
        // 0x800018D0: nop
    
            goto L_800019B4;
    }
    // 0x800018D0: nop

    // 0x800018D4: jal         0x8001C07C
    // 0x800018D8: nop

    func_8001C07C(rdram, ctx);
        goto after_0;
    // 0x800018D8: nop

    after_0:
    // 0x800018DC: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x800018E0: lw          $v1, -0x350($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X350);
    // 0x800018E4: lw          $v1, 0x44($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X44);
    // 0x800018E8: andi        $v1, $v1, 0x200
    ctx->r3 = ctx->r3 & 0X200;
    // 0x800018EC: beq         $v1, $zero, L_80001924
    if (ctx->r3 == 0) {
        // 0x800018F0: addu        $s0, $v0, $zero
        ctx->r16 = ADD32(ctx->r2, 0);
            goto L_80001924;
    }
    // 0x800018F0: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // 0x800018F4: jal         0x8001BC48
    // 0x800018F8: nop

    func_8001BC48(rdram, ctx);
        goto after_1;
    // 0x800018F8: nop

    after_1:
    // 0x800018FC: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80001900: addiu       $a0, $a0, -0x104
    ctx->r4 = ADD32(ctx->r4, -0X104);
    // 0x80001904: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80001908: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x8000190C: addu        $a3, $s0, $zero
    ctx->r7 = ADD32(ctx->r16, 0);
    // 0x80001910: addu        $v0, $a3, $v0
    ctx->r2 = ADD32(ctx->r7, ctx->r2);
    // 0x80001914: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x80001918: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8000191C: j           L_800019AC
    // 0x80001920: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
        goto L_800019AC;
    // 0x80001920: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
L_80001924:
    // 0x80001924: jal         0x8001BC48
    // 0x80001928: nop

    func_8001BC48(rdram, ctx);
        goto after_2;
    // 0x80001928: nop

    after_2:
    // 0x8000192C: lui         $s1, 0x8011
    ctx->r17 = S32(0X8011 << 16);
    // 0x80001930: addiu       $s1, $s1, 0x63E4
    ctx->r17 = ADD32(ctx->r17, 0X63E4);
    // 0x80001934: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x80001938: addu        $v0, $s0, $v0
    ctx->r2 = ADD32(ctx->r16, ctx->r2);
    // 0x8000193C: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x80001940: subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // 0x80001944: bne         $v1, $zero, L_8000197C
    if (ctx->r3 != 0) {
        // 0x80001948: sw          $v1, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r3;
            goto L_8000197C;
    }
    // 0x80001948: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    // 0x8000194C: jal         0x8001BC48
    // 0x80001950: nop

    func_8001BC48(rdram, ctx);
        goto after_3;
    // 0x80001950: nop

    after_3:
    // 0x80001954: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80001958: addiu       $a0, $a0, -0x104
    ctx->r4 = ADD32(ctx->r4, -0X104);
    // 0x8000195C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80001960: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x80001964: addu        $a3, $s0, $zero
    ctx->r7 = ADD32(ctx->r16, 0);
    // 0x80001968: addu        $v0, $a3, $v0
    ctx->r2 = ADD32(ctx->r7, ctx->r2);
    // 0x8000196C: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x80001970: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80001974: j           L_800019AC
    // 0x80001978: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
        goto L_800019AC;
    // 0x80001978: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
L_8000197C:
    // 0x8000197C: jal         0x8001BC48
    // 0x80001980: nop

    func_8001BC48(rdram, ctx);
        goto after_4;
    // 0x80001980: nop

    after_4:
    // 0x80001984: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80001988: addiu       $a0, $a0, -0x104
    ctx->r4 = ADD32(ctx->r4, -0X104);
    // 0x8000198C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80001990: addiu       $a2, $sp, 0x18
    ctx->r6 = ADD32(ctx->r29, 0X18);
    // 0x80001994: lw          $t0, 0x0($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X0);
    // 0x80001998: addu        $a3, $s0, $zero
    ctx->r7 = ADD32(ctx->r16, 0);
    // 0x8000199C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x800019A0: sw          $v1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r3;
    // 0x800019A4: addu        $t0, $t0, $v0
    ctx->r8 = ADD32(ctx->r8, ctx->r2);
    // 0x800019A8: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
L_800019AC:
    // 0x800019AC: jal         0x80001F8C
    // 0x800019B0: nop

    func_80001F8C(rdram, ctx);
        goto after_5;
    // 0x800019B0: nop

    after_5:
L_800019B4:
    // 0x800019B4: lw          $ra, 0x28($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X28);
    // 0x800019B8: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x800019BC: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800019C0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800019C4: jr          $ra
    // 0x800019C8: nop

    return;
    // 0x800019C8: nop

;}
RECOMP_FUNC void func_800019CC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800019CC: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x800019D0: lw          $a0, -0xE8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0XE8);
    // 0x800019D4: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x800019D8: beq         $a0, $zero, L_80001A40
    if (ctx->r4 == 0) {
        // 0x800019DC: addu        $a2, $zero, $zero
        ctx->r6 = ADD32(0, 0);
            goto L_80001A40;
    }
    // 0x800019DC: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
L_800019E0:
    // 0x800019E0: lhu         $v0, 0x0($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X0);
    // 0x800019E4: andi        $v0, $v0, 0x8
    ctx->r2 = ctx->r2 & 0X8;
    // 0x800019E8: bne         $v0, $zero, L_80001A20
    if (ctx->r2 != 0) {
        // 0x800019EC: nop
    
            goto L_80001A20;
    }
    // 0x800019EC: nop

L_800019F0:
    // 0x800019F0: lhu         $v0, 0x0($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X0);
    // 0x800019F4: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x800019F8: beq         $v0, $zero, L_80001A08
    if (ctx->r2 == 0) {
        // 0x800019FC: nop
    
            goto L_80001A08;
    }
    // 0x800019FC: nop

    // 0x80001A00: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    // 0x80001A04: addu        $a1, $a1, $v0
    ctx->r5 = ADD32(ctx->r5, ctx->r2);
L_80001A08:
    // 0x80001A08: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    // 0x80001A0C: addu        $v0, $a0, $v0
    ctx->r2 = ADD32(ctx->r4, ctx->r2);
    // 0x80001A10: lhu         $v1, 0x10($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X10);
    // 0x80001A14: andi        $v1, $v1, 0x8
    ctx->r3 = ctx->r3 & 0X8;
    // 0x80001A18: beq         $v1, $zero, L_800019F0
    if (ctx->r3 == 0) {
        // 0x80001A1C: addiu       $a0, $v0, 0x10
        ctx->r4 = ADD32(ctx->r2, 0X10);
            goto L_800019F0;
    }
    // 0x80001A1C: addiu       $a0, $v0, 0x10
    ctx->r4 = ADD32(ctx->r2, 0X10);
L_80001A20:
    // 0x80001A20: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80001A24: lw          $a0, -0x100($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X100);
    // 0x80001A28: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x80001A2C: sltiu       $v0, $a2, 0x2
    ctx->r2 = ctx->r6 < 0X2 ? 1 : 0;
    // 0x80001A30: sltu        $v1, $zero, $a0
    ctx->r3 = 0 < ctx->r4 ? 1 : 0;
    // 0x80001A34: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x80001A38: bne         $v0, $zero, L_800019E0
    if (ctx->r2 != 0) {
        // 0x80001A3C: nop
    
            goto L_800019E0;
    }
    // 0x80001A3C: nop

L_80001A40:
    // 0x80001A40: jr          $ra
    // 0x80001A44: addu        $v0, $a1, $zero
    ctx->r2 = ADD32(ctx->r5, 0);
    return;
    // 0x80001A44: addu        $v0, $a1, $zero
    ctx->r2 = ADD32(ctx->r5, 0);
;}
RECOMP_FUNC void func_80001A48(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80001A48: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80001A4C: lw          $a0, -0xE8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0XE8);
    // 0x80001A50: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80001A54: beq         $a0, $zero, L_80001AC4
    if (ctx->r4 == 0) {
        // 0x80001A58: addu        $a2, $zero, $zero
        ctx->r6 = ADD32(0, 0);
            goto L_80001AC4;
    }
    // 0x80001A58: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
L_80001A5C:
    // 0x80001A5C: lhu         $v0, 0x0($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X0);
    // 0x80001A60: andi        $v0, $v0, 0x8
    ctx->r2 = ctx->r2 & 0X8;
    // 0x80001A64: bne         $v0, $zero, L_80001AA4
    if (ctx->r2 != 0) {
        // 0x80001A68: nop
    
            goto L_80001AA4;
    }
    // 0x80001A68: nop

L_80001A6C:
    // 0x80001A6C: lhu         $v0, 0x0($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X0);
    // 0x80001A70: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x80001A74: beq         $v0, $zero, L_80001A8C
    if (ctx->r2 == 0) {
        // 0x80001A78: nop
    
            goto L_80001A8C;
    }
    // 0x80001A78: nop

    // 0x80001A7C: lw          $v1, 0x4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X4);
    // 0x80001A80: sltu        $v0, $a1, $v1
    ctx->r2 = ctx->r5 < ctx->r3 ? 1 : 0;
    // 0x80001A84: bnel        $v0, $zero, L_80001A8C
    if (ctx->r2 != 0) {
        // 0x80001A88: addu        $a1, $v1, $zero
        ctx->r5 = ADD32(ctx->r3, 0);
            goto L_80001A8C;
    }
    goto skip_0;
    // 0x80001A88: addu        $a1, $v1, $zero
    ctx->r5 = ADD32(ctx->r3, 0);
    skip_0:
L_80001A8C:
    // 0x80001A8C: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    // 0x80001A90: addu        $v0, $a0, $v0
    ctx->r2 = ADD32(ctx->r4, ctx->r2);
    // 0x80001A94: lhu         $v1, 0x10($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X10);
    // 0x80001A98: andi        $v1, $v1, 0x8
    ctx->r3 = ctx->r3 & 0X8;
    // 0x80001A9C: beq         $v1, $zero, L_80001A6C
    if (ctx->r3 == 0) {
        // 0x80001AA0: addiu       $a0, $v0, 0x10
        ctx->r4 = ADD32(ctx->r2, 0X10);
            goto L_80001A6C;
    }
    // 0x80001AA0: addiu       $a0, $v0, 0x10
    ctx->r4 = ADD32(ctx->r2, 0X10);
L_80001AA4:
    // 0x80001AA4: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80001AA8: lw          $a0, -0x100($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X100);
    // 0x80001AAC: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x80001AB0: sltiu       $v0, $a2, 0x2
    ctx->r2 = ctx->r6 < 0X2 ? 1 : 0;
    // 0x80001AB4: sltu        $v1, $zero, $a0
    ctx->r3 = 0 < ctx->r4 ? 1 : 0;
    // 0x80001AB8: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x80001ABC: bne         $v0, $zero, L_80001A5C
    if (ctx->r2 != 0) {
        // 0x80001AC0: nop
    
            goto L_80001A5C;
    }
    // 0x80001AC0: nop

L_80001AC4:
    // 0x80001AC4: jr          $ra
    // 0x80001AC8: addu        $v0, $a1, $zero
    ctx->r2 = ADD32(ctx->r5, 0);
    return;
    // 0x80001AC8: addu        $v0, $a1, $zero
    ctx->r2 = ADD32(ctx->r5, 0);
;}
RECOMP_FUNC void rs_malloc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80001ACC: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80001AD0: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80001AD4: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x80001AD8: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x80001ADC: addu        $s1, $a1, $zero
    ctx->r17 = ADD32(ctx->r5, 0);
    // 0x80001AE0: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x80001AE4: addu        $s2, $zero, $zero
    ctx->r18 = ADD32(0, 0);
    // 0x80001AE8: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x80001AEC: addu        $s3, $s1, $zero
    ctx->r19 = ADD32(ctx->r17, 0);
    // 0x80001AF0: beq         $s0, $zero, L_80001C74
    if (ctx->r16 == 0) {
        // 0x80001AF4: sw          $ra, 0x30($sp)
        MEM_W(0X30, ctx->r29) = ctx->r31;
            goto L_80001C74;
    }
    // 0x80001AF4: sw          $ra, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r31;
    // 0x80001AF8: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80001AFC: addiu       $a0, $a0, -0x120
    ctx->r4 = ADD32(ctx->r4, -0X120);
    // 0x80001B00: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80001B04: jal         0x800331D0
    // 0x80001B08: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x80001B08: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x80001B0C: addiu       $v0, $s0, 0xF
    ctx->r2 = ADD32(ctx->r16, 0XF);
    // 0x80001B10: addiu       $v1, $zero, -0x10
    ctx->r3 = ADD32(0, -0X10);
    // 0x80001B14: and         $s0, $v0, $v1
    ctx->r16 = ctx->r2 & ctx->r3;
    // 0x80001B18: andi        $v0, $s1, 0x4
    ctx->r2 = ctx->r17 & 0X4;
    // 0x80001B1C: beq         $v0, $zero, L_80001B44
    if (ctx->r2 == 0) {
        // 0x80001B20: nop
    
            goto L_80001B44;
    }
    // 0x80001B20: nop

    // 0x80001B24: jal         0x80001890
    // 0x80001B28: nop

    func_80001890(rdram, ctx);
        goto after_1;
    // 0x80001B28: nop

    after_1:
    // 0x80001B2C: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80001B30: lw          $v0, -0x104($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X104);
    // 0x80001B34: beq         $v0, $zero, L_80001C60
    if (ctx->r2 == 0) {
        // 0x80001B38: addiu       $t0, $zero, 0x1
        ctx->r8 = ADD32(0, 0X1);
            goto L_80001C60;
    }
    // 0x80001B38: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80001B3C: j           L_80001B98
    // 0x80001B40: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
        goto L_80001B98;
    // 0x80001B40: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
L_80001B44:
    // 0x80001B44: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x80001B48: lw          $v1, -0x100($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X100);
    // 0x80001B4C: beq         $v1, $zero, L_80001B88
    if (ctx->r3 == 0) {
        // 0x80001B50: andi        $v0, $s1, 0x10
        ctx->r2 = ctx->r17 & 0X10;
            goto L_80001B88;
    }
    // 0x80001B50: andi        $v0, $s1, 0x10
    ctx->r2 = ctx->r17 & 0X10;
    // 0x80001B54: beq         $v0, $zero, L_80001B70
    if (ctx->r2 == 0) {
        // 0x80001B58: nop
    
            goto L_80001B70;
    }
    // 0x80001B58: nop

    // 0x80001B5C: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80001B60: lw          $v0, -0xE8($v0)
    ctx->r2 = MEM_W(ctx->r2, -0XE8);
    // 0x80001B64: sw          $v1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r3;
    // 0x80001B68: j           L_80001B80
    // 0x80001B6C: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
        goto L_80001B80;
    // 0x80001B6C: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
L_80001B70:
    // 0x80001B70: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80001B74: lw          $v0, -0xE8($v0)
    ctx->r2 = MEM_W(ctx->r2, -0XE8);
    // 0x80001B78: sw          $v1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r3;
    // 0x80001B7C: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
L_80001B80:
    // 0x80001B80: j           L_80001B98
    // 0x80001B84: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
        goto L_80001B98;
    // 0x80001B84: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
L_80001B88:
    // 0x80001B88: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80001B8C: lw          $v0, -0xE8($v0)
    ctx->r2 = MEM_W(ctx->r2, -0XE8);
    // 0x80001B90: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80001B94: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
L_80001B98:
    // 0x80001B98: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80001B9C: beq         $t0, $zero, L_80001C60
    if (ctx->r8 == 0) {
        // 0x80001BA0: addu        $a2, $zero, $zero
        ctx->r6 = ADD32(0, 0);
            goto L_80001C60;
    }
    // 0x80001BA0: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x80001BA4: andi        $t1, $s3, 0x88
    ctx->r9 = ctx->r19 & 0X88;
    // 0x80001BA8: addiu       $t2, $zero, 0x8
    ctx->r10 = ADD32(0, 0X8);
    // 0x80001BAC: addiu       $a3, $sp, 0x10
    ctx->r7 = ADD32(ctx->r29, 0X10);
L_80001BB0:
    // 0x80001BB0: lw          $a0, 0x0($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X0);
    // 0x80001BB4: lhu         $v0, 0x0($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X0);
    // 0x80001BB8: andi        $v0, $v0, 0x8
    ctx->r2 = ctx->r2 & 0X8;
    // 0x80001BBC: bne         $v0, $zero, L_80001C04
    if (ctx->r2 != 0) {
        // 0x80001BC0: nop
    
            goto L_80001C04;
    }
    // 0x80001BC0: nop

L_80001BC4:
    // 0x80001BC4: lhu         $v0, 0x0($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X0);
    // 0x80001BC8: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x80001BCC: beq         $v0, $zero, L_80001BEC
    if (ctx->r2 == 0) {
        // 0x80001BD0: nop
    
            goto L_80001BEC;
    }
    // 0x80001BD0: nop

    // 0x80001BD4: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    // 0x80001BD8: sltu        $v0, $v0, $s0
    ctx->r2 = ctx->r2 < ctx->r16 ? 1 : 0;
    // 0x80001BDC: bne         $v0, $zero, L_80001BEC
    if (ctx->r2 != 0) {
        // 0x80001BE0: nop
    
            goto L_80001BEC;
    }
    // 0x80001BE0: nop

    // 0x80001BE4: bne         $t1, $t2, L_80001C04
    if (ctx->r9 != ctx->r10) {
        // 0x80001BE8: addu        $a1, $a0, $zero
        ctx->r5 = ADD32(ctx->r4, 0);
            goto L_80001C04;
    }
    // 0x80001BE8: addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
L_80001BEC:
    // 0x80001BEC: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    // 0x80001BF0: addu        $v0, $a0, $v0
    ctx->r2 = ADD32(ctx->r4, ctx->r2);
    // 0x80001BF4: lhu         $v1, 0x10($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X10);
    // 0x80001BF8: andi        $v1, $v1, 0x8
    ctx->r3 = ctx->r3 & 0X8;
    // 0x80001BFC: beq         $v1, $zero, L_80001BC4
    if (ctx->r3 == 0) {
        // 0x80001C00: addiu       $a0, $v0, 0x10
        ctx->r4 = ADD32(ctx->r2, 0X10);
            goto L_80001BC4;
    }
    // 0x80001C00: addiu       $a0, $v0, 0x10
    ctx->r4 = ADD32(ctx->r2, 0X10);
L_80001C04:
    // 0x80001C04: beql        $a1, $zero, L_80001C54
    if (ctx->r5 == 0) {
        // 0x80001C08: addiu       $a2, $a2, 0x1
        ctx->r6 = ADD32(ctx->r6, 0X1);
            goto L_80001C54;
    }
    goto skip_0;
    // 0x80001C08: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    skip_0:
    // 0x80001C0C: lw          $v1, 0x4($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X4);
    // 0x80001C10: addiu       $s2, $a1, 0x10
    ctx->r18 = ADD32(ctx->r5, 0X10);
    // 0x80001C14: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x80001C18: sh          $v0, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r2;
    // 0x80001C1C: beq         $s0, $v1, L_80001C60
    if (ctx->r16 == ctx->r3) {
        // 0x80001C20: sh          $s3, 0x2($a1)
        MEM_H(0X2, ctx->r5) = ctx->r19;
            goto L_80001C60;
    }
    // 0x80001C20: sh          $s3, 0x2($a1)
    MEM_H(0X2, ctx->r5) = ctx->r19;
    // 0x80001C24: subu        $v0, $v1, $s0
    ctx->r2 = SUB32(ctx->r3, ctx->r16);
    // 0x80001C28: sltiu       $v0, $v0, 0x20
    ctx->r2 = ctx->r2 < 0X20 ? 1 : 0;
    // 0x80001C2C: bne         $v0, $zero, L_80001C60
    if (ctx->r2 != 0) {
        // 0x80001C30: addu        $a0, $s2, $s0
        ctx->r4 = ADD32(ctx->r18, ctx->r16);
            goto L_80001C60;
    }
    // 0x80001C30: addu        $a0, $s2, $s0
    ctx->r4 = ADD32(ctx->r18, ctx->r16);
    // 0x80001C34: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80001C38: sh          $v0, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r2;
    // 0x80001C3C: lw          $v0, 0x4($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X4);
    // 0x80001C40: subu        $v0, $v0, $s0
    ctx->r2 = SUB32(ctx->r2, ctx->r16);
    // 0x80001C44: addiu       $v0, $v0, -0x10
    ctx->r2 = ADD32(ctx->r2, -0X10);
    // 0x80001C48: sw          $v0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r2;
    // 0x80001C4C: j           L_80001C60
    // 0x80001C50: sw          $s0, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r16;
        goto L_80001C60;
    // 0x80001C50: sw          $s0, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r16;
L_80001C54:
    // 0x80001C54: sltu        $v0, $a2, $t0
    ctx->r2 = ctx->r6 < ctx->r8 ? 1 : 0;
    // 0x80001C58: bne         $v0, $zero, L_80001BB0
    if (ctx->r2 != 0) {
        // 0x80001C5C: addiu       $a3, $a3, 0x4
        ctx->r7 = ADD32(ctx->r7, 0X4);
            goto L_80001BB0;
    }
    // 0x80001C5C: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
L_80001C60:
    // 0x80001C60: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80001C64: addiu       $a0, $a0, -0x120
    ctx->r4 = ADD32(ctx->r4, -0X120);
    // 0x80001C68: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80001C6C: jal         0x80033410
    // 0x80001C70: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    osSendMesg_recomp(rdram, ctx);
        goto after_2;
    // 0x80001C70: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    after_2:
L_80001C74:
    {
    gpr addr = ctx->r18;
    gpr size = ctx->r16;
    uint32_t addr32 = (uint32_t)addr;
    uint32_t size32 = (uint32_t)size;
    if ((addr32 & 0xE0000000u) == 0x80000000u && addr32 < 0x80800000u && size32 > 0 && size32 < 0x100000u && addr32 + size32 <= 0x80800000u) {
        for (uint32_t i = 0; i < size32; ++i) MEM_B(i, addr) = 0;
    }
}
    // 0x80001C74: addu        $v0, $s2, $zero
    ctx->r2 = ADD32(ctx->r18, 0);
    // 0x80001C78: lw          $ra, 0x30($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X30);
    // 0x80001C7C: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x80001C80: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x80001C84: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x80001C88: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80001C8C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80001C90: jr          $ra
    // 0x80001C94: nop

    return;
    // 0x80001C94: nop

;}
RECOMP_FUNC void rs_free(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80001C98: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80001C9C: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80001CA0: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x80001CA4: beq         $s0, $zero, L_80001F78
    if (ctx->r16 == 0) {
        // 0x80001CA8: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_80001F78;
    }
    // 0x80001CA8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80001CAC: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80001CB0: addiu       $a0, $a0, -0x120
    ctx->r4 = ADD32(ctx->r4, -0X120);
    // 0x80001CB4: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80001CB8: jal         0x800331D0
    // 0x80001CBC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x80001CBC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x80001CC0: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x80001CC4: lw          $a1, -0xE8($a1)
    ctx->r5 = MEM_W(ctx->r5, -0XE8);
    // 0x80001CC8: lhu         $v1, 0x0($a1)
    ctx->r3 = MEM_HU(ctx->r5, 0X0);
    // 0x80001CCC: addu        $t0, $zero, $zero
    ctx->r8 = ADD32(0, 0);
    // 0x80001CD0: andi        $v0, $v1, 0x8
    ctx->r2 = ctx->r3 & 0X8;
    // 0x80001CD4: bne         $v0, $zero, L_80001D94
    if (ctx->r2 != 0) {
        // 0x80001CD8: addiu       $a0, $s0, -0x10
        ctx->r4 = ADD32(ctx->r16, -0X10);
            goto L_80001D94;
    }
    // 0x80001CD8: addiu       $a0, $s0, -0x10
    ctx->r4 = ADD32(ctx->r16, -0X10);
    // 0x80001CDC: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
L_80001CE0:
    // 0x80001CE0: lw          $v0, 0x4($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X4);
    // 0x80001CE4: addu        $a2, $a1, $v0
    ctx->r6 = ADD32(ctx->r5, ctx->r2);
    // 0x80001CE8: andi        $v0, $v1, 0x2
    ctx->r2 = ctx->r3 & 0X2;
    // 0x80001CEC: beq         $v0, $zero, L_80001D7C
    if (ctx->r2 == 0) {
        // 0x80001CF0: addiu       $a3, $a2, 0x10
        ctx->r7 = ADD32(ctx->r6, 0X10);
            goto L_80001D7C;
    }
    // 0x80001CF0: addiu       $a3, $a2, 0x10
    ctx->r7 = ADD32(ctx->r6, 0X10);
    // 0x80001CF4: bnel        $a0, $a1, L_80001D80
    if (ctx->r4 != ctx->r5) {
        // 0x80001CF8: addu        $t0, $a1, $zero
        ctx->r8 = ADD32(ctx->r5, 0);
            goto L_80001D80;
    }
    goto skip_0;
    // 0x80001CF8: addu        $t0, $a1, $zero
    ctx->r8 = ADD32(ctx->r5, 0);
    skip_0:
    // 0x80001CFC: srl         $v0, $v1, 2
    ctx->r2 = S32(U32(ctx->r3) >> 2);
    // 0x80001D00: xori        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 ^ 0X1;
    // 0x80001D04: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x80001D08: beq         $v0, $zero, L_80001D98
    if (ctx->r2 == 0) {
        // 0x80001D0C: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_80001D98;
    }
    // 0x80001D0C: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x80001D10: sh          $t1, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r9;
    // 0x80001D14: lhu         $v1, 0x10($a2)
    ctx->r3 = MEM_HU(ctx->r6, 0X10);
    // 0x80001D18: andi        $v0, $v1, 0x1
    ctx->r2 = ctx->r3 & 0X1;
    // 0x80001D1C: beq         $v0, $zero, L_80001D40
    if (ctx->r2 == 0) {
        // 0x80001D20: andi        $v0, $v1, 0x4
        ctx->r2 = ctx->r3 & 0X4;
            goto L_80001D40;
    }
    // 0x80001D20: andi        $v0, $v1, 0x4
    ctx->r2 = ctx->r3 & 0X4;
    // 0x80001D24: bne         $v0, $zero, L_80001D40
    if (ctx->r2 != 0) {
        // 0x80001D28: nop
    
            goto L_80001D40;
    }
    // 0x80001D28: nop

    // 0x80001D2C: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    // 0x80001D30: lw          $v1, 0x14($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X14);
    // 0x80001D34: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x80001D38: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80001D3C: sw          $v0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r2;
L_80001D40:
    // 0x80001D40: beq         $t0, $zero, L_80001D98
    if (ctx->r8 == 0) {
        // 0x80001D44: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80001D98;
    }
    // 0x80001D44: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80001D48: lhu         $v1, 0x0($t0)
    ctx->r3 = MEM_HU(ctx->r8, 0X0);
    // 0x80001D4C: andi        $v0, $v1, 0x1
    ctx->r2 = ctx->r3 & 0X1;
    // 0x80001D50: beq         $v0, $zero, L_80001D74
    if (ctx->r2 == 0) {
        // 0x80001D54: andi        $v0, $v1, 0x4
        ctx->r2 = ctx->r3 & 0X4;
            goto L_80001D74;
    }
    // 0x80001D54: andi        $v0, $v1, 0x4
    ctx->r2 = ctx->r3 & 0X4;
    // 0x80001D58: bnel        $v0, $zero, L_80001D98
    if (ctx->r2 != 0) {
        // 0x80001D5C: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80001D98;
    }
    goto skip_1;
    // 0x80001D5C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_1:
    // 0x80001D60: lw          $v0, 0x4($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X4);
    // 0x80001D64: lw          $v1, 0x4($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X4);
    // 0x80001D68: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x80001D6C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80001D70: sw          $v0, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r2;
L_80001D74:
    // 0x80001D74: j           L_80001D98
    // 0x80001D78: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80001D98;
    // 0x80001D78: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80001D7C:
    // 0x80001D7C: addu        $t0, $a1, $zero
    ctx->r8 = ADD32(ctx->r5, 0);
L_80001D80:
    // 0x80001D80: addu        $a1, $a3, $zero
    ctx->r5 = ADD32(ctx->r7, 0);
    // 0x80001D84: lhu         $v1, 0x0($a1)
    ctx->r3 = MEM_HU(ctx->r5, 0X0);
    // 0x80001D88: andi        $v0, $v1, 0x8
    ctx->r2 = ctx->r3 & 0X8;
    // 0x80001D8C: beq         $v0, $zero, L_80001CE0
    if (ctx->r2 == 0) {
        // 0x80001D90: nop
    
            goto L_80001CE0;
    }
    // 0x80001D90: nop

L_80001D94:
    // 0x80001D94: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_80001D98:
    // 0x80001D98: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x80001D9C: bne         $v0, $zero, L_80001F64
    if (ctx->r2 != 0) {
        // 0x80001DA0: nop
    
            goto L_80001F64;
    }
    // 0x80001DA0: nop

    // 0x80001DA4: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80001DA8: lw          $v0, -0x100($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X100);
    // 0x80001DAC: beq         $v0, $zero, L_80001E90
    if (ctx->r2 == 0) {
        // 0x80001DB0: nop
    
            goto L_80001E90;
    }
    // 0x80001DB0: nop

    // 0x80001DB4: addu        $a1, $v0, $zero
    ctx->r5 = ADD32(ctx->r2, 0);
    // 0x80001DB8: lhu         $v1, 0x0($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X0);
    // 0x80001DBC: andi        $v0, $v1, 0x8
    ctx->r2 = ctx->r3 & 0X8;
    // 0x80001DC0: bne         $v0, $zero, L_80001E80
    if (ctx->r2 != 0) {
        // 0x80001DC4: addu        $t0, $zero, $zero
        ctx->r8 = ADD32(0, 0);
            goto L_80001E80;
    }
    // 0x80001DC4: addu        $t0, $zero, $zero
    ctx->r8 = ADD32(0, 0);
    // 0x80001DC8: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
L_80001DCC:
    // 0x80001DCC: lw          $v0, 0x4($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X4);
    // 0x80001DD0: addu        $a2, $a1, $v0
    ctx->r6 = ADD32(ctx->r5, ctx->r2);
    // 0x80001DD4: andi        $v0, $v1, 0x2
    ctx->r2 = ctx->r3 & 0X2;
    // 0x80001DD8: beq         $v0, $zero, L_80001E68
    if (ctx->r2 == 0) {
        // 0x80001DDC: addiu       $a3, $a2, 0x10
        ctx->r7 = ADD32(ctx->r6, 0X10);
            goto L_80001E68;
    }
    // 0x80001DDC: addiu       $a3, $a2, 0x10
    ctx->r7 = ADD32(ctx->r6, 0X10);
    // 0x80001DE0: bnel        $a0, $a1, L_80001E6C
    if (ctx->r4 != ctx->r5) {
        // 0x80001DE4: addu        $t0, $a1, $zero
        ctx->r8 = ADD32(ctx->r5, 0);
            goto L_80001E6C;
    }
    goto skip_2;
    // 0x80001DE4: addu        $t0, $a1, $zero
    ctx->r8 = ADD32(ctx->r5, 0);
    skip_2:
    // 0x80001DE8: srl         $v0, $v1, 2
    ctx->r2 = S32(U32(ctx->r3) >> 2);
    // 0x80001DEC: xori        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 ^ 0X1;
    // 0x80001DF0: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x80001DF4: beq         $v0, $zero, L_80001E84
    if (ctx->r2 == 0) {
        // 0x80001DF8: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_80001E84;
    }
    // 0x80001DF8: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x80001DFC: sh          $t1, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r9;
    // 0x80001E00: lhu         $v1, 0x10($a2)
    ctx->r3 = MEM_HU(ctx->r6, 0X10);
    // 0x80001E04: andi        $v0, $v1, 0x1
    ctx->r2 = ctx->r3 & 0X1;
    // 0x80001E08: beq         $v0, $zero, L_80001E2C
    if (ctx->r2 == 0) {
        // 0x80001E0C: andi        $v0, $v1, 0x4
        ctx->r2 = ctx->r3 & 0X4;
            goto L_80001E2C;
    }
    // 0x80001E0C: andi        $v0, $v1, 0x4
    ctx->r2 = ctx->r3 & 0X4;
    // 0x80001E10: bne         $v0, $zero, L_80001E2C
    if (ctx->r2 != 0) {
        // 0x80001E14: nop
    
            goto L_80001E2C;
    }
    // 0x80001E14: nop

    // 0x80001E18: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    // 0x80001E1C: lw          $v1, 0x14($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X14);
    // 0x80001E20: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x80001E24: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80001E28: sw          $v0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r2;
L_80001E2C:
    // 0x80001E2C: beq         $t0, $zero, L_80001E84
    if (ctx->r8 == 0) {
        // 0x80001E30: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80001E84;
    }
    // 0x80001E30: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80001E34: lhu         $v1, 0x0($t0)
    ctx->r3 = MEM_HU(ctx->r8, 0X0);
    // 0x80001E38: andi        $v0, $v1, 0x1
    ctx->r2 = ctx->r3 & 0X1;
    // 0x80001E3C: beq         $v0, $zero, L_80001E60
    if (ctx->r2 == 0) {
        // 0x80001E40: andi        $v0, $v1, 0x4
        ctx->r2 = ctx->r3 & 0X4;
            goto L_80001E60;
    }
    // 0x80001E40: andi        $v0, $v1, 0x4
    ctx->r2 = ctx->r3 & 0X4;
    // 0x80001E44: bnel        $v0, $zero, L_80001E84
    if (ctx->r2 != 0) {
        // 0x80001E48: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80001E84;
    }
    goto skip_3;
    // 0x80001E48: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_3:
    // 0x80001E4C: lw          $v0, 0x4($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X4);
    // 0x80001E50: lw          $v1, 0x4($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X4);
    // 0x80001E54: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x80001E58: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80001E5C: sw          $v0, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r2;
L_80001E60:
    // 0x80001E60: j           L_80001E84
    // 0x80001E64: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80001E84;
    // 0x80001E64: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80001E68:
    // 0x80001E68: addu        $t0, $a1, $zero
    ctx->r8 = ADD32(ctx->r5, 0);
L_80001E6C:
    // 0x80001E6C: addu        $a1, $a3, $zero
    ctx->r5 = ADD32(ctx->r7, 0);
    // 0x80001E70: lhu         $v1, 0x0($a1)
    ctx->r3 = MEM_HU(ctx->r5, 0X0);
    // 0x80001E74: andi        $v0, $v1, 0x8
    ctx->r2 = ctx->r3 & 0X8;
    // 0x80001E78: beq         $v0, $zero, L_80001DCC
    if (ctx->r2 == 0) {
        // 0x80001E7C: nop
    
            goto L_80001DCC;
    }
    // 0x80001E7C: nop

L_80001E80:
    // 0x80001E80: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_80001E84:
    // 0x80001E84: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x80001E88: bne         $v0, $zero, L_80001F64
    if (ctx->r2 != 0) {
        // 0x80001E8C: nop
    
            goto L_80001F64;
    }
    // 0x80001E8C: nop

L_80001E90:
    // 0x80001E90: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80001E94: lw          $v0, -0x104($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X104);
    // 0x80001E98: beq         $v0, $zero, L_80001F64
    if (ctx->r2 == 0) {
        // 0x80001E9C: addu        $a1, $v0, $zero
        ctx->r5 = ADD32(ctx->r2, 0);
            goto L_80001F64;
    }
    // 0x80001E9C: addu        $a1, $v0, $zero
    ctx->r5 = ADD32(ctx->r2, 0);
    // 0x80001EA0: lhu         $v1, 0x0($a1)
    ctx->r3 = MEM_HU(ctx->r5, 0X0);
    // 0x80001EA4: andi        $v0, $v1, 0x8
    ctx->r2 = ctx->r3 & 0X8;
    // 0x80001EA8: bne         $v0, $zero, L_80001F64
    if (ctx->r2 != 0) {
        // 0x80001EAC: addu        $t0, $zero, $zero
        ctx->r8 = ADD32(0, 0);
            goto L_80001F64;
    }
    // 0x80001EAC: addu        $t0, $zero, $zero
    ctx->r8 = ADD32(0, 0);
    // 0x80001EB0: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
L_80001EB4:
    // 0x80001EB4: lw          $v0, 0x4($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X4);
    // 0x80001EB8: addu        $a2, $a1, $v0
    ctx->r6 = ADD32(ctx->r5, ctx->r2);
    // 0x80001EBC: andi        $v0, $v1, 0x2
    ctx->r2 = ctx->r3 & 0X2;
    // 0x80001EC0: beq         $v0, $zero, L_80001F4C
    if (ctx->r2 == 0) {
        // 0x80001EC4: addiu       $a3, $a2, 0x10
        ctx->r7 = ADD32(ctx->r6, 0X10);
            goto L_80001F4C;
    }
    // 0x80001EC4: addiu       $a3, $a2, 0x10
    ctx->r7 = ADD32(ctx->r6, 0X10);
    // 0x80001EC8: bnel        $a0, $a1, L_80001F50
    if (ctx->r4 != ctx->r5) {
        // 0x80001ECC: addu        $t0, $a1, $zero
        ctx->r8 = ADD32(ctx->r5, 0);
            goto L_80001F50;
    }
    goto skip_4;
    // 0x80001ECC: addu        $t0, $a1, $zero
    ctx->r8 = ADD32(ctx->r5, 0);
    skip_4:
    // 0x80001ED0: srl         $v0, $v1, 2
    ctx->r2 = S32(U32(ctx->r3) >> 2);
    // 0x80001ED4: xori        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 ^ 0X1;
    // 0x80001ED8: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x80001EDC: beq         $v0, $zero, L_80001F64
    if (ctx->r2 == 0) {
        // 0x80001EE0: nop
    
            goto L_80001F64;
    }
    // 0x80001EE0: nop

    // 0x80001EE4: sh          $t1, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r9;
    // 0x80001EE8: lhu         $v1, 0x10($a2)
    ctx->r3 = MEM_HU(ctx->r6, 0X10);
    // 0x80001EEC: andi        $v0, $v1, 0x1
    ctx->r2 = ctx->r3 & 0X1;
    // 0x80001EF0: beq         $v0, $zero, L_80001F14
    if (ctx->r2 == 0) {
        // 0x80001EF4: andi        $v0, $v1, 0x4
        ctx->r2 = ctx->r3 & 0X4;
            goto L_80001F14;
    }
    // 0x80001EF4: andi        $v0, $v1, 0x4
    ctx->r2 = ctx->r3 & 0X4;
    // 0x80001EF8: bne         $v0, $zero, L_80001F14
    if (ctx->r2 != 0) {
        // 0x80001EFC: nop
    
            goto L_80001F14;
    }
    // 0x80001EFC: nop

    // 0x80001F00: lw          $v0, 0x4($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X4);
    // 0x80001F04: lw          $v1, 0x14($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X14);
    // 0x80001F08: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x80001F0C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80001F10: sw          $v0, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r2;
L_80001F14:
    // 0x80001F14: beq         $t0, $zero, L_80001F64
    if (ctx->r8 == 0) {
        // 0x80001F18: nop
    
            goto L_80001F64;
    }
    // 0x80001F18: nop

    // 0x80001F1C: lhu         $v1, 0x0($t0)
    ctx->r3 = MEM_HU(ctx->r8, 0X0);
    // 0x80001F20: andi        $v0, $v1, 0x1
    ctx->r2 = ctx->r3 & 0X1;
    // 0x80001F24: beq         $v0, $zero, L_80001F64
    if (ctx->r2 == 0) {
        // 0x80001F28: andi        $v0, $v1, 0x4
        ctx->r2 = ctx->r3 & 0X4;
            goto L_80001F64;
    }
    // 0x80001F28: andi        $v0, $v1, 0x4
    ctx->r2 = ctx->r3 & 0X4;
    // 0x80001F2C: bne         $v0, $zero, L_80001F64
    if (ctx->r2 != 0) {
        // 0x80001F30: nop
    
            goto L_80001F64;
    }
    // 0x80001F30: nop

    // 0x80001F34: lw          $v0, 0x4($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X4);
    // 0x80001F38: lw          $v1, 0x4($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X4);
    // 0x80001F3C: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x80001F40: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80001F44: j           L_80001F64
    // 0x80001F48: sw          $v0, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r2;
        goto L_80001F64;
    // 0x80001F48: sw          $v0, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r2;
L_80001F4C:
    // 0x80001F4C: addu        $t0, $a1, $zero
    ctx->r8 = ADD32(ctx->r5, 0);
L_80001F50:
    // 0x80001F50: addu        $a1, $a3, $zero
    ctx->r5 = ADD32(ctx->r7, 0);
    // 0x80001F54: lhu         $v1, 0x0($a1)
    ctx->r3 = MEM_HU(ctx->r5, 0X0);
    // 0x80001F58: andi        $v0, $v1, 0x8
    ctx->r2 = ctx->r3 & 0X8;
    // 0x80001F5C: beq         $v0, $zero, L_80001EB4
    if (ctx->r2 == 0) {
        // 0x80001F60: nop
    
            goto L_80001EB4;
    }
    // 0x80001F60: nop

L_80001F64:
    // 0x80001F64: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80001F68: addiu       $a0, $a0, -0x120
    ctx->r4 = ADD32(ctx->r4, -0X120);
    // 0x80001F6C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80001F70: jal         0x80033410
    // 0x80001F74: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    osSendMesg_recomp(rdram, ctx);
        goto after_1;
    // 0x80001F74: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    after_1:
L_80001F78:
    // 0x80001F78: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80001F7C: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80001F80: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80001F84: jr          $ra
    // 0x80001F88: nop

    return;
    // 0x80001F88: nop

;}
RECOMP_FUNC void func_80001F8C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80001F8C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80001F90: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80001F94: lw          $s2, 0x48($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X48);
    // 0x80001F98: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80001F9C: addu        $s3, $a0, $zero
    ctx->r19 = ADD32(ctx->r4, 0);
    // 0x80001FA0: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80001FA4: addu        $s4, $a1, $zero
    ctx->r20 = ADD32(ctx->r5, 0);
    // 0x80001FA8: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x80001FAC: addu        $s5, $a2, $zero
    ctx->r21 = ADD32(ctx->r6, 0);
    // 0x80001FB0: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80001FB4: addu        $s1, $a3, $zero
    ctx->r17 = ADD32(ctx->r7, 0);
    // 0x80001FB8: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80001FBC: addiu       $a0, $a0, -0x120
    ctx->r4 = ADD32(ctx->r4, -0X120);
    // 0x80001FC0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80001FC4: lbu         $s0, 0x4F($sp)
    ctx->r16 = MEM_BU(ctx->r29, 0X4F);
    // 0x80001FC8: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x80001FCC: addiu       $a1, $a1, -0x108
    ctx->r5 = ADD32(ctx->r5, -0X108);
    // 0x80001FD0: sw          $ra, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r31;
    // 0x80001FD4: jal         0x8002B300
    // 0x80001FD8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_0;
    // 0x80001FD8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x80001FDC: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80001FE0: addiu       $a0, $a0, -0x120
    ctx->r4 = ADD32(ctx->r4, -0X120);
    // 0x80001FE4: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80001FE8: jal         0x80033410
    // 0x80001FEC: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    osSendMesg_recomp(rdram, ctx);
        goto after_1;
    // 0x80001FEC: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    after_1:
    // 0x80001FF0: beq         $s0, $zero, L_8000201C
    if (ctx->r16 == 0) {
        // 0x80001FF4: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8000201C;
    }
    // 0x80001FF4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80001FF8: sw          $s1, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r17;
    // 0x80001FFC: sh          $v0, 0x0($s1)
    MEM_H(0X0, ctx->r17) = ctx->r2;
    // 0x80002000: lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X0);
    // 0x80002004: sh          $zero, 0x2($v0)
    MEM_H(0X2, ctx->r2) = 0;
    // 0x80002008: lw          $v1, 0x0($s3)
    ctx->r3 = MEM_W(ctx->r19, 0X0);
    // 0x8000200C: subu        $v0, $s2, $s1
    ctx->r2 = SUB32(ctx->r18, ctx->r17);
    // 0x80002010: addiu       $v0, $v0, -0x20
    ctx->r2 = ADD32(ctx->r2, -0X20);
    // 0x80002014: j           L_80002048
    // 0x80002018: sw          $v0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r2;
        goto L_80002048;
    // 0x80002018: sw          $v0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r2;
L_8000201C:
    // 0x8000201C: addu        $a3, $s1, $zero
    ctx->r7 = ADD32(ctx->r17, 0);
L_80002020:
    // 0x80002020: lw          $v0, 0x4($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X4);
    // 0x80002024: addu        $v0, $a3, $v0
    ctx->r2 = ADD32(ctx->r7, ctx->r2);
    // 0x80002028: lhu         $v1, 0x10($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X10);
    // 0x8000202C: addu        $a1, $a3, $zero
    ctx->r5 = ADD32(ctx->r7, 0);
    // 0x80002030: andi        $v1, $v1, 0x8
    ctx->r3 = ctx->r3 & 0X8;
    // 0x80002034: beq         $v1, $zero, L_80002020
    if (ctx->r3 == 0) {
        // 0x80002038: addiu       $a3, $v0, 0x10
        ctx->r7 = ADD32(ctx->r2, 0X10);
            goto L_80002020;
    }
    // 0x80002038: addiu       $a3, $v0, 0x10
    ctx->r7 = ADD32(ctx->r2, 0X10);
    // 0x8000203C: subu        $v0, $s2, $a1
    ctx->r2 = SUB32(ctx->r18, ctx->r5);
    // 0x80002040: addiu       $v0, $v0, -0x20
    ctx->r2 = ADD32(ctx->r2, -0X20);
    // 0x80002044: sw          $v0, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r2;
L_80002048:
    // 0x80002048: addu        $t2, $zero, $zero
    ctx->r10 = ADD32(0, 0);
    // 0x8000204C: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
    // 0x80002050: sh          $v0, -0x10($s2)
    MEM_H(-0X10, ctx->r18) = ctx->r2;
    // 0x80002054: sh          $zero, -0xE($s2)
    MEM_H(-0XE, ctx->r18) = 0;
    // 0x80002058: beq         $s4, $zero, L_80002128
    if (ctx->r20 == 0) {
        // 0x8000205C: sw          $zero, -0xC($s2)
        MEM_W(-0XC, ctx->r18) = 0;
            goto L_80002128;
    }
    // 0x8000205C: sw          $zero, -0xC($s2)
    MEM_W(-0XC, ctx->r18) = 0;
    // 0x80002060: addiu       $t5, $zero, -0x10
    ctx->r13 = ADD32(0, -0X10);
    // 0x80002064: addiu       $t4, $zero, 0x6
    ctx->r12 = ADD32(0, 0X6);
    // 0x80002068: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8000206C: addu        $a2, $s5, $zero
    ctx->r6 = ADD32(ctx->r21, 0);
L_80002070:
    // 0x80002070: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x80002074: lw          $a3, 0x0($s3)
    ctx->r7 = MEM_W(ctx->r19, 0X0);
    // 0x80002078: lw          $v1, 0x4($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X4);
    // 0x8000207C: addiu       $a1, $v0, -0x10
    ctx->r5 = ADD32(ctx->r2, -0X10);
    // 0x80002080: lhu         $v0, 0x0($a3)
    ctx->r2 = MEM_HU(ctx->r7, 0X0);
    // 0x80002084: addiu       $v1, $v1, 0xF
    ctx->r3 = ADD32(ctx->r3, 0XF);
    // 0x80002088: andi        $v0, $v0, 0x8
    ctx->r2 = ctx->r2 & 0X8;
    // 0x8000208C: bne         $v0, $zero, L_80002118
    if (ctx->r2 != 0) {
        // 0x80002090: and         $t1, $v1, $t5
        ctx->r9 = ctx->r3 & ctx->r13;
            goto L_80002118;
    }
    // 0x80002090: and         $t1, $v1, $t5
    ctx->r9 = ctx->r3 & ctx->r13;
L_80002094:
    // 0x80002094: lw          $v0, 0x4($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X4);
    // 0x80002098: addu        $a0, $a3, $v0
    ctx->r4 = ADD32(ctx->r7, ctx->r2);
    // 0x8000209C: addiu       $t0, $a0, 0x10
    ctx->r8 = ADD32(ctx->r4, 0X10);
    // 0x800020A0: sltu        $v0, $a1, $a3
    ctx->r2 = ctx->r5 < ctx->r7 ? 1 : 0;
    // 0x800020A4: xori        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 ^ 0X1;
    // 0x800020A8: sltu        $v1, $a1, $t0
    ctx->r3 = ctx->r5 < ctx->r8 ? 1 : 0;
    // 0x800020AC: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x800020B0: beq         $v0, $zero, L_80002108
    if (ctx->r2 == 0) {
        // 0x800020B4: nop
    
            goto L_80002108;
    }
    // 0x800020B4: nop

    // 0x800020B8: sh          $t4, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r12;
    // 0x800020BC: beq         $a1, $a3, L_800020D0
    if (ctx->r5 == ctx->r7) {
        // 0x800020C0: sh          $zero, 0x2($a1)
        MEM_H(0X2, ctx->r5) = 0;
            goto L_800020D0;
    }
    // 0x800020C0: sh          $zero, 0x2($a1)
    MEM_H(0X2, ctx->r5) = 0;
    // 0x800020C4: subu        $v0, $a1, $a3
    ctx->r2 = SUB32(ctx->r5, ctx->r7);
    // 0x800020C8: addiu       $v0, $v0, -0x10
    ctx->r2 = ADD32(ctx->r2, -0X10);
    // 0x800020CC: sw          $v0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r2;
L_800020D0:
    // 0x800020D0: subu        $v0, $t0, $a1
    ctx->r2 = SUB32(ctx->r8, ctx->r5);
    // 0x800020D4: addiu       $v1, $v0, -0x10
    ctx->r3 = ADD32(ctx->r2, -0X10);
    // 0x800020D8: beq         $v1, $t1, L_80002100
    if (ctx->r3 == ctx->r9) {
        // 0x800020DC: subu        $a0, $v1, $t1
        ctx->r4 = SUB32(ctx->r3, ctx->r9);
            goto L_80002100;
    }
    // 0x800020DC: subu        $a0, $v1, $t1
    ctx->r4 = SUB32(ctx->r3, ctx->r9);
    // 0x800020E0: sltiu       $v0, $a0, 0x21
    ctx->r2 = ctx->r4 < 0X21 ? 1 : 0;
    // 0x800020E4: bnel        $v0, $zero, L_80002100
    if (ctx->r2 != 0) {
        // 0x800020E8: addu        $t1, $v1, $zero
        ctx->r9 = ADD32(ctx->r3, 0);
            goto L_80002100;
    }
    goto skip_0;
    // 0x800020E8: addu        $t1, $v1, $zero
    ctx->r9 = ADD32(ctx->r3, 0);
    skip_0:
    // 0x800020EC: addu        $v1, $a1, $t1
    ctx->r3 = ADD32(ctx->r5, ctx->r9);
    // 0x800020F0: addiu       $v0, $a0, -0x10
    ctx->r2 = ADD32(ctx->r4, -0X10);
    // 0x800020F4: sh          $t3, 0x10($v1)
    MEM_H(0X10, ctx->r3) = ctx->r11;
    // 0x800020F8: sh          $zero, 0x12($v1)
    MEM_H(0X12, ctx->r3) = 0;
    // 0x800020FC: sw          $v0, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->r2;
L_80002100:
    // 0x80002100: j           L_80002118
    // 0x80002104: sw          $t1, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r9;
        goto L_80002118;
    // 0x80002104: sw          $t1, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r9;
L_80002108:
    // 0x80002108: lhu         $v0, 0x10($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X10);
    // 0x8000210C: andi        $v0, $v0, 0x8
    ctx->r2 = ctx->r2 & 0X8;
    // 0x80002110: beq         $v0, $zero, L_80002094
    if (ctx->r2 == 0) {
        // 0x80002114: addu        $a3, $t0, $zero
        ctx->r7 = ADD32(ctx->r8, 0);
            goto L_80002094;
    }
    // 0x80002114: addu        $a3, $t0, $zero
    ctx->r7 = ADD32(ctx->r8, 0);
L_80002118:
    // 0x80002118: addiu       $t2, $t2, 0x1
    ctx->r10 = ADD32(ctx->r10, 0X1);
    // 0x8000211C: sltu        $v0, $t2, $s4
    ctx->r2 = ctx->r10 < ctx->r20 ? 1 : 0;
    // 0x80002120: bne         $v0, $zero, L_80002070
    if (ctx->r2 != 0) {
        // 0x80002124: addiu       $a2, $a2, 0x8
        ctx->r6 = ADD32(ctx->r6, 0X8);
            goto L_80002070;
    }
    // 0x80002124: addiu       $a2, $a2, 0x8
    ctx->r6 = ADD32(ctx->r6, 0X8);
L_80002128:
    // 0x80002128: lw          $ra, 0x30($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X30);
    // 0x8000212C: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x80002130: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80002134: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80002138: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8000213C: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80002140: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80002144: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80002148: jr          $ra
    // 0x8000214C: nop

    return;
    // 0x8000214C: nop

;}
RECOMP_FUNC void func_80002150(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80002150: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80002154: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x80002158: addu        $s2, $a0, $zero
    ctx->r18 = ADD32(ctx->r4, 0);
    // 0x8000215C: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x80002160: addu        $s3, $a1, $zero
    ctx->r19 = ADD32(ctx->r5, 0);
    // 0x80002164: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80002168: addu        $s0, $a2, $zero
    ctx->r16 = ADD32(ctx->r6, 0);
    // 0x8000216C: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x80002170: addu        $s1, $a3, $zero
    ctx->r17 = ADD32(ctx->r7, 0);
    // 0x80002174: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80002178: addiu       $a0, $a0, -0x120
    ctx->r4 = ADD32(ctx->r4, -0X120);
    // 0x8000217C: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x80002180: addiu       $a1, $a1, -0x108
    ctx->r5 = ADD32(ctx->r5, -0X108);
    // 0x80002184: sw          $ra, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r31;
    // 0x80002188: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x8000218C: sw          $s3, -0xF8($at)
    MEM_W(-0XF8, ctx->r1) = ctx->r19;
    // 0x80002190: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x80002194: sw          $s2, -0xF4($at)
    MEM_W(-0XF4, ctx->r1) = ctx->r18;
    // 0x80002198: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x8000219C: sw          $s0, -0xF0($at)
    MEM_W(-0XF0, ctx->r1) = ctx->r16;
    // 0x800021A0: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800021A4: sw          $s1, -0xEC($at)
    MEM_W(-0XEC, ctx->r1) = ctx->r17;
    // 0x800021A8: jal         0x8002B300
    // 0x800021AC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_0;
    // 0x800021AC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x800021B0: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x800021B4: addiu       $a0, $a0, -0x120
    ctx->r4 = ADD32(ctx->r4, -0X120);
    // 0x800021B8: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x800021BC: jal         0x80033410
    // 0x800021C0: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    osSendMesg_recomp(rdram, ctx);
        goto after_1;
    // 0x800021C0: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    after_1:
    // 0x800021C4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800021C8: sh          $v0, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r2;
    // 0x800021CC: subu        $v0, $s1, $s0
    ctx->r2 = SUB32(ctx->r17, ctx->r16);
    // 0x800021D0: addiu       $v0, $v0, -0x20
    ctx->r2 = ADD32(ctx->r2, -0X20);
    // 0x800021D4: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800021D8: sw          $s0, -0xE8($at)
    MEM_W(-0XE8, ctx->r1) = ctx->r16;
    // 0x800021DC: sh          $zero, 0x2($s0)
    MEM_H(0X2, ctx->r16) = 0;
    // 0x800021E0: sw          $v0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r2;
    // 0x800021E4: addu        $t2, $zero, $zero
    ctx->r10 = ADD32(0, 0);
    // 0x800021E8: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
    // 0x800021EC: sh          $v0, -0x10($s1)
    MEM_H(-0X10, ctx->r17) = ctx->r2;
    // 0x800021F0: sh          $zero, -0xE($s1)
    MEM_H(-0XE, ctx->r17) = 0;
    // 0x800021F4: beq         $s2, $zero, L_800022C8
    if (ctx->r18 == 0) {
        // 0x800021F8: sw          $zero, -0xC($s1)
        MEM_W(-0XC, ctx->r17) = 0;
            goto L_800022C8;
    }
    // 0x800021F8: sw          $zero, -0xC($s1)
    MEM_W(-0XC, ctx->r17) = 0;
    // 0x800021FC: addiu       $t5, $zero, -0x10
    ctx->r13 = ADD32(0, -0X10);
    // 0x80002200: addiu       $t4, $zero, 0x6
    ctx->r12 = ADD32(0, 0X6);
    // 0x80002204: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80002208: addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
L_8000220C:
    // 0x8000220C: lw          $v0, 0x4($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X4);
    // 0x80002210: lui         $a2, 0x8011
    ctx->r6 = S32(0X8011 << 16);
    // 0x80002214: lw          $a2, -0xE8($a2)
    ctx->r6 = MEM_W(ctx->r6, -0XE8);
    // 0x80002218: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
    // 0x8000221C: addiu       $v0, $v0, 0xF
    ctx->r2 = ADD32(ctx->r2, 0XF);
    // 0x80002220: lhu         $v1, 0x0($a2)
    ctx->r3 = MEM_HU(ctx->r6, 0X0);
    // 0x80002224: and         $t1, $v0, $t5
    ctx->r9 = ctx->r2 & ctx->r13;
    // 0x80002228: andi        $v1, $v1, 0x8
    ctx->r3 = ctx->r3 & 0X8;
    // 0x8000222C: bne         $v1, $zero, L_800022B8
    if (ctx->r3 != 0) {
        // 0x80002230: addiu       $a0, $a0, -0x10
        ctx->r4 = ADD32(ctx->r4, -0X10);
            goto L_800022B8;
    }
    // 0x80002230: addiu       $a0, $a0, -0x10
    ctx->r4 = ADD32(ctx->r4, -0X10);
L_80002234:
    // 0x80002234: lw          $v0, 0x4($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X4);
    // 0x80002238: addu        $a3, $a2, $v0
    ctx->r7 = ADD32(ctx->r6, ctx->r2);
    // 0x8000223C: addiu       $t0, $a3, 0x10
    ctx->r8 = ADD32(ctx->r7, 0X10);
    // 0x80002240: sltu        $v0, $a0, $a2
    ctx->r2 = ctx->r4 < ctx->r6 ? 1 : 0;
    // 0x80002244: xori        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 ^ 0X1;
    // 0x80002248: sltu        $v1, $a0, $t0
    ctx->r3 = ctx->r4 < ctx->r8 ? 1 : 0;
    // 0x8000224C: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x80002250: beq         $v0, $zero, L_800022A8
    if (ctx->r2 == 0) {
        // 0x80002254: nop
    
            goto L_800022A8;
    }
    // 0x80002254: nop

    // 0x80002258: sh          $t4, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r12;
    // 0x8000225C: beq         $a0, $a2, L_80002270
    if (ctx->r4 == ctx->r6) {
        // 0x80002260: sh          $zero, 0x2($a0)
        MEM_H(0X2, ctx->r4) = 0;
            goto L_80002270;
    }
    // 0x80002260: sh          $zero, 0x2($a0)
    MEM_H(0X2, ctx->r4) = 0;
    // 0x80002264: subu        $v0, $a0, $a2
    ctx->r2 = SUB32(ctx->r4, ctx->r6);
    // 0x80002268: addiu       $v0, $v0, -0x10
    ctx->r2 = ADD32(ctx->r2, -0X10);
    // 0x8000226C: sw          $v0, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r2;
L_80002270:
    // 0x80002270: subu        $v0, $t0, $a0
    ctx->r2 = SUB32(ctx->r8, ctx->r4);
    // 0x80002274: addiu       $v1, $v0, -0x10
    ctx->r3 = ADD32(ctx->r2, -0X10);
    // 0x80002278: beq         $v1, $t1, L_800022A0
    if (ctx->r3 == ctx->r9) {
        // 0x8000227C: subu        $a2, $v1, $t1
        ctx->r6 = SUB32(ctx->r3, ctx->r9);
            goto L_800022A0;
    }
    // 0x8000227C: subu        $a2, $v1, $t1
    ctx->r6 = SUB32(ctx->r3, ctx->r9);
    // 0x80002280: sltiu       $v0, $a2, 0x21
    ctx->r2 = ctx->r6 < 0X21 ? 1 : 0;
    // 0x80002284: bnel        $v0, $zero, L_800022A0
    if (ctx->r2 != 0) {
        // 0x80002288: addu        $t1, $v1, $zero
        ctx->r9 = ADD32(ctx->r3, 0);
            goto L_800022A0;
    }
    goto skip_0;
    // 0x80002288: addu        $t1, $v1, $zero
    ctx->r9 = ADD32(ctx->r3, 0);
    skip_0:
    // 0x8000228C: addu        $v1, $a0, $t1
    ctx->r3 = ADD32(ctx->r4, ctx->r9);
    // 0x80002290: addiu       $v0, $a2, -0x10
    ctx->r2 = ADD32(ctx->r6, -0X10);
    // 0x80002294: sh          $t3, 0x10($v1)
    MEM_H(0X10, ctx->r3) = ctx->r11;
    // 0x80002298: sh          $zero, 0x12($v1)
    MEM_H(0X12, ctx->r3) = 0;
    // 0x8000229C: sw          $v0, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->r2;
L_800022A0:
    // 0x800022A0: j           L_800022B8
    // 0x800022A4: sw          $t1, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r9;
        goto L_800022B8;
    // 0x800022A4: sw          $t1, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r9;
L_800022A8:
    // 0x800022A8: lhu         $v0, 0x10($a3)
    ctx->r2 = MEM_HU(ctx->r7, 0X10);
    // 0x800022AC: andi        $v0, $v0, 0x8
    ctx->r2 = ctx->r2 & 0X8;
    // 0x800022B0: beq         $v0, $zero, L_80002234
    if (ctx->r2 == 0) {
        // 0x800022B4: addu        $a2, $t0, $zero
        ctx->r6 = ADD32(ctx->r8, 0);
            goto L_80002234;
    }
    // 0x800022B4: addu        $a2, $t0, $zero
    ctx->r6 = ADD32(ctx->r8, 0);
L_800022B8:
    // 0x800022B8: addiu       $t2, $t2, 0x1
    ctx->r10 = ADD32(ctx->r10, 0X1);
    // 0x800022BC: sltu        $v0, $t2, $s2
    ctx->r2 = ctx->r10 < ctx->r18 ? 1 : 0;
    // 0x800022C0: bne         $v0, $zero, L_8000220C
    if (ctx->r2 != 0) {
        // 0x800022C4: addiu       $a1, $a1, 0x8
        ctx->r5 = ADD32(ctx->r5, 0X8);
            goto L_8000220C;
    }
    // 0x800022C4: addiu       $a1, $a1, 0x8
    ctx->r5 = ADD32(ctx->r5, 0X8);
L_800022C8:
    // 0x800022C8: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800022CC: sw          $zero, -0x100($at)
    MEM_W(-0X100, ctx->r1) = 0;
    // 0x800022D0: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800022D4: sw          $zero, -0x104($at)
    MEM_W(-0X104, ctx->r1) = 0;
    // 0x800022D8: lw          $ra, 0x30($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X30);
    // 0x800022DC: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x800022E0: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x800022E4: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x800022E8: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800022EC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x800022F0: jr          $ra
    // 0x800022F4: nop

    return;
    // 0x800022F4: nop

;}
RECOMP_FUNC void func_800022F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800022F8: lui         $t0, 0x8011
    ctx->r8 = S32(0X8011 << 16);
    // 0x800022FC: lw          $t0, -0xE8($t0)
    ctx->r8 = MEM_W(ctx->r8, -0XE8);
    // 0x80002300: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80002304: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x80002308: addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // 0x8000230C: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x80002310: addu        $s3, $a1, $zero
    ctx->r19 = ADD32(ctx->r5, 0);
    // 0x80002314: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x80002318: addu        $s2, $a2, $zero
    ctx->r18 = ADD32(ctx->r6, 0);
    // 0x8000231C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80002320: addu        $s0, $a3, $zero
    ctx->r16 = ADD32(ctx->r7, 0);
    // 0x80002324: sw          $ra, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r31;
    // 0x80002328: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x8000232C: sw          $s3, -0xF8($at)
    MEM_W(-0XF8, ctx->r1) = ctx->r19;
    // 0x80002330: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x80002334: sw          $s1, -0xF4($at)
    MEM_W(-0XF4, ctx->r1) = ctx->r17;
    // 0x80002338: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x8000233C: sw          $s2, -0xF0($at)
    MEM_W(-0XF0, ctx->r1) = ctx->r18;
    // 0x80002340: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x80002344: sw          $s0, -0xEC($at)
    MEM_W(-0XEC, ctx->r1) = ctx->r16;
    // 0x80002348: lhu         $v0, 0x0($t0)
    ctx->r2 = MEM_HU(ctx->r8, 0X0);
    // 0x8000234C: andi        $v0, $v0, 0x8
    ctx->r2 = ctx->r2 & 0X8;
    // 0x80002350: bne         $v0, $zero, L_80002444
    if (ctx->r2 != 0) {
        // 0x80002354: addiu       $t1, $zero, 0x1
        ctx->r9 = ADD32(0, 0X1);
            goto L_80002444;
    }
    // 0x80002354: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
L_80002358:
    // 0x80002358: lhu         $v0, 0x0($t0)
    ctx->r2 = MEM_HU(ctx->r8, 0X0);
    // 0x8000235C: andi        $v0, $v0, 0x6
    ctx->r2 = ctx->r2 & 0X6;
    // 0x80002360: beq         $v0, $zero, L_8000242C
    if (ctx->r2 == 0) {
        // 0x80002364: nop
    
            goto L_8000242C;
    }
    // 0x80002364: nop

    // 0x80002368: lhu         $v0, 0x2($t0)
    ctx->r2 = MEM_HU(ctx->r8, 0X2);
    // 0x8000236C: andi        $v0, $v0, 0x80
    ctx->r2 = ctx->r2 & 0X80;
    // 0x80002370: bne         $v0, $zero, L_8000242C
    if (ctx->r2 != 0) {
        // 0x80002374: nop
    
            goto L_8000242C;
    }
    // 0x80002374: nop

    // 0x80002378: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x8000237C: lw          $a0, -0xE8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0XE8);
    // 0x80002380: lhu         $v1, 0x0($a0)
    ctx->r3 = MEM_HU(ctx->r4, 0X0);
    // 0x80002384: andi        $v0, $v1, 0x8
    ctx->r2 = ctx->r3 & 0X8;
    // 0x80002388: bne         $v0, $zero, L_8000242C
    if (ctx->r2 != 0) {
        // 0x8000238C: addu        $a3, $zero, $zero
        ctx->r7 = ADD32(0, 0);
            goto L_8000242C;
    }
    // 0x8000238C: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
L_80002390:
    // 0x80002390: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    // 0x80002394: addu        $a1, $a0, $v0
    ctx->r5 = ADD32(ctx->r4, ctx->r2);
    // 0x80002398: andi        $v0, $v1, 0x2
    ctx->r2 = ctx->r3 & 0X2;
    // 0x8000239C: beq         $v0, $zero, L_80002414
    if (ctx->r2 == 0) {
        // 0x800023A0: addiu       $a2, $a1, 0x10
        ctx->r6 = ADD32(ctx->r5, 0X10);
            goto L_80002414;
    }
    // 0x800023A0: addiu       $a2, $a1, 0x10
    ctx->r6 = ADD32(ctx->r5, 0X10);
    // 0x800023A4: bnel        $t0, $a0, L_80002418
    if (ctx->r8 != ctx->r4) {
        // 0x800023A8: addu        $a3, $a0, $zero
        ctx->r7 = ADD32(ctx->r4, 0);
            goto L_80002418;
    }
    goto skip_0;
    // 0x800023A8: addu        $a3, $a0, $zero
    ctx->r7 = ADD32(ctx->r4, 0);
    skip_0:
    // 0x800023AC: sh          $t1, 0x0($t0)
    MEM_H(0X0, ctx->r8) = ctx->r9;
    // 0x800023B0: lhu         $v1, 0x10($a1)
    ctx->r3 = MEM_HU(ctx->r5, 0X10);
    // 0x800023B4: andi        $v0, $v1, 0x1
    ctx->r2 = ctx->r3 & 0X1;
    // 0x800023B8: beq         $v0, $zero, L_800023DC
    if (ctx->r2 == 0) {
        // 0x800023BC: andi        $v0, $v1, 0x4
        ctx->r2 = ctx->r3 & 0X4;
            goto L_800023DC;
    }
    // 0x800023BC: andi        $v0, $v1, 0x4
    ctx->r2 = ctx->r3 & 0X4;
    // 0x800023C0: bne         $v0, $zero, L_800023DC
    if (ctx->r2 != 0) {
        // 0x800023C4: nop
    
            goto L_800023DC;
    }
    // 0x800023C4: nop

    // 0x800023C8: lw          $v0, 0x4($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X4);
    // 0x800023CC: lw          $v1, 0x14($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X14);
    // 0x800023D0: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x800023D4: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800023D8: sw          $v0, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r2;
L_800023DC:
    // 0x800023DC: beq         $a3, $zero, L_8000242C
    if (ctx->r7 == 0) {
        // 0x800023E0: nop
    
            goto L_8000242C;
    }
    // 0x800023E0: nop

    // 0x800023E4: lhu         $v1, 0x0($a3)
    ctx->r3 = MEM_HU(ctx->r7, 0X0);
    // 0x800023E8: andi        $v0, $v1, 0x1
    ctx->r2 = ctx->r3 & 0X1;
    // 0x800023EC: beq         $v0, $zero, L_8000242C
    if (ctx->r2 == 0) {
        // 0x800023F0: andi        $v0, $v1, 0x4
        ctx->r2 = ctx->r3 & 0X4;
            goto L_8000242C;
    }
    // 0x800023F0: andi        $v0, $v1, 0x4
    ctx->r2 = ctx->r3 & 0X4;
    // 0x800023F4: bne         $v0, $zero, L_8000242C
    if (ctx->r2 != 0) {
        // 0x800023F8: nop
    
            goto L_8000242C;
    }
    // 0x800023F8: nop

    // 0x800023FC: lw          $v0, 0x4($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X4);
    // 0x80002400: lw          $v1, 0x4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X4);
    // 0x80002404: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x80002408: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8000240C: j           L_8000242C
    // 0x80002410: sw          $v0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r2;
        goto L_8000242C;
    // 0x80002410: sw          $v0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r2;
L_80002414:
    // 0x80002414: addu        $a3, $a0, $zero
    ctx->r7 = ADD32(ctx->r4, 0);
L_80002418:
    // 0x80002418: addu        $a0, $a2, $zero
    ctx->r4 = ADD32(ctx->r6, 0);
    // 0x8000241C: lhu         $v1, 0x0($a0)
    ctx->r3 = MEM_HU(ctx->r4, 0X0);
    // 0x80002420: andi        $v0, $v1, 0x8
    ctx->r2 = ctx->r3 & 0X8;
    // 0x80002424: beq         $v0, $zero, L_80002390
    if (ctx->r2 == 0) {
        // 0x80002428: nop
    
            goto L_80002390;
    }
    // 0x80002428: nop

L_8000242C:
    // 0x8000242C: lw          $v0, 0x4($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X4);
    // 0x80002430: addu        $v0, $t0, $v0
    ctx->r2 = ADD32(ctx->r8, ctx->r2);
    // 0x80002434: lhu         $v1, 0x10($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X10);
    // 0x80002438: andi        $v1, $v1, 0x8
    ctx->r3 = ctx->r3 & 0X8;
    // 0x8000243C: beq         $v1, $zero, L_80002358
    if (ctx->r3 == 0) {
        // 0x80002440: addiu       $t0, $v0, 0x10
        ctx->r8 = ADD32(ctx->r2, 0X10);
            goto L_80002358;
    }
    // 0x80002440: addiu       $t0, $v0, 0x10
    ctx->r8 = ADD32(ctx->r2, 0X10);
L_80002444:
    // 0x80002444: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80002448: addiu       $a0, $a0, -0x120
    ctx->r4 = ADD32(ctx->r4, -0X120);
    // 0x8000244C: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x80002450: addiu       $a1, $a1, -0x108
    ctx->r5 = ADD32(ctx->r5, -0X108);
    // 0x80002454: jal         0x8002B300
    // 0x80002458: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_0;
    // 0x80002458: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x8000245C: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80002460: addiu       $a0, $a0, -0x120
    ctx->r4 = ADD32(ctx->r4, -0X120);
    // 0x80002464: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80002468: jal         0x80033410
    // 0x8000246C: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    osSendMesg_recomp(rdram, ctx);
        goto after_1;
    // 0x8000246C: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    after_1:
    // 0x80002470: addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
L_80002474:
    // 0x80002474: lw          $v0, 0x4($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X4);
    // 0x80002478: addu        $v0, $a2, $v0
    ctx->r2 = ADD32(ctx->r6, ctx->r2);
    // 0x8000247C: lhu         $v1, 0x10($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X10);
    // 0x80002480: addu        $a3, $a2, $zero
    ctx->r7 = ADD32(ctx->r6, 0);
    // 0x80002484: andi        $v1, $v1, 0x8
    ctx->r3 = ctx->r3 & 0X8;
    // 0x80002488: beq         $v1, $zero, L_80002474
    if (ctx->r3 == 0) {
        // 0x8000248C: addiu       $a2, $v0, 0x10
        ctx->r6 = ADD32(ctx->r2, 0X10);
            goto L_80002474;
    }
    // 0x8000248C: addiu       $a2, $v0, 0x10
    ctx->r6 = ADD32(ctx->r2, 0X10);
    // 0x80002490: subu        $v0, $s0, $a3
    ctx->r2 = SUB32(ctx->r16, ctx->r7);
    // 0x80002494: addu        $t2, $zero, $zero
    ctx->r10 = ADD32(0, 0);
    // 0x80002498: addiu       $v0, $v0, -0x20
    ctx->r2 = ADD32(ctx->r2, -0X20);
    // 0x8000249C: sw          $v0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r2;
    // 0x800024A0: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
    // 0x800024A4: sh          $v0, -0x10($s0)
    MEM_H(-0X10, ctx->r16) = ctx->r2;
    // 0x800024A8: sh          $zero, -0xE($s0)
    MEM_H(-0XE, ctx->r16) = 0;
    // 0x800024AC: beq         $s1, $zero, L_80002580
    if (ctx->r17 == 0) {
        // 0x800024B0: sw          $zero, -0xC($s0)
        MEM_W(-0XC, ctx->r16) = 0;
            goto L_80002580;
    }
    // 0x800024B0: sw          $zero, -0xC($s0)
    MEM_W(-0XC, ctx->r16) = 0;
    // 0x800024B4: addiu       $t5, $zero, -0x10
    ctx->r13 = ADD32(0, -0X10);
    // 0x800024B8: addiu       $t4, $zero, 0x6
    ctx->r12 = ADD32(0, 0X6);
    // 0x800024BC: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x800024C0: addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
L_800024C4:
    // 0x800024C4: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x800024C8: lui         $a2, 0x8011
    ctx->r6 = S32(0X8011 << 16);
    // 0x800024CC: lw          $a2, -0xE8($a2)
    ctx->r6 = MEM_W(ctx->r6, -0XE8);
    // 0x800024D0: lw          $v1, 0x4($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X4);
    // 0x800024D4: addiu       $a3, $v0, -0x10
    ctx->r7 = ADD32(ctx->r2, -0X10);
    // 0x800024D8: lhu         $v0, 0x0($a2)
    ctx->r2 = MEM_HU(ctx->r6, 0X0);
    // 0x800024DC: addiu       $v1, $v1, 0xF
    ctx->r3 = ADD32(ctx->r3, 0XF);
    // 0x800024E0: andi        $v0, $v0, 0x8
    ctx->r2 = ctx->r2 & 0X8;
    // 0x800024E4: bne         $v0, $zero, L_80002570
    if (ctx->r2 != 0) {
        // 0x800024E8: and         $t1, $v1, $t5
        ctx->r9 = ctx->r3 & ctx->r13;
            goto L_80002570;
    }
    // 0x800024E8: and         $t1, $v1, $t5
    ctx->r9 = ctx->r3 & ctx->r13;
L_800024EC:
    // 0x800024EC: lw          $v0, 0x4($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X4);
    // 0x800024F0: addu        $a0, $a2, $v0
    ctx->r4 = ADD32(ctx->r6, ctx->r2);
    // 0x800024F4: addiu       $t0, $a0, 0x10
    ctx->r8 = ADD32(ctx->r4, 0X10);
    // 0x800024F8: sltu        $v0, $a3, $a2
    ctx->r2 = ctx->r7 < ctx->r6 ? 1 : 0;
    // 0x800024FC: xori        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 ^ 0X1;
    // 0x80002500: sltu        $v1, $a3, $t0
    ctx->r3 = ctx->r7 < ctx->r8 ? 1 : 0;
    // 0x80002504: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x80002508: beq         $v0, $zero, L_80002560
    if (ctx->r2 == 0) {
        // 0x8000250C: nop
    
            goto L_80002560;
    }
    // 0x8000250C: nop

    // 0x80002510: sh          $t4, 0x0($a3)
    MEM_H(0X0, ctx->r7) = ctx->r12;
    // 0x80002514: beq         $a3, $a2, L_80002528
    if (ctx->r7 == ctx->r6) {
        // 0x80002518: sh          $zero, 0x2($a3)
        MEM_H(0X2, ctx->r7) = 0;
            goto L_80002528;
    }
    // 0x80002518: sh          $zero, 0x2($a3)
    MEM_H(0X2, ctx->r7) = 0;
    // 0x8000251C: subu        $v0, $a3, $a2
    ctx->r2 = SUB32(ctx->r7, ctx->r6);
    // 0x80002520: addiu       $v0, $v0, -0x10
    ctx->r2 = ADD32(ctx->r2, -0X10);
    // 0x80002524: sw          $v0, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r2;
L_80002528:
    // 0x80002528: subu        $v0, $t0, $a3
    ctx->r2 = SUB32(ctx->r8, ctx->r7);
    // 0x8000252C: addiu       $v1, $v0, -0x10
    ctx->r3 = ADD32(ctx->r2, -0X10);
    // 0x80002530: beq         $v1, $t1, L_80002558
    if (ctx->r3 == ctx->r9) {
        // 0x80002534: subu        $a0, $v1, $t1
        ctx->r4 = SUB32(ctx->r3, ctx->r9);
            goto L_80002558;
    }
    // 0x80002534: subu        $a0, $v1, $t1
    ctx->r4 = SUB32(ctx->r3, ctx->r9);
    // 0x80002538: sltiu       $v0, $a0, 0x21
    ctx->r2 = ctx->r4 < 0X21 ? 1 : 0;
    // 0x8000253C: bnel        $v0, $zero, L_80002558
    if (ctx->r2 != 0) {
        // 0x80002540: addu        $t1, $v1, $zero
        ctx->r9 = ADD32(ctx->r3, 0);
            goto L_80002558;
    }
    goto skip_1;
    // 0x80002540: addu        $t1, $v1, $zero
    ctx->r9 = ADD32(ctx->r3, 0);
    skip_1:
    // 0x80002544: addu        $v1, $a3, $t1
    ctx->r3 = ADD32(ctx->r7, ctx->r9);
    // 0x80002548: addiu       $v0, $a0, -0x10
    ctx->r2 = ADD32(ctx->r4, -0X10);
    // 0x8000254C: sh          $t3, 0x10($v1)
    MEM_H(0X10, ctx->r3) = ctx->r11;
    // 0x80002550: sh          $zero, 0x12($v1)
    MEM_H(0X12, ctx->r3) = 0;
    // 0x80002554: sw          $v0, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->r2;
L_80002558:
    // 0x80002558: j           L_80002570
    // 0x8000255C: sw          $t1, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r9;
        goto L_80002570;
    // 0x8000255C: sw          $t1, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r9;
L_80002560:
    // 0x80002560: lhu         $v0, 0x10($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X10);
    // 0x80002564: andi        $v0, $v0, 0x8
    ctx->r2 = ctx->r2 & 0X8;
    // 0x80002568: beq         $v0, $zero, L_800024EC
    if (ctx->r2 == 0) {
        // 0x8000256C: addu        $a2, $t0, $zero
        ctx->r6 = ADD32(ctx->r8, 0);
            goto L_800024EC;
    }
    // 0x8000256C: addu        $a2, $t0, $zero
    ctx->r6 = ADD32(ctx->r8, 0);
L_80002570:
    // 0x80002570: addiu       $t2, $t2, 0x1
    ctx->r10 = ADD32(ctx->r10, 0X1);
    // 0x80002574: sltu        $v0, $t2, $s1
    ctx->r2 = ctx->r10 < ctx->r17 ? 1 : 0;
    // 0x80002578: bne         $v0, $zero, L_800024C4
    if (ctx->r2 != 0) {
        // 0x8000257C: addiu       $a1, $a1, 0x8
        ctx->r5 = ADD32(ctx->r5, 0X8);
            goto L_800024C4;
    }
    // 0x8000257C: addiu       $a1, $a1, 0x8
    ctx->r5 = ADD32(ctx->r5, 0X8);
L_80002580:
    // 0x80002580: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x80002584: sw          $zero, -0x100($at)
    MEM_W(-0X100, ctx->r1) = 0;
    // 0x80002588: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x8000258C: sw          $zero, -0x104($at)
    MEM_W(-0X104, ctx->r1) = 0;
    // 0x80002590: lw          $ra, 0x30($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X30);
    // 0x80002594: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x80002598: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x8000259C: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x800025A0: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800025A4: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x800025A8: jr          $ra
    // 0x800025AC: nop

    return;
    // 0x800025AC: nop

;}
RECOMP_FUNC void func_800025B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800025B0: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x800025B4: ori         $v0, $v0, 0x400
    ctx->r2 = ctx->r2 | 0X400;
    // 0x800025B8: lui         $v1, 0x8000
    ctx->r3 = S32(0X8000 << 16);
    // 0x800025BC: addiu       $v1, $v1, 0x31C
    ctx->r3 = ADD32(ctx->r3, 0X31C);
    // 0x800025C0: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x800025C4: sw          $v1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r3;
    // 0x800025C8: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
    // 0x800025CC: jr          $ra
    // 0x800025D0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x800025D0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
;}
RECOMP_FUNC void func_800025D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800025D4: addiu       $sp, $sp, -0x228
    ctx->r29 = ADD32(ctx->r29, -0X228);
    // 0x800025D8: addu        $v0, $a0, $zero
    ctx->r2 = ADD32(ctx->r4, 0);
    // 0x800025DC: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // 0x800025E0: sw          $a1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r5;
    // 0x800025E4: lui         $a1, 0x8000
    ctx->r5 = S32(0X8000 << 16);
    // 0x800025E8: addiu       $a1, $a1, 0x440
    ctx->r5 = ADD32(ctx->r5, 0X440);
    // 0x800025EC: addu        $a3, $a2, $zero
    ctx->r7 = ADD32(ctx->r6, 0);
    // 0x800025F0: addu        $a2, $v0, $zero
    ctx->r6 = ADD32(ctx->r2, 0);
    // 0x800025F4: sw          $ra, 0x224($sp)
    MEM_W(0X224, ctx->r29) = ctx->r31;
    // 0x800025F8: jal         0x80033CC4
    // 0x800025FC: sw          $s0, 0x220($sp)
    MEM_W(0X220, ctx->r29) = ctx->r16;
    sprintf_recomp(rdram, ctx);
        goto after_0;
    // 0x800025FC: sw          $s0, 0x220($sp)
    MEM_W(0X220, ctx->r29) = ctx->r16;
    after_0:
    // 0x80002600: lui         $v1, 0x8000
    ctx->r3 = S32(0X8000 << 16);
    // 0x80002604: ori         $v1, $v1, 0x400
    ctx->r3 = ctx->r3 | 0X400;
    // 0x80002608: addiu       $s0, $v0, 0x1
    ctx->r16 = ADD32(ctx->r2, 0X1);
    // 0x8000260C: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    // 0x80002610: lui         $a0, 0x8000
    ctx->r4 = S32(0X8000 << 16);
    // 0x80002614: addiu       $a0, $a0, 0x31C
    ctx->r4 = ADD32(ctx->r4, 0X31C);
    // 0x80002618: subu        $v1, $v1, $a0
    ctx->r3 = SUB32(ctx->r3, ctx->r4);
    // 0x8000261C: sltu        $v0, $v1, $s0
    ctx->r2 = ctx->r3 < ctx->r16 ? 1 : 0;
    // 0x80002620: sw          $a0, 0x218($sp)
    MEM_W(0X218, ctx->r29) = ctx->r4;
    // 0x80002624: beq         $v0, $zero, L_80002630
    if (ctx->r2 == 0) {
        // 0x80002628: sw          $v1, 0x21C($sp)
        MEM_W(0X21C, ctx->r29) = ctx->r3;
            goto L_80002630;
    }
    // 0x80002628: sw          $v1, 0x21C($sp)
    MEM_W(0X21C, ctx->r29) = ctx->r3;
    // 0x8000262C: addu        $a2, $v1, $zero
    ctx->r6 = ADD32(ctx->r3, 0);
L_80002630:
    // 0x80002630: jal         0x800078E0
    // 0x80002634: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    rs_memset(rdram, ctx);
        goto after_1;
    // 0x80002634: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_1:
    // 0x80002638: lw          $a0, 0x218($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X218);
    // 0x8000263C: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // 0x80002640: jal         0x80007640
    // 0x80002644: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    rs_strncpy(rdram, ctx);
        goto after_2;
    // 0x80002644: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    after_2:
L_80002648:
    // 0x80002648: j           L_80002648
    pause_self(rdram);
    // 0x8000264C: nop

    // 0x80002650: lw          $ra, 0x224($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X224);
    // 0x80002654: lw          $s0, 0x220($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X220);
    // 0x80002658: addiu       $sp, $sp, 0x228
    ctx->r29 = ADD32(ctx->r29, 0X228);
    // 0x8000265C: jr          $ra
    // 0x80002660: nop

    return;
    // 0x80002660: nop

;}
RECOMP_FUNC void func_80002664(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80002664: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80002668: lw          $v0, -0x350($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X350);
    // 0x8000266C: lw          $v1, 0x44($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X44);
    // 0x80002670: andi        $v1, $v1, 0x2000
    ctx->r3 = ctx->r3 & 0X2000;
    // 0x80002674: bne         $v1, $zero, L_80002684
    if (ctx->r3 != 0) {
        // 0x80002678: lui         $v0, 0x40
        ctx->r2 = S32(0X40 << 16);
            goto L_80002684;
    }
    // 0x80002678: lui         $v0, 0x40
    ctx->r2 = S32(0X40 << 16);
    // 0x8000267C: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x80002680: lw          $v0, 0x318($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X318);
L_80002684:
    // 0x80002684: jr          $ra
    // 0x80002688: nop

    return;
    // 0x80002688: nop

;}
RECOMP_FUNC void func_8000268C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000268C: srl         $v1, $v0, 24
    ctx->r3 = S32(U32(ctx->r2) >> 24);
    // 0x80002690: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80002694: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80002698: lui         $s0, 0x8003
    ctx->r16 = S32(0X8003 << 16);
    // 0x8000269C: lw          $s0, 0x7620($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X7620);
    // 0x800026A0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800026A4: jal         0x8002BF00
    // 0x800026A8: nop

    osGetTime_recomp(rdram, ctx);
        goto after_0;
    // 0x800026A8: nop

    after_0:
    // 0x800026AC: lui         $a0, 0x3B9A
    ctx->r4 = S32(0X3B9A << 16);
    // 0x800026B0: ori         $a0, $a0, 0xCA00
    ctx->r4 = ctx->r4 | 0XCA00;
    // 0x800026B4: subu        $s0, $v1, $s0
    ctx->r16 = SUB32(ctx->r3, ctx->r16);
    // 0x800026B8: multu       $s0, $a0
    result = U64(U32(ctx->r16)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800026BC: lui         $a2, 0x8004
    ctx->r6 = S32(0X8004 << 16);
    // 0x800026C0: lw          $a2, -0x6F00($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X6F00);
    // 0x800026C4: lui         $a3, 0x8004
    ctx->r7 = S32(0X8004 << 16);
    // 0x800026C8: lw          $a3, -0x6EFC($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X6EFC);
    // 0x800026CC: lui         $at, 0x8003
    ctx->r1 = S32(0X8003 << 16);
    // 0x800026D0: sw          $v1, 0x7620($at)
    MEM_W(0X7620, ctx->r1) = ctx->r3;
    // 0x800026D4: mfhi        $a0
    ctx->r4 = hi;
    // 0x800026D8: mflo        $a1
    ctx->r5 = lo;
    // 0x800026DC: jal         0x800074E0
    // 0x800026E0: nop

    func_800074E0(rdram, ctx);
        goto after_1;
    // 0x800026E0: nop

    after_1:
    // 0x800026E4: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x800026E8: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x800026EC: addiu       $a3, $zero, 0x3E8
    ctx->r7 = ADD32(0, 0X3E8);
    // 0x800026F0: jal         0x800074E0
    // 0x800026F4: addu        $a1, $v1, $zero
    ctx->r5 = ADD32(ctx->r3, 0);
    func_800074E0(rdram, ctx);
        goto after_2;
    // 0x800026F4: addu        $a1, $v1, $zero
    ctx->r5 = ADD32(ctx->r3, 0);
    after_2:
    // 0x800026F8: addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
    // 0x800026FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80002700: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80002704: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80002708: jr          $ra
    // 0x8000270C: nop

    return;
    // 0x8000270C: nop

;}
RECOMP_FUNC void getViModePeriod(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80002710: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x80002714: lbu         $v1, -0xE0($v1)
    ctx->r3 = MEM_BU(ctx->r3, -0XE0);
    // 0x80002718: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8000271C: lwc1        $f0, 0x450($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X450);
    // 0x80002720: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80002724: bne         $v1, $v0, L_80002734
    if (ctx->r3 != ctx->r2) {
        // 0x80002728: nop
    
            goto L_80002734;
    }
    // 0x80002728: nop

    // 0x8000272C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80002730: lwc1        $f0, 0x454($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X454);
L_80002734:
    // 0x80002734: jr          $ra
    // 0x80002738: nop

    return;
    // 0x80002738: nop

;}
RECOMP_FUNC void getViModeType(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000273C: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80002740: lbu         $v0, -0xE0($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0XE0);
    // 0x80002744: jr          $ra
    // 0x80002748: nop

    return;
    // 0x80002748: nop

;}
RECOMP_FUNC void setViModeType(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000274C: lui         $v1, 0x8000
    ctx->r3 = S32(0X8000 << 16);
    // 0x80002750: lw          $v1, 0x300($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X300);
    // 0x80002754: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80002758: beq         $v1, $v0, L_80002788
    if (ctx->r3 == ctx->r2) {
        // 0x8000275C: slti        $v0, $v1, 0x2
        ctx->r2 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
            goto L_80002788;
    }
    // 0x8000275C: slti        $v0, $v1, 0x2
    ctx->r2 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
    // 0x80002760: beql        $v0, $zero, L_80002778
    if (ctx->r2 == 0) {
        // 0x80002764: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_80002778;
    }
    goto skip_0;
    // 0x80002764: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    skip_0:
    // 0x80002768: beq         $v1, $zero, L_80002798
    if (ctx->r3 == 0) {
        // 0x8000276C: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80002798;
    }
    // 0x8000276C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80002770: j           L_800027A0
    // 0x80002774: nop

        goto L_800027A0;
    // 0x80002774: nop

L_80002778:
    // 0x80002778: beq         $v1, $v0, L_80002798
    if (ctx->r3 == ctx->r2) {
        // 0x8000277C: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_80002798;
    }
    // 0x8000277C: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x80002780: j           L_800027A0
    // 0x80002784: nop

        goto L_800027A0;
    // 0x80002784: nop

L_80002788:
    // 0x80002788: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x8000278C: sb          $zero, -0xE0($at)
    MEM_B(-0XE0, ctx->r1) = 0;
    // 0x80002790: j           L_800027A0
    // 0x80002794: nop

        goto L_800027A0;
    // 0x80002794: nop

L_80002798:
    // 0x80002798: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x8000279C: sb          $v0, -0xE0($at)
    MEM_B(-0XE0, ctx->r1) = ctx->r2;
L_800027A0:
    // 0x800027A0: jr          $ra
    // 0x800027A4: nop

    return;
    // 0x800027A4: nop

;}
RECOMP_FUNC void getOsResetType(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800027A8: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x800027AC: lbu         $v0, 0x30F($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X30F);
    // 0x800027B0: jr          $ra
    // 0x800027B4: nop

    return;
    // 0x800027B4: nop

;}
RECOMP_FUNC void fake_func_800027B8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
;}
RECOMP_FUNC void func_800027C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800027C0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800027C4: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x800027C8: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // 0x800027CC: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800027D0: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x800027D4: addiu       $s0, $v0, 0x520
    ctx->r16 = ADD32(ctx->r2, 0X520);
    // 0x800027D8: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800027DC: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x800027E0: addiu       $s2, $v0, 0x788
    ctx->r18 = ADD32(ctx->r2, 0X788);
    // 0x800027E4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800027E8: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
L_800027EC:
    // 0x800027EC: lbu         $v0, 0x6B($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X6B);
    // 0x800027F0: beq         $v0, $zero, L_8000298C
    if (ctx->r2 == 0) {
        // 0x800027F4: nop
    
            goto L_8000298C;
    }
    // 0x800027F4: nop

    // 0x800027F8: lw          $v1, 0x70($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X70);
    // 0x800027FC: lhu         $v0, 0x0($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X0);
    // 0x80002800: lwc1        $f20, 0x80($s0)
    ctx->f20.u32l = MEM_W(ctx->r16, 0X80);
    // 0x80002804: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x80002808: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x8000280C: c.lt.s      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.fl < ctx->f0.fl;
    // 0x80002810: nop

    // 0x80002814: bc1f        L_80002934
    if (!c1cs) {
        // 0x80002818: addiu       $v0, $zero, -0x1
        ctx->r2 = ADD32(0, -0X1);
            goto L_80002934;
    }
    // 0x80002818: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x8000281C: lbu         $v0, 0x6C($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X6C);
    // 0x80002820: andi        $v0, $v0, 0x2
    ctx->r2 = ctx->r2 & 0X2;
    // 0x80002824: bne         $v0, $zero, L_80002934
    if (ctx->r2 != 0) {
        // 0x80002828: addiu       $v0, $zero, -0x1
        ctx->r2 = ADD32(0, -0X1);
            goto L_80002934;
    }
    // 0x80002828: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x8000282C: lhu         $v0, 0x2($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X2);
    // 0x80002830: div.s       $f20, $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = DIV_S(ctx->f20.fl, ctx->f0.fl);
    // 0x80002834: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x80002838: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x8000283C: mul.s       $f20, $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = MUL_S(ctx->f20.fl, ctx->f0.fl);
    // 0x80002840: jal         0x80007510
    // 0x80002844: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    func_80007510(rdram, ctx);
        goto after_0;
    // 0x80002844: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    after_0:
    // 0x80002848: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x8000284C: lw          $a1, 0x70($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X70);
    // 0x80002850: mtc1        $a0, $f0
    ctx->f0.u32l = ctx->r4;
    // 0x80002854: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x80002858: lhu         $v0, 0x2($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X2);
    // 0x8000285C: addiu       $v1, $v0, -0x1
    ctx->r3 = ADD32(ctx->r2, -0X1);
    // 0x80002860: slt         $v0, $a0, $v1
    ctx->r2 = SIGNED(ctx->r4) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80002864: bne         $v0, $zero, L_800028A8
    if (ctx->r2 != 0) {
        // 0x80002868: sub.s       $f20, $f20, $f0
        CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = ctx->f20.fl - ctx->f0.fl;
            goto L_800028A8;
    }
    // 0x80002868: sub.s       $f20, $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = ctx->f20.fl - ctx->f0.fl;
    // 0x8000286C: lw          $v0, 0x4($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X4);
    // 0x80002870: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
    // 0x80002874: addu        $v0, $v1, $v0
    ctx->r2 = ADD32(ctx->r3, ctx->r2);
    // 0x80002878: lhu         $v0, 0x0($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X0);
    // 0x8000287C: addu        $a0, $a1, $zero
    ctx->r4 = ADD32(ctx->r5, 0);
    // 0x80002880: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x80002884: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x80002888: swc1        $f0, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->f0.u32l;
    // 0x8000288C: lw          $v0, 0x8($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X8);
    // 0x80002890: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80002894: lhu         $v0, 0x0($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X0);
    // 0x80002898: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x8000289C: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x800028A0: j           L_8000291C
    // 0x800028A4: swc1        $f0, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = ctx->f0.u32l;
        goto L_8000291C;
    // 0x800028A4: swc1        $f0, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = ctx->f0.u32l;
L_800028A8:
    // 0x800028A8: sll         $a0, $a0, 1
    ctx->r4 = S32(ctx->r4 << 1);
    // 0x800028AC: lw          $v1, 0x4($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X4);
    // 0x800028B0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800028B4: lwc1        $f4, 0x460($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X460);
    // 0x800028B8: addu        $v1, $a0, $v1
    ctx->r3 = ADD32(ctx->r4, ctx->r3);
    // 0x800028BC: lhu         $v0, 0x0($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X0);
    // 0x800028C0: sub.s       $f4, $f4, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = ctx->f4.fl - ctx->f20.fl;
    // 0x800028C4: mtc1        $v0, $f2
    ctx->f2.u32l = ctx->r2;
    // 0x800028C8: cvt.s.w     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    ctx->f2.fl = CVT_S_W(ctx->f2.u32l);
    // 0x800028CC: mul.s       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f4.fl);
    // 0x800028D0: lhu         $v0, 0x2($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X2);
    // 0x800028D4: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x800028D8: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x800028DC: mul.s       $f0, $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x800028E0: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x800028E4: lw          $v0, 0x70($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X70);
    // 0x800028E8: swc1        $f2, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->f2.u32l;
    // 0x800028EC: lw          $v0, 0x8($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X8);
    // 0x800028F0: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x800028F4: lhu         $v0, 0x0($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X0);
    // 0x800028F8: mtc1        $v0, $f2
    ctx->f2.u32l = ctx->r2;
    // 0x800028FC: cvt.s.w     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    ctx->f2.fl = CVT_S_W(ctx->f2.u32l);
    // 0x80002900: mul.s       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f4.fl);
    // 0x80002904: lhu         $v0, 0x2($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X2);
    // 0x80002908: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x8000290C: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x80002910: mul.s       $f0, $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x80002914: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x80002918: swc1        $f2, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = ctx->f2.u32l;
L_8000291C:
    // 0x8000291C: jal         0x80002710
    // 0x80002920: nop

    getViModePeriod(rdram, ctx);
        goto after_1;
    // 0x80002920: nop

    after_1:
    // 0x80002924: lwc1        $f2, 0x80($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X80);
    // 0x80002928: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x8000292C: j           L_8000298C
    // 0x80002930: swc1        $f2, 0x80($s0)
    MEM_W(0X80, ctx->r16) = ctx->f2.u32l;
        goto L_8000298C;
    // 0x80002930: swc1        $f2, 0x80($s0)
    MEM_W(0X80, ctx->r16) = ctx->f2.u32l;
L_80002934:
    // 0x80002934: sb          $zero, 0x6B($s0)
    MEM_B(0X6B, ctx->r16) = 0;
    // 0x80002938: sw          $v0, 0x84($s0)
    MEM_W(0X84, ctx->r16) = ctx->r2;
    // 0x8000293C: lbu         $v1, 0x3($s2)
    ctx->r3 = MEM_BU(ctx->r18, 0X3);
    // 0x80002940: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
    // 0x80002944: beq         $v1, $v0, L_80002AA8
    if (ctx->r3 == ctx->r2) {
        // 0x80002948: addiu       $v0, $zero, 0x4
        ctx->r2 = ADD32(0, 0X4);
            goto L_80002AA8;
    }
    // 0x80002948: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x8000294C: beq         $v1, $v0, L_80002994
    if (ctx->r3 == ctx->r2) {
        // 0x80002950: addiu       $v0, $zero, 0x8
        ctx->r2 = ADD32(0, 0X8);
            goto L_80002994;
    }
    // 0x80002950: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
    // 0x80002954: lbu         $v0, 0x68($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X68);
    // 0x80002958: beq         $v0, $zero, L_80002990
    if (ctx->r2 == 0) {
        // 0x8000295C: lui         $a0, 0x8011
        ctx->r4 = S32(0X8011 << 16);
            goto L_80002990;
    }
    // 0x8000295C: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80002960: addiu       $a0, $a0, 0x770
    ctx->r4 = ADD32(ctx->r4, 0X770);
    // 0x80002964: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x80002968: jal         0x8002D88C
    // 0x8000296C: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    osMotorInit_recomp(rdram, ctx);
        goto after_2;
    // 0x8000296C: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    after_2:
    // 0x80002970: bnel        $v0, $zero, L_80002988
    if (ctx->r2 != 0) {
        // 0x80002974: sb          $zero, 0x68($s0)
        MEM_B(0X68, ctx->r16) = 0;
            goto L_80002988;
    }
    goto skip_0;
    // 0x80002974: sb          $zero, 0x68($s0)
    MEM_B(0X68, ctx->r16) = 0;
    skip_0:
    // 0x80002978: jal         0x8002D3D0
    // 0x8000297C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    osMotorStop_recomp(rdram, ctx);
        goto after_3;
    // 0x8000297C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_3:
    // 0x80002980: j           L_8000298C
    // 0x80002984: sb          $zero, 0x6A($s0)
    MEM_B(0X6A, ctx->r16) = 0;
        goto L_8000298C;
    // 0x80002984: sb          $zero, 0x6A($s0)
    MEM_B(0X6A, ctx->r16) = 0;
L_80002988:
    // 0x80002988: sb          $zero, 0x6A($s0)
    MEM_B(0X6A, ctx->r16) = 0;
L_8000298C:
    // 0x8000298C: lbu         $v1, 0x3($s2)
    ctx->r3 = MEM_BU(ctx->r18, 0X3);
L_80002990:
    // 0x80002990: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
L_80002994:
    // 0x80002994: beq         $v1, $v0, L_80002AA8
    if (ctx->r3 == ctx->r2) {
        // 0x80002998: addiu       $v0, $zero, 0x4
        ctx->r2 = ADD32(0, 0X4);
            goto L_80002AA8;
    }
    // 0x80002998: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x8000299C: beql        $v1, $v0, L_80002AAC
    if (ctx->r3 == ctx->r2) {
        // 0x800029A0: sb          $zero, 0x69($s0)
        MEM_B(0X69, ctx->r16) = 0;
            goto L_80002AAC;
    }
    goto skip_1;
    // 0x800029A0: sb          $zero, 0x69($s0)
    MEM_B(0X69, ctx->r16) = 0;
    skip_1:
    // 0x800029A4: lbu         $v0, 0x68($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X68);
    // 0x800029A8: bne         $v0, $zero, L_800029E8
    if (ctx->r2 != 0) {
        // 0x800029AC: nop
    
            goto L_800029E8;
    }
    // 0x800029AC: nop

    // 0x800029B0: lbu         $v0, 0x69($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X69);
    // 0x800029B4: bne         $v0, $zero, L_800029E8
    if (ctx->r2 != 0) {
        // 0x800029B8: lui         $a0, 0x8011
        ctx->r4 = S32(0X8011 << 16);
            goto L_800029E8;
    }
    // 0x800029B8: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x800029BC: addiu       $a0, $a0, 0x770
    ctx->r4 = ADD32(ctx->r4, 0X770);
    // 0x800029C0: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x800029C4: jal         0x8002D88C
    // 0x800029C8: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    osMotorInit_recomp(rdram, ctx);
        goto after_4;
    // 0x800029C8: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    after_4:
    // 0x800029CC: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x800029D0: beq         $v0, $zero, L_800029E0
    if (ctx->r2 == 0) {
        // 0x800029D4: sb          $v0, 0x68($s0)
        MEM_B(0X68, ctx->r16) = ctx->r2;
            goto L_800029E0;
    }
    // 0x800029D4: sb          $v0, 0x68($s0)
    MEM_B(0X68, ctx->r16) = ctx->r2;
    // 0x800029D8: sb          $zero, 0x6A($s0)
    MEM_B(0X6A, ctx->r16) = 0;
    // 0x800029DC: sw          $zero, 0x74($s0)
    MEM_W(0X74, ctx->r16) = 0;
L_800029E0:
    // 0x800029E0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800029E4: sb          $v0, 0x69($s0)
    MEM_B(0X69, ctx->r16) = ctx->r2;
L_800029E8:
    // 0x800029E8: lbu         $v0, 0x6B($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X6B);
    // 0x800029EC: beql        $v0, $zero, L_80002AB0
    if (ctx->r2 == 0) {
        // 0x800029F0: addiu       $s0, $s0, 0x88
        ctx->r16 = ADD32(ctx->r16, 0X88);
            goto L_80002AB0;
    }
    goto skip_2;
    // 0x800029F0: addiu       $s0, $s0, 0x88
    ctx->r16 = ADD32(ctx->r16, 0X88);
    skip_2:
    // 0x800029F4: lbu         $v0, 0x68($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X68);
    // 0x800029F8: beql        $v0, $zero, L_80002AB0
    if (ctx->r2 == 0) {
        // 0x800029FC: addiu       $s0, $s0, 0x88
        ctx->r16 = ADD32(ctx->r16, 0X88);
            goto L_80002AB0;
    }
    goto skip_3;
    // 0x800029FC: addiu       $s0, $s0, 0x88
    ctx->r16 = ADD32(ctx->r16, 0X88);
    skip_3:
    // 0x80002A00: lwc1        $f2, 0x74($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X74);
    // 0x80002A04: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80002A08: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x80002A0C: nop

    // 0x80002A10: bc1f        L_80002A90
    if (!c1cs) {
        // 0x80002A14: nop
    
            goto L_80002A90;
    }
    // 0x80002A14: nop

    // 0x80002A18: lbu         $a0, 0x6C($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X6C);
    // 0x80002A1C: andi        $v0, $a0, 0x1
    ctx->r2 = ctx->r4 & 0X1;
    // 0x80002A20: beq         $v0, $zero, L_80002A34
    if (ctx->r2 == 0) {
        // 0x80002A24: andi        $v0, $a0, 0xFE
        ctx->r2 = ctx->r4 & 0XFE;
            goto L_80002A34;
    }
    // 0x80002A24: andi        $v0, $a0, 0xFE
    ctx->r2 = ctx->r4 & 0XFE;
    // 0x80002A28: lbu         $v1, 0x6A($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X6A);
    // 0x80002A2C: bne         $v1, $zero, L_80002A50
    if (ctx->r3 != 0) {
        // 0x80002A30: sb          $v0, 0x6C($s0)
        MEM_B(0X6C, ctx->r16) = ctx->r2;
            goto L_80002A50;
    }
    // 0x80002A30: sb          $v0, 0x6C($s0)
    MEM_B(0X6C, ctx->r16) = ctx->r2;
L_80002A34:
    // 0x80002A34: lbu         $v0, 0x6A($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X6A);
    // 0x80002A38: bne         $v0, $zero, L_80002A64
    if (ctx->r2 != 0) {
        // 0x80002A3C: nop
    
            goto L_80002A64;
    }
    // 0x80002A3C: nop

    // 0x80002A40: jal         0x8002D570
    // 0x80002A44: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    osMotorStart_recomp(rdram, ctx);
        goto after_5;
    // 0x80002A44: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_5:
    // 0x80002A48: bne         $v0, $zero, L_80002A84
    if (ctx->r2 != 0) {
        // 0x80002A4C: nop
    
            goto L_80002A84;
    }
    // 0x80002A4C: nop

L_80002A50:
    // 0x80002A50: lwc1        $f0, 0x78($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X78);
    // 0x80002A54: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80002A58: sb          $v0, 0x6A($s0)
    MEM_B(0X6A, ctx->r16) = ctx->r2;
    // 0x80002A5C: j           L_80002A90
    // 0x80002A60: swc1        $f0, 0x74($s0)
    MEM_W(0X74, ctx->r16) = ctx->f0.u32l;
        goto L_80002A90;
    // 0x80002A60: swc1        $f0, 0x74($s0)
    MEM_W(0X74, ctx->r16) = ctx->f0.u32l;
L_80002A64:
    // 0x80002A64: jal         0x8002D3D0
    // 0x80002A68: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    osMotorStop_recomp(rdram, ctx);
        goto after_6;
    // 0x80002A68: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_6:
    // 0x80002A6C: bne         $v0, $zero, L_80002A84
    if (ctx->r2 != 0) {
        // 0x80002A70: nop
    
            goto L_80002A84;
    }
    // 0x80002A70: nop

    // 0x80002A74: lwc1        $f0, 0x7C($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X7C);
    // 0x80002A78: sb          $zero, 0x6A($s0)
    MEM_B(0X6A, ctx->r16) = 0;
    // 0x80002A7C: j           L_80002A90
    // 0x80002A80: swc1        $f0, 0x74($s0)
    MEM_W(0X74, ctx->r16) = ctx->f0.u32l;
        goto L_80002A90;
    // 0x80002A80: swc1        $f0, 0x74($s0)
    MEM_W(0X74, ctx->r16) = ctx->f0.u32l;
L_80002A84:
    // 0x80002A84: lbu         $v0, 0x6C($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X6C);
    // 0x80002A88: ori         $v0, $v0, 0x2
    ctx->r2 = ctx->r2 | 0X2;
    // 0x80002A8C: sb          $v0, 0x6C($s0)
    MEM_B(0X6C, ctx->r16) = ctx->r2;
L_80002A90:
    // 0x80002A90: jal         0x80002710
    // 0x80002A94: nop

    getViModePeriod(rdram, ctx);
        goto after_7;
    // 0x80002A94: nop

    after_7:
    // 0x80002A98: lwc1        $f2, 0x74($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X74);
    // 0x80002A9C: sub.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x80002AA0: j           L_80002AAC
    // 0x80002AA4: swc1        $f2, 0x74($s0)
    MEM_W(0X74, ctx->r16) = ctx->f2.u32l;
        goto L_80002AAC;
    // 0x80002AA4: swc1        $f2, 0x74($s0)
    MEM_W(0X74, ctx->r16) = ctx->f2.u32l;
L_80002AA8:
    // 0x80002AA8: sb          $zero, 0x69($s0)
    MEM_B(0X69, ctx->r16) = 0;
L_80002AAC:
    // 0x80002AAC: addiu       $s0, $s0, 0x88
    ctx->r16 = ADD32(ctx->r16, 0X88);
L_80002AB0:
    // 0x80002AB0: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80002AB4: slti        $v0, $s1, 0x4
    ctx->r2 = SIGNED(ctx->r17) < 0X4 ? 1 : 0;
    // 0x80002AB8: bne         $v0, $zero, L_800027EC
    if (ctx->r2 != 0) {
        // 0x80002ABC: addiu       $s2, $s2, 0x4
        ctx->r18 = ADD32(ctx->r18, 0X4);
            goto L_800027EC;
    }
    // 0x80002ABC: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x80002AC0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80002AC4: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x80002AC8: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x80002ACC: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80002AD0: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x80002AD4: jr          $ra
    // 0x80002AD8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80002AD8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_80002ADC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80002ADC: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80002AE0: lbu         $v0, 0x740($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X740);
    // 0x80002AE4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80002AE8: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x80002AEC: addu        $s2, $a1, $zero
    ctx->r18 = ADD32(ctx->r5, 0);
    // 0x80002AF0: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80002AF4: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x80002AF8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80002AFC: bne         $v0, $zero, L_80002B8C
    if (ctx->r2 != 0) {
        // 0x80002B00: sw          $s1, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r17;
            goto L_80002B8C;
    }
    // 0x80002B00: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x80002B04: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80002B08: addiu       $s1, $v0, 0x750
    ctx->r17 = ADD32(ctx->r2, 0X750);
    // 0x80002B0C: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x80002B10: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80002B14: jal         0x800331D0
    // 0x80002B18: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x80002B18: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x80002B1C: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80002B20: addiu       $a0, $a0, 0x520
    ctx->r4 = ADD32(ctx->r4, 0X520);
    // 0x80002B24: andi        $v1, $s0, 0xFF
    ctx->r3 = ctx->r16 & 0XFF;
    // 0x80002B28: sll         $v0, $v1, 4
    ctx->r2 = S32(ctx->r3 << 4);
    // 0x80002B2C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80002B30: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x80002B34: addu        $s0, $v0, $a0
    ctx->r16 = ADD32(ctx->r2, ctx->r4);
    // 0x80002B38: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80002B3C: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80002B40: sb          $v0, 0x6B($s0)
    MEM_B(0X6B, ctx->r16) = ctx->r2;
    // 0x80002B44: sb          $v0, 0x6C($s0)
    MEM_B(0X6C, ctx->r16) = ctx->r2;
    // 0x80002B48: lw          $v1, 0x744($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X744);
    // 0x80002B4C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x80002B50: sw          $s2, 0x70($s0)
    MEM_W(0X70, ctx->r16) = ctx->r18;
    // 0x80002B54: sw          $zero, 0x74($s0)
    MEM_W(0X74, ctx->r16) = 0;
    // 0x80002B58: sw          $zero, 0x80($s0)
    MEM_W(0X80, ctx->r16) = 0;
    // 0x80002B5C: sw          $v1, 0x84($s0)
    MEM_W(0X84, ctx->r16) = ctx->r3;
    // 0x80002B60: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80002B64: bne         $v1, $v0, L_80002B70
    if (ctx->r3 != ctx->r2) {
        // 0x80002B68: sw          $v1, 0x744($a0)
        MEM_W(0X744, ctx->r4) = ctx->r3;
            goto L_80002B70;
    }
    // 0x80002B68: sw          $v1, 0x744($a0)
    MEM_W(0X744, ctx->r4) = ctx->r3;
    // 0x80002B6C: sw          $zero, 0x744($a0)
    MEM_W(0X744, ctx->r4) = 0;
L_80002B70:
    // 0x80002B70: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x80002B74: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80002B78: jal         0x80033410
    // 0x80002B7C: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    osSendMesg_recomp(rdram, ctx);
        goto after_1;
    // 0x80002B7C: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    after_1:
    // 0x80002B80: lw          $v0, 0x84($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X84);
    // 0x80002B84: j           L_80002B90
    // 0x80002B88: nop

        goto L_80002B90;
    // 0x80002B88: nop

L_80002B8C:
    // 0x80002B8C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80002B90:
    // 0x80002B90: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80002B94: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x80002B98: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x80002B9C: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80002BA0: jr          $ra
    // 0x80002BA4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80002BA4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_80002BA8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80002BA8: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80002BAC: lbu         $v0, 0x740($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X740);
    // 0x80002BB0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80002BB4: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x80002BB8: addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // 0x80002BBC: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x80002BC0: bne         $v0, $zero, L_80002C44
    if (ctx->r2 != 0) {
        // 0x80002BC4: sw          $s0, 0x10($sp)
        MEM_W(0X10, ctx->r29) = ctx->r16;
            goto L_80002C44;
    }
    // 0x80002BC4: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80002BC8: lui         $s0, 0x8011
    ctx->r16 = S32(0X8011 << 16);
    // 0x80002BCC: addiu       $a0, $s0, 0x750
    ctx->r4 = ADD32(ctx->r16, 0X750);
    // 0x80002BD0: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80002BD4: jal         0x800331D0
    // 0x80002BD8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x80002BD8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x80002BDC: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80002BE0: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80002BE4: addiu       $v1, $v0, 0x520
    ctx->r3 = ADD32(ctx->r2, 0X520);
L_80002BE8:
    // 0x80002BE8: lbu         $v0, 0x6B($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X6B);
    // 0x80002BEC: beq         $v0, $zero, L_80002C24
    if (ctx->r2 == 0) {
        // 0x80002BF0: addiu       $a1, $a1, 0x1
        ctx->r5 = ADD32(ctx->r5, 0X1);
            goto L_80002C24;
    }
    // 0x80002BF0: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80002BF4: lw          $v0, 0x84($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X84);
    // 0x80002BF8: bnel        $s1, $v0, L_80002C28
    if (ctx->r17 != ctx->r2) {
        // 0x80002BFC: slti        $v0, $a1, 0x4
        ctx->r2 = SIGNED(ctx->r5) < 0X4 ? 1 : 0;
            goto L_80002C28;
    }
    goto skip_0;
    // 0x80002BFC: slti        $v0, $a1, 0x4
    ctx->r2 = SIGNED(ctx->r5) < 0X4 ? 1 : 0;
    skip_0:
    // 0x80002C00: addiu       $a0, $s0, 0x750
    ctx->r4 = ADD32(ctx->r16, 0X750);
    // 0x80002C04: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80002C08: lbu         $v0, 0x6C($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X6C);
    // 0x80002C0C: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    // 0x80002C10: ori         $v0, $v0, 0x2
    ctx->r2 = ctx->r2 | 0X2;
    // 0x80002C14: jal         0x80033410
    // 0x80002C18: sb          $v0, 0x6C($v1)
    MEM_B(0X6C, ctx->r3) = ctx->r2;
    osSendMesg_recomp(rdram, ctx);
        goto after_1;
    // 0x80002C18: sb          $v0, 0x6C($v1)
    MEM_B(0X6C, ctx->r3) = ctx->r2;
    after_1:
    // 0x80002C1C: j           L_80002C48
    // 0x80002C20: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80002C48;
    // 0x80002C20: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80002C24:
    // 0x80002C24: slti        $v0, $a1, 0x4
    ctx->r2 = SIGNED(ctx->r5) < 0X4 ? 1 : 0;
L_80002C28:
    // 0x80002C28: bne         $v0, $zero, L_80002BE8
    if (ctx->r2 != 0) {
        // 0x80002C2C: addiu       $v1, $v1, 0x88
        ctx->r3 = ADD32(ctx->r3, 0X88);
            goto L_80002BE8;
    }
    // 0x80002C2C: addiu       $v1, $v1, 0x88
    ctx->r3 = ADD32(ctx->r3, 0X88);
    // 0x80002C30: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80002C34: addiu       $a0, $a0, 0x750
    ctx->r4 = ADD32(ctx->r4, 0X750);
    // 0x80002C38: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80002C3C: jal         0x80033410
    // 0x80002C40: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    osSendMesg_recomp(rdram, ctx);
        goto after_2;
    // 0x80002C40: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    after_2:
L_80002C44:
    // 0x80002C44: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_80002C48:
    // 0x80002C48: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x80002C4C: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x80002C50: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80002C54: jr          $ra
    // 0x80002C58: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80002C58: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_80002C5C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80002C5C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80002C60: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x80002C64: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80002C68: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x80002C6C: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // 0x80002C70: sw          $s6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r22;
    // 0x80002C74: addiu       $s6, $zero, -0x1
    ctx->r22 = ADD32(0, -0X1);
    // 0x80002C78: sw          $s5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r21;
    // 0x80002C7C: addiu       $s5, $zero, 0x8
    ctx->r21 = ADD32(0, 0X8);
    // 0x80002C80: sw          $s4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r20;
    // 0x80002C84: addiu       $s4, $zero, 0x4
    ctx->r20 = ADD32(0, 0X4);
    // 0x80002C88: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // 0x80002C8C: lui         $s3, 0x8011
    ctx->r19 = S32(0X8011 << 16);
    // 0x80002C90: sb          $v0, 0x740($v1)
    MEM_B(0X740, ctx->r3) = ctx->r2;
    // 0x80002C94: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80002C98: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x80002C9C: addiu       $s2, $v0, 0x788
    ctx->r18 = ADD32(ctx->r2, 0X788);
    // 0x80002CA0: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80002CA4: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80002CA8: addiu       $s0, $v0, 0x520
    ctx->r16 = ADD32(ctx->r2, 0X520);
    // 0x80002CAC: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
L_80002CB0:
    // 0x80002CB0: sb          $zero, 0x6B($s0)
    MEM_B(0X6B, ctx->r16) = 0;
    // 0x80002CB4: sw          $s6, 0x84($s0)
    MEM_W(0X84, ctx->r16) = ctx->r22;
    // 0x80002CB8: lbu         $v0, 0x3($s2)
    ctx->r2 = MEM_BU(ctx->r18, 0X3);
    // 0x80002CBC: beql        $v0, $s5, L_80002CF0
    if (ctx->r2 == ctx->r21) {
        // 0x80002CC0: addiu       $s2, $s2, 0x4
        ctx->r18 = ADD32(ctx->r18, 0X4);
            goto L_80002CF0;
    }
    goto skip_0;
    // 0x80002CC0: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    skip_0:
    // 0x80002CC4: beql        $v0, $s4, L_80002CF0
    if (ctx->r2 == ctx->r20) {
        // 0x80002CC8: addiu       $s2, $s2, 0x4
        ctx->r18 = ADD32(ctx->r18, 0X4);
            goto L_80002CF0;
    }
    goto skip_1;
    // 0x80002CC8: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    skip_1:
    // 0x80002CCC: lbu         $v0, 0x68($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X68);
    // 0x80002CD0: beq         $v0, $zero, L_80002CEC
    if (ctx->r2 == 0) {
        // 0x80002CD4: addu        $a1, $s0, $zero
        ctx->r5 = ADD32(ctx->r16, 0);
            goto L_80002CEC;
    }
    // 0x80002CD4: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x80002CD8: addiu       $a0, $s3, 0x770
    ctx->r4 = ADD32(ctx->r19, 0X770);
    // 0x80002CDC: jal         0x8002D88C
    // 0x80002CE0: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    osMotorInit_recomp(rdram, ctx);
        goto after_0;
    // 0x80002CE0: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    after_0:
    // 0x80002CE4: jal         0x8002D3D0
    // 0x80002CE8: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    osMotorStop_recomp(rdram, ctx);
        goto after_1;
    // 0x80002CE8: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_1:
L_80002CEC:
    // 0x80002CEC: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
L_80002CF0:
    // 0x80002CF0: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80002CF4: slti        $v0, $s1, 0x4
    ctx->r2 = SIGNED(ctx->r17) < 0X4 ? 1 : 0;
    // 0x80002CF8: bne         $v0, $zero, L_80002CB0
    if (ctx->r2 != 0) {
        // 0x80002CFC: addiu       $s0, $s0, 0x88
        ctx->r16 = ADD32(ctx->r16, 0X88);
            goto L_80002CB0;
    }
    // 0x80002CFC: addiu       $s0, $s0, 0x88
    ctx->r16 = ADD32(ctx->r16, 0X88);
    // 0x80002D00: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80002D04: lw          $s6, 0x28($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X28);
    // 0x80002D08: lw          $s5, 0x24($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X24);
    // 0x80002D0C: lw          $s4, 0x20($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X20);
    // 0x80002D10: lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X1C);
    // 0x80002D14: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x80002D18: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x80002D1C: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80002D20: jr          $ra
    // 0x80002D24: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80002D24: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_80002D28(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80002D28: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80002D2C: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80002D30: addiu       $a0, $a0, 0x750
    ctx->r4 = ADD32(ctx->r4, 0X750);
    // 0x80002D34: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80002D38: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80002D3C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80002D40: sw          $s4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r20;
    // 0x80002D44: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // 0x80002D48: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x80002D4C: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x80002D50: jal         0x800331D0
    // 0x80002D54: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    osRecvMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x80002D54: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    after_0:
    // 0x80002D58: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // 0x80002D5C: addiu       $s4, $zero, -0x1
    ctx->r20 = ADD32(0, -0X1);
    // 0x80002D60: addiu       $s3, $zero, 0x8
    ctx->r19 = ADD32(0, 0X8);
    // 0x80002D64: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80002D68: addiu       $s0, $v0, 0x520
    ctx->r16 = ADD32(ctx->r2, 0X520);
    // 0x80002D6C: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80002D70: addiu       $s2, $v0, 0x788
    ctx->r18 = ADD32(ctx->r2, 0X788);
L_80002D74:
    // 0x80002D74: sb          $zero, 0x6B($s0)
    MEM_B(0X6B, ctx->r16) = 0;
    // 0x80002D78: sw          $s4, 0x84($s0)
    MEM_W(0X84, ctx->r16) = ctx->r20;
    // 0x80002D7C: lbu         $v1, 0x3($s2)
    ctx->r3 = MEM_BU(ctx->r18, 0X3);
    // 0x80002D80: beq         $v1, $s3, L_80002DC8
    if (ctx->r3 == ctx->r19) {
        // 0x80002D84: addiu       $v0, $zero, 0x4
        ctx->r2 = ADD32(0, 0X4);
            goto L_80002DC8;
    }
    // 0x80002D84: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x80002D88: beql        $v1, $v0, L_80002DCC
    if (ctx->r3 == ctx->r2) {
        // 0x80002D8C: addiu       $s0, $s0, 0x88
        ctx->r16 = ADD32(ctx->r16, 0X88);
            goto L_80002DCC;
    }
    goto skip_0;
    // 0x80002D8C: addiu       $s0, $s0, 0x88
    ctx->r16 = ADD32(ctx->r16, 0X88);
    skip_0:
    // 0x80002D90: lbu         $v0, 0x68($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X68);
    // 0x80002D94: beq         $v0, $zero, L_80002DC8
    if (ctx->r2 == 0) {
        // 0x80002D98: lui         $a0, 0x8011
        ctx->r4 = S32(0X8011 << 16);
            goto L_80002DC8;
    }
    // 0x80002D98: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80002D9C: addiu       $a0, $a0, 0x770
    ctx->r4 = ADD32(ctx->r4, 0X770);
    // 0x80002DA0: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x80002DA4: jal         0x8002D88C
    // 0x80002DA8: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    osMotorInit_recomp(rdram, ctx);
        goto after_1;
    // 0x80002DA8: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    after_1:
    // 0x80002DAC: bnel        $v0, $zero, L_80002DC4
    if (ctx->r2 != 0) {
        // 0x80002DB0: sb          $zero, 0x68($s0)
        MEM_B(0X68, ctx->r16) = 0;
            goto L_80002DC4;
    }
    goto skip_1;
    // 0x80002DB0: sb          $zero, 0x68($s0)
    MEM_B(0X68, ctx->r16) = 0;
    skip_1:
    // 0x80002DB4: jal         0x8002D3D0
    // 0x80002DB8: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    osMotorStop_recomp(rdram, ctx);
        goto after_2;
    // 0x80002DB8: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_2:
    // 0x80002DBC: j           L_80002DC8
    // 0x80002DC0: sb          $zero, 0x6A($s0)
    MEM_B(0X6A, ctx->r16) = 0;
        goto L_80002DC8;
    // 0x80002DC0: sb          $zero, 0x6A($s0)
    MEM_B(0X6A, ctx->r16) = 0;
L_80002DC4:
    // 0x80002DC4: sb          $zero, 0x6A($s0)
    MEM_B(0X6A, ctx->r16) = 0;
L_80002DC8:
    // 0x80002DC8: addiu       $s0, $s0, 0x88
    ctx->r16 = ADD32(ctx->r16, 0X88);
L_80002DCC:
    // 0x80002DCC: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80002DD0: slti        $v0, $s1, 0x4
    ctx->r2 = SIGNED(ctx->r17) < 0X4 ? 1 : 0;
    // 0x80002DD4: bne         $v0, $zero, L_80002D74
    if (ctx->r2 != 0) {
        // 0x80002DD8: addiu       $s2, $s2, 0x4
        ctx->r18 = ADD32(ctx->r18, 0X4);
            goto L_80002D74;
    }
    // 0x80002DD8: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x80002DDC: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80002DE0: addiu       $a0, $a0, 0x750
    ctx->r4 = ADD32(ctx->r4, 0X750);
    // 0x80002DE4: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80002DE8: jal         0x80033410
    // 0x80002DEC: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    osSendMesg_recomp(rdram, ctx);
        goto after_3;
    // 0x80002DEC: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    after_3:
    // 0x80002DF0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80002DF4: lw          $s4, 0x20($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X20);
    // 0x80002DF8: lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X1C);
    // 0x80002DFC: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x80002E00: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x80002E04: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80002E08: jr          $ra
    // 0x80002E0C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80002E0C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_80002E10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80002E10: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80002E14: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80002E18: lui         $s0, 0x8011
    ctx->r16 = S32(0X8011 << 16);
    // 0x80002E1C: addiu       $s0, $s0, 0x770
    ctx->r16 = ADD32(ctx->r16, 0X770);
    // 0x80002E20: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80002E24: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x80002E28: addiu       $a1, $a1, -0xB8
    ctx->r5 = ADD32(ctx->r5, -0XB8);
    // 0x80002E2C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80002E30: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80002E34: sw          $s4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r20;
    // 0x80002E38: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // 0x80002E3C: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x80002E40: jal         0x8002B300
    // 0x80002E44: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_0;
    // 0x80002E44: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    after_0:
    // 0x80002E48: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    // 0x80002E4C: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x80002E50: jal         0x80033560
    // 0x80002E54: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    osSetEventMesg_recomp(rdram, ctx);
        goto after_1;
    // 0x80002E54: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    after_1:
    // 0x80002E58: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80002E5C: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x80002E60: addiu       $a1, $a1, 0x798
    ctx->r5 = ADD32(ctx->r5, 0X798);
    // 0x80002E64: lui         $a2, 0x8011
    ctx->r6 = S32(0X8011 << 16);
    // 0x80002E68: jal         0x8002AE50
    // 0x80002E6C: addiu       $a2, $a2, 0x788
    ctx->r6 = ADD32(ctx->r6, 0X788);
    osContInit_recomp(rdram, ctx);
        goto after_2;
    // 0x80002E6C: addiu       $a2, $a2, 0x788
    ctx->r6 = ADD32(ctx->r6, 0X788);
    after_2:
    // 0x80002E70: lui         $s1, 0x8011
    ctx->r17 = S32(0X8011 << 16);
    // 0x80002E74: addiu       $a0, $s1, -0xB0
    ctx->r4 = ADD32(ctx->r17, -0XB0);
    // 0x80002E78: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x80002E7C: addiu       $a1, $a1, -0x98
    ctx->r5 = ADD32(ctx->r5, -0X98);
    // 0x80002E80: jal         0x8002B300
    // 0x80002E84: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_3;
    // 0x80002E84: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_3:
    // 0x80002E88: addu        $s4, $s1, $zero
    ctx->r20 = ADD32(ctx->r17, 0);
    // 0x80002E8C: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80002E90: addiu       $s2, $v0, 0x750
    ctx->r18 = ADD32(ctx->r2, 0X750);
    // 0x80002E94: lui         $s1, 0x8011
    ctx->r17 = S32(0X8011 << 16);
    // 0x80002E98: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
    // 0x80002E9C: addiu       $a0, $s4, -0xB0
    ctx->r4 = ADD32(ctx->r20, -0XB0);
L_80002EA0:
    // 0x80002EA0: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80002EA4: jal         0x800331D0
    // 0x80002EA8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_4;
    // 0x80002EA8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_4:
    // 0x80002EAC: jal         0x80037510
    // 0x80002EB0: nop

    osYieldThread_recomp(rdram, ctx);
        goto after_5;
    // 0x80002EB0: nop

    after_5:
    // 0x80002EB4: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x80002EB8: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80002EBC: jal         0x800331D0
    // 0x80002EC0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_6;
    // 0x80002EC0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_6:
    // 0x80002EC4: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80002EC8: sb          $s3, 0x741($s1)
    MEM_B(0X741, ctx->r17) = ctx->r19;
    // 0x80002ECC: jal         0x8002AB80
    // 0x80002ED0: nop

    osContStartQuery_recomp(rdram, ctx);
        goto after_7;
    // 0x80002ED0: nop

    after_7:
    // 0x80002ED4: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80002ED8: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80002EDC: jal         0x800331D0
    // 0x80002EE0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_8;
    // 0x80002EE0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_8:
    // 0x80002EE4: jal         0x80037510
    // 0x80002EE8: nop

    osYieldThread_recomp(rdram, ctx);
        goto after_9;
    // 0x80002EE8: nop

    after_9:
    // 0x80002EEC: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80002EF0: jal         0x8002AC04
    // 0x80002EF4: addiu       $a0, $a0, 0x788
    ctx->r4 = ADD32(ctx->r4, 0X788);
    osContGetQuery_recomp(rdram, ctx);
        goto after_10;
    // 0x80002EF4: addiu       $a0, $a0, 0x788
    ctx->r4 = ADD32(ctx->r4, 0X788);
    after_10:
    // 0x80002EF8: jal         0x8002AC30
    // 0x80002EFC: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    osContStartReadData_recomp(rdram, ctx);
        goto after_11;
    // 0x80002EFC: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_11:
    // 0x80002F00: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80002F04: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80002F08: jal         0x800331D0
    // 0x80002F0C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_12;
    // 0x80002F0C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_12:
    // 0x80002F10: jal         0x80037510
    // 0x80002F14: nop

    osYieldThread_recomp(rdram, ctx);
        goto after_13;
    // 0x80002F14: nop

    after_13:
    // 0x80002F18: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80002F1C: jal         0x8002ACBC
    // 0x80002F20: addiu       $a0, $a0, -0xD0
    ctx->r4 = ADD32(ctx->r4, -0XD0);
    osContGetReadData_recomp(rdram, ctx);
        goto after_14;
    // 0x80002F20: addiu       $a0, $a0, -0xD0
    ctx->r4 = ADD32(ctx->r4, -0XD0);
    after_14:
    // 0x80002F24: jal         0x800027C0
    // 0x80002F28: nop

    func_800027C0(rdram, ctx);
        goto after_15;
    // 0x80002F28: nop

    after_15:
    // 0x80002F2C: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x80002F30: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80002F34: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    // 0x80002F38: sb          $zero, 0x741($s1)
    MEM_B(0X741, ctx->r17) = 0;
    // 0x80002F3C: jal         0x80033410
    // 0x80002F40: nop

    osSendMesg_recomp(rdram, ctx);
        goto after_16;
    // 0x80002F40: nop

    after_16:
    // 0x80002F44: j           L_80002EA0
    // 0x80002F48: addiu       $a0, $s4, -0xB0
    ctx->r4 = ADD32(ctx->r20, -0XB0);
        goto L_80002EA0;
    // 0x80002F48: addiu       $a0, $s4, -0xB0
    ctx->r4 = ADD32(ctx->r20, -0XB0);
;}
RECOMP_FUNC void func_80002F4C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80002F4C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80002F50: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80002F54: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    // 0x80002F58: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80002F5C: addiu       $v1, $v0, 0x520
    ctx->r3 = ADD32(ctx->r2, 0X520);
    // 0x80002F60: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80002F64: addiu       $a0, $v0, -0xD0
    ctx->r4 = ADD32(ctx->r2, -0XD0);
    // 0x80002F68: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80002F6C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
L_80002F70:
    // 0x80002F70: sb          $a2, 0x4($a0)
    MEM_B(0X4, ctx->r4) = ctx->r6;
    // 0x80002F74: sb          $zero, 0x69($v1)
    MEM_B(0X69, ctx->r3) = 0;
    // 0x80002F78: sb          $zero, 0x68($v1)
    MEM_B(0X68, ctx->r3) = 0;
    // 0x80002F7C: sb          $zero, 0x6B($v1)
    MEM_B(0X6B, ctx->r3) = 0;
    // 0x80002F80: addiu       $v1, $v1, 0x88
    ctx->r3 = ADD32(ctx->r3, 0X88);
    // 0x80002F84: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80002F88: slti        $v0, $a1, 0x4
    ctx->r2 = SIGNED(ctx->r5) < 0X4 ? 1 : 0;
    // 0x80002F8C: bne         $v0, $zero, L_80002F70
    if (ctx->r2 != 0) {
        // 0x80002F90: addiu       $a0, $a0, 0x6
        ctx->r4 = ADD32(ctx->r4, 0X6);
            goto L_80002F70;
    }
    // 0x80002F90: addiu       $a0, $a0, 0x6
    ctx->r4 = ADD32(ctx->r4, 0X6);
    // 0x80002F94: lui         $s0, 0x8011
    ctx->r16 = S32(0X8011 << 16);
    // 0x80002F98: addiu       $s0, $s0, -0x90
    ctx->r16 = ADD32(ctx->r16, -0X90);
    // 0x80002F9C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80002FA0: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80002FA4: sb          $zero, 0x741($v0)
    MEM_B(0X741, ctx->r2) = 0;
    // 0x80002FA8: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80002FAC: addiu       $v0, $v0, 0x520
    ctx->r2 = ADD32(ctx->r2, 0X520);
    // 0x80002FB0: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x80002FB4: addiu       $v0, $zero, 0x76
    ctx->r2 = ADD32(0, 0X76);
    // 0x80002FB8: lui         $a2, 0x8000
    ctx->r6 = S32(0X8000 << 16);
    // 0x80002FBC: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80002FC0: addiu       $a2, $a2, 0x2E10
    ctx->r6 = ADD32(ctx->r6, 0X2E10);
    // 0x80002FC4: addu        $a3, $a1, $zero
    ctx->r7 = ADD32(ctx->r5, 0);
    // 0x80002FC8: jal         0x8002B330
    // 0x80002FCC: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    osCreateThread_recomp(rdram, ctx);
        goto after_0;
    // 0x80002FCC: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    after_0:
    // 0x80002FD0: jal         0x800344E0
    // 0x80002FD4: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    osStartThread_recomp(rdram, ctx);
        goto after_1;
    // 0x80002FD4: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_1:
    // 0x80002FD8: lui         $a0, 0x8000
    ctx->r4 = S32(0X8000 << 16);
    // 0x80002FDC: jal         0x80007910
    // 0x80002FE0: addiu       $a0, $a0, 0x3250
    ctx->r4 = ADD32(ctx->r4, 0X3250);
    func_80007910(rdram, ctx);
        goto after_2;
    // 0x80002FE0: addiu       $a0, $a0, 0x3250
    ctx->r4 = ADD32(ctx->r4, 0X3250);
    after_2:
    // 0x80002FE4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80002FE8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80002FEC: jr          $ra
    // 0x80002FF0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80002FF0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_80002FF4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80002FF4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80002FF8: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80002FFC: lui         $s0, 0x8011
    ctx->r16 = S32(0X8011 << 16);
    // 0x80003000: lw          $v0, 0x748($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X748);
    // 0x80003004: beq         $v0, $zero, L_800030F0
    if (ctx->r2 == 0) {
        // 0x80003008: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_800030F0;
    }
    // 0x80003008: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000300C: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80003010: addiu       $a0, $a0, 0x750
    ctx->r4 = ADD32(ctx->r4, 0X750);
    // 0x80003014: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80003018: jal         0x800331D0
    // 0x8000301C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x8000301C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x80003020: addu        $t0, $zero, $zero
    ctx->r8 = ADD32(0, 0);
    // 0x80003024: addiu       $t2, $zero, 0x8
    ctx->r10 = ADD32(0, 0X8);
    // 0x80003028: addiu       $t1, $zero, 0x4
    ctx->r9 = ADD32(0, 0X4);
    // 0x8000302C: addu        $a3, $s0, $zero
    ctx->r7 = ADD32(ctx->r16, 0);
    // 0x80003030: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80003034: addu        $a1, $t0, $zero
    ctx->r5 = ADD32(ctx->r8, 0);
    // 0x80003038: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x8000303C: addiu       $a0, $v0, -0xD0
    ctx->r4 = ADD32(ctx->r2, -0XD0);
    // 0x80003040: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80003044: addiu       $a2, $v0, 0x788
    ctx->r6 = ADD32(ctx->r2, 0X788);
L_80003048:
    // 0x80003048: lbu         $v0, 0x3($a2)
    ctx->r2 = MEM_BU(ctx->r6, 0X3);
    // 0x8000304C: beq         $v0, $t2, L_800030B8
    if (ctx->r2 == ctx->r10) {
        // 0x80003050: nop
    
            goto L_800030B8;
    }
    // 0x80003050: nop

    // 0x80003054: beq         $v0, $t1, L_800030B8
    if (ctx->r2 == ctx->r9) {
        // 0x80003058: nop
    
            goto L_800030B8;
    }
    // 0x80003058: nop

    // 0x8000305C: lhu         $v0, 0x0($a2)
    ctx->r2 = MEM_HU(ctx->r6, 0X0);
    // 0x80003060: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x80003064: beq         $v0, $zero, L_800030B8
    if (ctx->r2 == 0) {
        // 0x80003068: nop
    
            goto L_800030B8;
    }
    // 0x80003068: nop

    // 0x8000306C: lbu         $v0, 0x4($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X4);
    // 0x80003070: beq         $v0, $t2, L_800030B8
    if (ctx->r2 == ctx->r10) {
        // 0x80003074: nop
    
            goto L_800030B8;
    }
    // 0x80003074: nop

    // 0x80003078: beq         $v0, $t1, L_800030B8
    if (ctx->r2 == ctx->r9) {
        // 0x8000307C: nop
    
            goto L_800030B8;
    }
    // 0x8000307C: nop

    // 0x80003080: lw          $v1, 0x748($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X748);
    // 0x80003084: lhu         $v0, 0x0($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X0);
    // 0x80003088: addu        $v1, $v1, $a1
    ctx->r3 = ADD32(ctx->r3, ctx->r5);
    // 0x8000308C: sh          $v0, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r2;
    // 0x80003090: lbu         $v0, 0x2($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X2);
    // 0x80003094: sb          $v0, 0x2($v1)
    MEM_B(0X2, ctx->r3) = ctx->r2;
    // 0x80003098: lw          $v0, 0x748($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X748);
    // 0x8000309C: lbu         $v1, 0x3($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X3);
    // 0x800030A0: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x800030A4: sb          $v1, 0x3($v0)
    MEM_B(0X3, ctx->r2) = ctx->r3;
    // 0x800030A8: lw          $v0, 0x748($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X748);
    // 0x800030AC: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x800030B0: j           L_800030C4
    // 0x800030B4: sb          $t3, 0x4($v0)
    MEM_B(0X4, ctx->r2) = ctx->r11;
        goto L_800030C4;
    // 0x800030B4: sb          $t3, 0x4($v0)
    MEM_B(0X4, ctx->r2) = ctx->r11;
L_800030B8:
    // 0x800030B8: lw          $v0, 0x748($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X748);
    // 0x800030BC: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x800030C0: sb          $zero, 0x4($v0)
    MEM_B(0X4, ctx->r2) = 0;
L_800030C4:
    // 0x800030C4: addiu       $a1, $a1, 0x6
    ctx->r5 = ADD32(ctx->r5, 0X6);
    // 0x800030C8: addiu       $a0, $a0, 0x6
    ctx->r4 = ADD32(ctx->r4, 0X6);
    // 0x800030CC: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x800030D0: slti        $v0, $t0, 0x4
    ctx->r2 = SIGNED(ctx->r8) < 0X4 ? 1 : 0;
    // 0x800030D4: bne         $v0, $zero, L_80003048
    if (ctx->r2 != 0) {
        // 0x800030D8: addiu       $a2, $a2, 0x4
        ctx->r6 = ADD32(ctx->r6, 0X4);
            goto L_80003048;
    }
    // 0x800030D8: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    // 0x800030DC: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x800030E0: addiu       $a0, $a0, 0x750
    ctx->r4 = ADD32(ctx->r4, 0X750);
    // 0x800030E4: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x800030E8: jal         0x80033410
    // 0x800030EC: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    osSendMesg_recomp(rdram, ctx);
        goto after_1;
    // 0x800030EC: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    after_1:
L_800030F0:
    // 0x800030F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800030F4: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x800030F8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800030FC: jr          $ra
    // 0x80003100: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80003100: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80003104(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80003104: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x80003108: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8000310C: bne         $a0, $v0, L_80003148
    if (ctx->r4 != ctx->r2) {
        // 0x80003110: lui         $v0, 0x8011
        ctx->r2 = S32(0X8011 << 16);
            goto L_80003148;
    }
    // 0x80003110: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80003114: sw          $a1, 0x748($v0)
    MEM_W(0X748, ctx->r2) = ctx->r5;
    // 0x80003118: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x8000311C: addu        $a1, $v0, $zero
    ctx->r5 = ADD32(ctx->r2, 0);
    // 0x80003120: addu        $v1, $a0, $zero
    ctx->r3 = ADD32(ctx->r4, 0);
L_80003124:
    // 0x80003124: lw          $v0, 0x748($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X748);
    // 0x80003128: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8000312C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80003130: sb          $zero, 0x4($v0)
    MEM_B(0X4, ctx->r2) = 0;
    // 0x80003134: slti        $v0, $a0, 0x4
    ctx->r2 = SIGNED(ctx->r4) < 0X4 ? 1 : 0;
    // 0x80003138: bne         $v0, $zero, L_80003124
    if (ctx->r2 != 0) {
        // 0x8000313C: addiu       $v1, $v1, 0x6
        ctx->r3 = ADD32(ctx->r3, 0X6);
            goto L_80003124;
    }
    // 0x8000313C: addiu       $v1, $v1, 0x6
    ctx->r3 = ADD32(ctx->r3, 0X6);
    // 0x80003140: jr          $ra
    // 0x80003144: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80003144: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80003148:
    // 0x80003148: jr          $ra
    // 0x8000314C: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    return;
    // 0x8000314C: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
;}
RECOMP_FUNC void func_80003150(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80003150: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x80003154: sltiu       $v0, $a0, 0x4
    ctx->r2 = ctx->r4 < 0X4 ? 1 : 0;
    // 0x80003158: beq         $v0, $zero, L_80003180
    if (ctx->r2 == 0) {
        // 0x8000315C: lui         $v1, 0x8011
        ctx->r3 = S32(0X8011 << 16);
            goto L_80003180;
    }
    // 0x8000315C: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x80003160: addiu       $v1, $v1, 0x520
    ctx->r3 = ADD32(ctx->r3, 0X520);
    // 0x80003164: sll         $v0, $a0, 4
    ctx->r2 = S32(ctx->r4 << 4);
    // 0x80003168: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x8000316C: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x80003170: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80003174: lbu         $v0, 0x6B($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X6B);
    // 0x80003178: jr          $ra
    // 0x8000317C: nop

    return;
    // 0x8000317C: nop

L_80003180:
    // 0x80003180: jr          $ra
    // 0x80003184: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    return;
    // 0x80003184: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
;}
RECOMP_FUNC void func_80003188(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80003188: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x8000318C: sltiu       $v0, $a0, 0x4
    ctx->r2 = ctx->r4 < 0X4 ? 1 : 0;
    // 0x80003190: bne         $v0, $zero, L_800031A0
    if (ctx->r2 != 0) {
        // 0x80003194: lui         $v0, 0x8011
        ctx->r2 = S32(0X8011 << 16);
            goto L_800031A0;
    }
    // 0x80003194: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80003198: jr          $ra
    // 0x8000319C: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    return;
    // 0x8000319C: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_800031A0:
    // 0x800031A0: addiu       $v0, $v0, 0x520
    ctx->r2 = ADD32(ctx->r2, 0X520);
    // 0x800031A4: sll         $v1, $a0, 4
    ctx->r3 = S32(ctx->r4 << 4);
    // 0x800031A8: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x800031AC: sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3 << 3);
    // 0x800031B0: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800031B4: lbu         $v0, 0x69($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X69);
    // 0x800031B8: beq         $v0, $zero, L_800031C8
    if (ctx->r2 == 0) {
        // 0x800031BC: nop
    
            goto L_800031C8;
    }
    // 0x800031BC: nop

    // 0x800031C0: sb          $zero, 0x69($v1)
    MEM_B(0X69, ctx->r3) = 0;
    // 0x800031C4: sb          $zero, 0x68($v1)
    MEM_B(0X68, ctx->r3) = 0;
L_800031C8:
    // 0x800031C8: jr          $ra
    // 0x800031CC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x800031CC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
;}
RECOMP_FUNC void func_800031D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800031D0: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800031D4: lbu         $v0, 0x740($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X740);
    // 0x800031D8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800031DC: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x800031E0: addu        $s2, $a0, $zero
    ctx->r18 = ADD32(ctx->r4, 0);
    // 0x800031E4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800031E8: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x800031EC: bne         $v0, $zero, L_8000322C
    if (ctx->r2 != 0) {
        // 0x800031F0: sw          $s0, 0x10($sp)
        MEM_W(0X10, ctx->r29) = ctx->r16;
            goto L_8000322C;
    }
    // 0x800031F0: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x800031F4: andi        $v0, $s2, 0xFF
    ctx->r2 = ctx->r18 & 0XFF;
    // 0x800031F8: beq         $v0, $zero, L_8000322C
    if (ctx->r2 == 0) {
        // 0x800031FC: addu        $s1, $zero, $zero
        ctx->r17 = ADD32(0, 0);
            goto L_8000322C;
    }
    // 0x800031FC: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // 0x80003200: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80003204: addiu       $s0, $v0, 0x520
    ctx->r16 = ADD32(ctx->r2, 0X520);
L_80003208:
    // 0x80003208: lbu         $v0, 0x6B($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X6B);
    // 0x8000320C: beq         $v0, $zero, L_80003220
    if (ctx->r2 == 0) {
        // 0x80003210: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_80003220;
    }
    // 0x80003210: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80003214: lw          $a0, 0x84($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X84);
    // 0x80003218: jal         0x80002BA8
    // 0x8000321C: nop

    func_80002BA8(rdram, ctx);
        goto after_0;
    // 0x8000321C: nop

    after_0:
L_80003220:
    // 0x80003220: slti        $v0, $s1, 0x4
    ctx->r2 = SIGNED(ctx->r17) < 0X4 ? 1 : 0;
    // 0x80003224: bne         $v0, $zero, L_80003208
    if (ctx->r2 != 0) {
        // 0x80003228: addiu       $s0, $s0, 0x88
        ctx->r16 = ADD32(ctx->r16, 0X88);
            goto L_80003208;
    }
    // 0x80003228: addiu       $s0, $s0, 0x88
    ctx->r16 = ADD32(ctx->r16, 0X88);
L_8000322C:
    // 0x8000322C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80003230: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80003234: sb          $s2, 0x740($v0)
    MEM_B(0X740, ctx->r2) = ctx->r18;
    // 0x80003238: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x8000323C: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x80003240: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80003244: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80003248: jr          $ra
    // 0x8000324C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8000324C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_80003250(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80003250: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80003254: lbu         $v0, 0x742($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X742);
    // 0x80003258: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8000325C: bne         $v0, $zero, L_80003278
    if (ctx->r2 != 0) {
        // 0x80003260: sw          $ra, 0x10($sp)
        MEM_W(0X10, ctx->r29) = ctx->r31;
            goto L_80003278;
    }
    // 0x80003260: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80003264: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80003268: addiu       $a0, $a0, -0xB0
    ctx->r4 = ADD32(ctx->r4, -0XB0);
    // 0x8000326C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80003270: jal         0x80033410
    // 0x80003274: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    osSendMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x80003274: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    after_0:
L_80003278:
    // 0x80003278: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x8000327C: jr          $ra
    // 0x80003280: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80003280: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80003284(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80003284: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x80003288: lbu         $v0, 0x741($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X741);
    // 0x8000328C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80003290: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80003294: beq         $v0, $zero, L_800032B4
    if (ctx->r2 == 0) {
        // 0x80003298: sw          $s0, 0x10($sp)
        MEM_W(0X10, ctx->r29) = ctx->r16;
            goto L_800032B4;
    }
    // 0x80003298: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8000329C: addu        $s0, $v1, $zero
    ctx->r16 = ADD32(ctx->r3, 0);
L_800032A0:
    // 0x800032A0: jal         0x80037510
    // 0x800032A4: nop

    osYieldThread_recomp(rdram, ctx);
        goto after_0;
    // 0x800032A4: nop

    after_0:
    // 0x800032A8: lbu         $v0, 0x741($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X741);
    // 0x800032AC: bne         $v0, $zero, L_800032A0
    if (ctx->r2 != 0) {
        // 0x800032B0: nop
    
            goto L_800032A0;
    }
    // 0x800032B0: nop

L_800032B4:
    // 0x800032B4: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800032B8: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x800032BC: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x800032C0: addiu       $a0, $a0, -0x90
    ctx->r4 = ADD32(ctx->r4, -0X90);
    // 0x800032C4: sb          $v1, 0x742($v0)
    MEM_B(0X742, ctx->r2) = ctx->r3;
    // 0x800032C8: jal         0x80034630
    // 0x800032CC: nop

    osStopThread_recomp(rdram, ctx);
        goto after_1;
    // 0x800032CC: nop

    after_1:
    // 0x800032D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800032D4: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x800032D8: jr          $ra
    // 0x800032DC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800032DC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_800032E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800032E0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800032E4: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800032E8: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x800032EC: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x800032F0: sb          $zero, 0x742($v0)
    MEM_B(0X742, ctx->r2) = 0;
    // 0x800032F4: jal         0x800344E0
    // 0x800032F8: addiu       $a0, $a0, -0x90
    ctx->r4 = ADD32(ctx->r4, -0X90);
    osStartThread_recomp(rdram, ctx);
        goto after_0;
    // 0x800032F8: addiu       $a0, $a0, -0x90
    ctx->r4 = ADD32(ctx->r4, -0X90);
    after_0:
    // 0x800032FC: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80003300: jr          $ra
    // 0x80003304: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80003304: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80003308(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80003308: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8000330C: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80003310: lui         $s0, 0x8011
    ctx->r16 = S32(0X8011 << 16);
    // 0x80003314: addiu       $s0, $s0, 0x750
    ctx->r16 = ADD32(ctx->r16, 0X750);
    // 0x80003318: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x8000331C: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x80003320: addiu       $a1, $a1, 0x768
    ctx->r5 = ADD32(ctx->r5, 0X768);
    // 0x80003324: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80003328: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x8000332C: sb          $zero, 0x742($v0)
    MEM_B(0X742, ctx->r2) = 0;
    // 0x80003330: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80003334: sw          $zero, 0x748($v0)
    MEM_W(0X748, ctx->r2) = 0;
    // 0x80003338: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x8000333C: sw          $zero, 0x744($v0)
    MEM_W(0X744, ctx->r2) = 0;
    // 0x80003340: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80003344: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80003348: sb          $zero, 0x740($v0)
    MEM_B(0X740, ctx->r2) = 0;
    // 0x8000334C: jal         0x8002B300
    // 0x80003350: nop

    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_0;
    // 0x80003350: nop

    after_0:
    // 0x80003354: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80003358: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x8000335C: jal         0x80033410
    // 0x80003360: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    osSendMesg_recomp(rdram, ctx);
        goto after_1;
    // 0x80003360: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    after_1:
    // 0x80003364: jal         0x80002F4C
    // 0x80003368: nop

    func_80002F4C(rdram, ctx);
        goto after_2;
    // 0x80003368: nop

    after_2:
    // 0x8000336C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80003370: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80003374: jr          $ra
    // 0x80003378: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80003378: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void fake_func_8000337C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
;}
RECOMP_FUNC void func_80003380(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80003380: lui         $v1, 0x8003
    ctx->r3 = S32(0X8003 << 16);
    // 0x80003384: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80003388: jr          $ra
    // 0x8000338C: sw          $v0, 0x7630($v1)
    MEM_W(0X7630, ctx->r3) = ctx->r2;
    return;
    // 0x8000338C: sw          $v0, 0x7630($v1)
    MEM_W(0X7630, ctx->r3) = ctx->r2;
;}
