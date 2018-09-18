function [X info] = qoptimalcolumnkaczmarz(A,b,K,x0,options)
%QOPTIMALCOLUMNKACZMARZ Column Kaczmarz method with quasi-optimal rule for Tikhonov regularization problem
%
%   [X info] = qoptimalcolumnkaczmarz(A,b,K)
%   [X info] = qoptimalcolumnkaczmarz(A,b,K,x0)
%   [X info] = qoptimalcolumnkaczmarz(A,b,K,x0,options)
%
% Modifed quasi-optimal version of Kaczmarz method for solving ill-posed systems of linear 
% algebraic equations. This algorithm is based on transforming regularized
% normal equations to the equivalent augmented regularized normal system of 
% equations. Implements the optimal column Kaczmarz's method for the system Ax = b:
%
%       ro^{k-1} = (a'^j(k)*r^{k-1} - alpha*x^{k-1}_j(k))/(||a^j(k)||_2^2 + alpha),
%       r^k = r^{k-1} - ro^{k-1}*a^j(k),
%       x^k_j(k) = x^{k-1}_j(k) + ro^{k-1},
%
% where j(k) = argmax(abs(a'^i*r^k/sqrt(alpha) - sqrt(alpha)*x^k)/sqrt(||a^i||_2^2 + alpha),
% i = 1,2, ... n; k = 1,2, ... ., and a^j(k) - column of matrix
% A with j(k) number, alpha - regularization parametr of 
% problem (A'A+alpha*eye(n,n))*u = A'*f, where A in R^{m x n}.
%
% One iteration consists of n such steps.
%
% Input:
%   A          m times n matrix.
%   b          m times 1 vector.
%   K          Number of iterations. If K is a scalar, then K is the maximum
%              number of iterations and only the last iterate is saved.
%              If K is a vector, then the largest value in K is the maximum
%              number of iterations and only iterates corresponding to the
%              values in K are saved, together with the last iterate.
%              If K is empty then a stopping criterion must be specified.
%   x0         n times 1 starting vector. Default: x0 = 0.
%   options    Struct with the following fields:
%       alpha       The regularization parameter. For this method alpha must
%                   be a scalar.
%       stoprule    Struct containing the following information about the
%                   stopping rule:
%                       type = 'NO' : (Default) the only stopping rule
%                                       is the maximum number of iterations.
%                              'NR' : Naive stop rule, ||x^{k} - x^{k-1}|| <= epsilon.
%                       epsilon = convergence factor, only
%                                   necessary for NR.
%       nonneg      Logical; if true then nonnegativity in enforced in
%                   each step.
%
% Output:
%   X           Matrix containing the saved iterations.
%   info        Information vector with 2 elements.
%               info(1) = 0 : stopped by maximum number of iterations
%                         1 : stopped by NR-rule
%               info(2) = no. of iterations.
%
% See also: kaczmarz.
% Example  of use:
%   N = [1:10:1000];                % Saved every tenth result
%   options.stoprule.type = 'none'; % Do not use step rule
%   options.alpha = alpha;          % Set Regularization parametr
%   [x1 info1] = qoptimalcolumnkaczmarz(A,b,N,[],options);
%
% THIS CODE BASED on paper P. C. Hansen and M. Saxild-Hansen, AIR Tools - A 
% MATLAB Package of Algebraic Iterative Reconstruction Methods, Journal 
% of Computational and Applied Mathematics, 236 (2012), pp. 2167-2178,
% http://www2.imm.dtu.dk/~pcha/AIRtools/.
%
% Dept. of Applied Mathematics, S. P. Korolyov Samara State Aerospace 
% University (National Research University), 
% Faculty of Computer Science, Russia, Samara.
%
% Ivanov Andrey, Graduate student,
% ssauivanov@gmail.com.
%
% Reference:
% [1]   A. I. Zhdanov, The method of augmented regularized normal equations, Computational Math-
%       ematics and Mathematical Physics, 52 (2012), pp. 194-197.
% [2]   A. I. Zhdanov, A. A. Ivanov, Projection Regularization Algorithm 
%       for Solving Linear Algebraic System of Large Dimension, 
%       Vestn. Samar. Gos. Tekhn. Univ. Ser. Fiz.-Mat. Nauki, 2010,
%       Issue 5(21), pp. 309-312, (In Russian)
%       http://www.mathnet.ru/php/archive.phtml?wshow=paper&jrnid=vsgtu&paperid=827&option_lang=eng
% [3]   V. A. Morozov, Methods of solving incorrectly posed problems, 
%       Springer Verlag, New York, 1984.
% [4]   G. P. Vasil'chenko and A. A. Svetlakov, A projection algorithm for solving systems of
%       linear algebraic equations of high dimensionality, USSR Computational Mathematics and
%       Mathematical Physics, 20 (1980), pp. 1-8.
% [5]   G. T. Herman, Fundamentals of Computerized Tomography,
%       Image Reconstruction from Projections, Springer, New York, 2009.

[m n] = size(A);

if nargin < 3
    error('Too few input arguments')
end
% Default values of alpha and x0.
if nargin < 4
    x0 = zeros(n,1);
end

% Check if x0 is empty.
if isempty(x0)
    x0 = zeros(n,1);
end

% The sizes of A, b and x must match.
if size(b,1) ~= m || size(b,2) ~= 1
    error('The size of A and b do not match')
elseif size(x0,1) ~= n || size(x0,2) ~= 1
    error('The size of x0 does not match the problem')
end

% Initialization.
if nargin < 5
    if isempty(K)
        error('No stopping rule specified')
    end
    stoprule = 'NO';
    alpha = 10^(-8);
    
    Knew = sort(K);
    kmax = Knew(end);
    X = zeros(n,length(K));
    
    % Default there is no nonnegativity projection.
    nonneg = false;
end

% Check the contents of options, if present.
if nargin == 5
    
    % Nonnegativity.
    if isfield(options,'nonneg')
        nonneg = options.nonneg;
    else
        nonneg = false;
    end
    
    if (isfield(options,'alpha'))
        if (isnumeric(options.alpha))
            alpha = options.alpha;
            if alpha <= 0
                warning('MATLAB:IncorrectRegularizationParam',...
                    'The alpha value is negative');
            end;
        else
            error('alpha must be numeric')
        end;
        
    end;

    if isfield(options,'stoprule') && isfield(options.stoprule,'type')
        stoprule = options.stoprule.type;
        if ischar(stoprule)
            if strncmpi(stoprule,'NR',2);
                    % Naive stopping rule.
                    if isfield(options.stoprule,'epsilon')
                        epsilon = options.stoprule.epsilon;
                    else
                    error(['The factor epsilon must be specified when '...
                        'using NR'])
                    end
            elseif strncmpi(stoprule,'NO',2)
                % No stopping rule.
                if isempty(K)
                    error('No stopping rule specified')
                end
                
            else
                % Other stopping rules.
                error('The chosen stopping rule is not valid')
            end % end different stopping rules.
            
        else
            error('The stoprule type must be a string')
        end
        if isempty(K)
            kmax = inf;
            X = zeros(n,1);
        else
            Knew = sort(K);
            kmax = Knew(end);
            X = zeros(n,length(K));
        end
    else
        if isempty(K)
            error('No stopping rule specified')
        else
            Knew = sort(K);
            kmax = Knew(end);
            X = zeros(n,length(K));
            stoprule = 'NO';
        end
    end % end stoprule type specified.
    
end % end if nargin includes options.

xk = x0;
rk = b - A*xk;

normAi = full(abs(sum(A.*A,1)));
stop = 0;
k = 0;
l = 0;

while ~stop
    k = k + 1;
    
    xkm1 = xk;
    for i = 1:n
        % The iterate.       
        v = abs(A'*rk/sqrt(alpha) - sqrt(alpha)*xk)./sqrt(normAi' + alpha);
        v(v == Inf) = -1;
        [mx, ri] = max(v);
        
        ari = full(A(:,ri))';

        ro = (ari*rk - (alpha)*xk(ri))/(normAi(ri) + alpha);
        rk = rk - ro*ari';
        xk(ri) = xk(ri) + ro;
        
        if nonneg && xk(ri) < 0, xk(ri) = 0; end
    end
    xk1 = xk;
    
    if strncmpi(stoprule,'NR',2);
        dNR = norm(xkm1 - xk1);
        
        if dNR <= epsilon || k >= kmax
            stop = 1;
            
            if k ~= kmax
                info = [1 k-1];
            else
                info = [0 k-1];
            end
        end
    elseif strncmpi(stoprule,'NO',2)
        % No stopping rule.
        if k >= kmax 
            stop = 1;
            info = [0 k];
        end
    end % end stoprule type.
    
    % If the current iteration is requested saved.
    if (~isempty(K) && k == Knew(l+1)) || stop
        l = l + 1;
        % Saves the current iteration.
        X(:,l) = xk1;
    end
    xk = xk1;
end
X = X(:,1:l);