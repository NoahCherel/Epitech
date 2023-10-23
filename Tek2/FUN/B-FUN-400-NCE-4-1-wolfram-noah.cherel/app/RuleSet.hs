{-
-- EPITECH PROJECT, 2023
-- Untitled (Workspace)
-- File description:
-- RuleSet
-}

module RuleSet (module RuleSet) where

rule30 :: [Char] -> Char
rule30 ('*':' ':' ':_) = '*'
rule30 (' ':'*':'*':_) = '*'
rule30 (' ':'*':' ':_) = '*'
rule30 (' ':' ':'*':_) = '*'
rule30 _                = ' '

rule90 :: [Char] -> Char
rule90 ('*':'*':' ':_) = '*'
rule90 ('*':' ':' ':_) = '*'
rule90 (' ':'*':'*':_) = '*'
rule90 (' ':' ':'*':_) = '*'
rule90 _                = ' '

rule110 :: [Char] -> Char
rule110 ('*':'*':' ':_) = '*'
rule110 ('*':' ':'*':_) = '*'
rule110 (' ':'*':'*':_) = '*'
rule110 (' ':'*':' ':_) = '*'
rule110 (' ':' ':'*':_) = '*'
rule110 _                = ' '

applyRule :: Int -> [Char] -> Char
applyRule 30  = rule30
applyRule 90  = rule90
applyRule 110 = rule110
applyRule _   = error "Invalid rule"
