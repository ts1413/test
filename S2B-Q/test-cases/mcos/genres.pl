#/usr/bin/perl -w

my %channel = ();
my %thread = ();

while (<>) {
    my $ch;
    if (/CH__TASK_SCHED\(((IN|OUT)_(IO)?\d+),.*\)/) {
	$channel{$1} = 0;
    } elsif (/CH__CORE_THREAD_SCHED\(((IN|OUT)_(IO)?\d+),.*\)/) {
	$channel{$1} = 0;
    } elsif (/mcos_thread_create\s*\(\s*\&\w+\s*,\s*(\w+)\s*,\s*\w+\s*\)\s*;/) {
	$thread{$1} = 0;
    }
}

print "#include <stdio.h>\n";
print "#include <pthread.h>\n";

foreach my $k (sort {$a cmp $b;} keys %channel) {
    print "\n/* ${k} */\n";
    print "pthread_mutex_t mutex__${k} = PTHREAD_MUTEX_INITIALIZER;\n";
    print "pthread_cond_t cond__${k} = PTHREAD_COND_INITIALIZER;\n";
    print "int flag__${k} = 0;\n";
}

print "\n";
foreach my $k (sort {$a cmp $b;} keys %thread) {
    print "void ${k}(uint32_t stacd, uintptr_t exinf);\n";
}

foreach my $k (sort {$a cmp $b;} keys %thread) {
    print "\nstatic void *f__${k} (void *arg)\n";
    print "{\n";
    print "  if (PTHREAD_DEBUG) {\n";
    print "    fputs (\"start ${k}\\n\", stdout);\n";
    print "    fflush (stdout);\n";
    print "  }\n";
    print "  ${k} (0, (uintptr_t)arg);\n";
    print "  return NULL;\n";
    print "}\n";
}
