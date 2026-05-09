#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void func_80003390(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80003390: lui         $v0, 0x8003
    ctx->r2 = S32(0X8003 << 16);
    // 0x80003394: sw          $zero, 0x7630($v0)
    MEM_W(0X7630, ctx->r2) = 0;
    // 0x80003398: jr          $ra
    // 0x8000339C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x8000339C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
;}
RECOMP_FUNC void func_800033A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800033A0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800033A4: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x800033A8: addu        $s2, $a0, $zero
    ctx->r18 = ADD32(ctx->r4, 0);
    // 0x800033AC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800033B0: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x800033B4: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x800033B8: lw          $v0, 0x60($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X60);
    // 0x800033BC: blez        $v0, L_800033F0
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800033C0: addu        $s1, $zero, $zero
        ctx->r17 = ADD32(0, 0);
            goto L_800033F0;
    }
    // 0x800033C0: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // 0x800033C4: addu        $s0, $s2, $zero
    ctx->r16 = ADD32(ctx->r18, 0);
L_800033C8:
    // 0x800033C8: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x800033CC: lw          $a1, 0x20($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X20);
    // 0x800033D0: lw          $a2, 0x40($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X40);
    // 0x800033D4: jal         0x80005200
    // 0x800033D8: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    func_80005200(rdram, ctx);
        goto after_0;
    // 0x800033D8: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    after_0:
    // 0x800033DC: lw          $v0, 0x60($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X60);
    // 0x800033E0: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800033E4: slt         $v0, $s1, $v0
    ctx->r2 = SIGNED(ctx->r17) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800033E8: bne         $v0, $zero, L_800033C8
    if (ctx->r2 != 0) {
        // 0x800033EC: nop
    
            goto L_800033C8;
    }
    // 0x800033EC: nop

L_800033F0:
    // 0x800033F0: lw          $a0, 0x64($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X64);
    // 0x800033F4: beq         $a0, $zero, L_80003408
    if (ctx->r4 == 0) {
        // 0x800033F8: nop
    
            goto L_80003408;
    }
    // 0x800033F8: nop

    // 0x800033FC: lw          $a2, 0x68($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X68);
    // 0x80003400: jal         0x800078E0
    // 0x80003404: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    rs_memset(rdram, ctx);
        goto after_1;
    // 0x80003404: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_1:
L_80003408:
    // 0x80003408: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8000340C: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x80003410: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x80003414: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80003418: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8000341C: jr          $ra
    // 0x80003420: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80003420: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void fake_func_80003424(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
;}
RECOMP_FUNC void rand_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80003430: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x80003434: lw          $v0, 0x3470($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X3470);
    // 0x80003438: lui         $v1, 0xA835
    ctx->r3 = S32(0XA835 << 16);
    // 0x8000343C: ori         $v1, $v1, 0x1D63
    ctx->r3 = ctx->r3 | 0X1D63;
    // 0x80003440: mult        $v0, $v1
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80003444: mflo        $v0
    ctx->r2 = lo;
    // 0x80003448: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8000344C: sw          $v0, 0x3470($at)
    MEM_W(0X3470, ctx->r1) = ctx->r2;
    // 0x80003450: srl         $v0, $v0, 6
    ctx->r2 = S32(U32(ctx->r2) >> 6);
    // 0x80003454: andi        $v0, $v0, 0x7FFF
    ctx->r2 = ctx->r2 & 0X7FFF;
    // 0x80003458: jr          $ra
    // 0x8000345C: nop

    return;
    // 0x8000345C: nop

;}
RECOMP_FUNC void setRngSeed(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80003460: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80003464: sw          $a0, 0x3470($at)
    MEM_W(0X3470, ctx->r1) = ctx->r4;
    // 0x80003468: jr          $ra
    // 0x8000346C: nop

    return;
    // 0x8000346C: nop

;}
RECOMP_FUNC void func_80003480(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80003480: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80003484: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x80003488: addu        $s5, $a0, $zero
    ctx->r21 = ADD32(ctx->r4, 0);
    // 0x8000348C: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x80003490: addu        $s4, $a1, $zero
    ctx->r20 = ADD32(ctx->r5, 0);
    // 0x80003494: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80003498: addu        $s0, $a2, $zero
    ctx->r16 = ADD32(ctx->r6, 0);
    // 0x8000349C: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x800034A0: addiu       $a0, $a0, 0x990
    ctx->r4 = ADD32(ctx->r4, 0X990);
    // 0x800034A4: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x800034A8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800034AC: sw          $ra, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r31;
    // 0x800034B0: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x800034B4: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x800034B8: jal         0x800331D0
    // 0x800034BC: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    osRecvMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x800034BC: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    after_0:
    // 0x800034C0: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x800034C4: lw          $s2, 0x9A8($a0)
    ctx->r18 = MEM_W(ctx->r4, 0X9A8);
    // 0x800034C8: addiu       $v1, $s2, 0x1
    ctx->r3 = ADD32(ctx->r18, 0X1);
    // 0x800034CC: bgez        $v1, L_800034D8
    if (SIGNED(ctx->r3) >= 0) {
        // 0x800034D0: addu        $v0, $v1, $zero
        ctx->r2 = ADD32(ctx->r3, 0);
            goto L_800034D8;
    }
    // 0x800034D0: addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
    // 0x800034D4: addiu       $v0, $s2, 0x8
    ctx->r2 = ADD32(ctx->r18, 0X8);
L_800034D8:
    // 0x800034D8: sra         $v0, $v0, 3
    ctx->r2 = S32(SIGNED(ctx->r2) >> 3);
    // 0x800034DC: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x800034E0: subu        $v0, $v1, $v0
    ctx->r2 = SUB32(ctx->r3, ctx->r2);
    // 0x800034E4: sw          $v0, 0x9A8($a0)
    MEM_W(0X9A8, ctx->r4) = ctx->r2;
    // 0x800034E8: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800034EC: addiu       $v0, $v0, 0x9B0
    ctx->r2 = ADD32(ctx->r2, 0X9B0);
    // 0x800034F0: sll         $a0, $s2, 2
    ctx->r4 = S32(ctx->r18 << 2);
    // 0x800034F4: addu        $v0, $a0, $v0
    ctx->r2 = ADD32(ctx->r4, ctx->r2);
    // 0x800034F8: sw          $s4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r20;
    // 0x800034FC: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80003500: addiu       $v0, $v0, 0x9D0
    ctx->r2 = ADD32(ctx->r2, 0X9D0);
    // 0x80003504: addu        $v0, $a0, $v0
    ctx->r2 = ADD32(ctx->r4, ctx->r2);
    // 0x80003508: sw          $s0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r16;
    // 0x8000350C: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80003510: addiu       $v0, $v0, 0x9F0
    ctx->r2 = ADD32(ctx->r2, 0X9F0);
    // 0x80003514: addu        $v0, $a0, $v0
    ctx->r2 = ADD32(ctx->r4, ctx->r2);
    // 0x80003518: sw          $s5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r21;
    // 0x8000351C: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80003520: addiu       $v0, $v0, 0xA30
    ctx->r2 = ADD32(ctx->r2, 0XA30);
    // 0x80003524: addu        $v0, $a0, $v0
    ctx->r2 = ADD32(ctx->r4, ctx->r2);
    // 0x80003528: sw          $s0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r16;
    // 0x8000352C: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80003530: addiu       $v0, $v0, 0xA10
    ctx->r2 = ADD32(ctx->r2, 0XA10);
    // 0x80003534: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x80003538: lw          $v1, 0x1254($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X1254);
    // 0x8000353C: addu        $v0, $a0, $v0
    ctx->r2 = ADD32(ctx->r4, ctx->r2);
    // 0x80003540: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x80003544: addu        $s1, $v1, $zero
    ctx->r17 = ADD32(ctx->r3, 0);
    // 0x80003548: sltu        $v0, $s1, $s0
    ctx->r2 = ctx->r17 < ctx->r16 ? 1 : 0;
    // 0x8000354C: beql        $v0, $zero, L_80003554
    if (ctx->r2 == 0) {
        // 0x80003550: addu        $s1, $s0, $zero
        ctx->r17 = ADD32(ctx->r16, 0);
            goto L_80003554;
    }
    goto skip_0;
    // 0x80003550: addu        $s1, $s0, $zero
    ctx->r17 = ADD32(ctx->r16, 0);
    skip_0:
L_80003554:
    // 0x80003554: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80003558: addiu       $v0, $v0, 0xA50
    ctx->r2 = ADD32(ctx->r2, 0XA50);
    // 0x8000355C: addu        $v0, $a0, $v0
    ctx->r2 = ADD32(ctx->r4, ctx->r2);
    // 0x80003560: sw          $s1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r17;
    // 0x80003564: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
    // 0x80003568: lui         $s0, 0x8011
    ctx->r16 = S32(0X8011 << 16);
L_8000356C:
    // 0x8000356C: jal         0x800058C0
    // 0x80003570: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    func_800058C0(rdram, ctx);
        goto after_1;
    // 0x80003570: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_1:
    // 0x80003574: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x80003578: bne         $v0, $s3, L_80003594
    if (ctx->r2 != ctx->r19) {
        // 0x8000357C: addu        $a0, $s4, $zero
        ctx->r4 = ADD32(ctx->r20, 0);
            goto L_80003594;
    }
    // 0x8000357C: addu        $a0, $s4, $zero
    ctx->r4 = ADD32(ctx->r20, 0);
    // 0x80003580: lw          $a0, 0xD54($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XD54);
    // 0x80003584: jal         0x800072AC
    // 0x80003588: nop

    func_800072AC(rdram, ctx);
        goto after_2;
    // 0x80003588: nop

    after_2:
    // 0x8000358C: j           L_8000356C
    // 0x80003590: nop

        goto L_8000356C;
    // 0x80003590: nop

L_80003594:
    // 0x80003594: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x80003598: lui         $s0, 0x8011
    ctx->r16 = S32(0X8011 << 16);
    // 0x8000359C: sb          $zero, 0xA70($s0)
    MEM_B(0XA70, ctx->r16) = 0;
    // 0x800035A0: jal         0x800358B0
    // 0x800035A4: nop

    osWritebackDCache_recomp(rdram, ctx);
        goto after_3;
    // 0x800035A4: nop

    after_3:
    // 0x800035A8: sll         $v1, $s2, 1
    ctx->r3 = S32(ctx->r18 << 1);
    // 0x800035AC: addu        $v1, $v1, $s2
    ctx->r3 = ADD32(ctx->r3, ctx->r18);
    // 0x800035B0: sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3 << 3);
    // 0x800035B4: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x800035B8: addiu       $a0, $a0, 0x7E0
    ctx->r4 = ADD32(ctx->r4, 0X7E0);
    // 0x800035BC: addu        $a0, $v1, $a0
    ctx->r4 = ADD32(ctx->r3, ctx->r4);
    // 0x800035C0: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x800035C4: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    // 0x800035C8: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800035CC: addiu       $v0, $v0, 0x8C0
    ctx->r2 = ADD32(ctx->r2, 0X8C0);
    // 0x800035D0: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800035D4: addu        $a3, $s5, $zero
    ctx->r7 = ADD32(ctx->r21, 0);
    // 0x800035D8: sw          $s4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r20;
    // 0x800035DC: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x800035E0: jal         0x80032420
    // 0x800035E4: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    osPiStartDma_recomp(rdram, ctx);
        goto after_4;
    // 0x800035E4: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    after_4:
    // 0x800035E8: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x800035EC: addiu       $a0, $a0, 0x990
    ctx->r4 = ADD32(ctx->r4, 0X990);
    // 0x800035F0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x800035F4: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x800035F8: lw          $v0, 0x9AC($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X9AC);
    // 0x800035FC: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    // 0x80003600: sb          $s3, 0xA70($s0)
    MEM_B(0XA70, ctx->r16) = ctx->r19;
    // 0x80003604: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x80003608: jal         0x80033410
    // 0x8000360C: sw          $v0, 0x9AC($v1)
    MEM_W(0X9AC, ctx->r3) = ctx->r2;
    osSendMesg_recomp(rdram, ctx);
        goto after_5;
    // 0x8000360C: sw          $v0, 0x9AC($v1)
    MEM_W(0X9AC, ctx->r3) = ctx->r2;
    after_5:
    // 0x80003610: addu        $v0, $s2, $zero
    ctx->r2 = ADD32(ctx->r18, 0);
    // 0x80003614: lw          $ra, 0x38($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X38);
    // 0x80003618: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x8000361C: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x80003620: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x80003624: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x80003628: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x8000362C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80003630: jr          $ra
    // 0x80003634: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x80003634: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_80003638(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80003638: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x8000363C: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80003640: addiu       $v0, $v0, 0x9B0
    ctx->r2 = ADD32(ctx->r2, 0X9B0);
    // 0x80003644: sw          $fp, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r30;
    // 0x80003648: sll         $fp, $a0, 2
    ctx->r30 = S32(ctx->r4 << 2);
    // 0x8000364C: addu        $v0, $fp, $v0
    ctx->r2 = ADD32(ctx->r30, ctx->r2);
    // 0x80003650: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x80003654: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80003658: addiu       $v0, $v0, 0xA10
    ctx->r2 = ADD32(ctx->r2, 0XA10);
    // 0x8000365C: sw          $s5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r21;
    // 0x80003660: addu        $s5, $fp, $v0
    ctx->r21 = ADD32(ctx->r30, ctx->r2);
    // 0x80003664: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80003668: addiu       $v0, $v0, 0xA50
    ctx->r2 = ADD32(ctx->r2, 0XA50);
    // 0x8000366C: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x80003670: addu        $s4, $fp, $v0
    ctx->r20 = ADD32(ctx->r30, ctx->r2);
    // 0x80003674: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80003678: addiu       $v0, $v0, 0xA30
    ctx->r2 = ADD32(ctx->r2, 0XA30);
    // 0x8000367C: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x80003680: addu        $s3, $fp, $v0
    ctx->r19 = ADD32(ctx->r30, ctx->r2);
    // 0x80003684: sll         $v0, $a0, 1
    ctx->r2 = S32(ctx->r4 << 1);
    // 0x80003688: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x8000368C: sw          $s7, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r23;
    // 0x80003690: sll         $s7, $v0, 3
    ctx->r23 = S32(ctx->r2 << 3);
    // 0x80003694: lui         $t0, 0x8011
    ctx->r8 = S32(0X8011 << 16);
    // 0x80003698: addiu       $t0, $t0, 0x8C0
    ctx->r8 = ADD32(ctx->r8, 0X8C0);
    // 0x8000369C: addu        $t0, $s7, $t0
    ctx->r8 = ADD32(ctx->r23, ctx->r8);
    // 0x800036A0: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x800036A4: sw          $s6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r22;
    // 0x800036A8: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x800036AC: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x800036B0: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x800036B4: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    // 0x800036B8: lui         $t0, 0x8011
    ctx->r8 = S32(0X8011 << 16);
L_800036BC:
    // 0x800036BC: addiu       $t0, $t0, 0x8C0
    ctx->r8 = ADD32(ctx->r8, 0X8C0);
    // 0x800036C0: addu        $a0, $s7, $t0
    ctx->r4 = ADD32(ctx->r23, ctx->r8);
    // 0x800036C4: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x800036C8: jal         0x800331D0
    // 0x800036CC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x800036CC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x800036D0: jal         0x80037510
    // 0x800036D4: nop

    osYieldThread_recomp(rdram, ctx);
        goto after_1;
    // 0x800036D4: nop

    after_1:
    // 0x800036D8: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x800036DC: lw          $a0, 0x0($s5)
    ctx->r4 = MEM_W(ctx->r21, 0X0);
    // 0x800036E0: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x800036E4: lw          $a1, 0x0($s4)
    ctx->r5 = MEM_W(ctx->r20, 0X0);
    // 0x800036E8: jal         0x8002C280
    // 0x800036EC: addu        $a0, $v0, $a0
    ctx->r4 = ADD32(ctx->r2, ctx->r4);
    osInvalDCache_recomp(rdram, ctx);
        goto after_2;
    // 0x800036EC: addu        $a0, $v0, $a0
    ctx->r4 = ADD32(ctx->r2, ctx->r4);
    after_2:
    // 0x800036F0: lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X0);
    // 0x800036F4: lw          $v1, 0x0($s4)
    ctx->r3 = MEM_W(ctx->r20, 0X0);
    // 0x800036F8: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x800036FC: sw          $v0, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r2;
    // 0x80003700: lw          $v0, 0x0($s5)
    ctx->r2 = MEM_W(ctx->r21, 0X0);
    // 0x80003704: lw          $v1, 0x0($s4)
    ctx->r3 = MEM_W(ctx->r20, 0X0);
    // 0x80003708: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8000370C: sw          $v0, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->r2;
    // 0x80003710: lw          $v1, 0x0($s3)
    ctx->r3 = MEM_W(ctx->r19, 0X0);
    // 0x80003714: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80003718: sb          $zero, 0xA70($v0)
    MEM_B(0XA70, ctx->r2) = 0;
    // 0x8000371C: beq         $v1, $zero, L_800037DC
    if (ctx->r3 == 0) {
        // 0x80003720: lui         $v0, 0x8011
        ctx->r2 = S32(0X8011 << 16);
            goto L_800037DC;
    }
    // 0x80003720: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80003724: lw          $v0, 0x1254($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X1254);
    // 0x80003728: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // 0x8000372C: sltu        $v0, $s0, $v1
    ctx->r2 = ctx->r16 < ctx->r3 ? 1 : 0;
    // 0x80003730: beql        $v0, $zero, L_80003738
    if (ctx->r2 == 0) {
        // 0x80003734: addu        $s0, $v1, $zero
        ctx->r16 = ADD32(ctx->r3, 0);
            goto L_80003738;
    }
    goto skip_0;
    // 0x80003734: addu        $s0, $v1, $zero
    ctx->r16 = ADD32(ctx->r3, 0);
    skip_0:
L_80003738:
    // 0x80003738: lui         $s6, 0x8011
    ctx->r22 = S32(0X8011 << 16);
    // 0x8000373C: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80003740: addiu       $v0, $v0, 0x9F0
    ctx->r2 = ADD32(ctx->r2, 0X9F0);
    // 0x80003744: addu        $v0, $fp, $v0
    ctx->r2 = ADD32(ctx->r30, ctx->r2);
    // 0x80003748: sw          $s0, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r16;
    // 0x8000374C: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x80003750: lw          $v1, 0x0($s5)
    ctx->r3 = MEM_W(ctx->r21, 0X0);
    // 0x80003754: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x80003758: lw          $a0, 0x0($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X0);
    // 0x8000375C: addu        $s2, $v0, $v1
    ctx->r18 = ADD32(ctx->r2, ctx->r3);
    // 0x80003760: addu        $s1, $a0, $v1
    ctx->r17 = ADD32(ctx->r4, ctx->r3);
L_80003764:
    // 0x80003764: jal         0x800058C0
    // 0x80003768: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    func_800058C0(rdram, ctx);
        goto after_3;
    // 0x80003768: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_3:
    // 0x8000376C: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x80003770: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80003774: bne         $v0, $t0, L_80003790
    if (ctx->r2 != ctx->r8) {
        // 0x80003778: addu        $a0, $s1, $zero
        ctx->r4 = ADD32(ctx->r17, 0);
            goto L_80003790;
    }
    // 0x80003778: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x8000377C: lw          $a0, 0xD54($s6)
    ctx->r4 = MEM_W(ctx->r22, 0XD54);
    // 0x80003780: jal         0x800072AC
    // 0x80003784: nop

    func_800072AC(rdram, ctx);
        goto after_4;
    // 0x80003784: nop

    after_4:
    // 0x80003788: j           L_80003764
    // 0x8000378C: nop

        goto L_80003764;
    // 0x8000378C: nop

L_80003790:
    // 0x80003790: jal         0x800358B0
    // 0x80003794: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    osWritebackDCache_recomp(rdram, ctx);
        goto after_5;
    // 0x80003794: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_5:
    // 0x80003798: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x8000379C: addiu       $a0, $a0, 0x7E0
    ctx->r4 = ADD32(ctx->r4, 0X7E0);
    // 0x800037A0: addu        $a0, $s7, $a0
    ctx->r4 = ADD32(ctx->r23, ctx->r4);
    // 0x800037A4: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x800037A8: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    // 0x800037AC: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x800037B0: addu        $a3, $s2, $zero
    ctx->r7 = ADD32(ctx->r18, 0);
    // 0x800037B4: sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    // 0x800037B8: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800037BC: jal         0x80032420
    // 0x800037C0: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    osPiStartDma_recomp(rdram, ctx);
        goto after_6;
    // 0x800037C0: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    after_6:
    // 0x800037C4: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800037C8: lw          $v1, 0x0($s3)
    ctx->r3 = MEM_W(ctx->r19, 0X0);
    // 0x800037CC: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x800037D0: sb          $t0, 0xA70($v0)
    MEM_B(0XA70, ctx->r2) = ctx->r8;
    // 0x800037D4: bne         $v1, $zero, L_800036BC
    if (ctx->r3 != 0) {
        // 0x800037D8: lui         $t0, 0x8011
        ctx->r8 = S32(0X8011 << 16);
            goto L_800036BC;
    }
    // 0x800037D8: lui         $t0, 0x8011
    ctx->r8 = S32(0X8011 << 16);
L_800037DC:
    // 0x800037DC: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x800037E0: lw          $v0, 0x9AC($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X9AC);
    // 0x800037E4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800037E8: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x800037EC: jal         0x800058C0
    // 0x800037F0: sw          $v0, 0x9AC($v1)
    MEM_W(0X9AC, ctx->r3) = ctx->r2;
    func_800058C0(rdram, ctx);
        goto after_7;
    // 0x800037F0: sw          $v0, 0x9AC($v1)
    MEM_W(0X9AC, ctx->r3) = ctx->r2;
    after_7:
    // 0x800037F4: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x800037F8: lw          $fp, 0x48($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X48);
    // 0x800037FC: lw          $s7, 0x44($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X44);
    // 0x80003800: lw          $s6, 0x40($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X40);
    // 0x80003804: lw          $s5, 0x3C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X3C);
    // 0x80003808: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x8000380C: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x80003810: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x80003814: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x80003818: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x8000381C: jr          $ra
    // 0x80003820: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x80003820: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void func_80003824(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80003824: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80003828: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x8000382C: addu        $s6, $a0, $zero
    ctx->r22 = ADD32(ctx->r4, 0);
    // 0x80003830: sll         $v0, $s6, 1
    ctx->r2 = S32(ctx->r22 << 1);
    // 0x80003834: addu        $v0, $v0, $s6
    ctx->r2 = ADD32(ctx->r2, ctx->r22);
    // 0x80003838: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x8000383C: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80003840: addiu       $a0, $a0, 0x8C0
    ctx->r4 = ADD32(ctx->r4, 0X8C0);
    // 0x80003844: addu        $a0, $v0, $a0
    ctx->r4 = ADD32(ctx->r2, ctx->r4);
    // 0x80003848: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x8000384C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80003850: sw          $ra, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r31;
    // 0x80003854: sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // 0x80003858: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x8000385C: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x80003860: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x80003864: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x80003868: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x8000386C: jal         0x800331D0
    // 0x80003870: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    osRecvMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x80003870: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    after_0:
    // 0x80003874: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // 0x80003878: beq         $v0, $v1, L_800039E0
    if (ctx->r2 == ctx->r3) {
        // 0x8000387C: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_800039E0;
    }
    // 0x8000387C: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x80003880: jal         0x80037510
    // 0x80003884: sll         $s2, $s6, 2
    ctx->r18 = S32(ctx->r22 << 2);
    osYieldThread_recomp(rdram, ctx);
        goto after_1;
    // 0x80003884: sll         $s2, $s6, 2
    ctx->r18 = S32(ctx->r22 << 2);
    after_1:
    // 0x80003888: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x8000388C: addiu       $v0, $v0, 0x9B0
    ctx->r2 = ADD32(ctx->r2, 0X9B0);
    // 0x80003890: addu        $s7, $s2, $v0
    ctx->r23 = ADD32(ctx->r18, ctx->r2);
    // 0x80003894: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80003898: addiu       $v0, $v0, 0xA10
    ctx->r2 = ADD32(ctx->r2, 0XA10);
    // 0x8000389C: addu        $s3, $s2, $v0
    ctx->r19 = ADD32(ctx->r18, ctx->r2);
    // 0x800038A0: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800038A4: addiu       $v0, $v0, 0xA50
    ctx->r2 = ADD32(ctx->r2, 0XA50);
    // 0x800038A8: addu        $s1, $s2, $v0
    ctx->r17 = ADD32(ctx->r18, ctx->r2);
    // 0x800038AC: lw          $v0, 0x0($s7)
    ctx->r2 = MEM_W(ctx->r23, 0X0);
    // 0x800038B0: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    // 0x800038B4: lw          $a1, 0x0($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X0);
    // 0x800038B8: jal         0x8002C280
    // 0x800038BC: addu        $a0, $v0, $a0
    ctx->r4 = ADD32(ctx->r2, ctx->r4);
    osInvalDCache_recomp(rdram, ctx);
        goto after_2;
    // 0x800038BC: addu        $a0, $v0, $a0
    ctx->r4 = ADD32(ctx->r2, ctx->r4);
    after_2:
    // 0x800038C0: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x800038C4: addiu       $v1, $v1, 0xA30
    ctx->r3 = ADD32(ctx->r3, 0XA30);
    // 0x800038C8: addu        $v1, $s2, $v1
    ctx->r3 = ADD32(ctx->r18, ctx->r3);
    // 0x800038CC: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800038D0: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x800038D4: subu        $v0, $v0, $a0
    ctx->r2 = SUB32(ctx->r2, ctx->r4);
    // 0x800038D8: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x800038DC: lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X0);
    // 0x800038E0: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x800038E4: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x800038E8: sw          $v0, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r2;
    // 0x800038EC: lw          $v1, 0x0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X0);
    // 0x800038F0: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800038F4: sb          $zero, 0xA70($v0)
    MEM_B(0XA70, ctx->r2) = 0;
    // 0x800038F8: beql        $v1, $zero, L_800039C8
    if (ctx->r3 == 0) {
        // 0x800038FC: lui         $v1, 0x8011
        ctx->r3 = S32(0X8011 << 16);
            goto L_800039C8;
    }
    goto skip_0;
    // 0x800038FC: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    skip_0:
    // 0x80003900: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80003904: lw          $v0, 0x1254($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X1254);
    // 0x80003908: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // 0x8000390C: sltu        $v0, $s0, $v1
    ctx->r2 = ctx->r16 < ctx->r3 ? 1 : 0;
    // 0x80003910: beql        $v0, $zero, L_80003918
    if (ctx->r2 == 0) {
        // 0x80003914: addu        $s0, $v1, $zero
        ctx->r16 = ADD32(ctx->r3, 0);
            goto L_80003918;
    }
    goto skip_1;
    // 0x80003914: addu        $s0, $v1, $zero
    ctx->r16 = ADD32(ctx->r3, 0);
    skip_1:
L_80003918:
    // 0x80003918: addiu       $s4, $zero, 0x1
    ctx->r20 = ADD32(0, 0X1);
    // 0x8000391C: lui         $s5, 0x8011
    ctx->r21 = S32(0X8011 << 16);
    // 0x80003920: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80003924: addiu       $v0, $v0, 0x9F0
    ctx->r2 = ADD32(ctx->r2, 0X9F0);
    // 0x80003928: addu        $v0, $s2, $v0
    ctx->r2 = ADD32(ctx->r18, ctx->r2);
    // 0x8000392C: sw          $s0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r16;
    // 0x80003930: lw          $a0, 0x0($s7)
    ctx->r4 = MEM_W(ctx->r23, 0X0);
    // 0x80003934: lw          $v1, 0x0($s3)
    ctx->r3 = MEM_W(ctx->r19, 0X0);
    // 0x80003938: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x8000393C: addu        $s1, $a0, $v1
    ctx->r17 = ADD32(ctx->r4, ctx->r3);
    // 0x80003940: addu        $s2, $v0, $v1
    ctx->r18 = ADD32(ctx->r2, ctx->r3);
L_80003944:
    // 0x80003944: jal         0x800058C0
    // 0x80003948: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    func_800058C0(rdram, ctx);
        goto after_3;
    // 0x80003948: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_3:
    // 0x8000394C: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x80003950: bne         $v0, $s4, L_8000396C
    if (ctx->r2 != ctx->r20) {
        // 0x80003954: addu        $a0, $s1, $zero
        ctx->r4 = ADD32(ctx->r17, 0);
            goto L_8000396C;
    }
    // 0x80003954: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x80003958: lw          $a0, 0xD54($s5)
    ctx->r4 = MEM_W(ctx->r21, 0XD54);
    // 0x8000395C: jal         0x800072AC
    // 0x80003960: nop

    func_800072AC(rdram, ctx);
        goto after_4;
    // 0x80003960: nop

    after_4:
    // 0x80003964: j           L_80003944
    // 0x80003968: nop

        goto L_80003944;
    // 0x80003968: nop

L_8000396C:
    // 0x8000396C: jal         0x800358B0
    // 0x80003970: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    osWritebackDCache_recomp(rdram, ctx);
        goto after_5;
    // 0x80003970: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_5:
    // 0x80003974: sll         $v1, $s6, 1
    ctx->r3 = S32(ctx->r22 << 1);
    // 0x80003978: addu        $v1, $v1, $s6
    ctx->r3 = ADD32(ctx->r3, ctx->r22);
    // 0x8000397C: sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3 << 3);
    // 0x80003980: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80003984: addiu       $a0, $a0, 0x7E0
    ctx->r4 = ADD32(ctx->r4, 0X7E0);
    // 0x80003988: addu        $a0, $v1, $a0
    ctx->r4 = ADD32(ctx->r3, ctx->r4);
    // 0x8000398C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80003990: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    // 0x80003994: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80003998: addiu       $v0, $v0, 0x8C0
    ctx->r2 = ADD32(ctx->r2, 0X8C0);
    // 0x8000399C: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800039A0: addu        $a3, $s2, $zero
    ctx->r7 = ADD32(ctx->r18, 0);
    // 0x800039A4: sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    // 0x800039A8: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800039AC: jal         0x80032420
    // 0x800039B0: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    osPiStartDma_recomp(rdram, ctx);
        goto after_6;
    // 0x800039B0: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    after_6:
    // 0x800039B4: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x800039B8: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x800039BC: sb          $s4, 0xA70($v1)
    MEM_B(0XA70, ctx->r3) = ctx->r20;
    // 0x800039C0: j           L_800039E0
    // 0x800039C4: nop

        goto L_800039E0;
    // 0x800039C4: nop

L_800039C8:
    // 0x800039C8: lw          $v0, 0x9AC($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X9AC);
    // 0x800039CC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800039D0: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x800039D4: jal         0x800058C0
    // 0x800039D8: sw          $v0, 0x9AC($v1)
    MEM_W(0X9AC, ctx->r3) = ctx->r2;
    func_800058C0(rdram, ctx);
        goto after_7;
    // 0x800039D8: sw          $v0, 0x9AC($v1)
    MEM_W(0X9AC, ctx->r3) = ctx->r2;
    after_7:
    // 0x800039DC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800039E0:
    // 0x800039E0: lw          $ra, 0x40($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X40);
    // 0x800039E4: lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X3C);
    // 0x800039E8: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x800039EC: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x800039F0: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x800039F4: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x800039F8: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x800039FC: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x80003A00: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80003A04: jr          $ra
    // 0x80003A08: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x80003A08: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void find_manifest_entry(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80003A0C: addiu       $sp, $sp, -0x148
    ctx->r29 = ADD32(ctx->r29, -0X148);
    // 0x80003A10: sw          $s0, 0x128($sp)
    MEM_W(0X128, ctx->r29) = ctx->r16;
    // 0x80003A14: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x80003A18: sw          $s1, 0x12C($sp)
    MEM_W(0X12C, ctx->r29) = ctx->r17;
    // 0x80003A1C: addu        $s1, $a1, $zero
    ctx->r17 = ADD32(ctx->r5, 0);
    // 0x80003A20: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // 0x80003A24: sll         $v0, $s0, 2
    ctx->r2 = S32(ctx->r16 << 2);
    // 0x80003A28: addu        $v0, $v0, $s0
    ctx->r2 = ADD32(ctx->r2, ctx->r16);
    // 0x80003A2C: sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2 << 4);
    // 0x80003A30: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x80003A34: addiu       $a1, $a1, 0xAA0
    ctx->r5 = ADD32(ctx->r5, 0XAA0);
    // 0x80003A38: addu        $a1, $v0, $a1
    ctx->r5 = ADD32(ctx->r2, ctx->r5);
    // 0x80003A3C: sw          $ra, 0x140($sp)
    MEM_W(0X140, ctx->r29) = ctx->r31;
    // 0x80003A40: sw          $s5, 0x13C($sp)
    MEM_W(0X13C, ctx->r29) = ctx->r21;
    // 0x80003A44: sw          $s4, 0x138($sp)
    MEM_W(0X138, ctx->r29) = ctx->r20;
    // 0x80003A48: sw          $s3, 0x134($sp)
    MEM_W(0X134, ctx->r29) = ctx->r19;
    // 0x80003A4C: jal         0x8000761C
    // 0x80003A50: sw          $s2, 0x130($sp)
    MEM_W(0X130, ctx->r29) = ctx->r18;
    rs_strcpy(rdram, ctx);
        goto after_0;
    // 0x80003A50: sw          $s2, 0x130($sp)
    MEM_W(0X130, ctx->r29) = ctx->r18;
    after_0:
    // 0x80003A54: lbu         $v0, 0x10($sp)
    ctx->r2 = MEM_BU(ctx->r29, 0X10);
    // 0x80003A58: beq         $v0, $zero, L_80003A90
    if (ctx->r2 == 0) {
        // 0x80003A5C: addiu       $a0, $sp, 0x10
        ctx->r4 = ADD32(ctx->r29, 0X10);
            goto L_80003A90;
    }
    // 0x80003A5C: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // 0x80003A60: jal         0x8003471C
    // 0x80003A64: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    strlen_recomp(rdram, ctx);
        goto after_1;
    // 0x80003A64: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    after_1:
    // 0x80003A68: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // 0x80003A6C: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x80003A70: lbu         $v1, -0x1($v0)
    ctx->r3 = MEM_BU(ctx->r2, -0X1);
    // 0x80003A74: addiu       $v0, $zero, 0x2F
    ctx->r2 = ADD32(0, 0X2F);
    // 0x80003A78: beq         $v1, $v0, L_80003A90
    if (ctx->r3 == ctx->r2) {
        // 0x80003A7C: nop
    
            goto L_80003A90;
    }
    // 0x80003A7C: nop

    // 0x80003A80: lui         $a1, 0x8000
    ctx->r5 = S32(0X8000 << 16);
    // 0x80003A84: jal         0x8000767C
    // 0x80003A88: addiu       $a1, $a1, 0x470
    ctx->r5 = ADD32(ctx->r5, 0X470);
    rs_strcat(rdram, ctx);
        goto after_2;
    // 0x80003A88: addiu       $a1, $a1, 0x470
    ctx->r5 = ADD32(ctx->r5, 0X470);
    after_2:
    // 0x80003A8C: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
L_80003A90:
    // 0x80003A90: jal         0x8000767C
    // 0x80003A94: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    rs_strcat(rdram, ctx);
        goto after_3;
    // 0x80003A94: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    after_3:
    // 0x80003A98: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // 0x80003A9C: lui         $a1, 0x8000
    ctx->r5 = S32(0X8000 << 16);
    // 0x80003AA0: jal         0x8000767C
    // 0x80003AA4: addiu       $a1, $a1, 0x470
    ctx->r5 = ADD32(ctx->r5, 0X470);
    rs_strcat(rdram, ctx);
        goto after_4;
    // 0x80003AA4: addiu       $a1, $a1, 0x470
    ctx->r5 = ADD32(ctx->r5, 0X470);
    after_4:
    // 0x80003AA8: addiu       $s5, $sp, 0x10
    ctx->r21 = ADD32(ctx->r29, 0X10);
    // 0x80003AAC: addu        $a0, $s5, $zero
    ctx->r4 = ADD32(ctx->r21, 0);
    // 0x80003AB0: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x80003AB4: addiu       $v1, $v1, 0xA80
    ctx->r3 = ADD32(ctx->r3, 0XA80);
    // 0x80003AB8: sll         $v0, $s0, 2
    ctx->r2 = S32(ctx->r16 << 2);
    // 0x80003ABC: addu        $v0, $v0, $s0
    ctx->r2 = ADD32(ctx->r2, ctx->r16);
    // 0x80003AC0: sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2 << 4);
    // 0x80003AC4: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80003AC8: lw          $s2, 0x40($v0)
    ctx->r18 = MEM_W(ctx->r2, 0X40);
    // 0x80003ACC: lw          $s4, 0x48($v0)
    ctx->r20 = MEM_W(ctx->r2, 0X48);
    // 0x80003AD0: jal         0x80034744
    // 0x80003AD4: addiu       $a1, $zero, 0x2F
    ctx->r5 = ADD32(0, 0X2F);
    strchr_recomp(rdram, ctx);
        goto after_5;
    // 0x80003AD4: addiu       $a1, $zero, 0x2F
    ctx->r5 = ADD32(0, 0X2F);
    after_5:
    // 0x80003AD8: addu        $s3, $v0, $zero
    ctx->r19 = ADD32(ctx->r2, 0);
    // 0x80003ADC: addiu       $s1, $sp, 0x110
    ctx->r17 = ADD32(ctx->r29, 0X110);
    // 0x80003AE0: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x80003AE4: addu        $a1, $s5, $zero
    ctx->r5 = ADD32(ctx->r21, 0);
    // 0x80003AE8: subu        $s0, $s3, $a1
    ctx->r16 = SUB32(ctx->r19, ctx->r5);
    // 0x80003AEC: jal         0x80007640
    // 0x80003AF0: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    rs_strncpy(rdram, ctx);
        goto after_6;
    // 0x80003AF0: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    after_6:
    // 0x80003AF4: addiu       $s5, $s3, 0x1
    ctx->r21 = ADD32(ctx->r19, 0X1);
    // 0x80003AF8: addu        $s0, $s1, $s0
    ctx->r16 = ADD32(ctx->r17, ctx->r16);
    // 0x80003AFC: sb          $zero, 0x0($s0)
    MEM_B(0X0, ctx->r16) = 0;
    // 0x80003B00: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
L_80003B04:
    // 0x80003B04: addiu       $a1, $s2, 0x10
    ctx->r5 = ADD32(ctx->r18, 0X10);
    // 0x80003B08: jal         0x800077A8
    // 0x80003B0C: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    rs_strncmp(rdram, ctx);
        goto after_7;
    // 0x80003B0C: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    after_7:
    // 0x80003B10: beq         $v0, $zero, L_80003B48
    if (ctx->r2 == 0) {
        // 0x80003B14: nop
    
            goto L_80003B48;
    }
    // 0x80003B14: nop

    // 0x80003B18: lbu         $v0, 0xC($s2)
    ctx->r2 = MEM_BU(ctx->r18, 0XC);
    // 0x80003B1C: andi        $v0, $v0, 0x80
    ctx->r2 = ctx->r2 & 0X80;
    // 0x80003B20: beql        $v0, $zero, L_80003B40
    if (ctx->r2 == 0) {
        // 0x80003B24: addiu       $s2, $s2, 0x20
        ctx->r18 = ADD32(ctx->r18, 0X20);
            goto L_80003B40;
    }
    goto skip_0;
    // 0x80003B24: addiu       $s2, $s2, 0x20
    ctx->r18 = ADD32(ctx->r18, 0X20);
    skip_0:
    // 0x80003B28: lhu         $v1, 0xE($s2)
    ctx->r3 = MEM_HU(ctx->r18, 0XE);
    // 0x80003B2C: srl         $v1, $v1, 5
    ctx->r3 = S32(U32(ctx->r3) >> 5);
    // 0x80003B30: sll         $v0, $v1, 5
    ctx->r2 = S32(ctx->r3 << 5);
    // 0x80003B34: addu        $s2, $s2, $v0
    ctx->r18 = ADD32(ctx->r18, ctx->r2);
    // 0x80003B38: j           L_80003B9C
    // 0x80003B3C: subu        $s4, $s4, $v1
    ctx->r20 = SUB32(ctx->r20, ctx->r3);
        goto L_80003B9C;
    // 0x80003B3C: subu        $s4, $s4, $v1
    ctx->r20 = SUB32(ctx->r20, ctx->r3);
L_80003B40:
    // 0x80003B40: j           L_80003B9C
    // 0x80003B44: addiu       $s4, $s4, -0x1
    ctx->r20 = ADD32(ctx->r20, -0X1);
        goto L_80003B9C;
    // 0x80003B44: addiu       $s4, $s4, -0x1
    ctx->r20 = ADD32(ctx->r20, -0X1);
L_80003B48:
    // 0x80003B48: lbu         $v0, 0xC($s2)
    ctx->r2 = MEM_BU(ctx->r18, 0XC);
    // 0x80003B4C: andi        $v0, $v0, 0x80
    ctx->r2 = ctx->r2 & 0X80;
    // 0x80003B50: bne         $v0, $zero, L_80003B60
    if (ctx->r2 != 0) {
        // 0x80003B54: addu        $a0, $s5, $zero
        ctx->r4 = ADD32(ctx->r21, 0);
            goto L_80003B60;
    }
    // 0x80003B54: addu        $a0, $s5, $zero
    ctx->r4 = ADD32(ctx->r21, 0);
    // 0x80003B58: j           L_80003BA8
    // 0x80003B5C: addu        $v0, $s2, $zero
    ctx->r2 = ADD32(ctx->r18, 0);
        goto L_80003BA8;
    // 0x80003B5C: addu        $v0, $s2, $zero
    ctx->r2 = ADD32(ctx->r18, 0);
L_80003B60:
    // 0x80003B60: addiu       $a1, $zero, 0x2F
    ctx->r5 = ADD32(0, 0X2F);
    // 0x80003B64: lhu         $v0, 0xE($s2)
    ctx->r2 = MEM_HU(ctx->r18, 0XE);
    // 0x80003B68: addiu       $s2, $s2, 0x20
    ctx->r18 = ADD32(ctx->r18, 0X20);
    // 0x80003B6C: jal         0x80034744
    // 0x80003B70: srl         $s4, $v0, 5
    ctx->r20 = S32(U32(ctx->r2) >> 5);
    strchr_recomp(rdram, ctx);
        goto after_8;
    // 0x80003B70: srl         $s4, $v0, 5
    ctx->r20 = S32(U32(ctx->r2) >> 5);
    after_8:
    // 0x80003B74: addu        $s3, $v0, $zero
    ctx->r19 = ADD32(ctx->r2, 0);
    // 0x80003B78: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x80003B7C: addu        $a1, $s5, $zero
    ctx->r5 = ADD32(ctx->r21, 0);
    // 0x80003B80: subu        $s0, $s3, $a1
    ctx->r16 = SUB32(ctx->r19, ctx->r5);
    // 0x80003B84: jal         0x80007640
    // 0x80003B88: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    rs_strncpy(rdram, ctx);
        goto after_9;
    // 0x80003B88: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    after_9:
    // 0x80003B8C: addiu       $s5, $s3, 0x1
    ctx->r21 = ADD32(ctx->r19, 0X1);
    // 0x80003B90: addiu       $s4, $s4, -0x1
    ctx->r20 = ADD32(ctx->r20, -0X1);
    // 0x80003B94: addu        $s0, $s1, $s0
    ctx->r16 = ADD32(ctx->r17, ctx->r16);
    // 0x80003B98: sb          $zero, 0x0($s0)
    MEM_B(0X0, ctx->r16) = 0;
L_80003B9C:
    // 0x80003B9C: bgtz        $s4, L_80003B04
    if (SIGNED(ctx->r20) > 0) {
        // 0x80003BA0: addu        $a0, $s1, $zero
        ctx->r4 = ADD32(ctx->r17, 0);
            goto L_80003B04;
    }
    // 0x80003BA0: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x80003BA4: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_80003BA8:
    // 0x80003BA8: lw          $ra, 0x140($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X140);
    // 0x80003BAC: lw          $s5, 0x13C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X13C);
    // 0x80003BB0: lw          $s4, 0x138($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X138);
    // 0x80003BB4: lw          $s3, 0x134($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X134);
    // 0x80003BB8: lw          $s2, 0x130($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X130);
    // 0x80003BBC: lw          $s1, 0x12C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X12C);
    // 0x80003BC0: lw          $s0, 0x128($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X128);
    // 0x80003BC4: jr          $ra
    // 0x80003BC8: addiu       $sp, $sp, 0x148
    ctx->r29 = ADD32(ctx->r29, 0X148);
    return;
    // 0x80003BC8: addiu       $sp, $sp, 0x148
    ctx->r29 = ADD32(ctx->r29, 0X148);
;}
RECOMP_FUNC void func_80003BCC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80003BCC: addu        $a3, $a0, $zero
    ctx->r7 = ADD32(ctx->r4, 0);
    // 0x80003BD0: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80003BD4: lw          $a2, 0x1244($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X1244);
    // 0x80003BD8: addiu       $v1, $a2, 0x1
    ctx->r3 = ADD32(ctx->r6, 0X1);
    // 0x80003BDC: bgez        $v1, L_80003BE8
    if (SIGNED(ctx->r3) >= 0) {
        // 0x80003BE0: addu        $v0, $v1, $zero
        ctx->r2 = ADD32(ctx->r3, 0);
            goto L_80003BE8;
    }
    // 0x80003BE0: addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
    // 0x80003BE4: addiu       $v0, $a2, 0x8
    ctx->r2 = ADD32(ctx->r6, 0X8);
