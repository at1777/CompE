% LaTex class file for generating KGCOE reports
% https://kgcoe-git.rit.edu/jgm6496/KGCOEReport_template

\NeedsTeXFormat{LaTeX2e}
\ProvidesClass{KGCOEReport}[2016/05/25 Example LaTeX class]

%%%%%%% Base class
\LoadClass[12pt]{article}

%%%%%%% Required packages
\RequirePackage{multicol} %Make columns
\RequirePackage[margin=1in]{geometry} %Change margins

\setlength{\parindent}{0pt} % Don't indent paragraphs

%%%%%%% Internal functions and environments
% Used to make sure the TA listing is even
\newenvironment{_TAalignment}{%
\def\\{\newline\leavevmode\phantom{TA:}}
}

%%%%%%% External functions and environments

%%%%%%% Write a CE report
\DeclareOption{CMPE}{
	\newcommand{\KGCOEDocType}{CMPE}

	\renewcommand{\maketitle}{%
	\vspace*{2.5cm}

		\begin{center}
			\large
			\textbf{\classCode \ Laboratory Exercise \exerciseNumber}

			\bigskip

			\textbf{\exerciseDescription}
			\normalsize
		\end{center}

		\vspace*{5cm}

		\begin{multicols}{2}
			\phantom{LaTeX doesn't like empty columns} % Phantom will take up that much space, but not actually appear
			\columnbreak{} % Starts the second column
			\begin{flushleft} % Make sure LaTeX does not try to justify these lines
				\name\\
				Performed: \dateDone\\
				Submitted: \dateSubmitted\\
				\vspace*{\baselineskip} % Adds one line of spacing on this line, like the template
				Lab Section: \LabSectionNum\\
				Instructor: \LabInstructor\\
				TA:\begin{_TAalignment}\TAs  % There can't be a space between the \TAs and the enviroment declaration
				\end{_TAalignment}
				\vspace*{\baselineskip}
				Lecture Section: \LectureSectionNum\\
				Professor: \LectureInstructor\\
			\end{flushleft}
		\end{multicols}


		\vspace{1cm}

		By submitting this report, you attest that you neither have given nor have received any assistance (including writing, collecting data, plotting figures, tables or graphs, or using previous student reports as a reference), and you further acknowledge that giving or receiving such assistance will result in a failing grade for this course.

		\vfill

		{\centering{}
		Your Signature: \hrulefill}

		\newpage
	}
}

% Pass any other options to
\DeclareOption*{\PassOptionsToClass{\CurrentOption}{article}}
\ProcessOptions

%%%%%%% Check to see if we were given a correct department code
\@ifundefined{KGCOEDocType}{\ClassError{KGCOEReport}{Unrecognized Department Code}{Available department codes are CMPE, EEEE}}{}
