class C {
    v = 10;
    f1 = () => {
        console.log(this.v);
        console.log(v)
        var v = 20;
        console.log(this.v);
        console.log(v);
    }
    f2() {
        console.log(this.v);
        console.log(v)
        var v = 30;
        console.log(this.v);
        console.log(v)
    }
}

obj = new C();
obj.f1();
console.log("**********");
obj.f2();