L_80003BE8:
    // 0x80003BE8: sra         $v0, $v0, 3
    ctx->r2 = S32(SIGNED(ctx->r2) >> 3);
    // 0x80003BEC: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x80003BF0: subu        $v0, $v1, $v0
    ctx->r2 = SUB32(ctx->r3, ctx->r2);
    // 0x80003BF4: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x80003BF8: sw          $v0, 0x1244($a0)
    MEM_W(0X1244, ctx->r4) = ctx->r2;
    // 0x80003BFC: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80003C00: addiu       $a0, $a0, 0xD60
    ctx->r4 = ADD32(ctx->r4, 0XD60);
    // 0x80003C04: sll         $v0, $a2, 3
    ctx->r2 = S32(ctx->r6 << 3);
    // 0x80003C08: subu        $v0, $v0, $a2
    ctx->r2 = SUB32(ctx->r2, ctx->r6);
    // 0x80003C0C: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80003C10: addu        $v0, $v0, $a2
    ctx->r2 = ADD32(ctx->r2, ctx->r6);
    // 0x80003C14: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80003C18: addu        $a2, $v0, $a0
    ctx->r6 = ADD32(ctx->r2, ctx->r4);
    // 0x80003C1C: lw          $v1, 0x124C($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X124C);
    // 0x80003C20: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80003C24: sh          $zero, 0x2($a2)
    MEM_H(0X2, ctx->r6) = 0;
    // 0x80003C28: sw          $a3, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r7;
    // 0x80003C2C: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x80003C30: sw          $v1, 0x124C($a1)
    MEM_W(0X124C, ctx->r5) = ctx->r3;
    // 0x80003C34: sb          $v0, 0x1($a2)
    MEM_B(0X1, ctx->r6) = ctx->r2;
    // 0x80003C38: lbu         $a0, 0x1($a3)
    ctx->r4 = MEM_BU(ctx->r7, 0X1);
    // 0x80003C3C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80003C40: beq         $a0, $v0, L_80003C78
    if (ctx->r4 == ctx->r2) {
        // 0x80003C44: slti        $v0, $a0, 0x2
        ctx->r2 = SIGNED(ctx->r4) < 0X2 ? 1 : 0;
            goto L_80003C78;
    }
    // 0x80003C44: slti        $v0, $a0, 0x2
    ctx->r2 = SIGNED(ctx->r4) < 0X2 ? 1 : 0;
    // 0x80003C48: beq         $v0, $zero, L_80003C60
    if (ctx->r2 == 0) {
        // 0x80003C4C: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_80003C60;
    }
    // 0x80003C4C: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x80003C50: beq         $a0, $zero, L_80003C70
    if (ctx->r4 == 0) {
        // 0x80003C54: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80003C70;
    }
    // 0x80003C54: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80003C58: j           L_80003C90
    // 0x80003C5C: nop

        goto L_80003C90;
    // 0x80003C5C: nop

L_80003C60:
    // 0x80003C60: beq         $a0, $v0, L_80003C80
    if (ctx->r4 == ctx->r2) {
        // 0x80003C64: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80003C80;
    }
    // 0x80003C64: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80003C68: j           L_80003C90
    // 0x80003C6C: nop

        goto L_80003C90;
    // 0x80003C6C: nop

L_80003C70:
    // 0x80003C70: j           L_80003C8C
    // 0x80003C74: sb          $zero, 0x0($a2)
    MEM_B(0X0, ctx->r6) = 0;
        goto L_80003C8C;
    // 0x80003C74: sb          $zero, 0x0($a2)
    MEM_B(0X0, ctx->r6) = 0;
L_80003C78:
    // 0x80003C78: j           L_80003C8C
    // 0x80003C7C: sb          $a0, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r4;
        goto L_80003C8C;
    // 0x80003C7C: sb          $a0, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r4;
L_80003C80:
    // 0x80003C80: sb          $a0, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r4;
    // 0x80003C84: sh          $zero, 0x8($a2)
    MEM_H(0X8, ctx->r6) = 0;
    // 0x80003C88: sw          $zero, 0x48($a2)
    MEM_W(0X48, ctx->r6) = 0;
L_80003C8C:
    // 0x80003C8C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80003C90:
    // 0x80003C90: jr          $ra
    // 0x80003C94: nop

    return;
    // 0x80003C94: nop

