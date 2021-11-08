
class User(private var name:String,var age:Int){
    def p():Unit={
        println(f"Hi $name")
    }
}

object main{
    def main(args:Array[String])={
        println("Hi")
        var u = new User("Himanshu",40);
        u.age = 20
        println(u.age)
        println(u.name) // not possible
        u.p
    }
}