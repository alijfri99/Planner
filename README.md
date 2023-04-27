# Introduction
This repository implements a general-purpose propositional planner in C++, based on the definitions in [1], [2]. In this paradigm, a planning domain is a pair $D = (R, A)$ where $R$ is a finite set of predicates and $A$ is a finite set of actions. Each action $\alpha \in A$ is a 4-tuple $\alpha = (x, \text{PRE}(x), \text{ADD}(x), \text{DEL}(x))$ where $x$ is the action name, $\text{PRE}(x)$ specifies the set of preconditions that are required for applying the action with action name $x$, $\text{ADD}(x)$ is the add list and $\text{DEL}(x)$ is the delete list. Furthermore, each action $\alpha \in A$ has a unique action name. Finally, a planning problem is a 3-tuple $P = (D, s_0, g)$ where $D$ is the planning domain as defined above, $s_0$ is the initial state and $g$ is the goal state. Specifically, each of $s_0$ and $g$ is a conjunction of predicates from $R$. A solution to $P$ is defined as a sequence of actions from $A$ that transforms $s_0$ to $g$.

# Implementation
This implementation consists of five modules: `Model`, `Domains`, `Problems`, `Planners` and `Utils`.

* `Model`: This module implements the concepts of a predicate, an action and a state. It is important to note that throughout this implementation, the names of the objects and the predicates in a planning domain are mapped to natural numbers for faster access and manipulation. This mapping is bijective, so that the original name of each object or predicate can be retrieved later on.

* `Domains`: This module implements the general concept of a planning domain in `Domain.cpp`. Furthermore, it implements three specific domain instances, all of which inherit from the `Domain` class implemented in `Domain.cpp`. These domain instances are the *spare tire* domain [1], the *link-repeat* domain [3] and the *depots* domain [4].

* `Problems`: This module implements the general notion of a planning problem in `Problem.cpp`. Moreover, it implements the planning problem instance associated with each of the *spare tire* and *link-repeat* domains, both of which inherit from the `Problem` class in `Problem.cpp`. However, since multiple problem instances can be associated with a single instance of the *depots* domain, I have left it to the users to implement their own problem instance associated with an instance of the *depots* domain by inheriting similarly from the `Problem` class.

* `Planners`: This module provides an implementation of the backward planning algorithm [1], which inherits from the `Planner` class in `Planner.cpp`. Users can implement other planners by inheriting similarly from the `Planner` class.

* `Utils`: This module provides an implementation of the set operations used in finding relevant actions and action regression during backward planning [1]. Also, it defines a large prime in `Constants.cpp` which is used for hashing observed states during planning.

# References
[1] S. Russell and P. Norvig, “Artificial intelligence: a modern approach, global edition 4th,” Foundations, vol. 19, p. 23, 2021.

[2] H. H. Zhuo, T. Nguyen, and S. Kambhampati, “Model-lite case-based planning,” in Proceedings of the AAAI Conference on Artificial Intelligence, vol. 27, pp. 1077–1083, 2013.

[3] M. M. Veloso and J. Blythe, “Linkability: Examining causal link commitments in partial-order planning.,” in AIPS, pp. 170–175, 1994.

[4] D. Long and M. Fox, “The 3rd international planning competition: Results and analysis,” Journal of Artificial Intelligence Research, vol. 20, pp. 1–59, 2003.