;}
RECOMP_FUNC void func_80003C98(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80003C98: addu        $a3, $a0, $zero
    ctx->r7 = ADD32(ctx->r4, 0);
    // 0x80003C9C: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x80003CA0: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80003CA4: addiu       $v1, $v0, 0xBC0
    ctx->r3 = ADD32(ctx->r2, 0XBC0);
L_80003CA8:
    // 0x80003CA8: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x80003CAC: beq         $v0, $zero, L_80003CE8
    if (ctx->r2 == 0) {
        // 0x80003CB0: lui         $v0, 0x8011
        ctx->r2 = S32(0X8011 << 16);
            goto L_80003CE8;
    }
    // 0x80003CB0: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80003CB4: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x80003CB8: slti        $v0, $a2, 0x10
    ctx->r2 = SIGNED(ctx->r6) < 0X10 ? 1 : 0;
    // 0x80003CBC: bne         $v0, $zero, L_80003CA8
    if (ctx->r2 != 0) {
        // 0x80003CC0: addiu       $v1, $v1, 0x18
        ctx->r3 = ADD32(ctx->r3, 0X18);
            goto L_80003CA8;
    }
    // 0x80003CC0: addiu       $v1, $v1, 0x18
    ctx->r3 = ADD32(ctx->r3, 0X18);
    // 0x80003CC4: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80003CC8: addiu       $v0, $v0, 0xBC0
    ctx->r2 = ADD32(ctx->r2, 0XBC0);
    // 0x80003CCC: sll         $v1, $a2, 1
    ctx->r3 = S32(ctx->r6 << 1);
    // 0x80003CD0: addu        $v1, $v1, $a2
    ctx->r3 = ADD32(ctx->r3, ctx->r6);
    // 0x80003CD4: sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3 << 3);
    // 0x80003CD8: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80003CDC: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x80003CE0: bne         $v0, $zero, L_80003D5C
    if (ctx->r2 != 0) {
        // 0x80003CE4: lui         $v0, 0x8011
        ctx->r2 = S32(0X8011 << 16);
            goto L_80003D5C;
    }
    // 0x80003CE4: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
L_80003CE8:
    // 0x80003CE8: addiu       $v0, $v0, 0xBC0
    ctx->r2 = ADD32(ctx->r2, 0XBC0);
    // 0x80003CEC: sll         $a0, $a2, 1
    ctx->r4 = S32(ctx->r6 << 1);
    // 0x80003CF0: addu        $a0, $a0, $a2
    ctx->r4 = ADD32(ctx->r4, ctx->r6);
    // 0x80003CF4: sll         $a0, $a0, 3
    ctx->r4 = S32(ctx->r4 << 3);
    // 0x80003CF8: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x80003CFC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80003D00: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x80003D04: sb          $v0, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r2;
    // 0x80003D08: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80003D0C: lw          $v1, 0x1240($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X1240);
    // 0x80003D10: addiu       $a1, $a1, 0xD60
    ctx->r5 = ADD32(ctx->r5, 0XD60);
    // 0x80003D14: sll         $v0, $v1, 3
    ctx->r2 = S32(ctx->r3 << 3);
    // 0x80003D18: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x80003D1C: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80003D20: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80003D24: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80003D28: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x80003D2C: lw          $v1, 0x4($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X4);
    // 0x80003D30: lw          $v1, 0x18($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X18);
    // 0x80003D34: sw          $v1, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r3;
    // 0x80003D38: lw          $v1, 0x4($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X4);
    // 0x80003D3C: lhu         $v1, 0x20($v1)
    ctx->r3 = MEM_HU(ctx->r3, 0X20);
    // 0x80003D40: sw          $zero, 0x8($a0)
    MEM_W(0X8, ctx->r4) = 0;
    // 0x80003D44: sh          $v1, 0xC($a0)
    MEM_H(0XC, ctx->r4) = ctx->r3;
    // 0x80003D48: lw          $v0, 0x4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X4);
    // 0x80003D4C: lw          $v0, 0x1C($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X1C);
    // 0x80003D50: sw          $zero, 0x14($a0)
    MEM_W(0X14, ctx->r4) = 0;
    // 0x80003D54: sw          $v0, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r2;
    // 0x80003D58: sw          $a2, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r6;
L_80003D5C:
    // 0x80003D5C: jr          $ra
    // 0x80003D60: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80003D60: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
;}
RECOMP_FUNC void func_80003D64(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80003D64: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80003D68: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x80003D6C: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80003D70: lw          $v0, 0x1240($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X1240);
    // 0x80003D74: addiu       $v1, $v1, 0xD60
    ctx->r3 = ADD32(ctx->r3, 0XD60);
    // 0x80003D78: sw          $ra, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r31;
    // 0x80003D7C: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // 0x80003D80: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x80003D84: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x80003D88: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80003D8C: sll         $a1, $v0, 3
    ctx->r5 = S32(ctx->r2 << 3);
    // 0x80003D90: subu        $a1, $a1, $v0
    ctx->r5 = SUB32(ctx->r5, ctx->r2);
    // 0x80003D94: sll         $a1, $a1, 2
    ctx->r5 = S32(ctx->r5 << 2);
    // 0x80003D98: addu        $a1, $a1, $v0
    ctx->r5 = ADD32(ctx->r5, ctx->r2);
    // 0x80003D9C: sll         $a1, $a1, 2
    ctx->r5 = S32(ctx->r5 << 2);
    // 0x80003DA0: addu        $a1, $a1, $v1
    ctx->r5 = ADD32(ctx->r5, ctx->r3);
    // 0x80003DA4: lw          $v0, 0x4($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X4);
    // 0x80003DA8: addiu       $s1, $v0, 0x18
    ctx->r17 = ADD32(ctx->r2, 0X18);
    // 0x80003DAC: lw          $a2, 0x18($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X18);
    // 0x80003DB0: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80003DB4: addiu       $v0, $v0, 0xBC0
    ctx->r2 = ADD32(ctx->r2, 0XBC0);
    // 0x80003DB8: sb          $zero, 0x0($a0)
    MEM_B(0X0, ctx->r4) = 0;
    // 0x80003DBC: sll         $v1, $a2, 1
    ctx->r3 = S32(ctx->r6 << 1);
    // 0x80003DC0: addu        $v1, $v1, $a2
    ctx->r3 = ADD32(ctx->r3, ctx->r6);
    // 0x80003DC4: sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3 << 3);
    // 0x80003DC8: addu        $s2, $v1, $v0
    ctx->r18 = ADD32(ctx->r3, ctx->r2);
    // 0x80003DCC: lw          $v0, 0x14($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X14);
    // 0x80003DD0: bne         $v0, $zero, L_80004340
    if (ctx->r2 != 0) {
        // 0x80003DD4: addu        $s0, $a1, $zero
        ctx->r16 = ADD32(ctx->r5, 0);
            goto L_80004340;
    }
    // 0x80003DD4: addu        $s0, $a1, $zero
    ctx->r16 = ADD32(ctx->r5, 0);
    // 0x80003DD8: lw          $a0, 0x4($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X4);
    // 0x80003DDC: lw          $v1, 0x8($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X8);
    // 0x80003DE0: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x80003DE4: beq         $v1, $v0, L_80003DFC
    if (ctx->r3 == ctx->r2) {
        // 0x80003DE8: lui         $v0, 0x8011
        ctx->r2 = S32(0X8011 << 16);
            goto L_80003DFC;
    }
    // 0x80003DE8: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80003DEC: lbu         $v0, 0xC($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0XC);
    // 0x80003DF0: andi        $v0, $v0, 0x4
    ctx->r2 = ctx->r2 & 0X4;
    // 0x80003DF4: beq         $v0, $zero, L_80003F88
    if (ctx->r2 == 0) {
        // 0x80003DF8: lui         $v0, 0x8011
        ctx->r2 = S32(0X8011 << 16);
            goto L_80003F88;
    }
    // 0x80003DF8: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
L_80003DFC:
    // 0x80003DFC: lw          $v1, 0x10($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X10);
    // 0x80003E00: addiu       $s3, $v0, 0xA80
    ctx->r19 = ADD32(ctx->r2, 0XA80);
    // 0x80003E04: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x80003E08: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80003E0C: sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2 << 4);
    // 0x80003E10: addu        $v0, $v0, $s3
    ctx->r2 = ADD32(ctx->r2, ctx->r19);
    // 0x80003E14: lhu         $v0, 0x4C($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X4C);
    // 0x80003E18: bne         $v0, $zero, L_80004344
    if (ctx->r2 != 0) {
        // 0x80003E1C: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_80004344;
    }
    // 0x80003E1C: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x80003E20: lhu         $v1, 0x8($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X8);
    // 0x80003E24: andi        $v0, $v1, 0x8000
    ctx->r2 = ctx->r3 & 0X8000;
    // 0x80003E28: beq         $v0, $zero, L_80003E98
    if (ctx->r2 == 0) {
        // 0x80003E2C: andi        $v0, $v1, 0x800
        ctx->r2 = ctx->r3 & 0X800;
            goto L_80003E98;
    }
    // 0x80003E2C: andi        $v0, $v1, 0x800
    ctx->r2 = ctx->r3 & 0X800;
    // 0x80003E30: lw          $a0, 0xC($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XC);
    // 0x80003E34: jal         0x80003824
    // 0x80003E38: nop

    func_80003824(rdram, ctx);
        goto after_0;
    // 0x80003E38: nop

    after_0:
    // 0x80003E3C: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x80003E40: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80003E44: bne         $v0, $v1, L_80004344
    if (ctx->r2 != ctx->r3) {
        // 0x80003E48: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_80004344;
    }
    // 0x80003E48: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x80003E4C: lbu         $v0, 0x70($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X70);
    // 0x80003E50: beq         $v0, $zero, L_80004344
    if (ctx->r2 == 0) {
        // 0x80003E54: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80004344;
    }
    // 0x80003E54: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80003E58: lhu         $v1, 0x8($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X8);
    // 0x80003E5C: andi        $v0, $v1, 0x400
    ctx->r2 = ctx->r3 & 0X400;
    // 0x80003E60: beq         $v0, $zero, L_80003E90
    if (ctx->r2 == 0) {
        // 0x80003E64: andi        $v0, $v1, 0x7FFF
        ctx->r2 = ctx->r3 & 0X7FFF;
            goto L_80003E90;
    }
    // 0x80003E64: andi        $v0, $v1, 0x7FFF
    ctx->r2 = ctx->r3 & 0X7FFF;
    // 0x80003E68: lw          $a0, 0xC($s1)
    ctx->r4 = MEM_W(ctx->r17, 0XC);
    // 0x80003E6C: lw          $a1, 0x48($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X48);
    // 0x80003E70: jal         0x800346F0
    // 0x80003E74: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    memcpy_recomp(rdram, ctx);
        goto after_1;
    // 0x80003E74: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_1:
    // 0x80003E78: lw          $a0, 0x48($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X48);
    // 0x80003E7C: jal         0x80001C98
    // 0x80003E80: nop

    rs_free(rdram, ctx);
        goto after_2;
    // 0x80003E80: nop

    after_2:
    // 0x80003E84: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80003E88: j           L_80004344
    // 0x80003E8C: sw          $zero, 0x48($s0)
    MEM_W(0X48, ctx->r16) = 0;
        goto L_80004344;
    // 0x80003E8C: sw          $zero, 0x48($s0)
    MEM_W(0X48, ctx->r16) = 0;
L_80003E90:
    // 0x80003E90: j           L_8000433C
    // 0x80003E94: ori         $v0, $v0, 0x800
    ctx->r2 = ctx->r2 | 0X800;
        goto L_8000433C;
    // 0x80003E94: ori         $v0, $v0, 0x800
    ctx->r2 = ctx->r2 | 0X800;
L_80003E98:
    // 0x80003E98: beq         $v0, $zero, L_80003EF0
    if (ctx->r2 == 0) {
        // 0x80003E9C: addiu       $a0, $zero, 0x10
        ctx->r4 = ADD32(0, 0X10);
            goto L_80003EF0;
    }
    // 0x80003E9C: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    // 0x80003EA0: jal         0x80001ACC
    // 0x80003EA4: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    rs_malloc(rdram, ctx);
        goto after_3;
    // 0x80003EA4: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    after_3:
    // 0x80003EA8: lhu         $v1, 0x8($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X8);
    // 0x80003EAC: sw          $v0, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->r2;
    // 0x80003EB0: ori         $v1, $v1, 0x8400
    ctx->r3 = ctx->r3 | 0X8400;
    // 0x80003EB4: sh          $v1, 0x8($s0)
    MEM_H(0X8, ctx->r16) = ctx->r3;
    // 0x80003EB8: lw          $v0, 0x4($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X4);
    // 0x80003EBC: lw          $v1, 0x8($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X8);
    // 0x80003EC0: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x80003EC4: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80003EC8: sw          $v0, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r2;
    // 0x80003ECC: addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
    // 0x80003ED0: lw          $v1, 0xC($s1)
    ctx->r3 = MEM_W(ctx->r17, 0XC);
    // 0x80003ED4: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x80003ED8: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80003EDC: sw          $v1, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->r3;
    // 0x80003EE0: lw          $v1, 0x10($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X10);
    // 0x80003EE4: lw          $a1, 0x48($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X48);
    // 0x80003EE8: j           L_80003F54
    // 0x80003EEC: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
        goto L_80003F54;
    // 0x80003EEC: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
L_80003EF0:
    // 0x80003EF0: lbu         $v0, 0xB($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0XB);
    // 0x80003EF4: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x80003EF8: sb          $v0, 0x70($s0)
    MEM_B(0X70, ctx->r16) = ctx->r2;
    // 0x80003EFC: lw          $v1, 0x8($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X8);
    // 0x80003F00: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80003F04: bne         $v1, $v0, L_80003F34
    if (ctx->r3 != ctx->r2) {
        // 0x80003F08: nop
    
            goto L_80003F34;
    }
    // 0x80003F08: nop

    // 0x80003F0C: jal         0x80001ACC
    // 0x80003F10: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    rs_malloc(rdram, ctx);
        goto after_4;
    // 0x80003F10: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    after_4:
    // 0x80003F14: lhu         $v1, 0x8($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X8);
    // 0x80003F18: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    // 0x80003F1C: sw          $v0, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->r2;
    // 0x80003F20: ori         $v1, $v1, 0x8400
    ctx->r3 = ctx->r3 | 0X8400;
    // 0x80003F24: sh          $v1, 0x8($s0)
    MEM_H(0X8, ctx->r16) = ctx->r3;
    // 0x80003F28: lw          $v1, 0x10($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X10);
    // 0x80003F2C: j           L_80003F54
    // 0x80003F30: addu        $a1, $v0, $zero
    ctx->r5 = ADD32(ctx->r2, 0);
        goto L_80003F54;
    // 0x80003F30: addu        $a1, $v0, $zero
    ctx->r5 = ADD32(ctx->r2, 0);
L_80003F34:
    // 0x80003F34: lhu         $v0, 0x8($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X8);
    // 0x80003F38: ori         $v0, $v0, 0x8000
    ctx->r2 = ctx->r2 | 0X8000;
    // 0x80003F3C: sh          $v0, 0x8($s0)
    MEM_H(0X8, ctx->r16) = ctx->r2;
    // 0x80003F40: lw          $a1, 0xC($s1)
    ctx->r5 = MEM_W(ctx->r17, 0XC);
    // 0x80003F44: lbu         $v0, 0x70($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X70);
    // 0x80003F48: lw          $a2, 0x8($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X8);
    // 0x80003F4C: lw          $v1, 0x10($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X10);
    // 0x80003F50: subu        $a2, $a2, $v0
    ctx->r6 = SUB32(ctx->r6, ctx->r2);
L_80003F54:
    // 0x80003F54: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x80003F58: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80003F5C: sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2 << 4);
    // 0x80003F60: addu        $v0, $v0, $s3
    ctx->r2 = ADD32(ctx->r2, ctx->r19);
    // 0x80003F64: lw          $v1, 0x4($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X4);
    // 0x80003F68: lw          $a0, 0x44($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X44);
    // 0x80003F6C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80003F70: lw          $v1, 0x4($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X4);
    // 0x80003F74: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x80003F78: jal         0x80003480
    // 0x80003F7C: addu        $a0, $a0, $v1
    ctx->r4 = ADD32(ctx->r4, ctx->r3);
    func_80003480(rdram, ctx);
        goto after_5;
    // 0x80003F7C: addu        $a0, $a0, $v1
    ctx->r4 = ADD32(ctx->r4, ctx->r3);
    after_5:
    // 0x80003F80: j           L_80004340
    // 0x80003F84: sw          $v0, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r2;
        goto L_80004340;
    // 0x80003F84: sw          $v0, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r2;
L_80003F88:
    // 0x80003F88: lw          $v1, 0x10($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X10);
    // 0x80003F8C: addiu       $s3, $v0, 0xA80
    ctx->r19 = ADD32(ctx->r2, 0XA80);
    // 0x80003F90: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x80003F94: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80003F98: sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2 << 4);
    // 0x80003F9C: addu        $v0, $v0, $s3
    ctx->r2 = ADD32(ctx->r2, ctx->r19);
    // 0x80003FA0: lhu         $v0, 0x4C($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X4C);
    // 0x80003FA4: bne         $v0, $zero, L_80004344
    if (ctx->r2 != 0) {
        // 0x80003FA8: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_80004344;
    }
    // 0x80003FA8: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x80003FAC: lhu         $v1, 0x8($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X8);
    // 0x80003FB0: andi        $v0, $v1, 0x4000
    ctx->r2 = ctx->r3 & 0X4000;
    // 0x80003FB4: bne         $v0, $zero, L_80004080
    if (ctx->r2 != 0) {
        // 0x80003FB8: addiu       $a0, $zero, 0x1000
        ctx->r4 = ADD32(0, 0X1000);
            goto L_80004080;
    }
    // 0x80003FB8: addiu       $a0, $zero, 0x1000
    ctx->r4 = ADD32(0, 0X1000);
    // 0x80003FBC: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    // 0x80003FC0: ori         $v0, $v1, 0x4000
    ctx->r2 = ctx->r3 | 0X4000;
    // 0x80003FC4: jal         0x80001ACC
    // 0x80003FC8: sh          $v0, 0x8($s0)
    MEM_H(0X8, ctx->r16) = ctx->r2;
    rs_malloc(rdram, ctx);
        goto after_6;
    // 0x80003FC8: sh          $v0, 0x8($s0)
    MEM_H(0X8, ctx->r16) = ctx->r2;
    after_6:
    // 0x80003FCC: sw          $v0, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->r2;
    // 0x80003FD0: lw          $v1, 0x10($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X10);
    // 0x80003FD4: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x80003FD8: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80003FDC: sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2 << 4);
    // 0x80003FE0: addu        $v0, $v0, $s3
    ctx->r2 = ADD32(ctx->r2, ctx->r19);
    // 0x80003FE4: lw          $v1, 0x4($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X4);
    // 0x80003FE8: lw          $v0, 0x44($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X44);
    // 0x80003FEC: lw          $v1, 0x0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X0);
    // 0x80003FF0: sw          $zero, 0x54($s0)
    MEM_W(0X54, ctx->r16) = 0;
    // 0x80003FF4: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80003FF8: sw          $v0, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->r2;
    // 0x80003FFC: lw          $v0, 0x4($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X4);
    // 0x80004000: lw          $v0, 0x8($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X8);
    // 0x80004004: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x80004008: sb          $v0, 0x70($s0)
    MEM_B(0X70, ctx->r16) = ctx->r2;
    // 0x8000400C: lw          $v0, 0x4($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X4);
    // 0x80004010: lw          $v1, 0x4($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X4);
    // 0x80004014: lw          $v0, 0x8($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X8);
    // 0x80004018: sw          $zero, 0x5C($s0)
    MEM_W(0X5C, ctx->r16) = 0;
    // 0x8000401C: sw          $zero, 0x60($s0)
    MEM_W(0X60, ctx->r16) = 0;
    // 0x80004020: sw          $zero, 0x68($s0)
    MEM_W(0X68, ctx->r16) = 0;
    // 0x80004024: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80004028: srl         $v0, $v0, 1
    ctx->r2 = S32(U32(ctx->r2) >> 1);
    // 0x8000402C: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x80004030: sw          $v0, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->r2;
    // 0x80004034: lw          $v0, 0x20($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X20);
    // 0x80004038: sw          $v0, 0x6C($s0)
    MEM_W(0X6C, ctx->r16) = ctx->r2;
    // 0x8000403C: lw          $v0, 0x4($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X4);
    // 0x80004040: beq         $v0, $zero, L_80004054
    if (ctx->r2 == 0) {
        // 0x80004044: nop
    
            goto L_80004054;
    }
    // 0x80004044: nop

    // 0x80004048: lhu         $v0, 0x8($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X8);
    // 0x8000404C: j           L_8000405C
    // 0x80004050: ori         $v0, $v0, 0x1000
    ctx->r2 = ctx->r2 | 0X1000;
        goto L_8000405C;
    // 0x80004050: ori         $v0, $v0, 0x1000
    ctx->r2 = ctx->r2 | 0X1000;
L_80004054:
    // 0x80004054: lhu         $v0, 0x8($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X8);
    // 0x80004058: ori         $v0, $v0, 0x200
    ctx->r2 = ctx->r2 | 0X200;
L_8000405C:
    // 0x8000405C: sh          $v0, 0x8($s0)
    MEM_H(0X8, ctx->r16) = ctx->r2;
    // 0x80004060: addiu       $a0, $s0, 0x10
    ctx->r4 = ADD32(ctx->r16, 0X10);
    // 0x80004064: lui         $a1, 0x8000
    ctx->r5 = S32(0X8000 << 16);
    // 0x80004068: addiu       $a1, $a1, 0x474
    ctx->r5 = ADD32(ctx->r5, 0X474);
    // 0x8000406C: addiu       $a2, $zero, 0x38
    ctx->r6 = ADD32(0, 0X38);
    // 0x80004070: sw          $zero, 0x30($s0)
    MEM_W(0X30, ctx->r16) = 0;
    // 0x80004074: sw          $zero, 0x34($s0)
    MEM_W(0X34, ctx->r16) = 0;
    // 0x80004078: jal         0x80026E7C
    // 0x8000407C: sw          $zero, 0x38($s0)
    MEM_W(0X38, ctx->r16) = 0;
    inflateInit_(rdram, ctx);
        goto after_7;
    // 0x8000407C: sw          $zero, 0x38($s0)
    MEM_W(0X38, ctx->r16) = 0;
    after_7:
L_80004080:
    // 0x80004080: lhu         $a0, 0x8($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X8);
    // 0x80004084: andi        $v0, $a0, 0x2000
    ctx->r2 = ctx->r4 & 0X2000;
    // 0x80004088: beq         $v0, $zero, L_80004280
    if (ctx->r2 == 0) {
        // 0x8000408C: nop
    
            goto L_80004280;
    }
    // 0x8000408C: nop

    // 0x80004090: lw          $v1, 0x4($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X4);
    // 0x80004094: lw          $a1, 0x60($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X60);
    // 0x80004098: lw          $s1, 0x1C($v1)
    ctx->r17 = MEM_W(ctx->r3, 0X1C);
    // 0x8000409C: lw          $a2, 0x20($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X20);
    // 0x800040A0: sltu        $v0, $a1, $s1
    ctx->r2 = ctx->r5 < ctx->r17 ? 1 : 0;
    // 0x800040A4: beq         $v0, $zero, L_800041C0
    if (ctx->r2 == 0) {
        // 0x800040A8: andi        $v0, $a0, 0x800
        ctx->r2 = ctx->r4 & 0X800;
            goto L_800041C0;
    }
    // 0x800040A8: andi        $v0, $a0, 0x800
    ctx->r2 = ctx->r4 & 0X800;
    // 0x800040AC: bne         $v0, $zero, L_800040F4
    if (ctx->r2 != 0) {
        // 0x800040B0: andi        $v0, $a0, 0xF7FF
        ctx->r2 = ctx->r4 & 0XF7FF;
            goto L_800040F4;
    }
    // 0x800040B0: andi        $v0, $a0, 0xF7FF
    ctx->r2 = ctx->r4 & 0XF7FF;
    // 0x800040B4: subu        $v0, $s1, $a1
    ctx->r2 = SUB32(ctx->r17, ctx->r5);
    // 0x800040B8: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x800040BC: sltu        $v0, $a2, $v1
    ctx->r2 = ctx->r6 < ctx->r3 ? 1 : 0;
    // 0x800040C0: bnel        $v0, $zero, L_800040C8
    if (ctx->r2 != 0) {
        // 0x800040C4: addu        $v1, $a2, $zero
        ctx->r3 = ADD32(ctx->r6, 0);
            goto L_800040C8;
    }
    goto skip_0;
    // 0x800040C4: addu        $v1, $a2, $zero
    ctx->r3 = ADD32(ctx->r6, 0);
    skip_0:
L_800040C8:
    // 0x800040C8: sltiu       $v0, $v1, 0x1001
    ctx->r2 = ctx->r3 < 0X1001 ? 1 : 0;
    // 0x800040CC: bne         $v0, $zero, L_800040DC
    if (ctx->r2 != 0) {
        // 0x800040D0: sw          $v1, 0x64($s0)
        MEM_W(0X64, ctx->r16) = ctx->r3;
            goto L_800040DC;
    }
    // 0x800040D0: sw          $v1, 0x64($s0)
    MEM_W(0X64, ctx->r16) = ctx->r3;
    // 0x800040D4: addiu       $v0, $zero, 0x1000
    ctx->r2 = ADD32(0, 0X1000);
    // 0x800040D8: sw          $v0, 0x64($s0)
    MEM_W(0X64, ctx->r16) = ctx->r2;
L_800040DC:
    // 0x800040DC: lw          $v0, 0x4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4);
    // 0x800040E0: lw          $v1, 0x64($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X64);
    // 0x800040E4: lw          $v0, 0x24($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X24);
    // 0x800040E8: sw          $v1, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r3;
    // 0x800040EC: j           L_800040F8
    // 0x800040F0: sw          $v0, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->r2;
        goto L_800040F8;
    // 0x800040F0: sw          $v0, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->r2;
L_800040F4:
    // 0x800040F4: sh          $v0, 0x8($s0)
    MEM_H(0X8, ctx->r16) = ctx->r2;
L_800040F8:
    // 0x800040F8: lhu         $v1, 0x8($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X8);
    // 0x800040FC: andi        $v0, $v1, 0x400
    ctx->r2 = ctx->r3 & 0X400;
    // 0x80004100: beq         $v0, $zero, L_80004120
    if (ctx->r2 == 0) {
        // 0x80004104: andi        $v0, $v1, 0xFBFF
        ctx->r2 = ctx->r3 & 0XFBFF;
            goto L_80004120;
    }
    // 0x80004104: andi        $v0, $v1, 0xFBFF
    ctx->r2 = ctx->r3 & 0XFBFF;
    // 0x80004108: sh          $v0, 0x8($s0)
    MEM_H(0X8, ctx->r16) = ctx->r2;
    // 0x8000410C: lw          $v0, 0x4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4);
    // 0x80004110: lw          $v1, 0x64($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X64);
    // 0x80004114: lw          $v0, 0x24($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X24);
    // 0x80004118: sw          $v1, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r3;
    // 0x8000411C: sw          $v0, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->r2;
L_80004120:
    // 0x80004120: addiu       $a0, $s0, 0x10
    ctx->r4 = ADD32(ctx->r16, 0X10);
    // 0x80004124: jal         0x80026EA8
    // 0x80004128: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    inflate_recomp(rdram, ctx);
        goto after_8;
    // 0x80004128: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_8:
    // 0x8000412C: lw          $a0, 0x24($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X24);
    // 0x80004130: lw          $v1, 0x68($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X68);
    // 0x80004134: lw          $a1, 0x24($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X24);
    // 0x80004138: subu        $a0, $a0, $v1
    ctx->r4 = SUB32(ctx->r4, ctx->r3);
    // 0x8000413C: lw          $v1, 0x60($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X60);
    // 0x80004140: sltiu       $v0, $v0, 0x2
    ctx->r2 = ctx->r2 < 0X2 ? 1 : 0;
    // 0x80004144: sw          $a1, 0x68($s0)
    MEM_W(0X68, ctx->r16) = ctx->r5;
    // 0x80004148: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x8000414C: beq         $v0, $zero, L_80004280
    if (ctx->r2 == 0) {
        // 0x80004150: sw          $v1, 0x60($s0)
        MEM_W(0X60, ctx->r16) = ctx->r3;
            goto L_80004280;
    }
    // 0x80004150: sw          $v1, 0x60($s0)
    MEM_W(0X60, ctx->r16) = ctx->r3;
    // 0x80004154: lw          $v0, 0x14($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X14);
    // 0x80004158: bne         $v0, $zero, L_80004184
    if (ctx->r2 != 0) {
        // 0x8000415C: nop
    
            goto L_80004184;
    }
    // 0x8000415C: nop

    // 0x80004160: lw          $v0, 0x20($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X20);
    // 0x80004164: beq         $v0, $zero, L_80004178
    if (ctx->r2 == 0) {
        // 0x80004168: nop
    
            goto L_80004178;
    }
    // 0x80004168: nop

    // 0x8000416C: lhu         $v0, 0x8($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X8);
    // 0x80004170: ori         $v0, $v0, 0x800
    ctx->r2 = ctx->r2 | 0X800;
    // 0x80004174: sh          $v0, 0x8($s0)
    MEM_H(0X8, ctx->r16) = ctx->r2;
L_80004178:
    // 0x80004178: lhu         $v0, 0x8($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X8);
    // 0x8000417C: andi        $v0, $v0, 0xDFFF
    ctx->r2 = ctx->r2 & 0XDFFF;
    // 0x80004180: sh          $v0, 0x8($s0)
    MEM_H(0X8, ctx->r16) = ctx->r2;
L_80004184:
    // 0x80004184: lw          $v0, 0x20($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X20);
    // 0x80004188: bne         $v0, $zero, L_800041A4
    if (ctx->r2 != 0) {
        // 0x8000418C: nop
    
            goto L_800041A4;
    }
    // 0x8000418C: nop

    // 0x80004190: lw          $v0, 0x4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4);
    // 0x80004194: lw          $v1, 0x64($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X64);
    // 0x80004198: lw          $v0, 0x24($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X24);
    // 0x8000419C: sw          $v1, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r3;
    // 0x800041A0: sw          $v0, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->r2;
L_800041A4:
    // 0x800041A4: lw          $v0, 0x60($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X60);
    // 0x800041A8: sltu        $v0, $v0, $s1
    ctx->r2 = ctx->r2 < ctx->r17 ? 1 : 0;
    // 0x800041AC: bnel        $v0, $zero, L_80004344
    if (ctx->r2 != 0) {
        // 0x800041B0: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_80004344;
    }
    goto skip_1;
    // 0x800041B0: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    skip_1:
    // 0x800041B4: lhu         $v0, 0x8($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X8);
    // 0x800041B8: j           L_8000433C
    // 0x800041BC: ori         $v0, $v0, 0x200
    ctx->r2 = ctx->r2 | 0X200;
        goto L_8000433C;
    // 0x800041BC: ori         $v0, $v0, 0x200
    ctx->r2 = ctx->r2 | 0X200;
L_800041C0:
    // 0x800041C0: andi        $v0, $a0, 0x200
    ctx->r2 = ctx->r4 & 0X200;
    // 0x800041C4: beq         $v0, $zero, L_800041DC
    if (ctx->r2 == 0) {
        // 0x800041C8: andi        $v1, $a0, 0xFDFF
        ctx->r3 = ctx->r4 & 0XFDFF;
            goto L_800041DC;
    }
    // 0x800041C8: andi        $v1, $a0, 0xFDFF
    ctx->r3 = ctx->r4 & 0XFDFF;
    // 0x800041CC: lw          $v0, 0x4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4);
    // 0x800041D0: sh          $v1, 0x8($s0)
    MEM_H(0X8, ctx->r16) = ctx->r3;
    // 0x800041D4: lw          $v0, 0x24($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X24);
    // 0x800041D8: sw          $v0, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->r2;
L_800041DC:
    // 0x800041DC: lw          $v0, 0x20($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X20);
    // 0x800041E0: bne         $v0, $zero, L_80004200
    if (ctx->r2 != 0) {
        // 0x800041E4: addiu       $s1, $s0, 0x10
        ctx->r17 = ADD32(ctx->r16, 0X10);
            goto L_80004200;
    }
    // 0x800041E4: addiu       $s1, $s0, 0x10
    ctx->r17 = ADD32(ctx->r16, 0X10);
    // 0x800041E8: lw          $v1, 0x6C($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X6C);
    // 0x800041EC: sltiu       $v0, $v1, 0x1001
    ctx->r2 = ctx->r3 < 0X1001 ? 1 : 0;
    // 0x800041F0: beql        $v0, $zero, L_800041F8
    if (ctx->r2 == 0) {
        // 0x800041F4: addiu       $v1, $zero, 0x1000
        ctx->r3 = ADD32(0, 0X1000);
            goto L_800041F8;
    }
    goto skip_2;
    // 0x800041F4: addiu       $v1, $zero, 0x1000
    ctx->r3 = ADD32(0, 0X1000);
    skip_2:
L_800041F8:
    // 0x800041F8: sw          $v1, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r3;
    // 0x800041FC: addiu       $s1, $s0, 0x10
    ctx->r17 = ADD32(ctx->r16, 0X10);
L_80004200:
    // 0x80004200: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x80004204: jal         0x80026EA8
    // 0x80004208: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    inflate_recomp(rdram, ctx);
        goto after_9;
    // 0x80004208: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_9:
    // 0x8000420C: lw          $a0, 0x24($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X24);
    // 0x80004210: lw          $v1, 0x68($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X68);
    // 0x80004214: lw          $a1, 0x24($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X24);
    // 0x80004218: lw          $a2, 0x68($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X68);
    // 0x8000421C: subu        $a0, $a0, $v1
    ctx->r4 = SUB32(ctx->r4, ctx->r3);
    // 0x80004220: lw          $v1, 0x6C($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X6C);
    // 0x80004224: subu        $a1, $a1, $a2
    ctx->r5 = SUB32(ctx->r5, ctx->r6);
    // 0x80004228: subu        $v1, $v1, $a0
    ctx->r3 = SUB32(ctx->r3, ctx->r4);
    // 0x8000422C: sw          $v1, 0x6C($s0)
    MEM_W(0X6C, ctx->r16) = ctx->r3;
    // 0x80004230: lw          $v1, 0x60($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X60);
    // 0x80004234: lw          $a0, 0x24($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X24);
    // 0x80004238: addu        $v1, $v1, $a1
    ctx->r3 = ADD32(ctx->r3, ctx->r5);
    // 0x8000423C: sw          $v1, 0x60($s0)
    MEM_W(0X60, ctx->r16) = ctx->r3;
    // 0x80004240: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x80004244: sltiu       $v0, $v1, 0x2
    ctx->r2 = ctx->r3 < 0X2 ? 1 : 0;
    // 0x80004248: beq         $v0, $zero, L_80004280
    if (ctx->r2 == 0) {
        // 0x8000424C: sw          $a0, 0x68($s0)
        MEM_W(0X68, ctx->r16) = ctx->r4;
            goto L_80004280;
    }
    // 0x8000424C: sw          $a0, 0x68($s0)
    MEM_W(0X68, ctx->r16) = ctx->r4;
    // 0x80004250: lw          $v0, 0x14($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X14);
    // 0x80004254: bne         $v0, $zero, L_80004268
    if (ctx->r2 != 0) {
        // 0x80004258: nop
    
            goto L_80004268;
    }
    // 0x80004258: nop

    // 0x8000425C: lhu         $v0, 0x8($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X8);
    // 0x80004260: andi        $v0, $v0, 0xDFFF
    ctx->r2 = ctx->r2 & 0XDFFF;
    // 0x80004264: sh          $v0, 0x8($s0)
    MEM_H(0X8, ctx->r16) = ctx->r2;
L_80004268:
    // 0x80004268: beq         $v1, $zero, L_80004344
    if (ctx->r3 == 0) {
        // 0x8000426C: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_80004344;
    }
    // 0x8000426C: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x80004270: jal         0x80026C04
    // 0x80004274: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    inflateEnd(rdram, ctx);
        goto after_10;
    // 0x80004274: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_10:
    // 0x80004278: j           L_80004344
    // 0x8000427C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80004344;
    // 0x8000427C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80004280:
    // 0x80004280: lhu         $v1, 0x8($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X8);
    // 0x80004284: andi        $v0, $v1, 0x8000
    ctx->r2 = ctx->r3 & 0X8000;
    // 0x80004288: bne         $v0, $zero, L_80004314
    if (ctx->r2 != 0) {
        // 0x8000428C: ori         $v0, $v1, 0x8000
        ctx->r2 = ctx->r3 | 0X8000;
            goto L_80004314;
    }
    // 0x8000428C: ori         $v0, $v1, 0x8000
    ctx->r2 = ctx->r3 | 0X8000;
    // 0x80004290: lw          $a0, 0x58($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X58);
    // 0x80004294: sh          $v0, 0x8($s0)
    MEM_H(0X8, ctx->r16) = ctx->r2;
    // 0x80004298: sltiu       $v0, $a0, 0x1000
    ctx->r2 = ctx->r4 < 0X1000 ? 1 : 0;
    // 0x8000429C: bnel        $v0, $zero, L_800042AC
    if (ctx->r2 != 0) {
        // 0x800042A0: sw          $a0, 0x5C($s0)
        MEM_W(0X5C, ctx->r16) = ctx->r4;
            goto L_800042AC;
    }
    goto skip_3;
    // 0x800042A0: sw          $a0, 0x5C($s0)
    MEM_W(0X5C, ctx->r16) = ctx->r4;
    skip_3:
    // 0x800042A4: addiu       $v0, $zero, 0x1000
    ctx->r2 = ADD32(0, 0X1000);
    // 0x800042A8: sw          $v0, 0x5C($s0)
    MEM_W(0X5C, ctx->r16) = ctx->r2;
L_800042AC:
    // 0x800042AC: lw          $a1, 0x48($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X48);
    // 0x800042B0: lw          $v0, 0x50($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X50);
    // 0x800042B4: lw          $a0, 0x54($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X54);
    // 0x800042B8: lw          $a2, 0x5C($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X5C);
    // 0x800042BC: jal         0x80003480
    // 0x800042C0: addu        $a0, $v0, $a0
    ctx->r4 = ADD32(ctx->r2, ctx->r4);
    func_80003480(rdram, ctx);
        goto after_11;
    // 0x800042C0: addu        $a0, $v0, $a0
    ctx->r4 = ADD32(ctx->r2, ctx->r4);
    after_11:
    // 0x800042C4: lw          $v1, 0x58($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X58);
    // 0x800042C8: lw          $a0, 0x5C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X5C);
    // 0x800042CC: sw          $v0, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r2;
    // 0x800042D0: subu        $v1, $v1, $a0
    ctx->r3 = SUB32(ctx->r3, ctx->r4);
    // 0x800042D4: bne         $v1, $zero, L_800042F0
    if (ctx->r3 != 0) {
        // 0x800042D8: sw          $v1, 0x58($s0)
        MEM_W(0X58, ctx->r16) = ctx->r3;
            goto L_800042F0;
    }
    // 0x800042D8: sw          $v1, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->r3;
    // 0x800042DC: lbu         $v0, 0x70($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X70);
    // 0x800042E0: beq         $v0, $zero, L_800042F0
    if (ctx->r2 == 0) {
        // 0x800042E4: addu        $v0, $a0, $zero
        ctx->r2 = ADD32(ctx->r4, 0);
            goto L_800042F0;
    }
    // 0x800042E4: addu        $v0, $a0, $zero
    ctx->r2 = ADD32(ctx->r4, 0);
    // 0x800042E8: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x800042EC: sw          $v0, 0x5C($s0)
    MEM_W(0X5C, ctx->r16) = ctx->r2;
L_800042F0:
    // 0x800042F0: lw          $v0, 0x54($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X54);
    // 0x800042F4: lw          $v1, 0x5C($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X5C);
    // 0x800042F8: lw          $a0, 0x48($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X48);
    // 0x800042FC: addu        $a1, $v1, $zero
    ctx->r5 = ADD32(ctx->r3, 0);
    // 0x80004300: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80004304: sw          $v0, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->r2;
    // 0x80004308: sw          $a0, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->r4;
    // 0x8000430C: j           L_80004340
    // 0x80004310: sw          $a1, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r5;
        goto L_80004340;
    // 0x80004310: sw          $a1, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r5;
L_80004314:
    // 0x80004314: lw          $a0, 0xC($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XC);
    // 0x80004318: jal         0x80003824
    // 0x8000431C: nop

    func_80003824(rdram, ctx);
        goto after_12;
    // 0x8000431C: nop

    after_12:
    // 0x80004320: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x80004324: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80004328: bne         $v0, $v1, L_80004344
    if (ctx->r2 != ctx->r3) {
        // 0x8000432C: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_80004344;
    }
    // 0x8000432C: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x80004330: lhu         $v0, 0x8($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X8);
    // 0x80004334: andi        $v0, $v0, 0x7FFF
    ctx->r2 = ctx->r2 & 0X7FFF;
    // 0x80004338: ori         $v0, $v0, 0x2000
    ctx->r2 = ctx->r2 | 0X2000;
L_8000433C:
    // 0x8000433C: sh          $v0, 0x8($s0)
    MEM_H(0X8, ctx->r16) = ctx->r2;
L_80004340:
    // 0x80004340: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_80004344:
    // 0x80004344: lw          $ra, 0x20($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X20);
    // 0x80004348: lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X1C);
    // 0x8000434C: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x80004350: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x80004354: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80004358: jr          $ra
    // 0x8000435C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8000435C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_80004360(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80004360: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80004364: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x80004368: addu        $s7, $a0, $zero
    ctx->r23 = ADD32(ctx->r4, 0);
    // 0x8000436C: addiu       $v1, $zero, 0x7
    ctx->r3 = ADD32(0, 0X7);
    // 0x80004370: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80004374: addiu       $v0, $v0, 0xD60
    ctx->r2 = ADD32(ctx->r2, 0XD60);
    // 0x80004378: addiu       $v0, $v0, 0x32C
    ctx->r2 = ADD32(ctx->r2, 0X32C);
    // 0x8000437C: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80004380: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x80004384: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x80004388: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x8000438C: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80004390: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80004394: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80004398: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8000439C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
L_800043A0:
    // 0x800043A0: sb          $zero, 0x1($v0)
    MEM_B(0X1, ctx->r2) = 0;
    // 0x800043A4: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x800043A8: bgez        $v1, L_800043A0
    if (SIGNED(ctx->r3) >= 0) {
        // 0x800043AC: addiu       $v0, $v0, -0x74
        ctx->r2 = ADD32(ctx->r2, -0X74);
            goto L_800043A0;
    }
    // 0x800043AC: addiu       $v0, $v0, -0x74
    ctx->r2 = ADD32(ctx->r2, -0X74);
    // 0x800043B0: addu        $s2, $zero, $zero
    ctx->r18 = ADD32(0, 0);
    // 0x800043B4: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800043B8: addu        $s3, $v0, $zero
    ctx->r19 = ADD32(ctx->r2, 0);
    // 0x800043BC: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800043C0: addiu       $s5, $v0, 0xD60
    ctx->r21 = ADD32(ctx->r2, 0XD60);
    // 0x800043C4: addiu       $s4, $zero, 0x1
    ctx->r20 = ADD32(0, 0X1);
    // 0x800043C8: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800043CC: addiu       $fp, $v0, 0xBC0
    ctx->r30 = ADD32(ctx->r2, 0XBC0);
    // 0x800043D0: lui         $s6, 0x8011
    ctx->r22 = S32(0X8011 << 16);
    // 0x800043D4: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800043D8: sw          $zero, 0x1244($v0)
    MEM_W(0X1244, ctx->r2) = 0;
    // 0x800043DC: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800043E0: sw          $zero, 0x1248($v0)
    MEM_W(0X1248, ctx->r2) = 0;
    // 0x800043E4: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800043E8: addiu       $v1, $zero, 0x8
    ctx->r3 = ADD32(0, 0X8);
    // 0x800043EC: sw          $v1, 0x1250($v0)
    MEM_W(0X1250, ctx->r2) = ctx->r3;
    // 0x800043F0: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800043F4: sw          $v1, 0x124C($v0)
    MEM_W(0X124C, ctx->r2) = ctx->r3;
    // 0x800043F8: sw          $zero, 0x1240($s3)
    MEM_W(0X1240, ctx->r19) = 0;
    // 0x800043FC: andi        $v0, $s2, 0xFF
    ctx->r2 = ctx->r18 & 0XFF;
L_80004400:
    // 0x80004400: bne         $v0, $zero, L_80004424
    if (ctx->r2 != 0) {
        // 0x80004404: nop
    
            goto L_80004424;
    }
    // 0x80004404: nop

    // 0x80004408: lw          $a0, 0x0($s7)
    ctx->r4 = MEM_W(ctx->r23, 0X0);
    // 0x8000440C: jal         0x80006F24
    // 0x80004410: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
    func_80006F24(rdram, ctx);
        goto after_0;
    // 0x80004410: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
    after_0:
    // 0x80004414: jal         0x80003BCC
    // 0x80004418: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    func_80003BCC(rdram, ctx);
        goto after_1;
    // 0x80004418: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    after_1:
    // 0x8000441C: j           L_80004400
    // 0x80004420: andi        $v0, $s2, 0xFF
    ctx->r2 = ctx->r18 & 0XFF;
        goto L_80004400;
    // 0x80004420: andi        $v0, $s2, 0xFF
    ctx->r2 = ctx->r18 & 0XFF;
L_80004424:
    // 0x80004424: lw          $a0, 0x0($s7)
    ctx->r4 = MEM_W(ctx->r23, 0X0);
    // 0x80004428: jal         0x80006EC4
    // 0x8000442C: nop

    func_80006EC4(rdram, ctx);
        goto after_2;
    // 0x8000442C: nop

    after_2:
    // 0x80004430: beq         $v0, $zero, L_80004444
    if (ctx->r2 == 0) {
        // 0x80004434: nop
    
            goto L_80004444;
    }
    // 0x80004434: nop

    // 0x80004438: jal         0x80003BCC
    // 0x8000443C: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    func_80003BCC(rdram, ctx);
        goto after_3;
    // 0x8000443C: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    after_3:
    // 0x80004440: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
L_80004444:
    // 0x80004444: lw          $v0, 0x1240($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X1240);
    // 0x80004448: sll         $v1, $v0, 3
    ctx->r3 = S32(ctx->r2 << 3);
    // 0x8000444C: subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // 0x80004450: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x80004454: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80004458: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x8000445C: addu        $s0, $v1, $s5
    ctx->r16 = ADD32(ctx->r3, ctx->r21);
    // 0x80004460: lbu         $v0, 0x1($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X1);
    // 0x80004464: bne         $v0, $s4, L_800045D4
    if (ctx->r2 != ctx->r20) {
        // 0x80004468: nop
    
            goto L_800045D4;
    }
    // 0x80004468: nop

    // 0x8000446C: lbu         $v1, 0x0($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X0);
    // 0x80004470: beq         $v1, $s4, L_800044CC
    if (ctx->r3 == ctx->r20) {
        // 0x80004474: slti        $v0, $v1, 0x2
        ctx->r2 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
            goto L_800044CC;
    }
    // 0x80004474: slti        $v0, $v1, 0x2
    ctx->r2 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
    // 0x80004478: beq         $v0, $zero, L_80004490
    if (ctx->r2 == 0) {
        // 0x8000447C: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_80004490;
    }
    // 0x8000447C: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x80004480: beq         $v1, $zero, L_800044A0
    if (ctx->r3 == 0) {
        // 0x80004484: andi        $v0, $s1, 0xFF
        ctx->r2 = ctx->r17 & 0XFF;
            goto L_800044A0;
    }
    // 0x80004484: andi        $v0, $s1, 0xFF
    ctx->r2 = ctx->r17 & 0XFF;
    // 0x80004488: j           L_80004528
    // 0x8000448C: nop

        goto L_80004528;
    // 0x8000448C: nop

L_80004490:
    // 0x80004490: beq         $v1, $v0, L_800044F0
    if (ctx->r3 == ctx->r2) {
        // 0x80004494: andi        $v0, $s1, 0xFF
        ctx->r2 = ctx->r17 & 0XFF;
            goto L_800044F0;
    }
    // 0x80004494: andi        $v0, $s1, 0xFF
    ctx->r2 = ctx->r17 & 0XFF;
    // 0x80004498: j           L_80004528
    // 0x8000449C: nop

        goto L_80004528;
    // 0x8000449C: nop

L_800044A0:
    // 0x800044A0: jal         0x80003C98
    // 0x800044A4: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    func_80003C98(rdram, ctx);
        goto after_4;
    // 0x800044A4: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    after_4:
    // 0x800044A8: addu        $s1, $v0, $zero
    ctx->r17 = ADD32(ctx->r2, 0);
    // 0x800044AC: andi        $v0, $s1, 0xFF
    ctx->r2 = ctx->r17 & 0XFF;
    // 0x800044B0: bne         $v0, $s4, L_800045AC
    if (ctx->r2 != ctx->r20) {
        // 0x800044B4: nop
    
            goto L_800045AC;
    }
    // 0x800044B4: nop

    // 0x800044B8: lw          $v0, 0x4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4);
    // 0x800044BC: lw          $v1, 0x10($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X10);
    // 0x800044C0: lw          $v0, 0x10($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X10);
    // 0x800044C4: j           L_80004524
    // 0x800044C8: sw          $v0, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r2;
        goto L_80004524;
    // 0x800044C8: sw          $v0, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r2;
L_800044CC:
    // 0x800044CC: lw          $v0, 0x4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4);
    // 0x800044D0: lw          $v1, 0x18($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X18);
    // 0x800044D4: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
    // 0x800044D8: sllv        $v0, $v1, $s1
    ctx->r2 = S32(ctx->r3 << (ctx->r17 & 31));
    // 0x800044DC: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800044E0: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x800044E4: addu        $v0, $v0, $fp
    ctx->r2 = ADD32(ctx->r2, ctx->r30);
    // 0x800044E8: j           L_80004524
    // 0x800044EC: sb          $zero, 0x0($v0)
    MEM_B(0X0, ctx->r2) = 0;
        goto L_80004524;
    // 0x800044EC: sb          $zero, 0x0($v0)
    MEM_B(0X0, ctx->r2) = 0;
L_800044F0:
    // 0x800044F0: jal         0x80003D64
    // 0x800044F4: addiu       $a0, $sp, 0x14
    ctx->r4 = ADD32(ctx->r29, 0X14);
    func_80003D64(rdram, ctx);
        goto after_5;
    // 0x800044F4: addiu       $a0, $sp, 0x14
    ctx->r4 = ADD32(ctx->r29, 0X14);
    after_5:
    // 0x800044F8: addu        $s1, $v0, $zero
    ctx->r17 = ADD32(ctx->r2, 0);
    // 0x800044FC: andi        $v0, $s1, 0xFF
    ctx->r2 = ctx->r17 & 0XFF;
    // 0x80004500: bne         $v0, $s4, L_800045AC
    if (ctx->r2 != ctx->r20) {
        // 0x80004504: nop
    
            goto L_800045AC;
    }
    // 0x80004504: nop

    // 0x80004508: lw          $a0, 0x48($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X48);
    // 0x8000450C: jal         0x80001C98
    // 0x80004510: nop

    rs_free(rdram, ctx);
        goto after_6;
    // 0x80004510: nop

    after_6:
    // 0x80004514: lw          $v0, 0x4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4);
    // 0x80004518: lw          $v1, 0x10($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X10);
    // 0x8000451C: lbu         $v0, 0x14($sp)
    ctx->r2 = MEM_BU(ctx->r29, 0X14);
    // 0x80004520: sw          $v0, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r2;
L_80004524:
    // 0x80004524: andi        $v0, $s1, 0xFF
    ctx->r2 = ctx->r17 & 0XFF;
L_80004528:
    // 0x80004528: bne         $v0, $s4, L_800045AC
    if (ctx->r2 != ctx->r20) {
        // 0x8000452C: nop
    
            goto L_800045AC;
    }
    // 0x8000452C: nop

    // 0x80004530: lw          $v0, 0x4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4);
    // 0x80004534: lw          $a0, 0xD54($s6)
    ctx->r4 = MEM_W(ctx->r22, 0XD54);
    // 0x80004538: lw          $a1, 0x14($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X14);
    // 0x8000453C: lw          $a2, 0x10($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X10);
    // 0x80004540: jal         0x80006F78
    // 0x80004544: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_80006F78(rdram, ctx);
        goto after_7;
    // 0x80004544: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_7:
    // 0x80004548: lw          $v1, 0x1240($s3)
    ctx->r3 = MEM_W(ctx->r19, 0X1240);
    // 0x8000454C: sll         $v0, $v1, 3
    ctx->r2 = S32(ctx->r3 << 3);
    // 0x80004550: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x80004554: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80004558: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8000455C: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80004560: addu        $v0, $v0, $s5
    ctx->r2 = ADD32(ctx->r2, ctx->r21);
    // 0x80004564: sb          $zero, 0x1($v0)
    MEM_B(0X1, ctx->r2) = 0;
    // 0x80004568: lw          $a0, 0x1240($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X1240);
    // 0x8000456C: addiu       $v1, $a0, 0x1
    ctx->r3 = ADD32(ctx->r4, 0X1);
    // 0x80004570: bgez        $v1, L_8000457C
    if (SIGNED(ctx->r3) >= 0) {
        // 0x80004574: addu        $v0, $v1, $zero
        ctx->r2 = ADD32(ctx->r3, 0);
            goto L_8000457C;
    }
    // 0x80004574: addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
    // 0x80004578: addiu       $v0, $a0, 0x8
    ctx->r2 = ADD32(ctx->r4, 0X8);
L_8000457C:
    // 0x8000457C: sra         $v0, $v0, 3
    ctx->r2 = S32(SIGNED(ctx->r2) >> 3);
    // 0x80004580: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x80004584: subu        $v0, $v1, $v0
    ctx->r2 = SUB32(ctx->r3, ctx->r2);
    // 0x80004588: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x8000458C: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x80004590: sw          $v0, 0x1240($s3)
    MEM_W(0X1240, ctx->r19) = ctx->r2;
    // 0x80004594: lw          $v0, 0x1250($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1250);
    // 0x80004598: lw          $v1, 0x124C($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X124C);
    // 0x8000459C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800045A0: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800045A4: sw          $v0, 0x1250($a0)
    MEM_W(0X1250, ctx->r4) = ctx->r2;
    // 0x800045A8: sw          $v1, 0x124C($a1)
    MEM_W(0X124C, ctx->r5) = ctx->r3;
L_800045AC:
    // 0x800045AC: lw          $v0, 0x1240($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X1240);
    // 0x800045B0: sll         $v1, $v0, 3
    ctx->r3 = S32(ctx->r2 << 3);
    // 0x800045B4: subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // 0x800045B8: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x800045BC: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800045C0: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x800045C4: addu        $v1, $v1, $s5
    ctx->r3 = ADD32(ctx->r3, ctx->r21);
    // 0x800045C8: lbu         $v0, 0x1($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X1);
    // 0x800045CC: beql        $v0, $zero, L_800045D4
    if (ctx->r2 == 0) {
        // 0x800045D0: addu        $s2, $zero, $zero
        ctx->r18 = ADD32(0, 0);
            goto L_800045D4;
    }
    goto skip_0;
    // 0x800045D0: addu        $s2, $zero, $zero
    ctx->r18 = ADD32(0, 0);
    skip_0:
L_800045D4:
    // 0x800045D4: lw          $a0, 0xD54($s6)
    ctx->r4 = MEM_W(ctx->r22, 0XD54);
    // 0x800045D8: jal         0x800072AC
    // 0x800045DC: nop

    func_800072AC(rdram, ctx);
        goto after_8;
    // 0x800045DC: nop

    after_8:
    // 0x800045E0: j           L_80004400
    // 0x800045E4: andi        $v0, $s2, 0xFF
    ctx->r2 = ctx->r18 & 0XFF;
        goto L_80004400;
    // 0x800045E4: andi        $v0, $s2, 0xFF
    ctx->r2 = ctx->r18 & 0XFF;
;}
RECOMP_FUNC void func_800045E8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800045E8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800045EC: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // 0x800045F0: addu        $s3, $a0, $zero
    ctx->r19 = ADD32(ctx->r4, 0);
    // 0x800045F4: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x800045F8: addiu       $v0, $zero, 0x4000
    ctx->r2 = ADD32(0, 0X4000);
    // 0x800045FC: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80004600: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // 0x80004604: sw          $v0, 0x1254($v1)
    MEM_W(0X1254, ctx->r3) = ctx->r2;
    // 0x80004608: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x8000460C: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x80004610: addiu       $s2, $v0, 0x8A0
    ctx->r18 = ADD32(ctx->r2, 0X8A0);
    // 0x80004614: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80004618: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x8000461C: addiu       $s1, $v0, 0x8C0
    ctx->r17 = ADD32(ctx->r2, 0X8C0);
    // 0x80004620: sw          $ra, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r31;
