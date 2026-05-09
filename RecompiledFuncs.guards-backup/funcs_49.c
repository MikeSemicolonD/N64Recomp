#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void func_80108D1C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80108D1C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80108D20: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x80108D24: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x80108D28: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80108D2C: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80108D30: jal         0x800C7D1C
    // 0x80108D34: addiu       $a0, $zero, 0x2B4
    ctx->r4 = ADD32(0, 0X2B4);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_0;
    // 0x80108D34: addiu       $a0, $zero, 0x2B4
    ctx->r4 = ADD32(0, 0X2B4);
    after_0:
    // 0x80108D38: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80108D3C: jal         0x800C7D1C
    // 0x80108D40: addiu       $a0, $zero, 0x142
    ctx->r4 = ADD32(0, 0X142);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_1;
    // 0x80108D40: addiu       $a0, $zero, 0x142
    ctx->r4 = ADD32(0, 0X142);
    after_1:
    // 0x80108D44: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80108D48: jal         0x800C7D1C
    // 0x80108D4C: addiu       $a0, $zero, 0x1E6
    ctx->r4 = ADD32(0, 0X1E6);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_2;
    // 0x80108D4C: addiu       $a0, $zero, 0x1E6
    ctx->r4 = ADD32(0, 0X1E6);
    after_2:
    // 0x80108D50: lui         $a1, 0x3F00
    ctx->r5 = S32(0X3F00 << 16);
    // 0x80108D54: jal         0x800C7D1C
    // 0x80108D58: addiu       $a0, $zero, 0x11A
    ctx->r4 = ADD32(0, 0X11A);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_3;
    // 0x80108D58: addiu       $a0, $zero, 0x11A
    ctx->r4 = ADD32(0, 0X11A);
    after_3:
    // 0x80108D5C: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80108D60: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80108D64: jr          $ra
    // 0x80108D68: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80108D68: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_80108D6C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80108D6C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80108D70: addiu       $a0, $zero, 0x93
    ctx->r4 = ADD32(0, 0X93);
    // 0x80108D74: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80108D78: jal         0x800C7D1C
    // 0x80108D7C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_0;
    // 0x80108D7C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_0:
    // 0x80108D80: lui         $a1, 0x4060
    ctx->r5 = S32(0X4060 << 16);
    // 0x80108D84: jal         0x800C7D1C
    // 0x80108D88: addiu       $a0, $zero, 0x96
    ctx->r4 = ADD32(0, 0X96);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_1;
    // 0x80108D88: addiu       $a0, $zero, 0x96
    ctx->r4 = ADD32(0, 0X96);
    after_1:
    // 0x80108D8C: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80108D90: jr          $ra
    // 0x80108D94: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80108D94: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80108D98(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80108D98: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80108D9C: addiu       $a0, $zero, 0x1EB
    ctx->r4 = ADD32(0, 0X1EB);
    // 0x80108DA0: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80108DA4: jal         0x800C7D1C
    // 0x80108DA8: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_0;
    // 0x80108DA8: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_0:
    // 0x80108DAC: lui         $a1, 0x4020
    ctx->r5 = S32(0X4020 << 16);
    // 0x80108DB0: jal         0x800C7D1C
    // 0x80108DB4: addiu       $a0, $zero, 0x1AC
    ctx->r4 = ADD32(0, 0X1AC);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_1;
    // 0x80108DB4: addiu       $a0, $zero, 0x1AC
    ctx->r4 = ADD32(0, 0X1AC);
    after_1:
    // 0x80108DB8: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80108DBC: jr          $ra
    // 0x80108DC0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80108DC0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80108DC4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80108DC4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80108DC8: addiu       $a0, $zero, 0x246
    ctx->r4 = ADD32(0, 0X246);
    // 0x80108DCC: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80108DD0: jal         0x800C7D1C
    // 0x80108DD4: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_0;
    // 0x80108DD4: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_0:
    // 0x80108DD8: lui         $a1, 0x3F00
    ctx->r5 = S32(0X3F00 << 16);
    // 0x80108DDC: jal         0x800C7D1C
    // 0x80108DE0: addiu       $a0, $zero, 0x11A
    ctx->r4 = ADD32(0, 0X11A);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_1;
    // 0x80108DE0: addiu       $a0, $zero, 0x11A
    ctx->r4 = ADD32(0, 0X11A);
    after_1:
    // 0x80108DE4: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80108DE8: jr          $ra
    // 0x80108DEC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80108DEC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80108DF0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80108DF0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80108DF4: lui         $a1, 0x4100
    ctx->r5 = S32(0X4100 << 16);
    // 0x80108DF8: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80108DFC: jal         0x800C7D1C
    // 0x80108E00: addiu       $a0, $zero, 0x22E
    ctx->r4 = ADD32(0, 0X22E);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_0;
    // 0x80108E00: addiu       $a0, $zero, 0x22E
    ctx->r4 = ADD32(0, 0X22E);
    after_0:
    // 0x80108E04: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80108E08: jr          $ra
    // 0x80108E0C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80108E0C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80108E10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80108E10: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80108E14: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x80108E18: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x80108E1C: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80108E20: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80108E24: jal         0x800C7D1C
    // 0x80108E28: addiu       $a0, $zero, 0x1F7
    ctx->r4 = ADD32(0, 0X1F7);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_0;
    // 0x80108E28: addiu       $a0, $zero, 0x1F7
    ctx->r4 = ADD32(0, 0X1F7);
    after_0:
    // 0x80108E2C: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80108E30: jal         0x800C7D1C
    // 0x80108E34: addiu       $a0, $zero, 0x1F3
    ctx->r4 = ADD32(0, 0X1F3);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_1;
    // 0x80108E34: addiu       $a0, $zero, 0x1F3
    ctx->r4 = ADD32(0, 0X1F3);
    after_1:
    // 0x80108E38: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80108E3C: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80108E40: jr          $ra
    // 0x80108E44: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80108E44: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_80108E48(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80108E48: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80108E4C: lui         $a1, 0x4100
    ctx->r5 = S32(0X4100 << 16);
    // 0x80108E50: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80108E54: jal         0x800C7D1C
    // 0x80108E58: addiu       $a0, $zero, 0x219
    ctx->r4 = ADD32(0, 0X219);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_0;
    // 0x80108E58: addiu       $a0, $zero, 0x219
    ctx->r4 = ADD32(0, 0X219);
    after_0:
    // 0x80108E5C: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80108E60: jr          $ra
    // 0x80108E64: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80108E64: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void lvh_80108E68(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80108E68: jr          $ra
    // 0x80108E6C: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    return;
    // 0x80108E6C: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
