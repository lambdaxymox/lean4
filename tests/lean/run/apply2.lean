open tactic

example (p q : Prop) : p → q → p ∧ q ∧ p :=
by do
  intros,
  c₁ ← return (expr.const `and.intro []),
  repeat_at_most 10 (apply c₁ <|> assumption)
