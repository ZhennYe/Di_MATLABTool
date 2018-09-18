function varargout = adimat_diff_min1(varargin)
  [varargout{2}, tmp1]= min(varargin{2});
  if numel(tmp1) == 1
    varargout{1} = varargin{1}(:, tmp1);
  else
    varargout{1} = d_zeros(varargout{2});
    for i=1:numel(tmp1)
      varargout{1}(:, i) = varargin{1}(:, tmp1(i), i);
    end
  end
end
% automatically generated from $Id: derivatives-vdd.xml 3983 2013-12-21 11:20:23Z willkomm $