L_80004624:
    // 0x80004624: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x80004628: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    // 0x8000462C: jal         0x8002B300
    // 0x80004630: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_0;
    // 0x80004630: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x80004634: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x80004638: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8000463C: slti        $v0, $s0, 0x8
    ctx->r2 = SIGNED(ctx->r16) < 0X8 ? 1 : 0;
    // 0x80004640: bne         $v0, $zero, L_80004624
    if (ctx->r2 != 0) {
        // 0x80004644: addiu       $s1, $s1, 0x18
        ctx->r17 = ADD32(ctx->r17, 0X18);
            goto L_80004624;
    }
    // 0x80004644: addiu       $s1, $s1, 0x18
    ctx->r17 = ADD32(ctx->r17, 0X18);
    // 0x80004648: lui         $s0, 0x8011
    ctx->r16 = S32(0X8011 << 16);
    // 0x8000464C: addiu       $s0, $s0, 0x990
    ctx->r16 = ADD32(ctx->r16, 0X990);
    // 0x80004650: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80004654: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x80004658: addiu       $a1, $a1, 0x980
    ctx->r5 = ADD32(ctx->r5, 0X980);
    // 0x8000465C: jal         0x8002B300
    // 0x80004660: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_1;
    // 0x80004660: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_1:
    // 0x80004664: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80004668: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8000466C: jal         0x80033410
    // 0x80004670: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    osSendMesg_recomp(rdram, ctx);
        goto after_2;
    // 0x80004670: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    after_2:
    // 0x80004674: addiu       $a0, $zero, 0x96
    ctx->r4 = ADD32(0, 0X96);
    // 0x80004678: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x8000467C: addiu       $a1, $a1, 0x7C0
    ctx->r5 = ADD32(ctx->r5, 0X7C0);
    // 0x80004680: lui         $a2, 0x8011
    ctx->r6 = S32(0X8011 << 16);
    // 0x80004684: addiu       $a2, $a2, 0x7A0
    ctx->r6 = ADD32(ctx->r6, 0X7A0);
    // 0x80004688: jal         0x80032560
    // 0x8000468C: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    osCreatePiManager_recomp(rdram, ctx);
        goto after_3;
    // 0x8000468C: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    after_3:
    // 0x80004690: addiu       $s0, $zero, 0x3
    ctx->r16 = ADD32(0, 0X3);
    // 0x80004694: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80004698: addiu       $v0, $v0, 0xA80
    ctx->r2 = ADD32(ctx->r2, 0XA80);
    // 0x8000469C: addiu       $v0, $v0, 0xF0
    ctx->r2 = ADD32(ctx->r2, 0XF0);
