% function [Jacobian, varargout] = ...
%      admComputeDerivComplex(diffFunction, seedMatrix, ...
%                         independents, dependents, fNargout, varargin)
%
% see also admDiffComplex.
%
% This file is part of the ADiMat runtime environment.
%
% Copyright (C) 2014 Johannes Willkomm
% Copyright (C) 2010,2011 Johannes Willkomm, Institute for Scientific Computing
%                     RWTH Aachen University
function [Jacobian varargout] = admComputeDerivComplex(diffFunction, seedMatrix, independents, dependents, fNargout, ch, varargin)
    
  funcArgs = varargin;
  
  nActArgs = length(independents);
  nActResults = length(dependents);

  totNumEl = admTotalNumel(funcArgs{independents});
  if isequal(seedMatrix, 1)
    seedMatrix = eye(totNumEl);
  else
    if totNumEl ~= size(seedMatrix, 1)
      error('adimat:csmethod:nonConformingSeed', ...
            ['In Complex Step (CS) mode, the number of columns of the seed ' ...
             'matrix S must be identical with the total number of ' ...
             'components in the (active) function arguments. However, ' ...
             'admTotalNumel(independents) == %d and size(seedMatrix, 1) ' ...
             '= %d'], totNumEl, size(seedMatrix, 1));
    end
  end
  
  Jacobian = [];
  colJ = 1;

  inputs = bsxfun(@complex, admGetV(funcArgs(independents)), ch .* full(seedMatrix));
  
  ndd = size(seedMatrix, 2);
  
  inputsC = inputMatrix2CellOfArguments(inputs, funcArgs, independents);
  
  [outputs{1:fNargout}] = cellfun(diffFunction, inputsC{:}, 'uniformoutput', false);

  for k=dependents
    outk = outputs{k};
    for i=1:length(outk)
      outk{i} = imag(outk{i}(:));
    end
    Jblock{k} = horzcat(outk{:});
  end
  
  Jacobian = vertcat(Jblock{:}) ./ ch;

  [varargout{1:fNargout}] = diffFunction(funcArgs{:});
  
% $Id: admComputeDerivComplex.m 4499 2014-06-13 12:02:25Z willkomm $
