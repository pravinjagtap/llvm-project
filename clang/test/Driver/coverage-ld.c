// Test coverage ld flags.
//
// RUN: %clang -### %s 2>&1 \
// RUN:     --target=i386-unknown-linux -fprofile-arcs \
// RUN:     -resource-dir=%S/Inputs/resource_dir \
// RUN:     --sysroot=%S/Inputs/basic_linux_tree \
// RUN:   | FileCheck --check-prefix=CHECK-LINUX-I386 %s
//
// RUN: %clang -### %s 2>&1 \
// RUN:     --target=i386-unknown-linux --coverage \
// RUN:     -resource-dir=%S/Inputs/resource_dir \
// RUN:     --sysroot=%S/Inputs/basic_linux_tree \
// RUN:   | FileCheck --check-prefix=CHECK-LINUX-I386 %s
//
// CHECK-LINUX-I386-NOT: "-u__llvm_profile_runtime"
// CHECK-LINUX-I386: /Inputs/resource_dir{{/|\\\\}}lib{{.*}}i386-unknown-linux{{.*}}libclang_rt.profile.a"
// CHECK-LINUX-I386-NOT: "-u__llvm_profile_runtime"
// CHECK-LINUX-I386: "-lc"
//
// RUN: %clang -### %s 2>&1 \
// RUN:     --target=x86_64-unknown-linux --coverage -fuse-ld=ld \
// RUN:     -resource-dir=%S/Inputs/resource_dir \
// RUN:     --sysroot=%S/Inputs/basic_linux_tree \
// RUN:   | FileCheck --check-prefix=CHECK-LINUX-X86-64 %s
//
// CHECK-LINUX-X86-64: "{{(.*[^-.0-9A-Z_a-z])?}}ld{{(.exe)?}}"
// CHECK-LINUX-X86-64: "{{.*}}/Inputs/resource_dir{{/|\\\\}}lib{{.*}}linux{{.*}}libclang_rt.profile.a" {{.*}} "-lc"
//
// RUN: %clang -### %s 2>&1 \
// RUN:     --target=x86_64-unknown-freebsd --coverage -fuse-ld=ld \
// RUN:     -resource-dir=%S/Inputs/resource_dir \
// RUN:     --sysroot=%S/Inputs/basic_freebsd64_tree \
// RUN:   | FileCheck --check-prefix=CHECK-FREEBSD-X86-64 %s
//
// CHECK-FREEBSD-X86-64: "{{(.*[^-.0-9A-Z_a-z])?}}ld{{(.exe)?}}"
// CHECK-FREEBSD-X86-64: "{{.*}}/Inputs/resource_dir{{/|\\\\}}lib{{/|\\\\}}x86_64-unknown-freebsd{{/|\\\\}}libclang_rt.profile.a"
//
// RUN: %clang -### %s 2>&1 \
// RUN:     --target=x86_64-unknown-netbsd --coverage -fuse-ld=ld \
// RUN:     -resource-dir=%S/Inputs/resource_dir \
// RUN:     --sysroot=%S/Inputs/basic_netbsd_tree \
// RUN:   | FileCheck --check-prefix=CHECK-NETBSD-X86-64 %s

// CHECK-NETBSD-X86-64: "{{(.*[^-.0-9A-Z_a-z])?}}ld{{(.exe)?}}"
// CHECK-NETBSD-X86-64: "{{.*}}/Inputs/resource_dir{{/|\\\\}}lib{{/|\\\\}}x86_64-unknown-netbsd{{/|\\\\}}libclang_rt.profile.a"

// RUN: %clang -### %s 2>&1 \
// RUN:     --target=x86_64-unknown-openbsd --coverage -fuse-ld=ld \
// RUN:     -resource-dir=%S/Inputs/resource_dir \
// RUN:     --sysroot=%S/Inputs/basic_openbsd_tree \
// RUN:   | FileCheck --check-prefix=CHECK-OPENBSD-X86-64 %s

// CHECK-OPENBSD-X86-64: "{{(.*[^-.0-9A-Z_a-z])?}}ld{{(.exe)?}}"
// CHECK-OPENBSD-X86-64: "{{.*}}/Inputs/resource_dir{{/|\\\\}}lib{{/|\\\\}}x86_64-unknown-openbsd{{/|\\\\}}libclang_rt.profile.a"

// RUN: %clang -### %s 2>&1 \
// RUN:     --target=arm-linux-androideabi --coverage -fuse-ld=ld \
// RUN:     -resource-dir=%S/Inputs/resource_dir \
// RUN:     --sysroot=%S/Inputs/basic_android_tree/sysroot \
// RUN:   | FileCheck --check-prefix=CHECK-ANDROID-ARM %s
//
// CHECK-ANDROID-ARM: "{{(.*[^.0-9A-Z_a-z])?}}ld.lld{{(.exe)?}}"
// CHECK-ANDROID-ARM: "{{.*}}/Inputs/resource_dir{{/|\\\\}}lib{{/|\\\\}}arm-unknown-linux-android{{/|\\\\}}libclang_rt.profile.a"