L_800046A0:
    // 0x800046A0: sb          $zero, 0x4E($v0)
    MEM_B(0X4E, ctx->r2) = 0;
    // 0x800046A4: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    // 0x800046A8: bgez        $s0, L_800046A0
    if (SIGNED(ctx->r16) >= 0) {
        // 0x800046AC: addiu       $v0, $v0, -0x50
        ctx->r2 = ADD32(ctx->r2, -0X50);
            goto L_800046A0;
    }
    // 0x800046AC: addiu       $v0, $v0, -0x50
    ctx->r2 = ADD32(ctx->r2, -0X50);
    // 0x800046B0: addiu       $s0, $zero, 0xF
    ctx->r16 = ADD32(0, 0XF);
    // 0x800046B4: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800046B8: addiu       $v0, $v0, 0xBC0
    ctx->r2 = ADD32(ctx->r2, 0XBC0);
    // 0x800046BC: addiu       $v0, $v0, 0x168
    ctx->r2 = ADD32(ctx->r2, 0X168);
L_800046C0:
    // 0x800046C0: sb          $zero, 0x0($v0)
    MEM_B(0X0, ctx->r2) = 0;
    // 0x800046C4: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    // 0x800046C8: bgez        $s0, L_800046C0
    if (SIGNED(ctx->r16) >= 0) {
        // 0x800046CC: addiu       $v0, $v0, -0x18
        ctx->r2 = ADD32(ctx->r2, -0X18);
            goto L_800046C0;
    }
    // 0x800046CC: addiu       $v0, $v0, -0x18
    ctx->r2 = ADD32(ctx->r2, -0X18);
    // 0x800046D0: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800046D4: lw          $v0, -0x350($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X350);
    // 0x800046D8: lbu         $v0, 0x31($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X31);
    // 0x800046DC: beq         $v0, $zero, L_8000470C
    if (ctx->r2 == 0) {
        // 0x800046E0: lui         $v0, 0x8011
        ctx->r2 = S32(0X8011 << 16);
            goto L_8000470C;
    }
    // 0x800046E0: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800046E4: sw          $s3, 0xD4C($v0)
    MEM_W(0XD4C, ctx->r2) = ctx->r19;
    // 0x800046E8: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800046EC: beq         $s3, $zero, L_80004720
    if (ctx->r19 == 0) {
        // 0x800046F0: sw          $s3, 0xD48($v0)
        MEM_W(0XD48, ctx->r2) = ctx->r19;
            goto L_80004720;
    }
    // 0x800046F0: sw          $s3, 0xD48($v0)
    MEM_W(0XD48, ctx->r2) = ctx->r19;
    // 0x800046F4: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // 0x800046F8: jal         0x80001ACC
    // 0x800046FC: addiu       $a1, $zero, 0x81
    ctx->r5 = ADD32(0, 0X81);
    rs_malloc(rdram, ctx);
        goto after_4;
    // 0x800046FC: addiu       $a1, $zero, 0x81
    ctx->r5 = ADD32(0, 0X81);
    after_4:
    // 0x80004700: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x80004704: j           L_80004720
    // 0x80004708: sw          $v0, 0xD50($v1)
    MEM_W(0XD50, ctx->r3) = ctx->r2;
        goto L_80004720;
    // 0x80004708: sw          $v0, 0xD50($v1)
    MEM_W(0XD50, ctx->r3) = ctx->r2;
L_8000470C:
    // 0x8000470C: sw          $zero, 0xD4C($v0)
    MEM_W(0XD4C, ctx->r2) = 0;
    // 0x80004710: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80004714: sw          $zero, 0xD48($v0)
    MEM_W(0XD48, ctx->r2) = 0;
    // 0x80004718: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x8000471C: sw          $zero, 0xD50($v0)
    MEM_W(0XD50, ctx->r2) = 0;
L_80004720:
    // 0x80004720: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80004724: lw          $a0, 0xD50($v0)
    ctx->r4 = MEM_W(ctx->r2, 0XD50);
    // 0x80004728: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x8000472C: lw          $a1, 0xD48($v0)
    ctx->r5 = MEM_W(ctx->r2, 0XD48);
    // 0x80004730: jal         0x80005380
    // 0x80004734: nop

    func_80005380(rdram, ctx);
        goto after_5;
    // 0x80004734: nop

    after_5:
    // 0x80004738: lui         $v0, 0x0
    ctx->r2 = S32(0X0 << 16);
    // 0x8000473C: addiu       $s0, $v0, 0x40
    ctx->r16 = ADD32(ctx->r2, 0X40);
    // 0x80004740: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80004744: addiu       $a1, $zero, 0x81
    ctx->r5 = ADD32(0, 0X81);
    // 0x80004748: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x8000474C: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x80004750: sw          $zero, 0x9A8($v0)
    MEM_W(0X9A8, ctx->r2) = 0;
    // 0x80004754: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
    // 0x80004758: sw          $v0, 0x9AC($v1)
    MEM_W(0X9AC, ctx->r3) = ctx->r2;
    // 0x8000475C: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80004760: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x80004764: sb          $zero, 0xA70($v0)
    MEM_B(0XA70, ctx->r2) = 0;
    // 0x80004768: srl         $v0, $s0, 5
    ctx->r2 = S32(U32(ctx->r16) >> 5);
    // 0x8000476C: jal         0x80001ACC
    // 0x80004770: sw          $v0, 0xD40($v1)
    MEM_W(0XD40, ctx->r3) = ctx->r2;
    rs_malloc(rdram, ctx);
        goto after_6;
    // 0x80004770: sw          $v0, 0xD40($v1)
    MEM_W(0XD40, ctx->r3) = ctx->r2;
    after_6:
    // 0x80004774: lui         $a0, 0xB014
    ctx->r4 = S32(0XB014 << 16);
    // 0x80004778: addiu       $a0, $a0, 0x4340
    ctx->r4 = ADD32(ctx->r4, 0X4340);
    // 0x8000477C: addu        $a1, $v0, $zero
    ctx->r5 = ADD32(ctx->r2, 0);
    // 0x80004780: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    // 0x80004784: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80004788: jal         0x80003480
    // 0x8000478C: sw          $a1, 0xA74($v0)
    MEM_W(0XA74, ctx->r2) = ctx->r5;
    func_80003480(rdram, ctx);
        goto after_7;
    // 0x8000478C: sw          $a1, 0xA74($v0)
    MEM_W(0XA74, ctx->r2) = ctx->r5;
    after_7:
    // 0x80004790: jal         0x80003638
    // 0x80004794: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    func_80003638(rdram, ctx);
        goto after_8;
    // 0x80004794: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    after_8:
    // 0x80004798: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x8000479C: lui         $v0, 0xB014
    ctx->r2 = S32(0XB014 << 16);
    // 0x800047A0: addiu       $v0, $v0, 0x4380
    ctx->r2 = ADD32(ctx->r2, 0X4380);
    // 0x800047A4: jal         0x80005850
    // 0x800047A8: sw          $v0, 0xD44($v1)
    MEM_W(0XD44, ctx->r3) = ctx->r2;
    func_80005850(rdram, ctx);
        goto after_9;
    // 0x800047A8: sw          $v0, 0xD44($v1)
    MEM_W(0XD44, ctx->r3) = ctx->r2;
    after_9:
    // 0x800047AC: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    // 0x800047B0: addiu       $a1, $zero, 0x2000
    ctx->r5 = ADD32(0, 0X2000);
    // 0x800047B4: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    // 0x800047B8: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    // 0x800047BC: jal         0x80006C28
    // 0x800047C0: addiu       $a3, $a3, 0x4360
    ctx->r7 = ADD32(ctx->r7, 0X4360);
    func_80006C28(rdram, ctx);
        goto after_10;
    // 0x800047C0: addiu       $a3, $a3, 0x4360
    ctx->r7 = ADD32(ctx->r7, 0X4360);
    after_10:
    // 0x800047C4: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x800047C8: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800047CC: jal         0x80006D9C
    // 0x800047D0: sw          $a0, 0xD54($v0)
    MEM_W(0XD54, ctx->r2) = ctx->r4;
    func_80006D9C(rdram, ctx);
        goto after_11;
    // 0x800047D0: sw          $a0, 0xD54($v0)
    MEM_W(0XD54, ctx->r2) = ctx->r4;
    after_11:
    // 0x800047D4: lw          $ra, 0x20($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X20);
    // 0x800047D8: lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X1C);
    // 0x800047DC: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x800047E0: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x800047E4: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x800047E8: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x800047EC: jr          $ra
    // 0x800047F0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800047F0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_800047F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800047F4: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x800047F8: lw          $v0, 0xD40($v1)
    ctx->r2 = MEM_W(ctx->r3, 0XD40);
    // 0x800047FC: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80004800: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // 0x80004804: addu        $s3, $a0, $zero
    ctx->r19 = ADD32(ctx->r4, 0);
    // 0x80004808: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8000480C: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // 0x80004810: sw          $ra, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r31;
    // 0x80004814: sw          $s5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r21;
    // 0x80004818: sw          $s4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r20;
    // 0x8000481C: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x80004820: blez        $v0, L_80004860
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80004824: sw          $s1, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r17;
            goto L_80004860;
    }
    // 0x80004824: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x80004828: lui         $s2, 0x8011
    ctx->r18 = S32(0X8011 << 16);
    // 0x8000482C: addu        $s1, $v1, $zero
    ctx->r17 = ADD32(ctx->r3, 0);
    // 0x80004830: addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
L_80004834:
    // 0x80004834: lw          $v0, 0xA74($s2)
    ctx->r2 = MEM_W(ctx->r18, 0XA74);
    // 0x80004838: sll         $a0, $s0, 5
    ctx->r4 = S32(ctx->r16 << 5);
    // 0x8000483C: jal         0x800076F8
    // 0x80004840: addu        $a0, $v0, $a0
    ctx->r4 = ADD32(ctx->r2, ctx->r4);
    rs_strcmp(rdram, ctx);
        goto after_0;
    // 0x80004840: addu        $a0, $v0, $a0
    ctx->r4 = ADD32(ctx->r2, ctx->r4);
    after_0:
    // 0x80004844: beq         $v0, $zero, L_80004864
    if (ctx->r2 == 0) {
        // 0x80004848: addu        $s4, $zero, $zero
        ctx->r20 = ADD32(0, 0);
            goto L_80004864;
    }
    // 0x80004848: addu        $s4, $zero, $zero
    ctx->r20 = ADD32(0, 0);
    // 0x8000484C: lw          $v0, 0xD40($s1)
    ctx->r2 = MEM_W(ctx->r17, 0XD40);
    // 0x80004850: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80004854: slt         $v0, $s0, $v0
    ctx->r2 = SIGNED(ctx->r16) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80004858: bne         $v0, $zero, L_80004834
    if (ctx->r2 != 0) {
        // 0x8000485C: addu        $a1, $s3, $zero
        ctx->r5 = ADD32(ctx->r19, 0);
            goto L_80004834;
    }
    // 0x8000485C: addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
L_80004860:
    // 0x80004860: addu        $s4, $zero, $zero
    ctx->r20 = ADD32(0, 0);
L_80004864:
    // 0x80004864: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80004868: addiu       $s1, $v0, 0xA80
    ctx->r17 = ADD32(ctx->r2, 0XA80);
    // 0x8000486C: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x80004870: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80004874: lw          $v1, 0xA74($v0)
    ctx->r3 = MEM_W(ctx->r2, 0XA74);
    // 0x80004878: sll         $v0, $s0, 5
    ctx->r2 = S32(ctx->r16 << 5);
    // 0x8000487C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80004880: lw          $s5, 0x1C($v0)
    ctx->r21 = MEM_W(ctx->r2, 0X1C);
L_80004884:
    // 0x80004884: lbu         $v0, 0x4E($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X4E);
    // 0x80004888: beql        $v0, $zero, L_800048A4
    if (ctx->r2 == 0) {
        // 0x8000488C: addiu       $a0, $zero, 0x8
        ctx->r4 = ADD32(0, 0X8);
            goto L_800048A4;
    }
    goto skip_0;
    // 0x8000488C: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    skip_0:
    // 0x80004890: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x80004894: slti        $v0, $s4, 0x4
    ctx->r2 = SIGNED(ctx->r20) < 0X4 ? 1 : 0;
    // 0x80004898: bne         $v0, $zero, L_80004884
    if (ctx->r2 != 0) {
        // 0x8000489C: addiu       $a0, $a0, 0x50
        ctx->r4 = ADD32(ctx->r4, 0X50);
            goto L_80004884;
    }
    // 0x8000489C: addiu       $a0, $a0, 0x50
    ctx->r4 = ADD32(ctx->r4, 0X50);
    // 0x800048A0: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
L_800048A4:
    // 0x800048A4: jal         0x80001ACC
    // 0x800048A8: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    rs_malloc(rdram, ctx);
        goto after_1;
    // 0x800048A8: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    after_1:
    // 0x800048AC: addu        $s2, $v0, $zero
    ctx->r18 = ADD32(ctx->r2, 0);
    // 0x800048B0: sll         $v1, $s4, 2
    ctx->r3 = S32(ctx->r20 << 2);
    // 0x800048B4: addu        $v1, $v1, $s4
    ctx->r3 = ADD32(ctx->r3, ctx->r20);
    // 0x800048B8: sll         $v1, $v1, 4
    ctx->r3 = S32(ctx->r3 << 4);
    // 0x800048BC: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800048C0: lw          $a0, 0xA74($v0)
    ctx->r4 = MEM_W(ctx->r2, 0XA74);
    // 0x800048C4: sll         $v0, $s0, 5
    ctx->r2 = S32(ctx->r16 << 5);
    // 0x800048C8: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x800048CC: lw          $v0, 0x18($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X18);
    // 0x800048D0: bne         $v0, $zero, L_8000496C
    if (ctx->r2 != 0) {
        // 0x800048D4: addu        $s3, $v1, $s1
        ctx->r19 = ADD32(ctx->r3, ctx->r17);
            goto L_8000496C;
    }
    // 0x800048D4: addu        $s3, $v1, $s1
    ctx->r19 = ADD32(ctx->r3, ctx->r17);
    // 0x800048D8: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    // 0x800048DC: lui         $s1, 0x8011
    ctx->r17 = S32(0X8011 << 16);
    // 0x800048E0: lw          $a0, 0xD44($s1)
    ctx->r4 = MEM_W(ctx->r17, 0XD44);
    // 0x800048E4: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    // 0x800048E8: jal         0x80003480
    // 0x800048EC: addu        $a0, $a0, $s5
    ctx->r4 = ADD32(ctx->r4, ctx->r21);
    func_80003480(rdram, ctx);
        goto after_2;
    // 0x800048EC: addu        $a0, $a0, $s5
    ctx->r4 = ADD32(ctx->r4, ctx->r21);
    after_2:
    // 0x800048F0: jal         0x80003638
    // 0x800048F4: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    func_80003638(rdram, ctx);
        goto after_3;
    // 0x800048F4: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    after_3:
    // 0x800048F8: lui         $v0, 0x7FFF
    ctx->r2 = S32(0X7FFF << 16);
    // 0x800048FC: ori         $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 | 0XFFFF;
    // 0x80004900: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x80004904: lw          $s0, 0x4($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X4);
    // 0x80004908: lw          $s2, 0x0($a0)
    ctx->r18 = MEM_W(ctx->r4, 0X0);
    // 0x8000490C: jal         0x80001C98
    // 0x80004910: and         $s0, $s0, $v0
    ctx->r16 = ctx->r16 & ctx->r2;
    rs_free(rdram, ctx);
        goto after_4;
    // 0x80004910: and         $s0, $s0, $v0
    ctx->r16 = ctx->r16 & ctx->r2;
    after_4:
    // 0x80004914: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80004918: jal         0x80001ACC
    // 0x8000491C: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    rs_malloc(rdram, ctx);
        goto after_5;
    // 0x8000491C: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    after_5:
    // 0x80004920: sw          $v0, 0x40($s3)
    MEM_W(0X40, ctx->r19) = ctx->r2;
    // 0x80004924: addu        $a1, $v0, $zero
    ctx->r5 = ADD32(ctx->r2, 0);
    // 0x80004928: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8000492C: sb          $v0, 0x4E($s3)
    MEM_B(0X4E, ctx->r19) = ctx->r2;
    // 0x80004930: lw          $v1, 0xD44($s1)
    ctx->r3 = MEM_W(ctx->r17, 0XD44);
    // 0x80004934: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    // 0x80004938: sb          $zero, 0x0($s3)
    MEM_B(0X0, ctx->r19) = 0;
    // 0x8000493C: sb          $zero, 0x20($s3)
    MEM_B(0X20, ctx->r19) = 0;
    // 0x80004940: lw          $a0, 0xD44($s1)
    ctx->r4 = MEM_W(ctx->r17, 0XD44);
    // 0x80004944: srl         $v0, $a2, 5
    ctx->r2 = S32(U32(ctx->r6) >> 5);
    // 0x80004948: sw          $v0, 0x48($s3)
    MEM_W(0X48, ctx->r19) = ctx->r2;
    // 0x8000494C: sh          $zero, 0x4C($s3)
    MEM_H(0X4C, ctx->r19) = 0;
    // 0x80004950: addu        $a0, $a0, $s5
    ctx->r4 = ADD32(ctx->r4, ctx->r21);
    // 0x80004954: addu        $a0, $a0, $s2
    ctx->r4 = ADD32(ctx->r4, ctx->r18);
    // 0x80004958: addu        $v1, $v1, $s5
    ctx->r3 = ADD32(ctx->r3, ctx->r21);
    // 0x8000495C: jal         0x80003480
    // 0x80004960: sw          $v1, 0x44($s3)
    MEM_W(0X44, ctx->r19) = ctx->r3;
    func_80003480(rdram, ctx);
        goto after_6;
    // 0x80004960: sw          $v1, 0x44($s3)
    MEM_W(0X44, ctx->r19) = ctx->r3;
    after_6:
    // 0x80004964: jal         0x80003638
    // 0x80004968: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    func_80003638(rdram, ctx);
        goto after_7;
    // 0x80004968: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    after_7:
L_8000496C:
    // 0x8000496C: addu        $v0, $s4, $zero
    ctx->r2 = ADD32(ctx->r20, 0);
    // 0x80004970: lw          $ra, 0x28($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X28);
    // 0x80004974: lw          $s5, 0x24($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X24);
    // 0x80004978: lw          $s4, 0x20($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X20);
    // 0x8000497C: lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X1C);
    // 0x80004980: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x80004984: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x80004988: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8000498C: jr          $ra
    // 0x80004990: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80004990: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_80004994(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80004994: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80004998: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x8000499C: sw          $ra, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r31;
    // 0x800049A0: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // 0x800049A4: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x800049A8: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x800049AC: bne         $a0, $v0, L_80004A2C
    if (ctx->r4 != ctx->r2) {
        // 0x800049B0: sw          $s0, 0x10($sp)
        MEM_W(0X10, ctx->r29) = ctx->r16;
            goto L_80004A2C;
    }
    // 0x800049B0: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x800049B4: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // 0x800049B8: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
    // 0x800049BC: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800049C0: addiu       $s3, $v0, 0xBC0
    ctx->r19 = ADD32(ctx->r2, 0XBC0);
    // 0x800049C4: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800049C8: addiu       $s0, $v0, 0xA80
    ctx->r16 = ADD32(ctx->r2, 0XA80);
L_800049CC:
    // 0x800049CC: lbu         $v0, 0x4E($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X4E);
    // 0x800049D0: bnel        $v0, $s2, L_80004A18
    if (ctx->r2 != ctx->r18) {
        // 0x800049D4: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_80004A18;
    }
    goto skip_0;
    // 0x800049D4: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_0:
    // 0x800049D8: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x800049DC: addu        $v1, $s3, $zero
    ctx->r3 = ADD32(ctx->r19, 0);
L_800049E0:
    // 0x800049E0: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x800049E4: bnel        $v0, $s2, L_800049FC
    if (ctx->r2 != ctx->r18) {
        // 0x800049E8: addiu       $a1, $a1, 0x1
        ctx->r5 = ADD32(ctx->r5, 0X1);
            goto L_800049FC;
    }
    goto skip_1;
    // 0x800049E8: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    skip_1:
    // 0x800049EC: lw          $v0, 0x10($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X10);
    // 0x800049F0: beql        $v0, $s1, L_800049F8
    if (ctx->r2 == ctx->r17) {
        // 0x800049F4: sb          $zero, 0x0($v1)
        MEM_B(0X0, ctx->r3) = 0;
            goto L_800049F8;
    }
    goto skip_2;
    // 0x800049F4: sb          $zero, 0x0($v1)
    MEM_B(0X0, ctx->r3) = 0;
    skip_2:
L_800049F8:
    // 0x800049F8: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
L_800049FC:
    // 0x800049FC: sltiu       $v0, $a1, 0x10
    ctx->r2 = ctx->r5 < 0X10 ? 1 : 0;
    // 0x80004A00: bne         $v0, $zero, L_800049E0
    if (ctx->r2 != 0) {
        // 0x80004A04: addiu       $v1, $v1, 0x18
        ctx->r3 = ADD32(ctx->r3, 0X18);
            goto L_800049E0;
    }
    // 0x80004A04: addiu       $v1, $v1, 0x18
    ctx->r3 = ADD32(ctx->r3, 0X18);
    // 0x80004A08: lw          $a0, 0x40($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X40);
    // 0x80004A0C: jal         0x80001C98
    // 0x80004A10: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    rs_free(rdram, ctx);
        goto after_0;
    // 0x80004A10: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    after_0:
    // 0x80004A14: sb          $zero, 0x4E($s0)
    MEM_B(0X4E, ctx->r16) = 0;
L_80004A18:
    // 0x80004A18: sltiu       $v0, $s1, 0x4
    ctx->r2 = ctx->r17 < 0X4 ? 1 : 0;
    // 0x80004A1C: bne         $v0, $zero, L_800049CC
    if (ctx->r2 != 0) {
        // 0x80004A20: addiu       $s0, $s0, 0x50
        ctx->r16 = ADD32(ctx->r16, 0X50);
            goto L_800049CC;
    }
    // 0x80004A20: addiu       $s0, $s0, 0x50
    ctx->r16 = ADD32(ctx->r16, 0X50);
    // 0x80004A24: j           L_80004A8C
    // 0x80004A28: nop

        goto L_80004A8C;
    // 0x80004A28: nop

L_80004A2C:
    // 0x80004A2C: sll         $v0, $a0, 2
    ctx->r2 = S32(ctx->r4 << 2);
    // 0x80004A30: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x80004A34: sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2 << 4);
    // 0x80004A38: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x80004A3C: addiu       $v1, $v1, 0xA80
    ctx->r3 = ADD32(ctx->r3, 0XA80);
    // 0x80004A40: addu        $s0, $v0, $v1
    ctx->r16 = ADD32(ctx->r2, ctx->r3);
    // 0x80004A44: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80004A48: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80004A4C: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80004A50: addiu       $v1, $v0, 0xBC0
    ctx->r3 = ADD32(ctx->r2, 0XBC0);
