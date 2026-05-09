# CS460_Capstone_Repo
# Evaluating Large Language Models for Security Vulnerability Analysis

## Overview

This research project evaluates the effectiveness of Large Language Models (LLMs) in identifying software security vulnerabilities compared to traditional Static Application Security Testing (SAST) tools.
The project investigates whether modern LLMs can accurately detect vulnerabilities across multiple programming languages and vulnerability categories while also generating meaningful explanations and remediation suggestions.
The research performs a side-by-side comparison between:
- Commercial LLMs
- Open-source LLMs
- Traditional static analysis tools

using standardized datasets, structured prompts, and quantitative evaluation metrics.

---

## Problem Statement

Traditional SAST tools often struggle to detect:
- Novel vulnerabilities
- Complex code patterns
- Context-dependent security flaws

At the same time, LLMs are becoming increasingly integrated into software development workflows, but their reliability in vulnerability detection remains insufficiently explored.

This research investigates whether LLMs can:
- Match traditional security tools
- Surpass traditional tools
- Assist security auditors effectively
- Reduce missed vulnerabilities

---

## Research Questions

The project focuses on four major research questions:

1. **Can LLMs accurately identify vulnerabilities in source code?**
2. **How does vulnerability complexity and novelty affect detection accuracy?**
3. **How do LLMs compare with existing static analysis tools?**
4. **Can LLM-generated explanations be trusted for security auditing?**

---

## Project Architecture

#### Preparation Phase
- Collect vulnerable and secure code samples
- Configure SAST tools
- Configure LLM APIs and models
- Build prompt templates
- Prepare evaluation pipeline

#### Execution Phase
1. Run prompts against LLMs
2. Run datasets through SAST tools
3. Store outputs
4. Compare predictions
5. Generate metrics

#### Outcome
- Side-by-side comparison
- Confusion matrix analysis
- Model performance benchmarking
- Research conclusions

---

## Dataset Design

### Dataset Summary

The dataset consists of:
- **600 total code samples**
- **50 vulnerable + 50 secure samples per vulnerability**
- **12 programming languages**
- Various complexity levels and novel attack patterns

---

## Vulnerability Categories

The project evaluates the following CWE categories:

| CWE ID  | Vulnerability              |
| ------- | -------------------------- |
| CWE-120 | Buffer Overflow            |
| CWE-79  | Cross-Site Scripting (XSS) |
| CWE-89  | SQL Injection              |
| CWE-416 | Use After Free             |
| CWE-94  | Code Injection             |
| CWE-434 | Dangerous File Upload      |

---

## Programming Languages

The dataset includes multiple languages:
- C
- C++
- Java
- Python
- PHP
- SQL
- Additional supported languages

The project intentionally includes multiple languages to test cross-language generalization.

---

## Models Evaluated

### Commercial LLMs

| Model           | Provider  |
| --------------- | --------- |
| ChatGPT 5.4     | OpenAI    |
| Claude Opus 4.6 | Anthropic |
| Gemini 3.1 Pro  | Google    |

### Open-Source LLM

| Model         | Description                          |
| ------------- | ------------------------------------ |
| Code Llama 7B | Lightweight open-source coding model |

---

## Static Analysis Tools

| Tool      | Purpose                        |
| --------- | ------------------------------ |
| Semgrep   | Multi-language static analysis |
| Cppcheck  | C/C++ vulnerability detection  |
| SonarQube | General static code analysis   |

---

## Prompt Engineering

### Why Prompting Matters

LLMs can produce significantly different outputs depending on:
- Prompt wording
- Role assignment
- Task specificity
- Output structure

The project heavily focuses on prompt engineering to ensure fair evaluation.

### Prompt Structure

The prompts include:

#### 1. Role Prompting
```text
You are a cybersecurity expert specializing in vulnerability detection.
```

#### 2. Task Definition
The model is instructed to:
- Detect vulnerabilities
- Explain vulnerabilities
- Suggest fixes
- Reason about findings

#### 3. Output Specification
The models must return structured JSON responses.

### Example Prompt

````json
{
  "role": "cybersecurity expert",
  "task": "analyze source code for vulnerabilities",
  "output": {
    "vulnerabilities": [
      {
        "type": "CWE-XXX",
        "explanation": "...",
        "suggestion": "..."
      }
    ]
  }
}

## Vulnerability Categories
- **CWE-79**: Cross-Site Scripting (XSS)
- **CWE-89**: SQL Injection
- **CWE-94**: Code Injection
- **CWE-120**: Buffer Overflow
- **CWE-416**: Use After Free
- **CWE-434**: Dangerous File Upload

## Dataset Sources
- OWASP Benchmark Project
- Juliet Test Suite
- VulDeePecker Dataset
- GitHub vulnerability examples
- AI-generated code samples

## Models Evaluated

### Large Language Models
- **OpenAI GPT-4** - State-of-the-art reasoning capabilities
- **OpenAI GPT-3.5** - Fast, cost-effective alternative
- **Anthropic Claude 3 Opus** - Advanced reasoning model
- **Anthropic Claude 3 Sonnet** - Balanced performance model
- **Google Gemini Pro** - Multimodal capabilities

### Static Analysis Tools
- **Semgrep** - Fast, customizable static analysis with rule-based detection for 30+ languages

## Evaluation Metrics
- **Accuracy**: Overall correctness of predictions
- **Precision**: True Positives / (True Positives + False Positives)
- **Recall**: True Positives / (True Positives + False Negatives)
- **F1-Score**: Harmonic mean of precision and recall
- **True Positives (TP)**: Correctly identified vulnerabilities
- **False Positives (FP)**: Incorrectly flagged code
- **False Negatives (FN)**: Missed vulnerabilities
- **True Negatives (TN)**: Correctly identified safe code

## Experimental Workflow
1. **Dataset Preparation** - Collect and preprocess vulnerability samples
2. **Model Execution** - Run LLMs and static analysis tools with standardized prompts
3. **Result Parsing** - Extract and normalize results from each model
4. **Metrics Generation** - Calculate evaluation metrics
5. **Comparative Analysis** - Analyze performance across models and CWE categories

## Technologies Used
- **Python** (3.9+) - Primary programming language
- **Semgrep** - Static analysis engine
- **OpenAI API** - GPT model access
- **Anthropic API** - Claude model access
- **Google Gemini API** - Gemini model access
- **Pandas** - Data manipulation and analysis
- **NumPy** - Numerical computing
- **Jupyter Notebook** - Data exploration and visualization

## Installation

### Prerequisites
- Python 3.9 or higher
- pip or conda package manager
- API keys for:
  - OpenAI (https://platform.openai.com/api-keys)
  - Anthropic (https://console.anthropic.com/)
  - Google Gemini (https://ai.google.dev/)


## Contributing
This is an academic research project

## Authors
- Research Team - CS460 Capstone Project

## License
This project is intended for academic and research purposes only.

## References
- https://owasp.org/www-project-top-ten/
- https://cwe.mitre.org
- https://semgrep.dev/docs/
- https://github.com/OWASP/Benchmark
- https://platform.openai.com/docs/
- https://docs.anthropic.com/
- https://ai.google.dev/docs

