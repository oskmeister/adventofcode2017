package main
import "fmt"
func main() {
    var P []int
    for {
        var v int
        n, err := fmt.Scan(&v)
        if (n == 0 || err != nil) {
            break
        }
        P = append(P, v)
    }
    i := 0
    steps := 0
    for {
        if (i < 0 || i >= len(P)) {
            fmt.Println(steps)
            break
        }
        at_value := i
        i += P[i]
        P[at_value]++
        steps++
    }
}