L_80004A54:
    // 0x80004A54: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x80004A58: bnel        $v0, $a2, L_80004A70
    if (ctx->r2 != ctx->r6) {
        // 0x80004A5C: addiu       $a1, $a1, 0x1
        ctx->r5 = ADD32(ctx->r5, 0X1);
            goto L_80004A70;
    }
    goto skip_3;
    // 0x80004A5C: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    skip_3:
    // 0x80004A60: lw          $v0, 0x10($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X10);
    // 0x80004A64: beql        $v0, $a0, L_80004A6C
    if (ctx->r2 == ctx->r4) {
        // 0x80004A68: sb          $zero, 0x0($v1)
        MEM_B(0X0, ctx->r3) = 0;
            goto L_80004A6C;
    }
    goto skip_4;
    // 0x80004A68: sb          $zero, 0x0($v1)
    MEM_B(0X0, ctx->r3) = 0;
    skip_4:
L_80004A6C:
    // 0x80004A6C: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
L_80004A70:
    // 0x80004A70: sltiu       $v0, $a1, 0x10
    ctx->r2 = ctx->r5 < 0X10 ? 1 : 0;
    // 0x80004A74: bne         $v0, $zero, L_80004A54
    if (ctx->r2 != 0) {
        // 0x80004A78: addiu       $v1, $v1, 0x18
        ctx->r3 = ADD32(ctx->r3, 0X18);
            goto L_80004A54;
    }
    // 0x80004A78: addiu       $v1, $v1, 0x18
    ctx->r3 = ADD32(ctx->r3, 0X18);
    // 0x80004A7C: lw          $a0, 0x40($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X40);
    // 0x80004A80: jal         0x80001C98
    // 0x80004A84: nop

    rs_free(rdram, ctx);
        goto after_1;
    // 0x80004A84: nop

    after_1:
    // 0x80004A88: sb          $zero, 0x4E($s0)
    MEM_B(0X4E, ctx->r16) = 0;
L_80004A8C:
    // 0x80004A8C: lw          $ra, 0x20($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X20);
    // 0x80004A90: lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X1C);
    // 0x80004A94: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x80004A98: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x80004A9C: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80004AA0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80004AA4: jr          $ra
    // 0x80004AA8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80004AA8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_80004AAC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80004AAC: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80004AB0: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x80004AB4: addu        $s3, $a0, $zero
    ctx->r19 = ADD32(ctx->r4, 0);
    // 0x80004AB8: sw          $s5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r21;
    // 0x80004ABC: addu        $s5, $a1, $zero
    ctx->r21 = ADD32(ctx->r5, 0);
    // 0x80004AC0: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x80004AC4: addu        $s2, $a3, $zero
    ctx->r18 = ADD32(ctx->r7, 0);
    // 0x80004AC8: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x80004ACC: addiu       $s4, $sp, 0x50
    ctx->r20 = ADD32(ctx->r29, 0X50);
    // 0x80004AD0: addu        $a0, $a2, $zero
    ctx->r4 = ADD32(ctx->r6, 0);
    // 0x80004AD4: sw          $s6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r22;
    // 0x80004AD8: lhu         $s6, 0x5A($sp)
    ctx->r22 = MEM_HU(ctx->r29, 0X5A);
    // 0x80004ADC: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x80004AE0: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x80004AE4: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x80004AE8: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x80004AEC: bne         $a0, $v0, L_80004B38
    if (ctx->r4 != ctx->r2) {
        // 0x80004AF0: sw          $a2, 0x50($sp)
        MEM_W(0X50, ctx->r29) = ctx->r6;
            goto L_80004B38;
    }
    // 0x80004AF0: sw          $a2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r6;
    // 0x80004AF4: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // 0x80004AF8: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80004AFC: addiu       $s1, $v0, 0xA80
    ctx->r17 = ADD32(ctx->r2, 0XA80);
L_80004B00:
    // 0x80004B00: lbu         $v0, 0x4E($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X4E);
    // 0x80004B04: beq         $v0, $zero, L_80004B20
    if (ctx->r2 == 0) {
        // 0x80004B08: addu        $a0, $s0, $zero
        ctx->r4 = ADD32(ctx->r16, 0);
            goto L_80004B20;
    }
    // 0x80004B08: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80004B0C: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    // 0x80004B10: jal         0x80003A0C
    // 0x80004B14: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    find_manifest_entry(rdram, ctx);
        goto after_0;
    // 0x80004B14: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    after_0:
    // 0x80004B18: bnel        $v0, $zero, L_80004B44
    if (ctx->r2 != 0) {
        // 0x80004B1C: sw          $s0, 0x0($s4)
        MEM_W(0X0, ctx->r20) = ctx->r16;
            goto L_80004B44;
    }
    goto skip_0;
    // 0x80004B1C: sw          $s0, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r16;
    skip_0:
L_80004B20:
    // 0x80004B20: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80004B24: sltiu       $v0, $s0, 0x4
    ctx->r2 = ctx->r16 < 0X4 ? 1 : 0;
    // 0x80004B28: bne         $v0, $zero, L_80004B00
    if (ctx->r2 != 0) {
        // 0x80004B2C: addiu       $s1, $s1, 0x50
        ctx->r17 = ADD32(ctx->r17, 0X50);
            goto L_80004B00;
    }
    // 0x80004B2C: addiu       $s1, $s1, 0x50
    ctx->r17 = ADD32(ctx->r17, 0X50);
    // 0x80004B30: j           L_80004B48
    // 0x80004B34: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
        goto L_80004B48;
    // 0x80004B34: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
L_80004B38:
    // 0x80004B38: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    // 0x80004B3C: jal         0x80003A0C
    // 0x80004B40: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    find_manifest_entry(rdram, ctx);
        goto after_1;
    // 0x80004B40: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    after_1:
L_80004B44:
    // 0x80004B44: addu        $a3, $v0, $zero
    ctx->r7 = ADD32(ctx->r2, 0);
L_80004B48:
    // 0x80004B48: bne         $a3, $zero, L_80004B58
    if (ctx->r7 != 0) {
        // 0x80004B4C: lui         $t0, 0x8011
        ctx->r8 = S32(0X8011 << 16);
            goto L_80004B58;
    }
    // 0x80004B4C: lui         $t0, 0x8011
    ctx->r8 = S32(0X8011 << 16);
    // 0x80004B50: j           L_80004C48
    // 0x80004B54: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
        goto L_80004C48;
    // 0x80004B54: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_80004B58:
    // 0x80004B58: lw          $a2, 0x1248($t0)
    ctx->r6 = MEM_W(ctx->r8, 0X1248);
    // 0x80004B5C: addiu       $a1, $a2, 0x1
    ctx->r5 = ADD32(ctx->r6, 0X1);
    // 0x80004B60: bgez        $a1, L_80004B6C
    if (SIGNED(ctx->r5) >= 0) {
        // 0x80004B64: addu        $v0, $a1, $zero
        ctx->r2 = ADD32(ctx->r5, 0);
            goto L_80004B6C;
    }
    // 0x80004B64: addu        $v0, $a1, $zero
    ctx->r2 = ADD32(ctx->r5, 0);
    // 0x80004B68: addiu       $v0, $a2, 0x8
    ctx->r2 = ADD32(ctx->r6, 0X8);
L_80004B6C:
    // 0x80004B6C: sra         $v0, $v0, 3
    ctx->r2 = S32(SIGNED(ctx->r2) >> 3);
    // 0x80004B70: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x80004B74: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80004B78: subu        $v0, $a1, $v0
    ctx->r2 = SUB32(ctx->r5, ctx->r2);
    // 0x80004B7C: sw          $v0, 0x1248($t0)
    MEM_W(0X1248, ctx->r8) = ctx->r2;
    // 0x80004B80: sll         $v0, $a2, 2
    ctx->r2 = S32(ctx->r6 << 2);
    // 0x80004B84: addu        $v0, $v0, $a2
    ctx->r2 = ADD32(ctx->r2, ctx->r6);
    // 0x80004B88: lw          $v1, 0x1250($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1250);
    // 0x80004B8C: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x80004B90: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x80004B94: sw          $v1, 0x1250($a0)
    MEM_W(0X1250, ctx->r4) = ctx->r3;
    // 0x80004B98: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x80004B9C: addiu       $v1, $v1, 0x1100
    ctx->r3 = ADD32(ctx->r3, 0X1100);
    // 0x80004BA0: addu        $a2, $v0, $v1
    ctx->r6 = ADD32(ctx->r2, ctx->r3);
    // 0x80004BA4: lw          $v1, 0x50($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X50);
    // 0x80004BA8: ori         $v0, $zero, 0x8000
    ctx->r2 = 0 | 0X8000;
    // 0x80004BAC: sh          $v0, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r2;
    // 0x80004BB0: sw          $s3, 0x14($a2)
    MEM_W(0X14, ctx->r6) = ctx->r19;
    // 0x80004BB4: sw          $a3, 0x18($a2)
    MEM_W(0X18, ctx->r6) = ctx->r7;
    // 0x80004BB8: sh          $s6, 0x20($a2)
    MEM_H(0X20, ctx->r6) = ctx->r22;
    // 0x80004BBC: bne         $s5, $zero, L_80004C24
    if (ctx->r21 != 0) {
        // 0x80004BC0: sw          $v1, 0x1C($a2)
        MEM_W(0X1C, ctx->r6) = ctx->r3;
            goto L_80004C24;
    }
    // 0x80004BC0: sw          $v1, 0x1C($a2)
    MEM_W(0X1C, ctx->r6) = ctx->r3;
    // 0x80004BC4: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // 0x80004BC8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80004BCC: ori         $s1, $zero, 0x80FF
    ctx->r17 = 0 | 0X80FF;
    // 0x80004BD0: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80004BD4: lw          $a1, 0xD54($v0)
    ctx->r5 = MEM_W(ctx->r2, 0XD54);
    // 0x80004BD8: addiu       $v0, $sp, 0x10
    ctx->r2 = ADD32(ctx->r29, 0X10);
    // 0x80004BDC: sw          $v0, 0x10($a2)
    MEM_W(0X10, ctx->r6) = ctx->r2;
    // 0x80004BE0: addu        $v0, $s1, $zero
    ctx->r2 = ADD32(ctx->r17, 0);
    // 0x80004BE4: jal         0x80006F78
    // 0x80004BE8: sh          $v0, 0x10($sp)
    MEM_H(0X10, ctx->r29) = ctx->r2;
    func_80006F78(rdram, ctx);
        goto after_2;
    // 0x80004BE8: sh          $v0, 0x10($sp)
    MEM_H(0X10, ctx->r29) = ctx->r2;
    after_2:
L_80004BEC:
    // 0x80004BEC: jal         0x80006F24
    // 0x80004BF0: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    func_80006F24(rdram, ctx);
        goto after_3;
    // 0x80004BF0: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    after_3:
    // 0x80004BF4: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // 0x80004BF8: lhu         $v0, 0x0($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X0);
    // 0x80004BFC: beq         $v0, $s1, L_80004C18
    if (ctx->r2 == ctx->r17) {
        // 0x80004C00: addu        $a0, $s3, $zero
        ctx->r4 = ADD32(ctx->r19, 0);
            goto L_80004C18;
    }
    // 0x80004C00: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // 0x80004C04: jal         0x80007070
    // 0x80004C08: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    func_80007070(rdram, ctx);
        goto after_4;
    // 0x80004C08: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_4:
    // 0x80004C0C: lhu         $v0, 0x0($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X0);
    // 0x80004C10: bne         $v0, $s1, L_80004BEC
    if (ctx->r2 != ctx->r17) {
        // 0x80004C14: nop
    
            goto L_80004BEC;
    }
    // 0x80004C14: nop

L_80004C18:
    // 0x80004C18: lw          $v0, 0xC($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XC);
    // 0x80004C1C: j           L_80004C48
    // 0x80004C20: nop

        goto L_80004C48;
    // 0x80004C20: nop

L_80004C24:
    // 0x80004C24: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // 0x80004C28: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80004C2C: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80004C30: lw          $a1, 0xD54($v0)
    ctx->r5 = MEM_W(ctx->r2, 0XD54);
    // 0x80004C34: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // 0x80004C38: sh          $v0, 0x0($s5)
    MEM_H(0X0, ctx->r21) = ctx->r2;
    // 0x80004C3C: jal         0x80006F78
    // 0x80004C40: sw          $s5, 0x10($a2)
    MEM_W(0X10, ctx->r6) = ctx->r21;
    func_80006F78(rdram, ctx);
        goto after_5;
    // 0x80004C40: sw          $s5, 0x10($a2)
    MEM_W(0X10, ctx->r6) = ctx->r21;
    after_5:
    // 0x80004C44: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80004C48:
    // 0x80004C48: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x80004C4C: lw          $s6, 0x40($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X40);
    // 0x80004C50: lw          $s5, 0x3C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X3C);
    // 0x80004C54: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x80004C58: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x80004C5C: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x80004C60: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x80004C64: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x80004C68: jr          $ra
    // 0x80004C6C: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x80004C6C: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void func_80004C70(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80004C70: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80004C74: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x80004C78: addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // 0x80004C7C: lui         $t0, 0x8011
    ctx->r8 = S32(0X8011 << 16);
    // 0x80004C80: lw          $a3, 0x1248($t0)
    ctx->r7 = MEM_W(ctx->r8, 0X1248);
    // 0x80004C84: addu        $t1, $a1, $zero
    ctx->r9 = ADD32(ctx->r5, 0);
    // 0x80004C88: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80004C8C: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x80004C90: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x80004C94: addiu       $v1, $a3, 0x1
    ctx->r3 = ADD32(ctx->r7, 0X1);
    // 0x80004C98: bgez        $v1, L_80004CA4
    if (SIGNED(ctx->r3) >= 0) {
        // 0x80004C9C: addu        $a2, $v1, $zero
        ctx->r6 = ADD32(ctx->r3, 0);
            goto L_80004CA4;
    }
    // 0x80004C9C: addu        $a2, $v1, $zero
    ctx->r6 = ADD32(ctx->r3, 0);
    // 0x80004CA0: addiu       $a2, $a3, 0x8
    ctx->r6 = ADD32(ctx->r7, 0X8);
L_80004CA4:
    // 0x80004CA4: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x80004CA8: ori         $s2, $zero, 0x80FF
    ctx->r18 = 0 | 0X80FF;
    // 0x80004CAC: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80004CB0: lw          $a1, 0xD54($v0)
    ctx->r5 = MEM_W(ctx->r2, 0XD54);
    // 0x80004CB4: sra         $v0, $a2, 3
    ctx->r2 = S32(SIGNED(ctx->r6) >> 3);
    // 0x80004CB8: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x80004CBC: subu        $v0, $v1, $v0
    ctx->r2 = SUB32(ctx->r3, ctx->r2);
    // 0x80004CC0: sw          $v0, 0x1248($t0)
    MEM_W(0X1248, ctx->r8) = ctx->r2;
    // 0x80004CC4: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80004CC8: addiu       $v0, $v0, 0x1100
    ctx->r2 = ADD32(ctx->r2, 0X1100);
    // 0x80004CCC: sll         $a2, $a3, 2
    ctx->r6 = S32(ctx->r7 << 2);
    // 0x80004CD0: addu        $a2, $a2, $a3
    ctx->r6 = ADD32(ctx->r6, ctx->r7);
    // 0x80004CD4: sll         $a2, $a2, 3
    ctx->r6 = S32(ctx->r6 << 3);
    // 0x80004CD8: addu        $a2, $a2, $v0
    ctx->r6 = ADD32(ctx->r6, ctx->r2);
    // 0x80004CDC: ori         $v0, $zero, 0x8001
    ctx->r2 = 0 | 0X8001;
    // 0x80004CE0: sh          $v0, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r2;
    // 0x80004CE4: addiu       $v0, $sp, 0x10
    ctx->r2 = ADD32(ctx->r29, 0X10);
    // 0x80004CE8: lui         $a3, 0x8011
    ctx->r7 = S32(0X8011 << 16);
    // 0x80004CEC: sw          $v0, 0x10($a2)
    MEM_W(0X10, ctx->r6) = ctx->r2;
    // 0x80004CF0: lw          $v0, 0x1250($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X1250);
    // 0x80004CF4: addu        $v1, $s2, $zero
    ctx->r3 = ADD32(ctx->r18, 0);
    // 0x80004CF8: sw          $s1, 0x14($a2)
    MEM_W(0X14, ctx->r6) = ctx->r17;
    // 0x80004CFC: sw          $t1, 0x18($a2)
    MEM_W(0X18, ctx->r6) = ctx->r9;
    // 0x80004D00: sh          $v1, 0x10($sp)
    MEM_H(0X10, ctx->r29) = ctx->r3;
    // 0x80004D04: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x80004D08: sw          $v0, 0x1250($a3)
    MEM_W(0X1250, ctx->r7) = ctx->r2;
    // 0x80004D0C: jal         0x80006F78
    // 0x80004D10: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_80006F78(rdram, ctx);
        goto after_0;
    // 0x80004D10: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_0:
L_80004D14:
    // 0x80004D14: jal         0x80006F24
    // 0x80004D18: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_80006F24(rdram, ctx);
        goto after_1;
    // 0x80004D18: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_1:
    // 0x80004D1C: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // 0x80004D20: lhu         $v0, 0x0($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X0);
    // 0x80004D24: beq         $v0, $s2, L_80004D40
    if (ctx->r2 == ctx->r18) {
        // 0x80004D28: addu        $a0, $s1, $zero
        ctx->r4 = ADD32(ctx->r17, 0);
            goto L_80004D40;
    }
    // 0x80004D28: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x80004D2C: jal         0x80007070
    // 0x80004D30: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    func_80007070(rdram, ctx);
        goto after_2;
    // 0x80004D30: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_2:
    // 0x80004D34: lhu         $v0, 0x0($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X0);
    // 0x80004D38: bne         $v0, $s2, L_80004D14
    if (ctx->r2 != ctx->r18) {
        // 0x80004D3C: nop
    
            goto L_80004D14;
    }
    // 0x80004D3C: nop

L_80004D40:
    // 0x80004D40: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x80004D44: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x80004D48: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x80004D4C: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x80004D50: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80004D54: jr          $ra
    // 0x80004D58: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80004D58: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void get_asset_size_extra(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80004D5C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80004D60: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x80004D64: addu        $s2, $a1, $zero
    ctx->r18 = ADD32(ctx->r5, 0);
    // 0x80004D68: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // 0x80004D6C: addiu       $s3, $sp, 0x28
    ctx->r19 = ADD32(ctx->r29, 0X28);
    // 0x80004D70: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x80004D74: sw          $ra, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r31;
    // 0x80004D78: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x80004D7C: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80004D80: bne         $a0, $v0, L_80004DCC
    if (ctx->r4 != ctx->r2) {
        // 0x80004D84: sw          $a0, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r4;
            goto L_80004DCC;
    }
    // 0x80004D84: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80004D88: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // 0x80004D8C: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80004D90: addiu       $s1, $v0, 0xA80
    ctx->r17 = ADD32(ctx->r2, 0XA80);
L_80004D94:
    // 0x80004D94: lbu         $v0, 0x4E($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X4E);
    // 0x80004D98: beq         $v0, $zero, L_80004DB4
    if (ctx->r2 == 0) {
        // 0x80004D9C: addu        $a0, $s0, $zero
        ctx->r4 = ADD32(ctx->r16, 0);
            goto L_80004DB4;
    }
    // 0x80004D9C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80004DA0: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    // 0x80004DA4: jal         0x80003A0C
    // 0x80004DA8: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    find_manifest_entry(rdram, ctx);
        goto after_0;
    // 0x80004DA8: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    after_0:
    // 0x80004DAC: bnel        $v0, $zero, L_80004DD8
    if (ctx->r2 != 0) {
        // 0x80004DB0: sw          $s0, 0x0($s3)
        MEM_W(0X0, ctx->r19) = ctx->r16;
            goto L_80004DD8;
    }
    goto skip_0;
    // 0x80004DB0: sw          $s0, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r16;
    skip_0:
L_80004DB4:
    // 0x80004DB4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80004DB8: sltiu       $v0, $s0, 0x4
    ctx->r2 = ctx->r16 < 0X4 ? 1 : 0;
    // 0x80004DBC: bne         $v0, $zero, L_80004D94
    if (ctx->r2 != 0) {
        // 0x80004DC0: addiu       $s1, $s1, 0x50
        ctx->r17 = ADD32(ctx->r17, 0X50);
            goto L_80004D94;
    }
    // 0x80004DC0: addiu       $s1, $s1, 0x50
    ctx->r17 = ADD32(ctx->r17, 0X50);
    // 0x80004DC4: j           L_80004DDC
    // 0x80004DC8: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
        goto L_80004DDC;
    // 0x80004DC8: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
L_80004DCC:
    // 0x80004DCC: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    // 0x80004DD0: jal         0x80003A0C
    // 0x80004DD4: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    find_manifest_entry(rdram, ctx);
        goto after_1;
    // 0x80004DD4: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    after_1:
L_80004DD8:
    // 0x80004DD8: addu        $a1, $v0, $zero
    ctx->r5 = ADD32(ctx->r2, 0);
L_80004DDC:
    // 0x80004DDC: bne         $a1, $zero, L_80004DEC
    if (ctx->r5 != 0) {
        // 0x80004DE0: lui         $v1, 0x8011
        ctx->r3 = S32(0X8011 << 16);
            goto L_80004DEC;
    }
    // 0x80004DE0: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x80004DE4: j           L_80004E54
    // 0x80004DE8: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
        goto L_80004E54;
    // 0x80004DE8: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_80004DEC:
    // 0x80004DEC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80004DF0: addiu       $v1, $v1, 0xA80
    ctx->r3 = ADD32(ctx->r3, 0XA80);
    // 0x80004DF4: sll         $v0, $a0, 2
    ctx->r2 = S32(ctx->r4 << 2);
    // 0x80004DF8: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x80004DFC: sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2 << 4);
    // 0x80004E00: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80004E04: lhu         $v0, 0x4C($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X4C);
    // 0x80004E08: beq         $v0, $zero, L_80004E30
    if (ctx->r2 == 0) {
        // 0x80004E0C: addu        $a0, $zero, $zero
        ctx->r4 = ADD32(0, 0);
            goto L_80004E30;
    }
    // 0x80004E0C: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x80004E10: lw          $v1, 0x8($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X8);
    // 0x80004E14: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x80004E18: beq         $v1, $v0, L_80004E30
    if (ctx->r3 == ctx->r2) {
        // 0x80004E1C: nop
    
            goto L_80004E30;
    }
    // 0x80004E1C: nop

    // 0x80004E20: lbu         $v0, 0xC($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0XC);
    // 0x80004E24: andi        $v0, $v0, 0x44
    ctx->r2 = ctx->r2 & 0X44;
    // 0x80004E28: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80004E2C: sll         $a0, $v0, 6
    ctx->r4 = S32(ctx->r2 << 6);
L_80004E30:
    // 0x80004E30: lbu         $v0, 0xC($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0XC);
    // 0x80004E34: andi        $v0, $v0, 0x4
    ctx->r2 = ctx->r2 & 0X4;
    // 0x80004E38: beq         $v0, $zero, L_80004E4C
    if (ctx->r2 == 0) {
        // 0x80004E3C: nop
    
            goto L_80004E4C;
    }
    // 0x80004E3C: nop

    // 0x80004E40: lw          $v0, 0x8($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X8);
    // 0x80004E44: j           L_80004E54
    // 0x80004E48: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
        goto L_80004E54;
    // 0x80004E48: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
L_80004E4C:
    // 0x80004E4C: lw          $v0, 0x4($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X4);
    // 0x80004E50: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
L_80004E54:
    // 0x80004E54: lw          $ra, 0x20($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X20);
    // 0x80004E58: lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X1C);
    // 0x80004E5C: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x80004E60: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x80004E64: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80004E68: jr          $ra
    // 0x80004E6C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80004E6C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_80004E70(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80004E70: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80004E74: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x80004E78: addu        $s2, $a0, $zero
    ctx->r18 = ADD32(ctx->r4, 0);
    // 0x80004E7C: addu        $t0, $a1, $zero
    ctx->r8 = ADD32(ctx->r5, 0);
    // 0x80004E80: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80004E84: lw          $a1, 0x1248($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X1248);
    // 0x80004E88: addu        $t1, $a2, $zero
    ctx->r9 = ADD32(ctx->r6, 0);
    // 0x80004E8C: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80004E90: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x80004E94: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x80004E98: addiu       $v1, $a1, 0x1
    ctx->r3 = ADD32(ctx->r5, 0X1);
    // 0x80004E9C: bgez        $v1, L_80004EA8
    if (SIGNED(ctx->r3) >= 0) {
        // 0x80004EA0: addu        $v0, $v1, $zero
        ctx->r2 = ADD32(ctx->r3, 0);
            goto L_80004EA8;
    }
    // 0x80004EA0: addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
    // 0x80004EA4: addiu       $v0, $a1, 0x8
    ctx->r2 = ADD32(ctx->r5, 0X8);
L_80004EA8:
    // 0x80004EA8: sra         $v0, $v0, 3
    ctx->r2 = S32(SIGNED(ctx->r2) >> 3);
    // 0x80004EAC: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x80004EB0: subu        $v0, $v1, $v0
    ctx->r2 = SUB32(ctx->r3, ctx->r2);
    // 0x80004EB4: sw          $v0, 0x1248($a0)
    MEM_W(0X1248, ctx->r4) = ctx->r2;
    // 0x80004EB8: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80004EBC: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x80004EC0: addiu       $v1, $v1, 0x1100
    ctx->r3 = ADD32(ctx->r3, 0X1100);
    // 0x80004EC4: sll         $v0, $a1, 2
    ctx->r2 = S32(ctx->r5 << 2);
    // 0x80004EC8: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x80004ECC: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x80004ED0: addu        $a2, $v0, $v1
    ctx->r6 = ADD32(ctx->r2, ctx->r3);
    // 0x80004ED4: ori         $v0, $zero, 0x8002
    ctx->r2 = 0 | 0X8002;
    // 0x80004ED8: sh          $v0, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r2;
    // 0x80004EDC: sw          $s2, 0x14($a2)
    MEM_W(0X14, ctx->r6) = ctx->r18;
    // 0x80004EE0: sw          $t1, 0x18($a2)
    MEM_W(0X18, ctx->r6) = ctx->r9;
    // 0x80004EE4: sw          $a3, 0x1C($a2)
    MEM_W(0X1C, ctx->r6) = ctx->r7;
    // 0x80004EE8: lw          $v0, 0x48($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X48);
    // 0x80004EEC: lw          $v1, 0x1250($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1250);
    // 0x80004EF0: sw          $v0, 0x20($a2)
    MEM_W(0X20, ctx->r6) = ctx->r2;
    // 0x80004EF4: lw          $v0, 0x4C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X4C);
    // 0x80004EF8: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x80004EFC: sw          $v1, 0x1250($a0)
    MEM_W(0X1250, ctx->r4) = ctx->r3;
    // 0x80004F00: bne         $t0, $zero, L_80004F74
    if (ctx->r8 != 0) {
        // 0x80004F04: sw          $v0, 0x24($a2)
        MEM_W(0X24, ctx->r6) = ctx->r2;
            goto L_80004F74;
    }
    // 0x80004F04: sw          $v0, 0x24($a2)
    MEM_W(0X24, ctx->r6) = ctx->r2;
    // 0x80004F08: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x80004F0C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80004F10: ori         $s1, $zero, 0x80FF
    ctx->r17 = 0 | 0X80FF;
    // 0x80004F14: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80004F18: lw          $a1, 0xD54($v0)
    ctx->r5 = MEM_W(ctx->r2, 0XD54);
    // 0x80004F1C: addiu       $v0, $sp, 0x10
    ctx->r2 = ADD32(ctx->r29, 0X10);
    // 0x80004F20: sw          $v0, 0x10($a2)
    MEM_W(0X10, ctx->r6) = ctx->r2;
    // 0x80004F24: addu        $v0, $s1, $zero
    ctx->r2 = ADD32(ctx->r17, 0);
    // 0x80004F28: jal         0x80006F78
    // 0x80004F2C: sh          $v0, 0x10($sp)
    MEM_H(0X10, ctx->r29) = ctx->r2;
    func_80006F78(rdram, ctx);
        goto after_0;
    // 0x80004F2C: sh          $v0, 0x10($sp)
    MEM_H(0X10, ctx->r29) = ctx->r2;
    after_0:
L_80004F30:
    // 0x80004F30: jal         0x80006F24
    // 0x80004F34: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    func_80006F24(rdram, ctx);
        goto after_1;
    // 0x80004F34: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    after_1:
    // 0x80004F38: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // 0x80004F3C: lhu         $v0, 0x0($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X0);
    // 0x80004F40: beq         $v0, $s1, L_80004F5C
    if (ctx->r2 == ctx->r17) {
        // 0x80004F44: addu        $a0, $s2, $zero
        ctx->r4 = ADD32(ctx->r18, 0);
            goto L_80004F5C;
    }
    // 0x80004F44: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x80004F48: jal         0x80007070
    // 0x80004F4C: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    func_80007070(rdram, ctx);
        goto after_2;
    // 0x80004F4C: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_2:
    // 0x80004F50: lhu         $v0, 0x0($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X0);
    // 0x80004F54: bne         $v0, $s1, L_80004F30
    if (ctx->r2 != ctx->r17) {
        // 0x80004F58: nop
    
            goto L_80004F30;
    }
    // 0x80004F58: nop

L_80004F5C:
    // 0x80004F5C: jal         0x800072AC
    // 0x80004F60: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    func_800072AC(rdram, ctx);
        goto after_3;
    // 0x80004F60: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    after_3:
    // 0x80004F64: jal         0x8000736C
    // 0x80004F68: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8000736C(rdram, ctx);
        goto after_4;
    // 0x80004F68: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_4:
    // 0x80004F6C: j           L_80004F98
    // 0x80004F70: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
        goto L_80004F98;
    // 0x80004F70: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
L_80004F74:
    // 0x80004F74: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x80004F78: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80004F7C: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80004F80: lw          $a1, 0xD54($v0)
    ctx->r5 = MEM_W(ctx->r2, 0XD54);
    // 0x80004F84: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // 0x80004F88: sh          $v0, 0x0($t0)
    MEM_H(0X0, ctx->r8) = ctx->r2;
    // 0x80004F8C: jal         0x80006F78
    // 0x80004F90: sw          $t0, 0x10($a2)
    MEM_W(0X10, ctx->r6) = ctx->r8;
    func_80006F78(rdram, ctx);
        goto after_5;
    // 0x80004F90: sw          $t0, 0x10($a2)
    MEM_W(0X10, ctx->r6) = ctx->r8;
    after_5:
    // 0x80004F94: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_80004F98:
    // 0x80004F98: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x80004F9C: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x80004FA0: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x80004FA4: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x80004FA8: jr          $ra
    // 0x80004FAC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80004FAC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_80004FB0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80004FB0: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80004FB4: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80004FB8: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x80004FBC: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80004FC0: jr          $ra
    // 0x80004FC4: nop

    return;
    // 0x80004FC4: nop

;}
RECOMP_FUNC void func_80004FC8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80004FC8: jr          $ra
    // 0x80004FCC: nop

    return;
    // 0x80004FCC: nop

;}
RECOMP_FUNC void func_80004FD0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80004FD0: jr          $ra
    // 0x80004FD4: nop

    return;
    // 0x80004FD4: nop

;}
RECOMP_FUNC void func_80004FD8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80004FD8: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80004FDC: lw          $a0, 0xD54($v0)
    ctx->r4 = MEM_W(ctx->r2, 0XD54);
    // 0x80004FE0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80004FE4: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80004FE8: jal         0x800070BC
    // 0x80004FEC: nop

    func_800070BC(rdram, ctx);
        goto after_0;
    // 0x80004FEC: nop

    after_0:
    // 0x80004FF0: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80004FF4: lw          $a0, 0xD50($v0)
    ctx->r4 = MEM_W(ctx->r2, 0XD50);
    // 0x80004FF8: beq         $a0, $zero, L_80005008
    if (ctx->r4 == 0) {
        // 0x80004FFC: nop
    
            goto L_80005008;
    }
    // 0x80004FFC: nop

    // 0x80005000: jal         0x80001C98
    // 0x80005004: nop

    rs_free(rdram, ctx);
        goto after_1;
    // 0x80005004: nop

    after_1:
L_80005008:
    // 0x80005008: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x8000500C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80005010: jr          $ra
    // 0x80005014: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80005014: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80005018(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80005018: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8000501C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x80005020: bne         $a0, $v0, L_80005030
    if (ctx->r4 != ctx->r2) {
        // 0x80005024: sw          $ra, 0x10($sp)
        MEM_W(0X10, ctx->r29) = ctx->r31;
            goto L_80005030;
    }
    // 0x80005024: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80005028: j           L_80005074
    // 0x8000502C: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
        goto L_80005074;
    // 0x8000502C: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_80005030:
    // 0x80005030: beq         $a1, $zero, L_80005058
    if (ctx->r5 == 0) {
        // 0x80005034: sll         $v0, $a0, 2
        ctx->r2 = S32(ctx->r4 << 2);
            goto L_80005058;
    }
    // 0x80005034: sll         $v0, $a0, 2
    ctx->r2 = S32(ctx->r4 << 2);
    // 0x80005038: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x8000503C: sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2 << 4);
    // 0x80005040: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80005044: addiu       $a0, $a0, 0xAA0
    ctx->r4 = ADD32(ctx->r4, 0XAA0);
    // 0x80005048: jal         0x8000761C
    // 0x8000504C: addu        $a0, $v0, $a0
    ctx->r4 = ADD32(ctx->r2, ctx->r4);
    rs_strcpy(rdram, ctx);
        goto after_0;
    // 0x8000504C: addu        $a0, $v0, $a0
    ctx->r4 = ADD32(ctx->r2, ctx->r4);
    after_0:
    // 0x80005050: j           L_80005074
    // 0x80005054: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80005074;
    // 0x80005054: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80005058:
    // 0x80005058: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x8000505C: addiu       $v1, $v1, 0xA80
    ctx->r3 = ADD32(ctx->r3, 0XA80);
    // 0x80005060: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x80005064: sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2 << 4);
    // 0x80005068: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8000506C: sb          $zero, 0x20($v0)
    MEM_B(0X20, ctx->r2) = 0;
    // 0x80005070: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80005074:
    // 0x80005074: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80005078: jr          $ra
    // 0x8000507C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8000507C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void get_manifest_entry_type(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80005080: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80005084: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x80005088: addu        $s2, $a1, $zero
    ctx->r18 = ADD32(ctx->r5, 0);
    // 0x8000508C: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // 0x80005090: addiu       $s3, $sp, 0x28
    ctx->r19 = ADD32(ctx->r29, 0X28);
    // 0x80005094: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x80005098: sw          $ra, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r31;
    // 0x8000509C: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x800050A0: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x800050A4: bne         $a0, $v0, L_800050F0
    if (ctx->r4 != ctx->r2) {
        // 0x800050A8: sw          $a0, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r4;
            goto L_800050F0;
    }
    // 0x800050A8: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x800050AC: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // 0x800050B0: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800050B4: addiu       $s1, $v0, 0xA80
    ctx->r17 = ADD32(ctx->r2, 0XA80);
L_800050B8:
    // 0x800050B8: lbu         $v0, 0x4E($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X4E);
    // 0x800050BC: beq         $v0, $zero, L_800050D8
    if (ctx->r2 == 0) {
        // 0x800050C0: addu        $a0, $s0, $zero
        ctx->r4 = ADD32(ctx->r16, 0);
            goto L_800050D8;
    }
    // 0x800050C0: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800050C4: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    // 0x800050C8: jal         0x80003A0C
    // 0x800050CC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    find_manifest_entry(rdram, ctx);
        goto after_0;
    // 0x800050CC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x800050D0: bnel        $v0, $zero, L_800050FC
    if (ctx->r2 != 0) {
        // 0x800050D4: sw          $s0, 0x0($s3)
        MEM_W(0X0, ctx->r19) = ctx->r16;
            goto L_800050FC;
    }
    goto skip_0;
    // 0x800050D4: sw          $s0, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r16;
    skip_0:
L_800050D8:
    // 0x800050D8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800050DC: sltiu       $v0, $s0, 0x4
    ctx->r2 = ctx->r16 < 0X4 ? 1 : 0;
    // 0x800050E0: bne         $v0, $zero, L_800050B8
    if (ctx->r2 != 0) {
        // 0x800050E4: addiu       $s1, $s1, 0x50
        ctx->r17 = ADD32(ctx->r17, 0X50);
            goto L_800050B8;
    }
    // 0x800050E4: addiu       $s1, $s1, 0x50
    ctx->r17 = ADD32(ctx->r17, 0X50);
    // 0x800050E8: j           L_800050FC
    // 0x800050EC: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
        goto L_800050FC;
    // 0x800050EC: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_800050F0:
    // 0x800050F0: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    // 0x800050F4: jal         0x80003A0C
    // 0x800050F8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    find_manifest_entry(rdram, ctx);
        goto after_1;
    // 0x800050F8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_1:
L_800050FC:
    // 0x800050FC: beql        $v0, $zero, L_80005118
    if (ctx->r2 == 0) {
        // 0x80005100: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_80005118;
    }
    goto skip_1;
    // 0x80005100: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    skip_1:
    // 0x80005104: lbu         $v1, 0xC($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0XC);
    // 0x80005108: andi        $v1, $v1, 0x80
    ctx->r3 = ctx->r3 & 0X80;
    // 0x8000510C: bne         $v1, $zero, L_80005118
    if (ctx->r3 != 0) {
        // 0x80005110: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_80005118;
    }
    // 0x80005110: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x80005114: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80005118:
    // 0x80005118: lw          $ra, 0x20($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X20);
    // 0x8000511C: lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X1C);
    // 0x80005120: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x80005124: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x80005128: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8000512C: jr          $ra
    // 0x80005130: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80005130: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void get_asset_size_simple(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80005134: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80005138: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x8000513C: addu        $s2, $a1, $zero
    ctx->r18 = ADD32(ctx->r5, 0);
    // 0x80005140: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // 0x80005144: addiu       $s3, $sp, 0x28
    ctx->r19 = ADD32(ctx->r29, 0X28);
    // 0x80005148: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x8000514C: sw          $ra, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r31;
    // 0x80005150: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x80005154: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80005158: bne         $a0, $v0, L_800051A4
    if (ctx->r4 != ctx->r2) {
        // 0x8000515C: sw          $a0, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r4;
            goto L_800051A4;
    }
    // 0x8000515C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80005160: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // 0x80005164: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80005168: addiu       $s1, $v0, 0xA80
    ctx->r17 = ADD32(ctx->r2, 0XA80);
L_8000516C:
    // 0x8000516C: lbu         $v0, 0x4E($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X4E);
    // 0x80005170: beq         $v0, $zero, L_8000518C
    if (ctx->r2 == 0) {
        // 0x80005174: addu        $a0, $s0, $zero
        ctx->r4 = ADD32(ctx->r16, 0);
            goto L_8000518C;
    }
    // 0x80005174: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80005178: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    // 0x8000517C: jal         0x80003A0C
    // 0x80005180: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    find_manifest_entry(rdram, ctx);
        goto after_0;
    // 0x80005180: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    after_0:
    // 0x80005184: bnel        $v0, $zero, L_800051B0
    if (ctx->r2 != 0) {
        // 0x80005188: sw          $s0, 0x0($s3)
        MEM_W(0X0, ctx->r19) = ctx->r16;
            goto L_800051B0;
    }
    goto skip_0;
    // 0x80005188: sw          $s0, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r16;
    skip_0:
L_8000518C:
    // 0x8000518C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80005190: sltiu       $v0, $s0, 0x4
    ctx->r2 = ctx->r16 < 0X4 ? 1 : 0;
    // 0x80005194: bne         $v0, $zero, L_8000516C
    if (ctx->r2 != 0) {
        // 0x80005198: addiu       $s1, $s1, 0x50
        ctx->r17 = ADD32(ctx->r17, 0X50);
            goto L_8000516C;
    }
    // 0x80005198: addiu       $s1, $s1, 0x50
    ctx->r17 = ADD32(ctx->r17, 0X50);
    // 0x8000519C: j           L_800051B4
    // 0x800051A0: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
        goto L_800051B4;
    // 0x800051A0: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
L_800051A4:
    // 0x800051A4: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    // 0x800051A8: jal         0x80003A0C
    // 0x800051AC: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    find_manifest_entry(rdram, ctx);
        goto after_1;
    // 0x800051AC: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    after_1:
L_800051B0:
    // 0x800051B0: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
L_800051B4:
    // 0x800051B4: beq         $v1, $zero, L_800051DC
    if (ctx->r3 == 0) {
        // 0x800051B8: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_800051DC;
    }
    // 0x800051B8: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x800051BC: lbu         $v0, 0xC($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0XC);
    // 0x800051C0: andi        $v0, $v0, 0x4
    ctx->r2 = ctx->r2 & 0X4;
    // 0x800051C4: beq         $v0, $zero, L_800051D8
    if (ctx->r2 == 0) {
        // 0x800051C8: nop
    
            goto L_800051D8;
    }
    // 0x800051C8: nop

    // 0x800051CC: lw          $v0, 0x8($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X8);
    // 0x800051D0: j           L_800051DC
    // 0x800051D4: nop

        goto L_800051DC;
    // 0x800051D4: nop

L_800051D8:
    // 0x800051D8: lw          $v0, 0x4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X4);
L_800051DC:
    // 0x800051DC: lw          $ra, 0x20($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X20);
    // 0x800051E0: lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X1C);
    // 0x800051E4: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x800051E8: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x800051EC: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x800051F0: jr          $ra
    // 0x800051F4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800051F4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_800051F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800051F8: jr          $ra
    // 0x800051FC: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    return;
    // 0x800051FC: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
;}
RECOMP_FUNC void func_80005200(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80005200: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80005204: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80005208: jal         0x80003480
    // 0x8000520C: nop

    func_80003480(rdram, ctx);
        goto after_0;
    // 0x8000520C: nop

    after_0:
    // 0x80005210: jal         0x80003638
    // 0x80005214: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    func_80003638(rdram, ctx);
        goto after_1;
    // 0x80005214: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    after_1:
    // 0x80005218: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x8000521C: jr          $ra
    // 0x80005220: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80005220: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80005224(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80005224: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80005228: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8000522C: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x80005230: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80005234: jal         0x80001ACC
    // 0x80005238: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    rs_malloc(rdram, ctx);
        goto after_0;
    // 0x80005238: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_0:
    // 0x8000523C: bne         $v0, $zero, L_8000524C
    if (ctx->r2 != 0) {
        // 0x80005240: addu        $a0, $s0, $zero
        ctx->r4 = ADD32(ctx->r16, 0);
            goto L_8000524C;
    }
    // 0x80005240: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80005244: jal         0x80001ACC
    // 0x80005248: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    rs_malloc(rdram, ctx);
        goto after_1;
    // 0x80005248: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_1:
L_8000524C:
    // 0x8000524C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80005250: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80005254: jr          $ra
    // 0x80005258: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80005258: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void rs_zcfree(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000525C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80005260: beq         $a0, $zero, L_80005270
    if (ctx->r4 == 0) {
        // 0x80005264: sw          $ra, 0x10($sp)
        MEM_W(0X10, ctx->r29) = ctx->r31;
            goto L_80005270;
    }
    // 0x80005264: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80005268: jal         0x80001C98
    // 0x8000526C: nop

    rs_free(rdram, ctx);
        goto after_0;
    // 0x8000526C: nop

    after_0:
L_80005270:
    // 0x80005270: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80005274: jr          $ra
    // 0x80005278: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80005278: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void rs_zcalloc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000527C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80005280: mult        $a0, $a1
    result = S64(S32(ctx->r4)) * S64(S32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80005284: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x80005288: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x8000528C: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x80005290: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80005294: mflo        $s1
    ctx->r17 = lo;
    // 0x80005298: jal         0x80001ACC
    // 0x8000529C: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    rs_malloc(rdram, ctx);
        goto after_0;
    // 0x8000529C: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_0:
    // 0x800052A0: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // 0x800052A4: bne         $s0, $zero, L_800052B8
    if (ctx->r16 != 0) {
        // 0x800052A8: addu        $a0, $s1, $zero
        ctx->r4 = ADD32(ctx->r17, 0);
            goto L_800052B8;
    }
    // 0x800052A8: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x800052AC: jal         0x80001ACC
    // 0x800052B0: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    rs_malloc(rdram, ctx);
        goto after_1;
    // 0x800052B0: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_1:
    // 0x800052B4: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
L_800052B8:
    // 0x800052B8: beq         $s0, $zero, L_800052CC
    if (ctx->r16 == 0) {
        // 0x800052BC: addu        $a0, $s0, $zero
        ctx->r4 = ADD32(ctx->r16, 0);
            goto L_800052CC;
    }
    // 0x800052BC: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800052C0: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x800052C4: jal         0x800078E0
    // 0x800052C8: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    rs_memset(rdram, ctx);
        goto after_2;
    // 0x800052C8: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    after_2:
L_800052CC:
    // 0x800052CC: addu        $v0, $s0, $zero
    ctx->r2 = ADD32(ctx->r16, 0);
    // 0x800052D0: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x800052D4: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x800052D8: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x800052DC: jr          $ra
    // 0x800052E0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800052E0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_800052E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800052E4: jr          $ra
    // 0x800052E8: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    return;
    // 0x800052E8: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
;}
RECOMP_FUNC void func_800052EC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800052EC: jr          $ra
    // 0x800052F0: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    return;
    // 0x800052F0: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
;}
RECOMP_FUNC void func_800052F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800052F4: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x800052F8: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800052FC: addiu       $v0, $v0, 0xBC0
    ctx->r2 = ADD32(ctx->r2, 0XBC0);
    // 0x80005300: sll         $v1, $a0, 1
    ctx->r3 = S32(ctx->r4 << 1);
    // 0x80005304: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x80005308: sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3 << 3);
    // 0x8000530C: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80005310: addiu       $a1, $a1, 0xA80
    ctx->r5 = ADD32(ctx->r5, 0XA80);
    // 0x80005314: lw          $a0, 0x10($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X10);
    // 0x80005318: lw          $v1, 0x4($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X4);
    // 0x8000531C: sll         $v0, $a0, 2
    ctx->r2 = S32(ctx->r4 << 2);
    // 0x80005320: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x80005324: sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2 << 4);
    // 0x80005328: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x8000532C: lw          $a0, 0x44($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X44);
    // 0x80005330: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80005334: jr          $ra
    // 0x80005338: addu        $v0, $a0, $v0
    ctx->r2 = ADD32(ctx->r4, ctx->r2);
    return;
    // 0x80005338: addu        $v0, $a0, $v0
    ctx->r2 = ADD32(ctx->r4, ctx->r2);
;}
RECOMP_FUNC void func_8000533C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000533C: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80005340: lbu         $v0, 0xA70($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0XA70);
    // 0x80005344: jr          $ra
    // 0x80005348: nop

    return;
    // 0x80005348: nop

;}
RECOMP_FUNC void func_8000534C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000534C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80005350: addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
    // 0x80005354: bgtz        $a1, L_80005360
    if (SIGNED(ctx->r5) > 0) {
        // 0x80005358: sw          $ra, 0x10($sp)
        MEM_W(0X10, ctx->r29) = ctx->r31;
            goto L_80005360;
    }
    // 0x80005358: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x8000535C: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
L_80005360:
    // 0x80005360: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80005364: lw          $a0, 0xD54($v0)
    ctx->r4 = MEM_W(ctx->r2, 0XD54);
    // 0x80005368: jal         0x8000725C
    // 0x8000536C: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    func_8000725C(rdram, ctx);
        goto after_0;
    // 0x8000536C: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    after_0:
    // 0x80005370: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80005374: jr          $ra
    // 0x80005378: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80005378: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void fake_func_8000537C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
;}
RECOMP_FUNC void func_80005380(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80005380: addu        $a3, $a0, $zero
    ctx->r7 = ADD32(ctx->r4, 0);
    // 0x80005384: bne         $a3, $zero, L_8000539C
    if (ctx->r7 != 0) {
        // 0x80005388: addu        $t0, $a1, $zero
        ctx->r8 = ADD32(ctx->r5, 0);
            goto L_8000539C;
    }
    // 0x80005388: addu        $t0, $a1, $zero
    ctx->r8 = ADD32(ctx->r5, 0);
    // 0x8000538C: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80005390: sw          $zero, 0x1260($v0)
    MEM_W(0X1260, ctx->r2) = 0;
    // 0x80005394: jr          $ra
    // 0x80005398: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    return;
    // 0x80005398: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_8000539C:
    // 0x8000539C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800053A0: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x800053A4: addiu       $a2, $t0, -0x10
    ctx->r6 = ADD32(ctx->r8, -0X10);
    // 0x800053A8: sw          $a3, 0x1260($v1)
    MEM_W(0X1260, ctx->r3) = ctx->r7;
    // 0x800053AC: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x800053B0: addu        $a0, $a3, $a2
    ctx->r4 = ADD32(ctx->r7, ctx->r6);
    // 0x800053B4: sw          $a0, 0x1264($v1)
    MEM_W(0X1264, ctx->r3) = ctx->r4;
    // 0x800053B8: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x800053BC: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x800053C0: sw          $a2, 0x1268($v1)
    MEM_W(0X1268, ctx->r3) = ctx->r6;
    // 0x800053C4: addiu       $v1, $t0, -0x36
    ctx->r3 = ADD32(ctx->r8, -0X36);
    // 0x800053C8: sw          $v1, 0x126C($a1)
    MEM_W(0X126C, ctx->r5) = ctx->r3;
    // 0x800053CC: sw          $a0, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r4;
    // 0x800053D0: sw          $zero, 0x4($a3)
    MEM_W(0X4, ctx->r7) = 0;
    // 0x800053D4: sw          $a2, 0x8($a3)
    MEM_W(0X8, ctx->r7) = ctx->r6;
    // 0x800053D8: sw          $zero, 0xC($a3)
    MEM_W(0XC, ctx->r7) = 0;
    // 0x800053DC: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
    // 0x800053E0: sw          $a3, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r7;
    // 0x800053E4: sw          $zero, 0x8($a0)
    MEM_W(0X8, ctx->r4) = 0;
    // 0x800053E8: jr          $ra
    // 0x800053EC: sw          $zero, 0xC($a0)
    MEM_W(0XC, ctx->r4) = 0;
    return;
    // 0x800053EC: sw          $zero, 0xC($a0)
    MEM_W(0XC, ctx->r4) = 0;
;}
RECOMP_FUNC void func_800053F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800053F0: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800053F4: lw          $v0, 0x1260($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X1260);
    // 0x800053F8: bne         $v0, $zero, L_80005408
    if (ctx->r2 != 0) {
        // 0x800053FC: lui         $v0, 0x8011
        ctx->r2 = S32(0X8011 << 16);
            goto L_80005408;
    }
    // 0x800053FC: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80005400: jr          $ra
    // 0x80005404: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    return;
    // 0x80005404: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_80005408:
    // 0x80005408: lw          $v0, 0x126C($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X126C);
    // 0x8000540C: jr          $ra
    // 0x80005410: addiu       $v0, $v0, -0x23
    ctx->r2 = ADD32(ctx->r2, -0X23);
    return;
    // 0x80005410: addiu       $v0, $v0, -0x23
    ctx->r2 = ADD32(ctx->r2, -0X23);