;}
RECOMP_FUNC void lvh_calculateFriendliesSaved(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80108E70: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80108E74: addiu       $a0, $zero, 0x80
    ctx->r4 = ADD32(0, 0X80);
    // 0x80108E78: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80108E7C: jal         0x800C761C
    // 0x80108E80: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    getObjectiveCount(rdram, ctx);
        goto after_0;
    // 0x80108E80: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    after_0:
    // 0x80108E84: addiu       $a0, $zero, 0x80
    ctx->r4 = ADD32(0, 0X80);
    // 0x80108E88: jal         0x800C761C
    // 0x80108E8C: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    getObjectiveCount(rdram, ctx);
        goto after_1;
    // 0x80108E8C: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    after_1:
    // 0x80108E90: addu        $s0, $s0, $v0
    ctx->r16 = ADD32(ctx->r16, ctx->r2);
    // 0x80108E94: jal         0x800C77B0
    // 0x80108E98: negu        $a0, $s0
    ctx->r4 = SUB32(0, ctx->r16);
    setFriendliesSaved(rdram, ctx);
        goto after_2;
    // 0x80108E98: negu        $a0, $s0
    ctx->r4 = SUB32(0, ctx->r16);
    after_2:
    // 0x80108E9C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80108EA0: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80108EA4: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x80108EA8: jr          $ra
    // 0x80108EAC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80108EAC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void lvh_checkComplexObjectives(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80108EB0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80108EB4: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80108EB8: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x80108EBC: jal         0x800C794C
    // 0x80108EC0: nop

    func_800C794C(rdram, ctx);
        goto after_0;
    // 0x80108EC0: nop

    after_0:
    // 0x80108EC4: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80108EC8: ldc1        $f2, -0x6558($at)
    CHECK_FR(ctx, 2);
    ctx->f2.u64 = LD(ctx->r1, -0X6558);
    // 0x80108ECC: cvt.d.s     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.d = CVT_D_S(ctx->f0.fl);
    // 0x80108ED0: c.lt.d      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.d < ctx->f2.d;
    // 0x80108ED4: nop

    // 0x80108ED8: bc1f        L_80108F30
    if (!c1cs) {
        // 0x80108EDC: nop
    
            goto L_80108F30;
    }
    // 0x80108EDC: nop

    // 0x80108EE0: jal         0x800C759C
    // 0x80108EE4: addiu       $a0, $zero, 0x64
    ctx->r4 = ADD32(0, 0X64);
    getObjectiveBoolean(rdram, ctx);
        goto after_1;
    // 0x80108EE4: addiu       $a0, $zero, 0x64
    ctx->r4 = ADD32(0, 0X64);
    after_1:
    // 0x80108EE8: bne         $v0, $zero, L_80108F30
    if (ctx->r2 != 0) {
        // 0x80108EEC: addiu       $a0, $zero, 0x64
        ctx->r4 = ADD32(0, 0X64);
            goto L_80108F30;
    }
    // 0x80108EEC: addiu       $a0, $zero, 0x64
    ctx->r4 = ADD32(0, 0X64);
    // 0x80108EF0: jal         0x800C7540
    // 0x80108EF4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    setObjectiveBoolean(rdram, ctx);
        goto after_2;
    // 0x80108EF4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x80108EF8: addiu       $a0, $zero, 0x65
    ctx->r4 = ADD32(0, 0X65);
    // 0x80108EFC: jal         0x800C75EC
    // 0x80108F00: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    increaseObjectiveCount(rdram, ctx);
        goto after_3;
    // 0x80108F00: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
    // 0x80108F04: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x80108F08: jal         0x800C7738
    // 0x80108F0C: nop

    func_800C7738(rdram, ctx);
        goto after_4;
    // 0x80108F0C: nop

    after_4:
    // 0x80108F10: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80108F14: jal         0x800C7D1C
    // 0x80108F18: addiu       $a0, $zero, 0x2B8
    ctx->r4 = ADD32(0, 0X2B8);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_5;
    // 0x80108F18: addiu       $a0, $zero, 0x2B8
    ctx->r4 = ADD32(0, 0X2B8);
    after_5:
    // 0x80108F1C: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80108F20: jal         0x800C7D1C
    // 0x80108F24: addiu       $a0, $zero, 0x1F0
    ctx->r4 = ADD32(0, 0X1F0);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_6;
    // 0x80108F24: addiu       $a0, $zero, 0x1F0
    ctx->r4 = ADD32(0, 0X1F0);
    after_6:
    // 0x80108F28: j           L_80108F50
    // 0x80108F2C: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
        goto L_80108F50;
    // 0x80108F2C: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_80108F30:
    // 0x80108F30: jal         0x800C759C
    // 0x80108F34: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    getObjectiveBoolean(rdram, ctx);
        goto after_7;
    // 0x80108F34: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    after_7:
    // 0x80108F38: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80108F3C: bne         $v0, $v1, L_80108F50
    if (ctx->r2 != ctx->r3) {
        // 0x80108F40: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_80108F50;
    }
    // 0x80108F40: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x80108F44: jal         0x800C776C
    // 0x80108F48: nop

    func_800C776C(rdram, ctx);
        goto after_8;
    // 0x80108F48: nop

    after_8:
    // 0x80108F4C: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_80108F50:
    // 0x80108F50: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80108F54: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80108F58: jr          $ra
    // 0x80108F5C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80108F5C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void lvi_checkComplexObjectives(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80108F60: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80108F64: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80108F68: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x80108F6C: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x80108F70: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80108F74: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x80108F78: jal         0x800C7B60
    // 0x80108F7C: addiu       $a0, $a0, -0x6550
    ctx->r4 = ADD32(ctx->r4, -0X6550);
    getDatItemHealth(rdram, ctx);
        goto after_0;
    // 0x80108F7C: addiu       $a0, $a0, -0x6550
    ctx->r4 = ADD32(ctx->r4, -0X6550);
    after_0:
    // 0x80108F80: slti        $v0, $v0, 0x41
    ctx->r2 = SIGNED(ctx->r2) < 0X41 ? 1 : 0;
    // 0x80108F84: beq         $v0, $zero, L_80108FE0
    if (ctx->r2 == 0) {
        // 0x80108F88: lui         $s0, 0x8011
        ctx->r16 = S32(0X8011 << 16);
            goto L_80108FE0;
    }
    // 0x80108F88: lui         $s0, 0x8011
    ctx->r16 = S32(0X8011 << 16);
    // 0x80108F8C: lw          $v0, -0x2E1C($s0)
    ctx->r2 = MEM_W(ctx->r16, -0X2E1C);
    // 0x80108F90: bne         $v0, $zero, L_80108FE0
    if (ctx->r2 != 0) {
        // 0x80108F94: nop
    
            goto L_80108FE0;
    }
    // 0x80108F94: nop

    // 0x80108F98: jal         0x800C7738
    // 0x80108F9C: nop

    func_800C7738(rdram, ctx);
        goto after_1;
    // 0x80108F9C: nop

    after_1:
    // 0x80108FA0: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80108FA4: addiu       $a0, $a0, -0x6540
    ctx->r4 = ADD32(ctx->r4, -0X6540);
    // 0x80108FA8: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x80108FAC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80108FB0: jal         0x800C7884
    // 0x80108FB4: sw          $v0, -0x2E1C($s0)
    MEM_W(-0X2E1C, ctx->r16) = ctx->r2;
    func_800C7884(rdram, ctx);
        goto after_2;
    // 0x80108FB4: sw          $v0, -0x2E1C($s0)
    MEM_W(-0X2E1C, ctx->r16) = ctx->r2;
    after_2:
    // 0x80108FB8: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80108FBC: jal         0x800C7D1C
    // 0x80108FC0: addiu       $a0, $zero, 0x11
    ctx->r4 = ADD32(0, 0X11);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_3;
    // 0x80108FC0: addiu       $a0, $zero, 0x11
    ctx->r4 = ADD32(0, 0X11);
    after_3:
    // 0x80108FC4: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80108FC8: jal         0x800C7D1C
    // 0x80108FCC: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_4;
    // 0x80108FCC: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    after_4:
    // 0x80108FD0: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80108FD4: lui         $a1, 0x40A0
    ctx->r5 = S32(0X40A0 << 16);
    // 0x80108FD8: jal         0x800C7864
    // 0x80108FDC: addiu       $a0, $a0, -0x6F34
    ctx->r4 = ADD32(ctx->r4, -0X6F34);
    addTimerHandleWrapper(rdram, ctx);
        goto after_5;
    // 0x80108FDC: addiu       $a0, $a0, -0x6F34
    ctx->r4 = ADD32(ctx->r4, -0X6F34);
    after_5:
L_80108FE0:
    // 0x80108FE0: jal         0x800C759C
    // 0x80108FE4: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    getObjectiveBoolean(rdram, ctx);
        goto after_6;
    // 0x80108FE4: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    after_6:
    // 0x80108FE8: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // 0x80108FEC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80108FF0: bne         $s0, $v0, L_8010904C
    if (ctx->r16 != ctx->r2) {
        // 0x80108FF4: nop
    
            goto L_8010904C;
    }
    // 0x80108FF4: nop

    // 0x80108FF8: lui         $s1, 0x8011
    ctx->r17 = S32(0X8011 << 16);
    // 0x80108FFC: lw          $v0, -0x2E1C($s1)
    ctx->r2 = MEM_W(ctx->r17, -0X2E1C);
    // 0x80109000: bne         $v0, $zero, L_8010904C
    if (ctx->r2 != 0) {
        // 0x80109004: nop
    
            goto L_8010904C;
    }
    // 0x80109004: nop

    // 0x80109008: jal         0x800C7738
    // 0x8010900C: nop

    func_800C7738(rdram, ctx);
        goto after_7;
    // 0x8010900C: nop

    after_7:
    // 0x80109010: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80109014: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x80109018: addiu       $a0, $a0, -0x6540
    ctx->r4 = ADD32(ctx->r4, -0X6540);
    // 0x8010901C: jal         0x800C7884
    // 0x80109020: sw          $s0, -0x2E1C($s1)
    MEM_W(-0X2E1C, ctx->r17) = ctx->r16;
    func_800C7884(rdram, ctx);
        goto after_8;
    // 0x80109020: sw          $s0, -0x2E1C($s1)
    MEM_W(-0X2E1C, ctx->r17) = ctx->r16;
    after_8:
    // 0x80109024: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80109028: jal         0x800C7D1C
    // 0x8010902C: addiu       $a0, $zero, 0x11
    ctx->r4 = ADD32(0, 0X11);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_9;
    // 0x8010902C: addiu       $a0, $zero, 0x11
    ctx->r4 = ADD32(0, 0X11);
    after_9:
    // 0x80109030: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80109034: jal         0x800C7D1C
    // 0x80109038: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_10;
    // 0x80109038: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    after_10:
    // 0x8010903C: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80109040: lui         $a1, 0x40A0
    ctx->r5 = S32(0X40A0 << 16);
    // 0x80109044: jal         0x800C7864
    // 0x80109048: addiu       $a0, $a0, -0x6F10
    ctx->r4 = ADD32(ctx->r4, -0X6F10);
    addTimerHandleWrapper(rdram, ctx);
        goto after_11;
    // 0x80109048: addiu       $a0, $a0, -0x6F10
    ctx->r4 = ADD32(ctx->r4, -0X6F10);
    after_11:
L_8010904C:
    // 0x8010904C: jal         0x800C761C
    // 0x80109050: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    getObjectiveCount(rdram, ctx);
        goto after_12;
    // 0x80109050: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    after_12:
    // 0x80109054: addiu       $v1, $zero, 0x8
    ctx->r3 = ADD32(0, 0X8);
    // 0x80109058: bne         $v0, $v1, L_801090B0
    if (ctx->r2 != ctx->r3) {
        // 0x8010905C: lui         $s0, 0x8011
        ctx->r16 = S32(0X8011 << 16);
            goto L_801090B0;
    }
    // 0x8010905C: lui         $s0, 0x8011
    ctx->r16 = S32(0X8011 << 16);
    // 0x80109060: lw          $v0, -0x2E14($s0)
    ctx->r2 = MEM_W(ctx->r16, -0X2E14);
    // 0x80109064: bne         $v0, $zero, L_801090B0
    if (ctx->r2 != 0) {
        // 0x80109068: nop
    
            goto L_801090B0;
    }
    // 0x80109068: nop

    // 0x8010906C: jal         0x800C776C
    // 0x80109070: nop

    func_800C776C(rdram, ctx);
        goto after_13;
    // 0x80109070: nop

    after_13:
    // 0x80109074: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80109078: jal         0x800C7884
    // 0x8010907C: addiu       $a0, $a0, -0x6534
    ctx->r4 = ADD32(ctx->r4, -0X6534);
    func_800C7884(rdram, ctx);
        goto after_14;
    // 0x8010907C: addiu       $a0, $a0, -0x6534
    ctx->r4 = ADD32(ctx->r4, -0X6534);
    after_14:
    // 0x80109080: addiu       $a0, $zero, 0x2BE
    ctx->r4 = ADD32(0, 0X2BE);
    // 0x80109084: jal         0x800C7D1C
    // 0x80109088: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_15;
    // 0x80109088: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_15:
    // 0x8010908C: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    // 0x80109090: jal         0x800C7D1C
    // 0x80109094: addiu       $a0, $zero, 0x2BF
    ctx->r4 = ADD32(0, 0X2BF);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_16;
    // 0x80109094: addiu       $a0, $zero, 0x2BF
    ctx->r4 = ADD32(0, 0X2BF);
    after_16:
    // 0x80109098: jal         0x800C76B0
    // 0x8010909C: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    activateObjectiveCompleteFlag(rdram, ctx);
        goto after_17;
    // 0x8010909C: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_17:
    // 0x801090A0: jal         0x800C7D98
    // 0x801090A4: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    func_800C7D98(rdram, ctx);
        goto after_18;
    // 0x801090A4: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    after_18:
    // 0x801090A8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x801090AC: sw          $v0, -0x2E14($s0)
    MEM_W(-0X2E14, ctx->r16) = ctx->r2;
L_801090B0:
    // 0x801090B0: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x801090B4: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x801090B8: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x801090BC: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x801090C0: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x801090C4: jr          $ra
    // 0x801090C8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x801090C8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_801090CC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801090CC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801090D0: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x801090D4: addiu       $a0, $a0, -0x6550
    ctx->r4 = ADD32(ctx->r4, -0X6550);
    // 0x801090D8: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x801090DC: jal         0x800C7390
    // 0x801090E0: addiu       $a1, $zero, 0x42
    ctx->r5 = ADD32(0, 0X42);
    dealDamagetoDatItem(rdram, ctx);
        goto after_0;
    // 0x801090E0: addiu       $a1, $zero, 0x42
    ctx->r5 = ADD32(0, 0X42);
    after_0:
    // 0x801090E4: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x801090E8: jr          $ra
    // 0x801090EC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x801090EC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_801090F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801090F0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801090F4: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x801090F8: addiu       $a0, $a0, -0x6550
    ctx->r4 = ADD32(ctx->r4, -0X6550);
    // 0x801090FC: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80109100: jal         0x800C7390
    // 0x80109104: addiu       $a1, $zero, 0x321
    ctx->r5 = ADD32(0, 0X321);
    dealDamagetoDatItem(rdram, ctx);
        goto after_0;
    // 0x80109104: addiu       $a1, $zero, 0x321
    ctx->r5 = ADD32(0, 0X321);
    after_0:
    // 0x80109108: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x8010910C: jr          $ra
    // 0x80109110: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80109110: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void lvi_initializeObjectTracking(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80109114: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80109118: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x8010911C: addiu       $a0, $a0, -0x6DF8
    ctx->r4 = ADD32(ctx->r4, -0X6DF8);
    // 0x80109120: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80109124: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    // 0x80109128: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    // 0x8010912C: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80109130: sw          $zero, -0x2E1C($v0)
    MEM_W(-0X2E1C, ctx->r2) = 0;
    // 0x80109134: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80109138: sw          $zero, -0x2E18($v0)
    MEM_W(-0X2E18, ctx->r2) = 0;
    // 0x8010913C: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80109140: sw          $zero, -0x2E14($v0)
    MEM_W(-0X2E14, ctx->r2) = 0;
    // 0x80109144: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80109148: sw          $zero, -0x2E20($v0)
    MEM_W(-0X2E20, ctx->r2) = 0;
    // 0x8010914C: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x80109150: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80109154: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80109158: jal         0x800C7830
    // 0x8010915C: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    addBooleanCountHandleWrapper(rdram, ctx);
        goto after_0;
    // 0x8010915C: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_0:
    // 0x80109160: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80109164: addiu       $a0, $a0, -0x6C7C
    ctx->r4 = ADD32(ctx->r4, -0X6C7C);
    // 0x80109168: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x8010916C: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    // 0x80109170: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    // 0x80109174: addiu       $s0, $zero, 0x4
    ctx->r16 = ADD32(0, 0X4);
    // 0x80109178: jal         0x800C7830
    // 0x8010917C: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    addBooleanCountHandleWrapper(rdram, ctx);
        goto after_1;
    // 0x8010917C: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    after_1:
    // 0x80109180: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80109184: addiu       $a0, $a0, -0x6D1C
    ctx->r4 = ADD32(ctx->r4, -0X6D1C);
    // 0x80109188: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x8010918C: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    // 0x80109190: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    // 0x80109194: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
    // 0x80109198: jal         0x800C7830
    // 0x8010919C: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    addBooleanCountHandleWrapper(rdram, ctx);
        goto after_2;
    // 0x8010919C: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_2:
    // 0x801091A0: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x801091A4: addiu       $a0, $a0, -0x6C24
    ctx->r4 = ADD32(ctx->r4, -0X6C24);
    // 0x801091A8: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    // 0x801091AC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801091B0: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // 0x801091B4: jal         0x800C7830
    // 0x801091B8: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    addBooleanCountHandleWrapper(rdram, ctx);
        goto after_3;
    // 0x801091B8: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_3:
    // 0x801091BC: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x801091C0: addiu       $a0, $a0, -0x6C50
    ctx->r4 = ADD32(ctx->r4, -0X6C50);
    // 0x801091C4: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x801091C8: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    // 0x801091CC: addu        $a3, $s0, $zero
    ctx->r7 = ADD32(ctx->r16, 0);
    // 0x801091D0: jal         0x800C7830
    // 0x801091D4: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    addBooleanCountHandleWrapper(rdram, ctx);
        goto after_4;
    // 0x801091D4: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    after_4:
    // 0x801091D8: addiu       $a0, $zero, 0x2BC
    ctx->r4 = ADD32(0, 0X2BC);
    // 0x801091DC: jal         0x800C7D1C
    // 0x801091E0: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_5;
    // 0x801091E0: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_5:
    // 0x801091E4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801091E8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x801091EC: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x801091F0: jr          $ra
    // 0x801091F4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x801091F4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void lvi_801091F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801091F8: jr          $ra
    // 0x801091FC: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    return;
    // 0x801091FC: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
;}
RECOMP_FUNC void lvi_calculateFriendliesSaved(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80109200: jr          $ra
    // 0x80109204: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    return;
    // 0x80109204: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
;}
RECOMP_FUNC void func_80109208(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80109208: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8010920C: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80109210: lui         $a1, 0x4040
    ctx->r5 = S32(0X4040 << 16);
    // 0x80109214: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80109218: jal         0x800C7864
    // 0x8010921C: addiu       $a0, $a0, -0x6DD4
    ctx->r4 = ADD32(ctx->r4, -0X6DD4);
    addTimerHandleWrapper(rdram, ctx);
        goto after_0;
    // 0x8010921C: addiu       $a0, $a0, -0x6DD4
    ctx->r4 = ADD32(ctx->r4, -0X6DD4);
    after_0:
    // 0x80109220: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80109224: jr          $ra
    // 0x80109228: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80109228: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_8010922C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010922C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80109230: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80109234: addiu       $a0, $a0, -0x6520
    ctx->r4 = ADD32(ctx->r4, -0X6520);
    // 0x80109238: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8010923C: jal         0x800C7884
    // 0x80109240: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    func_800C7884(rdram, ctx);
        goto after_0;
    // 0x80109240: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    after_0:
    // 0x80109244: lui         $a1, 0x3FC0
    ctx->r5 = S32(0X3FC0 << 16);
    // 0x80109248: jal         0x800C7D1C
    // 0x8010924C: addiu       $a0, $zero, 0x126
    ctx->r4 = ADD32(0, 0X126);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_1;
    // 0x8010924C: addiu       $a0, $zero, 0x126
    ctx->r4 = ADD32(0, 0X126);
    after_1:
    // 0x80109250: addiu       $a0, $zero, 0x127
    ctx->r4 = ADD32(0, 0X127);
    // 0x80109254: jal         0x800C7D1C
    // 0x80109258: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_2;
    // 0x80109258: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_2:
    // 0x8010925C: lui         $a1, 0x4000
    ctx->r5 = S32(0X4000 << 16);
    // 0x80109260: jal         0x800C7D1C
    // 0x80109264: addiu       $a0, $zero, 0x137
    ctx->r4 = ADD32(0, 0X137);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_3;
    // 0x80109264: addiu       $a0, $zero, 0x137
    ctx->r4 = ADD32(0, 0X137);
    after_3:
    // 0x80109268: jal         0x800C76B0
    // 0x8010926C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    activateObjectiveCompleteFlag(rdram, ctx);
        goto after_4;
    // 0x8010926C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_4:
    // 0x80109270: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80109274: addiu       $a0, $a0, -0x6510
    ctx->r4 = ADD32(ctx->r4, -0X6510);
    // 0x80109278: lui         $s0, 0x800B
    ctx->r16 = S32(0X800B << 16);
    // 0x8010927C: addiu       $s0, $s0, -0x64FC
    ctx->r16 = ADD32(ctx->r16, -0X64FC);
    // 0x80109280: jal         0x800C7AB0
    // 0x80109284: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    func_800C7AB0(rdram, ctx);
        goto after_5;
    // 0x80109284: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_5:
    // 0x80109288: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x8010928C: addiu       $a0, $a0, -0x64E4
    ctx->r4 = ADD32(ctx->r4, -0X64E4);
    // 0x80109290: jal         0x800C7AB0
    // 0x80109294: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    func_800C7AB0(rdram, ctx);
        goto after_6;
    // 0x80109294: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_6:
    // 0x80109298: addiu       $a0, $zero, 0x78
    ctx->r4 = ADD32(0, 0X78);
    // 0x8010929C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x801092A0: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x801092A4: addu        $v0, $a1, $zero
    ctx->r2 = ADD32(ctx->r5, 0);
    // 0x801092A8: jal         0x800C7540
    // 0x801092AC: sw          $v0, -0x2E18($v1)
    MEM_W(-0X2E18, ctx->r3) = ctx->r2;
    setObjectiveBoolean(rdram, ctx);
        goto after_7;
    // 0x801092AC: sw          $v0, -0x2E18($v1)
    MEM_W(-0X2E18, ctx->r3) = ctx->r2;
    after_7:
    // 0x801092B0: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x801092B4: addiu       $a0, $a0, -0x64D0
    ctx->r4 = ADD32(ctx->r4, -0X64D0);
    // 0x801092B8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x801092BC: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x801092C0: addu        $v0, $a1, $zero
    ctx->r2 = ADD32(ctx->r5, 0);
    // 0x801092C4: jal         0x800C7D60
    // 0x801092C8: sw          $v0, -0x2E20($v1)
    MEM_W(-0X2E20, ctx->r3) = ctx->r2;
    func_800C7D60(rdram, ctx);
        goto after_8;
    // 0x801092C8: sw          $v0, -0x2E20($v1)
    MEM_W(-0X2E20, ctx->r3) = ctx->r2;
    after_8:
    // 0x801092CC: jal         0x800C7D98
    // 0x801092D0: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    func_800C7D98(rdram, ctx);
        goto after_9;
    // 0x801092D0: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    after_9:
    // 0x801092D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801092D8: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x801092DC: jr          $ra
    // 0x801092E0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x801092E0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_801092E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801092E4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801092E8: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x801092EC: lui         $a1, 0x40A0
    ctx->r5 = S32(0X40A0 << 16);
    // 0x801092F0: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x801092F4: jal         0x800C7864
    // 0x801092F8: addiu       $a0, $a0, -0x6CDC
    ctx->r4 = ADD32(ctx->r4, -0X6CDC);
    addTimerHandleWrapper(rdram, ctx);
        goto after_0;
    // 0x801092F8: addiu       $a0, $a0, -0x6CDC
    ctx->r4 = ADD32(ctx->r4, -0X6CDC);
    after_0:
    // 0x801092FC: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80109300: addiu       $a0, $a0, -0x64D0
    ctx->r4 = ADD32(ctx->r4, -0X64D0);
    // 0x80109304: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80109308: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x8010930C: addu        $v0, $a1, $zero
    ctx->r2 = ADD32(ctx->r5, 0);
    // 0x80109310: jal         0x800C7D60
    // 0x80109314: sw          $v0, -0x2E20($v1)
    MEM_W(-0X2E20, ctx->r3) = ctx->r2;
    func_800C7D60(rdram, ctx);
        goto after_1;
    // 0x80109314: sw          $v0, -0x2E20($v1)
    MEM_W(-0X2E20, ctx->r3) = ctx->r2;
    after_1:
    // 0x80109318: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x8010931C: jr          $ra
    // 0x80109320: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80109320: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80109324(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80109324: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80109328: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x8010932C: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80109330: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x80109334: jal         0x800C7884
    // 0x80109338: addiu       $a0, $a0, -0x64B8
    ctx->r4 = ADD32(ctx->r4, -0X64B8);
    func_800C7884(rdram, ctx);
        goto after_0;
    // 0x80109338: addiu       $a0, $a0, -0x64B8
    ctx->r4 = ADD32(ctx->r4, -0X64B8);
    after_0:
    // 0x8010933C: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    // 0x80109340: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x80109344: jal         0x800C7D1C
    // 0x80109348: addiu       $a0, $zero, 0x2BD
    ctx->r4 = ADD32(0, 0X2BD);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_1;
    // 0x80109348: addiu       $a0, $zero, 0x2BD
    ctx->r4 = ADD32(0, 0X2BD);
    after_1:
    // 0x8010934C: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80109350: jal         0x800C7D1C
    // 0x80109354: addiu       $a0, $zero, 0x11A
    ctx->r4 = ADD32(0, 0X11A);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_2;
    // 0x80109354: addiu       $a0, $zero, 0x11A
    ctx->r4 = ADD32(0, 0X11A);
    after_2:
    // 0x80109358: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x8010935C: jal         0x800C7D1C
    // 0x80109360: addiu       $a0, $zero, 0x11B
    ctx->r4 = ADD32(0, 0X11B);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_3;
    // 0x80109360: addiu       $a0, $zero, 0x11B
    ctx->r4 = ADD32(0, 0X11B);
    after_3:
    // 0x80109364: jal         0x800C76B0
    // 0x80109368: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    activateObjectiveCompleteFlag(rdram, ctx);
        goto after_4;
    // 0x80109368: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_4:
    // 0x8010936C: jal         0x800C7D98
    // 0x80109370: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    func_800C7D98(rdram, ctx);
        goto after_5;
    // 0x80109370: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_5:
    // 0x80109374: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80109378: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x8010937C: jr          $ra
    // 0x80109380: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80109380: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_80109384(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80109384: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80109388: lui         $a1, 0x3F00
    ctx->r5 = S32(0X3F00 << 16);
    // 0x8010938C: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80109390: jal         0x800C7D1C
    // 0x80109394: addiu       $a0, $zero, 0x21C
    ctx->r4 = ADD32(0, 0X21C);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_0;
    // 0x80109394: addiu       $a0, $zero, 0x21C
    ctx->r4 = ADD32(0, 0X21C);
    after_0:
    // 0x80109398: addiu       $a0, $zero, 0x13E
    ctx->r4 = ADD32(0, 0X13E);
    // 0x8010939C: jal         0x800C7D1C
    // 0x801093A0: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_1;
    // 0x801093A0: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_1:
    // 0x801093A4: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x801093A8: jr          $ra
    // 0x801093AC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x801093AC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_801093B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801093B0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801093B4: lui         $a1, 0x3F00
    ctx->r5 = S32(0X3F00 << 16);
    // 0x801093B8: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x801093BC: jal         0x800C7D1C
    // 0x801093C0: addiu       $a0, $zero, 0x230
    ctx->r4 = ADD32(0, 0X230);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_0;
    // 0x801093C0: addiu       $a0, $zero, 0x230
    ctx->r4 = ADD32(0, 0X230);
    after_0:
    // 0x801093C4: addiu       $a0, $zero, 0x13A
    ctx->r4 = ADD32(0, 0X13A);
    // 0x801093C8: jal         0x800C7D1C
    // 0x801093CC: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_1;
    // 0x801093CC: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_1:
    // 0x801093D0: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x801093D4: jr          $ra
    // 0x801093D8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x801093D8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_801093DC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801093DC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801093E0: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x801093E4: lui         $s0, 0x8011
    ctx->r16 = S32(0X8011 << 16);
    // 0x801093E8: lw          $v0, -0x2E18($s0)
    ctx->r2 = MEM_W(ctx->r16, -0X2E18);
    // 0x801093EC: bne         $v0, $zero, L_80109418
    if (ctx->r2 != 0) {
        // 0x801093F0: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_80109418;
    }
    // 0x801093F0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801093F4: jal         0x800C761C
    // 0x801093F8: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    getObjectiveCount(rdram, ctx);
        goto after_0;
    // 0x801093F8: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_0:
    // 0x801093FC: addiu       $v1, $zero, 0x6
    ctx->r3 = ADD32(0, 0X6);
    // 0x80109400: bne         $v0, $v1, L_80109418
    if (ctx->r2 != ctx->r3) {
        // 0x80109404: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80109418;
    }
    // 0x80109404: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80109408: sw          $v0, -0x2E18($s0)
    MEM_W(-0X2E18, ctx->r16) = ctx->r2;
    // 0x8010940C: addiu       $a0, $zero, 0x226
    ctx->r4 = ADD32(0, 0X226);
    // 0x80109410: jal         0x800C7D1C
    // 0x80109414: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_1;
    // 0x80109414: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_1:
L_80109418:
    // 0x80109418: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8010941C: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80109420: jr          $ra
    // 0x80109424: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80109424: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void fake_func_80109428(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
;}
RECOMP_FUNC void lvk_checkComplexObjectives(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80109430: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80109434: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80109438: lui         $s0, 0x8011
    ctx->r16 = S32(0X8011 << 16);
    // 0x8010943C: lw          $v0, -0x2E10($s0)
    ctx->r2 = MEM_W(ctx->r16, -0X2E10);
    // 0x80109440: bne         $v0, $zero, L_80109544
    if (ctx->r2 != 0) {
        // 0x80109444: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_80109544;
    }
    // 0x80109444: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80109448: jal         0x800C761C
    // 0x8010944C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    getObjectiveCount(rdram, ctx);
        goto after_0;
    // 0x8010944C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x80109450: addiu       $v1, $zero, 0x25
    ctx->r3 = ADD32(0, 0X25);
    // 0x80109454: bne         $v0, $v1, L_8010949C
    if (ctx->r2 != ctx->r3) {
        // 0x80109458: nop
    
            goto L_8010949C;
    }
    // 0x80109458: nop

    // 0x8010945C: jal         0x800C761C
    // 0x80109460: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    getObjectiveCount(rdram, ctx);
        goto after_1;
    // 0x80109460: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_1:
    // 0x80109464: addiu       $v1, $zero, 0xF
    ctx->r3 = ADD32(0, 0XF);
    // 0x80109468: bne         $v0, $v1, L_8010949C
    if (ctx->r2 != ctx->r3) {
        // 0x8010946C: lui         $a0, 0x800B
        ctx->r4 = S32(0X800B << 16);
            goto L_8010949C;
    }
    // 0x8010946C: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80109470: addiu       $a0, $a0, -0x64A0
    ctx->r4 = ADD32(ctx->r4, -0X64A0);
    // 0x80109474: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80109478: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8010947C: jal         0x800C7D60
    // 0x80109480: sw          $v0, -0x2E10($s0)
    MEM_W(-0X2E10, ctx->r16) = ctx->r2;
    func_800C7D60(rdram, ctx);
        goto after_2;
    // 0x80109480: sw          $v0, -0x2E10($s0)
    MEM_W(-0X2E10, ctx->r16) = ctx->r2;
    after_2:
    // 0x80109484: jal         0x800C7D98
    // 0x80109488: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    func_800C7D98(rdram, ctx);
        goto after_3;
    // 0x80109488: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_3:
    // 0x8010948C: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80109490: lui         $a1, 0x40B0
    ctx->r5 = S32(0X40B0 << 16);
    // 0x80109494: j           L_801094F0
    // 0x80109498: addiu       $a0, $a0, -0x6AA8
    ctx->r4 = ADD32(ctx->r4, -0X6AA8);
        goto L_801094F0;
    // 0x80109498: addiu       $a0, $a0, -0x6AA8
    ctx->r4 = ADD32(ctx->r4, -0X6AA8);
L_8010949C:
    // 0x8010949C: jal         0x800C761C
    // 0x801094A0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    getObjectiveCount(rdram, ctx);
        goto after_4;
    // 0x801094A0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_4:
    // 0x801094A4: addiu       $v1, $zero, 0x25
    ctx->r3 = ADD32(0, 0X25);
    // 0x801094A8: bne         $v0, $v1, L_801094F8
    if (ctx->r2 != ctx->r3) {
        // 0x801094AC: nop
    
            goto L_801094F8;
    }
    // 0x801094AC: nop

    // 0x801094B0: jal         0x800C759C
    // 0x801094B4: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    getObjectiveBoolean(rdram, ctx);
        goto after_5;
    // 0x801094B4: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    after_5:
    // 0x801094B8: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x801094BC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x801094C0: bne         $v1, $v0, L_801094F8
    if (ctx->r3 != ctx->r2) {
        // 0x801094C4: lui         $a0, 0x800B
        ctx->r4 = S32(0X800B << 16);
            goto L_801094F8;
    }
    // 0x801094C4: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x801094C8: addiu       $a0, $a0, -0x64A0
    ctx->r4 = ADD32(ctx->r4, -0X64A0);
    // 0x801094CC: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x801094D0: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x801094D4: jal         0x800C7D60
    // 0x801094D8: sw          $v1, -0x2E10($v0)
    MEM_W(-0X2E10, ctx->r2) = ctx->r3;
    func_800C7D60(rdram, ctx);
        goto after_6;
    // 0x801094D8: sw          $v1, -0x2E10($v0)
    MEM_W(-0X2E10, ctx->r2) = ctx->r3;
    after_6:
    // 0x801094DC: jal         0x800C7D98
    // 0x801094E0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800C7D98(rdram, ctx);
        goto after_7;
    // 0x801094E0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_7:
    // 0x801094E4: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x801094E8: lui         $a1, 0x4090
    ctx->r5 = S32(0X4090 << 16);
    // 0x801094EC: addiu       $a0, $a0, -0x6A8C
    ctx->r4 = ADD32(ctx->r4, -0X6A8C);
L_801094F0:
    // 0x801094F0: jal         0x800C7864
    // 0x801094F4: nop

    addTimerHandleWrapper(rdram, ctx);
        goto after_8;
    // 0x801094F4: nop

    after_8:
L_801094F8:
    // 0x801094F8: jal         0x800C759C
    // 0x801094FC: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    getObjectiveBoolean(rdram, ctx);
        goto after_9;
    // 0x801094FC: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_9:
    // 0x80109500: bne         $v0, $zero, L_80109544
    if (ctx->r2 != 0) {
        // 0x80109504: nop
    
            goto L_80109544;
    }
    // 0x80109504: nop

    // 0x80109508: jal         0x800C761C
    // 0x8010950C: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    getObjectiveCount(rdram, ctx);
        goto after_10;
    // 0x8010950C: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_10:
    // 0x80109510: blez        $v0, L_80109544
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80109514: nop
    
            goto L_80109544;
    }
    // 0x80109514: nop

    // 0x80109518: jal         0x800C761C
    // 0x8010951C: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    getObjectiveCount(rdram, ctx);
        goto after_11;
    // 0x8010951C: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_11:
    // 0x80109520: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x80109524: jal         0x800C761C
    // 0x80109528: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    getObjectiveCount(rdram, ctx);
        goto after_12;
    // 0x80109528: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    after_12:
    // 0x8010952C: addiu       $v1, $zero, 0xF
    ctx->r3 = ADD32(0, 0XF);
    // 0x80109530: subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // 0x80109534: bne         $s0, $v1, L_80109544
    if (ctx->r16 != ctx->r3) {
        // 0x80109538: addiu       $a0, $zero, 0x3
        ctx->r4 = ADD32(0, 0X3);
            goto L_80109544;
    }
    // 0x80109538: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x8010953C: jal         0x800C7540
    // 0x80109540: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    setObjectiveBoolean(rdram, ctx);
        goto after_13;
    // 0x80109540: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_13:
L_80109544:
    // 0x80109544: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80109548: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8010954C: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x80109550: jr          $ra
    // 0x80109554: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80109554: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80109558(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80109558: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8010955C: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80109560: jal         0x800C776C
    // 0x80109564: nop

    func_800C776C(rdram, ctx);
        goto after_0;
    // 0x80109564: nop

    after_0:
    // 0x80109568: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x8010956C: jr          $ra
    // 0x80109570: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80109570: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80109574(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80109574: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80109578: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x8010957C: jal         0x800C7738
    // 0x80109580: nop

    func_800C7738(rdram, ctx);
        goto after_0;
    // 0x80109580: nop

    after_0:
    // 0x80109584: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80109588: jr          $ra
    // 0x8010958C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8010958C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void lvk_initializeObjectTracking(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80109590: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80109594: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80109598: addiu       $a0, $a0, -0x6A24
    ctx->r4 = ADD32(ctx->r4, -0X6A24);
    // 0x8010959C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x801095A0: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    // 0x801095A4: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // 0x801095A8: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x801095AC: jal         0x800C7830
    // 0x801095B0: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    addBooleanCountHandleWrapper(rdram, ctx);
        goto after_0;
    // 0x801095B0: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_0:
    // 0x801095B4: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x801095B8: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x801095BC: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x801095C0: sw          $zero, -0x2E10($v1)
    MEM_W(-0X2E10, ctx->r3) = 0;
    // 0x801095C4: jr          $ra
    // 0x801095C8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x801095C8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void lvk_801095CC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801095CC: jr          $ra
    // 0x801095D0: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    return;
    // 0x801095D0: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
