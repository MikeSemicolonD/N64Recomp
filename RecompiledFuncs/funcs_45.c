#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void lv3_dealDamageHookA(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010349C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801034A0: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x801034A4: addiu       $a0, $a0, -0x696C
    ctx->r4 = ADD32(ctx->r4, -0X696C);
    // 0x801034A8: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x801034AC: jal         0x800C7390
    // 0x801034B0: addiu       $a1, $zero, 0x3A98
    ctx->r5 = ADD32(0, 0X3A98);
    dealDamagetoDatItem(rdram, ctx);
        goto after_0;
    // 0x801034B0: addiu       $a1, $zero, 0x3A98
    ctx->r5 = ADD32(0, 0X3A98);
    after_0:
    // 0x801034B4: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x801034B8: jr          $ra
    // 0x801034BC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x801034BC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void lv3_dealDamageHookB(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801034C0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801034C4: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x801034C8: addiu       $a0, $a0, -0x695C
    ctx->r4 = ADD32(ctx->r4, -0X695C);
    // 0x801034CC: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x801034D0: jal         0x800C7390
    // 0x801034D4: addiu       $a1, $zero, 0x32C8
    ctx->r5 = ADD32(0, 0X32C8);
    dealDamagetoDatItem(rdram, ctx);
        goto after_0;
    // 0x801034D4: addiu       $a1, $zero, 0x32C8
    ctx->r5 = ADD32(0, 0X32C8);
    after_0:
    // 0x801034D8: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x801034DC: jr          $ra
    // 0x801034E0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x801034E0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void lv3_dealDamageHookA_v2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801034E4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801034E8: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x801034EC: addiu       $a0, $a0, -0x696C
    ctx->r4 = ADD32(ctx->r4, -0X696C);
    // 0x801034F0: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x801034F4: jal         0x800C7390
    // 0x801034F8: addiu       $a1, $zero, 0x3A98
    ctx->r5 = ADD32(0, 0X3A98);
    dealDamagetoDatItem(rdram, ctx);
        goto after_0;
    // 0x801034F8: addiu       $a1, $zero, 0x3A98
    ctx->r5 = ADD32(0, 0X3A98);
    after_0:
    // 0x801034FC: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80103500: jr          $ra
    // 0x80103504: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80103504: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void playVoice_0x07(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80103508: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8010350C: addiu       $a0, $zero, 0x6F
    ctx->r4 = ADD32(0, 0X6F);
    // 0x80103510: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80103514: jal         0x800C7540
    // 0x80103518: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    setObjectiveBoolean(rdram, ctx);
        goto after_0;
    // 0x80103518: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_0:
    // 0x8010351C: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80103520: jr          $ra
    // 0x80103524: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80103524: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void lv3_objectiveSlot1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80103528: jr          $ra
    // 0x8010352C: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    return;
    // 0x8010352C: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
;}
RECOMP_FUNC void lv3_calculateFriendliesSaved(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80103530: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80103534: addiu       $a0, $zero, 0x1B
    ctx->r4 = ADD32(0, 0X1B);
    // 0x80103538: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8010353C: jal         0x800C761C
    // 0x80103540: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    getObjectiveCount(rdram, ctx);
        goto after_0;
    // 0x80103540: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    after_0:
    // 0x80103544: addiu       $a0, $zero, 0x1C
    ctx->r4 = ADD32(0, 0X1C);
    // 0x80103548: jal         0x800C761C
    // 0x8010354C: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    getObjectiveCount(rdram, ctx);
        goto after_1;
    // 0x8010354C: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    after_1:
    // 0x80103550: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x80103554: addu        $s0, $s0, $v0
    ctx->r16 = ADD32(ctx->r16, ctx->r2);
    // 0x80103558: addiu       $a0, $zero, 0x64
    ctx->r4 = ADD32(0, 0X64);
    // 0x8010355C: subu        $a0, $a0, $s0
    ctx->r4 = SUB32(ctx->r4, ctx->r16);
    // 0x80103560: jal         0x800C77B0
    // 0x80103564: sw          $s0, -0x2FAC($v1)
    MEM_W(-0X2FAC, ctx->r3) = ctx->r16;
    setFriendliesSaved(rdram, ctx);
        goto after_2;
    // 0x80103564: sw          $s0, -0x2FAC($v1)
    MEM_W(-0X2FAC, ctx->r3) = ctx->r16;
    after_2:
    // 0x80103568: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8010356C: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80103570: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x80103574: jr          $ra
    // 0x80103578: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80103578: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void fake_func_8010357C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
;}
RECOMP_FUNC void lv4_initializeObjectTracking(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80103580: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80103584: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x80103588: addiu       $a0, $a0, 0x3994
    ctx->r4 = ADD32(ctx->r4, 0X3994);
    // 0x8010358C: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    // 0x80103590: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80103594: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // 0x80103598: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x8010359C: sw          $zero, -0x2FA0($v0)
    MEM_W(-0X2FA0, ctx->r2) = 0;
    // 0x801035A0: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x801035A4: sw          $zero, -0x2F9C($v0)
    MEM_W(-0X2F9C, ctx->r2) = 0;
    // 0x801035A8: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x801035AC: sw          $zero, -0x2F98($v0)
    MEM_W(-0X2F98, ctx->r2) = 0;
    // 0x801035B0: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x801035B4: sw          $zero, -0x2F94($v0)
    MEM_W(-0X2F94, ctx->r2) = 0;
    // 0x801035B8: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x801035BC: sw          $zero, -0x2F90($v0)
    MEM_W(-0X2F90, ctx->r2) = 0;
    // 0x801035C0: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x801035C4: sw          $zero, -0x2F8C($v0)
    MEM_W(-0X2F8C, ctx->r2) = 0;
    // 0x801035C8: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x801035CC: sw          $zero, -0x2F88($v0)
    MEM_W(-0X2F88, ctx->r2) = 0;
    // 0x801035D0: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x801035D4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801035D8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x801035DC: sw          $zero, -0x2F84($v0)
    MEM_W(-0X2F84, ctx->r2) = 0;
    // 0x801035E0: jal         0x800C7830
    // 0x801035E4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    addBooleanCountHandleWrapper(rdram, ctx);
        goto after_0;
    // 0x801035E4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_0:
    // 0x801035E8: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x801035EC: addiu       $a0, $a0, 0x3A90
    ctx->r4 = ADD32(ctx->r4, 0X3A90);
    // 0x801035F0: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    // 0x801035F4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801035F8: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // 0x801035FC: jal         0x800C7830
    // 0x80103600: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    addBooleanCountHandleWrapper(rdram, ctx);
        goto after_1;
    // 0x80103600: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_1:
    // 0x80103604: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x80103608: addiu       $a0, $a0, 0x3C10
    ctx->r4 = ADD32(ctx->r4, 0X3C10);
    // 0x8010360C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80103610: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80103614: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // 0x80103618: jal         0x800C7830
    // 0x8010361C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    addBooleanCountHandleWrapper(rdram, ctx);
        goto after_2;
    // 0x8010361C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_2:
    // 0x80103620: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x80103624: addiu       $a0, $a0, 0x3AB0
    ctx->r4 = ADD32(ctx->r4, 0X3AB0);
    // 0x80103628: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    // 0x8010362C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80103630: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // 0x80103634: jal         0x800C7830
    // 0x80103638: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    addBooleanCountHandleWrapper(rdram, ctx);
        goto after_3;
    // 0x80103638: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_3:
    // 0x8010363C: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x80103640: addiu       $a0, $a0, 0x39B0
    ctx->r4 = ADD32(ctx->r4, 0X39B0);
    // 0x80103644: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80103648: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    // 0x8010364C: addiu       $a3, $zero, 0xF
    ctx->r7 = ADD32(0, 0XF);
    // 0x80103650: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80103654: jal         0x800C7830
    // 0x80103658: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    addBooleanCountHandleWrapper(rdram, ctx);
        goto after_4;
    // 0x80103658: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_4:
    // 0x8010365C: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x80103660: addiu       $a0, $a0, 0x3A00
    ctx->r4 = ADD32(ctx->r4, 0X3A00);
    // 0x80103664: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80103668: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    // 0x8010366C: addiu       $a3, $zero, 0xF
    ctx->r7 = ADD32(0, 0XF);
    // 0x80103670: addiu       $s0, $zero, 0x2
    ctx->r16 = ADD32(0, 0X2);
    // 0x80103674: jal         0x800C7830
    // 0x80103678: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    addBooleanCountHandleWrapper(rdram, ctx);
        goto after_5;
    // 0x80103678: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    after_5:
    // 0x8010367C: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x80103680: addiu       $a0, $a0, 0x3A50
    ctx->r4 = ADD32(ctx->r4, 0X3A50);
    // 0x80103684: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80103688: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    // 0x8010368C: addiu       $a3, $zero, 0xF
    ctx->r7 = ADD32(0, 0XF);
    // 0x80103690: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x80103694: jal         0x800C7830
    // 0x80103698: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    addBooleanCountHandleWrapper(rdram, ctx);
        goto after_6;
    // 0x80103698: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_6:
    // 0x8010369C: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x801036A0: addiu       $a0, $a0, 0x3A70
    ctx->r4 = ADD32(ctx->r4, 0X3A70);
    // 0x801036A4: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x801036A8: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    // 0x801036AC: addiu       $a3, $zero, 0x1D
    ctx->r7 = ADD32(0, 0X1D);
    // 0x801036B0: jal         0x800C7830
    // 0x801036B4: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    addBooleanCountHandleWrapper(rdram, ctx);
        goto after_7;
    // 0x801036B4: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    after_7:
    // 0x801036B8: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x801036BC: addiu       $a0, $a0, 0x3BBC
    ctx->r4 = ADD32(ctx->r4, 0X3BBC);
    // 0x801036C0: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x801036C4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801036C8: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // 0x801036CC: jal         0x800C7830
    // 0x801036D0: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    addBooleanCountHandleWrapper(rdram, ctx);
        goto after_8;
    // 0x801036D0: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_8:
    // 0x801036D4: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x801036D8: addiu       $a0, $a0, 0x3BF0
    ctx->r4 = ADD32(ctx->r4, 0X3BF0);
    // 0x801036DC: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x801036E0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801036E4: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // 0x801036E8: jal         0x800C7830
    // 0x801036EC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    addBooleanCountHandleWrapper(rdram, ctx);
        goto after_9;
    // 0x801036EC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_9:
    // 0x801036F0: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x801036F4: lui         $a1, 0x40E0
    ctx->r5 = S32(0X40E0 << 16);
    // 0x801036F8: jal         0x800C7864
    // 0x801036FC: addiu       $a0, $a0, 0x3C40
    ctx->r4 = ADD32(ctx->r4, 0X3C40);
    addTimerHandleWrapper(rdram, ctx);
        goto after_10;
    // 0x801036FC: addiu       $a0, $a0, 0x3C40
    ctx->r4 = ADD32(ctx->r4, 0X3C40);
    after_10:
    // 0x80103700: lui         $a1, 0x4000
    ctx->r5 = S32(0X4000 << 16);
    // 0x80103704: jal         0x800C7D1C
    // 0x80103708: addiu       $a0, $zero, 0x2A2
    ctx->r4 = ADD32(0, 0X2A2);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_11;
    // 0x80103708: addiu       $a0, $zero, 0x2A2
    ctx->r4 = ADD32(0, 0X2A2);
    after_11:
    // 0x8010370C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80103710: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80103714: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x80103718: jr          $ra
    // 0x8010371C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8010371C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void lv4_checkComplexObjectives(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80103720: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80103724: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    // 0x80103728: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8010372C: jal         0x800C761C
    // 0x80103730: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    getObjectiveCount(rdram, ctx);
        goto after_0;
    // 0x80103730: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    after_0:
    // 0x80103734: slti        $v0, $v0, 0x3
    ctx->r2 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // 0x80103738: bne         $v0, $zero, L_80103748
    if (ctx->r2 != 0) {
        // 0x8010373C: nop
    
            goto L_80103748;
    }
    // 0x8010373C: nop

    // 0x80103740: jal         0x800C7738
    // 0x80103744: nop

    setHudEnableBit4(rdram, ctx);
        goto after_1;
    // 0x80103744: nop

    after_1:
L_80103748:
    // 0x80103748: jal         0x800C761C
    // 0x8010374C: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    getObjectiveCount(rdram, ctx);
        goto after_2;
    // 0x8010374C: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    after_2:
    // 0x80103750: slti        $v0, $v0, 0x3
    ctx->r2 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // 0x80103754: bne         $v0, $zero, L_80103764
    if (ctx->r2 != 0) {
        // 0x80103758: nop
    
            goto L_80103764;
    }
    // 0x80103758: nop

    // 0x8010375C: jal         0x800C7738
    // 0x80103760: nop

    setHudEnableBit4(rdram, ctx);
        goto after_3;
    // 0x80103760: nop

    after_3:
L_80103764:
    // 0x80103764: jal         0x800C761C
    // 0x80103768: addiu       $a0, $zero, 0x1C
    ctx->r4 = ADD32(0, 0X1C);
    getObjectiveCount(rdram, ctx);
        goto after_4;
    // 0x80103768: addiu       $a0, $zero, 0x1C
    ctx->r4 = ADD32(0, 0X1C);
    after_4:
    // 0x8010376C: blez        $v0, L_8010379C
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80103770: lui         $v0, 0x8011
        ctx->r2 = S32(0X8011 << 16);
            goto L_8010379C;
    }
    // 0x80103770: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80103774: lw          $v1, -0x2FA0($v0)
    ctx->r3 = MEM_W(ctx->r2, -0X2FA0);
    // 0x80103778: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8010377C: bne         $v1, $v0, L_8010379C
    if (ctx->r3 != ctx->r2) {
        // 0x80103780: nop
    
            goto L_8010379C;
    }
    // 0x80103780: nop

    // 0x80103784: jal         0x800C776C
    // 0x80103788: nop

    setHudEnableBit8(rdram, ctx);
        goto after_5;
    // 0x80103788: nop

    after_5:
    // 0x8010378C: jal         0x800C76B0
    // 0x80103790: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    activateObjectiveCompleteFlag(rdram, ctx);
        goto after_6;
    // 0x80103790: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_6:
    // 0x80103794: jal         0x800C76B0
    // 0x80103798: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    activateObjectiveCompleteFlag(rdram, ctx);
        goto after_7;
    // 0x80103798: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_7:
L_8010379C:
    // 0x8010379C: jal         0x800C759C
    // 0x801037A0: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    getObjectiveBoolean(rdram, ctx);
        goto after_8;
    // 0x801037A0: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    after_8:
    // 0x801037A4: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // 0x801037A8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x801037AC: bne         $s0, $v0, L_801037EC
    if (ctx->r16 != ctx->r2) {
        // 0x801037B0: nop
    
            goto L_801037EC;
    }
    // 0x801037B0: nop

    // 0x801037B4: jal         0x800C759C
    // 0x801037B8: addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
    getObjectiveBoolean(rdram, ctx);
        goto after_9;
    // 0x801037B8: addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
    after_9:
    // 0x801037BC: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x801037C0: bne         $v1, $s0, L_801037EC
    if (ctx->r3 != ctx->r16) {
        // 0x801037C4: lui         $a2, 0x8011
        ctx->r6 = S32(0X8011 << 16);
            goto L_801037EC;
    }
    // 0x801037C4: lui         $a2, 0x8011
    ctx->r6 = S32(0X8011 << 16);
    // 0x801037C8: lw          $v0, -0x2F9C($a2)
    ctx->r2 = MEM_W(ctx->r6, -0X2F9C);
    // 0x801037CC: bne         $v0, $zero, L_801037EC
    if (ctx->r2 != 0) {
        // 0x801037D0: addiu       $a0, $zero, 0x31
        ctx->r4 = ADD32(0, 0X31);
            goto L_801037EC;
    }
    // 0x801037D0: addiu       $a0, $zero, 0x31
    ctx->r4 = ADD32(0, 0X31);
    // 0x801037D4: lui         $a1, 0x4000
    ctx->r5 = S32(0X4000 << 16);
    // 0x801037D8: jal         0x800C7D1C
    // 0x801037DC: sw          $v1, -0x2F9C($a2)
    MEM_W(-0X2F9C, ctx->r6) = ctx->r3;
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_10;
    // 0x801037DC: sw          $v1, -0x2F9C($a2)
    MEM_W(-0X2F9C, ctx->r6) = ctx->r3;
    after_10:
    // 0x801037E0: lui         $a1, 0x3F00
    ctx->r5 = S32(0X3F00 << 16);
    // 0x801037E4: jal         0x800C7D1C
    // 0x801037E8: addiu       $a0, $zero, 0x143
    ctx->r4 = ADD32(0, 0X143);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_11;
    // 0x801037E8: addiu       $a0, $zero, 0x143
    ctx->r4 = ADD32(0, 0X143);
    after_11:
L_801037EC:
    // 0x801037EC: jal         0x800C761C
    // 0x801037F0: addiu       $a0, $zero, 0x1D
    ctx->r4 = ADD32(0, 0X1D);
    getObjectiveCount(rdram, ctx);
        goto after_12;
    // 0x801037F0: addiu       $a0, $zero, 0x1D
    ctx->r4 = ADD32(0, 0X1D);
    after_12:
    // 0x801037F4: slti        $v0, $v0, 0x3
    ctx->r2 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // 0x801037F8: bne         $v0, $zero, L_8010382C
    if (ctx->r2 != 0) {
        // 0x801037FC: nop
    
            goto L_8010382C;
    }
    // 0x801037FC: nop

    // 0x80103800: jal         0x800C761C
    // 0x80103804: addiu       $a0, $zero, 0x1E
    ctx->r4 = ADD32(0, 0X1E);
    getObjectiveCount(rdram, ctx);
        goto after_13;
    // 0x80103804: addiu       $a0, $zero, 0x1E
    ctx->r4 = ADD32(0, 0X1E);
    after_13:
    // 0x80103808: slti        $v0, $v0, 0x3
    ctx->r2 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // 0x8010380C: bne         $v0, $zero, L_8010382C
    if (ctx->r2 != 0) {
        // 0x80103810: lui         $v1, 0x8011
        ctx->r3 = S32(0X8011 << 16);
            goto L_8010382C;
    }
    // 0x80103810: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x80103814: lw          $v0, -0x2F98($v1)
    ctx->r2 = MEM_W(ctx->r3, -0X2F98);
    // 0x80103818: bne         $v0, $zero, L_8010382C
    if (ctx->r2 != 0) {
        // 0x8010381C: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8010382C;
    }
    // 0x8010381C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80103820: sw          $v0, -0x2F98($v1)
    MEM_W(-0X2F98, ctx->r3) = ctx->r2;
    // 0x80103824: jal         0x800C7CF8
    // 0x80103828: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    playObjectiveVoiceLine1(rdram, ctx);
        goto after_14;
    // 0x80103828: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    after_14:
L_8010382C:
    // 0x8010382C: jal         0x800C759C
    // 0x80103830: addiu       $a0, $zero, 0x1A
    ctx->r4 = ADD32(0, 0X1A);
    getObjectiveBoolean(rdram, ctx);
        goto after_15;
    // 0x80103830: addiu       $a0, $zero, 0x1A
    ctx->r4 = ADD32(0, 0X1A);
    after_15:
    // 0x80103834: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x80103838: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8010383C: bne         $v1, $v0, L_80103860
    if (ctx->r3 != ctx->r2) {
        // 0x80103840: lui         $a0, 0x8011
        ctx->r4 = S32(0X8011 << 16);
            goto L_80103860;
    }
    // 0x80103840: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80103844: lw          $v0, -0x2F8C($a0)
    ctx->r2 = MEM_W(ctx->r4, -0X2F8C);
    // 0x80103848: bne         $v0, $zero, L_80103860
    if (ctx->r2 != 0) {
        // 0x8010384C: nop
    
            goto L_80103860;
    }
    // 0x8010384C: nop

    // 0x80103850: jal         0x800C7738
    // 0x80103854: sw          $v1, -0x2F8C($a0)
    MEM_W(-0X2F8C, ctx->r4) = ctx->r3;
    setHudEnableBit4(rdram, ctx);
        goto after_16;
    // 0x80103854: sw          $v1, -0x2F8C($a0)
    MEM_W(-0X2F8C, ctx->r4) = ctx->r3;
    after_16:
    // 0x80103858: jal         0x800C7CF8
    // 0x8010385C: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    playObjectiveVoiceLine1(rdram, ctx);
        goto after_17;
    // 0x8010385C: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    after_17:
L_80103860:
    // 0x80103860: jal         0x800C759C
    // 0x80103864: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    getObjectiveBoolean(rdram, ctx);
        goto after_18;
    // 0x80103864: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    after_18:
    // 0x80103868: bne         $v0, $zero, L_801038B4
    if (ctx->r2 != 0) {
        // 0x8010386C: nop
    
            goto L_801038B4;
    }
    // 0x8010386C: nop

    // 0x80103870: jal         0x800C761C
    // 0x80103874: addiu       $a0, $zero, 0x1F
    ctx->r4 = ADD32(0, 0X1F);
    getObjectiveCount(rdram, ctx);
        goto after_19;
    // 0x80103874: addiu       $a0, $zero, 0x1F
    ctx->r4 = ADD32(0, 0X1F);
    after_19:
    // 0x80103878: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x8010387C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80103880: bne         $v1, $v0, L_801038B4
    if (ctx->r3 != ctx->r2) {
        // 0x80103884: lui         $s0, 0x8011
        ctx->r16 = S32(0X8011 << 16);
            goto L_801038B4;
    }
    // 0x80103884: lui         $s0, 0x8011
    ctx->r16 = S32(0X8011 << 16);
    // 0x80103888: lw          $v0, -0x2F94($s0)
    ctx->r2 = MEM_W(ctx->r16, -0X2F94);
    // 0x8010388C: bne         $v0, $v1, L_801038B4
    if (ctx->r2 != ctx->r3) {
        // 0x80103890: nop
    
            goto L_801038B4;
    }
    // 0x80103890: nop

    // 0x80103894: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    // 0x80103898: jal         0x800C7D1C
    // 0x8010389C: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_20;
    // 0x8010389C: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
    after_20:
    // 0x801038A0: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x801038A4: lui         $a1, 0x40A0
    ctx->r5 = S32(0X40A0 << 16);
    // 0x801038A8: jal         0x800C7864
    // 0x801038AC: addiu       $a0, $a0, 0x3C30
    ctx->r4 = ADD32(ctx->r4, 0X3C30);
    addTimerHandleWrapper(rdram, ctx);
        goto after_21;
    // 0x801038AC: addiu       $a0, $a0, 0x3C30
    ctx->r4 = ADD32(ctx->r4, 0X3C30);
    after_21:
    // 0x801038B0: sw          $zero, -0x2F94($s0)
    MEM_W(-0X2F94, ctx->r16) = 0;
