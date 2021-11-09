# Abstract Classes

Abstract classes are more indicated for refining what an object is. For instance, we can have an abstract class Animal and now say that Cow is a subclass of Animal. One important limitation is that classes can only inherit from a single abstract class at most.

Abstract classes are defined with the abstract modifier preceding the class keyword. Moreover, abstract classes can contain fully defined methods and abstract methods as well:

```

abstract class Animal {

  def heartBeat(): Int = {
    42
  }

  // this is an abstract method that should
  // be overridden by subclasses
  def eat(): String // returns the sound made while eating
}
```

# Traits

Just like abstract classes, traits are an inheritance mechanism to allow reusing behavior across different classes. One of the most important features of traits is that a class may inherit from multiple traits.

Traits are used to group methods for a given behavior. Just like abstract classes they can have fully defined and not implement methods. Traits are defined using the trait keyword:

```

trait Walker {
def walk(): Int // returns the number of steps walked

def rest(): Int = {
0
}
}
```

## Significant Differences

Classes are limited to inherit from a single abstract class but can inherit from multiple traits.

Another important difference is that abstract classes allow specifying constructor parameters. Traits do not allow us to do the same. Nevertheless, both approaches allow specifying type parameters.

Some guidelines to decide when to use abstract classes or traits:

If it might be reused in several and unrelated classes, we should implement it as a trait. In complex class hierarchies mixing a trait is possible, but adding an abstract class in between won’t be possible
