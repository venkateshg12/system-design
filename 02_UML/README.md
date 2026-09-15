# UML (Unified Modeling Language)

## Definition

A UML diagram is a standardized visual representation used to **model, visualize, specify, and document** the structure and behavior of a software system.

## Classification Map

UML diagrams are broadly classified into two categories:

![UML Diagram Categories](./images/category.png)

---

## Class Diagram

Shows the classes, their attributes, methods, and relationships.

![Class Diagram](./images/class.png)

### Access Modifiers

Access modifiers are important to know for drawing class diagrams.

![Access Modifiers](./images/access_modifier.png)

### Types of Classes

There are two types of classes:
- Abstract classes
- Concrete classes

Representation of abstract classes: `<<abstract>>`
For concrete classes: `<<concrete>>` — but the default classes are actually called concrete classes.

Diagram of abstract class:

![Abstract Class Diagram](./images/abstract.png)

### Association

Association is a structural relationship between two or more classes that indicates that their objects are connected or can communicate with each other.

Classification of associations:

![Association Diagram](./images/association.png)

#### Class Association

**Inheritance:**

![Inheritance Diagram](./images/inheritance.png)

#### Object Association

- **Simple Association**

![Simple Association Diagram](./images/simple.png)

- **Aggregation**

![Aggregation Diagram](./images/aggregation.png)

- **Composition**

![Composition Diagram](./images/composition.png)

---

## Sequence Diagram

A Sequence Diagram is a UML behavioral diagram that shows how actors and objects interact with each other in a specific sequence over time to accomplish a particular operation or use case.

![Sequence Diagram](./images/sequence.png)

### Messages

Messages are of two types:

- **Sync**

![Sync Message](./images/sync.png)

- **Async**

![Async Message](./images/async.png)

Other message types:

- **Create message**

![Create Message](./images/create_message.png)

- **Delete message**

![Delete Message](./images/destroy_image.png)

- **Found message**

![Found Message](./images/found_message.png)

- **Lost message**

![Lost Message](./images/lost_message.png)