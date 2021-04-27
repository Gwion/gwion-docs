# Types

Gwion has a plethora of types. Some are user defined; others are builtin. There are a variety of ways to construct user types, but each compose with the same building blocks.

## Primitive Types

Gwion offers many primitive types. These are types that represent a multitude of numbers.

Name | Description
---- | -----------
`int` | A signed integer type the same width as the native pointer type
`float` | A floating point real number type
`dur` | A type to represent duration
`time` | A type to represent time
`char` | An ascii character
`bool` | A boolean type that can take the values `true` and `false`
`None` | A type that cannot be constructed
`Object` | The global superclass type

## Enums

Enums (or enumerated types) are a way to define a set of distinct options. Like C, normal enums are not namespaced.

You can declare an enum with the `enum` keyword and provide enum cases within the body separated by commas.

```gwion,editable
enum Ordering {
    Less, Equal, Greater
}

<<< "`Less` has the value ${Less}!" >>>;
```

## Classes

## Function Pointers

## Tagged Unions

## Typedefs
