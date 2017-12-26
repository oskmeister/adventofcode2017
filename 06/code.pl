sub hash {
    my $result = scalar @_;
    foreach $number (@_) {
        $result = $result * 8237;
        $result += ($number + 1);
        $result %= 1<<32;
    }
    return $result;
}
sub maximumIndex {
    my $highest = -1;
    my $index = 0;
    my $cur = 0;
    foreach $item (@_) {
        if ($item > $highest) {
            $highest = $item;
            $index = $cur;
        }
        $cur++;
    }
    return $index;
}

sub iterate {
    my $idx = maximumIndex(@_);
    my $n = scalar(@_);
    my $sz = @_[$idx];
    @_[$idx] = 0;
    $idx++;
    $idx = $idx % $n;
    for ($i = 0; $i < $sz; $i++) {
        @_[$idx++]++;
        $idx = $idx % $n;
    }
    return @_;
}

my @input_row = split("\t",<>);
my @numbers = ();
for my $each(@input_row) {
    push @numbers, int($each);
}
my %seen;
my @cur = @numbers;
my $steps = 1;
while (1) {
    if ($seen{hash(@cur)}) {
        my $diff = $steps - $seen{hash(@cur)};
        print "Saw state $diff steps ago.\n";
        last;
    }
    $seen{hash(@cur)} = $steps;
    @cur = iterate(@cur);
    $steps++;
}
$steps--;
print "Finished in $steps total steps.\n";