L_801038B4:
    // 0x801038B4: jal         0x800C759C
    // 0x801038B8: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    getObjectiveBoolean(rdram, ctx);
        goto after_22;
    // 0x801038B8: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    after_22:
    // 0x801038BC: bne         $v0, $zero, L_801038F8
    if (ctx->r2 != 0) {
        // 0x801038C0: nop
    
            goto L_801038F8;
    }
    // 0x801038C0: nop

    // 0x801038C4: jal         0x800C761C
    // 0x801038C8: addiu       $a0, $zero, 0x1F
    ctx->r4 = ADD32(0, 0X1F);
    getObjectiveCount(rdram, ctx);
        goto after_23;
    // 0x801038C8: addiu       $a0, $zero, 0x1F
    ctx->r4 = ADD32(0, 0X1F);
    after_23:
    // 0x801038CC: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
    // 0x801038D0: bne         $v0, $v1, L_801038F8
    if (ctx->r2 != ctx->r3) {
        // 0x801038D4: lui         $a2, 0x8011
        ctx->r6 = S32(0X8011 << 16);
            goto L_801038F8;
    }
    // 0x801038D4: lui         $a2, 0x8011
    ctx->r6 = S32(0X8011 << 16);
    // 0x801038D8: lw          $v1, -0x2F90($a2)
    ctx->r3 = MEM_W(ctx->r6, -0X2F90);
    // 0x801038DC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x801038E0: bne         $v1, $v0, L_801038F8
    if (ctx->r3 != ctx->r2) {
        // 0x801038E4: lui         $a0, 0x8010
        ctx->r4 = S32(0X8010 << 16);
            goto L_801038F8;
    }
    // 0x801038E4: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x801038E8: lui         $a1, 0x4000
    ctx->r5 = S32(0X4000 << 16);
    // 0x801038EC: addiu       $a0, $a0, 0x3C50
    ctx->r4 = ADD32(ctx->r4, 0X3C50);
    // 0x801038F0: jal         0x800C7864
    // 0x801038F4: sw          $zero, -0x2F90($a2)
    MEM_W(-0X2F90, ctx->r6) = 0;
    addTimerHandleWrapper(rdram, ctx);
        goto after_24;
    // 0x801038F4: sw          $zero, -0x2F90($a2)
    MEM_W(-0X2F90, ctx->r6) = 0;
    after_24:
L_801038F8:
    // 0x801038F8: jal         0x800C759C
    // 0x801038FC: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    getObjectiveBoolean(rdram, ctx);
        goto after_25;
    // 0x801038FC: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    after_25:
    // 0x80103900: bne         $v0, $zero, L_8010393C
    if (ctx->r2 != 0) {
        // 0x80103904: nop
    
            goto L_8010393C;
    }
    // 0x80103904: nop

    // 0x80103908: jal         0x800C761C
    // 0x8010390C: addiu       $a0, $zero, 0x1F
    ctx->r4 = ADD32(0, 0X1F);
    getObjectiveCount(rdram, ctx);
        goto after_26;
    // 0x8010390C: addiu       $a0, $zero, 0x1F
    ctx->r4 = ADD32(0, 0X1F);
    after_26:
    // 0x80103910: addiu       $v1, $zero, 0x3
    ctx->r3 = ADD32(0, 0X3);
    // 0x80103914: bne         $v0, $v1, L_8010393C
    if (ctx->r2 != ctx->r3) {
        // 0x80103918: lui         $v1, 0x8011
        ctx->r3 = S32(0X8011 << 16);
            goto L_8010393C;
    }
    // 0x80103918: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x8010391C: lw          $v0, -0x2F88($v1)
    ctx->r2 = MEM_W(ctx->r3, -0X2F88);
    // 0x80103920: bne         $v0, $zero, L_8010393C
    if (ctx->r2 != 0) {
        // 0x80103924: lui         $a0, 0x8010
        ctx->r4 = S32(0X8010 << 16);
            goto L_8010393C;
    }
    // 0x80103924: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x80103928: addiu       $a0, $a0, 0x3C74
    ctx->r4 = ADD32(ctx->r4, 0X3C74);
    // 0x8010392C: lui         $a1, 0x4000
    ctx->r5 = S32(0X4000 << 16);
    // 0x80103930: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80103934: jal         0x800C7864
    // 0x80103938: sw          $v0, -0x2F88($v1)
    MEM_W(-0X2F88, ctx->r3) = ctx->r2;
    addTimerHandleWrapper(rdram, ctx);
        goto after_27;
    // 0x80103938: sw          $v0, -0x2F88($v1)
    MEM_W(-0X2F88, ctx->r3) = ctx->r2;
    after_27:
L_8010393C:
    // 0x8010393C: jal         0x800C759C
    // 0x80103940: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    getObjectiveBoolean(rdram, ctx);
        goto after_28;
    // 0x80103940: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    after_28:
    // 0x80103944: bne         $v0, $zero, L_80103980
    if (ctx->r2 != 0) {
        // 0x80103948: nop
    
            goto L_80103980;
    }
    // 0x80103948: nop

    // 0x8010394C: jal         0x800C761C
    // 0x80103950: addiu       $a0, $zero, 0x1F
    ctx->r4 = ADD32(0, 0X1F);
    getObjectiveCount(rdram, ctx);
        goto after_29;
    // 0x80103950: addiu       $a0, $zero, 0x1F
    ctx->r4 = ADD32(0, 0X1F);
    after_29:
    // 0x80103954: addiu       $v1, $zero, 0x5
    ctx->r3 = ADD32(0, 0X5);
    // 0x80103958: bne         $v0, $v1, L_80103980
    if (ctx->r2 != ctx->r3) {
        // 0x8010395C: lui         $v1, 0x8011
        ctx->r3 = S32(0X8011 << 16);
            goto L_80103980;
    }
    // 0x8010395C: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x80103960: lw          $v0, -0x2F84($v1)
    ctx->r2 = MEM_W(ctx->r3, -0X2F84);
    // 0x80103964: bne         $v0, $zero, L_80103980
    if (ctx->r2 != 0) {
        // 0x80103968: lui         $a0, 0x8010
        ctx->r4 = S32(0X8010 << 16);
            goto L_80103980;
    }
    // 0x80103968: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x8010396C: addiu       $a0, $a0, 0x3C98
    ctx->r4 = ADD32(ctx->r4, 0X3C98);
    // 0x80103970: lui         $a1, 0x4000
    ctx->r5 = S32(0X4000 << 16);
    // 0x80103974: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80103978: jal         0x800C7864
    // 0x8010397C: sw          $v0, -0x2F84($v1)
    MEM_W(-0X2F84, ctx->r3) = ctx->r2;
    addTimerHandleWrapper(rdram, ctx);
        goto after_30;
    // 0x8010397C: sw          $v0, -0x2F84($v1)
    MEM_W(-0X2F84, ctx->r3) = ctx->r2;
    after_30:
L_80103980:
    // 0x80103980: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80103984: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80103988: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x8010398C: jr          $ra
    // 0x80103990: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80103990: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void playVoice_0x0A(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80103994: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80103998: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x8010399C: jal         0x800C7CF8
    // 0x801039A0: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    playObjectiveVoiceLine1(rdram, ctx);
        goto after_0;
    // 0x801039A0: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    after_0:
    // 0x801039A4: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x801039A8: jr          $ra
    // 0x801039AC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x801039AC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void lv4_progressWithDialogueA(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801039B0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801039B4: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x801039B8: jal         0x800C761C
    // 0x801039BC: addiu       $a0, $zero, 0x1E
    ctx->r4 = ADD32(0, 0X1E);
    getObjectiveCount(rdram, ctx);
        goto after_0;
    // 0x801039BC: addiu       $a0, $zero, 0x1E
    ctx->r4 = ADD32(0, 0X1E);
    after_0:
    // 0x801039C0: slti        $v0, $v0, 0x3
    ctx->r2 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // 0x801039C4: bne         $v0, $zero, L_801039D8
    if (ctx->r2 != 0) {
        // 0x801039C8: addiu       $a0, $zero, 0xB
        ctx->r4 = ADD32(0, 0XB);
            goto L_801039D8;
    }
    // 0x801039C8: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
    // 0x801039CC: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    // 0x801039D0: j           L_801039EC
    // 0x801039D4: nop

        goto L_801039EC;
    // 0x801039D4: nop

L_801039D8:
    // 0x801039D8: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    // 0x801039DC: jal         0x800C7D1C
    // 0x801039E0: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_1;
    // 0x801039E0: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
    after_1:
    // 0x801039E4: addiu       $a0, $zero, 0x2A1
    ctx->r4 = ADD32(0, 0X2A1);
    // 0x801039E8: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
L_801039EC:
    // 0x801039EC: jal         0x800C7D1C
    // 0x801039F0: nop

    playObjectiveVoiceLine2(rdram, ctx);
        goto after_2;
    // 0x801039F0: nop

    after_2:
    // 0x801039F4: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x801039F8: jr          $ra
    // 0x801039FC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x801039FC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void lv4_progressWithDialogueB(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80103A00: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80103A04: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80103A08: jal         0x800C761C
    // 0x80103A0C: addiu       $a0, $zero, 0x1E
    ctx->r4 = ADD32(0, 0X1E);
    getObjectiveCount(rdram, ctx);
        goto after_0;
    // 0x80103A0C: addiu       $a0, $zero, 0x1E
    ctx->r4 = ADD32(0, 0X1E);
    after_0:
    // 0x80103A10: slti        $v0, $v0, 0x3
    ctx->r2 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // 0x80103A14: bne         $v0, $zero, L_80103A28
    if (ctx->r2 != 0) {
        // 0x80103A18: addiu       $a0, $zero, 0x33
        ctx->r4 = ADD32(0, 0X33);
            goto L_80103A28;
    }
    // 0x80103A18: addiu       $a0, $zero, 0x33
    ctx->r4 = ADD32(0, 0X33);
    // 0x80103A1C: lui         $a1, 0x3F00
    ctx->r5 = S32(0X3F00 << 16);
    // 0x80103A20: j           L_80103A3C
    // 0x80103A24: nop

        goto L_80103A3C;
    // 0x80103A24: nop