;}
RECOMP_FUNC void lvk_calculateFriendliesSaved(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801095D4: jr          $ra
    // 0x801095D8: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    return;
    // 0x801095D8: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
;}
RECOMP_FUNC void func_801095DC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801095DC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801095E0: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x801095E4: addiu       $s0, $zero, 0xA
    ctx->r16 = ADD32(0, 0XA);
    // 0x801095E8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801095EC: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
L_801095F0:
    // 0x801095F0: jal         0x800C7540
    // 0x801095F4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    setObjectiveBoolean(rdram, ctx);
        goto after_0;
    // 0x801095F4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x801095F8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x801095FC: slti        $v0, $s0, 0x19
    ctx->r2 = SIGNED(ctx->r16) < 0X19 ? 1 : 0;
    // 0x80109600: bne         $v0, $zero, L_801095F0
    if (ctx->r2 != 0) {
        // 0x80109604: addu        $a0, $s0, $zero
        ctx->r4 = ADD32(ctx->r16, 0);
            goto L_801095F0;
    }
    // 0x80109604: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80109608: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8010960C: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80109610: jr          $ra
    // 0x80109614: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80109614: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void fake_func_80109618(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
;}
RECOMP_FUNC void lvj_initializeObjectTracking(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80109620: jr          $ra
    // 0x80109624: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    return;
    // 0x80109624: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
;}
RECOMP_FUNC void lvj_80109628(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80109628: jr          $ra
    // 0x8010962C: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    return;
    // 0x8010962C: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
;}
RECOMP_FUNC void lvj_calculateFriendliesSaved(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80109630: jr          $ra
    // 0x80109634: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    return;
    // 0x80109634: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
;}
RECOMP_FUNC void lvj_checkComplexObjectives(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80109638: jr          $ra
    // 0x8010963C: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    return;
    // 0x8010963C: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
;}
RECOMP_FUNC void func_8008ED70(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008ED70: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8008ED74: addiu       $a0, $zero, 0x3000
    ctx->r4 = ADD32(0, 0X3000);
    // 0x8008ED78: addiu       $a1, $zero, 0x80
    ctx->r5 = ADD32(0, 0X80);
    // 0x8008ED7C: sw          $ra, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r31;
    // 0x8008ED80: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8008ED84: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8008ED88: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8008ED8C: jal         0x80001ACC
    // 0x8008ED90: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    rs_malloc(rdram, ctx);
        goto after_0;
    // 0x8008ED90: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    after_0:
    // 0x8008ED94: lui         $v1, 0x8015
    ctx->r3 = S32(0X8015 << 16);
    // 0x8008ED98: addiu       $v1, $v1, -0x6950
    ctx->r3 = ADD32(ctx->r3, -0X6950);
    // 0x8008ED9C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8008EDA0: addiu       $a0, $v1, 0x4
    ctx->r4 = ADD32(ctx->r3, 0X4);
    // 0x8008EDA4: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
L_8008EDA8:
    // 0x8008EDA8: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8008EDAC: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8008EDB0: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8008EDB4: addiu       $v0, $v0, 0x300
    ctx->r2 = ADD32(ctx->r2, 0X300);
    // 0x8008EDB8: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // 0x8008EDBC: slti        $v0, $a1, 0x10
    ctx->r2 = SIGNED(ctx->r5) < 0X10 ? 1 : 0;
    // 0x8008EDC0: bne         $v0, $zero, L_8008EDA8
    if (ctx->r2 != 0) {
        // 0x8008EDC4: addiu       $a0, $a0, 0x4
        ctx->r4 = ADD32(ctx->r4, 0X4);
            goto L_8008EDA8;
    }
    // 0x8008EDC4: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x8008EDC8: lui         $s0, 0x8015
    ctx->r16 = S32(0X8015 << 16);
    // 0x8008EDCC: addiu       $s0, $s0, -0x6950
    ctx->r16 = ADD32(ctx->r16, -0X6950);
    // 0x8008EDD0: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8008EDD4: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x8008EDD8: addiu       $a2, $zero, 0x3000
    ctx->r6 = ADD32(0, 0X3000);
    // 0x8008EDDC: jal         0x800078E0
    // 0x8008EDE0: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    rs_memset(rdram, ctx);
        goto after_1;
    // 0x8008EDE0: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    after_1:
    // 0x8008EDE4: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8008EDE8: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
    // 0x8008EDEC: jal         0x800358B0
    // 0x8008EDF0: addiu       $a1, $zero, 0x3000
    ctx->r5 = ADD32(0, 0X3000);
    osWritebackDCache_recomp(rdram, ctx);
        goto after_2;
    // 0x8008EDF0: addiu       $a1, $zero, 0x3000
    ctx->r5 = ADD32(0, 0X3000);
    after_2:
    // 0x8008EDF4: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8008EDF8: addiu       $s2, $zero, 0xFF
    ctx->r18 = ADD32(0, 0XFF);
    // 0x8008EDFC: addiu       $a1, $zero, 0x300
    ctx->r5 = ADD32(0, 0X300);
    // 0x8008EE00: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8008EE04: sb          $zero, -0x6910($at)
    MEM_B(-0X6910, ctx->r1) = 0;
    // 0x8008EE08: jal         0x80029E80
    // 0x8008EE0C: nop

    osAiSetNextBuffer_recomp(rdram, ctx);
        goto after_3;
    // 0x8008EE0C: nop

    after_3:
L_8008EE10:
    // 0x8008EE10: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x8008EE14: addiu       $a0, $a0, -0x6990
    ctx->r4 = ADD32(ctx->r4, -0X6990);
    // 0x8008EE18: addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    // 0x8008EE1C: jal         0x800331D0
    // 0x8008EE20: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_4;
    // 0x8008EE20: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_4:
    // 0x8008EE24: lw          $v0, 0x10($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X10);
    // 0x8008EE28: lbu         $v0, 0x0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X0);
    // 0x8008EE2C: beq         $v0, $s3, L_8008EE44
    if (ctx->r2 == ctx->r19) {
        // 0x8008EE30: nop
    
            goto L_8008EE44;
    }
    // 0x8008EE30: nop

    // 0x8008EE34: beql        $v0, $s2, L_8008EE94
    if (ctx->r2 == ctx->r18) {
        // 0x8008EE38: addiu       $s1, $zero, 0x1
        ctx->r17 = ADD32(0, 0X1);
            goto L_8008EE94;
    }
    goto skip_0;
    // 0x8008EE38: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
    skip_0:
    // 0x8008EE3C: j           L_8008EE98
    // 0x8008EE40: andi        $v0, $s1, 0xFF
    ctx->r2 = ctx->r17 & 0XFF;
        goto L_8008EE98;
    // 0x8008EE40: andi        $v0, $s1, 0xFF
    ctx->r2 = ctx->r17 & 0XFF;
L_8008EE44:
    // 0x8008EE44: lui         $v0, 0x8015
    ctx->r2 = S32(0X8015 << 16);
    // 0x8008EE48: lbu         $v0, -0x6910($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X6910);
    // 0x8008EE4C: andi        $a0, $v0, 0xFF
    ctx->r4 = ctx->r2 & 0XFF;
    // 0x8008EE50: addiu       $v1, $a0, 0x1
    ctx->r3 = ADD32(ctx->r4, 0X1);
    // 0x8008EE54: bgez        $v1, L_8008EE60
    if (SIGNED(ctx->r3) >= 0) {
        // 0x8008EE58: addu        $v0, $v1, $zero
        ctx->r2 = ADD32(ctx->r3, 0);
            goto L_8008EE60;
    }
    // 0x8008EE58: addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
    // 0x8008EE5C: addiu       $v0, $a0, 0x10
    ctx->r2 = ADD32(ctx->r4, 0X10);
L_8008EE60:
    // 0x8008EE60: andi        $v0, $v0, 0x1F0
    ctx->r2 = ctx->r2 & 0X1F0;
    // 0x8008EE64: subu        $v0, $v1, $v0
    ctx->r2 = SUB32(ctx->r3, ctx->r2);
    // 0x8008EE68: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8008EE6C: sb          $v0, -0x6910($at)
    MEM_B(-0X6910, ctx->r1) = ctx->r2;
    // 0x8008EE70: lui         $v0, 0x8015
    ctx->r2 = S32(0X8015 << 16);
    // 0x8008EE74: lbu         $v0, -0x6910($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X6910);
    // 0x8008EE78: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8008EE7C: addu        $v0, $v0, $s0
    ctx->r2 = ADD32(ctx->r2, ctx->r16);
    // 0x8008EE80: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x8008EE84: jal         0x80029E80
    // 0x8008EE88: addiu       $a1, $zero, 0x300
    ctx->r5 = ADD32(0, 0X300);
    osAiSetNextBuffer_recomp(rdram, ctx);
        goto after_5;
    // 0x8008EE88: addiu       $a1, $zero, 0x300
    ctx->r5 = ADD32(0, 0X300);
    after_5:
    // 0x8008EE8C: j           L_8008EE98
    // 0x8008EE90: andi        $v0, $s1, 0xFF
    ctx->r2 = ctx->r17 & 0XFF;
        goto L_8008EE98;
    // 0x8008EE90: andi        $v0, $s1, 0xFF
    ctx->r2 = ctx->r17 & 0XFF;
L_8008EE94:
    // 0x8008EE94: andi        $v0, $s1, 0xFF
    ctx->r2 = ctx->r17 & 0XFF;
L_8008EE98:
    // 0x8008EE98: beq         $v0, $zero, L_8008EE10
    if (ctx->r2 == 0) {
        // 0x8008EE9C: nop
    
            goto L_8008EE10;
    }
    // 0x8008EE9C: nop

    // 0x8008EEA0: lw          $ra, 0x28($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X28);
    // 0x8008EEA4: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8008EEA8: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8008EEAC: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8008EEB0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8008EEB4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8008EEB8: jr          $ra
    // 0x8008EEBC: nop

    return;
    // 0x8008EEBC: nop

;}