;}
RECOMP_FUNC void func_80005414(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80005414: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80005418: lw          $v0, 0x1260($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X1260);
    // 0x8000541C: beq         $v0, $zero, L_800054BC
    if (ctx->r2 == 0) {
        // 0x80005420: addu        $t1, $a1, $zero
        ctx->r9 = ADD32(ctx->r5, 0);
            goto L_800054BC;
    }
    // 0x80005420: addu        $t1, $a1, $zero
    ctx->r9 = ADD32(ctx->r5, 0);
    // 0x80005424: addu        $a2, $v0, $zero
    ctx->r6 = ADD32(ctx->r2, 0);
    // 0x80005428: addiu       $v0, $a0, 0xF
    ctx->r2 = ADD32(ctx->r4, 0XF);
    // 0x8000542C: addiu       $v1, $zero, -0x10
    ctx->r3 = ADD32(0, -0X10);
    // 0x80005430: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x80005434: lw          $v1, 0x0($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X0);
    // 0x80005438: beq         $v1, $zero, L_8000546C
    if (ctx->r3 == 0) {
        // 0x8000543C: addiu       $a3, $v0, 0x10
        ctx->r7 = ADD32(ctx->r2, 0X10);
            goto L_8000546C;
    }
    // 0x8000543C: addiu       $a3, $v0, 0x10
    ctx->r7 = ADD32(ctx->r2, 0X10);
L_80005440:
    // 0x80005440: lw          $a0, 0x8($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X8);
    // 0x80005444: sltu        $v0, $a0, $a3
    ctx->r2 = ctx->r4 < ctx->r7 ? 1 : 0;
    // 0x80005448: bne         $v0, $zero, L_8000545C
    if (ctx->r2 != 0) {
        // 0x8000544C: nop
    
            goto L_8000545C;
    }
    // 0x8000544C: nop

    // 0x80005450: lw          $v0, 0xC($a2)
    ctx->r2 = MEM_W(ctx->r6, 0XC);
    // 0x80005454: beq         $v0, $zero, L_80005478
    if (ctx->r2 == 0) {
        // 0x80005458: addu        $v1, $a2, $a3
        ctx->r3 = ADD32(ctx->r6, ctx->r7);
            goto L_80005478;
    }
    // 0x80005458: addu        $v1, $a2, $a3
    ctx->r3 = ADD32(ctx->r6, ctx->r7);
L_8000545C:
    // 0x8000545C: lw          $a2, 0x0($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X0);
    // 0x80005460: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x80005464: bne         $v0, $zero, L_80005440
    if (ctx->r2 != 0) {
        // 0x80005468: nop
    
            goto L_80005440;
    }
    // 0x80005468: nop

L_8000546C:
    // 0x8000546C: addu        $t0, $zero, $zero
    ctx->r8 = ADD32(0, 0);
L_80005470:
    // 0x80005470: jr          $ra
    // 0x80005474: addu        $v0, $t0, $zero
    ctx->r2 = ADD32(ctx->r8, 0);
    return;
    // 0x80005474: addu        $v0, $t0, $zero
    ctx->r2 = ADD32(ctx->r8, 0);
L_80005478:
    // 0x80005478: subu        $v0, $a0, $a3
    ctx->r2 = SUB32(ctx->r4, ctx->r7);
    // 0x8000547C: addiu       $t0, $a2, 0x10
    ctx->r8 = ADD32(ctx->r6, 0X10);
    // 0x80005480: sw          $v0, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r2;
    // 0x80005484: sw          $a2, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r6;
    // 0x80005488: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x8000548C: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80005490: sw          $zero, 0xC($v1)
    MEM_W(0XC, ctx->r3) = 0;
    // 0x80005494: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x80005498: lw          $v0, 0x126C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X126C);
    // 0x8000549C: lw          $a1, 0x0($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X0);
    // 0x800054A0: subu        $v0, $v0, $a3
    ctx->r2 = SUB32(ctx->r2, ctx->r7);
    // 0x800054A4: sw          $v0, 0x126C($a0)
    MEM_W(0X126C, ctx->r4) = ctx->r2;
    // 0x800054A8: sw          $a2, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r6;
    // 0x800054AC: sw          $a3, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->r7;
    // 0x800054B0: sw          $t1, 0xC($a2)
    MEM_W(0XC, ctx->r6) = ctx->r9;
    // 0x800054B4: j           L_80005470
    // 0x800054B8: sw          $v1, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r3;
        goto L_80005470;
    // 0x800054B8: sw          $v1, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r3;
L_800054BC:
    // 0x800054BC: jr          $ra
    // 0x800054C0: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    return;
    // 0x800054C0: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
;}
RECOMP_FUNC void func_800054C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800054C4: addu        $a3, $a0, $zero
    ctx->r7 = ADD32(ctx->r4, 0);
    // 0x800054C8: beq         $a3, $zero, L_80005558
    if (ctx->r7 == 0) {
        // 0x800054CC: addiu       $a2, $a3, -0x10
        ctx->r6 = ADD32(ctx->r7, -0X10);
            goto L_80005558;
    }
    // 0x800054CC: addiu       $a2, $a3, -0x10
    ctx->r6 = ADD32(ctx->r7, -0X10);
    // 0x800054D0: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x800054D4: lw          $v0, 0x126C($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X126C);
    // 0x800054D8: lw          $v1, 0x8($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X8);
    // 0x800054DC: lw          $a0, 0xC($a2)
    ctx->r4 = MEM_W(ctx->r6, 0XC);
    // 0x800054E0: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800054E4: sw          $v0, 0x126C($a1)
    MEM_W(0X126C, ctx->r5) = ctx->r2;
    // 0x800054E8: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
    // 0x800054EC: sw          $zero, 0xC($a2)
    MEM_W(0XC, ctx->r6) = 0;
    // 0x800054F0: lw          $v1, -0x10($a3)
    ctx->r3 = MEM_W(ctx->r7, -0X10);
    // 0x800054F4: lw          $v0, 0xC($v1)
    ctx->r2 = MEM_W(ctx->r3, 0XC);
    // 0x800054F8: bne         $v0, $zero, L_80005524
    if (ctx->r2 != 0) {
        // 0x800054FC: nop
    
            goto L_80005524;
    }
    // 0x800054FC: nop

    // 0x80005500: lw          $v0, 0x8($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X8);
    // 0x80005504: lw          $v1, 0x8($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X8);
    // 0x80005508: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8000550C: sw          $v0, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->r2;
    // 0x80005510: lw          $v1, -0x10($a3)
    ctx->r3 = MEM_W(ctx->r7, -0X10);
    // 0x80005514: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80005518: beql        $v0, $zero, L_80005524
    if (ctx->r2 == 0) {
        // 0x8000551C: sw          $a2, 0x4($v1)
        MEM_W(0X4, ctx->r3) = ctx->r6;
            goto L_80005524;
    }
    goto skip_0;
    // 0x8000551C: sw          $a2, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r6;
    skip_0:
    // 0x80005520: sw          $v0, -0x10($a3)
    MEM_W(-0X10, ctx->r7) = ctx->r2;
L_80005524:
    // 0x80005524: lw          $a0, 0x4($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X4);
    // 0x80005528: beq         $a0, $zero, L_80005558
    if (ctx->r4 == 0) {
        // 0x8000552C: nop
    
            goto L_80005558;
    }
    // 0x8000552C: nop

    // 0x80005530: lw          $v0, 0xC($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XC);
    // 0x80005534: bne         $v0, $zero, L_80005558
    if (ctx->r2 != 0) {
        // 0x80005538: nop
    
            goto L_80005558;
    }
    // 0x80005538: nop

    // 0x8000553C: lw          $v0, 0x8($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X8);
    // 0x80005540: lw          $v1, 0x8($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X8);
    // 0x80005544: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80005548: sw          $v0, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r2;
    // 0x8000554C: lw          $v1, 0x4($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X4);
    // 0x80005550: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x80005554: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
L_80005558:
    // 0x80005558: jr          $ra
    // 0x8000555C: nop

    return;
    // 0x8000555C: nop

;}
RECOMP_FUNC void func_80005560(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80005560: jr          $ra
    // 0x80005564: nop

    return;
    // 0x80005564: nop

;}
RECOMP_FUNC void fake_func_80005568(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
;}
RECOMP_FUNC void func_80005570(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80005570: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80005574: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x80005578: lui         $s4, 0x8011
    ctx->r20 = S32(0X8011 << 16);
    // 0x8000557C: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x80005580: lui         $s2, 0x8011
    ctx->r18 = S32(0X8011 << 16);
    // 0x80005584: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x80005588: lui         $s1, 0x8011
    ctx->r17 = S32(0X8011 << 16);
    // 0x8000558C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80005590: lui         $s0, 0x8011
    ctx->r16 = S32(0X8011 << 16);
    // 0x80005594: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80005598: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x8000559C: addiu       $s5, $v0, 0x12B0
    ctx->r21 = ADD32(ctx->r2, 0X12B0);
    // 0x800055A0: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800055A4: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x800055A8: addiu       $s3, $v0, 0x1290
    ctx->r19 = ADD32(ctx->r2, 0X1290);
    // 0x800055AC: sw          $ra, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r31;
L_800055B0:
    // 0x800055B0: lw          $a0, 0x26BC($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X26BC);
    // 0x800055B4: jal         0x80006F24
    // 0x800055B8: nop

    func_80006F24(rdram, ctx);
        goto after_0;
    // 0x800055B8: nop

    after_0:
    // 0x800055BC: lw          $a0, 0x26B0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X26B0);
    // 0x800055C0: lw          $v1, 0x26B4($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X26B4);
    // 0x800055C4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800055C8: sw          $v0, 0x26B8($s2)
    MEM_W(0X26B8, ctx->r18) = ctx->r2;
    // 0x800055CC: beq         $a0, $v1, L_80005690
    if (ctx->r4 == ctx->r3) {
        // 0x800055D0: nop
    
            goto L_80005690;
    }
    // 0x800055D0: nop

L_800055D4:
    // 0x800055D4: lw          $v1, 0x26B0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X26B0);
    // 0x800055D8: addiu       $a1, $v1, 0x1
    ctx->r5 = ADD32(ctx->r3, 0X1);
    // 0x800055DC: addu        $a0, $a1, $zero
    ctx->r4 = ADD32(ctx->r5, 0);
    // 0x800055E0: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x800055E4: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800055E8: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800055EC: bgez        $a1, L_800055F8
    if (SIGNED(ctx->r5) >= 0) {
        // 0x800055F0: addu        $a2, $v0, $s5
        ctx->r6 = ADD32(ctx->r2, ctx->r21);
            goto L_800055F8;
    }
    // 0x800055F0: addu        $a2, $v0, $s5
    ctx->r6 = ADD32(ctx->r2, ctx->r21);
    // 0x800055F4: addiu       $a0, $v1, 0x100
    ctx->r4 = ADD32(ctx->r3, 0X100);
L_800055F8:
    // 0x800055F8: sra         $v0, $a0, 8
    ctx->r2 = S32(SIGNED(ctx->r4) >> 8);
    // 0x800055FC: sll         $v0, $v0, 8
    ctx->r2 = S32(ctx->r2 << 8);
    // 0x80005600: subu        $v1, $a1, $v0
    ctx->r3 = SUB32(ctx->r5, ctx->r2);
    // 0x80005604: sw          $v1, 0x26B0($s1)
    MEM_W(0X26B0, ctx->r17) = ctx->r3;
    // 0x80005608: lbu         $v0, 0x10($a2)
    ctx->r2 = MEM_BU(ctx->r6, 0X10);
    // 0x8000560C: bne         $v0, $zero, L_80005660
    if (ctx->r2 != 0) {
        // 0x80005610: lui         $a0, 0x8011
        ctx->r4 = S32(0X8011 << 16);
            goto L_80005660;
    }
    // 0x80005610: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80005614: lw          $v0, 0x8($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X8);
    // 0x80005618: addiu       $a0, $a0, 0x1270
    ctx->r4 = ADD32(ctx->r4, 0X1270);
    // 0x8000561C: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x80005620: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x80005624: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80005628: sw          $s3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r19;
    // 0x8000562C: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // 0x80005630: lw          $a3, 0x4($a2)
    ctx->r7 = MEM_W(ctx->r6, 0X4);
    // 0x80005634: jal         0x80032420
    // 0x80005638: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    osPiStartDma_recomp(rdram, ctx);
        goto after_1;
    // 0x80005638: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    after_1:
    // 0x8000563C: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // 0x80005640: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80005644: jal         0x800331D0
    // 0x80005648: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_2;
    // 0x80005648: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_2:
    // 0x8000564C: lw          $a0, 0x26BC($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X26BC);
    // 0x80005650: jal         0x800072AC
    // 0x80005654: nop

    func_800072AC(rdram, ctx);
        goto after_3;
    // 0x80005654: nop

    after_3:
    // 0x80005658: j           L_80005680
    // 0x8000565C: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
        goto L_80005680;
    // 0x8000565C: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
L_80005660:
    // 0x80005660: lw          $v0, 0x26B4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X26B4);
    // 0x80005664: beql        $v1, $v0, L_8000566C
    if (ctx->r3 == ctx->r2) {
        // 0x80005668: sw          $zero, 0x26B8($s2)
        MEM_W(0X26B8, ctx->r18) = 0;
            goto L_8000566C;
    }
    goto skip_0;
    // 0x80005668: sw          $zero, 0x26B8($s2)
    MEM_W(0X26B8, ctx->r18) = 0;
    skip_0:
L_8000566C:
    // 0x8000566C: lw          $a0, 0xC($a2)
    ctx->r4 = MEM_W(ctx->r6, 0XC);
    // 0x80005670: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80005674: jal         0x80033410
    // 0x80005678: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    osSendMesg_recomp(rdram, ctx);
        goto after_4;
    // 0x80005678: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    after_4:
    // 0x8000567C: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
L_80005680:
    // 0x80005680: lw          $v1, 0x26B0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X26B0);
    // 0x80005684: lw          $v0, 0x26B4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X26B4);
    // 0x80005688: bne         $v1, $v0, L_800055D4
    if (ctx->r3 != ctx->r2) {
        // 0x8000568C: nop
    
            goto L_800055D4;
    }
    // 0x8000568C: nop

L_80005690:
    // 0x80005690: sw          $zero, 0x26B8($s2)
    MEM_W(0X26B8, ctx->r18) = 0;
    // 0x80005694: j           L_800055B0
    // 0x80005698: nop

        goto L_800055B0;
    // 0x80005698: nop

;}
RECOMP_FUNC void func_8000569C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000569C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800056A0: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x800056A4: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x800056A8: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800056AC: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x800056B0: lw          $a0, 0x26B0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X26B0);
    // 0x800056B4: lw          $v1, 0x26B4($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X26B4);
    // 0x800056B8: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x800056BC: addu        $s1, $a1, $zero
    ctx->r17 = ADD32(ctx->r5, 0);
    // 0x800056C0: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x800056C4: addu        $s2, $a2, $zero
    ctx->r18 = ADD32(ctx->r6, 0);
    // 0x800056C8: slt         $v0, $a0, $v1
    ctx->r2 = SIGNED(ctx->r4) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800056CC: bne         $v0, $zero, L_800056DC
    if (ctx->r2 != 0) {
        // 0x800056D0: sw          $ra, 0x34($sp)
        MEM_W(0X34, ctx->r29) = ctx->r31;
            goto L_800056DC;
    }
    // 0x800056D0: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x800056D4: j           L_800056E0
    // 0x800056D8: subu        $v0, $a0, $v1
    ctx->r2 = SUB32(ctx->r4, ctx->r3);
        goto L_800056E0;
    // 0x800056D8: subu        $v0, $a0, $v1
    ctx->r2 = SUB32(ctx->r4, ctx->r3);
L_800056DC:
    // 0x800056DC: subu        $v0, $v1, $a0
    ctx->r2 = SUB32(ctx->r3, ctx->r4);
L_800056E0:
    // 0x800056E0: addu        $v0, $v0, $s1
    ctx->r2 = ADD32(ctx->r2, ctx->r17);
    // 0x800056E4: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800056E8: slti        $v0, $v0, 0x100
    ctx->r2 = SIGNED(ctx->r2) < 0X100 ? 1 : 0;
    // 0x800056EC: beq         $v0, $zero, L_80005838
    if (ctx->r2 == 0) {
        // 0x800056F0: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_80005838;
    }
    // 0x800056F0: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x800056F4: jal         0x8000533C
    // 0x800056F8: nop

    func_8000533C(rdram, ctx);
        goto after_0;
    // 0x800056F8: nop

    after_0:
    // 0x800056FC: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x80005700: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
    // 0x80005704: beq         $v0, $v1, L_80005838
    if (ctx->r2 == ctx->r3) {
        // 0x80005708: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_80005838;
    }
    // 0x80005708: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x8000570C: blez        $s1, L_8000578C
    if (SIGNED(ctx->r17) <= 0) {
        // 0x80005710: addu        $t0, $zero, $zero
        ctx->r8 = ADD32(0, 0);
            goto L_8000578C;
    }
    // 0x80005710: addu        $t0, $zero, $zero
    ctx->r8 = ADD32(0, 0);
    // 0x80005714: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80005718: addiu       $t2, $v0, 0x12B0
    ctx->r10 = ADD32(ctx->r2, 0X12B0);
    // 0x8000571C: lui         $t1, 0x8011
    ctx->r9 = S32(0X8011 << 16);
    // 0x80005720: addiu       $a3, $s0, 0x8
    ctx->r7 = ADD32(ctx->r16, 0X8);
L_80005724:
    // 0x80005724: lw          $v0, 0x26B4($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X26B4);
    // 0x80005728: sll         $v1, $v0, 2
    ctx->r3 = S32(ctx->r2 << 2);
    // 0x8000572C: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80005730: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x80005734: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80005738: addu        $v1, $v1, $t2
    ctx->r3 = ADD32(ctx->r3, ctx->r10);
    // 0x8000573C: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x80005740: lw          $v0, -0x4($a3)
    ctx->r2 = MEM_W(ctx->r7, -0X4);
    // 0x80005744: sw          $v0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r2;
    // 0x80005748: lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X0);
    // 0x8000574C: sb          $zero, 0x10($v1)
    MEM_B(0X10, ctx->r3) = 0;
    // 0x80005750: lw          $a2, 0x26B4($t1)
    ctx->r6 = MEM_W(ctx->r9, 0X26B4);
    // 0x80005754: addiu       $a0, $a2, 0x1
    ctx->r4 = ADD32(ctx->r6, 0X1);
    // 0x80005758: addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
    // 0x8000575C: bgez        $a0, L_80005768
    if (SIGNED(ctx->r4) >= 0) {
        // 0x80005760: sw          $v0, 0x8($v1)
        MEM_W(0X8, ctx->r3) = ctx->r2;
            goto L_80005768;
    }
    // 0x80005760: sw          $v0, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r2;
    // 0x80005764: addiu       $a1, $a2, 0x100
    ctx->r5 = ADD32(ctx->r6, 0X100);
L_80005768:
    // 0x80005768: sra         $v0, $a1, 8
    ctx->r2 = S32(SIGNED(ctx->r5) >> 8);
    // 0x8000576C: sll         $v0, $v0, 8
    ctx->r2 = S32(ctx->r2 << 8);
    // 0x80005770: subu        $v0, $a0, $v0
    ctx->r2 = SUB32(ctx->r4, ctx->r2);
    // 0x80005774: sw          $v0, 0x26B4($t1)
    MEM_W(0X26B4, ctx->r9) = ctx->r2;
    // 0x80005778: addiu       $a3, $a3, 0xC
    ctx->r7 = ADD32(ctx->r7, 0XC);
    // 0x8000577C: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x80005780: slt         $v0, $t0, $s1
    ctx->r2 = SIGNED(ctx->r8) < SIGNED(ctx->r17) ? 1 : 0;
    // 0x80005784: bne         $v0, $zero, L_80005724
    if (ctx->r2 != 0) {
        // 0x80005788: addiu       $s0, $s0, 0xC
        ctx->r16 = ADD32(ctx->r16, 0XC);
            goto L_80005724;
    }
    // 0x80005788: addiu       $s0, $s0, 0xC
    ctx->r16 = ADD32(ctx->r16, 0XC);
L_8000578C:
    // 0x8000578C: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80005790: lui         $s0, 0x8011
    ctx->r16 = S32(0X8011 << 16);
    // 0x80005794: lw          $v1, 0x26B4($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X26B4);
    // 0x80005798: addiu       $a0, $a0, 0x12B0
    ctx->r4 = ADD32(ctx->r4, 0X12B0);
    // 0x8000579C: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x800057A0: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800057A4: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800057A8: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x800057AC: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x800057B0: sb          $v1, 0x10($v0)
    MEM_B(0X10, ctx->r2) = ctx->r3;
    // 0x800057B4: lw          $v1, 0x26B4($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X26B4);
    // 0x800057B8: addiu       $a1, $v1, 0x1
    ctx->r5 = ADD32(ctx->r3, 0X1);
    // 0x800057BC: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    // 0x800057C0: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x800057C4: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800057C8: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800057CC: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x800057D0: bgez        $a1, L_800057DC
    if (SIGNED(ctx->r5) >= 0) {
        // 0x800057D4: sw          $s2, 0xC($v0)
        MEM_W(0XC, ctx->r2) = ctx->r18;
            goto L_800057DC;
    }
    // 0x800057D4: sw          $s2, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r18;
    // 0x800057D8: addiu       $a2, $v1, 0x100
    ctx->r6 = ADD32(ctx->r3, 0X100);
L_800057DC:
    // 0x800057DC: sra         $v0, $a2, 8
    ctx->r2 = S32(SIGNED(ctx->r6) >> 8);
    // 0x800057E0: sll         $v0, $v0, 8
    ctx->r2 = S32(ctx->r2 << 8);
    // 0x800057E4: subu        $v0, $a1, $v0
    ctx->r2 = SUB32(ctx->r5, ctx->r2);
    // 0x800057E8: jal         0x8000533C
    // 0x800057EC: sw          $v0, 0x26B4($s0)
    MEM_W(0X26B4, ctx->r16) = ctx->r2;
    func_8000533C(rdram, ctx);
        goto after_1;
    // 0x800057EC: sw          $v0, 0x26B4($s0)
    MEM_W(0X26B4, ctx->r16) = ctx->r2;
    after_1:
    // 0x800057F0: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x800057F4: bne         $v0, $zero, L_80005838
    if (ctx->r2 != 0) {
        // 0x800057F8: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80005838;
    }
    // 0x800057F8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800057FC: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80005800: lw          $v1, 0x26B0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X26B0);
    // 0x80005804: lw          $v0, 0x26B4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X26B4);
    // 0x80005808: beq         $v1, $v0, L_80005834
    if (ctx->r3 == ctx->r2) {
        // 0x8000580C: lui         $v0, 0x8011
        ctx->r2 = S32(0X8011 << 16);
            goto L_80005834;
    }
    // 0x8000580C: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80005810: lw          $v0, 0x26B8($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X26B8);
    // 0x80005814: bne         $v0, $zero, L_80005838
    if (ctx->r2 != 0) {
        // 0x80005818: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80005838;
    }
    // 0x80005818: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8000581C: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80005820: lw          $a0, 0x26BC($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X26BC);
    // 0x80005824: addiu       $a2, $sp, 0x10
    ctx->r6 = ADD32(ctx->r29, 0X10);
    // 0x80005828: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // 0x8000582C: jal         0x80006F78
    // 0x80005830: addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
    func_80006F78(rdram, ctx);
        goto after_2;
    // 0x80005830: addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
    after_2:
L_80005834:
    // 0x80005834: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80005838:
    // 0x80005838: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x8000583C: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x80005840: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x80005844: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x80005848: jr          $ra
    // 0x8000584C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8000584C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_80005850(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80005850: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80005854: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80005858: addiu       $a0, $a0, 0x1290
    ctx->r4 = ADD32(ctx->r4, 0X1290);
    // 0x8000585C: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x80005860: addiu       $a1, $a1, 0x1288
    ctx->r5 = ADD32(ctx->r5, 0X1288);
    // 0x80005864: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80005868: jal         0x8002B300
    // 0x8000586C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_0;
    // 0x8000586C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x80005870: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x80005874: addiu       $a1, $zero, 0x200
    ctx->r5 = ADD32(0, 0X200);
    // 0x80005878: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x8000587C: sw          $zero, 0x26B4($v0)
    MEM_W(0X26B4, ctx->r2) = 0;
    // 0x80005880: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80005884: sw          $zero, 0x26B0($v0)
    MEM_W(0X26B0, ctx->r2) = 0;
    // 0x80005888: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x8000588C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    // 0x80005890: addiu       $a3, $a3, 0x5570
    ctx->r7 = ADD32(ctx->r7, 0X5570);
    // 0x80005894: sw          $zero, 0x26B8($v0)
    MEM_W(0X26B8, ctx->r2) = 0;
    // 0x80005898: jal         0x80006C28
    // 0x8000589C: addiu       $a2, $zero, 0x78
    ctx->r6 = ADD32(0, 0X78);
    func_80006C28(rdram, ctx);
        goto after_1;
    // 0x8000589C: addiu       $a2, $zero, 0x78
    ctx->r6 = ADD32(0, 0X78);
    after_1:
    // 0x800058A0: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x800058A4: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800058A8: jal         0x80006D9C
    // 0x800058AC: sw          $a0, 0x26BC($v0)
    MEM_W(0X26BC, ctx->r2) = ctx->r4;
    func_80006D9C(rdram, ctx);
        goto after_2;
    // 0x800058AC: sw          $a0, 0x26BC($v0)
    MEM_W(0X26BC, ctx->r2) = ctx->r4;
    after_2:
    // 0x800058B0: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x800058B4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800058B8: jr          $ra
    // 0x800058BC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800058BC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_800058C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800058C0: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800058C4: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x800058C8: lw          $a0, 0x26B0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X26B0);
    // 0x800058CC: lw          $v0, 0x26B4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X26B4);
    // 0x800058D0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800058D4: beq         $a0, $v0, L_8000590C
    if (ctx->r4 == ctx->r2) {
        // 0x800058D8: sw          $ra, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r31;
            goto L_8000590C;
    }
    // 0x800058D8: sw          $ra, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r31;
    // 0x800058DC: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800058E0: lw          $v0, 0x26B8($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X26B8);
    // 0x800058E4: bnel        $v0, $zero, L_80005910
    if (ctx->r2 != 0) {
        // 0x800058E8: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80005910;
    }
    goto skip_0;
    // 0x800058E8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_0:
    // 0x800058EC: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800058F0: lw          $a0, 0x26BC($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X26BC);
    // 0x800058F4: addiu       $a2, $sp, 0x10
    ctx->r6 = ADD32(ctx->r29, 0X10);
    // 0x800058F8: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // 0x800058FC: jal         0x80006F78
    // 0x80005900: addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
    func_80006F78(rdram, ctx);
        goto after_0;
    // 0x80005900: addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
    after_0:
    // 0x80005904: j           L_80005910
    // 0x80005908: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80005910;
    // 0x80005908: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8000590C:
    // 0x8000590C: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_80005910:
    // 0x80005910: lw          $ra, 0x28($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X28);
    // 0x80005914: jr          $ra
    // 0x80005918: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80005918: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_8000591C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000591C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80005920: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80005924: jal         0x800052F4
    // 0x80005928: nop

    func_800052F4(rdram, ctx);
        goto after_0;
    // 0x80005928: nop

    after_0:
    // 0x8000592C: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80005930: jr          $ra
    // 0x80005934: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80005934: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void setDmaSlotMaxTxSize(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80005938: addiu       $a0, $a0, 0xF
    ctx->r4 = ADD32(ctx->r4, 0XF);
    // 0x8000593C: addiu       $v0, $zero, -0x10
    ctx->r2 = ADD32(0, -0X10);
    // 0x80005940: and         $a0, $a0, $v0
    ctx->r4 = ctx->r4 & ctx->r2;
    // 0x80005944: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x80005948: lw          $v0, 0x1254($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X1254);
    // 0x8000594C: beql        $a0, $zero, L_80005954
    if (ctx->r4 == 0) {
        // 0x80005950: addiu       $a0, $zero, 0x10
        ctx->r4 = ADD32(0, 0X10);
            goto L_80005954;
    }
    goto skip_0;
    // 0x80005950: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    skip_0:
L_80005954:
    // 0x80005954: jr          $ra
    // 0x80005958: sw          $a0, 0x1254($v1)
    MEM_W(0X1254, ctx->r3) = ctx->r4;
    return;
    // 0x80005958: sw          $a0, 0x1254($v1)
    MEM_W(0X1254, ctx->r3) = ctx->r4;
;}