L_80103A28:
    // 0x80103A28: lui         $a1, 0x3F00
    ctx->r5 = S32(0X3F00 << 16);
    // 0x80103A2C: jal         0x800C7D1C
    // 0x80103A30: addiu       $a0, $zero, 0x33
    ctx->r4 = ADD32(0, 0X33);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_1;
    // 0x80103A30: addiu       $a0, $zero, 0x33
    ctx->r4 = ADD32(0, 0X33);
    after_1:
    // 0x80103A34: addiu       $a0, $zero, 0x2A1
    ctx->r4 = ADD32(0, 0X2A1);
    // 0x80103A38: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
L_80103A3C:
    // 0x80103A3C: jal         0x800C7D1C
    // 0x80103A40: nop

    playObjectiveVoiceLine2(rdram, ctx);
        goto after_2;
    // 0x80103A40: nop

    after_2:
    // 0x80103A44: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80103A48: jr          $ra
    // 0x80103A4C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80103A4C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void playVoice2_0x034(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80103A50: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80103A54: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    // 0x80103A58: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80103A5C: jal         0x800C7D1C
    // 0x80103A60: addiu       $a0, $zero, 0x34
    ctx->r4 = ADD32(0, 0X34);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_0;
    // 0x80103A60: addiu       $a0, $zero, 0x34
    ctx->r4 = ADD32(0, 0X34);
    after_0:
    // 0x80103A64: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80103A68: jr          $ra
    // 0x80103A6C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80103A6C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void playVoice2_0x028(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80103A70: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80103A74: lui         $a1, 0x3F40
    ctx->r5 = S32(0X3F40 << 16);
    // 0x80103A78: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80103A7C: jal         0x800C7D1C
    // 0x80103A80: addiu       $a0, $zero, 0x28
    ctx->r4 = ADD32(0, 0X28);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_0;
    // 0x80103A80: addiu       $a0, $zero, 0x28
    ctx->r4 = ADD32(0, 0X28);
    after_0:
    // 0x80103A84: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80103A88: jr          $ra
    // 0x80103A8C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80103A8C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void playVoice2_0x027(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80103A90: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80103A94: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    // 0x80103A98: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80103A9C: jal         0x800C7D1C
    // 0x80103AA0: addiu       $a0, $zero, 0x27
    ctx->r4 = ADD32(0, 0X27);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_0;
    // 0x80103AA0: addiu       $a0, $zero, 0x27
    ctx->r4 = ADD32(0, 0X27);
    after_0:
    // 0x80103AA4: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80103AA8: jr          $ra
    // 0x80103AAC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80103AAC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void lv4_majorMidMissionEvent(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80103AB0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80103AB4: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80103AB8: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x80103ABC: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x80103AC0: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80103AC4: jal         0x800C7884
    // 0x80103AC8: addiu       $a0, $a0, -0x6940
    ctx->r4 = ADD32(ctx->r4, -0X6940);
    setHudFlagBit40AndStoreArg(rdram, ctx);
        goto after_0;
    // 0x80103AC8: addiu       $a0, $a0, -0x6940
    ctx->r4 = ADD32(ctx->r4, -0X6940);
    after_0:
    // 0x80103ACC: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80103AD0: jal         0x800C7D1C
    // 0x80103AD4: addiu       $a0, $zero, 0x238
    ctx->r4 = ADD32(0, 0X238);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_1;
    // 0x80103AD4: addiu       $a0, $zero, 0x238
    ctx->r4 = ADD32(0, 0X238);
    after_1:
    // 0x80103AD8: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80103ADC: jal         0x800C7D1C
    // 0x80103AE0: addiu       $a0, $zero, 0x30
    ctx->r4 = ADD32(0, 0X30);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_2;
    // 0x80103AE0: addiu       $a0, $zero, 0x30
    ctx->r4 = ADD32(0, 0X30);
    after_2:
    // 0x80103AE4: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80103AE8: jal         0x800C7D1C
    // 0x80103AEC: addiu       $a0, $zero, 0x142
    ctx->r4 = ADD32(0, 0X142);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_3;
    // 0x80103AEC: addiu       $a0, $zero, 0x142
    ctx->r4 = ADD32(0, 0X142);
    after_3:
    // 0x80103AF0: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x80103AF4: lui         $a1, 0x4000
    ctx->r5 = S32(0X4000 << 16);
    // 0x80103AF8: jal         0x800C7864
    // 0x80103AFC: addiu       $a0, $a0, 0x3B34
    ctx->r4 = ADD32(ctx->r4, 0X3B34);
    addTimerHandleWrapper(rdram, ctx);
        goto after_4;
    // 0x80103AFC: addiu       $a0, $a0, 0x3B34
    ctx->r4 = ADD32(ctx->r4, 0X3B34);
    after_4:
    // 0x80103B00: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x80103B04: lui         $a1, 0x40E0
    ctx->r5 = S32(0X40E0 << 16);
    // 0x80103B08: jal         0x800C7864
    // 0x80103B0C: addiu       $a0, $a0, 0x3B88
    ctx->r4 = ADD32(ctx->r4, 0X3B88);
    addTimerHandleWrapper(rdram, ctx);
        goto after_5;
    // 0x80103B0C: addiu       $a0, $a0, 0x3B88
    ctx->r4 = ADD32(ctx->r4, 0X3B88);
    after_5:
    // 0x80103B10: jal         0x800C7D98
    // 0x80103B14: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    triggerSoundCueByType(rdram, ctx);
        goto after_6;
    // 0x80103B14: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_6:
    // 0x80103B18: addiu       $a0, $zero, 0x6F
    ctx->r4 = ADD32(0, 0X6F);
    // 0x80103B1C: jal         0x800C7540
    // 0x80103B20: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    setObjectiveBoolean(rdram, ctx);
        goto after_7;
    // 0x80103B20: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_7:
    // 0x80103B24: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80103B28: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80103B2C: jr          $ra
    // 0x80103B30: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80103B30: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_80103B34(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80103B34: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80103B38: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80103B3C: addiu       $a0, $a0, -0x6934
    ctx->r4 = ADD32(ctx->r4, -0X6934);
    // 0x80103B40: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80103B44: lui         $s0, 0x800B
    ctx->r16 = S32(0X800B << 16);
    // 0x80103B48: addiu       $s0, $s0, -0x6928
    ctx->r16 = ADD32(ctx->r16, -0X6928);
    // 0x80103B4C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80103B50: jal         0x800C7AB0
    // 0x80103B54: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    func_800C7AB0(rdram, ctx);
        goto after_0;
    // 0x80103B54: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_0:
    // 0x80103B58: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80103B5C: addiu       $a0, $a0, -0x6914
    ctx->r4 = ADD32(ctx->r4, -0X6914);
    // 0x80103B60: jal         0x800C7AB0
    // 0x80103B64: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    func_800C7AB0(rdram, ctx);
        goto after_1;
    // 0x80103B64: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_1:
    // 0x80103B68: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80103B6C: addiu       $a0, $a0, -0x6908
    ctx->r4 = ADD32(ctx->r4, -0X6908);
    // 0x80103B70: jal         0x800C7AB0
    // 0x80103B74: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    func_800C7AB0(rdram, ctx);
        goto after_2;
    // 0x80103B74: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_2:
    // 0x80103B78: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80103B7C: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80103B80: jr          $ra
    // 0x80103B84: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80103B84: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void lv4_dealMultiDamageEvent(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80103B88: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80103B8C: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80103B90: addiu       $a0, $a0, -0x68FC
    ctx->r4 = ADD32(ctx->r4, -0X68FC);
    // 0x80103B94: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80103B98: jal         0x800C7390
    // 0x80103B9C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    dealDamagetoDatItem(rdram, ctx);
        goto after_0;
    // 0x80103B9C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_0:
    // 0x80103BA0: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80103BA4: addiu       $a0, $a0, -0x68EC
    ctx->r4 = ADD32(ctx->r4, -0X68EC);
    // 0x80103BA8: jal         0x800C7390
    // 0x80103BAC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    dealDamagetoDatItem(rdram, ctx);
        goto after_1;
    // 0x80103BAC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_1:
    // 0x80103BB0: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80103BB4: jr          $ra
    // 0x80103BB8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80103BB8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void lv4_completeObjectiveWithVoice(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80103BBC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80103BC0: addiu       $a0, $zero, 0x27
    ctx->r4 = ADD32(0, 0X27);
    // 0x80103BC4: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x80103BC8: lui         $a1, 0x4000
    ctx->r5 = S32(0X4000 << 16);
    // 0x80103BCC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80103BD0: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80103BD4: jal         0x800C7D1C
    // 0x80103BD8: sw          $v0, -0x2FA0($v1)
    MEM_W(-0X2FA0, ctx->r3) = ctx->r2;
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_0;
    // 0x80103BD8: sw          $v0, -0x2FA0($v1)
    MEM_W(-0X2FA0, ctx->r3) = ctx->r2;
    after_0:
    // 0x80103BDC: jal         0x800C76B0
    // 0x80103BE0: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    activateObjectiveCompleteFlag(rdram, ctx);
        goto after_1;
    // 0x80103BE0: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_1:
    // 0x80103BE4: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80103BE8: jr          $ra
    // 0x80103BEC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80103BEC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void playVoice2_0x032(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80103BF0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80103BF4: lui         $a1, 0x4000
    ctx->r5 = S32(0X4000 << 16);
    // 0x80103BF8: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80103BFC: jal         0x800C7D1C
    // 0x80103C00: addiu       $a0, $zero, 0x32
    ctx->r4 = ADD32(0, 0X32);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_0;
    // 0x80103C00: addiu       $a0, $zero, 0x32
    ctx->r4 = ADD32(0, 0X32);
    after_0:
    // 0x80103C04: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80103C08: jr          $ra
    // 0x80103C0C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80103C0C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void playVoice2_0x0FE(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80103C10: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80103C14: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    // 0x80103C18: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80103C1C: jal         0x800C7D1C
    // 0x80103C20: addiu       $a0, $zero, 0xFE
    ctx->r4 = ADD32(0, 0XFE);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_0;
    // 0x80103C20: addiu       $a0, $zero, 0xFE
    ctx->r4 = ADD32(0, 0XFE);
    after_0:
    // 0x80103C24: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80103C28: jr          $ra
    // 0x80103C2C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80103C2C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80103C30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80103C30: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x80103C34: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80103C38: jr          $ra
    // 0x80103C3C: sw          $v0, -0x2F90($v1)
    MEM_W(-0X2F90, ctx->r3) = ctx->r2;
    return;
    // 0x80103C3C: sw          $v0, -0x2F90($v1)
    MEM_W(-0X2F90, ctx->r3) = ctx->r2;
;}
RECOMP_FUNC void func_80103C40(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80103C40: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x80103C44: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80103C48: jr          $ra
    // 0x80103C4C: sw          $v0, -0x2F94($v1)
    MEM_W(-0X2F94, ctx->r3) = ctx->r2;
    return;
    // 0x80103C4C: sw          $v0, -0x2F94($v1)
    MEM_W(-0X2F94, ctx->r3) = ctx->r2;
;}
RECOMP_FUNC void lv4_dealDamageHookA(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80103C50: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80103C54: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80103C58: addiu       $a0, $a0, -0x6934
    ctx->r4 = ADD32(ctx->r4, -0X6934);
    // 0x80103C5C: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80103C60: jal         0x800C7390
    // 0x80103C64: addiu       $a1, $zero, 0xD3
    ctx->r5 = ADD32(0, 0XD3);
    dealDamagetoDatItem(rdram, ctx);
        goto after_0;
    // 0x80103C64: addiu       $a1, $zero, 0xD3
    ctx->r5 = ADD32(0, 0XD3);
    after_0:
    // 0x80103C68: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80103C6C: jr          $ra
    // 0x80103C70: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80103C70: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void lv4_dealDamageHookB(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80103C74: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80103C78: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80103C7C: addiu       $a0, $a0, -0x6914
    ctx->r4 = ADD32(ctx->r4, -0X6914);
    // 0x80103C80: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80103C84: jal         0x800C7390
    // 0x80103C88: addiu       $a1, $zero, 0xD3
    ctx->r5 = ADD32(0, 0XD3);
    dealDamagetoDatItem(rdram, ctx);
        goto after_0;
    // 0x80103C88: addiu       $a1, $zero, 0xD3
    ctx->r5 = ADD32(0, 0XD3);
    after_0:
    // 0x80103C8C: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80103C90: jr          $ra
    // 0x80103C94: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80103C94: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void lv4_dealDamageHookC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80103C98: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80103C9C: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80103CA0: addiu       $a0, $a0, -0x6908
    ctx->r4 = ADD32(ctx->r4, -0X6908);
    // 0x80103CA4: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80103CA8: jal         0x800C7390
    // 0x80103CAC: addiu       $a1, $zero, 0xD3
    ctx->r5 = ADD32(0, 0XD3);
    dealDamagetoDatItem(rdram, ctx);
        goto after_0;
    // 0x80103CAC: addiu       $a1, $zero, 0xD3
    ctx->r5 = ADD32(0, 0XD3);
    after_0:
    // 0x80103CB0: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80103CB4: jr          $ra
    // 0x80103CB8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80103CB8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void lv4_objectiveSlot1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80103CBC: jr          $ra
    // 0x80103CC0: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    return;
    // 0x80103CC0: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
;}
RECOMP_FUNC void lv4_calculateFriendliesSaved(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80103CC4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80103CC8: addiu       $a0, $zero, 0x28
    ctx->r4 = ADD32(0, 0X28);
    // 0x80103CCC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80103CD0: jal         0x800C761C
    // 0x80103CD4: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    getObjectiveCount(rdram, ctx);
        goto after_0;
    // 0x80103CD4: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    after_0:
    // 0x80103CD8: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    // 0x80103CDC: jal         0x800C761C
    // 0x80103CE0: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    getObjectiveCount(rdram, ctx);
        goto after_1;
    // 0x80103CE0: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    after_1:
    // 0x80103CE4: addu        $s0, $s0, $v0
    ctx->r16 = ADD32(ctx->r16, ctx->r2);
    // 0x80103CE8: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    // 0x80103CEC: jal         0x800C77B0
    // 0x80103CF0: subu        $a0, $a0, $s0
    ctx->r4 = SUB32(ctx->r4, ctx->r16);
    setFriendliesSaved(rdram, ctx);
        goto after_2;
    // 0x80103CF0: subu        $a0, $a0, $s0
    ctx->r4 = SUB32(ctx->r4, ctx->r16);
    after_2:
    // 0x80103CF4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80103CF8: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80103CFC: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x80103D00: jr          $ra
    // 0x80103D04: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80103D04: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void fake_func_80103D08(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
;}
RECOMP_FUNC void lv5_initializeObjectTracking(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80103D10: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80103D14: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x80103D18: addiu       $a0, $a0, 0x3E5C
    ctx->r4 = ADD32(ctx->r4, 0X3E5C);
    // 0x80103D1C: addiu       $a1, $zero, 0x23
    ctx->r5 = ADD32(0, 0X23);
    // 0x80103D20: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80103D24: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // 0x80103D28: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80103D2C: sw          $zero, -0x2F80($v0)
    MEM_W(-0X2F80, ctx->r2) = 0;
    // 0x80103D30: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80103D34: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x80103D38: sw          $zero, -0x2F7C($v0)
    MEM_W(-0X2F7C, ctx->r2) = 0;
    // 0x80103D3C: jal         0x800C7830
    // 0x80103D40: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    addBooleanCountHandleWrapper(rdram, ctx);
        goto after_0;
    // 0x80103D40: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_0:
    // 0x80103D44: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x80103D48: addiu       $a0, $a0, 0x3F4C
    ctx->r4 = ADD32(ctx->r4, 0X3F4C);
    // 0x80103D4C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80103D50: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    // 0x80103D54: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    // 0x80103D58: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80103D5C: jal         0x800C7830
    // 0x80103D60: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    addBooleanCountHandleWrapper(rdram, ctx);
        goto after_1;
    // 0x80103D60: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_1:
    // 0x80103D64: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x80103D68: addiu       $a0, $a0, 0x3F68
    ctx->r4 = ADD32(ctx->r4, 0X3F68);
    // 0x80103D6C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80103D70: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    // 0x80103D74: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    // 0x80103D78: addu        $v0, $a3, $zero
    ctx->r2 = ADD32(ctx->r7, 0);
    // 0x80103D7C: jal         0x800C7830
    // 0x80103D80: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    addBooleanCountHandleWrapper(rdram, ctx);
        goto after_2;
    // 0x80103D80: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_2:
    // 0x80103D84: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x80103D88: addiu       $a0, $a0, 0x3F88
    ctx->r4 = ADD32(ctx->r4, 0X3F88);
    // 0x80103D8C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80103D90: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    // 0x80103D94: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    // 0x80103D98: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x80103D9C: jal         0x800C7830
    // 0x80103DA0: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    addBooleanCountHandleWrapper(rdram, ctx);
        goto after_3;
    // 0x80103DA0: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_3:
    // 0x80103DA4: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x80103DA8: addiu       $a0, $a0, 0x3FA8
    ctx->r4 = ADD32(ctx->r4, 0X3FA8);
    // 0x80103DAC: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    // 0x80103DB0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80103DB4: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // 0x80103DB8: jal         0x800C7830
    // 0x80103DBC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    addBooleanCountHandleWrapper(rdram, ctx);
        goto after_4;
    // 0x80103DBC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_4:
    // 0x80103DC0: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x80103DC4: addiu       $a0, $a0, 0x3FC8
    ctx->r4 = ADD32(ctx->r4, 0X3FC8);
    // 0x80103DC8: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x80103DCC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80103DD0: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // 0x80103DD4: jal         0x800C7830
    // 0x80103DD8: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    addBooleanCountHandleWrapper(rdram, ctx);
        goto after_5;
    // 0x80103DD8: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_5:
    // 0x80103DDC: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x80103DE0: addiu       $a0, $a0, 0x4030
    ctx->r4 = ADD32(ctx->r4, 0X4030);
    // 0x80103DE4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80103DE8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80103DEC: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // 0x80103DF0: jal         0x800C7830
    // 0x80103DF4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    addBooleanCountHandleWrapper(rdram, ctx);
        goto after_6;
    // 0x80103DF4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_6:
    // 0x80103DF8: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x80103DFC: addiu       $a0, $a0, 0x4080
    ctx->r4 = ADD32(ctx->r4, 0X4080);
    // 0x80103E00: addiu       $a1, $zero, 0x28
    ctx->r5 = ADD32(0, 0X28);
    // 0x80103E04: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80103E08: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // 0x80103E0C: jal         0x800C7830
    // 0x80103E10: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    addBooleanCountHandleWrapper(rdram, ctx);
        goto after_7;
    // 0x80103E10: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_7:
    // 0x80103E14: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x80103E18: addiu       $a0, $a0, 0x40B0
    ctx->r4 = ADD32(ctx->r4, 0X40B0);
    // 0x80103E1C: addiu       $a1, $zero, 0x1F
    ctx->r5 = ADD32(0, 0X1F);
    // 0x80103E20: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80103E24: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // 0x80103E28: jal         0x800C7830
    // 0x80103E2C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    addBooleanCountHandleWrapper(rdram, ctx);
        goto after_8;
    // 0x80103E2C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_8:
    // 0x80103E30: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x80103E34: addiu       $a0, $a0, 0x40D0
    ctx->r4 = ADD32(ctx->r4, 0X40D0);
    // 0x80103E38: addiu       $a1, $zero, 0x33
    ctx->r5 = ADD32(0, 0X33);
    // 0x80103E3C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80103E40: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // 0x80103E44: jal         0x800C7830
    // 0x80103E48: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    addBooleanCountHandleWrapper(rdram, ctx);
        goto after_9;
    // 0x80103E48: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_9:
    // 0x80103E4C: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x80103E50: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x80103E54: jr          $ra
    // 0x80103E58: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80103E58: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void lv5_startMissionAndBriefing(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80103E5C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80103E60: addiu       $a0, $zero, 0x32
    ctx->r4 = ADD32(0, 0X32);
    // 0x80103E64: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80103E68: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x80103E6C: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x80103E70: jal         0x800C7540
    // 0x80103E74: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    setObjectiveBoolean(rdram, ctx);
        goto after_0;
    // 0x80103E74: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x80103E78: jal         0x800C76B0
    // 0x80103E7C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    activateObjectiveCompleteFlag(rdram, ctx);
        goto after_1;
    // 0x80103E7C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_1:
    // 0x80103E80: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80103E84: jal         0x800C7884
    // 0x80103E88: addiu       $a0, $a0, -0x68D0
    ctx->r4 = ADD32(ctx->r4, -0X68D0);
    setHudFlagBit40AndStoreArg(rdram, ctx);
        goto after_2;
    // 0x80103E88: addiu       $a0, $a0, -0x68D0
    ctx->r4 = ADD32(ctx->r4, -0X68D0);
    after_2:
    // 0x80103E8C: lui         $a1, 0x3FC0
    ctx->r5 = S32(0X3FC0 << 16);
    // 0x80103E90: jal         0x800C7D1C
    // 0x80103E94: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_3;
    // 0x80103E94: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    after_3:
    // 0x80103E98: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80103E9C: lwc1        $f22, -0x68B0($at)
    ctx->f22.u32l = MEM_W(ctx->r1, -0X68B0);
    // 0x80103EA0: mfc1        $a1, $f22
    ctx->r5 = (int32_t)ctx->f22.u32l;
    // 0x80103EA4: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x80103EA8: jal         0x800C7D1C
    // 0x80103EAC: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_4;
    // 0x80103EAC: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    after_4:
    // 0x80103EB0: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80103EB4: jal         0x800C7D1C
    // 0x80103EB8: addiu       $a0, $zero, 0x147
    ctx->r4 = ADD32(0, 0X147);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_5;
    // 0x80103EB8: addiu       $a0, $zero, 0x147
    ctx->r4 = ADD32(0, 0X147);
    after_5:
    // 0x80103EBC: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80103EC0: jal         0x800C7D1C
    // 0x80103EC4: addiu       $a0, $zero, 0x23E
    ctx->r4 = ADD32(0, 0X23E);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_6;
    // 0x80103EC4: addiu       $a0, $zero, 0x23E
    ctx->r4 = ADD32(0, 0X23E);
    after_6:
    // 0x80103EC8: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80103ECC: jal         0x800C7D1C
    // 0x80103ED0: addiu       $a0, $zero, 0x148
    ctx->r4 = ADD32(0, 0X148);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_7;
    // 0x80103ED0: addiu       $a0, $zero, 0x148
    ctx->r4 = ADD32(0, 0X148);
    after_7:
    // 0x80103ED4: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80103ED8: jal         0x800C7D1C
    // 0x80103EDC: addiu       $a0, $zero, 0xDC
    ctx->r4 = ADD32(0, 0XDC);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_8;
    // 0x80103EDC: addiu       $a0, $zero, 0xDC
    ctx->r4 = ADD32(0, 0XDC);
    after_8:
    // 0x80103EE0: mfc1        $a1, $f22
    ctx->r5 = (int32_t)ctx->f22.u32l;
    // 0x80103EE4: jal         0x800C7D1C
    // 0x80103EE8: addiu       $a0, $zero, 0x149
    ctx->r4 = ADD32(0, 0X149);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_9;
    // 0x80103EE8: addiu       $a0, $zero, 0x149
    ctx->r4 = ADD32(0, 0X149);
    after_9:
    // 0x80103EEC: lui         $a1, 0x4100
    ctx->r5 = S32(0X4100 << 16);
    // 0x80103EF0: jal         0x800C7D1C
    // 0x80103EF4: addiu       $a0, $zero, 0x2A3
    ctx->r4 = ADD32(0, 0X2A3);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_10;
    // 0x80103EF4: addiu       $a0, $zero, 0x2A3
    ctx->r4 = ADD32(0, 0X2A3);
    after_10:
    // 0x80103EF8: addiu       $a0, $zero, 0x6E
    ctx->r4 = ADD32(0, 0X6E);
    // 0x80103EFC: jal         0x800C7540
    // 0x80103F00: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    setObjectiveBoolean(rdram, ctx);
        goto after_11;
    // 0x80103F00: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_11:
    // 0x80103F04: jal         0x800C7D98
    // 0x80103F08: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    triggerSoundCueByType(rdram, ctx);
        goto after_12;
    // 0x80103F08: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_12:
    // 0x80103F0C: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80103F10: addiu       $a0, $a0, -0x68C8
    ctx->r4 = ADD32(ctx->r4, -0X68C8);
    // 0x80103F14: jal         0x800C7D60
    // 0x80103F18: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    delegateToLevelStageTick(rdram, ctx);
        goto after_13;
    // 0x80103F18: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_13:
    // 0x80103F1C: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x80103F20: jal         0x800C7648
    // 0x80103F24: addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
    getAndSetByteAtLevelStateTable(rdram, ctx);
        goto after_14;
    // 0x80103F24: addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
    after_14:
    // 0x80103F28: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x80103F2C: lui         $a1, 0x4120
    ctx->r5 = S32(0X4120 << 16);
    // 0x80103F30: jal         0x800C7864
    // 0x80103F34: addiu       $a0, $a0, 0x40F0
    ctx->r4 = ADD32(ctx->r4, 0X40F0);
    addTimerHandleWrapper(rdram, ctx);
        goto after_15;
    // 0x80103F34: addiu       $a0, $a0, 0x40F0
    ctx->r4 = ADD32(ctx->r4, 0X40F0);
    after_15:
    // 0x80103F38: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80103F3C: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x80103F40: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80103F44: jr          $ra
    // 0x80103F48: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80103F48: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void playVoice_0x0B(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80103F4C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80103F50: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80103F54: jal         0x800C7CF8
    // 0x80103F58: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
    playObjectiveVoiceLine1(rdram, ctx);
        goto after_0;
    // 0x80103F58: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
    after_0:
    // 0x80103F5C: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80103F60: jr          $ra
    // 0x80103F64: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80103F64: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void playVoice2_0x00B(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80103F68: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80103F6C: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    // 0x80103F70: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80103F74: jal         0x800C7D1C
    // 0x80103F78: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_0;
    // 0x80103F78: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
    after_0:
    // 0x80103F7C: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80103F80: jr          $ra
    // 0x80103F84: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80103F84: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void playVoice2_0x15D(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80103F88: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80103F8C: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    // 0x80103F90: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80103F94: jal         0x800C7D1C
    // 0x80103F98: addiu       $a0, $zero, 0x15D
    ctx->r4 = ADD32(0, 0X15D);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_0;
    // 0x80103F98: addiu       $a0, $zero, 0x15D
    ctx->r4 = ADD32(0, 0X15D);
    after_0:
    // 0x80103F9C: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80103FA0: jr          $ra
    // 0x80103FA4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80103FA4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void playVoice2_0x0AF(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80103FA8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80103FAC: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    // 0x80103FB0: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80103FB4: jal         0x800C7D1C
    // 0x80103FB8: addiu       $a0, $zero, 0xAF
    ctx->r4 = ADD32(0, 0XAF);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_0;
    // 0x80103FB8: addiu       $a0, $zero, 0xAF
    ctx->r4 = ADD32(0, 0XAF);
    after_0:
    // 0x80103FBC: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80103FC0: jr          $ra
    // 0x80103FC4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80103FC4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void lv5_dialogueWithStateChange(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80103FC8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80103FCC: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80103FD0: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x80103FD4: jal         0x800C759C
    // 0x80103FD8: addiu       $a0, $zero, 0x28
    ctx->r4 = ADD32(0, 0X28);
    getObjectiveBoolean(rdram, ctx);
        goto after_0;
    // 0x80103FD8: addiu       $a0, $zero, 0x28
    ctx->r4 = ADD32(0, 0X28);
    after_0:
    // 0x80103FDC: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80103FE0: bne         $v0, $v1, L_80104020
    if (ctx->r2 != ctx->r3) {
        // 0x80103FE4: nop
    
            goto L_80104020;
    }
    // 0x80103FE4: nop

    // 0x80103FE8: jal         0x800C759C
    // 0x80103FEC: addiu       $a0, $zero, 0x23
    ctx->r4 = ADD32(0, 0X23);
    getObjectiveBoolean(rdram, ctx);
        goto after_1;
    // 0x80103FEC: addiu       $a0, $zero, 0x23
    ctx->r4 = ADD32(0, 0X23);
    after_1:
    // 0x80103FF0: bne         $v0, $zero, L_80104020
    if (ctx->r2 != 0) {
        // 0x80103FF4: nop
    
            goto L_80104020;
    }
    // 0x80103FF4: nop

    // 0x80103FF8: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x80103FFC: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80104000: jal         0x800C7D1C
    // 0x80104004: addiu       $a0, $zero, 0xDB
    ctx->r4 = ADD32(0, 0XDB);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_2;
    // 0x80104004: addiu       $a0, $zero, 0xDB
    ctx->r4 = ADD32(0, 0XDB);
    after_2:
    // 0x80104008: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x8010400C: jal         0x800C7D1C
    // 0x80104010: addiu       $a0, $zero, 0x23B
    ctx->r4 = ADD32(0, 0X23B);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_3;
    // 0x80104010: addiu       $a0, $zero, 0x23B
    ctx->r4 = ADD32(0, 0X23B);
    after_3:
    // 0x80104014: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80104018: jal         0x800C7D1C
    // 0x8010401C: addiu       $a0, $zero, 0x146
    ctx->r4 = ADD32(0, 0X146);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_4;
    // 0x8010401C: addiu       $a0, $zero, 0x146
    ctx->r4 = ADD32(0, 0X146);
    after_4:
L_80104020:
    // 0x80104020: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80104024: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80104028: jr          $ra
    // 0x8010402C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8010402C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void lv5_runDialogueSequenceA(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80104030: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80104034: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x80104038: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x8010403C: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80104040: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80104044: jal         0x800C7D1C
    // 0x80104048: addiu       $a0, $zero, 0x239
    ctx->r4 = ADD32(0, 0X239);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_0;
    // 0x80104048: addiu       $a0, $zero, 0x239
    ctx->r4 = ADD32(0, 0X239);
    after_0:
    // 0x8010404C: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    // 0x80104050: jal         0x800C7D1C
    // 0x80104054: addiu       $a0, $zero, 0x144
    ctx->r4 = ADD32(0, 0X144);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_1;
    // 0x80104054: addiu       $a0, $zero, 0x144
    ctx->r4 = ADD32(0, 0X144);
    after_1:
    // 0x80104058: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x8010405C: jal         0x800C7D1C
    // 0x80104060: addiu       $a0, $zero, 0x23A
    ctx->r4 = ADD32(0, 0X23A);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_2;
    // 0x80104060: addiu       $a0, $zero, 0x23A
    ctx->r4 = ADD32(0, 0X23A);
    after_2:
    // 0x80104064: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80104068: jal         0x800C7D1C
    // 0x8010406C: addiu       $a0, $zero, 0x145
    ctx->r4 = ADD32(0, 0X145);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_3;
    // 0x8010406C: addiu       $a0, $zero, 0x145
    ctx->r4 = ADD32(0, 0X145);
    after_3:
    // 0x80104070: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80104074: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80104078: jr          $ra
    // 0x8010407C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8010407C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void lv5_dialogueAndBool(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80104080: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80104084: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80104088: jal         0x800C759C
    // 0x8010408C: addiu       $a0, $zero, 0x23
    ctx->r4 = ADD32(0, 0X23);
    getObjectiveBoolean(rdram, ctx);
        goto after_0;
    // 0x8010408C: addiu       $a0, $zero, 0x23
    ctx->r4 = ADD32(0, 0X23);
    after_0:
    // 0x80104090: bne         $v0, $zero, L_801040A4
    if (ctx->r2 != 0) {
        // 0x80104094: nop
    
            goto L_801040A4;
    }
    // 0x80104094: nop

    // 0x80104098: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    // 0x8010409C: jal         0x800C7D1C
    // 0x801040A0: addiu       $a0, $zero, 0xD
    ctx->r4 = ADD32(0, 0XD);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_1;
    // 0x801040A0: addiu       $a0, $zero, 0xD
    ctx->r4 = ADD32(0, 0XD);
    after_1:
L_801040A4:
    // 0x801040A4: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x801040A8: jr          $ra
    // 0x801040AC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x801040AC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void playVoice2_0x163(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801040B0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801040B4: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    // 0x801040B8: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x801040BC: jal         0x800C7D1C
    // 0x801040C0: addiu       $a0, $zero, 0x163
    ctx->r4 = ADD32(0, 0X163);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_0;
    // 0x801040C0: addiu       $a0, $zero, 0x163
    ctx->r4 = ADD32(0, 0X163);
    after_0:
    // 0x801040C4: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x801040C8: jr          $ra
    // 0x801040CC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x801040CC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void playVoice2_0x2A4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801040D0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801040D4: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    // 0x801040D8: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x801040DC: jal         0x800C7D1C
    // 0x801040E0: addiu       $a0, $zero, 0x2A4
    ctx->r4 = ADD32(0, 0X2A4);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_0;
    // 0x801040E0: addiu       $a0, $zero, 0x2A4
    ctx->r4 = ADD32(0, 0X2A4);
    after_0:
    // 0x801040E4: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x801040E8: jr          $ra
    // 0x801040EC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x801040EC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void playVoice_0x65(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801040F0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801040F4: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x801040F8: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x801040FC: jal         0x800C7648
    // 0x80104100: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    getAndSetByteAtLevelStateTable(rdram, ctx);
        goto after_0;
    // 0x80104100: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x80104104: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80104108: jr          $ra
    // 0x8010410C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8010410C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void lv5_objectiveSlot1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80104110: jr          $ra
    // 0x80104114: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    return;
    // 0x80104114: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
;}
RECOMP_FUNC void lv5_calculateFriendliesSaved(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80104118: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8010411C: addiu       $a0, $zero, 0x28
    ctx->r4 = ADD32(0, 0X28);
    // 0x80104120: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80104124: jal         0x800C761C
    // 0x80104128: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    getObjectiveCount(rdram, ctx);
        goto after_0;
    // 0x80104128: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    after_0:
    // 0x8010412C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x80104130: jal         0x800C761C
    // 0x80104134: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    getObjectiveCount(rdram, ctx);
        goto after_1;
    // 0x80104134: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    after_1:
    // 0x80104138: addu        $s0, $s0, $v0
    ctx->r16 = ADD32(ctx->r16, ctx->r2);
    // 0x8010413C: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x80104140: jal         0x800C77B0
    // 0x80104144: subu        $a0, $a0, $s0
    ctx->r4 = SUB32(ctx->r4, ctx->r16);
    setFriendliesSaved(rdram, ctx);
        goto after_2;
    // 0x80104144: subu        $a0, $a0, $s0
    ctx->r4 = SUB32(ctx->r4, ctx->r16);
    after_2:
    // 0x80104148: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8010414C: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80104150: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x80104154: jr          $ra
    // 0x80104158: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80104158: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void lv5_checkComplexObjectives(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010415C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80104160: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80104164: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x80104168: jal         0x800C761C
    // 0x8010416C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    getObjectiveCount(rdram, ctx);
        goto after_0;
    // 0x8010416C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_0:
    // 0x80104170: slti        $v0, $v0, 0x4
    ctx->r2 = SIGNED(ctx->r2) < 0X4 ? 1 : 0;
    // 0x80104174: bne         $v0, $zero, L_801041BC
    if (ctx->r2 != 0) {
        // 0x80104178: lui         $v1, 0x8011
        ctx->r3 = S32(0X8011 << 16);
            goto L_801041BC;
    }
    // 0x80104178: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x8010417C: lw          $v0, -0x2F80($v1)
    ctx->r2 = MEM_W(ctx->r3, -0X2F80);
    // 0x80104180: bne         $v0, $zero, L_801041BC
    if (ctx->r2 != 0) {
        // 0x80104184: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_801041BC;
    }
    // 0x80104184: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80104188: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8010418C: lwc1        $f20, -0x68AC($at)
    ctx->f20.u32l = MEM_W(ctx->r1, -0X68AC);
    // 0x80104190: jal         0x800C7738
    // 0x80104194: sw          $v0, -0x2F80($v1)
    MEM_W(-0X2F80, ctx->r3) = ctx->r2;
    setHudEnableBit4(rdram, ctx);
        goto after_1;
    // 0x80104194: sw          $v0, -0x2F80($v1)
    MEM_W(-0X2F80, ctx->r3) = ctx->r2;
    after_1:
    // 0x80104198: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x8010419C: jal         0x800C7D1C
    // 0x801041A0: addiu       $a0, $zero, 0x11
    ctx->r4 = ADD32(0, 0X11);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_2;
    // 0x801041A0: addiu       $a0, $zero, 0x11
    ctx->r4 = ADD32(0, 0X11);
    after_2:
    // 0x801041A4: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x801041A8: jal         0x800C7D1C
    // 0x801041AC: addiu       $a0, $zero, 0xDD
    ctx->r4 = ADD32(0, 0XDD);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_3;
    // 0x801041AC: addiu       $a0, $zero, 0xDD
    ctx->r4 = ADD32(0, 0XDD);
    after_3:
    // 0x801041B0: lui         $a1, 0x3F00
    ctx->r5 = S32(0X3F00 << 16);
    // 0x801041B4: jal         0x800C7D1C
    // 0x801041B8: addiu       $a0, $zero, 0x14B
    ctx->r4 = ADD32(0, 0X14B);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_4;
    // 0x801041B8: addiu       $a0, $zero, 0x14B
    ctx->r4 = ADD32(0, 0X14B);
    after_4:
L_801041BC:
    // 0x801041BC: jal         0x800C761C
    // 0x801041C0: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    getObjectiveCount(rdram, ctx);
        goto after_5;
    // 0x801041C0: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    after_5:
    // 0x801041C4: slti        $v0, $v0, 0x9
    ctx->r2 = SIGNED(ctx->r2) < 0X9 ? 1 : 0;
    // 0x801041C8: bne         $v0, $zero, L_801041F4
    if (ctx->r2 != 0) {
        // 0x801041CC: lui         $v1, 0x8011
        ctx->r3 = S32(0X8011 << 16);
            goto L_801041F4;
    }
    // 0x801041CC: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x801041D0: lw          $v0, -0x2F7C($v1)
    ctx->r2 = MEM_W(ctx->r3, -0X2F7C);
    // 0x801041D4: bne         $v0, $zero, L_801041F4
    if (ctx->r2 != 0) {
        // 0x801041D8: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_801041F4;
    }
    // 0x801041D8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x801041DC: jal         0x800C776C
    // 0x801041E0: sw          $v0, -0x2F7C($v1)
    MEM_W(-0X2F7C, ctx->r3) = ctx->r2;
    setHudEnableBit8(rdram, ctx);
        goto after_6;
    // 0x801041E0: sw          $v0, -0x2F7C($v1)
    MEM_W(-0X2F7C, ctx->r3) = ctx->r2;
    after_6:
    // 0x801041E4: jal         0x800C76B0
    // 0x801041E8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    activateObjectiveCompleteFlag(rdram, ctx);
        goto after_7;
    // 0x801041E8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_7:
    // 0x801041EC: jal         0x800C76B0
    // 0x801041F0: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    activateObjectiveCompleteFlag(rdram, ctx);
        goto after_8;
    // 0x801041F0: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_8:
L_801041F4:
    // 0x801041F4: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x801041F8: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x801041FC: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x80104200: jr          $ra
    // 0x80104204: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80104204: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void fake_func_80104208(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
;}
RECOMP_FUNC void lv6_checkComplexObjectives(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80104210: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80104214: addiu       $a0, $zero, 0x22
    ctx->r4 = ADD32(0, 0X22);
    // 0x80104218: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8010421C: jal         0x800C761C
    // 0x80104220: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    getObjectiveCount(rdram, ctx);
        goto after_0;
    // 0x80104220: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    after_0:
    // 0x80104224: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    // 0x80104228: bne         $v0, $s0, L_80104248
    if (ctx->r2 != ctx->r16) {
        // 0x8010422C: nop
    
            goto L_80104248;
    }
    // 0x8010422C: nop

L_80104230:
    // 0x80104230: jal         0x800C7738
    // 0x80104234: nop

    setHudEnableBit4(rdram, ctx);
        goto after_1;
    // 0x80104234: nop

    after_1:
    // 0x80104238: jal         0x800C7CF8
    // 0x8010423C: addiu       $a0, $zero, 0x65
    ctx->r4 = ADD32(0, 0X65);
    playObjectiveVoiceLine1(rdram, ctx);
        goto after_2;
    // 0x8010423C: addiu       $a0, $zero, 0x65
    ctx->r4 = ADD32(0, 0X65);
    after_2:
    // 0x80104240: j           L_8010438C
    // 0x80104244: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
        goto L_8010438C;
    // 0x80104244: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_80104248:
    // 0x80104248: jal         0x800C761C
    // 0x8010424C: addiu       $a0, $zero, 0x23
    ctx->r4 = ADD32(0, 0X23);
    getObjectiveCount(rdram, ctx);
        goto after_3;
    // 0x8010424C: addiu       $a0, $zero, 0x23
    ctx->r4 = ADD32(0, 0X23);
    after_3:
    // 0x80104250: beq         $v0, $s0, L_80104230
    if (ctx->r2 == ctx->r16) {
        // 0x80104254: nop
    
            goto L_80104230;
    }
    // 0x80104254: nop

    // 0x80104258: jal         0x800C761C
    // 0x8010425C: addiu       $a0, $zero, 0x24
    ctx->r4 = ADD32(0, 0X24);
    getObjectiveCount(rdram, ctx);
        goto after_4;
    // 0x8010425C: addiu       $a0, $zero, 0x24
    ctx->r4 = ADD32(0, 0X24);
    after_4:
    // 0x80104260: beq         $v0, $s0, L_80104230
    if (ctx->r2 == ctx->r16) {
        // 0x80104264: nop
    
            goto L_80104230;
    }
    // 0x80104264: nop

    // 0x80104268: jal         0x800C761C
    // 0x8010426C: addiu       $a0, $zero, 0x25
    ctx->r4 = ADD32(0, 0X25);
    getObjectiveCount(rdram, ctx);
        goto after_5;
    // 0x8010426C: addiu       $a0, $zero, 0x25
    ctx->r4 = ADD32(0, 0X25);
    after_5:
    // 0x80104270: beq         $v0, $s0, L_80104230
    if (ctx->r2 == ctx->r16) {
        // 0x80104274: nop
    
            goto L_80104230;
    }
    // 0x80104274: nop

    // 0x80104278: jal         0x800C761C
    // 0x8010427C: addiu       $a0, $zero, 0x26
    ctx->r4 = ADD32(0, 0X26);
    getObjectiveCount(rdram, ctx);
        goto after_6;
    // 0x8010427C: addiu       $a0, $zero, 0x26
    ctx->r4 = ADD32(0, 0X26);
    after_6:
    // 0x80104280: beq         $v0, $s0, L_80104230
    if (ctx->r2 == ctx->r16) {
        // 0x80104284: nop
    
            goto L_80104230;
    }
    // 0x80104284: nop

    // 0x80104288: jal         0x800C761C
    // 0x8010428C: addiu       $a0, $zero, 0x27
    ctx->r4 = ADD32(0, 0X27);
    getObjectiveCount(rdram, ctx);
        goto after_7;
    // 0x8010428C: addiu       $a0, $zero, 0x27
    ctx->r4 = ADD32(0, 0X27);
    after_7:
    // 0x80104290: beq         $v0, $s0, L_80104230
    if (ctx->r2 == ctx->r16) {
        // 0x80104294: nop
    
            goto L_80104230;
    }
    // 0x80104294: nop

    // 0x80104298: jal         0x800C761C
    // 0x8010429C: addiu       $a0, $zero, 0x62
    ctx->r4 = ADD32(0, 0X62);
    getObjectiveCount(rdram, ctx);
        goto after_8;
    // 0x8010429C: addiu       $a0, $zero, 0x62
    ctx->r4 = ADD32(0, 0X62);
    after_8:
    // 0x801042A0: addiu       $v1, $zero, 0x6
    ctx->r3 = ADD32(0, 0X6);
    // 0x801042A4: bne         $v0, $v1, L_801042E4
    if (ctx->r2 != ctx->r3) {
        // 0x801042A8: nop
    
            goto L_801042E4;
    }
    // 0x801042A8: nop

    // 0x801042AC: jal         0x800C759C
    // 0x801042B0: addiu       $a0, $zero, 0x62
    ctx->r4 = ADD32(0, 0X62);
    getObjectiveBoolean(rdram, ctx);
        goto after_9;
    // 0x801042B0: addiu       $a0, $zero, 0x62
    ctx->r4 = ADD32(0, 0X62);
    after_9:
    // 0x801042B4: bne         $v0, $zero, L_801042E4
    if (ctx->r2 != 0) {
        // 0x801042B8: addiu       $a0, $zero, 0x62
        ctx->r4 = ADD32(0, 0X62);
            goto L_801042E4;
    }
    // 0x801042B8: addiu       $a0, $zero, 0x62
    ctx->r4 = ADD32(0, 0X62);
    // 0x801042BC: jal         0x800C7540
    // 0x801042C0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    setObjectiveBoolean(rdram, ctx);
        goto after_10;
    // 0x801042C0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_10:
    // 0x801042C4: addiu       $a0, $zero, 0x63
    ctx->r4 = ADD32(0, 0X63);
    // 0x801042C8: jal         0x800C75EC
    // 0x801042CC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    increaseObjectiveCount(rdram, ctx);
        goto after_11;
    // 0x801042CC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_11:
    // 0x801042D0: addiu       $a0, $zero, 0x64
    ctx->r4 = ADD32(0, 0X64);
    // 0x801042D4: jal         0x800C7D1C
    // 0x801042D8: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_12;
    // 0x801042D8: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_12:
    // 0x801042DC: jal         0x800C76B0
    // 0x801042E0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    activateObjectiveCompleteFlag(rdram, ctx);
        goto after_13;
    // 0x801042E0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_13:
L_801042E4:
    // 0x801042E4: jal         0x800C761C
    // 0x801042E8: addiu       $a0, $zero, 0x32
    ctx->r4 = ADD32(0, 0X32);
    getObjectiveCount(rdram, ctx);
        goto after_14;
    // 0x801042E8: addiu       $a0, $zero, 0x32
    ctx->r4 = ADD32(0, 0X32);
    after_14:
    // 0x801042EC: addiu       $v1, $zero, 0x4
    ctx->r3 = ADD32(0, 0X4);
    // 0x801042F0: bne         $v0, $v1, L_8010431C
    if (ctx->r2 != ctx->r3) {
        // 0x801042F4: nop
    
            goto L_8010431C;
    }
    // 0x801042F4: nop

    // 0x801042F8: jal         0x800C759C
    // 0x801042FC: addiu       $a0, $zero, 0x63
    ctx->r4 = ADD32(0, 0X63);
    getObjectiveBoolean(rdram, ctx);
        goto after_15;
    // 0x801042FC: addiu       $a0, $zero, 0x63
    ctx->r4 = ADD32(0, 0X63);
    after_15:
    // 0x80104300: bne         $v0, $zero, L_8010431C
    if (ctx->r2 != 0) {
        // 0x80104304: addiu       $a0, $zero, 0x63
        ctx->r4 = ADD32(0, 0X63);
            goto L_8010431C;
    }
    // 0x80104304: addiu       $a0, $zero, 0x63
    ctx->r4 = ADD32(0, 0X63);
    // 0x80104308: jal         0x800C7540
    // 0x8010430C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    setObjectiveBoolean(rdram, ctx);
        goto after_16;
    // 0x8010430C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_16:
    // 0x80104310: addiu       $a0, $zero, 0x63
    ctx->r4 = ADD32(0, 0X63);
    // 0x80104314: jal         0x800C75EC
    // 0x80104318: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    increaseObjectiveCount(rdram, ctx);
        goto after_17;
    // 0x80104318: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_17:
L_8010431C:
    // 0x8010431C: jal         0x800C759C
    // 0x80104320: addiu       $a0, $zero, 0x28
    ctx->r4 = ADD32(0, 0X28);
    getObjectiveBoolean(rdram, ctx);
        goto after_18;
    // 0x80104320: addiu       $a0, $zero, 0x28
    ctx->r4 = ADD32(0, 0X28);
    after_18:
    // 0x80104324: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    // 0x80104328: bne         $v0, $s0, L_80104338
    if (ctx->r2 != ctx->r16) {
        // 0x8010432C: nop
    
            goto L_80104338;
    }
    // 0x8010432C: nop

    // 0x80104330: jal         0x800C76B0
    // 0x80104334: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    activateObjectiveCompleteFlag(rdram, ctx);
        goto after_19;
    // 0x80104334: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_19:
L_80104338:
    // 0x80104338: jal         0x800C759C
    // 0x8010433C: addiu       $a0, $zero, 0x7D
    ctx->r4 = ADD32(0, 0X7D);
    getObjectiveBoolean(rdram, ctx);
        goto after_20;
    // 0x8010433C: addiu       $a0, $zero, 0x7D
    ctx->r4 = ADD32(0, 0X7D);
    after_20:
    // 0x80104340: bne         $v0, $s0, L_80104350
    if (ctx->r2 != ctx->r16) {
        // 0x80104344: nop
    
            goto L_80104350;
    }
    // 0x80104344: nop

    // 0x80104348: jal         0x800C76B0
    // 0x8010434C: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    activateObjectiveCompleteFlag(rdram, ctx);
        goto after_21;
    // 0x8010434C: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_21:
L_80104350:
    // 0x80104350: jal         0x800C761C
    // 0x80104354: addiu       $a0, $zero, 0x63
    ctx->r4 = ADD32(0, 0X63);
    getObjectiveCount(rdram, ctx);
        goto after_22;
    // 0x80104354: addiu       $a0, $zero, 0x63
    ctx->r4 = ADD32(0, 0X63);
    after_22:
    // 0x80104358: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
    // 0x8010435C: bne         $v0, $v1, L_8010438C
    if (ctx->r2 != ctx->r3) {
        // 0x80104360: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_8010438C;
    }
    // 0x80104360: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x80104364: jal         0x800C759C
    // 0x80104368: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
    getObjectiveBoolean(rdram, ctx);
        goto after_23;
    // 0x80104368: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
    after_23:
    // 0x8010436C: bne         $v0, $zero, L_8010438C
    if (ctx->r2 != 0) {
        // 0x80104370: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_8010438C;
    }
    // 0x80104370: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x80104374: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
    // 0x80104378: jal         0x800C7540
    // 0x8010437C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    setObjectiveBoolean(rdram, ctx);
        goto after_24;
    // 0x8010437C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_24:
    // 0x80104380: jal         0x800C776C
    // 0x80104384: nop

    setHudEnableBit8(rdram, ctx);
        goto after_25;
    // 0x80104384: nop

    after_25:
    // 0x80104388: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_8010438C:
    // 0x8010438C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80104390: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80104394: jr          $ra
    // 0x80104398: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80104398: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void lv6_initializeObjectTracking(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010439C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x801043A0: lwc1        $f12, -0x6888($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X6888);
    // 0x801043A4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801043A8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801043AC: jal         0x800C7CEC
    // 0x801043B0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    setLevelObjectTrackingScalar(rdram, ctx);
        goto after_0;
    // 0x801043B0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    after_0:
    // 0x801043B4: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x801043B8: addiu       $a0, $a0, 0x444C
    ctx->r4 = ADD32(ctx->r4, 0X444C);
    // 0x801043BC: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x801043C0: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    // 0x801043C4: addiu       $a3, $zero, 0x14
    ctx->r7 = ADD32(0, 0X14);
    // 0x801043C8: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    // 0x801043CC: jal         0x800C7830
    // 0x801043D0: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    addBooleanCountHandleWrapper(rdram, ctx);
        goto after_1;
    // 0x801043D0: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    after_1:
    // 0x801043D4: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x801043D8: addiu       $a0, $a0, 0x447C
    ctx->r4 = ADD32(ctx->r4, 0X447C);
    // 0x801043DC: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x801043E0: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    // 0x801043E4: addiu       $a3, $zero, 0x15
    ctx->r7 = ADD32(0, 0X15);
    // 0x801043E8: jal         0x800C7830
    // 0x801043EC: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    addBooleanCountHandleWrapper(rdram, ctx);
        goto after_2;
    // 0x801043EC: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    after_2:
    // 0x801043F0: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x801043F4: addiu       $a0, $a0, 0x4498
    ctx->r4 = ADD32(ctx->r4, 0X4498);
    // 0x801043F8: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x801043FC: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    // 0x80104400: addiu       $a3, $zero, 0xD
    ctx->r7 = ADD32(0, 0XD);
    // 0x80104404: jal         0x800C7830
    // 0x80104408: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    addBooleanCountHandleWrapper(rdram, ctx);
        goto after_3;
    // 0x80104408: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    after_3:
    // 0x8010440C: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x80104410: addiu       $a0, $a0, 0x44B4
    ctx->r4 = ADD32(ctx->r4, 0X44B4);
    // 0x80104414: addiu       $a1, $zero, 0x7F
    ctx->r5 = ADD32(0, 0X7F);
    // 0x80104418: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    // 0x8010441C: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // 0x80104420: jal         0x800C7830
    // 0x80104424: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    addBooleanCountHandleWrapper(rdram, ctx);
        goto after_4;
    // 0x80104424: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_4:
    // 0x80104428: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8010442C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80104430: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x80104434: jr          $ra
    // 0x80104438: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80104438: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void lv6_objectiveSlot1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010443C: jr          $ra
    // 0x80104440: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    return;
    // 0x80104440: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
;}
RECOMP_FUNC void lv6_calculateFriendliesSaved(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80104444: jr          $ra
    // 0x80104448: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    return;
    // 0x80104448: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
;}
RECOMP_FUNC void lv6_playPairedDialogue(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010444C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80104450: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    // 0x80104454: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80104458: jal         0x800C7D1C
    // 0x8010445C: addiu       $a0, $zero, 0x63
    ctx->r4 = ADD32(0, 0X63);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_0;
    // 0x8010445C: addiu       $a0, $zero, 0x63
    ctx->r4 = ADD32(0, 0X63);
    after_0:
    // 0x80104460: lui         $a1, 0x3FCC
    ctx->r5 = S32(0X3FCC << 16);
    // 0x80104464: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x80104468: jal         0x800C7D1C
    // 0x8010446C: addiu       $a0, $zero, 0x101
    ctx->r4 = ADD32(0, 0X101);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_1;
    // 0x8010446C: addiu       $a0, $zero, 0x101
    ctx->r4 = ADD32(0, 0X101);
    after_1:
    // 0x80104470: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80104474: jr          $ra
    // 0x80104478: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80104478: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
